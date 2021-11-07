#ifndef RPNCALC_H
#define RPNCALC_H
#include <iostream>
#include "GenStack.h"

using namespace std;

class RPNCalc{
public:
  RPNCalc();
  ~RPNCalc();
  void operations();
  void createStack(string mathProblem);
  void output();




private:
  //FileProcessor fp;
  GenStack<int> *Mathstack;
  char o;
//function for each operation
//function to print out postfix notation, and result
};



#endif
