#pragma once
#include <iostream>
using namespace std;
#include "Animals.hpp"

class Cow : public Animals{
    private:
    int current_produce;
    bool hunger;
    int produce_amount;
    int y_speed = 2;
    SDL_Rect cowDown = {150, 362, 57, 81};
    SDL_Rect cowUp = {150, 100, 57, 86};

    public:
    Cow(SDL_Renderer* gRenderer);
    ~Cow();
    void walk();
    // void sell(int qty);
    void feed();
    void produce();
    uint32_t timeElapsed();
    // void collectProduce(); should return milk, will need to increment in storage
    void setHunger();
};
