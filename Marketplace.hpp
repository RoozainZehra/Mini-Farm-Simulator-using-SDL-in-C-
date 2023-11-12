#include <iostream>
#include <vector>
using namespace std;
#include "Offer_for_seeds.hpp"
#include "Offer_for_coins.hpp"

class Marketplace{
    private:
    vector<Offer_for_seeds> SeedOffers;
    vector<Offer_for_coins> CoinOffers;
    public:
    void Purchase(int gold_coins, int qty);
    // void Purchase(int num_seeds, int qty); // needs to be connected
    void ViewOffers();
};