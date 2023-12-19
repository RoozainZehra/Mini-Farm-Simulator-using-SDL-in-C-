#pragma once

#include <iostream>
using namespace std;
#include "Vegetables.hpp"

class Radish:public Vegetables{
    private:
    int current_stage;


    public:
    Radish(SDL_Renderer* gRenderer, int x);
    ~Radish();
    uint32_t timeElapsed();
    void Grow();
    char Type();
    int Harvest();
    bool isHarvestable();
};
