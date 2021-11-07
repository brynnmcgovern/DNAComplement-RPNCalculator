
//file processor class
#include <iostream>

using namespace std;

class FileProcessor{

public:
  FileProcessor(); //constructor

  ~FileProcessor();//destructor


  /**
  method for opening input and output files
  */
  string readFile(string input);

  void writeFile(string input, string output);


};
