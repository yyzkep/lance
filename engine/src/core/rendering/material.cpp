#include "core/rendering/material.hpp"

namespace Lance::Rendering
{

Material::Material(Shader *shader)
    : shader_ptr(shader)
{
    shader_ptr->bind();
}

void Material::bind() const
{
    shader_ptr->bind();
}

void Material::set(const std::string &name, int value)
{
    shader_ptr->set_uniform(name, value);
}

void Material::set(const std::string &name, float value)
{
    shader_ptr->set_uniform(name, value);
}

void Material::set(const std::string &name, const glm::vec3 &value)
{
    shader_ptr->set_uniform(name, value);
}

void Material::set(const std::string &name, const glm::mat4 &value)
{
    shader_ptr->set_uniform(name, value);
}

} // namespace Lance::Rendering
