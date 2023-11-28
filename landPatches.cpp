#include "landPatches.hpp"

LandPatches::LandPatches(SDL_Renderer* gRenderer){ //make default values 0
    locked_patches = 7;
    open_patches = 2;
    TextureManager element(gRenderer);
    landTexture = element.loadTexture("land.png");
    TextureManager elementP(gRenderer);
    patchTexture = elementP.loadTexture("patch.png");
}

void LandPatches::landRender(SDL_Renderer* gRenderer){
    SDL_Rect landRect = { land_x, land_y, land_wdt, land_ht};
    SDL_RenderCopy(gRenderer, landTexture, NULL, &landRect);
}


void LandPatches::patchRender(SDL_Renderer* gRenderer){
    switch (open_patches)
    {
    case 3:
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch1);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch2);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch3);
        break;
    case 4:
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch1);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch2);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch3);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch4);
        break;
    case 5:
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch1);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch2);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch3);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch4);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch5);
        break;
    case 6:
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch1);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch2);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch3);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch4);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch5);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch6);
        break;
    case 7:
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch1);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch2);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch3);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch4);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch5);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch6);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch7);
        break;
    case 8:
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch1);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch2);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch3);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch4);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch5);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch6);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch7);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch8);
        break;
    case 9:
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch1);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch2);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch3);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch4);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch5);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch6);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch7);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch8);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch9);
        break;
    default:
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch1);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch2);
        break;
    }
}

bool LandPatches::loadMedia(){
    if (landTexture == NULL || patchTexture == NULL){
        std::cerr << "Failed to load texture image!" << std::endl;
        return false;
    }
    return true;
}

void LandPatches::drawVeg(){
    if (!p1){
        p1 = true;
        Vegetables* c = new Carrot(gRenderer, patch1_x)
        c ->
    }

}

// void LandPatches::UnlockPatch(){
//     //code here to remove locks from patches
//     if ((open_patches + locked_patches == num_patches) && ( open_patches <= num_patches) && (locked_patches <= num_patches)){
//         open_patches ++;
//         locked_patches--;
//     }    
// }