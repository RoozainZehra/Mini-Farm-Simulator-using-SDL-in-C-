#include "Animals.hpp"

Animals::Animals(int time){
    produce_time = time;
}

Animals::~Animals(){}

int Animals::getProduceTime(){
    return produce_time;
}
int Animals::getCurrentTime(){
    return current_time;
}
void Animals::updateTime(){
    current_time++;
}