#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <sstream>

#include "Startscreen.hpp"
#include "GameOver.hpp"
#include "Farm.hpp"
#include "Farmer.hpp"
#include "Storage.hpp"
#include "Marketplace.hpp"
#include "landPatches.hpp"
#include "Vegetables.hpp"
#include "Animals.hpp"
using namespace std;

class Game{
    private:
    //Screen dimension constants
    const int SCREEN_WIDTH = 900;
    const int SCREEN_HEIGHT = 650;
    vector<SDL_Rect> P;
    std::array <Vegetables*, 9> v{};
    vector <Animals*> a;
    
    //switch screens from start to main game
    Startscreen* startScreen;
    // GameOver* gameover;
    GameState game;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;  

    SDL_Window* marketWindow = NULL;
    SDL_Window* storageWindow = NULL;   

    bool game_over = false;

    public:
        Game(): game(GameState::MENU){};
        bool Game_logic(SDL_Event &e, bool quit);
        bool init();
        void close();
        void run();
        bool isClickedOnBarn(int clickX, int clickY);
        bool isClickedOnMarket(int clickX, int clickY);
        SDL_Texture* loadTexture(const std::string& filePath, SDL_Renderer* renderer);
        void renderTexture(SDL_Texture* texture, SDL_Renderer* renderer);
        void createStorageWindow(SDL_Window* storageWindow, Storage *storage);
        void createMarketWindow(SDL_Window* marketWindow, SDL_Renderer* Renderer, LandPatches *land, Storage *storage, Marketplace *market);
};
