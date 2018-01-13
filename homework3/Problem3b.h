//Problem3b.h
// Hok yin shum 
// collaborator: Hua bin Liu
//u77071350 
//
//  Created by Hok Yin Shum on 10/11/17.
//

#ifndef StackFromList_h
#define StackFromList_h

#include <iostream>
#include "Problem3a.h"
using namespace std;

template <class T = int>
class StackFromList {
public:
    StackFromList();                                   // constructor
    ~StackFromList();                                  // destructor
    void push(T data);                                  //push
    T pop();                                            //pop
    bool isEmpty();                                     //isEmpty boolean.
private:
    LinkedList<T> list;                                //pointer to the linked list.
};

template <class T>
StackFromList<T>::StackFromList()
{
   
}

template <class T>
StackFromList<T>::~StackFromList()
{
    
}

template <class T>
void StackFromList<T>::push(T data){
    list.InsertToHead(data);
    return;
}

template <class T>
T StackFromList<T>::pop(){
    return list.deleteFromHead();
}

template <class T>
bool StackFromList<T>::isEmpty(){
    if(list.getSize() == 0) return true;
    else return false;
}




#endif /* StackFromList_h */
