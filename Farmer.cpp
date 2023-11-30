
#include "Farmer.hpp"
Farmer::Farmer(SDL_Renderer* gRenderer){
        TextureManager element(gRenderer);
        farmerTexture = element.loadTexture("farmer.png");
}

void Farmer::farmerRender(SDL_Renderer* gRenderer){
    farmerRect = { farmer_x, farmer_y, farmer_wdt, farmer_ht };
    SDL_RenderCopy(gRenderer, farmerTexture, NULL, &farmerRect);
}

bool Farmer::loadMedia(){
    if (farmerTexture == NULL){
        std::cerr << "Failed to load texture image!" << std::endl;
        return false;
    }
    return true;
}

Farmer::~Farmer(){
    SDL_DestroyTexture(farmerTexture);
}

void Farmer::out_movement(int sw, int sh){
    if (farmer_x < 0){
        farmer_x = sw;
    }
    else if (farmer_x > sw){
        farmer_x = 0;
    }
    if (farmer_y < 0){
        farmer_y = sh;
    }
    else if (farmer_y > sh){
        farmer_y = 0;
    }
}

SDL_Rect Farmer::Get_SDlRECT(){
    return farmerRect;
}

bool Farmer::checkCollision( SDL_Rect b ){
    if(farmerRect.x == b.x && farmerRect.y == b.x) {
        return true;
    }  
    return false;
}

void Farmer::movements(char x){
    switch (x) {
        case 'U':
            farmer_y -= 10;
            break;
        case 'D':
            farmer_y += 10;
            break;
        case 'L':
            farmer_x -= 10;
            break;
        case 'R':
            farmer_x += 10;
            break;
        default:
            break;
    }
}