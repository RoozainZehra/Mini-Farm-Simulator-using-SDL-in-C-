#include "Startscreen.hpp"

Startscreen::Startscreen(SDL_Renderer* renderer) : mRenderer(renderer), mTexture(nullptr) {}

Startscreen::~Startscreen() {
    SDL_DestroyTexture(mTexture);
}

void Startscreen::handleEvent(SDL_Event& e, GameState& gamestate) {
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        // Define the restricted region
        int minX = 500;  
        int maxX = 700; 
        int minY = 400;  
        int maxY = 450;  

        // Check if the click is within the restricted region
        if (mouseX >= minX && mouseX <= maxX && mouseY >= minY && mouseY <= maxY) {
            gamestate = GameState::PLAYING;
        }
    }
}


bool Startscreen::loadStartscreenImage() {
    SDL_Surface* surface = IMG_Load("menu.png");
    if (surface == nullptr) {
        return false;
    }
    mTexture = SDL_CreateTextureFromSurface(mRenderer, surface);
    if (mTexture == nullptr) {
        SDL_FreeSurface(surface);
        return false;
    }

    SDL_FreeSurface(surface);
    return true;
}

bool Startscreen::loadMedia(){
    if (mTexture == NULL){
        std::cerr << "Failed to load texture image!" << std::endl;
        return false;
    }
    return true;
}

void Startscreen::render() {
    SDL_RenderClear(mRenderer);
    if (mTexture) {
        SDL_RenderCopy(mRenderer, mTexture, NULL, NULL);
    }
    SDL_RenderPresent(mRenderer);
}
