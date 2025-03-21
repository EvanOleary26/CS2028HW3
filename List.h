#ifndef __LIST__H
#define __LIST__H

#include "Node.h"
#include "Exceptions.h"
#include "Card.h"

template <class T>
class List {
private:
    Node<T>* first;
    Node<T>* last;
    Node<T>* curLocation;
    int length;
public:
    //Constructors
    List() : first(nullptr), last(nullptr), curLocation(nullptr), length(0) {};

    //Destructor
    ~List();

    //Functions
    void AddItem(T inVal);
    T GetItem(T target);
    T GetItemAt(int index);
    bool IsInList(T target);
    bool IsEmpty();
    int Size();
    T SeeNext();
    T SeePrev();
    T SeeAt(int target);
    void Reset();
    void DisplayList();

    //Operator Overloads
    bool operator<(const List<T>& right) const;
    bool operator>(const List<T>& right) const;
    bool operator==(const List<T>& right) const;
};

#endif