#include <iostream>
using namespace std;

class Farm{
    
    public:
    Farm();
    ~Farm();

    void HarvestVegetables();
    void PlantVegetables(string VegetableType);
    void FeedAnimals(string AnimalType);
    void CollectAnimalProducts(string AnimalType);
    void ExpandLandPatches(int num_patches);
};