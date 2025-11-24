#ifndef RENDER_SYSTEM
#define RENDER_SYSTEM

#include "entity/components/transform_component.hpp"
#include <unordered_map>
#include <vector>

namespace Lance::Rendering
{
class Mesh;
class Material;
} // namespace Lance::Rendering

namespace Lance::Entities::Systems
{

struct RenderEntry
{
    Lance::Rendering::Mesh *mesh = nullptr;
    Lance::Rendering::Material *material = nullptr;
    Lance::Entities::Components::TransformComponent *transform = nullptr;
};

class RenderSystem
{
public:
    RenderSystem() = default;

    void render(const std::vector<RenderEntry> &entries);
};

} // namespace Lance::Entities::Systems

#endif /* RENDER_SYSTEM */
