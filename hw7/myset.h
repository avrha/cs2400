/*
*        Files: myset.h, myset.cc myset-main.cc
*
*        Author: Joey Ferenchak
*        Date: Jun 26, 2019
*
*        Description: 
*        Overloads arithmetic operators (+,-,*,^,<=,>=,==) to have special functionality with vectors.
*        Program has been split and written in separate files. 
*        myset.h contains the header for the MySet class, along with all the variables and function prototypes in the class.
*        myset-main.cc is used for testing overloading operators.
*        Program was tested by running the TEST_cases file in the _TEST folder.
*/

#include <vector>
#include <string>
using namespace std;

class MySet
{
  private:
    //private variables
    vector <int> elements = vector <int>(); //initializes vector element an empty vector of integers

  public:
    //functions prototypes
    int size();

    /*
    *  Function: size
    *  Gets the size of the vector
    *  
    *  @return elements.size - assigns the value of the function to the size of the vector
    */

    void clear();

    /*
    *  Function: clear
    *  Clears the vector
    *  
    *  @return elements.clear - assigns the value of the function to the size of the empty vector
    */

    void sort(int val);

    /*
    *  Function: sort
    *  Sorts all the elements in a vector/array from least to greatest
    *
    *  
    *  @param val - size of the vector/size
    */

    string toString();

    /*
    *  Function: toString
    *  Formats all elements in a vector to a string
    *  
    *  @return str - assigns the value of the function to the formatted string
    */

    //constructor
    MySet();

    /*
    *  Constructor: MySet
    *  Default constructor that assigns an empty vector to newly declared class objects
    */

    //operator overloads prototypes
    friend bool operator^(int val, MySet& set);

    /*
    *  Function: operator^ | membership
    *  Overloads the ^ operator to check for duplicates between an integer value and a vector of integers
    *  
    *  @param val - single integer value to be compared with vector
    *  @param set - vector of integers that belong to the MySet class
    *  @return true/false - assigns the value of the function true if a duplicate was found, or false if none was found
    */

    friend MySet operator+(MySet& set, int val);

    /*
    *  Function: operator+ | addition
    *  Overloads the + operator to add a single integer to a vector of integers
    *  
    *  @param set - vector of integers that belong to the MySet class
    *  @param val - single integer value to be compared with vector
    *  @return set - assigns the value of the function the added vector
    */

    friend MySet operator+(MySet& set, MySet& set2);

    /*
    *  Function: operator+ | union
    *  Overloads the + operator to add all the elements in the two vectors of integers. Does not add duplicate elements
    *  
    *  @param set - vector of integers that belong to the MySet class
    *  @param set2 - vector of integers that belong to the MySet class
    *  @return set - assigns the value of the function a vector that stores all elements in two vectors
    */

    friend MySet operator-(MySet& set, int val);

    /*
    *  Function: operator- | subtraction
    *  Overloads the - operator to subtract a single integer to a vector of integers
    *  
    *  @param set - vector of integers that belong to the MySet class
    *  @param val - single integer value to be compared with vector
    *  @return set - assigns the value of the function the subtracted vector
    */

    friend MySet operator*(MySet& set, MySet& set2);

    /*
    *  Function: operator* | intersection
    *  Overloads the * operator to find any similar elements between two vectors 
    *  
    *  @param set - vector of integers that belong to the MySet class
    *  @param set2 - vector of integers that belong to the MySet class
    *  @return set3 - assigns the value of the function a vector that contains all elements in both vectors
    */

    friend MySet operator-(MySet& set, MySet& set2);

    /*
    *  Function: operator- | difference
    *  Overloads the - operator to find any differences in elements between two vectors
    *  
    *  @param set - vector of integers that belong to the MySet class
    *  @param set2 - vector of integers that belong to the MySet class
    *  @return set3 - assigns the value of the function a vector that contains all elements in the first vector but not second.
    */

    friend bool operator<= (MySet& set, MySet& set2);

    /*
    *  Function: operator<= | subset
    *  Overloads the <=  operator to check if all elements in the first vector is in the second vector
    *  
    *  @param set - vector of integers that belong to the MySet class
    *  @param set2 - vector of integers that belong to the MySet class
    *  @return true/false - assigns the value of the function true if all elements in the first vector are found in the second vector.
    *  Assigns the value of the function false if not all the elements in the first vector are found in the second vector.
    */

    friend bool operator>= (MySet& set, MySet& set2);

    /*
    *  Function: operator>= | superset
    *  Overloads the >=  operator to check if all elements in the second vector is in the first vector
    *  
    *  @param set - vector of integers that belong to the MySet class
    *  @param set2 - vector of integers that belong to the MySet class
    *  @return true/false - assigns the value of the function true if all elements in the second vector are found in the first vector.
    *  Assigns the value of the function false if not all the elements in the second vector are found in the first vector.
    */

    friend bool operator== (MySet& set, MySet& set2);

    /*
    *  Function: operator== | equality
    *  Overloads the ==  operator to check if both vectors contain the same elements (in particular order)
    *  
    *  @param set - vector of integers that belong to the MySet class
    *  @param set2 - vector of integers that belong to the MySet class
    *  @return true/false - assigns the value of the function true if the two vectors contain the same elements
    *  Assigns the value of the function false if the two vectors do not contain the same elements.
    */
};
