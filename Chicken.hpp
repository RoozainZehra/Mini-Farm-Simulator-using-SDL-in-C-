#include <iostream>
using namespace std;
#include "Animals.hpp"

class Chicken : public Animals{
    private:
    bool current_produce;
    bool hunger;
    int produce_amount;
    public:
    Chicken();
    ~Chicken();
    void sell(int qty); //will need to figure this one out
    void feed();
    void produce();
    // void collectProduce(); should return eggs
    void setHunger();
};