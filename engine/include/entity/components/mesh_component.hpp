#ifndef MESH_COMPONENT_H
#define MESH_COMPONENT_H

#include "core/rendering/mesh.hpp"

namespace Lance::Entities::Components
{
struct MeshComponent
{
    Rendering::Mesh mesh;
};
} // namespace Lance::Entities::Components

#endif
