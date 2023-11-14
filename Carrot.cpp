#include "Carrot.hpp"

Carrot::Carrot() : Vegetables::Vegetables(0, 20, 100, 0){
    current_stage = 1;
}

Carrot::~Carrot(){}

void Carrot::Sell(int qty){}
void Carrot::Grow(){
    if (current_stage < 3){ //since full growth stage is 3
        current_stage += 1; //image changes with every update in stage
    }
    if (current_stage == 3){
        Vegetables::SetGrown;
    }
}

void Carrot::Harvest(){} //change plot to empty





