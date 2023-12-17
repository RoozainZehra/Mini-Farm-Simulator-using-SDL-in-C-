#include "Wheat.hpp"

Wheat::Wheat( SDL_Renderer* gRenderer, int x){
    int items = (rand()%3) + 1;
    Vegetables::setVegetables(15, 10000, items, 0);
    TextureManager element(gRenderer);
    Vegetables::Renderer = gRenderer;
    Vegetables::Texture = element.loadTexture("seedsPlanted.png");
    Vegetables::Rect = {x+10, 426, 30, 42}; 

    current_stage = 1;
    creation_time = SDL_GetTicks();  //time of creation
    // std::cout << "seed planted" << std::endl;
}

Wheat::~Wheat(){} //deleting in the land patches

int Wheat::Sell(){
    return selling_price;
}

void Wheat::Grow(){
    if (current_stage < 3 && timeElapsed() >= growth_time && timeElapsed() <= (2*growth_time)){ //since full growth stage is 3
        current_stage += 1; //image changes with every update in stage
        if (current_stage == 2){
            TextureManager element(Renderer);
            Vegetables::Texture = element.loadTexture("sprout.png");
            // std::cout << "sprout grown" << std::endl;
        }
    }
    if (current_stage == 3 && timeElapsed()>=(2*growth_time)){
        TextureManager element(Renderer);
        Vegetables::Texture = element.loadTexture("wheatPlant.png"); 
        // std::cout << "carrot grown" << std::endl;
        Vegetables::harvestStatus = 1;
    }
}

char Wheat::Type(){
    return 'W';
}

uint32_t Wheat::timeElapsed(){
    current_time = SDL_GetTicks();
    return current_time - creation_time;
}

int Wheat::Harvest(){ //change plot to empty
    return totalHarvest;
}

bool Wheat::isHarvestable(){
    return harvestStatus;
}


