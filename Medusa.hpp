#ifndef MEDUSA_PODOLSKE_HPP
#define MEDUSA_PODOLSKE_HPP

#include "Creature.hpp"

class Medusa: public Creature {
public:
	Medusa(): Creature() {armor = 3; strength = 8; MAX_STRENGTH = strength;}
	void attack(Creature* defender);
	int defend(int damage);
	std::string getName() {return std::string(firstName + " the Medusa");}
	/*********************************************************************  
	** Function: getName()
	** Description: Returns a string containing the firstName and type of 
	                the creature
	*********************************************************************/ 
private:
};

#endif