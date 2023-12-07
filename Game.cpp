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

    flag = false;

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
    SDL_Event e;
    Farm *farm = new Farm(gRenderer);
    LandPatches *land = new LandPatches(gRenderer);
    Farmer *farmer = new Farmer(gRenderer);
    Storage *storage = new Storage(gRenderer);
    Marketplace *market = new Marketplace(gRenderer);

    while (!quit) {
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

                    // Animals* cow = new Cow(gRenderer); // Example: Creating a cow
                    // // cow->setPosition(mouseX, mouseY); // Set the position of the animal
                    // a.push_back(cow); // Add the animal to the vector

                    // Animals* chicken = new Chicken(gRenderer);
                    // a.push_back(chicken);
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
                land->createVeg(gRenderer, v, patch);
            }
        }


        // farm->getAnimals(gRenderer, a);
        for (auto& vegies : v) {
            uint32_t check = vegies->timeElapsed();
            if (check >= 30000 && check < 70000) {
                vegies->Grow();
            } else if (check >= 70000) {
                vegies->Grow();
            }
            vegies->VegetableRenderer();
        }

        // Render animals after updating positions
        for (auto& animal : a) {
            uint32_t check = (SDL_GetTicks() - animal->creation_time) % 10;
            if (check == 0){
                animal->walk();
            }
            animal->AnimalRenderer();
        }

        if (farmer->checkCollision(storage->getSDLRect()) && flag==false){
            storage->openStorage();
            flag=true;
        }
        else{
            flag = false;
        }

        farmer->farmerRender(gRenderer);
        storage->storageRender(gRenderer);
        market->marketRender(gRenderer);
        // farmer->farmerRender(gRenderer);

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
