#pragma once
#ifndef __STACK_HPP
#define __STACK_HPP

#include "Exceptions.h"
#include "Card.h"

//Stack made up of an array
template <typename T>
class Stack {
private:
	int SIZE = 5;
	T items;
	int index;

public:
	//Constructors
	Stack() : SIZE(inSize) { items = T *[5]; }	//Not totally sure if this is gonna work might need fixing

	//Functions
	void push(T inVal);		//Add an item to the Stack
	T pop();				//Remove item from the Stack, return the item removed from the Stack
	T top();				//Returns the top item in the Stack
	int length();			//Returns the total amount of items in the Stack
	void emptyStack();		//Sets the stack to empty
};

#endif