//Problem3a.h
//Hok Yin Shum 
//Collaborator: Hua Bin Liu 
//Copyright © 2017 Tali Moreshet. All rights reserved.

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>

using namespace std;

template <class T = int>
class Node {
public:
    Node();                                         // default constructor
    Node(const T& data, Node<T>* next = nullptr);   // constructor
    T data;                                         // node data
    Node<T>* next;                                  // node next pointer
};

template <class T = int>
class LinkedList {
public:
    LinkedList();                                   // constructor
    ~LinkedList();                                  // destructor
    T deleteFromHead(); //throw (runtime_error);       // removes and returns content of head
    T deleteFromTail(); //throw (runtime_error);       // removes and returns content of tail
    void deleteNode(T data); // throw (runtime_error);  // removes node with specified data
    void InsertToHead(T data);                      // insert node with data at the head
    void InsertToTail(T data);                      // insert node with data at the tail
    int getSize();                                  // returns size of linked list
    void print();                                   // prints linked list
private:
    Node<T>* head;                                  // head of linked list
};


/******* From here down is the content of the LinkedList.cpp file: ***********************/

 /* Implementation of Node */

 // default constructor
 template<class T>
 Node<T>::Node()
 {
 }
 
 // constructor
 template<class T>
 Node<T>::Node(const T& data, Node<T>* next)
 {
     this->data = data;
     this->next = next;
 }
 
 /* Implementation of linked list */

 // constructor
 template <class T>
 LinkedList<T>::LinkedList()
 {
     head = nullptr;
 }

 // destructor
 template <class T>
 LinkedList<T>::~LinkedList()
 {
     Node<T>* current = head;
     while(current != nullptr) {
         Node<T>* next = current->next;
         delete current;
         current = next;
     }
     head = 0;
     
 }


 template <class T>
 T LinkedList<T>::deleteFromHead()
 {
    //to be implemented
     T result = head->data;
     Node<T> * temp;
     if(head== nullptr){
         return result;
     }else{
         temp = head->next;
         //is delete necessary?
         head = temp;
     }
     return result;
 }


 template <class T>
 T LinkedList<T>::deleteFromTail()
 {
     T result;
     if(head == nullptr) return result;
     
     //Delete only node.
     if(head->next == nullptr) {
         result = head->data;
         head = nullptr;
         return result;
     }
     // Find the last node.
     Node<T> *tail = head;
     while(tail->next != nullptr){
         tail = tail -> next;
     }
     Node<T> *temp = head;
     while(temp->next!= tail)
     {
         temp=temp->next;
     }
     result = tail->data;
     delete tail;
     temp->next = nullptr;
     return result;
 }
 

 template <class T>
 void LinkedList<T>::deleteNode(T data)
 {
    //to be implemented
     if(head == nullptr) return;
     
     if(head->next == nullptr){
         delete head;
         return;
     }
     if(head->data == data){
         Node<T> *temp = head;
         temp = head->next;
         head = temp;
         return;
     }
     // find first match.
     Node<T> *temp = head;
     while(temp->data != data){
         temp=temp->next;
     }
     //delete first match.
     Node<T>* temp2 = head;
     while(temp2->next != temp){
         temp2 = temp2->next;
     }
     temp2->next = temp->next;
     delete temp;
     return;
 }


 template <class T>
 void LinkedList<T>::InsertToHead(T data)
 {
     Node<T> * newNode = new Node<T>(data, nullptr);
     if (head == nullptr)
         head = newNode;
     else
     {
         newNode->next = head;
         head = newNode;
     }
 }


 template <class T>
 void LinkedList<T>::InsertToTail(T data)
 {
     Node<T>* last = new Node<T>(data, nullptr); //last has new data.
     //Condition 1: if empty list, then just point head to last.
     if (head == nullptr) 
	{
         head = last;
     	}else 
	{ // if the linked list is not empty
	         Node<T> *temp = head;
	         while (temp->next != nullptr)
		 {
	             temp = temp->next;
	         }
	         temp->next = last;
         }
     return;
 }


 template <class T>
 int LinkedList<T>::getSize()
 {
     //to be implemented
     int size = 0;
     Node<T> *temp =  head;
     if(head == nullptr){
         return size;
     }else {
         while (temp != nullptr) {
             size++;
             temp = temp->next; 
         }
     }
     return size;
 }



 template <class T>
 void LinkedList<T>::print()
 {
     if (head == nullptr)
     {
         cout << "Linked list is empty" << endl;;
         return;
     }
     
     cout << head->data << " ";
     
     if (head->next == nullptr)
     {
         cout << endl;
         return;
     }
 
     Node<T>* currNode = head->next;
     Node<T>* prevNode = head;
 
     
     while (currNode->next != nullptr)
     {
         cout << currNode->data << " ";
         prevNode = currNode;
         currNode = currNode->next;
     }
 
     cout << currNode->data << endl;
     return;
 }
     
     
#endif /* LinkedList_h */
