#ifndef GENSTACK_H
#define GENSTACK_H
#include <iostream>
#include <exception>
#include "linkedlist.h"
using namespace std;


template <class T>
class GenStack{
	public:
		GenStack();
		~GenStack();

		void push(T data);
		T pop();
		T peek();
    void deleteAtPos(T d);

		int isFull();
		bool isEmpty();
    int find(T d);
    int getSize();
    void printStack();

		int top;
		int max;
    int numElements;
	  GenLinkedList<T> *stack;
};

template <class T>
GenStack<T>::GenStack(){
  stack = new GenLinkedList<T>();
  top = -1;
  numElements = 0;
}


template <class T>
GenStack<T>::~GenStack(){
	delete stack;
}

template <class T>
void GenStack<T>::push(T data){
	stack->insertFront(data);
  numElements ++;
  top ++;
}


template <class T>
int GenStack<T>::find(T d){
  if(stack->isEmpty() == true){
    throw runtime_error("Stack is empty");
  }
  else{
    return stack -> find(d);
  }

}

template<class T>
void GenStack<T>::deleteAtPos(T d){
  stack->deletePos(d);
}

template <class T>
int GenStack<T>::getSize(){
  return stack->getSize();
}


template <class T>
T GenStack<T>::pop(){
  if(isEmpty()){
    throw runtime_error("stack is empty; can not pop!!");
  }
	else if (top != -1){
		return stack->removeFront();
	}

	else{
		return 0;
	}
}

template <class T>
T GenStack<T>::peek(){
  //returns the data stored in the front but doesnt remove
    if(isEmpty()){
      cout << "Linked List already empty" << endl;
    }
    else{
      return stack->topNode();
    }

  }


template <class T>
bool GenStack<T>::isEmpty(){
	if(numElements == 0){
    return true;
  }
  else{
    return false;
  }
}

#endif
