#ifndef BABAYAGA_PODOLSKE_HPP
#define BABAYAGA_PODOLSKE_HPP

#include "Creature.hpp"

class BabaYaga: public Creature {
public:

	BabaYaga(): Creature() {armor = 3; strength = 12; MAX_STRENGTH = strength;}
	void attack(Creature* defender);
	int defend(int damage);
	std::string getName() {return std::string(firstName + " the Baba Yaga");}
	/*********************************************************************  
	** Function: getName()
	** Description: Returns a string containing the firstName and type of 
	                the creature
	*********************************************************************/ 
private:
};

#endif