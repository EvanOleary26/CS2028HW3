
#pragma once
#ifndef __STACK_HPP
#define __STACK_HPP

#include "Exceptions.h"
#include "Card.h"

//Stack made up of an array
template <class T>
class Stack {
private:
	int SIZE = 5;
	T* items;
	int index;

public:
	//Constructors
	Stack() : SIZE(5), index(0) {
		items = new T[SIZE];
	}
	Stack(int inSize) : SIZE(inSize), index(0) {
		items = new T[SIZE];
	}
	

	//Functions
	void push(T inVal);		//Add an item to the Stack
	T pop();				//Remove item from the Stack, return the item removed from the Stack
	T top();				//Returns the top item in the Stack
	int length();			//Returns the total amount of items in the Stack
	void emptyStack();		//Sets the stack to empty
};

#endif
