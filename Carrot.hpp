#pragma once

#include <iostream>
using namespace std;
#include "Vegetables.hpp"

class Carrot:public Vegetables{
    private:
    int current_stage;


    public:
    Carrot(SDL_Renderer* gRenderer, int y);
    ~Carrot();
    uint32_t timeElapsed();
    void Grow();
    char Type();
    int Harvest();
    bool isHarvestable();
};
