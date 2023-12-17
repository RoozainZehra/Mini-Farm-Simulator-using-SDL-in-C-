#include "Chicken.hpp"

Chicken::Chicken(SDL_Renderer* gRenderer){
    static int chicken = 1;
    static bool maxChicken = false;  //can have at max 7 chickens

    selling_price = 100;
    
    time_to_feed = 10000;
    current_produce = 0;
    hunger = 1;
    produce_amount = rand() % 3;
    if (produce_amount == 0){produce_amount++;} //can produe 1 or 2 eggs

    TextureManager element2(gRenderer);
    alertTexture = element2.loadTexture("alert.png");

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
        alertRect.x = moverRect.x;
        alertRect.y = moverRect.y - 20;
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

    setAlert();
}

int Chicken::Sell(){
    return selling_price;
}

char Chicken::Type(){
    return 'E';
}

char Chicken::feedType(){
    return 'C';
}

bool Chicken::feed(){ //will reset hunger to 0
    if (hunger == 1){
        hunger = 0;
        feeding_time = SDL_GetTicks();
        return true;
    }
    return false;
}

bool Chicken::produce(){ //will start produces after first feeding
    return current_produce;
}

void Chicken::setProduce(){
    if(timeElapsed() >= (time_to_feed + 2000)){
        current_produce = 1;
    }
}

int Chicken::collectProduce(){
    return produce_amount;
}

void Chicken::setHunger(){ //chicken gets hungry after this time
    if (timeElapsed() >= time_to_feed){
        hunger = 1;
    }
}

uint32_t Chicken::timeElapsed(){
    current_time = SDL_GetTicks();
    return current_time - feeding_time;
}

bool Chicken::animalSick(){
    if (timeElapsed() >= (time_to_feed + 5000)){
        return true;
    }
    return false;
}

void Chicken::setAlert(){
    if (hunger || current_produce){
        alert = true;
    }
}