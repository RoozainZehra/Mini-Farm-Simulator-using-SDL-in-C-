// #include <SDL.h>
// #include <SDL_image.h>
// #include <iostream>
// #include <string>

// enum class GameState{
//     MENU,
//     PLAYING
// };
// class GameMenu{
    
//     // The window renderer
//     SDL_Renderer* mRenderer = NULL;

//     // Current displayed texture
//     SDL_Texture* mTexture = NULL;
    
//     public:
//     GameMenu(SDL_Renderer* renderer) : mRenderer(renderer), mTexture(nullptr) {}

//     bool loadMenuImage() {
//         // Load menu image
//         SDL_Surface* surface = IMG_Load("MenuScreen.png");
//         if (surface == nullptr) {
//             return false;
//         }

//         mTexture = SDL_CreateTextureFromSurface(mRenderer, surface);
//         if (mTexture == nullptr) {
//             return false;
//         }

//         SDL_FreeSurface(surface);
//         return true;
//     }

//     void handleEvent(SDL_Event& e, GameState& gameState){
//         if (e.type == SDL_MOUSEBUTTONDOWN){
//             gameState = GameState::PLAYING;
//         }
//     }
//     void render(){
//         if (mTexture){
//             SDL_RenderCopy(mRenderer, mTexture, NULL, NULL);
//         }
//     }

// };
// class Game {
//     // Screen dimension constants
//     const int SCREEN_WIDTH = 900;
//     const int SCREEN_HEIGHT = 650;

//     // The window we'll be rendering to
//     SDL_Window* gWindow = NULL;

//     // The window renderer
//     SDL_Renderer* gRenderer = NULL;

//     // Current displayed texture
//     SDL_Texture* gTexture = NULL;
//     // Global reference to png image sheets
//     SDL_Texture* assets = NULL;

//     //Texture for farmer
//     SDL_Texture* farmerTexture = NULL;
//     //Texture for barn
//     SDL_Texture* barnTexture = NULL;
//     //Texture for market
//     SDL_Texture* marketTexture = NULL;
//     //Texture for Trees1 and Trees2
//     SDL_Texture* trees1Texture = NULL;
//     SDL_Texture* trees2Texture = NULL;
//     //Texture for Farm Patch
//     SDL_Texture* patchTexture = NULL;
//     //Texture for fence
//     SDL_Texture* fenceTexture = NULL;
//     //Texture for locks
//     SDL_Texture* lockTexture = NULL;
//     //Texture for bushes
//     SDL_Texture* bushTexture = NULL;

//     //farmers dimensions
//     const int farmer_ht = 40;
//     const int farmer_wdt = 35;
//     int farmer_x = 40;
//     int farmer_y = 0;

//     //barn dimensions and position
//     const int barn_ht = 180;
//     const int barn_wdt = 150;
//     const int barn_x = 390;
//     const int barn_y = 32;

//     //market dimensions and position
//     const int market_ht = 128;
//     const int market_wdt = 100;
//     const int market_x = 562;
//     const int market_y = 86;

//     //trees dimensions and position
//     const int tree_ht = 680;
//     const int tree_wdt = 200;
//     const int treeL_x = -60;
//     const int treeL_y = 0;

//     const int treeR_x = 760;
//     const int treeR_y = -25;

//     //Land patch dimensions and position
//     const int patch_ht = 190;
//     const int patch_wdt = 190;
//     const int patch_x = 166;
//     const int patch_y = 413;

//     //animal fence dimensions and position
//     const int fence_ht = 320;
//     const int fence_wdt = 310;
//     const int fence_x = 470;
//     const int fence_y = 315;

//     //lock dimensions
//     const int lock_ht = 20;
//     const int lock_wdt = 15;

//     //bush dimensions
//     const int bush_ht = 50;
//     const int bush_wdt = 60;

//     // Joining Menu Screen with game screen
//     GameMenu gMenu;

//     //Game State
//     GameState gameState = GameState::MENU;
    
    
// public:
//     Game() : gMenu(gRenderer) {}
//     bool init() {
//         // Initialize SDL
//         if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//             std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
//             return false;
//         }

//         // Create window
//         gWindow = SDL_CreateWindow("Mini Farm", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

//         if (gWindow == NULL) {
//             std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//             return false;
//         }

//         // Create renderer
//         gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

//         if (gRenderer == NULL) {
//             std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//             return false;
//         }
//         gMenu = GameMenu(gRenderer);
//         if (!gMenu.loadMenuImage()) {
//             return false;
//         }
//         // Set renderer color
//         SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

