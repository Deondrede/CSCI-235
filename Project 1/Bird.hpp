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
    Bird();
    Bird(string name, bool domestic = false, bool predator = false);
    bool isAirborne() const;
    bool isAquatic() const;
    void setAirborne();
    void setAquatic();
private:
    bool airborne_ = false;
    bool aquatic_ = false;
};
#endif