#ifndef POTTER_PODOLSKE_HPP
#define POTTER_PODOLSKE_HPP

#include "Creature.hpp"

class Potter: public Creature {
public:
	Potter(): Creature() {armor = 0; strength = 10; resurrected = false; MAX_STRENGTH = strength;}
	void attack(Creature* defender);
	int defend(int damage);
	std::string getName() {return std::string(firstName + " the Potter");}
	/*********************************************************************  
	** Function: getName()
	** Description: Returns a string containing the firstName and type of 
	                the creature
	*********************************************************************/ 
	void restore() {resurrected = false; Creature::restore();}
	/*********************************************************************  
	** Function: restore()
	** Description: Resets resurrected to false, to be used after winning a battle
	** Parameters:
	** Pre-Conditions: 
	** Post-Conditions: resurrected = false, Creature::restore() is called
	*********************************************************************/ 
private:
	bool resurrected;
};

#endif