//         return true;
//     }
 
//     bool loadMedia() {
//         // Load image
//         gTexture = loadTexture("grass2.png");
//         if (gTexture == NULL) {
//             std::cerr << "Failed to load texture image!" << std::endl;
//             return false;
//         }
//         //Load farmer image
//         SDL_Surface* farmerS = IMG_Load("farmer.png");
//         if (farmerS == nullptr) {
//             return false;
//         }
//         farmerTexture = SDL_CreateTextureFromSurface(gRenderer, farmerS);
//         if (gTexture == nullptr) {
//             return false;
//         }

//         //Load barn image
//         SDL_Surface* barnS = IMG_Load("barn.png");
//         if (barnS == nullptr) {
//             return false;
//         }
//         barnTexture = SDL_CreateTextureFromSurface(gRenderer, barnS);
//         if (barnTexture == nullptr) {
//             return false;
//         }

//         //Load marketplace image
//         SDL_Surface* marketS = IMG_Load("store.png");
//         if (marketS == nullptr) {
//             return false;
//         }
//         marketTexture = SDL_CreateTextureFromSurface(gRenderer, marketS);
//         if (marketTexture == nullptr) {
//             return false;
//         }

//         // Load trees1 and 2 on the screen
//         SDL_Surface* trees1S = IMG_Load("treesRight.png");
//         if (trees1S == nullptr) {
//             return false;
//         }
//         trees1Texture = SDL_CreateTextureFromSurface(gRenderer, trees1S);
//         if (gTexture == nullptr) {
//             return false;
//         }
//         SDL_Surface* trees2S = IMG_Load("treesLeft.png");
//         if (trees2S == nullptr) {
//             return false;
//         }
//         trees2Texture = SDL_CreateTextureFromSurface(gRenderer, trees2S);
//         if (gTexture == nullptr) {
//             return false;
//         }

//         //Load patch on the screen
//         SDL_Surface* patchS = IMG_Load("land.png");
//         if (patchS == nullptr) {
//             return false;
//         }
//         patchTexture = SDL_CreateTextureFromSurface(gRenderer, patchS);
//         if (gTexture == nullptr) {
//             return false;
//         }

//         //Load fence on the screen
//         SDL_Surface* fenceS = IMG_Load("fence.png");
//         if (fenceS == nullptr) {
//             return false;
//         }
//         fenceTexture = SDL_CreateTextureFromSurface(gRenderer, fenceS);
//         if (gTexture == nullptr) {
//             return false;
//         }

//         //Load lock on the patches on screen
//         SDL_Surface* lockS = IMG_Load("lock.png");
//         if (lockS == nullptr) {
//             return false;
//         }
//         lockTexture = SDL_CreateTextureFromSurface(gRenderer, lockS);
//         if (gTexture == nullptr) {
//             return false;
//         }

//         SDL_Surface* bush = IMG_Load("bush.png");
//         if (bush == nullptr) {
//             return false;
//         }
//         bushTexture = SDL_CreateTextureFromSurface(gRenderer, bush);
//         if (gTexture == nullptr) {
//             return false;
//         }

//         return true;
//     }


//     void close() {
//         // Free loaded image
//         SDL_DestroyTexture(gTexture);

//         // Destroy renderer
//         SDL_DestroyRenderer(gRenderer);

//         // Destroy window
//         SDL_DestroyWindow(gWindow);

//         // Quit SDL subsystems
//         SDL_Quit();
//     }
    
//     SDL_Texture* loadTexture(std::string path) {
//         // Load image at specified path
//         SDL_Surface* loadedSurface = IMG_Load(path.c_str());
//         if (loadedSurface == NULL) {
//             std::cerr << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
//             return NULL;
//         }

//         // Create texture from surface pixels
//         SDL_Texture* newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
//         if (newTexture == NULL) {
//             std::cerr << "Unable to create texture from image! SDL Error: " << SDL_GetError() << std::endl;
//         }

//         // Get rid of old loaded surface
//         SDL_FreeSurface(loadedSurface);

//         return newTexture;
//     }

//     void run() {
//         // Main loop
//         bool quit = false;
//         SDL_Event e;

