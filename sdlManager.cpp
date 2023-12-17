#include "sdlManager.hpp"

TextureManager::TextureManager(SDL_Renderer* renderer) : gRenderer(renderer) {}

SDL_Texture* TextureManager::loadTexture(const std::string& path) {
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cerr << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
    if (newTexture == nullptr) {
        std::cerr << "Unable to create texture from image! SDL Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_FreeSurface(loadedSurface);
    return newTexture;
}