#include "Farm.hpp"

Farm::Farm(SDL_Renderer* gRenderer){
    TextureManager element(gRenderer);
    farmTexture = element.loadTexture("grass2.png");    
}

void Farm::farmRender(SDL_Renderer* gRenderer){
    SDL_RenderCopy(gRenderer, farmTexture, NULL, NULL);
}

bool Farm::loadMedia(){
    if (farmTexture == NULL){
        std::cerr << "Failed to load texture image!" << std::endl;
        return false;
    }
    return true;
}

Farm::~Farm(){
    SDL_DestroyTexture(farmTexture);
}
