#include "Queue.h"
#include <iostream>
#include <string>

//Add an item to the front of the Queue
template <class T>
void Queue<T>::enqueue(T inVal) {
    //Needs to be updated for linked list
    Node *temp = new Node(inVal);
    if (first == nullptr) {
        //Check if queue is empty
        first = temp;
        last = temp;
    } else {
        first->next = temp->next;
        first = temp;
    }
}

//Remove an item from the back of the Queue, then return it
template <class T>
T Queue<T>::dequeue() {
    //Needs to be updated for linked list
    if (last == nullptr) {
        //Check if the queue is empty
        throw Exception("Queue Underflow", 1);
    } else {
        //Remove the last item in the Queue
    }
}

//Look at the top item of the Queue
template <class T>
T Queue<T>::peek() {    //Not totally sure if this is all right
    if (!isEmpty()) {
        throw Exception("Queue Underflow", 1);
    } else {
        return last;
    }
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

