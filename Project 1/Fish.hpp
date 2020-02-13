/*Author: Deondre De Freitas
Course: CSCI 235
Creation: 02/08/20
Header file for the Fish class*/

#ifndef FISH_H
#define FISH_H
#include <string>
#include "Animal.hpp"
using namespace std;

//Fish class to inherit Animal class
class Fish : public Animal{
public:
    Fish();
    Fish(string name, bool domestic = false, bool predator = false);
    bool isVenomous() const;
    void setVenomous();
private:
    bool venomous_ = false;
};
#endif