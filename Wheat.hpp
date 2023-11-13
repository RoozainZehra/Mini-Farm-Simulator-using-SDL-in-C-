#include <iostream>
using namespace std;
#include "Vegetables.hpp"

class Wheat: public Vegetables{
    private:
    int current_stage;

    public:
    Wheat();
    ~Wheat();
    void Sell(int qty);
    void Grow();
    void Harvest();
};