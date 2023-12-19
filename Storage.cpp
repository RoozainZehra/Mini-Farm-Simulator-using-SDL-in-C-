#include "Storage.hpp"

int Storage::GoldCoins = 150;
int Storage::carrots = 1;
int Storage::wheat = 1;
int Storage::radish = 1;
int Storage::milk = 0;
int Storage::eggs = 0;
int Storage::seeds = 4;

Storage::Storage(SDL_Renderer* gRenderer){
    TextureManager element(gRenderer);
    storageTexture = element.loadTexture("barn.png");
    TextureManager elementL(gRenderer);
    trees1Texture = elementL.loadTexture("treesLeft.png");
    TextureManager elementR(gRenderer);
    trees2Texture = elementR.loadTexture("treesRight.png");
}

Storage::Storage(){} //constructor overload

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

void Storage::addMaterial(char Material, int qty){
    if (Material == 'M'){
        milk += qty;
        cout << "milk added " << qty << " total: " << milk << endl;
    }
    else if (Material == 'E'){
        eggs += qty;
        cout << "eggs added " << qty << " total: " << eggs << endl;
    }
    else if (Material == 'C'){
        carrots += qty;
        cout << "carrot added " << qty << " total: " << carrots << endl;
    }
    else if (Material == 'R'){
        radish += qty;
        cout << "radish added " << qty << " total: " << radish << endl;
    }
    else if (Material == 'W'){
        wheat += qty;
        cout << "wheat added " << qty << " total: " << wheat << endl;
    }
    else{
        GoldCoins += qty;
        cout << "coins added " << qty << " total: " << GoldCoins << endl;
    }

}

int Storage::getAmount(char Material){
    if (Material == 'M'){
        return milk;
    }
    else if (Material == 'E'){
        return eggs;
    }
    else if (Material == 'C'){
        return carrots;
    }
    else if (Material == 'R'){
        return radish;
    }
    else if (Material == 'W'){
        return wheat;
    }
    else{
        cout << "total coins " << GoldCoins << endl; 
        return GoldCoins;
    }
}

void Storage::useMaterial(char Material){
    if (Material == 'M'){
        milk--;
        cout << "milk used" << endl;
    }
    else if (Material == 'E'){
        eggs--;
        cout << "eggs used" << endl;
    }
    else if (Material == 'C'){
        carrots--;
        cout << "carrot used" << endl;
    }
    else if (Material == 'R'){
        radish--;
        cout << "radish used" << endl;
    }
    else if (Material == 'W'){
        wheat--;
        cout << "wheat used" << endl;
    }
    else{
        GoldCoins--;
        cout << "coins used" << endl;
    }
}
