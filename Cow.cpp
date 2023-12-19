#include "Cow.hpp"

Cow::Cow(SDL_Renderer* gRenderer){
    static int cow = 1;
    static bool maxCow = false;

    time_to_feed = 15000;
    feeding_time = SDL_GetTicks();
    creation_time = SDL_GetTicks();
    current_produce = 0;
    hunger = 1;
    produce_amount = rand() % 3;
    if (produce_amount == 0){produce_amount++;} //can produe 1 or 2 milk

    TextureManager element2(gRenderer);
    alertTexture = element2.loadTexture("alert.png");
    alertRect.w = 30;
    alertRect.h = 30;

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
        alertRect.x = moverRect.x;
        alertRect.y = moverRect.y - 60;
        cow++;
    }
    
    cout << "cow created" << endl;
}

Cow::~Cow(){}

void Cow::walk(){
    //cow movements 
    if (moverRect.y >= 540){
        y_speed = -y_speed;
        Rect = cowUp;
    }
    else if (moverRect.y < 330){
        y_speed = -y_speed;
        Rect = cowDown;
    }
    moverRect.y += y_speed;

    setAlert();
}

char Cow::Type(){
    return 'M';
}

char Cow::feedType(){
    return 'C';
}

bool Cow::feed(){ //will reset hunger to 0
    if (hunger == 1){
        hunger = 0;
        if(!current_produce){
            alert = false;
        }
        feeding_time = SDL_GetTicks();
        return true;
    }
    return false;
}

bool Cow::produce(){ //will return produce status
    if (current_produce){
        current_produce = false;
        return true;
    }
    return false;
}

void Cow::setHunger(){ //cow gets hungry after this time
    if (timeElapsed() >= time_to_feed){
        hunger = 1;
    }
}

uint32_t Cow::timeElapsed(){
    current_time = SDL_GetTicks();
    return current_time - feeding_time;
}

bool Cow::animalSick(){
    if (timeElapsed() >= (time_to_feed + 10000)){
        return true;
    }
    return false;
}

void Cow::setProduce(){  //if a certain time has passed, cow is ready to produce milk
    if(timeElapsed() >= (time_to_feed + 5000)){
        current_produce = 1;
    }
}

int Cow::collectProduce(){
    return produce_amount;
}

void Cow::setAlert(){
    if (hunger || current_produce){
        alert = true;
    }
}
