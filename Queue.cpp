#include "Queue.h"
#include <iostream>
#include <string>

//Add an item to the bottom of the Queue
template <class T>
void Queue<T>::enqueue(T inVal) {
    //Needs to be updated for linked list
}

//Remove an item from the top of the Queue, then return it
template <class T>
T Queue<T>::dequeue() {
    //Needs to be updated for linked list
}

//Look at the top item of the Queue
template <class T>
T Queue<T>::peek() {
    //Needs to be updated for linked list
}

//Check if the Queue is empty
template <class T>
bool Queue<T>::isEmpty() {
    return size == 0;
}

//Returns the total amount of items in the Queue
template <class T>
int Queue<T>::length() {
    return size;
}


//Base template

