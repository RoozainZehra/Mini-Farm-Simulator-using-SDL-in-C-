#pragma once
#include <iostream>
using namespace std;
#include "sdlManager.hpp"

class Vegetables{
    protected:
    uint32_t creation_time;
    uint32_t current_time;
    
    int selling_price; //remians unchanged
    int growth_time; //remains unchanged
    int totalHarvest;
    bool harvestStatus;
    
    SDL_Renderer* Renderer = NULL;  //window renderer
    SDL_Texture* Texture = NULL;    //vegetable texture unique to each vegetable
    SDL_Rect Rect;                  //unique vegetable dimensions for each

    public:
    
    Vegetables();
    virtual ~Vegetables();
    
    bool loadMedia();
    void VegetableRenderer();
    virtual int Sell() = 0;
    virtual void Grow(){}
    virtual char Type() = 0;
    virtual int Harvest() = 0;
    virtual bool isHarvestable() = 0;
    void setVegetables(int price, int time, int harvestItems, bool harvest);
    SDL_Rect getRect();
    virtual uint32_t timeElapsed()=0;
};