#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "sdlManager.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Storage{
    private:
    const int barn_ht = 180;
    const int barn_wdt = 150;
    const int barn_x = 390;
    const int barn_y = 32;

    int WIDTH = 600;
    int HEIGHT = 450;

    //The window we'll be rendering to
    SDL_Window* StorageWindow = NULL;

    //The window renderer
    SDL_Renderer* StorageRenderer = NULL;  
    SDL_Texture* StorageWindowTexture = NULL;
    
    SDL_Rect storageRect = { barn_x, barn_y, barn_wdt, barn_ht };
    SDL_Rect StoreRect = {330, 45, 500, 400};
    SDL_Texture* storageTexture = NULL;
    //will display trees to complete the farm
    //Texture for Trees1 and Trees2
    SDL_Texture* trees1Texture = NULL;
    SDL_Texture* trees2Texture = NULL;
    SDL_Rect leftTrees = {-60, 0, 200, 680};
    SDL_Rect rightTrees = {760, -25, 200, 680};

    static int GoldCoins;
    static int milk, eggs, carrots, wheat, radish, seeds;

    public:
    Storage(SDL_Renderer* gRenderer);
    Storage();
    ~Storage();

    void storageRender(SDL_Renderer* gRenderer);
    bool loadMedia();
    SDL_Rect getSDLRect();

    void addMaterial(char Material, int qty);
    void useMaterial(char Material);
    int getAmount(char Material);
};
