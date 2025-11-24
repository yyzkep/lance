#include "core/rendering/mesh.hpp"

namespace Lance::Rendering
{

Mesh::Mesh(const std::vector<float> &vertices,
           const std::vector<unsigned int> &indices)
{
    GFX gfx;

    vao = gfx.create_vao();
    gfx.bind_vao(vao);

    vbo = gfx.create_vbo();
    gfx.bind_vbo(vbo);
    gfx.buffer_data(vertices);

    ebo = gfx.create_ebo();
    gfx.bind_ebo(ebo);
    gfx.buffer_indices(indices);

    index_count = static_cast<GLsizei>(indices.size());

    gfx.enable_vertex_attribute(0);
    gfx.set_vertex_attribute(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
}

Mesh::~Mesh()
{
    GFX gfx;

    gfx.delete_vbo(vbo);
    gfx.delete_ebo(ebo);
    gfx.delete_vao(vao);
}

void Mesh::draw() const
{
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, index_count, GL_UNSIGNED_INT, nullptr);
}

} // namespace Lance::Rendering
