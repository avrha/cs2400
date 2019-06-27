//******************************************************************* 
//                                                                    
//  Program:     Lab 3
//                                                                     
//  Author:      Joey Ferenchak
//  Email:       jf440918@ohio.edu
//                                                                    
//  Lab Section: Summer Semester 2019
//                                                                    
//  Description: Finds the area of the triangle by using
//               three user inputs
//                                                                    
//  Date:        May 28, 2019
//                                                                    
//*******************************************************************

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
//Clears terminal on startup
system("clear");

//Output manipulators
cout.setf(ios::fixed); // Use fixed point notation
cout.setf(ios::showpoint); // Show decimal point
cout.precision(2); // Set the amount of numbers shown after decimal point to two.

  do
  {
    //Variables
    double s, area, side1, side2, side3;
  
    //Prompts user to input sides
    cout << "Enter in the length of the three sides" << endl;
    cin >> side1;
    cin >> side2;
    cin >> side3;

    //Following three if statements is to ensure the sum of two sides is greater than one
    if (side1 + side2 < side3)
    {
      cout << "Invalid" << endl;
    }

    else if (side1 + side3 < side2)
    {
      cout << "Invalid" << endl;
    }

    else if (side2 + side3 < side1)
    {
      cout << "Invalid" << endl;
    }
      
    //If all inputs are zeros, then exit program
    else if(side1 == 0 || side2 == 0 || side3 == 0)
    {
      cout << "Exiting program..." << endl;
      exit(1);
    }
  
    //If there are all valid inputs, proceed to calculation
    else
    {
     //Calculations for s variable
     s = (side1 + side2 + side3) / 2;
  
     //Calculations for area variable
     area = sqrt(((s * s) - (s * side1)) * (s - side2) * (s- side3));

     //Outputs the area variable
     cout << "Area of the triangle is " <<  area << endl;
    }
  }while(1);

return 0;
}
