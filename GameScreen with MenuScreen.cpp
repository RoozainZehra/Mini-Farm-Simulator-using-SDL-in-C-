// // #include <SDL.h>
// // #include <SDL_image.h>
// // #include <iostream>
// // #include <string>

// // enum class GameState{
// //     MENU,
// //     PLAYING
// // };
// // class GameMenu{
    
// //     // The window renderer
// //     SDL_Renderer* mRenderer = NULL;

// //     // Current displayed texture
// //     SDL_Texture* mTexture = NULL;
    
// //     public:
// //     GameMenu(SDL_Renderer* renderer) : mRenderer(renderer), mTexture(nullptr) {}

// //     bool loadMenuImage() {
//     //     // Load menu image
//     //     SDL_Surface* surface = IMG_Load("MenuScreen.png");
//     //     if (surface == nullptr) {
//     //         return false;
//     //     }

//     //     mTexture = SDL_CreateTextureFromSurface(mRenderer, surface);
//     //     if (mTexture == nullptr) {
//     //         return false;
//     //     }

//     //     SDL_FreeSurface(surface);
//     //     return true;
//     // }

// //     void handleEvent(SDL_Event& e, GameState& gameState){
//     //     if (e.type == SDL_MOUSEBUTTONDOWN){
//     //         gameState = GameState::PLAYING;
//     //     }
//     // }
//     // void render(){
//     //     if (mTexture){
//     //         SDL_RenderCopy(mRenderer, mTexture, NULL, NULL);
//     //     }
// //     }

// // };
// class Game {
//     // Screen dimension constants
//     const int SCREEN_WIDTH = 1100;
//     const int SCREEN_HEIGHT = 700;

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
//     //Texture for Trees
//     SDL_Texture* treesTexture = NULL;

//     //farmers dimensions
//     const int farmer_ht = 90;
//     const int farmer_wdt = 70;
//     int farmer_x = 0;
//     int farmer_y = 0;

//     //barn dimensions and initial position
//     const int barn_ht = 318;
//     const int barn_wdt = 312;
//     const int barn_x = 354;
//     const int barn_y = -30;

//     //market dimensions and initial position
//     const int market_ht = 180;
//     const int market_wdt = 150;
//     const int market_x = 672;
//     const int market_y = 56;

//     //trees dimensions and initial position
//     const int tree_ht = 184;
//     const int tree_wdt = 177;
//     const int tree_x = 940;
//     // const int tree_y = 514;

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
//         gTexture = loadTexture("grass.jpeg");
//         if (gTexture == NULL) {
//             std::cerr << "Failed to load texture image!" << std::endl;
//             return false;
//         }
//         //Load farmer image
//         SDL_Surface* surface = IMG_Load("farmer.png");
//         if (surface == nullptr) {
//             return false;
//         }
//         farmerTexture = SDL_CreateTextureFromSurface(gRenderer, surface);
//         if (farmerTexture == nullptr) {
//             return false;
//         }

//         //Load barn image
//         SDL_Surface* surface2 = IMG_Load("barn.png");
//         if (surface2 == nullptr) {
//             return false;
//         }
//         barnTexture = SDL_CreateTextureFromSurface(gRenderer, surface2);
//         if (barnTexture == nullptr) {
//             return false;
//         }

//         //Load barn image
//         SDL_Surface* surface3 = IMG_Load("market.png");
//         if (surface3 == nullptr) {
//             return false;
//         }
//         marketTexture = SDL_CreateTextureFromSurface(gRenderer, surface3);
//         if (marketTexture == nullptr) {
//             return false;
//         }

//         //Load trees on the screen
//         SDL_Surface* surface4 = IMG_Load("3trees.png");
//         if (surface4 == nullptr) {
//             return false;
//         }
//         treesTexture = SDL_CreateTextureFromSurface(gRenderer, surface4);
//         if (treesTexture == nullptr) {
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
//                     // Render the image
//                     SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

//                     //Render the farmer image
//                     SDL_Rect farmerRect = { farmer_x, farmer_y, farmer_wdt, farmer_ht };
//                     SDL_RenderCopy(gRenderer, farmerTexture, NULL, &farmerRect);

//                     //Render the barn image
//                     SDL_Rect barnRect = { barn_x, barn_y, barn_wdt, barn_ht };
//                     SDL_RenderCopy(gRenderer, barnTexture, NULL, &barnRect);

//                     //Render the market image
//                     SDL_Rect marketRect = { market_x, market_y, market_wdt, market_ht};
//                     SDL_RenderCopy(gRenderer, marketTexture, NULL, &marketRect);

//                     //Render the tree image
//                     SDL_Rect treeRect1 = {tree_x, 100, tree_wdt, tree_ht};
//                     SDL_RenderCopy(gRenderer, treesTexture, NULL, &treeRect1);
//                     SDL_Rect treeRect2 = {tree_x, 250, tree_wdt, tree_ht};
//                     SDL_RenderCopy(gRenderer, treesTexture, NULL, &treeRect2);
//                     SDL_Rect treeRect3 = {tree_x, 400, tree_wdt, tree_ht};
//                     SDL_RenderCopy(gRenderer, treesTexture, NULL, &treeRect3);
//                     SDL_Rect treeRect4 = {tree_x, 550, tree_wdt, tree_ht};
//                     SDL_RenderCopy(gRenderer, treesTexture, NULL, &treeRect4);
//                     SDL_Rect treeRect5 = {tree_x, 700, tree_wdt, tree_ht};
//                     SDL_RenderCopy(gRenderer, treesTexture, NULL, &treeRect5);
//                     SDL_Rect treeRect6 = {tree_x, 850, tree_wdt, tree_ht};
//                     SDL_RenderCopy(gRenderer, treesTexture, NULL, &treeRect6);
//                 break;
//                 }
//             // Update screen
//             SDL_RenderPresent(gRenderer);
//         }
//     }
// };

// // int main(int argc, char* args[]) {
// //     Game game;

// //     // Initialize SDL and load media
// //     if (!game.init() || !game.loadMedia()) {
// //         std::cerr << "Failed to initialize or load media!" << std::endl;
// //         return 1;
// //     }

// //     // Run the game
// //     game.run();

// //     // Free resources and close SDL
// //     game.close();

// //     return 0;
// // }
// // // g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o ghostbuster.exe
// // //Display Menu
// // // //print coordinates
// // // if (e.type == SDL_MOUSEBUTTONDOWN){
// // //     if (e.button.button == SDL_BUTTON_LEFT) {
// // //     int mouseX, mouseY;
// // //     SDL_GetMouseState(&mouseX, &mouseY);
// // //     std::cout << "Mouse clicked at: X = " << mouseX << ", Y = " << mouseY << std::endl;
// // // }
