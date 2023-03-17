
#ifndef ZLL_H
#define ZLL_H

#include <iostream>
#include <string>
#include <iomanip>
#include "zany.h"

using namespace std;

template<typename T> class Node{
    public:
    T data;
    Node* next;
    Node* prev;
    //friend class ZLL;

    Node();
    Node(T input);
};

template<typename T> class ZLL {
    public:
    ZLL(); //Defalut Constructor
    ~ZLL();//Destructor

    //Member functions
    bool front(const T& item);
    bool back(const T& item);
    bool join(ZLL &other);
    ZLL<T> &operator+=(const ZLL &other);
    ZLL<T> &operator-=(const ZLL &other);
    int removeZany();
    int removeNonZany();
    bool promoteZany();
    bool empty();

    bool start();
    bool done();
    T getNext();


    //Extra functions to delete later probably
    bool isEmpty();
    bool removeNode(int nodeIndex);
    void printList();

    private:
    //Pointers for head and tail and list size
    Node<T>* head;
    Node<T>* tail;
    Node<T>* iterator;
    int listSize;
};


#include "ZLL.cpp"

#endif