/*********************************************************************  
** Program Filename: Creature.hpp
** Author: Eric Podolsky   
** Date: 8 May 2016
** Description: Header file for the Creature class and its derived 
                classes
** Input: N/A
** Output: Console output
*********************************************************************/

#ifndef CREATURE_PODOLSKE_HPP
#define CREATURE_PODOLSKE_HPP

#include <cstdlib>
#include <iostream>
#include <string>

class Creature {
public:
	//CONSTRUCTOR
	Creature() {}
	virtual ~Creature() {}
	
	//ABILITIES
	virtual void attack(Creature* defender) = 0; 
	virtual int defend(int damage) = 0;
	virtual void restore();
	
	//ACCESSORS
	int getStrength() {return strength;}
	/*********************************************************************  
	** Function: getStrength()
	** Description: Accessor for strength
	*********************************************************************/ 
	virtual std::string getName()=0;
	/*********************************************************************  
	** Function: getName()
	** Description: Returns a string containing the firstName and type of 
	                a creature. Defined in each child class.
	*********************************************************************/ 
	int get_team() {return team_num;}
	/*********************************************************************  
	** Function: get_team()
	** Description: Returns the team number
	*********************************************************************/ 
	
	//MUTATORS
	void set_firstName(std::string newName) {firstName = newName;}
	/*********************************************************************  
	** Function: set_firstName(int)
	** Description: Mutator for firstName
	*********************************************************************/ 

	void set_team(int team) {team_num = team;}
	/*********************************************************************  
	** Function: set_team(int)
	** Description: Set team_num to the team number
	*********************************************************************/ 

protected:
	int dice(int num, int sides);
	int armor;
	int strength;
	std::string firstName;
	int MAX_STRENGTH;
	int team_num; //whether the creature's team is 1 or 2
};

#endif