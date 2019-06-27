//******************************************************************* 
//                                                                    
//  Program:     word_count.cc
//                                                                     
//  Author:      Joey Ferenchak  
//  Email:       jf440918@ohio.edu
//                                                                    
//  Lab Section: CS2400 Summer Semester
//                                                                    
//  Description: Counts number of words and sentences in a paragraph.
//                                                                    
//  Date:        May 30, 2019
//                                                                    
//*******************************************************************

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main( )
{
  //Clears Terminal on startup.
  system("clear"); 

  //Prompts user for input.
  cout << "Enter a paragraph... " << endl;

  //Variable text stores the user's input.
  string text; 

  //Variables words and sentences serve as counters, while average stores the quotient of words/sentences.
  double words = 0, sentences = 0, average = 0;

  //Enters while loop for inputting string value.
  while(cin >> text)
  {
    //Variable length contains the length of the string.
    int length = text.length();

    //Variable word identifies the last character in the string.
    char word = text.at(length - 1);

    //Exits the loop if user inputs @@@
    if(text == "@@@")
    {
      break;
    }
    
    //Identifies and adds a sentence by using key characters. Adds a word.
    else if(word == '.' || word == '!' || word == '?')
    {
      ++sentences;
      ++words;
    }

    //Adds a word.
    else
    {
      ++words;
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
