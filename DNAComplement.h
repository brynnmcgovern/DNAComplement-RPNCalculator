#ifndef DNACOMPLEMENT_H
#define DNACOMPLEMENT_H
#include "GenStack.h"
#include <iostream>
using namespace std;

class DNAComplement{
public:
  DNAComplement();
  ~DNAComplement();
  void findComplement();
  void createStack(string sequence);
  void printSequence();
  //call file processor function to read input from a file
  //read from file into stack

//function to find complement
  //takes in stack char, and changes the character to the complementary one, then outputs
  //will have to reverse the final string
  void Complement();
private:
  string c;
  string reversed;
  GenStack<char> *DNAstack;

//function to find reverse
  //takes in stack char, changes the character to the complement, and prints out string
};



#endif
