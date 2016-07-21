/*********************************************************************  
** Program Filename: Creature.hpp
** Author: Eric Podolsky   
** Date: 8 May 2016
** Description: Implements the Creature class
** Input: N/A
** Output: N/A
*********************************************************************/


#include "Creature.hpp"

/*********************************************************************  
** Function: dice(int, int)
** Description: Returns the results of rolling the given number of dice
                with the given number of sides
** Parameters: num - the number of dice, sides - the number of sides
** Pre-Conditions: srand() has been seeded, <cstdlib>
** Post-Conditions: The total roll is returned
*********************************************************************/ 
int Creature::dice(int num, int sides) {
	int total = 0;
	for (int i = 0; i < num; ++i) {
		total += (rand()%sides + 1);
	}
	
	return total;
}

/*********************************************************************  
** Function: restore()
** Description: Restores the health of a Creature, to be used after winning
                a battle
** Parameters:
** Pre-Conditions: 
** Post-Conditions: A creature strength is recovered 50% is it is below
                    max strength. If it is above, it restored to its original
					level
*********************************************************************/ 
void Creature::restore() {
	if(strength < MAX_STRENGTH) {
		std::cout << firstName << " restored its health by 50%!" << std::endl;
		strength += ((MAX_STRENGTH - strength)/2);
	}
	else if(strength > MAX_STRENGTH) {
		std::cout << firstName << " returned to its original strength level." << std::endl;
		strength = MAX_STRENGTH;
	}
}