//******************************************************************* 
//                                                                    
//  Program:     lab2.cc
//                                                                     
//  Author:      Joey Ferenchak  
//  Email:       jf440918@ohio.edu
//                                                                    
//  Lab Section: CS2400 Summer Semester
//                                                                    
//  Description: Calculates the future value of an investment using
//               compound interest.
//                                                                    
//  Date:        May 21, 2019
//                                                                    
//*******************************************************************

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
  // Declares three variables as doubles, and one as a float
  double amount, interest, value;
  float time;

  // Asks user to input three values, which would be assigned to three variables.
  cout << "Enter the investment amount, the interest, and number of years" << endl;
  cin >> amount;
  cin >> interest;
  cin >> time;

  // New variable that takes interest and divides it by 100.  
  double percent = interest / 100;

  // If statement to make sure no negative values are inputted. 
  if (amount < 0 || interest < 0 || time < 0)
  {
    cout << "Error: Invalid input" << endl;
    exit (0);
  }

  // The formula to find the future value
  value = amount * pow(1 + percent, time);

  // Formats the outputs.
  cout.setf(ios::fixed); // Use fixed point notation
  cout.setf(ios::showpoint); // Show decimal point
  cout.precision(2); // Set the amount of numbers shown after decimal point to two.

  // Outputs final calculates. Aligns output.
  cout << setw(25) << "Investment Amount: $" << amount << endl;
  cout << setw(24) << "Interest: " << interest << "%" <<  endl;
  cout << setw(24) << "Number of years: " << time << endl;
  cout << setw(25) << "Future Value: $" << value << endl;
  
  return 0;
}
