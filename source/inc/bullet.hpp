#pragma once
#include "Gng2D/components/game_object.hpp"
#include "Gng2D/components/position.hpp"
#include "Gng2D/components/velocity.hpp"
#include "Gng2D/components/circle_colider.hpp"

struct AllyBullet : public Gng2D::GameObject
{
    struct Collider : public Gng2D::CircleCollider {};

    AllyBullet(Gng2D::Scene& s, Gng2D::Position p, Gng2D::Velocity v)
        : Gng2D::GameObject(s)
    {
        addComponent<Gng2D::Position>(p);
        addComponent<Gng2D::Velocity>(v);
        addComponent<Collider>(3.0f);
    }
};

struct EnemyBullet : public Gng2D::GameObject
{
    struct Collider : public Gng2D::CircleCollider {};

    EnemyBullet(Gng2D::Scene& s, Gng2D::Position p, Gng2D::Velocity v)
        : Gng2D::GameObject(s)
    {
        addComponent<Gng2D::Position>(p);
        addComponent<Gng2D::Velocity>(v);
        addComponent<Collider>(3.0f);
    }
};
