#pragma once
#include "sdlManager.hpp"
#include <iostream>
using namespace std;

class Animals{
    protected:
    uint32_t time_to_feed;
    uint32_t feeding_time;
    uint32_t produce_time;
    uint32_t current_time;

    static int egg_price, milk_price, cow_price, chicken_price;
    bool alert;

    SDL_Renderer* Renderer = NULL; //window renderer
    SDL_Texture* Texture = NULL;   //animal texture unique to each animal
    SDL_Texture* alertTexture = NULL; //texture for alert
    SDL_Rect alertRect;            //unique to each animal
    SDL_Rect Rect;                 //animal dimensions, unique to each animal
    SDL_Rect moverRect;            //tracks movements of the animal

    public:
    uint32_t creation_time;

    Animals();
    ~Animals();
    bool loadMedia();
    void AnimalRenderer();
    int Sell(char type);
    int itemPrice(char type);

    virtual uint32_t timeElapsed() = 0;
    virtual void walk() = 0;
    virtual char Type() = 0;
    virtual char feedType() = 0;
    virtual bool feed() = 0;
    virtual bool produce() = 0;
    virtual void setProduce() = 0;
    virtual int collectProduce() = 0;
    virtual void setHunger() = 0;
    virtual bool animalSick() = 0;
    virtual void setAlert() = 0;
};
