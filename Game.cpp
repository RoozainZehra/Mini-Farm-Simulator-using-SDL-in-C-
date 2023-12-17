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


void Game::run() {
    bool quit = false;
    bool displayOn = false;
    SDL_Event e;
    // bool showStorageWindow = false;
    Farm *farm = new Farm(gRenderer);
    LandPatches *land = new LandPatches(gRenderer);
    Farmer *farmer = new Farmer(gRenderer);
    Storage *storage = new Storage(gRenderer);
    Marketplace *market = new Marketplace(gRenderer);

    while (!quit && !game_over) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }

            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        farmer->movements('U');
                        break;
                    case SDLK_DOWN:
                        farmer->movements('D');
                        break;
                    case SDLK_LEFT:
                        farmer->movements('L');
                        break;
                    case SDLK_RIGHT:
                        farmer->movements('R');
                        break;
                    default:
                        break;
                }
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    int mouseX, mouseY;
                    SDL_GetMouseState(&mouseX, &mouseY);
                    std::cout << "Mouse clicked at X= " << mouseX << ", Y= " << mouseY << std::endl;
                    Animals* cow = new Cow(gRenderer);
                    a.push_back(cow);
                }
            }

        }

        // Clear the renderer
        SDL_RenderClear(gRenderer);

        // Rendering game elements
        farm->farmRender(gRenderer);
        land->landRender(gRenderer);
        land->patchRender(gRenderer);
        land->getPatches(P);

        for (auto& patch : P){
            if (farmer->checkCollision(patch)){
                if (land->isPlanted(patch)){
                    Vegetables* veg = land->returnVeg(v, patch);
                    if (veg != nullptr){
                        if (veg->isHarvestable()){
                            storage->addMaterial(veg->Type(), veg->Harvest());
                            land->setEmpty(v, patch);
                        }
                    }
                }
                else{
                    land->createVeg(gRenderer, v, patch);
                }
            }
        }


        // farm->getAnimals(gRenderer, a);


        for (int i=0; i<9; i++) {
            if (v[i] != nullptr){
                v[i]->Grow();
                v[i]->VegetableRenderer();
            }
        }


        // Render animals after updating positions
        for (auto& animal : a) {
            uint32_t check = (SDL_GetTicks() - animal->creation_time) % 10;
            if (check == 0){
                animal->walk();
            }
            game_over = animal->animalSick();
            animal->AnimalRenderer();
            animal->setHunger();
            animal->setProduce();
            if (farmer->checkCollision(farm->getFence(animal->Type()))){
                if(animal->produce()){
                    storage->addMaterial(animal->Type(), animal->collectProduce());
                }
                if(animal->feed()){
                    storage->useMaterial(animal->feedType());
                }
            }
        }

        farmer->farmerRender(gRenderer);
        storage->storageRender(gRenderer);
        market->marketRender(gRenderer);

        farmer->out_movement(SCREEN_WIDTH, SCREEN_HEIGHT);

        // Update screen
        SDL_RenderPresent(gRenderer);

        SDL_Delay(50); // Add a small delay for better control of frame rate
    }

    // Cleanup (deallocate memory, etc.) before exiting the game
    delete farm;
    delete land;
    delete farmer;
    delete storage;
    delete market;
}