#include <iostream>
using namespace std;

class Seeds{
    private:
    int qty;
    public:
    Seeds(int seed);
    ~Seeds();
    void Store_seeds(int amount);
    void display();
};