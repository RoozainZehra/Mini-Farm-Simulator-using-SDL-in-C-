#include "Chicken.hpp"

Chicken::Chicken() : Animals::Animals(60){
    current_produce = 0;
    hunger = 1;
    produce_amount = rand() % 3;
    if (produce_amount == 0){produce_amount++;} //can produe 1 or 2 eggs
}

Chicken::~Chicken(){}

void Chicken::feed(){ //will reset hunger to 0
    if (hunger == 1){
        hunger = 0;
    }
}

void Chicken::produce(){ //will start produces after first feeding
    if (hunger == 0 && getCurrentTime() == getProduceTime()){
        current_produce = 1;
    }
}

void Chicken::setHunger(){ //chicken gets hungry after this time
    if (getCurrentTime() == getProduceTime() && current_produce == 0){
        hunger = 1;
    }
}