// Problem3c.h
//  Hok Yin Shum
//  Collaborator: Hua Bin Liu 
//  Created by Hok Yin Shum on 10/11/17.

#ifndef QueueFromList_h
#define QueueFromList_h

#include <iostream>
#include "Problem3a.h" // linkedlist
using namespace std;

template <class T = int>
class QueueFromList {
public:
    QueueFromList();                                   // constructor
    ~QueueFromList();                                  // destructor
    void enqueue(T data);//(to head)
    T dequeue();//(from tail)
    bool isEmpty();                                     //isEmpty boolean.
private:
    LinkedList<T> list;                                //pointer to the linked list.
};

template <class T>
QueueFromList<T>::QueueFromList()
{
    
}

template <class T>
QueueFromList<T>::~QueueFromList()
{
    
}

template <class T>
void QueueFromList<T>::enqueue(T data)
{
    list.InsertToHead(data);
}

template <class T>
T QueueFromList<T>::dequeue()
{
    return list.deleteFromTail();
}

template <class T>
bool QueueFromList<T>::isEmpty(){
    if(list.getSize() == 0) return true;
    else return false;
}



#endif /* QueueFromList_h */
