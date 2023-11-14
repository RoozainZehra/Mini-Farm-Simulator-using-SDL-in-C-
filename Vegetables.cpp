#include "Vegetables.hpp"

Vegetables::Vegetables(bool grow, int price, int time, bool harvest){
    grown = grow;
    selling_price = price;
    growth_time = time;
    harvestStatus = 0;
}

Vegetables::~Vegetables(){
    cout << "Object deleted\n";
}

void Vegetables::SetGrown(){
    grown = 1;
}
void Vegetables::SetHarvest(){
    harvestStatus = 1;
}

