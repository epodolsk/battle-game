/*********************************************************************  
** Program Filename: Bluemen.hpp
** Author: Eric Podolsky   
** Date: 8 May 2016
** Description: Implements the Bluemen class
** Input: N/A
** Output: N/A
*********************************************************************/


#include "Bluemen.hpp"

/*********************************************************************  
** Function: attack(Creature*)
** Description: Generates an attack to be used against the given Creature
** Parameters: defender - a pointer to the defending creature
** Pre-Conditions: srand() has been seeded, Creature* points to a Creature
** Post-Conditions: defender's defend() function is called
*********************************************************************/ 
void Bluemen::attack(Creature* defender) {
	int points = dice(2, 10);
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
int Bluemen::defend(int damage) {
	int num_dice = 3-((12-strength)/4); //Blue Men's defense rolls are reduced by 1 for every 4 point loss in HP
	if(num_dice < 3) {
		std::cout << firstName << " has " << num_dice << " defense roll(s) due to injury!" << std::endl;
	}
	int defense = armor + dice(num_dice, 6);
	std::cout << firstName << " generated " << defense << " defense." << std::endl;
	int net = damage - defense;
	if(net > 0)
		strength -= net;
	std::cout << firstName << "'s HP is " << (strength > 0 ? strength : 0) << "." << std::endl;
	
	return net;
}