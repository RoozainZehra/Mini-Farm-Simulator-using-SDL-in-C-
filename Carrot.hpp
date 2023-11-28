#include <iostream>
using namespace std;
#include "Vegetables.hpp"

class Carrot:public Vegetables{
    private:
    int current_stage;


    public:
    Carrot(SDL_Renderer* gRenderer);
    ~Carrot();
    // void Sell(int qty);
    // void Grow();
    // void Harvest();
};
