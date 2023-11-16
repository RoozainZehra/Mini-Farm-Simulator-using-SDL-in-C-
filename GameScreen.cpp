#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

class Game {
    // Screen dimension constants
    const int SCREEN_WIDTH = 1100;
    const int SCREEN_HEIGHT = 650;

    // The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    // The window renderer
    SDL_Renderer* gRenderer = NULL;

    // Current displayed texture
    SDL_Texture* gTexture = NULL;
    // Global reference to png image sheets
    SDL_Texture* assets = NULL;

    //Texture for farmer
    SDL_Texture* farmerTexture = NULL;
    //Texture for barn
    SDL_Texture* barnTexture = NULL;
    //Texture for market
    SDL_Texture* marketTexture = NULL;
    //Texture for Trees1 and Trees2
    SDL_Texture* trees1Texture = NULL;
    SDL_Texture* trees2Texture = NULL;
    //Texture for Farm Patch
    SDL_Texture* patchTexture = NULL;
    //Texture for fence
    SDL_Texture* fenceTexture = NULL;
    //Texture for locks
    SDL_Texture* lockTexture = NULL;

    //farmers dimensions
    const int farmer_ht = 90;
    const int farmer_wdt = 70;
    int farmer_x = 0;
    int farmer_y = 0;

    //barn dimensions and position
    const int barn_ht = 318;
    const int barn_wdt = 312;
    const int barn_x = 354;
    const int barn_y = -30;

    //market dimensions and position
    const int market_ht = 120;
    const int market_wdt = 90;
    const int market_x = 672;
    const int market_y = 86;

    //trees dimensions and position
    const int tree_ht = 184;
    const int tree_wdt = 177;
    const int tree_x = 955;
    // const int tree_y = 514;

    //Land patch dimensions and position
    const int patch_ht = 200;
    const int patch_wdt = 200;
    const int patch_x = 416;
    const int patch_y = 273;

    //animal fence dimensions and position
    const int fence_ht = 120;
    const int fence_wdt = 210;
    const int fence_x = 210;
    const int fence_y = 97;

    //lock dimensions
    const int lock_ht = 20;
    const int lock_wdt = 15;
    
public:
    bool init() {
        // Initialize SDL
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
            return false;
        }

        // Create window
        gWindow = SDL_CreateWindow("Mini Farm", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (gWindow == NULL) {
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            return false;
        }

        // Create renderer
        gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

        if (gRenderer == NULL) {
            std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            return false;
        }

        // Set renderer color
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

        return true;
    }
 
    bool loadMedia() {
        // Load image
        gTexture = loadTexture("grass.jpeg");
        if (gTexture == NULL) {
            std::cerr << "Failed to load texture image!" << std::endl;
            return false;
        }
        //Load farmer image
        SDL_Surface* farmerS = IMG_Load("farmer.png");
        if (farmerS == nullptr) {
            return false;
        }
        farmerTexture = SDL_CreateTextureFromSurface(gRenderer, farmerS);
        if (gTexture == nullptr) {
            return false;
        }

        //Load barn image
        SDL_Surface* barnS = IMG_Load("barn.png");
        if (barnS == nullptr) {
            return false;
        }
        barnTexture = SDL_CreateTextureFromSurface(gRenderer, barnS);
        if (barnTexture == nullptr) {
            return false;
        }

        //Load marketplace image
        SDL_Surface* marketS = IMG_Load("store.png");
        if (marketS == nullptr) {
            return false;
        }
        marketTexture = SDL_CreateTextureFromSurface(gRenderer, marketS);
        if (marketTexture == nullptr) {
            return false;
        }

        //Load trees1 and 2 on the screen
        SDL_Surface* trees1S = IMG_Load("3trees.png");
        if (trees1S == nullptr) {
            return false;
        }
        trees1Texture = SDL_CreateTextureFromSurface(gRenderer, trees1S);
        if (gTexture == nullptr) {
            return false;
        }
        SDL_Surface* trees2S = IMG_Load("3treesflip.png");
        if (trees2S == nullptr) {
            return false;
        }
        trees2Texture = SDL_CreateTextureFromSurface(gRenderer, trees2S);
        if (gTexture == nullptr) {
            return false;
        }

        //Load patch on the screen
        SDL_Surface* patchS = IMG_Load("landPatch.jpg");
        if (patchS == nullptr) {
            return false;
        }
        patchTexture = SDL_CreateTextureFromSurface(gRenderer, patchS);
        if (gTexture == nullptr) {
            return false;
        }

        //Load fence on the screen
        SDL_Surface* fenceS = IMG_Load("animalSpace.png");
        if (fenceS == nullptr) {
            return false;
        }
        fenceTexture = SDL_CreateTextureFromSurface(gRenderer, fenceS);
        if (gTexture == nullptr) {
            return false;
        }

        //Load lock on the patches on screen
        SDL_Surface* lockS = IMG_Load("lock.png");
        if (lockS == nullptr) {
            return false;
        }
        lockTexture = SDL_CreateTextureFromSurface(gRenderer, lockS);
        if (gTexture == nullptr) {
            return false;
        }

        return true;
    }

