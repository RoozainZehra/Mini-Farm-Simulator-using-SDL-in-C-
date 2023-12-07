#include "Cow.hpp"

Cow::Cow(SDL_Renderer* gRenderer){
    static int cow = 1;
    static bool maxCow = false;

    creation_time = SDL_GetTicks();
    current_produce = 0;
    hunger = 1;
    produce_amount = rand() % 3;
    if (produce_amount == 0){produce_amount++;} //can produe 1 or 2 milk

    if (!maxCow){
        Renderer = gRenderer;
        TextureManager element(gRenderer);
        Texture = element.loadTexture("animals.png"); //load image
        Rect = cowDown; //initial image of the cow
        moverRect.w = 30;
        moverRect.h = 50;
        switch (cow)
        {
        case 2:
            moverRect.x = 600;
            moverRect.y = 330;
            break;
        case 3:
            moverRect.x = 680;
            moverRect.y = 330;
            maxCow = true;
            break;
        default:
            moverRect.x = 509;
            moverRect.y = 330;
            break;
        }
        cow++;
    }
    
    cout << "cow created" << endl;
}

Cow::~Cow(){
    delete this;
}

void Cow::walk(){
    //set cow movements here
    if (moverRect.y >= 540){
        y_speed = -y_speed;
        Rect = cowUp;
    }
    else if (moverRect.y < 330){
        y_speed = -y_speed;
        Rect = cowDown;
    }
    moverRect.y += y_speed;
}

// void Cow::sell(int qty){
//     //implementation here
    
// }

void Cow::feed(){ //will reset hunger to 0
    if (hunger == 1){
        hunger = 0;
        feeding_time = SDL_GetTicks();
    }
}

void Cow::produce(){ //will start produces after first feeding
    current_produce = 1;
}

void Cow::setHunger(){ //cow gets hungry after this time
    hunger = 1;
}

uint32_t Cow::timeElapsed(){
    current_time = SDL_GetTicks();
    return current_time - feeding_time;
}
