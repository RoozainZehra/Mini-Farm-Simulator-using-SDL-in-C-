#include "Farm.hpp"

Farm::Farm(SDL_Renderer* gRenderer){
    TextureManager element(gRenderer);
    farmTexture = element.loadTexture("grass2.png");
    TextureManager element_2(gRenderer);    
    fenceTexture = element_2.loadTexture("fence.png");
}

void Farm::farmRender(SDL_Renderer* gRenderer){
    SDL_RenderCopy(gRenderer, farmTexture, NULL, NULL);
    fenceRect = {470, 300, 310, 320};
    SDL_RenderCopy(gRenderer, fenceTexture, NULL, &fenceRect);
}

bool Farm::loadMedia(){
    if (farmTexture == NULL || fenceTexture == NULL){
        std::cerr << "Failed to load texture image!" << std::endl;
        return false;
    }
    return true;
}

Farm::~Farm(){
    SDL_DestroyTexture(farmTexture);
}
