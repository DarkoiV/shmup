#pragma once
#include <memory>
#include <vector>
#include "Gng2D/systems/movement_system.hpp"
#include "Gng2D/systems/collider_renderer_system.hpp"
#include "Gng2D/components/scene.hpp"
#include "Gng2D/components/game_object.hpp"
#include "player_ship.hpp"
#include "player_bullet_collision_system.hpp"
#include "bullet_bullet_collision_system.hpp"
#include "bullet.hpp"

struct FlightScene : public Gng2D::Scene
{
    void onEnter()      override;
    void onExit()       override;
    bool isCompleted()  override;
    void update()       override;
    void render()       override;

private:
    Gng2D::GameObject       playerShip = spawnObject<PlayerShip>();
    Gng2D::MovementSystem   movementSystem{entityRegistry};

    Gng2D::ColliderRendererSystem<PlayerShip::Collider>
        playerColliderRenderer{entityRegistry};
    Gng2D::ColliderRendererSystem<EnemyBullet::Collider>
        enemyBulletColliderRenderer{entityRegistry};
    Gng2D::ColliderRendererSystem<AllyBullet::Collider>
        allyBulletColliderRenderer{entityRegistry};

    PlayerBulletCollisionSystem
        playerBulletCollisionSystem{entityRegistry};
    BulletBulletCollisionSystem
        bulletBulletCollisionSystem{entityRegistry};
};
