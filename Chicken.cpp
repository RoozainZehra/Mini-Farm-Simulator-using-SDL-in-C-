#include "Chicken.hpp"

Chicken::Chicken(SDL_Renderer* gRenderer){
    static int chicken = 1;
    static bool maxChicken = false;  //can have at max 7 chickens
    
    current_produce = 0;
    hunger = 1;
    produce_amount = rand() % 3;
    if (produce_amount == 0){produce_amount++;} //can produe 1 or 2 eggs

    if (!maxChicken){
        Renderer = gRenderer;
        TextureManager element(gRenderer);
        Texture = element.loadTexture("animals.png"); //load image of a chicken here
        Rect = chickenDown; //initial image of the chicken
        moverRect.w = 20;
        moverRect.h = 25;
        moverRect.y = 85;
        switch (chicken)
        {
        case 2:
            moverRect.x = 178;
            break;
        case 3:
            moverRect.x = 208;
            break;
        case 4:
            moverRect.x = 238;
            break;  
        case 5:
            moverRect.x = 268;
            break;
        case 6:
            moverRect.x = 298;
            break;
        case 7:
            moverRect.x = 328;
            maxChicken = true;  
            break;    
        default:
            moverRect.x = 148;
            break;
        }
        chicken++;
    }

}

Chicken::~Chicken(){
    delete this;
}

void Chicken::walk(){
    //change faces and movements here
    if (moverRect.y >= 172){
        y_speed = -y_speed;
        Rect = chickenUp;
    }
    if (moverRect.y < 85){
        y_speed = -y_speed;
        Rect = chickenDown;
    }
    moverRect.y += y_speed;

}

// void Chicken::sell(int qty){
//     //implementation here
// }

void Chicken::feed(){ //will reset hunger to 0
    if (hunger == 1){
        hunger = 0;
        feeding_time = SDL_GetTicks();
    }
}

void Chicken::produce(){ //will start produces after first feeding
    current_produce = 1;
}

void Chicken::setHunger(){ //chicken gets hungry after this time
    hunger = 1;
}

uint32_t Chicken::timeElapsed(){
    current_time = SDL_GetTicks();
    return current_time - feeding_time;
}
