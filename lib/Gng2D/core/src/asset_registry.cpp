#include "SDL2/SDL_image.h"
#include "SDL2/SDL.h"
#include "Gng2D/core/asset_registry.hpp"
#include "Gng2D/core/log.hpp"
#include "Gng2D/core/window.hpp"

void Gng2D::AssetRegistry::loadSprite(const std::string& name)
{
    LOG::INFO("Loading sprite:", name);
    const std::string pathToSprite{"data/sprites/" + name + ".png"};
    auto renderer = Gng2D::Window::renderer();
    auto sprite = IMG_LoadTexture(renderer, pathToSprite.c_str());

    if (not sprite) return LOG::ERROR("Failed to load sprite:", name, "SDL Error:", SDL_GetError());
    if (loadedSprites.contains(name)) return LOG::WARN("Sprite", name, "already loaded");

    loadedSprites[name] = sprite;
}

SDL_Texture* Gng2D::AssetRegistry::getSprite(const std::string& name) const
{
    if (not loadedSprites.contains(name))
    {
        LOG::ERROR("No sprite:", name);
        return nullptr;
    }
    return loadedSprites.at(name);
}

void Gng2D::AssetRegistry::freeAllSprites()
{
    LOG::INFO("Freeing loaded sprites");
    for (const auto& [_, texture] : loadedSprites)
    {
        SDL_DestroyTexture(texture);
    }
}
