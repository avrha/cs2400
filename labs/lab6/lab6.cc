/*
*  Program: lab6.cc
*
*  Author: Joey Ferenchak
*  Email: jf440918@ohio.edu
*
*  Description:
*  Gets the data inside a file, then outputs data in orderly fashion.
*  Also finds the sum of all the last items in each line.
*
*  Date: 6/18/19
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

struct Employee
{
  //All of these variable are public
  string id, firstName, lastName; //id, firstName, lastName all take in strings from an input file
  double salary; //salary takes in a double from an input file
};

void fillUp(ifstream &inStream, Employee &e, vector <Employee> &allEmployees);

/*
*  Function: Fillup
*  Fills up vectors with strings and numbers from the input file.
*
*  @param ifstream &inStream - Streams objects from the input file
*  @param Employee &e - Sets the layout for all the variables in the structure Employee
*  @param vector <Employee> &allEmployees - A vector for all the values in the structure Employee
*/

void printAll(Employee &e);

/*
*  Function: printAll
*  Prints out all the variables in e in an orderly fashion.
*
*  @param Employee &e - Sets the layout for all the variables in the structure Employee
*/

double payRoll(vector <Employee> &allEmployees);

/*
*  Function: payRoll
*  Gets the sum of all the salaries;
*
*  @param vector <Employee> &allEmployees - A vector for all the values in the structure Employee
*  @return sum - Assigns the function the sum all the salaries
*/

int main()
{
  //Vectors
  vector <Employee> allEmployees;

  //Declares the overall layout for the variable in the structure Employee
  Employee e;

  //IO Streams
  ifstream inStream("employees.txt"); //Declares inStream as an input stream an opens the file employees.txt

  //Checks for failure in opening file
  if(inStream.fail())
  {
    cout << "File name not found" << endl;
    exit(1);
  }

  //Calls fillUp function
  fillUp(inStream, e, allEmployees);

  //Stores the initial value of the function payRoll before value in vector allEmployees are manipulated
  double payRollSum = payRoll(allEmployees);

  //Manipulated output statements to display a header for displaying the data
  cout << "Sorted by name" << endl;
  cout << left << setw(8) << "ID";
  cout << setw(28) << "Name";
  cout << "Salary" << endl;
  cout << "---------------------------------------------" << endl;

  //Goes through every element in the vector allEmployees
  for(size_t i = 0; i < allEmployees.size(); i++)
  {
    //Calls the printAll function
    printAll(allEmployees[i]);
  }

  //Manipulated output statements for showing the total payroll
  cout << endl;
  cout << "Total PayRoll: $" << payRollSum << endl;


  //Closes input stream
  inStream.close();
  return 0;
}

void fillUp(ifstream &inStream, Employee &e, vector <Employee> &allEmployees)
{
  //Input stream assigns the first objects in input file to variables laid out in e
  inStream >> e.id;
  inStream >> e.firstName;
  inStream >> e.lastName;
  inStream >> e.salary;

  while(!inStream.eof())
  {
    //Assigns the objects in e to the vector allEmployees
    allEmployees.push_back(e);

    //Input stream assigns the rest of the objects in input file to variables laid out in e
    inStream >> e.id;
    inStream >> e.firstName;
    inStream >> e.lastName;
    inStream >> e.salary;
  }
}

void printAll(Employee &e)
{
  //Output Manipulators for displaying data in input file
  cout << left << setw(8) << e.id;
  cout << setw(20) << e.firstName + " " + e.lastName;
  cout << right << setw(9) << "$"<< fixed << setprecision(2) << e.salary << endl;
}

double payRoll(vector <Employee> &allEmployees)
{
  //sum stores the all the salaries added together
  double sum;

  //Counts every element in the vector allEmployees
  for(size_t i = 0; i < allEmployees.size(); i++) 
  {
    //sum adds itself to the previous value in the vector allEmployees
    sum += allEmployees[i].salary;
  }
  return sum;
}
