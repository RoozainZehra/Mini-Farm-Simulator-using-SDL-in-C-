#pragma once
#include <iostream>
#include "sdlManager.hpp"
#include "Storage.hpp"
#include "Vegetables.hpp"
#include "Animals.hpp"
using namespace std;

class Marketplace{
    private:
    //Texture for market
    SDL_Texture* marketTexture = NULL;
    //market dimensions and position
    const int market_ht = 128;
    const int market_wdt = 100;
    const int market_x = 562;
    const int market_y = 86;

    SDL_Rect marketRect = {market_x, market_y, market_wdt, market_ht};

    public:
    Marketplace(SDL_Renderer* gRenderer);
    ~Marketplace();

    void marketRender(SDL_Renderer* gRenderer);
    bool loadMedia();

    SDL_Rect getSDLRect();
    template <typename T>
    void sellItems(Storage* store, T *item, char type){
        if (store->getAmount(type) >= 1){
            store->useMaterial(type);
            store->addMaterial('G', item->Sell(type));
        }   
    }
    template <typename T>
    bool Purchase(Storage* store, T *item, char type){
        if (store->getAmount('G') >= item->itemPrice(type)){
            cout << "buying" << endl;
            store->addMaterial('G', -(item->itemPrice(type)));
            return true;
        }
        return false;
    }
};
