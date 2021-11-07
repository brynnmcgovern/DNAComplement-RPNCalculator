#include <iostream>
#include "FileProcessor.h"
#include <fstream>

using namespace std;

FileProcessor::FileProcessor(){

}

FileProcessor::~FileProcessor(){

}

/**
processFile()
method for opening input file and output file, then
uses translateEnglishSentence() to translate text in input file
parameter: string input, string output
no return
*/
string FileProcessor::readFile(string input){



  /**
  string translated
  used to store translated text from file
  */
  string sentence;
  string line;
  ifstream inputFile;
  inputFile.open(input);
  if(inputFile.is_open()){
    while(getline(inputFile, line)){
      sentence = line;
    }
  }
  inputFile.close();
  return sentence;


}

void FileProcessor::writeFile(string complement, string reverse){

  ofstream outputFile;
  outputFile.open("dnaoutput.txt");
  if(outputFile.is_open()){
        outputFile << "DNA sequence: ";
        outputFile << "sequencedddd" << endl;
        outputFile << "DNA complement: ";
        outputFile << complement << endl;
        outputFile << "DNA reverse complement: ";
        outputFile << reverse << endl;
  }
  else{
    throw runtime_error("File is not open");
  }
  outputFile.close();
}
