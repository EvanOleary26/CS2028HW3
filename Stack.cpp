#include <iostream>
#include "Stack.h"

//Add an item to the Stack
template <class T>
void Stack<T>::push(T inVal) {
	if (index < SIZE) {
		items[index] = inVal;
		index++;
	}
	else {
		throw Exception(0, "Stack Overflow"); //need this to go back and say that stack is full and go back
	}
}

//Remove item from the Stack, return item removed from the Stack
template <class T>
T Stack<T>::pop() {
	if (index > 0) {
		T hold = items[index - 1];
		index--;
		return hold;
	}
	else {
		throw Exception(0, "Stack Underflow");
	}
}

//Returns the top item in the Stack
template <class T>
T Stack<T>::top() {
	return items[index - 1];
}

//Returns the total amount of items in the Stack
template <class T>
int Stack<T>::length() {
	return index;
}

//Sets the stack to empty
template <class T>
void Stack<T>::emptyStack() {
	index = 0;
}


//See if stack is full 
template <class T>
bool Stack<T>::isFull() {
	return index == SIZE;
}

//See if stack is empty
template <class T>
bool Stack<T>::isEmpty() {
	return index == 0;
}

//Base templates 
template class Stack<Card>;