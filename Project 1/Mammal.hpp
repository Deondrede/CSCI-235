/*Author: Deondre De Freitas
Course: CSCI 235
Creation: 02/06/20
Header file for the Mammal class*/

#ifndef MAMMAL_H
#define MAMMAL_H
#include"Animal.hpp"
#include<string>
using namespace std;

//Mammal class to inherit Animal class
class Mammal : public Animal {
public:
    //Constructors
    Mammal();
    Mammal(string name, bool domestic = false, bool predator = false);
    
    //Accessors
    bool hasHair() const;
    bool isAirborne() const;
    bool isAquatic() const;
    bool isToothed() const;
    bool hasFins() const;
    bool hasTail() const;
    int legs() const;
    
    //Mutators
    void setHair();
    void setAirborne();
    void setAquatic();
    void setToothed();
    void setFins();
    void setTail();
    void setLegs(int legs);
private:
    bool hair_ = false;
    bool airborne_ = false;
    bool aquatic_ = false;
    bool toothed_ = false;
    bool fins_ = false;
    bool tail_ = false;
    int legs_ = false;
};
#endif
