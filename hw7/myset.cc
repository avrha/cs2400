#include <vector>
#include "myset.h"
using namespace std;

//constructor defintion
MySet::MySet()
{
  elements = {};
}

//size function
int MySet::size()
{
  //uses c++'s built in function size to get size of vector 
  return elements.size(); 
}

//membership operator
bool operator^(int val, MySet& set) 
{
  //goes through each element in vector
  for (int i = 0; i < set.size(); i++)
  {
    //function is assigned a true value if match is found
    if (val == set.elements[i]) 
    {
      return true;
    } 
  }
  //function is assigned a true value if no match is found
  return false;
}

//addition operator
MySet operator+(MySet& set, int val) 
{
  //Sees if integer is a duplicate in vector 
  if (!(val ^ set)) 
  {
    //adds integer to vector after knowing integer is not a duplicate
    set.elements.push_back(val); 
  }

  //calls toString function to sort elements in vector from least to greatest
  set.toString(); 
  return set;
}

//union operator
MySet operator+(MySet& set, MySet& set2)
{
  //goes through each element in second vector
  for(int i = 0;  i < set2.size(); i++)
  {
    //first vector adds any non duplicated elements in second vector
    set + set2.elements.at(i);
  }

  //calls toString function to sort elements in vector from least to greatest
  set.toString(); 
  return set;
}

//string function
string MySet::toString() 
{
  //Calls sort function to sort elements in vector from least to greatest
  sort(size());

  //str will contain all the elements in the vector.
  string str = "{";

  //loops through vector to use each element
  for(int i = 0, count = size(); i < count; i++)
  {
    //str stores the current element in the for loop
    str += to_string(elements[i]);

    //if statement does not apply to last element in vector
    if(i != count - 1)
    {
      //str stores a comma and space for formatting
      str += ", ";
    }
  }

  str += "}";

  return str;
}  

//sort function
void MySet::sort(int val)
{
  //i and j serve as counters. min and temp store throwaway value
  int i, j, min, temp;

  //loops through vector to use each element
   for (i = 0; i < val - 1; i++) 
   {
     //smallest value is equal to element position
      min = i;

      //loops through vector like first for loop, but ahead one element position
      for (j = i + 1; j < val; j++)

         //executes following statement if current element (j) is smaller than the current smallest element (min) in loop
         if (elements[j] < elements[min])

            //assigns the new smallest value in loop
            min = j; 

      //temp is equal to current element in vector
      temp = elements[i]; 
      //current element is equal to smallest value in vector
      elements[i] = elements[min]; 
      //temp is equal to current smallest value in vector
      elements[min] = temp; 
   }
}

//clear function
void MySet::clear()
{
    //uses c++'s built in function clear to empty the vector 
    elements.clear();
}

//subtraction operator 
MySet operator-(MySet& set, int val)
{
  //loops through vector to use each element
  for(int i = 0; i < set.size(); i++)
  {
    //checks if current element and integer are duplicates
    if(set.elements[i] == val)
    {
      //removes element in vector
      set.elements.erase(set.elements.begin() + i);
    }
  }

  //calls toString function to sort elements in vector from least to greatest
  set.toString();
  return set;
}

//intersection operator
MySet operator*(MySet& set, MySet& set2)
{
  //set3 will store matching elements from the first vector (set1)
  MySet set3;

  //loops through set1 to use each element
  for(int i = 0; i < set.size(); i++)
  {
    //if statement is used if a matching element is found between the two vectors
    if((set.elements.at(i) ^ set2))
    {
      //set3 stores the matching element from set1
      set3 + set.elements.at(i);
    }
  }

  //calls toString function to sort elements in vector from least to greatest
  set3.toString();
  return set3;
}

//difference operator
MySet operator-(MySet& set, MySet& set2)
{
  //set3 will store differing elements from the first vector (set1)
  MySet set3;

  //loops through set1 to use each element
  for(int i = 0; i < set.size(); i++)
  {
    //if statement is run if no match is found between the two vectors
    if(!(set.elements.at(i) ^ set2))
    {
      //set3 stores the differing element from set1
      set3 + set.elements.at(i);
    }
  }

  //calls toString function to sort elements in vector from least to greatest
  set3.toString();
  return set3;
}

//subset operator 
bool operator<=(MySet& set, MySet& set2)
{
  //loops through first vector to use each element
  for(int i = 0; i < set.size(); i++)
  {
    //if statement is not run if current element in first vector is equal to the current element in the second vector
    if(!(set.elements[i] ^ set2))
    {
      //function is assigned a false value if no match was found
      return 0;
    }
  }
  //function is assigned a true value after exiting for loop
  return 1;
}

//superset operator
bool operator>=(MySet& set, MySet& set2)
{
  //loops through second vector to use each element
  for(int i = 0; i < set2.size(); i++)
  {
    //if statement is not run if current element in second vector is equal to the current element in the first vector
    if(!(set2.elements[i] ^ set))
    {
      //function is assigned a false value if no match was found
      return 0;
    }
  }
  //function is assigned a true value after exiting for loop
  return 1;
}

//equality operator
bool operator==(MySet& set, MySet& set2)
{
  //function is assigned a true value if subset and superset operator are both true
  if(set <= set2 && set >= set2)
  {
    return 1;
  }

  //function is assigned a false value if one/both subset and superset operator are false
  return 0;
}
