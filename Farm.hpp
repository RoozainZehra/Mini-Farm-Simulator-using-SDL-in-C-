#pragma once

#include <iostream>
#include "sdlManager.hpp"
#include "Animals.hpp"
#include "Cow.hpp"
#include "Chicken.hpp"
using namespace std;

class Farm{
    private:
    SDL_Texture* farmTexture = NULL;
    SDL_Texture* fenceTexture = NULL;
    SDL_Rect fenceRect = {470, 300, 310, 320}; //cow fence
    SDL_Rect fenceRect2 = {137, 69, 250, 150}; //chicken fence



    public:
    Farm(SDL_Renderer* gRenderer);
    ~Farm();

    void farmRender(SDL_Renderer* gRenderer);
    bool loadMedia();
    void getAnimals(SDL_Renderer* gRenderer, vector <Animals*> &A);
    SDL_Rect getFence(char type);
    // void HarvestVegetables();
    // void PlantVegetables(string VegetableType);
    // void FeedAnimals(string AnimalType);
    // void CollectAnimalProducts(string AnimalType);
    // void ExpandLandPatches(int num_patches);
};