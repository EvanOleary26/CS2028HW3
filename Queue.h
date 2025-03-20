#pragma once
#ifndef __QUEUE__HPP
#define __QUEUE__HPP

#include "Exceptions.h"
#include "Node.h"
#include "Card.h"

//Queue as a linked list
template<class T>
class Queue {
private:
	Node<T> *first;
	Node<T> *last;
	int size;
    
public:
	//Constructor
    Queue() : first(nullptr), last(nullptr), size(0) {};

	//Functions
	void enqueue(T inVal);   //Add an item to the bottom of the Queue
	T dequeue();             //Remove an item from the top of the Queue, then return it   
	T peek();                //Look at the top item of the Queue
	bool isEmpty();          //Check if the Queue is empty
    int length();            //Returns the total amount of items in the Queue

};


#endif