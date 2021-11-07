#include "RPNCalc.h"
#include "FileProcessor.h"
#include <iostream>
#include <sstream>
#include <string>

//constructor
RPNCalc::RPNCalc(){
  Mathstack = new GenStack<int>();
  o = ' ';
}

//destructor
RPNCalc::~RPNCalc(){

}

/**createStack()
function to create the stack based on user input
takes in string as paramter
*/
 void RPNCalc::createStack(string mathProblem){
   stringstream str;
   int v;
  for(int i = 0; i < mathProblem.length(); ++i){
      if(mathProblem[i] == '+' || mathProblem[i] == '-' || mathProblem[i] == '*' || mathProblem[i] == '/'){
        o = mathProblem[i];

      }
      else{
        str << mathProblem[i];
        str >> v;
        Mathstack->push(v);
        str.clear();
      }

    }



}

/** operations()
function to calculate the equation based on the operand
void return
*/
void RPNCalc::operations(){
  stringstream ss;
  int a;
  int b;
  int c;
  string equation;

  if(o == '+'){
    a = Mathstack->pop();
    cout << a << endl;
    b = Mathstack->pop();
    cout << b << endl;
    c = a + b;
    Mathstack->push(c);
    cout << c << endl;
  }
  else if(o == '-'){
    //Mathstack->pop();
    a = Mathstack->pop();
    b = Mathstack->pop();
    c = b - a;
    Mathstack->push(c);
    //cout << b - a << endl;
  }
  else if(o == '*'){
    //Mathstack->pop();
    a = Mathstack->pop();
    b = Mathstack->pop();
    c = b*a;
    Mathstack->push(c);
    //cout << b*a << endl;
  }
  else if(o == '/'){
    //Mathstack->pop();
    a = Mathstack->pop();
    b = Mathstack->pop();
    c = b/a;
    Mathstack->push(c);
    //cout << b /a << endl;
  }
  //else{
    //equation += Mathstack->pop();
  //}
}



/** output()
function to print out equation results
*/
void RPNCalc::output(){
  //use printList to output
  for(int i = 0; i < Mathstack->getSize(); ++i){
    cout << Mathstack->pop() << endl;
  }
}
