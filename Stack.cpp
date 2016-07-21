/*********************************************************************  
** Program Filename: Stack.cpp
** Author: Eric Podolsky   
** Date: 14 May 2016
** Description: Implementation file for the Stack class, which creates a FILO data structure
** Input: N/A
** Output: Console
*********************************************************************/


#include "Stack.hpp"

/*********************************************************************  
** Function: Stack::Stack()
** Description: Default Stack constructor
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: sets top = NULL
*********************************************************************/ 
Stack::Stack() {
	top = NULL;
}

/*********************************************************************  
** Function: Stack::~Stack()
** Description: Stack destructor
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: deletes all elements of Stack when it goes out of scope
*********************************************************************/ 
Stack::~Stack() {
	while(top!=NULL) {
		remove();
	}
}

/*********************************************************************  
** Function: Stack::add(Creature*)
** Description: Adds a new Stacknode to the Stack with the given data
** Parameters: Value - the Creature* to be added
** Pre-Conditions: 
** Post-Conditions: top is changed to a new Stacknode with the given data
                    and the previous top set to next
*********************************************************************/ 
void Stack::add(Creature* Value) {
	Stacknode *tmp = new Stacknode;
	tmp->data = Value;
	tmp->next = top;
	top = tmp;
}

/*********************************************************************  
** Function: Stack::remove()
** Description: Removes the top value of the stack and returns that value
				If the stack is empty, the null Creature*acter is returned
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: The top value of the stack is removed
*********************************************************************/ 
Creature* Stack::remove() {
	if(top!=NULL) {
		Stacknode *tmpptr = top;
		top = top->next;
		Creature* ctmp = tmpptr->data;
		delete tmpptr;
		return ctmp;
	}
	else {
		std::cout << "Error: There are no elements in the stack." << std::endl;
		return '\0';
	}
}

/*********************************************************************  
** Function: Stack::isEmpty()
** Description: Returns whether the Stack is empty
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/ 
bool Stack::isEmpty() {
	return top==NULL;
}