    void close() {
        // Free loaded image
        SDL_DestroyTexture(gTexture);

        // Destroy renderer
        SDL_DestroyRenderer(gRenderer);

        // Destroy window
        SDL_DestroyWindow(gWindow);

        // Quit SDL subsystems
        SDL_Quit();
    }
    
    SDL_Texture* loadTexture(std::string path) {
        // Load image at specified path
        SDL_Surface* loadedSurface = IMG_Load(path.c_str());
        if (loadedSurface == NULL) {
            std::cerr << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
            return NULL;
        }

        // Create texture from surface pixels
        SDL_Texture* newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL) {
            std::cerr << "Unable to create texture from image! SDL Error: " << SDL_GetError() << std::endl;
        }

        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);

        return newTexture;
    }

    void run() {
        // Main loop
        bool quit = false;
        SDL_Event e;

        while (!quit) {
            // Handle events on queue
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                }
                //Handles the famers movement when key is pressed
                else if (e.type == SDL_KEYDOWN) {
                    switch (e.key.keysym.sym) {
                        case SDLK_UP:
                            farmer_y -= 10;
                            break;
                        case SDLK_DOWN:
                            farmer_y += 10;
                            break;
                        case SDLK_LEFT:
                            farmer_x -= 10;
                            break;
                        case SDLK_RIGHT:
                            farmer_x += 10;
                            break;
                        default:
                            break;
                    }
                }
                //print coordinates
                else if (e.type == SDL_MOUSEBUTTONDOWN){
                    if (e.button.button == SDL_BUTTON_LEFT) {
                    int mouseX, mouseY;
                    SDL_GetMouseState(&mouseX, &mouseY);
                    std::cout << "Mouse clicked at: X = " << mouseX << ", Y = " << mouseY << std::endl;
                }
                }
                //If farmer walks out of the screen, it comes back from the other side
                if (farmer_x < 0){
                    farmer_x = SCREEN_WIDTH;
                }
                else if (farmer_x > SCREEN_WIDTH){
                    farmer_x = 0;
                }
                if (farmer_y < 0){
                    farmer_y = SCREEN_HEIGHT;
                }
                else if (farmer_y > SCREEN_HEIGHT){
                    farmer_y = 0;
                }
            // Clear the screen
            SDL_RenderClear(gRenderer);

            // Render the image
            SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

            //Render the patch image
            SDL_Rect patchRect = { patch_x, patch_y, patch_wdt, patch_ht};
            SDL_RenderCopy(gRenderer, patchTexture, NULL, &patchRect);

            //Render the locks on the patches
            SDL_Rect lock1Rect = {456, 312, lock_wdt, lock_ht};
            SDL_RenderCopy(gRenderer, lockTexture, NULL, &lock1Rect);
            SDL_Rect lock2Rect = {506, 312, lock_wdt, lock_ht};
            SDL_RenderCopy(gRenderer, lockTexture, NULL, &lock2Rect);
            SDL_Rect lock3Rect = {555, 312, lock_wdt, lock_ht};
            SDL_RenderCopy(gRenderer, lockTexture, NULL, &lock3Rect);
            SDL_Rect lock4Rect = {506, 362, lock_wdt, lock_ht};
            SDL_RenderCopy(gRenderer, lockTexture, NULL, &lock4Rect);
            SDL_Rect lock5Rect = {555, 362, lock_wdt, lock_ht};
            SDL_RenderCopy(gRenderer, lockTexture, NULL, &lock5Rect);
            SDL_Rect lock6Rect = {506, 412, lock_wdt, lock_ht};
            SDL_RenderCopy(gRenderer, lockTexture, NULL, &lock6Rect);
            SDL_Rect lock7Rect = {555, 412, lock_wdt, lock_ht};
            SDL_RenderCopy(gRenderer, lockTexture, NULL, &lock7Rect);

            //Render the farmer image
            SDL_Rect farmerRect = { farmer_x, farmer_y, farmer_wdt, farmer_ht };
            SDL_RenderCopy(gRenderer, farmerTexture, NULL, &farmerRect);

            //Render the barn image
            SDL_Rect barnRect = { barn_x, barn_y, barn_wdt, barn_ht };
            SDL_RenderCopy(gRenderer, barnTexture, NULL, &barnRect);

            //Render the market image
            SDL_Rect marketRect = { market_x, market_y, market_wdt, market_ht};
            SDL_RenderCopy(gRenderer, marketTexture, NULL, &marketRect);

            //Render the tree image
            SDL_Rect treeRect1 = {tree_x, 60, tree_wdt, tree_ht};
            SDL_RenderCopy(gRenderer, trees1Texture, NULL, &treeRect1);
            SDL_Rect treeRect2 = {tree_x, 190, tree_wdt, tree_ht};
            SDL_RenderCopy(gRenderer, trees2Texture, NULL, &treeRect2);
            SDL_Rect treeRect3 = {tree_x, 320, tree_wdt, tree_ht};
            SDL_RenderCopy(gRenderer, trees1Texture, NULL, &treeRect3);
            SDL_Rect treeRect4 = {tree_x, 450, tree_wdt, tree_ht};
            SDL_RenderCopy(gRenderer, trees2Texture, NULL, &treeRect4);
            SDL_Rect treeRect5 = {tree_x, 580, tree_wdt, tree_ht};
            SDL_RenderCopy(gRenderer, trees1Texture, NULL, &treeRect5);
            SDL_Rect treeRect6 = {tree_x, 710, tree_wdt, tree_ht};
            SDL_RenderCopy(gRenderer, trees2Texture, NULL, &treeRect6);

            int newtree_x = -20;
            SDL_Rect treeRect1f = {newtree_x, 60, tree_wdt, tree_ht};
            SDL_RenderCopy(gRenderer, trees1Texture, NULL, &treeRect1f);
            SDL_Rect treeRect2f = {newtree_x, 190, tree_wdt, tree_ht};
            SDL_RenderCopy(gRenderer, trees2Texture, NULL, &treeRect2f);
            SDL_Rect treeRect3f = {newtree_x, 320, tree_wdt, tree_ht};
            SDL_RenderCopy(gRenderer, trees1Texture, NULL, &treeRect3f);
            SDL_Rect treeRect4f = {newtree_x, 450, tree_wdt, tree_ht};
            SDL_RenderCopy(gRenderer, trees2Texture, NULL, &treeRect4f);
            SDL_Rect treeRect5f = {newtree_x, 580, tree_wdt, tree_ht};
            SDL_RenderCopy(gRenderer, trees1Texture, NULL, &treeRect5f);
            SDL_Rect treeRect6f = {newtree_x, 710, tree_wdt, tree_ht};
            SDL_RenderCopy(gRenderer, trees2Texture, NULL, &treeRect6f);

            //Render the fence image
            SDL_Rect fenceRect = { fence_x, fence_y, fence_wdt, fence_ht};
            SDL_RenderCopy(gRenderer, fenceTexture, NULL, &fenceRect);

            // Update screen
            SDL_RenderPresent(gRenderer);
        }
    }
    }
};

int main(int argc, char* args[]) {
    Game game;

    // Initialize SDL and load media
    if (!game.init() || !game.loadMedia()) {
        std::cerr << "Failed to initialize or load media!" << std::endl;
        return 1;
    }

    // Run the game
    game.run();

    // Free resources and close SDL
    game.close();

    return 0;
}
// g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o ghostbuster.exe
