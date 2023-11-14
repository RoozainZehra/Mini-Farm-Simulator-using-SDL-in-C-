#include <iostream>
using namespace std;
#include "Vegetables.hpp"

class Radish: public Vegetables{
    private:
    int current_stage;

    public:
    Radish();
    ~Radish();
    void Sell(int qty);
    void Grow();
    void Harvest(); 
};
