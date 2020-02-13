/*Author: Deondre De Freitas
Course: CSCI 235
Creation: 02/08/20
Header file for the Bird class*/

#ifndef BIRD_H
#define BIRD_H
#include "Animal.hpp"
#include <string>
using namespace std;

//Bird class to inherit Animal class
class Bird : public Animal {
public:
    //Constructors
    Bird();
    Bird(string name, bool domestic = false, bool predator = false);
    
    //Accessors
    bool isAirborne() const;
    bool isAquatic() const;
    
    //Mutators
    void setAirborne();
    void setAquatic();
private:
    bool airborne_ = false;
    bool aquatic_ = false;
};
#endif