//         while (!quit) {
//             // Handle events on queue
//             while (SDL_PollEvent(&e) != 0) {
//                 if (e.type == SDL_QUIT) {
//                     quit = true;
//                 }
//                 switch (gameState)
//                 {
//                     case GameState::MENU:
//                     gMenu.handleEvent(e, gameState);
//                     break;
//                     case GameState::PLAYING:
//                         //Handles the famers movement when key is pressed
//                         if (e.type == SDL_KEYDOWN) {
//                             switch (e.key.keysym.sym) {
//                                 case SDLK_UP:
//                                     farmer_y -= 10;
//                                     break;
//                                 case SDLK_DOWN:
//                                     farmer_y += 10;
//                                     break;
//                                 case SDLK_LEFT:
//                                     farmer_x -= 10;
//                                     break;
//                                 case SDLK_RIGHT:
//                                     farmer_x += 10;
//                                     break;
//                                 default:
//                                     break;
//                             }
//                         }
//                         //If farmer walks out of the screen, it comes back from the other side
//                         if (farmer_x < 0){
//                             farmer_x = SCREEN_WIDTH;
//                         }
//                         else if (farmer_x > SCREEN_WIDTH){
//                             farmer_x = 0;
//                         }
//                         if (farmer_y < 0){
//                             farmer_y = SCREEN_HEIGHT;
//                         }
//                         else if (farmer_y > SCREEN_HEIGHT){
//                             farmer_y = 0;
//                         }
//                         break;
//                     }
//                 }
//             // Clear the screen
//             SDL_RenderClear(gRenderer);
//             switch (gameState){
//                 case GameState::MENU:
//                     gMenu.render();
//                     break;
//                 case GameState::PLAYING:
//                     SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

//                     //Render the patch image
//                     SDL_Rect patchRect = { patch_x, patch_y, patch_wdt, patch_ht};
//                     SDL_RenderCopy(gRenderer, patchTexture, NULL, &patchRect);

//                     //Render the farmer image
//                     SDL_Rect farmerRect = { farmer_x, farmer_y, farmer_wdt, farmer_ht };
//                     SDL_RenderCopy(gRenderer, farmerTexture, NULL, &farmerRect);

//                     //Render the barn image
//                     SDL_Rect barnRect = { barn_x, barn_y, barn_wdt, barn_ht };
//                     SDL_RenderCopy(gRenderer, barnTexture, NULL, &barnRect);

//                     //Render the market image
//                     SDL_Rect marketRect = { market_x, market_y, market_wdt, market_ht};
//                     SDL_RenderCopy(gRenderer, marketTexture, NULL, &marketRect);

//                     //Render the fence image
//                     SDL_Rect fenceRect = { fence_x, fence_y, fence_wdt, fence_ht};
//                     SDL_RenderCopy(gRenderer, fenceTexture, NULL, &fenceRect);

//                     //Render the tree image
//                     SDL_Rect treesLRect = {treeL_x, treeL_y, tree_wdt, tree_ht};
//                     SDL_Rect treesRRect = {treeR_x, treeR_y, tree_wdt, tree_ht};
//                     SDL_RenderCopy(gRenderer, trees2Texture, NULL, &treesLRect);
//                     SDL_RenderCopy(gRenderer, trees1Texture, NULL, &treesRRect);

//                     //Render bush
//                     SDL_Rect bushRect = {340, 178, bush_wdt, bush_ht};
//                     SDL_Rect bushRect2 = {652, 178, bush_wdt, bush_ht};
//                     SDL_Rect bushRect3 = {115, 578, bush_wdt, bush_ht};
//                     SDL_Rect bushRect4 = {65, 300, bush_wdt, bush_ht};
//                     SDL_RenderCopy(gRenderer, bushTexture, NULL, &bushRect);
//                     SDL_RenderCopy(gRenderer, bushTexture, NULL, &bushRect2);
//                     SDL_RenderCopy(gRenderer, bushTexture, NULL, &bushRect3);
//                     SDL_RenderCopy(gRenderer, bushTexture, NULL, &bushRect4);
//                     SDL_Rect bushRect5 = {795, 480, bush_wdt, bush_ht};
//                     SDL_RenderCopy(gRenderer, bushTexture, NULL, &bushRect5);
//                     break;
//                 }
    
//             // Update screen
//             SDL_RenderPresent(gRenderer);
//         }
//     }
// };

// int main(int argc, char* args[]) {
//     Game game;

//     // Initialize SDL and load media
//     if (!game.init() || !game.loadMedia()) {
//         std::cerr << "Failed to initialize or load media!" << std::endl;
//         return 1;
//     }

//     // Run the game
//     game.run();

//     // Free resources and close SDL
//     game.close();

//     return 0;
// }