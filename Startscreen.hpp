#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

enum class GameState {
    MENU,
    PLAYING
};

class Startscreen {
private:
    SDL_Renderer* mRenderer;
    SDL_Texture* mTexture;

public:
    Startscreen(SDL_Renderer* renderer);
    ~Startscreen();
    bool loadMedia();
    void handleEvent(SDL_Event& e, GameState& gamestate);
    bool loadStartscreenImage();
    void render();
};
