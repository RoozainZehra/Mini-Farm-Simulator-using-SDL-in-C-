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
    // void sell(int qty); //will need to figure this one out
    void feed();
    void produce();
    // void collectProduce(); should return eggs
    void setHunger();
};
