#ifndef BARBARIAN_PODOLSKE_HPP
#define BARBARIAN_PODOLSKE_HPP

#include "Creature.hpp"

class Barbarian: public Creature {
public:
	Barbarian(): Creature() {armor = 0; strength = 12; MAX_STRENGTH = strength;}
	void attack(Creature* defender);
	int defend(int damage);
	std::string getName() {return std::string(firstName + " the Barbarian");}
	/*********************************************************************  
	** Function: getName()
	** Description: Returns a string containing the firstName and type of 
	                the creature
	*********************************************************************/ 
private:
};

#endif