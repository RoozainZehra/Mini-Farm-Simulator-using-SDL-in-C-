#include <iostream>
using namespace std;
#include "Animals.hpp"

class Cow : public Animals{
    private:
    int current_produce;
    bool hunger;
    int produce_amount;
    public:
    Cow();
    ~Cow();
    void sell(int qty);
    void feed();
    void produce();
    // void collectProduce(); should return milk, will need to increment in storage
    void setHunger();
};