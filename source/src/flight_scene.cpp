#include "flight_scene.hpp"
#include "Gng2D/core/log.hpp"

void FlightScene::onEnter()
{
    Gng2D::LOG::INFO("Entering flight scene");
}

void FlightScene::onExit()
{
    Gng2D::LOG::INFO("Exiting flight scene");
}

bool FlightScene::isCompleted()
{
    return false;
}

void FlightScene::update()
{
    static int spawnCounter;
    if (spawnCounter == 60)
    {
        spawnObject<EnemyBullet>();
        spawnCounter = 0;
    }
    spawnCounter++;

    auto& playerVelocity = playerShip.getComponent<Gng2D::Velocity>();
    playerVelocity = {0, 0};
    float speedMod = 1.0f;
    if (isKeyPressed(SDL_SCANCODE_LSHIFT))  speedMod = 0.25f;
    if (isKeyPressed(SDL_SCANCODE_DOWN))    playerVelocity.y += 4.0f * speedMod;
    if (isKeyPressed(SDL_SCANCODE_UP))      playerVelocity.y -= 4.0f * speedMod;
    if (isKeyPressed(SDL_SCANCODE_RIGHT))   playerVelocity.x += 4.0f * speedMod;
    if (isKeyPressed(SDL_SCANCODE_LEFT))    playerVelocity.x -= 4.0f * speedMod;

    const auto playerPosition = playerShip.getComponent<Gng2D::Position>();
    static int weaponCooldown = 0;
    if (isKeyPressed(SDL_SCANCODE_Z) and not weaponCooldown)
    {
        spawnObject<AllyBullet>(playerPosition, Gng2D::Velocity{0, -7});
        weaponCooldown = 20;
    }
    if (weaponCooldown > 0) weaponCooldown--;

    movementSystem();
    playerBulletCollisionSystem();
    bulletBulletCollisionSystem();
}

void FlightScene::render()
{
    Gng2D::Scene::render();
    playerColliderRenderer();
    allyBulletColliderRenderer();
    enemyBulletColliderRenderer();
}

