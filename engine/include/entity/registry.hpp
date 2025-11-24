#ifndef REGISTRY_H
#define REGISTRY_H

#include "component_storage.hpp"
#include "entity.hpp"
#include <memory>
#include <typeindex>
#include <unordered_map>

namespace Lance::Entities
{
class Registry
{
public:
    Entity create_entity()
    {
        return next_entity++;
    }

    template <typename T>
    ComponentStorage<T> &storage()
    {
        std::type_index ti(typeid(T));

        if (!stores.count(ti))
            stores[ti] = std::make_unique<Wrapper<T>>();

        return static_cast<Wrapper<T> *>(stores[ti].get())->storage;
    }

    template <typename T>
    void add_component(Entity e, const T &component)
    {
        storage<T>().add(e, component);
    }

    template <typename T>
    bool has_component(Entity e)
    {
        return storage<T>().has(e);
    }

    template <typename T>
    T &get_component(Entity e)
    {
        return storage<T>().get(e);
    }

    template <typename A, typename B, typename Func>
    void view(Func func)
    {
        auto &sa = storage<A>();
        auto &sb = storage<B>();

        for (auto &[e, comp_a] : sa.data())
        {
            if (sb.has(e))
                func(e, comp_a, sb.get(e));
        }
    }

    template <typename A, typename B, typename C, typename Func>
    void view(Func func)
    {
        auto &sa = storage<A>();
        auto &sb = storage<B>();
        auto &sc = storage<C>();

        for (auto &[e, comp_a] : sa.data())
        {
            if (sb.has(e) && sc.has(e))
                func(e, comp_a, sb.get(e), sc.get(e));
        }
    }

private:
    Entity next_entity = 1;

    struct BaseWrapper
    {
        virtual ~BaseWrapper()
        {
        }
    };

    template <typename T>
    struct Wrapper : BaseWrapper
    {
        ComponentStorage<T> storage;
    };

    std::unordered_map<std::type_index, std::unique_ptr<BaseWrapper>> stores;
};
} // namespace Lance::Entities

#endif // REGISTRY_H
