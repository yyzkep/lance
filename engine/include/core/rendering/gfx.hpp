#ifndef GFX_HPP
#define GFX_HPP

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <vector>

namespace Lance::Rendering
{

class GFX
{
public:
    GFX() = default;
    ~GFX() = default;

    GLuint create_vao();
    void bind_vao(GLuint vao);
    void delete_vao(GLuint vao);

    GLuint create_vbo();
    void bind_vbo(GLuint vbo);
    template <typename T>
    void buffer_data(const std::vector<T> &data, GLenum usage = GL_STATIC_DRAW)
    {
        glBufferData(GL_ARRAY_BUFFER,
                     data.size() * sizeof(T),
                     data.data(),
                     usage);
    }
    void delete_vbo(GLuint vbo);

    GLuint create_ebo();
    void bind_ebo(GLuint ebo);
    template <typename T>
    void buffer_indices(const std::vector<T> &indices,
                        GLenum usage = GL_STATIC_DRAW)
    {
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                     indices.size() * sizeof(T),
                     indices.data(),
                     usage);
    }
    void delete_ebo(GLuint ebo);

    void enable_vertex_attribute(GLuint index);
    void set_vertex_attribute(GLuint index,
                              GLint size,
                              GLenum type,
                              GLboolean normalized,
                              GLsizei stride,
                              const void *pointer);

    void draw_arrays(GLenum mode, GLint first, GLsizei count);
    void draw_elements(GLenum mode,
                       GLsizei count,
                       GLenum type = GL_UNSIGNED_INT,
                       const void *offset = nullptr);
};

} // namespace Lance::Rendering

#endif /* GFX */
