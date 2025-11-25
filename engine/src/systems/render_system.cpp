#include "systems/render_system.hpp"
#include "core/rendering/material.hpp"
#include "core/rendering/mesh.hpp"
#include <glm/glm.hpp>

using namespace Lance::Entities::Systems;
using namespace Lance::Entities::Components;

void RenderSystem::render(const std::vector<RenderEntry> &entries)
{
    for (const auto &entry : entries)
    {
        if (!entry.mesh || !entry.material || !entry.transform)
            continue;

        entry.material->set("u_model", entry.transform->matrix);

        entry.mesh->draw();
    }
}
