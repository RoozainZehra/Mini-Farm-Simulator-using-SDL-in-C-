#include <iostream>
using namespace std;

class GoldCoins{
    private:
    int qty;
    public:
    GoldCoins(int amount);
    ~GoldCoins();
    void Store_goldcoins(int amount);
    void display();
};