#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <vector>

// Class for managing textures
class TextureManager {
private:
    SDL_Renderer* gRenderer;

public:
    TextureManager(SDL_Renderer* renderer) ;

    SDL_Texture* loadTexture(const std::string& path) ;

};