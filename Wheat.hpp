#pragma once

#include <iostream>
using namespace std;
#include "Vegetables.hpp"

class Wheat:public Vegetables{
    private:
    int current_stage;


    public:
    Wheat(SDL_Renderer* gRenderer, int x);
    ~Wheat();
    uint32_t timeElapsed();
    void Grow();
    char Type();
    int Harvest();
    bool isHarvestable();
};
