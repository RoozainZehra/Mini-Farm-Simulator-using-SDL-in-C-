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
    
    SDL_Renderer* Renderer = NULL;
    SDL_Texture* Texture = NULL;
    SDL_Rect Rect;

    public:
    
    Vegetables(){}
    bool loadMedia();
    void VegetableRenderer();
    ~Vegetables();
    // virtual void Sell(int qty) = 0;
    virtual void Grow(){}
    // virtual void Harvest() = 0;
    // void SetHarvest();
    void setVegetables(bool grow, int price, int time, bool harvest);
    virtual uint32_t timeElapsed()=0;
    // uint32_t timeElapsed() = 0;
};
