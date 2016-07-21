/*********************************************************************  
** Program Filename: utilities.hpp
** Author: Eric Podolsky   
** Date: 1 May 2016
** Description: A set of utility functions
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef PODOLSKE_UTILITIES_HPP
#define PODOSLKE_UTILTIIES_HPP

#include <iostream>

//DECLARATIONS

//INPUT VALIDATION FUNCTIONS
void checkType(int& i);
void checkType(char& c);
void checkPositive(int& i);
void checkPositive(double& i);
void checkGreaterThan(int& i, const int j);
void checkRange(int& i, const int bound1, const int bound2);
void checkYN(char& c);

//DYNAMIC MEMORY MANAGEMENT
void resizeIntArray(int*& arr, const int numElements, int& arraySize);

#endif