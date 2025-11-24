#ifndef TRANSFORM_COMPONENT
#define TRANSFORM_COMPONENT

#include <glm/glm.hpp>

namespace Lance::Entities::Components
{
struct TransformComponent
{
    glm::vec3 position{0.0f, 0.0f, 0.0f};
    glm::vec3 rotation{0.0f, 0.0f, 0.0f};
    glm::vec3 scale{1.0f, 1.0f, 1.0f};

    glm::mat4 matrix; // cached
    bool dirty = true;
};
} // namespace Lance::Entities::Components

#endif /* TRANSFORM_COMPONENT */
