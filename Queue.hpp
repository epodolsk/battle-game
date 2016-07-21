/*********************************************************************  
** Program Filename: Queue.hpp
** Author: Eric Podolsky   
** Date: 14 May 2016
** Description: Header file for the Queue class, which creates a FIFO data structure
** Input: N/A
** Output: Console
*********************************************************************/

#ifndef QUEUE_PODOLSKE_HPP
#define QUEUE_PODOLSKE_HPP

#include <cstdlib>
#include <iostream>
#include "Creature.hpp"

struct Queuenode {
	Creature* data;
	Queuenode* next;
	Queuenode* prev;
};

class Queue {
public:
	Queue();
	~Queue();
	void add(Creature* Value);
	Creature* remove();
	bool isEmpty();
private:
	Queuenode* first;
	Queuenode* last;
};

#endif