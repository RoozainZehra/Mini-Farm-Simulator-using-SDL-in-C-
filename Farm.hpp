#pragma once

#include <iostream>
#include "sdlManager.hpp"
using namespace std;

class Farm{
    private:
    SDL_Texture* farmTexture = NULL;
    
    public:
    Farm(SDL_Renderer* gRenderer);
    ~Farm();

    void farmRender(SDL_Renderer* gRenderer);
    bool loadMedia();
};
