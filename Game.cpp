#include "Game.hpp"


bool Game::init() {
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

// bool loadMedia();
void Game::close(){
    // Destroy renderer
    SDL_DestroyRenderer(gRenderer);

    // Destroy window
    SDL_DestroyWindow(gWindow);

    // Quit SDL subsystems
    SDL_Quit();
}


void Game::run(){
    bool quit = false;
    SDL_Event e;
    Farm *farm = new Farm(gRenderer); //initialize farm
    LandPatches *land = new LandPatches(gRenderer);
    Farmer *farmer = new Farmer(gRenderer);
    Storage *storage = new Storage(gRenderer);
    Marketplace *market = new Marketplace(gRenderer);

    while (!quit){
        while (SDL_PollEvent(&e) != 0){
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            SDL_RenderClear(gRenderer);
            farm->farmRender(gRenderer);
            land->landRender(gRenderer);
            land->patchRender(gRenderer);
            
            for (auto& vegies : v){     
                uint32_t check = vegies->timeElapsed();
                if (check >= 30000){
                vegies->Grow();
                }
                vegies->VegetableRenderer();
            }
            
            farmer->farmerRender(gRenderer);
            storage ->storageRender(gRenderer);
            market->marketRender(gRenderer);
            if (!farm->loadMedia() || !land->loadMedia() || !storage->loadMedia() || !market->loadMedia() || !farmer->loadMedia()){
                break;
            }
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        farmer ->movements('U');
                        break;
                    case SDLK_DOWN:
                        farmer ->movements('D');
                        break;
                    case SDLK_LEFT:
                        farmer ->movements('L');
                        break;
                    case SDLK_RIGHT:
                        farmer ->movements('R');
                        break;
                    default:
                        break;
                }
            }
            else if(e.type == SDL_MOUSEBUTTONDOWN){
                if(e.button.button == SDL_BUTTON_LEFT){
                    int mouseX, mouseY;
                    SDL_GetMouseState(&mouseX, &mouseY);
                    std::cout<< "Mouse clicked at X= " <<mouseX << ", Y= "<<mouseY << std::endl;
                }
            }
            vector<SDL_Rect> patches = land->GetSDLRect();
            for (auto& patch : patches){
                if (farmer->checkCollision(patch)){
                    land->createVeg(gRenderer, v);
                }
            }
            farmer->out_movement(SCREEN_WIDTH, SCREEN_HEIGHT);

            // Update screen
            SDL_Delay(50);
            SDL_RenderPresent(gRenderer);
            
        }
        
    }
}
