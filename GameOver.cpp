#include "GameOver.hpp"

GameOver::GameOver(SDL_Renderer* gRenderer){
    TextureManager element(gRenderer);
    GTexture = element.loadTexture("Game_over.png");
}

void GameOver::render(SDL_Renderer* gRenderer){
    SDL_RenderCopy(gRenderer, GTexture, NULL, NULL);
}

bool GameOver::loadMedia(){
    if (GTexture == NULL){
        std::cerr << "Failed to load texture image!" << std::endl;
        return false;
    }
    return true;
}

GameOver::~GameOver(){
    SDL_DestroyTexture(GTexture);
}