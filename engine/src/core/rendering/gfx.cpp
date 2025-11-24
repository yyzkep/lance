#include "core/rendering/gfx.hpp"

namespace Lance::Rendering
{

GLuint GFX::create_vao()
{
    GLuint vao;
    glGenVertexArrays(1, &vao);
    return vao;
}

void GFX::bind_vao(GLuint vao)
{
    glBindVertexArray(vao);
}

void GFX::delete_vao(GLuint vao)
{
    glDeleteVertexArrays(1, &vao);
}

GLuint GFX::create_vbo()
{
    GLuint vbo;
    glGenBuffers(1, &vbo);
    return vbo;
}

void GFX::bind_vbo(GLuint vbo)
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
}

void GFX::delete_vbo(GLuint vbo)
{
    glDeleteBuffers(1, &vbo);
}

GLuint GFX::create_ebo()
{
    GLuint ebo;
    glGenBuffers(1, &ebo);
    return ebo;
}

void GFX::bind_ebo(GLuint ebo)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
}

void GFX::delete_ebo(GLuint ebo)
{
    glDeleteBuffers(1, &ebo);
}

void GFX::enable_vertex_attribute(GLuint index)
{
    glEnableVertexAttribArray(index);
}

void GFX::set_vertex_attribute(GLuint index,
                               GLint size,
                               GLenum type,
                               GLboolean normalized,
                               GLsizei stride,
                               const void *pointer)
{
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}

void GFX::draw_arrays(GLenum mode, GLint first, GLsizei count)
{
    glDrawArrays(mode, first, count);
}

void GFX::draw_elements(GLenum mode,
                        GLsizei count,
                        GLenum type,
                        const void *offset)
{
    glDrawElements(mode, count, type, offset);
}

} // namespace Lance::Rendering
