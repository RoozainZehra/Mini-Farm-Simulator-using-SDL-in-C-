#pragma once
#include <iostream>
// #include <vector>
#include "sdlManager.hpp"
#include "Storage.hpp"
using namespace std;

class Marketplace{
    private:
    //Texture for market
    SDL_Texture* marketTexture = NULL;
    //market dimensions and position
    const int market_ht = 128;
    const int market_wdt = 100;
    const int market_x = 562;
    const int market_y = 86;

    SDL_Rect marketRect = {market_x, market_y, market_wdt, market_ht};

    public:
    Marketplace(SDL_Renderer* gRenderer);
    ~Marketplace();

    void marketRender(SDL_Renderer* gRenderer);
    bool loadMedia();

    SDL_Rect getSDLRect();
    char sellItems();



    // void Purchase(int gold_coins, int qty);
    // // void Purchase(int num_seeds, int qty); // needs to be connected
    // void ViewOffers();
};