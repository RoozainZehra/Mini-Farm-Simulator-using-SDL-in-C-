#pragma once

#include <iostream>
#include "sdlManager.hpp"
using namespace std;

class Farmer{
    private:
    const int farmer_ht = 40;
    const int farmer_wdt = 35;
    int farmer_x = 40;
    int farmer_y = 0;
    SDL_Texture* farmerTexture = NULL;
    SDL_Rect farmerRect = { 40, 0, 35, 40 };
    
    public:
    Farmer(SDL_Renderer* gRenderer);
    ~Farmer();

    void farmerRender(SDL_Renderer* gRenderer);
    bool loadMedia();
    void movements(char x);
    void out_movement(int sw, int sh);
    SDL_Rect Get_SDlRECT();
    bool checkCollision( SDL_Rect b );
};
