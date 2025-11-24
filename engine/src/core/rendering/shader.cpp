#include "core/rendering/shader.hpp"
#include <iostream>

namespace Lance::Rendering
{

Shader::Shader(const std::string &vertex_src,
               const std::string &fragment_src)
{
    GLuint vs = compile_shader(GL_VERTEX_SHADER, vertex_src);
    GLuint fs = compile_shader(GL_FRAGMENT_SHADER, fragment_src);

    program_id = glCreateProgram();
    glAttachShader(program_id, vs);
    glAttachShader(program_id, fs);
    glLinkProgram(program_id);

    GLint success;
    glGetProgramiv(program_id, GL_LINK_STATUS, &success);

    if (!success)
    {
        char info[512];
        glGetProgramInfoLog(program_id, 512, nullptr, info);
        std::cerr << "Shader link error:\n"
                  << info << "\n";
    }

    glDeleteShader(vs);
    glDeleteShader(fs);
}

Shader::~Shader()
{
    glDeleteProgram(program_id);
}

void Shader::bind() const
{
    glUseProgram(program_id);
}

void Shader::unbind() const
{
    glUseProgram(0);
}

GLuint Shader::compile_shader(GLenum type, const std::string &src)
{
    GLuint shader = glCreateShader(type);
    const char *csrc = src.c_str();
    glShaderSource(shader, 1, &csrc, nullptr);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        char info[512];
        glGetShaderInfoLog(shader, 512, nullptr, info);
        std::cerr << "Shader compile error:\n"
                  << info << "\n";
    }

    return shader;
}

GLint Shader::get_uniform_location(const std::string &name) const
{
    return glGetUniformLocation(program_id, name.c_str());
}

void Shader::set_uniform(const std::string &name, int value) const
{
    glUniform1i(get_uniform_location(name), value);
}

void Shader::set_uniform(const std::string &name, float value) const
{
    glUniform1f(get_uniform_location(name), value);
}

void Shader::set_uniform(const std::string &name, const glm::vec3 &value) const
{
    glUniform3f(get_uniform_location(name), value.x, value.y, value.z);
}

void Shader::set_uniform(const std::string &name, const glm::mat4 &value) const
{
    glUniformMatrix4fv(get_uniform_location(name), 1, GL_FALSE, &value[0][0]);
}

} // namespace Lance::Rendering
