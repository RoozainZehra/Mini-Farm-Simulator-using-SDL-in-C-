#include "Radish.hpp"

Radish::Radish( SDL_Renderer* gRenderer, int x){
    Vegetables::setVegetables(0, 20, 100, 0);
    TextureManager element(gRenderer);
    Vegetables::Renderer = gRenderer;
    Vegetables::Texture = element.loadTexture("seedsPlanted.png");
    Vegetables::Rect = {x+10, 426, 30, 30}; 

    current_stage = 1;
    creation_time = SDL_GetTicks();  //time of creation
    // std::cout << "seed planted" << std::endl;
}

Radish::~Radish(){
    delete this;
}

// void Carrot::Sell(int qty){}
void Radish::Grow(){
    if (current_stage < 3){ //since full growth stage is 3
        current_stage += 1; //image changes with every update in stage
        if (current_stage == 2){
            TextureManager element(Renderer);
            Vegetables::Texture = element.loadTexture("sprout.png");
            // std::cout << "sprout grown" << std::endl;
        }
    }
    if (current_stage == 3 && timeElapsed()>=70000){
        TextureManager element(Renderer);
        Vegetables::Texture = element.loadTexture("Radish.png"); 
        // std::cout << "carrot grown" << std::endl;
        Vegetables::grown = 1;
    }
}

uint32_t Radish::timeElapsed(){
    current_time = SDL_GetTicks();
    return current_time - creation_time;
}

// void Carrot::Harvest(){} //change plot to empty


