/*********************************************************************  
** Program Filename: Medusa.cpp
** Author: Eric Podolsky   
** Date: 8 May 2016
** Description: Implements the Medusa class
** Input: N/A
** Output: N/A
*********************************************************************/


#include "Medusa.hpp"
#include <climits>

/*********************************************************************  
** Function: attack(Creature*)
** Description: Generates an attack to be used against the given Creature
** Parameters: defender - a pointer to the defending creature
** Pre-Conditions: srand() has been seeded, Creature* points to a Creature
				   <climits> for INT_MAX
** Post-Conditions: defender's defend() function is called
*********************************************************************/ 
void Medusa::attack(Creature* defender) {
	int points = dice(2, 6);
	if(points < 12)
		std::cout << firstName << " attacked with " << points << " power." << std::endl;
	else {
		points = INT_MAX; //sets Medusa's attack to the maximum possible int value
		std::cout << firstName << " rolled a 12. She uses Glare to generate a fatal attack!" << std::endl;
	}
	defender->defend(points);

}

/*********************************************************************  
** Function: defend(int)
** Description: Defends the attack with the given power
** Parameters: damage - the amount of power in the attack
** Pre-Conditions: srand() has been seeded
** Post-Conditions: returns the net damage (damage - armor - defense)
*********************************************************************/ 
int Medusa::defend(int damage) {
	int defense = armor + dice(1, 6);
	std::cout << firstName << " generated " << defense << " defense." << std::endl;
	int net = damage - defense;
	if(net > 0)
		strength -= net;
	std::cout << firstName << "'s HP is " << (strength > 0 ? strength : 0) << "." << std::endl;
	
	return net;
}