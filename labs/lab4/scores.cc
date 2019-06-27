//******************************************************************* 
//                                                                    
//  Program:     scores.cc
//                                                                     
//  Author:      Joey Ferenchak
//  Email:       your email address
//                                                                    
//  Lab Section: Summer Semester 2019 
//                                                                    
//  Description: Takes scores from input file, calculates the grade,
//               then outputs the all scores, grades, and grade occurrences 
//               to user.
//                                                                    
//  Date:       June 4, 2019
//                                                                    
//*******************************************************************

#include <iostream>
#include <fstream>
using namespace std;

/*
 *  Function:  getGrade
 *             Get the scores from the input file, and calculate 
 *             the letter grade.
 *              
 *  @param score - A single score from the score.txt file.
 *  @return score - assigns the function a letter grade value.
 */

char getGrade(double score)
{
  //Determines what letter grade is score
  if(score >= 90 && score < 100)
  {
    score = 'A';
  }
  
  else if(score >= 80 && score < 90)
  {
    score = 'B';
  }
  
  else if(score >= 70 && score < 80)
  {
    score = 'C';
  }
  
  else if(score >= 60 && score < 70)
  {
    score = 'D';
  }
  
  else
  {
    score = 'F';
  }
  return score;
}

/*
 *  Function:  printGrade 
 *             Outputs all the grades and scores.  
 *              
 *  @param score - Stores the letter grade from the getGrade function
 *  @param grade  - Stores the scores from the scores.txt file
 */
  
void printGrade(double score, char grade)
{
  cout << "Score: " << score << "," << " Grade: " <<  grade << endl;
}

/*
 *  Function:   printFrequencies
 *              Prints out the how many times do certain letter grades occur.
 *
 *  @param aCount - How many times A occurs
 *  @param bCount - How many times B occurs
 *  @param cCount - How many times C occurs
 *  @param dCount - How many times D occurs
 *  @param fCount - How many times F occurs
 */

void printFrequencies(int aCount, int bCount, int cCount, int dCount, int fCount)
{
  cout << "Grade   Frequency" << endl;
  cout << "-----------------" << endl;
  cout << "  A           " << aCount << endl;
  cout << "  B           " << bCount << endl;
  cout << "  C           " << cCount << endl;
  cout << "  D           " << dCount << endl;
  cout << "  F           " << fCount << endl;
}

int main()
{
  // Variables
  double score; // Stores values from scores.txt
  int aCount = 0, bCount = 0, cCount = 0, dCount = 0, fCount = 0; // Counters pertaining to letter grades.
  ifstream infile; // Variable to stores the file in use, scores.txt.

  // Opens file score.txt, and gets the first score from scores.txt
  infile.open("scores.txt");
  infile >> score;

  // Output manipulators
  cout.setf(ios::fixed); // Use fixed point notation
  cout.setf(ios::showpoint); // Show decimal point
  cout.precision(1); // Set the amount of numbers shown after decimal point to one.

  // Programs goes into a while loop until it reaches the end of file.
  while(!infile.eof())
  {
    // Variable grade is equal to the getGrade function parameter score
    char grade = getGrade(score);
    // Prints out scores and grades
    printGrade(score, grade);
    
    // Determines which grade counter should be updated.
    if(grade == 'A')
    {
      aCount++;
    }

    else if(grade == 'B')
    {
      bCount++;
    }

    else if(grade == 'C')
    {
      cCount++;
    }

    else if(grade == 'D')
    {
      dCount++;
    }

    else
    {
      fCount++;
    }

    // Gets the next score from file
    infile >> score;
  }
  cout << endl;
  // Prints out grades frequencies 
  printFrequencies(aCount, bCount, cCount, dCount, fCount);  
  infile.close();
  return 0;
}
