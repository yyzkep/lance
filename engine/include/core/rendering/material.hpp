#ifndef MATERIAL
#define MATERIAL

#include "shader.hpp"
#include <glm/glm.hpp>
#include <string>

namespace Lance::Rendering
{

class Material
{
public:
    Material() = default;
    Material(Shader *shader);

    void bind() const;

    void set(const std::string &name, int value);
    void set(const std::string &name, float value);
    void set(const std::string &name, const glm::vec3 &value);
    void set(const std::string &name, const glm::mat4 &value);

private:
    Shader *shader_ptr = nullptr;
};

} // namespace Lance::Rendering

#endif /* MATERIAL */
