/*                                                                    
*  Program: arrays.cc   
*  
*  Author: Joey Ferenchak     
*  Email: jf440918@ohio.edu
*  
*  Description:
*  Prints all the contents in two files, then prints out 
*  the greatest and least value.             
*  
*  Date: June 11, 2019      
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

//Function prototypes 
void loadNames(string dataNames[6], ifstream& inStreamNames);
void loadPrices(string dataPrices[6], ifstream& inStreamPrices);
void printAll(string dataNames[6], string dataPrices[6], ifstream& inStreamNames, ifstream& inStreamPrices);
int getLarge(string dataPrices[6]); 
int getSmallest(string dataPrices[6]);

int main()
{
  system("clear"); //Clears terminal on startup 

  ifstream inStreamPrices("data1.txt"); //Declares variable inStreamPrices and opens data1.txt
  ifstream inStreamNames("data2.txt"); //Declares variable inStreamNames and opens data2.txt

  string dataNames[6]; //Declares array dataNames to hold six strings.
  string dataPrices[6]; //Declares array dataPrices to hold six strings.
  
  //Checks if file fails to open
  if(inStreamPrices.fail())
  {
    cout << "File name not found." << endl;
    exit(1);
  }

  //Checks if file fails to open
  if(inStreamNames.fail())
  {
    cout << "File name not found." << endl;
    exit(1);
  }

  //Calls printall function
  printAll(dataNames, dataPrices, inStreamNames, inStreamPrices);
  cout << endl;

  int largest = getLarge(dataPrices) - 1; //Variable largest stores the index of the most expensive part
  cout << "The most expensive part is: " << dataNames[largest]; //Prints out the name of the most expensive part

  cout << endl;

  int smallest = getSmallest(dataPrices) -1; //Variable smallest stores the index of the least expensive part
  cout << "The least expensive part is: " << dataPrices[smallest]; //Prints out the name of the least expensive part

  //Closes the files
  inStreamNames.close();
  inStreamPrices.close();

  return 0;
}

/*
*  Function: loadNames
*            Loads the Names from data2.txt to the array dataNames 
*             
*
*  @param dataNames[6] - An array strings with a set width of six elements
*  @param inStreamNames - Streams objects from data2.txt
*/

void loadNames(string dataNames[6], ifstream& inStreamNames)
{
  string line; //Line takes in contents from data2.txt
  int i = 0; //I is used to count up the index in the array dataNames.

  while(getline(inStreamNames, line))
  {
    dataNames[i] = line; //Assigns the contents in line to the specific index in dataNames.
    i++; //I adds itself by one.
  }
}

/*
*  Function: loadPrices
*            Load the Prices from data1.txt to the array dataPrices
*             
*             
*
*  @param dataPrices[6] - An array of strings with a set width of six elements
*  @param inStreamPrices - Streams objects from data1.txt
*/

void loadPrices(string dataPrices[6], ifstream& inStreamPrices)
{
  string line; //Line takes in contents from data1.txt
  int i = 0;//I is used to count up the index in the array dataPrices.
  
  while(getline(inStreamPrices, line))
  {
    dataPrices[i] = line; //Assigns the contents in line to the specific index in dataPrices.
    i++; //I adds itself by one
  }
}

/*
*  Function: getLarge
*            Finds the index of the most expensive part
*             
*  @param dataPrices - An array of strings with a set width of six elements
*  @return maxIndex - Assigns the function the index of most expensive part
*/

int getLarge(string dataPrices[6])
{
  string max = dataPrices[0]; //Assigns the index in dataPrices
  int maxIndex = 0; //Assigns the the initial max index in dataPrices

  //Counts each index until the last element in the array.
  for(int i = 0; i < 6; i++)
  {
    //Updates maxIndex with new value if current index greater than the max index
    if(dataPrices[i] > max)
    {
      max = dataPrices[i];
      maxIndex = i;
    }
  }
  return maxIndex;
}

/*
*  Function: getSmallest 
*            Finds the index of the least expensive part 
*             
*
*  @param dataPrices - An array of strings with a set width of six elements
*  @return minIndex - Assigns the function the index of least expensive part
*/

int getSmallest(string dataPrices[6])
{
  string min = dataPrices[0]; //Assigns the index in dataPrices
  int minIndex = 0; //Assigns the initial min index in dataPrices

  //Counts each index until the last element in the array.
  for(int i = 0; i < 6; i++)
  {
    //Updates minIndex with new value if current index is less than the min index
    if(dataPrices[i] < min)
    {
      min = dataPrices[i];
      minIndex = i;
    }
  }
  return minIndex;
}

/*
*  Function: printAll
*            Prints all the names and values of the parts 
*             
*
*  @param dataNames - An array of strings with a set width of six elements
*  @param dataPrices - An array of strings with a set width of six elements 
*  @param inStreamPrices - Streams objects from data1.txt
*  @param inStreamNames - Streams objects from data2.txt
*/

void printAll(string dataNames[6], string dataPrices[6], ifstream& inStreamNames, ifstream& inStreamPrices)
{
  //Calls loadNames and loadPrices function 
  loadNames(dataNames, inStreamNames);
  loadPrices(dataPrices, inStreamPrices);

  //Aligns the output to make print statement clean
  cout << setw(27) << "Name | Price" << endl;
  cout << "----------------------------------------" << endl;

  //Counts and prints every index until last element.
  for(int i = 0; i < 6; i++)
  {
    cout << setw(20) <<  dataNames[i] << ": ";
    cout << dataPrices[i] << " ";
    cout << endl;
  }
}
