#pragma once
#include <iostream>
using namespace std;
#include "Animals.hpp"

class Chicken : public Animals{
    private:
    bool current_produce;
    bool hunger;
    int produce_amount;
    int y_speed = 2;

    SDL_Rect chickenDown = {243, 395, 42, 48};
    SDL_Rect chickenUp = {243, 141, 41, 45};
    public:
    Chicken(SDL_Renderer* gRenderer);
    ~Chicken();

    uint32_t timeElapsed();
    void walk();
    char Type();
    char feedType();
    bool feed();
    bool produce();
    void setProduce();
    int collectProduce();
    void setHunger();
    bool animalSick();
    void setAlert();
};
