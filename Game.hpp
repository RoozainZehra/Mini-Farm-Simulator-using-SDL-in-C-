#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "Farm.hpp"
#include "Farmer.hpp"
#include "Storage.hpp"
#include "Marketplace.hpp"
#include "landPatches.hpp"
#include "Vegetables.hpp"

class Game{
    private:
    //Screen dimension constants
    const int SCREEN_WIDTH = 900;
    const int SCREEN_HEIGHT = 650;
    vector <Vegetables*> v;
    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;  

    public:
        bool init();
        void close();
        void run();
};
