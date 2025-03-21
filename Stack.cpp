#include <iostream>
#include "Stack.h"

//Add an item to the Stack
template <typename T>
void Stack<T>::push(T inVal) {
	if (index < SIZE) {
		items[index] = inVal;
		index++;
	}
	else {
		throw Exception(0, "Stack Overflow");
	}
}

//Remove item from the Stack, return item removed from the Stack
template <typename T>
T Stack<T>::pop() {
	if (index > 0) {
		return items[index--];
	}
	else {
		throw Exception(0, "Stack Underflow");
	}
}

//Returns the top item in the Stack
template <typename T>
T Stack<T>::top(){
	return items[SIZE-1];
}

//Returns the total amount of items in the Stack
template <typename T>
int Stack<T>::length() {
	return index;
}

//Sets the stack to empty
template <typename T>
void Stack<T>::emptyStack() {
	index = 0;
}

//Base templates 
template class Stack<Card>;