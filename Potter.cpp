/*********************************************************************  
** Program Filename: Potter.hpp
** Author: Eric Podolsky   
** Date: 8 May 2016
** Description: Implements the Potter class
** Input: N/A
** Output: N/A
*********************************************************************/

#include "Potter.hpp"

/*********************************************************************  
** Function: attack(Creature*)
** Description: Generates an attack to be used against the given Creature
** Parameters: defender - a pointer to the defending creature
** Pre-Conditions: srand() has been seeded, Creature* points to a Creature
** Post-Conditions: defender's defend() function is called
*********************************************************************/ 
void Potter::attack(Creature* defender) {
	int points = dice(2, 6);
	std::cout << firstName << " attacked with " << points << " power." << std::endl;
	defender->defend(points);

}

/*********************************************************************  
** Function: defend(int)
** Description: Defends the attack with the given power
** Parameters: damage - the amount of power in the attack
** Pre-Conditions: srand() has been seeded
** Post-Conditions: returns the net damage (damage - armor - defense)
*********************************************************************/ 
int Potter::defend(int damage) {
	int defense = armor + dice(2, 6);
	std::cout << firstName << " generated " << defense << " defense." << std::endl;
	int net = damage - defense;
	if(net > 0)
		strength -= net;
	std::cout << firstName << "'s HP is " << (strength > 0 ? strength : 0) << "." << std::endl;
	if(strength <= 0 && resurrected == false) {
		resurrected = true;
		strength = 10;
		std::cout << firstName << " used Resurrect to come back to life with 10 HP!" << std::endl;
	}
	
	return net;
}