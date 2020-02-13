/*Author: Deondre De Freitas
Course: CSCI 235
Creation: 02/08/20
Implementation file for the Bird class*/

#include <string>
#include <iostream>
#include "Bird.hpp"
using namespace std;

Bird::Bird() : Animal(){}

Bird::Bird(string name, bool domestic, bool predator) : Animal(name, domestic, predator){}

bool Bird::isAirborne() const{
    return airborne_;
}

bool Bird::isAquatic() const{
    return aquatic_;
}

void Bird::setAirborne(){
    airborne_ = true;
}

void Bird::setAquatic(){
    aquatic_ = true;
}