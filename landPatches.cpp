#include "landPatches.hpp"

LandPatches::LandPatches(SDL_Renderer* gRenderer){ //make default values 0
    plantStatus.fill(false);

    locked_patches = 7;
    open_patches = 2;
    p1 = true;
    p2 = true;
    TextureManager element(gRenderer);
    landTexture = element.loadTexture("land.png");
    TextureManager elementP(gRenderer);
    patchTexture = elementP.loadTexture("patch.png");
}
LandPatches::~LandPatches(){
    SDL_DestroyTexture(landTexture);
    SDL_DestroyTexture(patchTexture);
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

        AllPatches.push_back(patch3);
        break;
    case 4:
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch1);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch2);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch3);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch4);

        AllPatches.push_back(patch4);
        break;
    case 5:
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch1);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch2);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch3);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch4);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch5);

        AllPatches.push_back(patch5);
        break;
    case 6:
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch1);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch2);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch3);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch4);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch5);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch6);

        AllPatches.push_back(patch6);
        break;
    case 7:
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch1);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch2);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch3);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch4);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch5);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch6);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch7);

        AllPatches.push_back(patch7);
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

        AllPatches.push_back(patch8);
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

        AllPatches.push_back(patch9);
        break;
    default:
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch1);
        SDL_RenderCopy(gRenderer, patchTexture, NULL, &patch2);
        AllPatches.push_back(patch1);
        AllPatches.push_back(patch2);
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

void LandPatches::createVeg(SDL_Renderer* gRenderer, vector <Vegetables*> &V ){
    if (p1 && !plantStatus[0]){
        plantStatus[0] = true;
        std::cout << "patch 1 planted" << std::endl;
        Vegetables* c1 = new Carrot(gRenderer, patch1_x);
        V.push_back(c1);
    }                                            
    else if (p2 && !plantStatus[1]){
        plantStatus[1] = true;
        Vegetables* c2 = new Carrot(gRenderer, patch2_x);
        std::cout << "patch 2 planted" << std::endl;
        V.push_back(c2);
    }
    else if (p3){
        Vegetables* c3 = new Carrot(gRenderer, patch3_x);
        std::cout << "patch 3 planted" << std::endl;
        V.push_back(c3);
    }
    else if (p4){
        Vegetables* c4 = new Carrot(gRenderer, patch4_x);
        std::cout << "patch 4 planted" << std::endl;
        V.push_back(c4);
    }
    else if (p5){
        Vegetables* c5 = new Carrot(gRenderer, patch5_x);
        std::cout << "patch 5 planted" << std::endl;
        V.push_back(c5);
    }
    else if (p6){
        Vegetables* c6 = new Carrot(gRenderer, patch6_x);
        std::cout << "patch 6 planted" << std::endl;
        V.push_back(c6);
    }
    else if (p7){
        Vegetables* c7 = new Carrot(gRenderer, patch7_x);
        std::cout << "patch 7 planted" << std::endl;
        V.push_back(c7);
    }
    else if (p8){
        Vegetables* c8 = new Carrot(gRenderer, patch8_x);
        std::cout << "patch 8 planted" << std::endl;
        V.push_back(c8);
    }
    else if (p9){
        Vegetables* c9 = new Carrot(gRenderer, patch9_x);
        std::cout << "patch 9 planted" << std::endl;
        V.push_back(c9);
    }

}

void LandPatches::UnlockPatch(){
    //code here to remove locks from patches
    if ((open_patches + locked_patches == num_patches) && ( open_patches <= num_patches) && (locked_patches <= num_patches)){
        open_patches ++;
        locked_patches--;

        switch (open_patches)
        {
        case 3:
            p3 = true;
            break;
        case 4:
            p3 = true;
            break;
        case 5:
            p3 = true;
            break;
        case 6:
            p3 = true;
            break;
        case 7:
            p3 = true;
            break;
        case 8:
            p3 = true;
            break;
        case 9:
            p3 = true;
            break;
        default:
            p1 = true;
            p2 = true;
            break;
        }
    }    
}
