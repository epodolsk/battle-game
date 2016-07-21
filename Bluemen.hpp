#ifndef BLUEMEN_PODOLSKE_HPP
#define BLUEMEN_PODOLSKE_HPP

#include "Creature.hpp"

class Bluemen: public Creature {
public:
	Bluemen(): Creature() {armor = 3; strength = 12; MAX_STRENGTH = strength;}
	void attack(Creature* defender);
	int defend(int damage);
	std::string getName() {return std::string(firstName + " the Blue Men");}
	/*********************************************************************  
	** Function: getName()
	** Description: Returns a string containing the firstName and type of 
	                the creature
	*********************************************************************/ 
private:
};

#endif