#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

template <class T>

class ListNode{
  public:
    T data;
    ListNode *next;

    //constructor and destructor
    ListNode();
    ListNode(T d);
    ~ListNode();
};

template <class T>
ListNode<T>::ListNode(){}

//overload constructor
template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;

}

//destructor
template <class T>
ListNode<T>::~ListNode(){
  next = NULL;
}

template <class T> //The templates - README for template reference

class GenLinkedList{
  private:
    ListNode<T> *front; //pointer to the node in the front
    ListNode<T> *back; //pointer to the node in the back
    unsigned int size; //size of the DoublyLinkedList

  public:
    GenLinkedList(); //constructor
    ~GenLinkedList(); //destructor

    void insertFront(T d); //insert node to front
    void insertBack(T d); //insert node to back
    T removeFront(); //removes and returns node in the front
    T removeBack(); //removes and returns node in the back
    T peek(); //returns the node in the front
    T deletePos(T pos); //delete and returns node at certain position
    int find(T d); //finds and returns the position of a node
    T topNode();
    bool isEmpty(); //checks if list is empty
    void printList(); //prints the list
    unsigned int getSize(); //returns the size of list
};

//default constructor
template<class T>
GenLinkedList<T>::GenLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

//destructor
template<class T>
GenLinkedList<T>::~GenLinkedList(){
  //iterate through the list
ListNode<T>* current = front;
while( current != 0 ) {
    ListNode<T>* next = current->next;
    delete current;
    current = next;
}
front = 0;
}


//inserts a node to the front
template<class T>
void GenLinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T>(d);
  node->next = front;
  front = node;
  ++size;
}

//removes the node from the front of the list
template<class T>
T GenLinkedList<T>::removeFront(){
  if(isEmpty()){
    cout << "List empty" << endl;
  }
  else{
  T temp = front->data;
  ListNode<T> *oldfront = front;
  front = front -> next;
  oldfront -> next = NULL;
  --size;
  delete oldfront;
  return temp;
  }
}


//inserts node to the back of the list
template<class T>
void GenLinkedList<T>::insertBack(T d){
  ListNode<T> *node = new ListNode<T>(d);

  if(isEmpty()){
    //empty list
    front = node;
  }
  else{
    back->next = node;
  }
  back = node;
  size++;
}

template<class T>
T GenLinkedList<T>::topNode(){
  if(isEmpty()){
    cout << "Linked List already empty" << endl;
  }
  else{
    return front->data;
  }
}

//deletes node at a certain position
template<class T>
T GenLinkedList<T>::deletePos(T d){
  if(isEmpty()){
    cout << "List already empty" << endl;
  }
  else{
  int nodePosition = 0;
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;

  while(nodePosition != d){
    prev = curr;
    curr = curr -> next;
    nodePosition += 1;
  }

  //at this point prev and curr should be in the correct spots
  prev -> next = curr -> next;
  curr -> next = NULL;
  int data = curr -> data;
  --size;

  delete curr;
  return data;
  }
}

//finds the position of a data
template<class T>
int GenLinkedList<T>::find(T d){
  if(isEmpty()){
    cout << "List is empty" << endl;
  }
  else{
      int index = 0;
      ListNode<T> *curr = front;

      while(curr != NULL){
        if(curr->data == d){
          break;
        }
        else{
          curr = curr->next;
          index++;
        }
      }

      if(curr == NULL){ //did not find the value we want
        index = -1;
      }
      return index;
    }
}

//returns if the list is empty
template<class T>
bool GenLinkedList<T>::isEmpty(){
  if(size == 0){
    return true;
  }
  else{
    return false;
  }
}

//prints list
template<class T>
void GenLinkedList<T>::printList(){
  ListNode<T> *curr = front;

  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}

//returns the size
template<class T>
unsigned int GenLinkedList<T>::getSize(){
  return size;
}
#endif
