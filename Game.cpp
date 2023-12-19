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

    startScreen = new Startscreen(gRenderer);
    if(game == GameState::MENU){
        if (!startScreen->loadStartscreenImage()) {
            return false;
        }
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

//function to check whether the barn/storage has been clicked.
bool Game::isClickedOnBarn(int clickX, int clickY) {
    // The barn's coordinates
    int barnTopLeftX = 392;
    int barnTopLeftY = 64;
    int barnBottomRightX = 534;
    int barnBottomRightY = 211;

    // if the click is within the barn's area
    if (clickX >= barnTopLeftX && clickX <= barnBottomRightX && clickY >= barnTopLeftY && clickY <= barnBottomRightY) {
        return true;
    }
    return false;
}

//function to check if amrket has been clicked.
bool Game::isClickedOnMarket(int clickX, int clickY) {
    // The barn's coordinates
    int barnTopLeftX = 567;
    int barnTopLeftY = 87;
    int barnBottomRightX = 655;
    int barnBottomRightY = 212;

    // if the click is within the barn's area
    if (clickX >= barnTopLeftX && clickX <= barnBottomRightX && clickY >= barnTopLeftY && clickY <= barnBottomRightY) {
        return true;
    }
    return false;
}

//function to create and return texture.
SDL_Texture* Game::loadTexture(const std::string& filePath, SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(filePath.c_str());
    if (surface == NULL) {
        std::cerr << "Unable to load image " << filePath << "! SDL_image Error: " << IMG_GetError() << std::endl;
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

// Function to render a texture on a given renderer
void Game::renderTexture(SDL_Texture* texture, SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, texture, NULL, NULL);
}

// Function to initialize the storage window
void Game::createStorageWindow(SDL_Window* storageWindow, Storage *storage) {
    string eggs = to_string(storage->getAmount('E'));
    string milk = to_string(storage->getAmount('M'));
    string coins = to_string(storage->getAmount('G'));
    string carrot = to_string(storage->getAmount('C'));
    string radish = to_string(storage->getAmount('R'));
    string wheat = to_string(storage->getAmount('W'));

    if (storageWindow == nullptr) {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
            return;
        }

        // Initialize SDL_ttf
        if (TTF_Init() == -1) {
            std::cerr << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
            SDL_Quit();
            return;
        }

        storageWindow = SDL_CreateWindow("Storage Screen", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 400, SDL_WINDOW_SHOWN);
        if (storageWindow != nullptr) {
            SDL_Renderer* storageRenderer = SDL_CreateRenderer(storageWindow, -1, SDL_RENDERER_ACCELERATED);
            if (storageRenderer != nullptr) {
                SDL_Texture* storageImage = loadTexture("Storage.png", storageRenderer);
                if (storageImage != nullptr) {
                    // Load the font
                    TTF_Font* font = TTF_OpenFont("8514oem.fon", 14); // Replace with your font path
                    if (font == nullptr) {
                        std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
                    } 
                    else {
                        SDL_Surface* eggSurface = TTF_RenderText_Solid(font, eggs.c_str(), {0,0,0,0});
                        SDL_Surface* milkSurface = TTF_RenderText_Solid(font, milk.c_str(), {0,0,0,0});
                        SDL_Surface* coinSurface = TTF_RenderText_Solid(font, coins.c_str(), {0,0,0,0});
                        SDL_Surface* carrotSurface = TTF_RenderText_Solid(font, carrot.c_str(), {0,0,0,0});
                        SDL_Surface* radishSurface = TTF_RenderText_Solid(font, radish.c_str(), {0,0,0,0});
                        SDL_Surface* wheatSurface = TTF_RenderText_Solid(font, wheat.c_str(), {0,0,0,0});
                        if (eggSurface == nullptr || milkSurface == nullptr || coinSurface == nullptr || carrotSurface == nullptr || radishSurface == nullptr || wheatSurface == nullptr) {
                            std::cerr << "Unable to create text surface! SDL Error: " << SDL_GetError() << std::endl;
                        } 
                        else {
                            SDL_Texture* eggTexture = SDL_CreateTextureFromSurface(storageRenderer, eggSurface);
                            SDL_Texture* milkTexture = SDL_CreateTextureFromSurface(storageRenderer, milkSurface);
                            SDL_Texture* coinTexture = SDL_CreateTextureFromSurface(storageRenderer, coinSurface);
                            SDL_Texture* carrotTexture = SDL_CreateTextureFromSurface(storageRenderer, carrotSurface);
                            SDL_Texture* radishTexture = SDL_CreateTextureFromSurface(storageRenderer, radishSurface);
                            SDL_Texture* wheatTexture = SDL_CreateTextureFromSurface(storageRenderer, wheatSurface);
                            if (eggTexture == nullptr || eggTexture == nullptr || milkTexture == nullptr || carrotTexture == nullptr || radishTexture == nullptr || wheatTexture == nullptr) {
                                std::cerr << "Unable to create text texture! SDL Error: " << SDL_GetError() << std::endl;
                            } 
                            else {
                                SDL_Rect eggRect = { 230, 325, eggSurface->w, eggSurface->h }; // Adjust position
                                SDL_Rect milkRect = { 108, 325, milkSurface->w, milkSurface->h };
                                SDL_Rect coinRect = { 362, 325, coinSurface->w, coinSurface->h };
                                SDL_Rect carrotRect = { 230, 195, carrotSurface->w, carrotSurface->h };
                                SDL_Rect radishRect = { 362, 195, radishSurface->w, radishSurface->h };
                                SDL_Rect wheatRect = { 108, 195, wheatSurface->w, wheatSurface->h };
                                
                                bool quitStorage = false;
                                while (!quitStorage) {
                                    SDL_Event event;
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_QUIT) {
                                            quitStorage = true;
                                        } else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE) {
                                            quitStorage = true;
                                        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                                            if (event.button.button == SDL_BUTTON_LEFT) {
                                                int mouseX, mouseY;
                                                SDL_GetMouseState(&mouseX, &mouseY);
                                                std::cout << "Storage mouse clicked at X= " << mouseX << ", Y= " << mouseY << std::endl;
                                            }
                                        }
                                    }

                                    SDL_RenderClear(storageRenderer);
                                    renderTexture(storageImage, storageRenderer);
                                    SDL_RenderCopy(storageRenderer, eggTexture, NULL, &eggRect);
                                    SDL_RenderCopy(storageRenderer, milkTexture, NULL, &milkRect);
                                    SDL_RenderCopy(storageRenderer, coinTexture, NULL, &coinRect);
                                    SDL_RenderCopy(storageRenderer, carrotTexture, NULL, &carrotRect);
                                    SDL_RenderCopy(storageRenderer, radishTexture, NULL, &radishRect);
                                    SDL_RenderCopy(storageRenderer, wheatTexture, NULL, &wheatRect);
                                    SDL_RenderPresent(storageRenderer);
                                }

                                SDL_DestroyTexture(eggTexture);
                                SDL_DestroyTexture(milkTexture);
                                SDL_DestroyTexture(coinTexture);
                                SDL_DestroyTexture(carrotTexture);
                                SDL_DestroyTexture(radishTexture);
                                SDL_DestroyTexture(wheatTexture);
                            }
                            SDL_FreeSurface(eggSurface);
                            SDL_FreeSurface(milkSurface);
                            SDL_FreeSurface(coinSurface);
                            SDL_FreeSurface(carrotSurface);
                            SDL_FreeSurface(radishSurface);
                            SDL_FreeSurface(wheatSurface);
                        }
                        TTF_CloseFont(font);
                    }

                    SDL_DestroyTexture(storageImage);
                    SDL_DestroyRenderer(storageRenderer);
                    SDL_DestroyWindow(storageWindow);
                    storageWindow = nullptr;
                }
            }
        }
    }
}

