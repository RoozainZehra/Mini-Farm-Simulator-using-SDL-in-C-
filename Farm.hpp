#pragma once

#include <iostream>
#include "sdlManager.hpp"

class Farmer{
    private:
    const int farmer_ht = 40;
    const int farmer_wdt = 35;
    int farmer_x = 40;
    int farmer_y = 0;
    SDL_Texture* farmerTexture = NULL;
    SDL_Rect farmerRect = { farmer_x, farmer_y, farmer_wdt, farmer_ht };
    
    public:
    Farmer(SDL_Renderer* gRenderer);
    ~Farmer();

    void farmerRender(SDL_Renderer* gRenderer);
    bool loadMedia();
    void movements(char x);
    void out_movement(int sw, int sh);
    SDL_Rect Get_SDlRECT();
    // void HarvestVegetables();
    // void PlantVegetables(string VegetableType);
    // void FeedAnimals(string AnimalType);
    // void CollectAnimalProducts(string AnimalType);
    // void ExpandLandPatches(int num_patches);
};
