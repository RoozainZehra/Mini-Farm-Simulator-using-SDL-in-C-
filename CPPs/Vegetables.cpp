#include "Vegetables.hpp"

int Vegetables::carrot_price = 20;
int Vegetables::radish_price = 20;
int Vegetables::wheat_price = 15;

Vegetables::Vegetables(){
    cout << "vegetables created" << endl;
}

void Vegetables::VegetableRenderer(){
    SDL_RenderCopy(Renderer, Texture, NULL, &Rect);
}

Vegetables::~Vegetables(){
    cout << "Object deleted\n";
}

bool Vegetables::loadMedia(){
    if (Vegetables::Texture == NULL){
        std::cerr << "Failed to load texture image!" << std::endl;
        return false;
    }
    return true;
}

void Vegetables::setVegetables(int time, int harvestItems, bool harvest){
    growth_time = time;
    totalHarvest = harvestItems;
    harvestStatus = harvest;
}

SDL_Rect Vegetables::getRect(){
    return Rect;
}

int Vegetables::Sell(char type){
    if(type == 'C'){
        return carrot_price;
    }
    else if (type == 'R'){
        return radish_price;
    }
    else if (type == 'W'){
        return wheat_price;
    }
    return 0;
}
