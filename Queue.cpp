/*********************************************************************  
** Program Filename: Queue.cpp
** Author: Eric Podolsky   
** Date: 14 May 2016
** Description: Implementation file for the Queue class, which creates a FIFO data structure
** Input: N/A
** Output: Console
*********************************************************************/

#include "Queue.hpp"

/*********************************************************************  
** Function: Queue::Queue()
** Description: Default Queue constructor
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: sets first and last = NULL
*********************************************************************/ 
Queue::Queue() {
	first = NULL;
	last = first;
}

/*********************************************************************  
** Function: Queue::~Queue()
** Description: Queue destructor
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: deletes all elements of Queue when it goes out of scope
*********************************************************************/ 
Queue::~Queue() {
	while(first!=NULL) {
		remove();
	}
}

/*********************************************************************  
** Function: Queue::add(char)
** Description: Adds a new Queuenode to the Queue with the given data
** Parameters: Value - the char to be added
** Pre-Conditions: 
** Post-Conditions: If the queue is empty, first and last are updated to 
                    the new Queuenode. Otherwise, only the last node is 
					updated.
*********************************************************************/ 
void Queue::add(Creature* Value) {
	if(first==NULL) {
		first = new Queuenode;
		first->data=Value;
		first->next=NULL;
		first->prev=NULL;
		last = first;
	}
	else {
		last->next = new Queuenode;
		last->next->data=Value;
		last->next->next=NULL;
		last->next->prev=last;
		last = last->next;
	}
}

/*********************************************************************  
** Function: Queue::remove()
** Description: Removes the last value of the Queue and returns that value
				If the Queue is empty, the null character is returned
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: The last value of the Queue is removed
*********************************************************************/ 
Creature* Queue::remove() {
	if(first!=NULL) {
		Queuenode *tmpptr = first;
		first = first->next;
		Creature* ctmp = tmpptr->data;
		delete tmpptr;
		return ctmp;
	}
	else {
		std::cout << "Error: There are no elements in the queue." << std::endl;
		return NULL;
	}
}

/*********************************************************************  
** Function: Queue::isEmpty()
** Description: Returns whether the Queue is empty
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/ 
bool Queue::isEmpty() {
	return first==NULL;
}