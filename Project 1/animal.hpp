/*Author: Deondre De Freitas
Course: CSCI 235
Creation: 02/04/20
Header file for the Animal class*/

#include <string>
using namespace std;

class Animal {
public:
	Animal();
	Animal(string name, bool domestic = false, bool predator = false);
	string getName() const;
	bool isDomestic() const;
 	bool isPredator() const;
 	void setName(string name);
 	void setDomestic();
 	void setPredator();
 private:
 	string name_;
 	bool domestic_;
 	bool predator_;
};