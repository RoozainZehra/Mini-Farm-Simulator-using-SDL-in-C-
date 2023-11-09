#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

class Game {
    // Screen dimension constants
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 600;

    // The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    // The window renderer
    SDL_Renderer* gRenderer = NULL;

    // Current displayed texture
    SDL_Texture* gTexture = NULL;
    // Global reference to png image sheets
    SDL_Texture* assets = NULL;

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
            }

            // Clear the screen
            SDL_RenderClear(gRenderer);

            // Render the image
            SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

            // Update screen
            SDL_RenderPresent(gRenderer);
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
