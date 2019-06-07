//******************************************************************* 
//                                                                    
//  Program:     word_count.cc
//                                                                     
//  Author:      Joey Ferenchak  
//  Email:       jf440918@ohio.edu
//                                                                    
//  Lab Section: CS2400 Summer Semester
//                                                                    
//  Description: Counts number of words and sentences inside a file.
//
//  Date:        May 30, 2019
//                                                                    
//*******************************************************************

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;

int main( )
{
  //Variable text stores the user's input.
  char text;

  //Variables words and sentences serve as counters, while average stores the quotient of words/sentences.
  double words = 0, sentences = 0, average = 0;

  //File variables
  ifstream inStream;  
  inStream.open("extraCredit.txt");

  //Tests if file does not open.
  if(inStream.fail())
  {
    cout << "Error opening the file" << endl;
    exit(0);
  }

  //Puts program into a while loop until the end of the input file is reached.
  while(!inStream.eof())
  {
    //Gets a character in the input file and stores it to the variable text
    inStream.get(text);

    //Checks for sentences and words.
    if(text == '.' || text == '!' || text == '?')
    {
      ++sentences;
      ++words;
    }

    //Checks for words only.
    if(text == ' ' || text == '\t' || text == '\n')
    {
      ++words;
    }

    //Ignores any other possibilities 
    else
    {
    }
  }

  //Newline for proper formatting.
  cout << endl; 

  //Prompts the user number and words and sentences.
  cout << "Number of words: " << words << endl;
  cout << "Number of sentences: " << sentences << endl;

  //Specific output if no words or sentences were found. 
  if(words == 0 && sentences == 0)
  {
    cout << "You did not enter any text!" << endl;
  }

  //Specific output if no sentences were found.
  else if(sentences == 0)
  {
    cout << "You did not enter any sentences!" << endl;
  }
  
  //Specific output if words and sentences were found.
  else
  {
    //Divides words by sentences.
    average = words/sentences;

    //Output manipulators for displaying the variable average.
    cout.setf(ios::fixed); // Use fixed point notation.
    cout.setf(ios::showpoint); // Show decimal point.
    cout.precision(1); // Set the amount of numbers shown after decimal point to one. 

    //Prompts user the average words per sentence.
    cout << "Average words per sentence: " << average << endl;
  }
  return 0;
}
