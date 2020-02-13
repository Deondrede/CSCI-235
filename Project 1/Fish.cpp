/*Author: Deondre De Freitas
Course: CSCI 235
Creation: 02/08/20
Header implementation for the Fish class*/

#include <string>
#include <iostream>
#include "Fish.hpp"
using namespace std;

Fish::Fish() : Animal(){}

Fish::Fish(string name, bool domestic, bool predator) : Animal(name, domestic, predator){}

bool Fish::isVenomous() const{
    return venomous_;
}

void Fish::setVenomous(){
    venomous_ = true;
}