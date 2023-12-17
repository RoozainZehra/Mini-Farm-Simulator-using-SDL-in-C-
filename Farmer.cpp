
#include "Farmer.hpp"
Farmer::Farmer(SDL_Renderer* gRenderer){
        TextureManager element(gRenderer);
        farmerTexture = element.loadTexture("farmer.png");
}

void Farmer::farmerRender(SDL_Renderer* gRenderer){
    farmerRect = { farmer_x, farmer_y, farmer_wdt, farmer_ht };
    SDL_RenderCopy(gRenderer, farmerTexture, NULL, &farmerRect);
}

bool Farmer::loadMedia(){
    if (farmerTexture == NULL){
        std::cerr << "Failed to load texture image!" << std::endl;
        return false;
    }
    return true;
}

Farmer::~Farmer(){
    SDL_DestroyTexture(farmerTexture);
}


void Farmer::out_movement(int sw, int sh) {
    //cow fence
    const int fence_x = 470; // X-coordinate of the fence's top-left corner
    const int fence_y = 300; // Y-coordinate of the fence's top-left corner
    const int fence_width = 310; // Width of the fence
    const int fence_height = 320; // Height of the fence
    //chicken fence
    int fence2_x = 137;
    int fence2_y = 69;
    int fence2_height = 150;
    // barn/storage
    const int barn_ht = 180;
    const int barn_x = 390;
    const int barn_y = 32;
    // market
    const int market_ht = 128;
    const int market_x = 562;
    const int market_y = 86; 
    const int total_width = 500;


    // Assuming farmer_wdt and farmer_ht represent the width and height of the farmer

    if (farmer_x < 0) {
        farmer_x = sw;
    } else if (farmer_x > sw) {
        farmer_x = 0;
    }

    if (farmer_y < 0) {
        farmer_y = sh;
    } else if (farmer_y > sh) {
        farmer_y = 0;
    }

    // Check if the farmer is within or intersecting the restricted area of the fence
    else if (farmer_x + farmer_wdt >= fence_x && farmer_x <= fence_x + fence_width &&
        farmer_y + farmer_ht >= fence_y && farmer_y <= fence_y + fence_height) {

        // Calculate distances to each edge of the fence
        int dist_left = fence_x - (farmer_x + farmer_wdt);
        int dist_right = farmer_x - (fence_x + fence_width);
        int dist_top = fence_y - (farmer_y + farmer_ht);
        int dist_bottom = farmer_y - (fence_y + fence_height);

        // Find the minimum distance
        int min_dist = min(min(abs(dist_left), abs(dist_right)),
                           min(abs(dist_top), abs(dist_bottom)));

        // Adjust farmer's position based on the fence boundary
        if (min_dist == abs(dist_left)) {
            farmer_x = fence_x - farmer_wdt; // Move left of the fence
        } else if (min_dist == abs(dist_right)) {
            farmer_x = fence_x + fence_width; // Move right of the fence
        } else if (min_dist == abs(dist_top)) {
            farmer_y = fence_y - farmer_ht; // Move above the fence
        } else {
            farmer_y = fence_y + fence_height - farmer_ht; // Move below the fence
        }
    }
}


// void Farmer::out_movement(int sw, int sh) {
//     // Cow fence
//     const int cow_fence_x = 470;
//     const int cow_fence_y = 300;
//     const int cow_fence_width = 310;
//     const int cow_fence_height = 320;

//     // Chicken fence
//     const int chicken_fence_x = 137;
//     const int chicken_fence_y = 69;
//     const int chicken_fence_height = 150;

//     // Barn
//     const int barn_height = 180;
//     const int barn_x = 390;
//     const int barn_y = 32;

//     // Market
//     const int market_height = 128;
//     const int market_x = 562;
//     const int market_y = 86;

//     const int total_width = 500;

//     // Assuming farmer_width and farmer_height represent the width and height of the farmer

//     if (farmer_x < 0) {
//         farmer_x = sw;
//     } else if (farmer_x > sw) {
//         farmer_x = 0;
//     }

//     if (farmer_y < 0) {
//         farmer_y = sh;
//     } else if (farmer_y > sh) {
//         farmer_y = 0;
//     }

//     // Check for cow fence restriction
//     if (farmer_x + farmer_wdt >= cow_fence_x && farmer_x <= cow_fence_x + cow_fence_width &&
//         farmer_y + farmer_ht >= cow_fence_y && farmer_y <= cow_fence_y + cow_fence_height) {

//         // Adjust farmer's position to stay outside the cow fence
//         farmer_x = (farmer_x <= cow_fence_x) ? cow_fence_x - farmer_wdt : cow_fence_x + cow_fence_width;
//         farmer_y = (farmer_y <= cow_fence_y) ? cow_fence_y - farmer_ht : cow_fence_y + cow_fence_height - farmer_ht;
//     }

//     // Check for chicken fence restriction
//     if (farmer_x >= chicken_fence_x && farmer_x <= chicken_fence_x + total_width &&
//         farmer_y >= chicken_fence_y && farmer_y <= chicken_fence_y + chicken_fence_height) {

//         // Adjust farmer's position to stay outside the chicken fence
//         farmer_x = (farmer_x <= chicken_fence_x) ? chicken_fence_x - farmer_wdt : chicken_fence_x + total_width;
//         farmer_y = (farmer_y <= chicken_fence_y) ? chicken_fence_y - farmer_ht : chicken_fence_y + chicken_fence_height - farmer_ht;
//     }

//     // Check for barn restriction
//     if (farmer_x >= barn_x && farmer_x <= barn_x + total_width &&
//         farmer_y >= barn_y && farmer_y <= barn_y + barn_height) {

//         // Adjust farmer's position to stay outside the barn
//         farmer_x = (farmer_x <= barn_x) ? barn_x - farmer_wdt : barn_x + total_width;
//         farmer_y = (farmer_y <= barn_y) ? barn_y - farmer_ht : barn_y + barn_height - farmer_ht;
//     }

//     // Check for market restriction
//     if (farmer_x >= market_x && farmer_x <= market_x + total_width &&
//         farmer_y >= market_y && farmer_y <= market_y + market_height) {

//         // Adjust farmer's position to stay outside the market
//         farmer_x = (farmer_x <= market_x) ? market_x - farmer_wdt : market_x + total_width;
//         farmer_y = (farmer_y <= market_y) ? market_y - farmer_ht : market_y + market_height - farmer_ht;
//     }
// }



SDL_Rect Farmer::Get_SDlRECT(){
    return farmerRect;
}

bool Farmer::checkCollision(SDL_Rect b) {
    // std::cout << "farmer at x = " << farmer_x << " y = " << farmer_y << std::endl;
    if ((farmerRect.x < (b.x + b.w) && farmerRect.x + farmerRect.w > b.x) && 
        (farmerRect.y < (b.y + b.h) && farmerRect.y + farmerRect.h > b.y)) {
        // std::cout << "collision detected" << std::endl;
        return true;
    } else {
        // std::cout << "no collision at x = " << b.x << " and y = " << b.y << std::endl;
        return false;
    }
}

void Farmer::movements(char x){
    switch (x) {
        case 'U':
            farmer_y -= 10;
            break;
        case 'D':
            farmer_y += 10;
            break;
        case 'L':
            farmer_x -= 10;
            break;
        case 'R':
            farmer_x += 10;
            break;
        default:
            break;
    }
}