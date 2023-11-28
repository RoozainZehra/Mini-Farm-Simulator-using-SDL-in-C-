#include "Storage.hpp"

Storage::Storage(SDL_Renderer* gRenderer){
    TextureManager element(gRenderer);
    storageTexture = element.loadTexture("barn.png");
    TextureManager elementL(gRenderer);
    trees1Texture = elementL.loadTexture("treesLeft.png");
    TextureManager elementR(gRenderer);
    trees2Texture = elementR.loadTexture("treesRight.png");
}

Storage::~Storage(){
    SDL_DestroyTexture(storageTexture);
    SDL_DestroyTexture(trees1Texture);
    SDL_DestroyTexture(trees2Texture);
}


void Storage::storageRender(SDL_Renderer* gRenderer){
    SDL_RenderCopy(gRenderer, storageTexture, NULL, &storageRect);
    SDL_RenderCopy(gRenderer, trees1Texture, NULL, &leftTrees);
    SDL_RenderCopy(gRenderer, trees2Texture, NULL, &rightTrees);
}

bool Storage::loadMedia(){
    if (storageTexture == NULL || trees1Texture == NULL || trees2Texture == NULL){
        std::cerr << "Failed to load texture image!" << std::endl;
        return false;
    }
    return true;
}

SDL_Rect Storage::getSDLRect(){
    return storageRect;
}


