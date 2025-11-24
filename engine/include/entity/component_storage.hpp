#ifndef COMPONENT_STORAGE_H
#define COMPONENT_STORAGE_H

#include "entity.hpp"
#include <unordered_map>
#include <vector>

namespace Lance::Entities
{
template <typename T>
class ComponentStorage
{
public:
    void add(Entity e, const T &component)
    {
        if (has(e))
            return;

        sparse[e] = dense.size();
        dense.push_back({e, component});
    }

    bool has(Entity e) const
    {
        return sparse.find(e) != sparse.end();
    }

    T &get(Entity e)
    {
        return dense[sparse[e]].second;
    }

    const std::vector<std::pair<Entity, T>> &data() const
    {
        return dense;
    }

private:
    std::unordered_map<Entity, size_t> sparse;

    std::vector<std::pair<Entity, T>> dense;
};
} // namespace Lance::Entities

#endif // COMPONENT_STORAGE_H
