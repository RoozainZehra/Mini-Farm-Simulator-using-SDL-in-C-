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


void Farmer::out_movement(int sw, int sh) {
    // Constants for fences, barn, and market
    const int fence_x = 470;
    const int fence_y = 300;
    const int fence_width = 310;
    const int fence_height = 320;

    const int fence2_x = 137;
    const int fence2_y = 69;
    const int fence2_width = 250;
    const int fence2_height = 150;

    const int barn_ht = 180;
    const int barn_x = 390;
    const int barn_y = 32;
    const int barn_width = 150;

    const int market_ht = 128;
    const int market_x = 562;
    const int market_y = 86; 
    const int market_width = 100;

    // Assuming farmer_wdt and farmer_ht represent the width and height of the farmer

    // Check and adjust for the cow fence
    if (farmer_x + farmer_wdt > fence_x && farmer_x < fence_x + fence_width &&
        farmer_y + farmer_ht > fence_y && farmer_y < fence_y + fence_height) {

        if (farmer_x < fence_x) {
            farmer_x = fence_x - farmer_wdt;
        } else if (farmer_x > fence_x + fence_width - farmer_wdt) {
            farmer_x = fence_x + fence_width;
        }

        if (farmer_y < fence_y) {
            farmer_y = fence_y - farmer_ht;
        } else if (farmer_y > fence_y + fence_height - farmer_ht) {
            farmer_y = fence_y + fence_height;
        }
    }

    // Check and adjust for the chicken fence
    if (farmer_x + farmer_wdt > fence2_x && farmer_x < fence2_x + fence2_width &&
        farmer_y + farmer_ht > fence2_y && farmer_y < fence2_y + fence2_height) {

        if (farmer_x < fence2_x) {
            farmer_x = fence2_x - farmer_wdt;
        } else if (farmer_x > fence2_x + fence2_width - farmer_wdt) {
            farmer_x = fence2_x + fence2_width;
        }

        if (farmer_y < fence2_y) {
            farmer_y = fence2_y - farmer_ht;
        } else if (farmer_y > fence2_y + fence2_height - farmer_ht) {
            farmer_y = fence2_y + fence2_height;
        }
    }

    // Check and adjust for the barn
    if (farmer_x + farmer_wdt > barn_x && farmer_x < barn_x + barn_width &&
        farmer_y + farmer_ht > barn_y && farmer_y < barn_y + barn_ht) {

        // if (farmer_x < barn_x) {
        //     farmer_x = barn_x - farmer_wdt;
        if (farmer_x > barn_x + barn_width){
            farmer_x = barn_x + barn_width;
        }

        if (farmer_y + farmer_ht > barn_y + barn_ht){
            farmer_y = barn_y + barn_ht;
        }
    }

    // Check and adjust for the market
    if (farmer_x + farmer_wdt > market_x && farmer_x < market_x + market_width &&
        farmer_y + farmer_ht > market_y && farmer_y < market_y + market_ht) {

        if (farmer_x < market_x) {
            farmer_x = market_x - farmer_wdt;
        } else if (farmer_x > market_x + market_width - farmer_wdt) {
            farmer_x = market_x + market_width;
        }

        if (farmer_y < market_y) {
            farmer_y = market_y - farmer_ht;
        } else if (farmer_y > market_y + market_ht - farmer_ht) {
            farmer_y = market_y + market_ht;
        }
    }

    // Boundary checking
    if (farmer_x < 0) {
        farmer_x = sw;
    } else if (farmer_x > sw) {
        farmer_x = 0;
    }

    if (farmer_y < 0) {
        farmer_y = sh;
    } else if (farmer_y > sh) {
        farmer_y = 0;
    }
}

SDL_Rect Farmer::Get_SDlRECT(){
    return farmerRect;
}

bool Farmer::checkCollision(SDL_Rect b) {
    if ((farmerRect.x < (b.x + b.w) && farmerRect.x + farmerRect.w > b.x) && 
        (farmerRect.y < (b.y + b.h) && farmerRect.y + farmerRect.h > b.y)) {
        return true;
    } else {
        return false;
    }
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
