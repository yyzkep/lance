#ifndef MATERIAL_COMPONENT_H
#define MATERIAL_COMPONENT_H

#include "core/rendering/material.hpp"

namespace Lance::Entities::Components
{
struct MaterialComponent
{
    Rendering::Material material;
};
} // namespace Lance::Entities::Components

#endif
