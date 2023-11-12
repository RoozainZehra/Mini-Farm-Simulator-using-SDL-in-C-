#include <iostream>
using namespace std;
#include "AnimalProducts.hpp"
#include "HarvestSupplies.hpp"
#include "Seeds.hpp"
#include "GoldCoins.hpp"

class Storage{
    private:
    Coins GoldCoins;
    Seeds seeds;
    vector<AnimalProducts> Products;
    vector<HarvestSupplies> Harvest;
    public:
    virtual void Store_AnimalProducts(string Animal, int qty);
    virtual void Store_seeds(int amount);
    virtual void Store_goldcoins(int amount);
    virtual void Store_harvestSupplies(string vegetables, int qty);
};