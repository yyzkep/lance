#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>

namespace Lance::Rendering
{

class Shader
{
public:
    Shader() = default;
    Shader(const std::string &vertex_src,
           const std::string &fragment_src);

    ~Shader();

    void bind() const;
    void unbind() const;

    void set_uniform(const std::string &name, int value) const;
    void set_uniform(const std::string &name, float value) const;
    void set_uniform(const std::string &name, const glm::vec3 &value) const;
    void set_uniform(const std::string &name, const glm::mat4 &value) const;

private:
    GLuint program_id = 0;

    GLuint compile_shader(GLenum type, const std::string &src);
    GLint get_uniform_location(const std::string &name) const;
};

} // namespace Lance::Rendering

#endif // SHADER_H
