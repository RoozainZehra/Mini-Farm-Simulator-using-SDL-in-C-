#include <iostream>
using namespace std;

class Vegetables{
    private:
    bool grown;
    int selling_price; //make constant
    int growth_time; //make constant
    public:
    Vegetables();
    ~Vegetables();
    void Sell(int qty);
    void Grow();
    void Harvest();
};