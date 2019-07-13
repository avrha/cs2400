/*                                                                    
*  Program: remove-blanks.cc    
*  
*  Author: Joey Ferenchak    
*  Email: jf440918@ohio.edu     
*  
*  Description: 
*  Reads in a file and writes some of it's contents to another file. 
*  Removes all white space characters at the beginning and end of line.
*  Removes all empty lines.
*  All lines are numbered from least to greatest starting at number one.
*  Program cleanly formats the output file by and adding a single blank space before inserting text.
*  Program also adds an extra blank line (unnumbered) at the end of the output file.
*  
*  Date: June 12, 2019       
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

string whitespace(string line); 

/*
*  Function: whitespace
*  Removes all whitespace characters in at the beginning and end of the line.          
*
*  @param string line - Intakes the current objects from a specific line in a file.
*  @return temp - Assigns the function a string with no whitespaces.
*/

void printFileErrors(ifstream& inStream, ofstream& outStream);

/*
*  Function: printFileErrors 
*  Prompts user with error messages if the input or/and output file fails to open,
*  then exits the program.
*
*  @param ifstream inStream - Streams objects from an input file.
*  @param ofstream outStream - Stream objects from an output file.
*/

void printCommandErrors(int argc);

/*
*  Function: printCommandErrors 
*  Prompts user with error messages if wrong amount of arguments is given in terminal,
*  then provides information on how to run the program before exiting.
*  If user enters in the correct amount of arguments, function will prompt user they have
*  successful ran the program.
*             
*  @param int argc - Represents number of arguments on the line.
*/
 
int main(int argc, char *argv[]) 
{ 
  //Declares input and output streams
  ifstream inStream;
  ofstream outStream;

  //Count is used to numbered each line.
  int count = 0; 
  
  //Calls printCommandErrors function
  printCommandErrors(argc);

  string sFile = argv[1]; //Assigns the inputFile to be the 2nd argument (after a.out) in command line
  string tFile = argv[2]; //Assigns the outputFile to be the 3rd argument in command line
  string line; //Declares string, which intakes the current objects from a specific line in a file.

  //Opens input and output files.
  inStream.open(sFile.c_str());
  outStream.open(tFile.c_str());

  //Calls printFileErrors function.
  printFileErrors(inStream, outStream); 

  //Gets every line in input file
  while(getline(inStream, line))
  {
    //Ignores writing from empty lines.
    if(line.length() == 0)
    {
      
    }
    
    //Writes from lines with at least one non-whitespace character.
    else
    {
      count++; //Counts increments itself by one
      outStream << count << '.'; //Writes count at the beginning of the line to number the line.
      outStream << whitespace(line); //Writes out the value from the function whitespace.
      outStream << endl; //Enters a newline in the output file.
    }
  }
  
  outStream << endl; //Enters an additional newline after the last line.

  //Closes files
  inStream.close();
  outStream.close();

  return 0;
}

string whitespace(string line) 
{
  string temp; //Temporally string variable that takes in characters 
  int i = 0, length = line.length(); //I is used for counting up in a line, length gets the length of the line.
  char ch = line.at(i); //ch holds any character at which the variable i is located at in the line.
  char first = line.at(0); //first holds the first character in a line.

  //If the first character is not a whitespace character
  if(!isspace(first))
  {
    temp = " "; //Used for formatting output
    //Counts up every character until the last in the line
    for(; i < length; i++)
    {
      ch = line.at(i); //ch stores the character at which the variable i is located at
      temp += ch; //temp takes in the current and previous value that ch obtains
    }
  }

  //If the first (or second, third, etc) is a whitespace character
  else
  {
    //Perform this task at least once
    do
    {
      i++; //i increments itself by one
      ch = line.at(i); //ch stores the character at which the variable i is located at
    }while(isspace(ch)); //keeps repeating loop until there is no longer a whitespace character

    temp = " "; //Used for formatting output.
    //Counts up every character until the last in the line
    for(;i < length; i++)
    {
      ch = line.at(i);//ch stores the character at which the variable i is located at
      temp += ch;//temp takes in the current and previous value that ch obtains
    }
  }
 return temp;
}

void printFileErrors(ifstream& inStream, ofstream& outStream)
{
  //Print statement if input file fails to open or is not found
  if(inStream.fail())
  {
    cout << "Error: Input file name not found." << endl;
    exit(1); //exits the program
  }
  
  //Print statement if output file fails to open or is not found
  else if(outStream.fail())
  {
    cout << "Error: Output file name out found." << endl;
    exit(1); //exits the program
  }
  
  //Print statement if input and output file name was found
  else
  {
    cout << "Success: Input and output file name was found." << endl;
  } 
}

void printCommandErrors(int argc)
{
  //Print statement if a.out, input file, and output file is not stated in terminal
  if(argc == 0) 
  { 
    cout << "Error: Three arguments wrong. Enter a.out (1) file plus input (2) and output (3) filename." << endl;
    exit(1); //exits the program
  }

  //Print statement if input file and output file is not stated in terminal
  else if(argc == 1)
  {
    cout << "Error: Two arguments wrong. Enter input (2) and output (3) filename." << endl;
    exit(1); //exits the program
  }

  //Print statement if output file is not stated terminal
  else if(argc == 2)
  {
    cout << "Error: One argument wrong. Enter output (3) filename." << endl;
    exit(1);
  }

  //Print statement if user correctly enters in the right amount of arguments
  else
  {
    cout << "Success: All arguments are right." << endl;
  }
}
