#include "Animals.hpp"

Animals::Animals(){
    // cout << "animal created" << endl;
}

Animals::~Animals(){
    delete this;
}

void Animals::AnimalRenderer(){
    SDL_RenderCopy(Renderer, Texture, &Rect, &moverRect);  //displays the animal
}

bool Animals::loadMedia(){
    if (Texture == NULL){
        std::cerr << "Failed to load texture image!" << std::endl;
        return false;
    }
    return true;
}
