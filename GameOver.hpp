#pragma once
#include "sdlManager.hpp"


class GameOver {
private:
    SDL_Texture* GTexture = NULL;

public:
    GameOver(SDL_Renderer* renderer);
    ~GameOver();
    bool loadMedia();
    void render(SDL_Renderer* gRenderer);
};