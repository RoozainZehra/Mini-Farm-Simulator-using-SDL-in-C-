#pragma once

#include <iostream>
#include "sdlManager.hpp"
using namespace std;

class Farm{
    private:
    SDL_Texture* farmTexture = NULL;
    SDL_Texture* fenceTexture = NULL;
    SDL_Rect fenceRect;

    public:
    Farm(SDL_Renderer* gRenderer);
    ~Farm();

    void farmRender(SDL_Renderer* gRenderer);
    bool loadMedia();
    // void HarvestVegetables();
    // void PlantVegetables(string VegetableType);
    // void FeedAnimals(string AnimalType);
    // void CollectAnimalProducts(string AnimalType);
    // void ExpandLandPatches(int num_patches);
};
