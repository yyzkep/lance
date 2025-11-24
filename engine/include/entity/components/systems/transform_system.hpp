#ifndef TRANSFORM_SYSTEM_HPP
#define TRANSFORM_SYSTEM_HPP

#include "../transform_component.hpp"
#include <vector>

namespace Lance::Entities::Systems
{

class TransformSystem
{
public:
    TransformSystem() = default;

    void Update(std::vector<Lance::Entities::Components::TransformComponent *> &transforms);
};

} // namespace Lance::Entities::Systems

#endif /* TRANSFORM_SYSTEM_HPP */
