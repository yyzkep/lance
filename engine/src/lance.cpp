#include "lance.hpp"
#include "GLFW/glfw3.h"
#include "core/rendering/mesh.hpp"
#include "core/rendering/shader.hpp"
#include "core/window.hpp"
#include "entity/components/transform_component.hpp"

using namespace Lance;

Application::Application() = default;
Application::~Application() = default;

void Application::init()
{
    running = true;
    Window window;
    glfw_window = window.window;
    auto entity = registry.create_entity();
    auto transform = Entities::Components::TransformComponent{};
    transform.position = {0.0f, 0.0f, 0.0f};
    transform.dirty = true;

    registry.add_component(entity, transform);

    transforms.push_back(&registry.get_component<Entities::Components::TransformComponent>(entity));

    const char *vertex_src = R"(
    #version 330 core
    layout(location = 0) in vec3 aPos;

    uniform mat4 u_model;

    void main()
    {
        gl_Position = u_model * vec4(aPos, 1.0);
    }
    )";

    const char *fragment_src = R"(
    #version 330 core
    out vec4 FragColor;

    void main()
    {
        FragColor = vec4(1.0, 0.5, 0.2, 1.0);
    }
    )";

    std::vector<float> vertices = {
        // positions       // colors
        0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   // top (red)
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left (green)
        0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f   // bottom right (blue)
    };

    std::vector<unsigned int> indices = {0, 1, 2};

    auto shader_ptr = new Rendering::Shader(vertex_src, fragment_src);
    auto mesh_ptr = new Rendering::Mesh(vertices, indices);
    auto material_ptr = new Rendering::Material(shader_ptr);

    Entities::Systems::RenderEntry entry;
    entry.mesh = mesh_ptr;
    entry.material = material_ptr;
    entry.transform = transforms.back();

    render_queue.push_back(entry);
}

void Application::run()
{
    while (running)
    {
        if (glfwWindowShouldClose(glfw_window))
            running = false;
        process_input();
        update();
        render();
    }
}

void Application::shutdown()
{
    for (auto &entry : render_queue)
    {
        delete entry.mesh;
        delete entry.material;
    }
    render_queue.clear();
    transforms.clear();
    glfwTerminate();
}

void Application::process_input()
{
    glfwPollEvents();
}

void Application::update()
{
    transform_system.Update(transforms);
}

void Application::render()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // RGBA
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    render_system.render(render_queue);
    glfwSwapBuffers(glfw_window);
}
