#include "DNAComplement.h"
#include "RPNCalc.h"
#include <iostream>

int main (int argc, char **argv){
  string user_choice;
  cout << "Please enter RPN for the RPN calculator, or DNA for the DNA complement program: " << endl;
  cin >> user_choice;
  if(user_choice == "RPN"){
    RPNCalc R;
    string equation;
    cout << "Please enter an equation with a space between each operator and operand: " << endl;
    cin >> equation;
    R.createStack(equation);
    R.operations();
    R.output();
  }
  else if(user_choice == "DNA"){
    DNAComplement D;
    string fileName;
    cout << "Please enter file name: " << endl;
    cin >> fileName;
    D.createStack(fileName);
    D.findComplement();
    D.Complement();
  }
  else{
    cout << "Please enter valid input: " << endl;
  }


}

//ask for RPN or DNA
//if RPN
  //prompt for numbers and operation

//add user input to stack
