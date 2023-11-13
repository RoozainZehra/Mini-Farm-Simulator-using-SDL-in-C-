#include <iostream>
using namespace std;

class Vegetables{
    private:
    bool grown;
    int selling_price; //make constant
    int growth_time; //make constant
    bool harvestStatus;
    
    public:
    Vegetables(bool grow, int price, int time, bool harvest);
    ~Vegetables();
    virtual void Sell(int qty) = 0;
    virtual void Grow() = 0;
    virtual void Harvest() = 0;
    void SetGrown();
    void SetHarvest();
};