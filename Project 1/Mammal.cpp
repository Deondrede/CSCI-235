/*Author: Deondre De Freitas
Course: CSCI 235
Creation: 02/06/20
Implementation file for the Mammal class*/

#include<string>
#include<iostream>
#include"Mammal.hpp"
using namespace std;

Mammal::Mammal() : Animal(){}

Mammal::Mammal(string name, bool domestic, bool predator) : Animal(name, domestic, predator){}

bool Mammal::hasHair() const{
    return hair_;
}

bool Mammal::isAirborne() const{
    return airborne_;
}

bool Mammal::isAquatic() const{
    return aquatic_;
}

bool Mammal::isToothed() const{
    return toothed_;
}

bool Mammal::hasFins() const{
    return fins_;
}

bool Mammal::hasTail() const{
    return tail_;
}

int Mammal::legs() const{
    return legs_;
}

void Mammal::setHair(){
    hair_ = true;
}

void Mammal::setAirborne(){
    airborne_ = true;
}

void Mammal::setAquatic(){
    aquatic_ = true;
}

void Mammal::setToothed(){
    toothed_ = true;
}

void Mammal::setFins(){
    fins_ = true;
}

void Mammal::setTail(){
    tail_ = true;
}

void Mammal::setLegs(int legs){
    legs_ = legs;
}