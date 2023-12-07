#include "Storage.hpp"

Storage::Storage(SDL_Renderer* gRenderer){
    TextureManager element(gRenderer);
    storageTexture = element.loadTexture("barn.png");
    TextureManager elementL(gRenderer);
    trees1Texture = elementL.loadTexture("treesLeft.png");
    TextureManager elementR(gRenderer);
    trees2Texture = elementR.loadTexture("treesRight.png");

    GoldCoins = 150;
    carrots = 1;
    wheat = 1;
    radish = 1;
    milk = 0;
    eggs = 0;
    seeds = 4;
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

void Storage::addMaterial(char Material, int qty){
    if (Material == 'M')
        milk += qty;
    else if (Material == 'E')
        eggs += qty;
    else if (Material == 'C')
        carrots += qty;
    else if (Material == 'R')
        radish += qty;
    else if (Material == 'W')
        wheat += qty;
    else
        GoldCoins += qty;

}

int Storage::getAmount(char Material){
    if (Material == 'M')
        return milk;
    else if (Material == 'E')
        return eggs;
    else if (Material == 'C')
        return carrots;
    else if (Material == 'R')
        return radish;
    else if (Material == 'W')
        return wheat;
    else
        return GoldCoins;


}

bool Storage::init() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create window
    StorageWindow = SDL_CreateWindow("Storage", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    if (StorageWindow == NULL) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create renderer
    StorageRenderer = SDL_CreateRenderer(StorageWindow, -1, SDL_RENDERER_ACCELERATED);

    if (StorageRenderer == NULL) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Set renderer color
    SDL_SetRenderDrawColor(StorageRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    return true;
}

void Storage::openStorage(){
    if (!init()){
        std::cerr << "Failed to initialize or load media!" << std::endl;
    }
}
