#include <iostream>
#include <cstdlib>
using namespace std;

void menu()
{
  cout << "1. Find the number of digits in an integer." << endl;
  cout << "2. Find the nth digit in an integer." << endl;
  cout << "3. Find the sum of all digits of an integer." << endl;
  cout << "4. Is the integer a palindrome?" << endl;
  cout << "5. Quit" << endl;
  cout << "Enter a choice: ";
}

int getInteger()
{
  int temp;
  cout << "Enter in a positive integer: ";
  
  while(cin >> temp)
  {
    if(temp < 0)
    {
      cout << "Enter in a positive integer: ";
    }

    else if (temp >= 0)
    {
      break;
    }
  }
  return temp;
}

int getNumDigits(int number)
{
  number = getInteger();
  return number;
} 

int main()
{
  int choice = 0;
  menu();

  while(cin >> choice)
  {
    if(choice == 1)
    {
      cout << getNumDigits(0) << endl;
      menu();
    }

    else if(choice == 2)
    {
      cout << "2" << endl;
      menu();
    }

    else if(choice == 3)
    {
      cout << "3" << endl;
      menu();
    }

    else if(choice == 4)
    {
      cout << "4" << endl;
      menu();
    }

    else if(choice == 5)
    {
      cout << "Exiting program..." << endl;
      break;
    }

    else
    {
      cout << "Invalid input, try again" << endl;
      menu();
    }
  }
  return 0;
}
