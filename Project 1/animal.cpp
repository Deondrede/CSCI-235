/*Author: Deondre De Freitas
Course: CSCI 235
Creation: 02/04/20
Implementation for the Animal class*/

#include <string> 
#include <iostream> 
#include "animal.hpp" 
using namespace std;

Animal::Animal(string name, bool domestic, bool predator){
	name_ = name;
	domestic_ = domestic;
	predator_ = predator;
}

string Animal::getName() const{
	return name_;
}

bool Animal::isDomestic() const{
	return domestic_;
}

bool Animal::isPredator() const{
	return predator_;
}

void Animal::setName(string name) {
	name_ = name;
}

void Animal::setDomestic(){
	if (domestic_ == false){
		domestic_ = true;
	}
	else if (domestic_ == true){
		domestic_ = false;
	}
}

void Animal::setPredator(){
	if (predator_ == false){
		predator_ = true;
	}
	else if (predator_ == true){
		predator_ = false;
	}
}