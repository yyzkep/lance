#ifndef MESH_H
#define MESH_H

#include "gfx.hpp"
#include <glm/glm.hpp>
#include <vector>

namespace Lance::Rendering
{

class Mesh
{
public:
    Mesh(const std::vector<float> &vertices,
         const std::vector<unsigned int> &indices);

    ~Mesh();

    void draw() const;

private:
    GLuint vao = 0;
    GLuint vbo = 0;
    GLuint ebo = 0;
    GLsizei index_count = 0;
};

} // namespace Lance::Rendering

#endif // MESH_H
