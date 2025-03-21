#include "Queue.h"
#include <iostream>
#include <string>

//Add an item to the front of the Queue
template <class T>
void Queue<T>::enqueue(T inVal) {
    Node<T>* temp = new Node<T>(inVal);
    temp->next = first;
    first = temp;
    size++;
    if (last == nullptr) {
        last = first;
    }
}

//Remove an item from the back of the Queue, then return it
template <class T>
T Queue<T>::dequeue() {
    Node<T>* temp = first;
    if (last == nullptr) {
        //Check if the queue is empty
        throw Exception(1, "Queue Underflow");
    }
    else if (first == last) {
        //Check if there is only one item in the Queue
        T retVal = first->data;
        first = nullptr;
        last = nullptr;
        size--;
        return retVal;
    }
    else {
        //Remove the last item in the Queue
        while (temp->next != last) {
            temp = temp->next;
        }
        T retVal = temp->next->data;
        temp->next = nullptr;
        last = temp;
        size--;
        return retVal;
    }
}

//Look at the top item of the Queue
template <class T>
T Queue<T>::peek() {
    if (!isEmpty()) {
        throw Exception(1, "Queue Underflow");
    }
    else {
        return last->data;
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
template class Queue<Card>;