#pragma once
#include "entt/entity/registry.hpp"

namespace Gng2D
{
struct MovementSystem
{
    MovementSystem(entt::registry&);
    void operator()();

protected:
    void updatePosition();

    entt::registry& registry;
};
}
