//******************************************************************* 
//                                                                    
//  Program:     gas_consumption.cc                                           
//                                                                     
//  Author:      Joey Ferenchak
//  Email:       jf440918@ohio.edu
//                                                                    
//  Lab Section: CS2400 Summer Semester
//                                                                    
//  Description: Calculates the gas consumption for a trip given the
//               number of miles driven in town and on a highway.
//                                                                    
//  Last Edit:   May 20, 2019
//                                                                    
//*******************************************************************

#include <iostream>
using namespace std;

// Declaring all 2 constant variables as doubles
const double GAS_AVERAGE_TOWN = 22.5;
const double GAS_AVERAGE_HIGHWAY = 29.5; 
  
int main()
{

  // Declaring all 7 variables as doubles 
  double town_mile, highway_mile, sum_mile, gas_town, gas_highway, gas_sum, total_mpg;
  
  // Prompts user to input miles driven in town and on highway
  cout << "Enter in the number of miles driven in town: ";
  cin >> town_mile;
  cout << "Enter in the number of miles driven on the highway: ";
  cin >> highway_mile;

  // Finding gas consumption for town driving 
  gas_town = town_mile / GAS_AVERAGE_TOWN;

  // Finding gas consumption for highway driving
  gas_highway = highway_mile / GAS_AVERAGE_HIGHWAY;

  // Finding total amount of miles driven
  sum_mile = town_mile + highway_mile; 

  // Finding total gas consumption for road trip
  gas_sum = gas_town + gas_highway;
  
  // Finding average miles per gallon for the whole trip
  total_mpg = sum_mile / gas_sum;

  // Outputs following calculations
  cout << "--------------------------Gas consumption--------------------------" << endl;
  cout << "The number of miles driven in town: " << town_mile <<" miles" << endl;
  cout << "The gas consumption for town driving: " << gas_town <<" gallons" << endl;
  cout << "The number of miles driven on the highway: " << highway_mile << " miles" << endl;
  cout << "The gas consumption for highway driving: " << gas_highway << " gallons" << endl;
  cout << "The total miles driven: " << sum_mile << " miles" << endl;
  cout << "The total gas consumption: " << gas_sum << " gallons" << endl;
  cout << "The average mpg for the trip: " << total_mpg << " miles/gallon" << endl;
  cout << "-------------------------------------------------------------------" << endl;

  return 0;
}
