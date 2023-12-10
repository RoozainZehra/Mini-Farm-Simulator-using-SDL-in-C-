#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Game.hpp"


int main(int argc, char* argv[]){
    Game game;
    // Initialize SDL and load media
    if (!game.init()) {
        std::cerr << "Failed to initialize or load media!" << std::endl;
        return 1;
    }

    // Run the game
    game.run();

    // Free resources and close SDL
    game.close();

    return 0;
}
