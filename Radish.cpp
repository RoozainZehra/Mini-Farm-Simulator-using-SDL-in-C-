#include "Radish.hpp"

Radish::Radish( SDL_Renderer* gRenderer, int x){
    int items = (rand() % 2) + 1;
    Vegetables::setVegetables(18000, items, 0);
    TextureManager element(gRenderer);
    Vegetables::Renderer = gRenderer;
    Vegetables::Texture = element.loadTexture("seedsPlanted.png");
    Vegetables::Rect = {x+10, 426, 30, 30}; 

    current_stage = 1;
    creation_time = SDL_GetTicks();  //time of creation
}

Radish::~Radish(){} //deletes in land patches

void Radish::Grow(){
    if (current_stage < 3 && timeElapsed() >= growth_time && timeElapsed() <= (2*growth_time)){ //since full growth stage is 3
        current_stage += 1; //image changes with every update in stage
        if (current_stage == 2){
            TextureManager element(Renderer);
            Vegetables::Texture = element.loadTexture("sprout.png");
        }
    }
    if (current_stage == 3 && timeElapsed()>=(2*growth_time)){
        TextureManager element(Renderer);
        Vegetables::Texture = element.loadTexture("Radish.png"); 
        Vegetables::harvestStatus = 1;
    }
}

char Radish::Type(){
    return 'R';
}

uint32_t Radish::timeElapsed(){
    current_time = SDL_GetTicks();
    return current_time - creation_time;
}

int Radish::Harvest(){ //change plot to empty
    return totalHarvest;
}

bool Radish::isHarvestable(){
    return harvestStatus;
}




