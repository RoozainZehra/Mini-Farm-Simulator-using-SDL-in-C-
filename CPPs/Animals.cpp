#include "Animals.hpp"

int Animals::egg_price = 15;
int Animals::milk_price = 25;
int Animals::cow_price = 150;
int Animals::chicken_price = 100;

Animals::Animals(){
    // constructor  
}

Animals::~Animals(){
    delete this;
}

void Animals::AnimalRenderer(){
    SDL_RenderCopy(Renderer, Texture, &Rect, &moverRect);  //displays the animal
    if (alert){
        SDL_RenderCopy(Renderer, alertTexture, NULL, &alertRect);
    }
}

bool Animals::loadMedia(){
    if (Texture == NULL){
        std::cerr << "Failed to load texture image!" << std::endl;
        return false;
    }
    return true;
}

int Animals::Sell(char type){
    if (type == 'E'){
        return egg_price;
    }
    else if (type == 'M'){
        return milk_price;
    }
    return 0;
}

int Animals::itemPrice(char type){
    if (type == 'M'){ //price of cow
        cout << "cow price " << cow_price << endl;
        return cow_price;
    }
    else if (type == 'E'){ //price of chicken
        cout << "chicken price " << chicken_price << endl;
        return chicken_price;
    }
    return 0;
}