// Function to initialize the market window
void Game::createMarketWindow(SDL_Window* marketWindow, SDL_Renderer* Renderer, LandPatches *land, Storage *storage, Marketplace *market) {
    Animals* animal;
    LandPatches* patch;
    Vegetables* vegetable;
    if (marketWindow == nullptr) {
        marketWindow = SDL_CreateWindow("Market Screen", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500,400, SDL_WINDOW_SHOWN);
        if (marketWindow != nullptr) {
            // Create renderer for market window
            SDL_Renderer* marketRenderer = SDL_CreateRenderer(marketWindow, -1, SDL_RENDERER_ACCELERATED);
            if (marketRenderer != nullptr) {
                // Load the market image
                SDL_Texture* marketImage = loadTexture("market.png", marketRenderer);
                if (marketImage != nullptr) {
                    bool quitMarket = false;
                    while (!quitMarket) {
                        SDL_Event event;
                        while (SDL_PollEvent(&event)) {
                            if (event.type == SDL_QUIT) {
                                quitMarket = true; // Handle SDL_QUIT event to exit the loop
                            }
                            // Handle window close event
                            else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE) {
                                quitMarket = true;
                            }
                            else if (event.type == SDL_MOUSEBUTTONDOWN){
                                if (event.button.button == SDL_BUTTON_LEFT){
                                    int mouseX, mouseY;
                                    SDL_GetMouseState(&mouseX, &mouseY);
                                    std::cout << "Market mouse clicked at X= " << mouseX << ", Y= " << mouseY << std::endl;
                                    if (mouseY >= 162 && mouseY <= 232){
                                        if (mouseX >= 88 && mouseX <= 130){
                                            market->sellItems(storage, vegetable, 'W');
                                        }
                                        else if (mouseX >= 132 && mouseX <= 185){
                                            market->sellItems(storage, vegetable, 'R');
                                        }
                                        else if (mouseX >= 187 && mouseX <= 225){
                                            market->sellItems(storage, vegetable, 'C');
                                        }
                                        else if (mouseX >= 290 && mouseX <= 355){
                                            if(market->Purchase(storage, animal, 'E')){
                                                Animals* chicken = new Chicken(Renderer);
                                                a.push_back(chicken);
                                            }
                                        }
                                        else if (mouseX >= 360 && mouseX <= 430){
                                            if(market->Purchase(storage, animal, 'M')){
                                                Animals* cow = new Cow(Renderer);
                                                a.push_back(cow);
                                            }
                                        }
                                    }
                                    else if (mouseY >= 256 && mouseY <= 320){
                                        if (mouseX >= 105 && mouseX <= 155){
                                            market->sellItems(storage, animal, 'E');
                                        }
                                        else if (mouseX >= 155 && mouseX <= 215){
                                            market->sellItems(storage, animal, 'M');
                                        }
                                        else if (mouseX >= 335 && mouseX <= 390){
                                            if (market->Purchase(storage, patch, 'P')){
                                                land->UnlockPatch();
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // Render the storage image
                        SDL_RenderClear(marketRenderer);
                        renderTexture(marketImage, marketRenderer);
                        SDL_RenderPresent(marketRenderer);
                    }
                    // Cleanup: Free loaded image and renderer
                    SDL_DestroyTexture(marketImage);
                    SDL_DestroyRenderer(marketRenderer);
                    SDL_DestroyWindow(marketWindow);
                    marketWindow = nullptr;
                }
            }
        }
    }
}
//function to handle the entire game logic/game play.
bool Game::Game_logic(SDL_Event &e, bool quit){
    Farm *farm = new Farm(gRenderer);
    LandPatches *land = new LandPatches(gRenderer);
    Farmer *farmer = new Farmer(gRenderer);
    Storage *storage = new Storage(gRenderer);
    Marketplace *market = new Marketplace(gRenderer);
    GameOver *gameover = new GameOver(gRenderer);
    
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
            } 
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    int mouseX, mouseY;
                    SDL_GetMouseState(&mouseX, &mouseY);
                    std::cout << "Mouse clicked at X= " << mouseX << ", Y= " << mouseY << std::endl;
                }
                if (e.button.button == SDL_BUTTON_LEFT) {
                    int mouseX, mouseY;
                    SDL_GetMouseState(&mouseX, &mouseY);
                    std::cout << "Mouse clicked at X= " << mouseX << ", Y= " << mouseY << std::endl;
                    // Check if the click is on the barn
                    if (isClickedOnBarn(mouseX, mouseY)) {   
                        createStorageWindow(storageWindow, storage);      
                    }
                    if (isClickedOnMarket(mouseX, mouseY)) {   
                        createMarketWindow(marketWindow, gRenderer, land, storage, market);      
                    }
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
        if (storageWindow != nullptr) {
            // Set the rendering context to the storage window
            SDL_Renderer* storageRenderer = SDL_CreateRenderer(storageWindow, -1, SDL_RENDERER_ACCELERATED);

            // Clear the storage window
            SDL_SetRenderDrawColor(storageRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(storageRenderer);

            // Render the storage screen
            storage->storageRender(storageRenderer);
            // Additional logic to handle interactions within the storage screen

            // Update the storage window
            SDL_RenderPresent(storageRenderer);
        }
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
                if(storage->getAmount(animal->feedType()) >= 1){
                    if(animal->feed()){
                        storage->useMaterial(animal->feedType());
                    }
                }
                
            }
        }
        if(game_over){
            SDL_RenderClear(gRenderer);
            gameover -> render(gRenderer);
            SDL_RenderPresent(gRenderer);
        }
        else{
            farmer->farmerRender(gRenderer);
            storage->storageRender(gRenderer);
            market->marketRender(gRenderer);

            farmer->out_movement(SCREEN_WIDTH, SCREEN_HEIGHT);

            // Update screen
            SDL_RenderPresent(gRenderer);
        }
        SDL_Delay(50); // Add a small delay for better control of frame rate
    }
    // Cleanup (deallocate memory, etc.) before exiting the game
    delete farm;
    delete land;
    delete farmer;
    delete storage;
    delete market;

    return quit;
}

//game run.
void Game::run() {
    bool quit = false;
    SDL_Event e;
    // bool showStorageWindow = false;
    while (!quit){
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (game == GameState::MENU){
               startScreen->handleEvent(e, game);
            }
        }
        if (game == GameState::MENU) {
            startScreen->render();
        } 
        else if (game == GameState::PLAYING) {
            quit = Game_logic(e, quit);
            
        }
        SDL_Delay(50);
    }
}
