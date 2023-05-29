#include "animations.hpp"

void emplaceAnimation(AnimationFunction af, entt::registry& reg, entt::entity e)
{
    reg.emplace_or_replace<Gng2D::Animation>(e, af, reg, e);
}

Gng2D::Coroutine flashShip(entt::registry& reg, entt::entity ship)
{
    {
        auto& sprite = reg.get<Gng2D::Sprite>(ship);
        EnemySpriteSheet::setVFrame(EnemySpriteSheet::VFrame::Flashing, sprite);
    }
    co_yield Gng2D::Coroutine::Wait{7};
    {
        auto& sprite = reg.get<Gng2D::Sprite>(ship);
        EnemySpriteSheet::setVFrame(EnemySpriteSheet::VFrame::Normal, sprite);
    }
}

static void selectPickupFrame(entt::registry& reg, entt::entity pickup, int frame)
{
    auto& sprite = reg.get<Gng2D::Sprite>(pickup);
    sprite.srcRect.x = frame * sprite.srcRect.w;
}

Gng2D::Coroutine rotatePickup(entt::registry& reg, entt::entity pickup)
{
    while (true)
    {
        selectPickupFrame(reg, pickup, 0);
        co_yield Gng2D::Coroutine::Wait{14};
        selectPickupFrame(reg, pickup, 1);
        co_yield Gng2D::Coroutine::Wait{7};
        selectPickupFrame(reg, pickup, 2);
        co_yield Gng2D::Coroutine::Wait{7};
        selectPickupFrame(reg, pickup, 3);
        co_yield Gng2D::Coroutine::Wait{7};
        selectPickupFrame(reg, pickup, 2);
        co_yield Gng2D::Coroutine::Wait{7};
        selectPickupFrame(reg, pickup, 1);
        co_yield Gng2D::Coroutine::Wait{7};
    }
}

