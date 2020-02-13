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

/*int main(){
    Fish tuna("that's a spicy tuna sandwhich");
    cout << tuna.getName() << endl;
    cout << tuna.isVenomous() << " not venomous" << endl;
    tuna.setVenomous();
    cout << tuna.isVenomous() << " venomous" << endl;
    cout << tuna.isDomestic() << " not domestic" << endl;
    tuna.setDomestic();
    cout << tuna.isDomestic() << " domestic" << endl;
    tuna.setName("I'm actually a piranha");
    cout << tuna.getName() << endl;
}*/