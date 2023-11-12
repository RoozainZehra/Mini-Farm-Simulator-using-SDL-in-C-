#include <iostream>
using namespace std;
#include "Farm.hpp"

class LandPatches: public Farm{
    private:
    int locked_patches;
    int open_patches;
    int num_patches;
    public:
    LandPatches(); //make default values 0
    ~LandPatches();
    void PlantVegOnPatch(string Vegetable);
    void UnlockPatch();
};