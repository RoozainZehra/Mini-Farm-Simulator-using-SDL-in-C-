#include <iostream>
using namespace std;
#include "Farm.hpp"

class LandPatches: public Farm{
    private:
    int locked_patches;
    int open_patches;
    const int num_patches = 9;
    public:
    LandPatches(); //make default values 0
    ~LandPatches();
    template <typename T> void PlantVegOnPatch(T Vegetable);
    void UnlockPatch();
};