#include "Vegetables.hpp"

void Vegetables::VegetableRenderer(){
    SDL_RenderCopy(gRenderer, T, NULL, R);
}

Vegetables::~Vegetables(){
    cout << "Object deleted\n";
}

bool Vegetables::loadMedia(){
    if (T == NULL){
        std::cerr << "Failed to load texture image!" << std::endl;
        return false;
    }
    return true;
}

void Vegetables::setVegetables(bool grow, int price, int time, bool harvest){
    grown = grow;
    selling_price = price;
    growth_time = time;
    harvestStatus = 0;
}
// void Vegetables::SetGrown(){
//     grown = 1;
// }
// void Vegetables::SetHarvest(){
//     harvestStatus = 1;
// }

