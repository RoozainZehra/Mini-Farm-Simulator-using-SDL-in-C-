#pragma once
#include <iostream>
using namespace std;
#include "Animals.hpp"

class Cow : public Animals{
    private:
    bool current_produce; //checks whether is currently in produce state
    bool hunger;
    int produce_amount;
    int y_speed = 2;
    SDL_Rect cowDown = {150, 362, 57, 81};
    SDL_Rect cowUp = {150, 100, 57, 86};

    public:
    Cow(SDL_Renderer* gRenderer);
    ~Cow();
    void walk();
    char Type();
    char feedType();
    bool feed();
    bool produce();
    uint32_t timeElapsed();
    int collectProduce(); 
    void setProduce();
    void setHunger();
    bool animalSick();
    void setAlert();
};
