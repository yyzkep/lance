#ifndef LANCE_H
#define LANCE_H

#include "core/rendering/material.hpp"
#include "core/rendering/mesh.hpp"
#include "core/window.hpp"
#include "entity/components/systems/render_system.hpp"
#include "entity/components/systems/transform_system.hpp"
#include "entity/components/transform_component.hpp"
#include "entity/registry.hpp"

#include <memory>
#include <vector>

namespace Lance
{

class Application
{
public:
    Application();
    ~Application();

    void init();

    void run();

    void shutdown();

private:
    Entities::Registry registry;
    Entities::Systems::TransformSystem transform_system;
    Entities::Systems::RenderSystem render_system;

    std::vector<Entities::Components::TransformComponent *> transforms;

    std::vector<Entities::Systems::RenderEntry> render_queue;

    GLFWwindow *glfw_window;

    bool running = false;

    void process_input();
    void update();
    void render();
};

} // namespace Lance

#endif /* LANCE */
