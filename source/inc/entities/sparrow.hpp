#pragma once
#include "Gng2D/types/game_object.hpp"
#include "Gng2D/components/circle_colider.hpp"
#include "Gng2D/components/layer.hpp"
#include "Gng2D/components/position.hpp"
#include "Gng2D/components/sprite.hpp"
#include "Gng2D/components/velocity.hpp"
#include "components/enemy_ship_collider.hpp"
#include "components/hit_points.hpp"
#include "components/enemy_basic_weapon.hpp"
#include "flight_scene_layers.hpp"

struct Sparrow : Gng2D::GameObject
{
    using Gng2D::GameObject::GameObject;

    void onCreate(Gng2D::Position p, Gng2D::Velocity v = {0.0f, 2.0f})
    {
        addComponent<Gng2D::Position>(p);
        addComponent<Gng2D::Velocity>(v);
        addComponent<Gng2D::Layer>(FlightSceneLayer::Ships);

        // 2 Animation frames normal/hurt
        auto& srcRect = addComponent<Gng2D::Sprite>("sparrow", 1).srcRect;
        srcRect.h /= 2;

        addComponent<EnemyShipCollider>(5.0f);
        addComponent<HitPoints>(3u, 3u);
        addComponent<EnemyBasicWeapon>(75u);
    }
};

