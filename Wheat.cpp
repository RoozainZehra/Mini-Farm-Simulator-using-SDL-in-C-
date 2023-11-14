#include "Wheat.hpp"

Wheat::Wheat() : Vegetables::Vegetables(0, 10, 70, 0){
    current_stage = 1;
}

Wheat::~Wheat(){}
void Wheat::Sell(int qty){} //check at marketplace
void Wheat::Grow(){
    if (current_stage < 3){
        current_stage += 1; //image changes at every increment
    }
    else if (current_stage == 3){
        Vegetables::SetGrown();
        Vegetables::SetHarvest();
    }
}
void Wheat::Harvest(){} //connect to patches