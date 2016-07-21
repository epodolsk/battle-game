/*********************************************************************  
** Program Filename: BabaYaga.hpp
** Author: Eric Podolsky   
** Date: 8 May 2016
** Description: Implements the BabaYaga class
** Input: N/A
** Output: N/A
*********************************************************************/

#include "BabaYaga.hpp"

/*********************************************************************  
** Function: attack(Creature*)
** Description: Generates an attack to be used against the given Creature
** Parameters: defender - a pointer to the defending creature
** Pre-Conditions: srand() has been seeded, Creature* points to a Creature
** Post-Conditions: defender's defend() function is called
*********************************************************************/ 
void BabaYaga::attack(Creature* defender) {
	int points = dice(2, 6);
	std::cout << firstName << " attacked with " << points << " power." << std::endl;
	int net = defender->defend(points);
	if(net > 0) {
		std::cout << firstName << " used her Soul ability to regain " << net << " strength." << std::endl;
		strength += net;
	}
}

/*********************************************************************  
** Function: defend(int)
** Description: Defends the attack with the given power
** Parameters: damage - the amount of power in the attack
** Pre-Conditions: srand() has been seeded
** Post-Conditions: returns the net damage (damage - armor - defense)
*********************************************************************/ 
int BabaYaga::defend(int damage) {
	int defense = armor + dice(1, 10);
	std::cout << firstName << " generated " << defense << " defense." << std::endl;
	int net = damage - defense;
	if(net > 0)
		strength -= net;
	std::cout << firstName << "'s HP is " << (strength > 0 ? strength : 0) << "." << std::endl;
	
	return net;
}