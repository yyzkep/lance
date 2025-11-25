#include "systems/transform_system.hpp"
#include <glm/gtc/matrix_transform.hpp>

using namespace Lance::Entities::Systems;
using namespace Lance::Entities::Components;

void TransformSystem::Update(
    std::vector<TransformComponent *> &transforms)
{
    for (auto *t : transforms)
    {
        if (!t->dirty)
            continue;

        glm::mat4 m(1.0f);

        // translate
        m = glm::translate(m, t->position);

        // rotate (x,y,z order)
        m = glm::rotate(m, t->rotation.x, glm::vec3(1, 0, 0));
        m = glm::rotate(m, t->rotation.y, glm::vec3(0, 1, 0));
        m = glm::rotate(m, t->rotation.z, glm::vec3(0, 0, 1));

        // scale
        m = glm::scale(m, t->scale);

        t->matrix = m;
        t->dirty = false;
    }
}
