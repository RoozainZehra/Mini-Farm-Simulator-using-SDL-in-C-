#include "Marketplace.hpp"

Marketplace::Marketplace(SDL_Renderer* gRenderer){
    TextureManager element(gRenderer);
    marketTexture = element.loadTexture("store.png");
}

Marketplace::~Marketplace(){
    SDL_DestroyTexture(marketTexture);
}


void Marketplace::marketRender(SDL_Renderer* gRenderer){
    SDL_RenderCopy(gRenderer, marketTexture, NULL, &marketRect);
}

bool Marketplace::loadMedia(){
    if (marketTexture == NULL){
        std::cerr << "Failed to load texture image!" << std::endl;
        return false;
    }
    return true;
}

SDL_Rect Marketplace::getSDLRect(){
    return marketRect;
}