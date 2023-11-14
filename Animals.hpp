#include <iostream>
using namespace std;

class Animals{
    private:
    int produce_time;
    int current_time;
    public:
    Animals(int time);
    ~Animals();
    int getProduceTime();
    int getCurrentTime();
    void updateTime();
    virtual void sell(int qty) = 0;
    virtual void feed() = 0;
    virtual void produce() = 0;
    virtual void collectProduce() = 0;
    virtual void setHunger() = 0;
};