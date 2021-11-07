#include "DNAComplement.h"
#include "FileProcessor.h"
#include <iostream>
using namespace std;

//constructor
DNAComplement::DNAComplement(){
  c = " ";
  reversed = " ";
  DNAstack = new GenStack<char>();
}

//destructor
DNAComplement::~DNAComplement(){

}

/** createStack()
function to create a stack
*/
void DNAComplement::createStack(string sequence){
  FileProcessor FP;
  string DNASequence = FP.readFile(sequence);
  for(int i = 0; i < DNASequence.length(); ++i){
    DNAstack->push(DNASequence[i]);
  }

}

/** findComplement()
function to find the complement to a DNA sequence
*/
void DNAComplement::findComplement(){

  char complement;
  char new_complement;
  string sequence;
  if(DNAstack->isEmpty() == true){
      throw runtime_error("Stack is empty");
  }
  else{
    for(int i = DNAstack->getSize(); i > 0; --i){


    complement = DNAstack->pop();

    if(complement == 'A'){
      new_complement = 'T';
      sequence += new_complement;

    }
    else if(complement == 'T'){
      new_complement = 'A';
      sequence += new_complement;

    }
    else if(complement == 'C'){
      new_complement = 'G';
      sequence += new_complement;

    }
    else if(complement == 'G'){
      new_complement = 'C';
      sequence += new_complement;

    }
  }

    for(int i = 0; i < sequence.length(); ++i){
      DNAstack->push(sequence[i]);
    }

  }

  printSequence();
}

/** Complement()
function to find reverse complement
*/
void DNAComplement::Complement(){
  for(int i = DNAstack->getSize(); i > 0; --i){
    c += DNAstack->pop();
  }
  for(int i = c.length()-1; i >= 0; --i){
    reversed += c[i];
  }


}
/** printSequence()
function to print out results
*/
void DNAComplement::printSequence(){
    FileProcessor FP;
    FP.writeFile(reversed, c);

}
