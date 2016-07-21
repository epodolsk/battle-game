/*********************************************************************  
** Program Filename: utilities.cpp
** Author: Eric Podolsky   
** Date: 23 April 2016
** Description: Implementation file for utilities.hpp
** Input: N/A
** Output: N/A
*********************************************************************/

#include "utilities.hpp"

/*********************************************************************  
** Function: checkType(int&)
** Description: Determines whether an input in the input stream is an integer
                as requested
** Parameters: i - the variable to be tested
** Pre-Conditions: std::cin is the input stream
** Post-Conditions: the value of i may be changed to the valid value
*********************************************************************/ 
void checkType(int& i) { 
    while(std::cin.fail()) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> i;
    }
}

/*********************************************************************  
** Function: checkType(char&)
** Description: Determines whether an input in the input stream is a character
                as requested
** Parameters: c - the variable to be tested
** Pre-Conditions: std::cin is the input stream
** Post-Conditions: the value of c may be changed to the valid value
*********************************************************************/ 
void checkType(char& c) { 
    while(std::cin.fail()) {
        std::cout << "Invalid input. Please enter a character: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> c;
    }
}

/*********************************************************************  
** Function: checkPositive(int&)
** Description: Determines whether a given number is a positive int and then
                requests a new number if it is not 
** Parameters: i - the variable to be tested
** Pre-Conditions: std::cin is the input stream
** Post-Conditions: the value of i may be changed to the valid value
*********************************************************************/ 
void checkPositive(int& i) { 
    while(std::cin.fail() || i < 1) {
        std::cout << "Invalid input. Please enter a positive integer: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> i;
    }
}

/*********************************************************************  
** Function: checkPositive(double&)
** Description: Determines whether a given number is a positive double and then
                requests a new number if it is not 
** Parameters: i - the variable to be tested
** Pre-Conditions: std::cin is the input stream
** Post-Conditions: the value of i may be changed to the valid value
*********************************************************************/ 
void checkPositive(double& i) { 
    while(std::cin.fail() || i < 1) {
        std::cout << "Invalid input. Please enter a positive number: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> i;
    }
}

/*********************************************************************  
** Function: checkPositive(int&, int&)
** Description: Compares two ints to determine whether the first number
                is greater than the second. If not, a new value is requested
                for the first number.
** Parameters: i - the variable to be tested
               j - the value to which i is compared
** Pre-Conditions: std::cin is the input stream
** Post-Conditions: the value of i may be changed to a value greater than j
*********************************************************************/ 
void checkGreaterThan(int& i, const int j) {
    while(i > j) {
        std::cout << "You must enter a number less than or equal to " << j << ": ";
        std::cin >> i;
        checkPositive(i);
    }
}

/*********************************************************************  
** Function: checkRange(int&, int&, int)
** Description: Determines whether the first parameter is an int between
                the values of the second and third parameter, inclusive
** Parameters: i - the variable to be tested
               bound1, bound2 - boundaries of the range
** Pre-Conditions: std::cin is the input stream
** Post-Conditions: the value of i may be changed to be within the range
*********************************************************************/ 
void checkRange(int& i, const int bound1, const int bound2) {
    int lowest, highest;
    if(bound2 > bound1) {
        lowest = bound1;
        highest = bound2;
    }
    else {
        lowest = bound2;
        highest = bound1;
    }
    while(std::cin.fail() || i > highest || i < lowest) {
        std::cin.clear();
        std::cin.ignore(255, '\n');
        std::cout << "You must enter a number from " << lowest << "-" << highest << ": ";
        std::cin >> i;
    }
}

/*********************************************************************  
** Function: resizeIntArray(int*&, const int, int&)
** Description: Doubles the capacity of a dynamic array
** Parameters: arr - the pointer to the start of the array
               numElements - the number of elements in the array
			   arraySize - the current size of the array
** Pre-Conditions: 
** Post-Conditions: arraySize is doubled, arr points to an array with
                    double the capacity
*********************************************************************/ 
void resizeIntArray(int*& arr, const int numElements, int& arraySize) {
	int* new_array = new int[arraySize*2];
	for(int i = 0; i < numElements; ++i) {
		new_array[i] = arr[i];
	}

	delete [] arr;

	arr = new_array;

	arraySize = arraySize * 2;
}

/*********************************************************************  
** Function: checkYN(char&)
** Description: Determines whether a 'Y' or 'N' (case insensitive) has been
                entered into the input stream
** Parameters: c - the input to be tested
** Pre-Conditions: std::cin is the input stream
** Post-Conditions: the value of c may be changed to a valid value
*********************************************************************/ 
void checkYN(char& c) {
	while(std::cin.fail() || (c != 'y' && c != 'n' && c!= 'Y' && c!='N')) {
        std::cout << "You must enter either 'y' or 'n': ";
		std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> c;
    }
}