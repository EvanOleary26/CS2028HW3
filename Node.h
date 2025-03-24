#ifndef __NODE__H
#define __NODE__H

template<class T>
class Node {
    public:
        T data;
        Node<T> *next;
    
        //Constructors
        Node() : data(T()), next(nullptr) {};
        Node(T inVal) : data(inVal), next(nullptr) {};
};









#endif