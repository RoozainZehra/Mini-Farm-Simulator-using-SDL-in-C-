#pragma once
#include <iostream>
using namespace std;
#include "sdlManager.hpp"

class Vegetables{
    protected:
    uint32_t creation_time;
    uint32_t current_time;
    bool grown;
    int selling_price; //make constant
    int growth_time; //make constant
    bool harvestStatus;
    
    SDL_Renderer* Renderer = NULL;  //window renderer
    SDL_Texture* Texture = NULL;    //vegetable texture unique to each vegetable
    SDL_Rect Rect;                  //unique vegetable dimensions for each

    public:
    
    Vegetables();
    virtual ~Vegetables();
    
    bool loadMedia();
    void VegetableRenderer();
    // virtual void Sell(int qty) = 0;
    virtual void Grow(){}
    // virtual void Harvest() = 0;
    void setVegetables(bool grow, int price, int time, bool harvest);
    SDL_Rect getRect();
    virtual uint32_t timeElapsed()=0;
};
