#include "Carrot.hpp"

Carrot::Carrot( SDL_Renderer* gRenderer, int x){
    Vegetables::setVegetables(0, 20, 100, 0);
    TextureManager element(gRenderer);
    T = element.loadTexture("sprout.png");
    R = {x, 423, 30, 10}; 
    current_stage = 1;
}

Carrot::~Carrot(){
    delete this;
}

// void Carrot::Sell(int qty){}
// void Carrot::Grow(){
//     if (current_stage < 3){ //since full growth stage is 3
//         current_stage += 1; //image changes with every update in stage
//     }
//     if (current_stage == 3){
//         Vegetables::SetGrown();
//     }
// }

// void Carrot::Harvest(){} //change plot to empty





