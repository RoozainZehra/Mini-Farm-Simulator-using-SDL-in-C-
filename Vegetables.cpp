#include "Vegetables.hpp"

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

void Vegetables::setVegetables(int price, int time, int harvestItems, bool harvest){
    selling_price = price;
    growth_time = time;
    totalHarvest = harvestItems;
    harvestStatus = harvest;
}

SDL_Rect Vegetables::getRect(){
    return Rect;
}
