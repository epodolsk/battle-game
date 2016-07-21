/*********************************************************************  
** Program Filename: Stack.hpp
** Author: Eric Podolsky   
** Date: 14 May 2016
** Description: Header file for the Stack class, which creates a FILO data structure
** Input: N/A
** Output: Console
*********************************************************************/

#ifndef STACK_PODOLSKE_HPP
#define STACK_PODOLSKE_HPP

#include <cstdlib>
#include <iostream>
#include "Creature.hpp"

struct Stacknode {
	Creature* data;
	Stacknode* next;
};

class Stack {
public:
	Stack();
	~Stack();
	void add(Creature* Value);
	Creature* remove();
	bool isEmpty();
private:
	Stacknode* top;
};

#endif