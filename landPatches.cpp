#include "landPatches.hpp"

LandPatches::LandPatches(){ //make default values 0
    locked_patches = 7;
    open_patches = 2;
}

LandPatches::~LandPatches(){}
template <typename T> void LandPatches::PlantVegOnPatch(T Vegetable){
    //connect vegetables here and code to show their
    //growth + may need to create new function in 
    //vegetable class to make this work
}
void LandPatches::UnlockPatch(){
    //code here to remove locks from patches
    if ((open_patches + locked_patches == num_patches) && ( open_patches <= num_patches) && (locked_patches <= num_patches)){
        open_patches ++;
        locked_patches--;
    }    
}