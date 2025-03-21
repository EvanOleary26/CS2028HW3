#include "List.h"


template <class T>
List<T>::~List() {
    while (first != nullptr) {
        Node<T>* temp = first;
        first = first->next;
        delete temp;
    }
}

template <class T>
void List<T>::AddItem(T inVal) {
    Reset();       //Reset curLocation if the list is changed
    Node<T>* temp = new Node<T>(inVal);
    if (first == nullptr) {
        first = temp;
        last = temp;
    }
    else {
        last->next = temp;
        last = last->next;
    }
    length++;
}

template<class T>
T List<T>::GetItem(T target) {
    if (length == 0) {
        throw Exception(1, "List is empty");
    }

    Node<T> *temp = first;

    if (temp->data == target) {
        T retVal = temp->data;
        first = temp->next;
        delete temp;
        length--;
        return retVal;
    }

    while (!((temp->next == nullptr) || (temp->next->data == target))) {
        temp = temp->next;
    }

    if (temp->next == nullptr) { 
        throw Exception(1, "Item not found in list"); 
    }

    Node<T> *hold = temp->next;
    temp->next = hold->next;
    T retVal = hold->data;
    delete hold;
    length--;
    return retVal;
}

template<class T>
T List<T>::GetItemAt(int index) {
    int curIndex = 0;

    if (length == 0) {
        //Check if list is empty
        throw Exception(1, "List is empty");
    }

    if (length < index) {
        throw Exception(1, "Index is out of range");
    }

    Node<T> *temp = first;

    if (index == 0) {
        T retVal = temp->data;
        first = temp->next;
        delete temp;
        length--;
        return retVal;
    }

    while ((temp->next != nullptr) && (curIndex+1 != index)) {
        temp = temp->next;
        curIndex++;
    }
    

    if (temp->next == nullptr) { 
        throw Exception(1, "Item not found in list"); 
    }

    Node<T> *hold = temp->next;
    temp->next = hold->next;
    T retVal = hold->data;
    delete hold;
    length--;
    return retVal;
}



template <class T>
bool List<T>::IsInList(T target) {
    Node<T>* temp = first;
    if (first == nullptr) {
        //Return false if no items in the list
        return false;
    }

    if (temp->data == target) {
        //Check if the first item is the target
        return true;
    }

    while (temp->next != nullptr) {
        //Continue while not at the end
        temp = temp->next;
        if (temp->data == target) {
            //Stop when the item is found
            return true;
        }
    }
    //Return false if item is not found in loop
    return false;

}

template <class T>
bool List<T>::IsEmpty() {
    return first == nullptr;
}

template <class T>
int List<T>::Size() {
    return length;
}

template <class T>
T List<T>::SeeNext() {
    if (first == nullptr) {
        throw Exception(1, "List is empty");
    }
    if (curLocation == nullptr) {
        curLocation = first;
    }
    else {
        curLocation = curLocation->next;
    }
    if (curLocation == nullptr) {
        throw Exception(1, "Index out of bounds");
    }
    return curLocation->data;
}


template <class T>
T List<T>::SeeAt(int target) {
    Node<T>* temp = first;
    for (int i = 0; i < target; i++) {
        temp = temp->next;
        if (temp == nullptr) {
            throw Exception(1, "Index out of bounds");
        }
    }
    curLocation = temp;
    return temp->data;
}

template <class T>
void List<T>::DisplayList() {
    Node<T>* temp = first;
	while (temp != nullptr) {
        temp->data.display();
        temp = temp->next;
        if (temp != nullptr) {
            std::cout << "         |  |" << std::endl;
        }
	}        
}

template <class T>
void List<T>::Reset() {
    curLocation = nullptr;
}

template <class T>
bool List<T>::operator==(const List<T>& right) const {
    return this->first->data == right.first->data;
}

template <class T>
bool List<T>::operator>(const List<T>& right) const {
    return this->first->data > right.first->data;
}

template <class T>
bool List<T>::operator<(const List<T>& right) const {
    return this->first->data < right.first->data;
}

//base template
template class List<Card>;