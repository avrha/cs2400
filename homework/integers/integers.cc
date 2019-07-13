/*                                                                    
*  Program:     integers.cc 
*  
*  Author:      Joey Ferenchak 
*  Email:       jf440918@ohio.edu
*  
*  Description: Performs one of four base functionalities on user's command.
*               Program finds number of digits, nth digit, sum all digits in an integer.
*               Program also determines if integer is a palindrome.
*  
*  Date:        June 7, 2019
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

/*
*  Function: menu
*            Prints out menu with options for user to select.
*/

void menu()
{
  cout << "1. Find the number of digits in an integer." << endl;
  cout << "2. Find the nth digit in an integer." << endl;
  cout << "3. Find the sum of all digits of an integer." << endl;
  cout << "4. Is the integer a palindrome?" << endl;
  cout << "5. Quit" << endl;
  cout << "Enter a choice: ";
}

/*
*  Function: getInteger 
*            Ensures user inputs a postive integer. 
*
* @param return - Assigns the function the positive integer.
*/

int getInteger()
{
  //temp stores the value of the integer 
  int temp;
  cout << "Enter in an integer number: ";

  //while loop with if statements to ensure inputs a positive integer 
  while(cin >> temp)
  {
    if(temp < 0)
    {
      cout << "Enter in an integer number: ";
    }

    else if (temp >= 0)
    {
      break;
    }
  }
  return temp;
}

/*
*  Function: getNumDigits
*            Finds the number of digits in an integer. 
*             
*  @param number - Holds the value for inputted integer. 
*  @return count - Assigns function the value for number of digits in an inputted integer. 
*/

int getNumDigits(int number)
{
  number = getInteger();
  cout << number << " has ";
  int count = 1;

  //Each time number is divisible by ten there is one known digit. 
  while(number /= 10)
  {
    count++; //Count adds itself by one each loop.
  }
  return count;
}

/*
*  Function: getNthDigit
*            Finds the nth digit in an inputted integer. 
*
*  @param number - Holds the value for inputted integer. 
*  @param n - Intakes the value for the specific position in integer.
*  @return location - Assigns function the value for location for inputted position.
*/

int getNthDigit(int number, int n)
{
  number = getInteger(); //Stores the value of the inputted integer.
  int tempNum = number; //Stores the same value as number, used to find size of inputted integer. 
  int size = 1; //Stores the size of the number.

  //Continuously Divides tempNum by 10 to find number size.
  while(tempNum /= 10)
  {
    size++; //Size adds itself by one each loop.
  }

  cout << "Enter a position: ";

  //While loop with if statements to ensure user inputs a valid position according to number's size.
  while(cin >> n)
  {
    if(n > size || n < 0)
    {
      cout << "Invalid input, try again: ";
    }

    else
    {
      break;
    }
  }

  cout << "Digit number " << n << " is ";

  int position = (number/ pow(10, n-1)); //Position holds the calculation of number divided by 10 the power of n -1. 
  int location = position % 10; //Location stores position's remainder of 10, determining the nth digit in an integer.

  return location;
}

/*
*  Function: getSumDigits
*            Finds the sum of all digits in an integer.
*
*  @param number - Holds the value for inputted integer. 
*  @return sum - Assigns function the sum of all digits in an integer.
*/

int getSumDigits(int number)
{
  number = getInteger(); //Stores the value of the inputted integer.
  cout << "The sum of all digits in " << number << " is ";

  int sum = 0; //Stores the sum of all digits in an integer.

  //While loop to run calculation until number equals 0.
  while(number != 0)
  {
    sum = sum + number % 10; //Sum is equal to number's last remainder of 10 plus number's current remainder of 10.
    number /= 10; //Divides number by 10 to keep lowering value.
  }
  return sum;
}

/*
*  Function: isPalindrome
*            Determines if integer is a palindrome. 
*             
*  @param getInteger - Calls the getInteger for user to input a positive integer.
*  @return 0 - Assigns function the value of zero.
*/

bool isPalindrome(int getInteger())
{
  int mod = getInteger(), num = mod, rev = 0, digit;

  /*
  *  int mod - Stores the value of the inputted integer.
  *  
  *  int num - Stores the value of mod and is used to find the palindrome in an integer.
  *
  *  int rev - Stores all the digits in the variable mod in reverse order.
  *
  *  int digit - Stores a single digit from the variable mod. 
  */

  //Calculation to create a reverse number of digits runs until mod equals 0.
  while(mod != 0)
  {
    digit = mod % 10; //Digit is equal to mod's last remainder to zero. 
    rev = (rev * 10) + digit; //rev is equal to the product of rev and 10 plus the latest value of digit.
    mod /= 10; //Divides num by 10 to keep lowering value.
  }

  //Determines if integer is a palindrome by seeing if variables num and rev have the same value.
  if (num == rev)
  {
    cout << "Number " << num << " is a palindrome" << endl;
    cout << endl;
  }

  else
  {
    cout << "Number " << num << " is not a palindrome" << endl;
    cout << endl;
  }
  return 0;
}


int main()
{
  system("clear"); //Clears terminal at start of program.
  int choice = 0; //Stores the value of user's selected choice.
  menu(); //Calls menu function, displays choice to user.

  //While loop with if statements to execute user's selected choice.
  while(cin >> choice)
  {
    //First choice calls getNumDigits function, then calls menu function.
    if(choice == 1)
    {
      cout << getNumDigits(0) << " digits" << endl << endl;
      menu();
    }

    //Second choice calls getNthDigit function, then calls menu function.
    else if(choice == 2)
    {
      cout << getNthDigit(0,0) << endl << endl;
      menu();
    }

    //Third choice calls getSumDigits function, then calls menu function.
    else if(choice == 3)
    {
      cout << getSumDigits(0) << endl << endl;
      menu();
    }

    //Fourth choice calls isPalindrome function, then calls menu function.
    else if(choice == 4)
    {
      isPalindrome(getInteger);
      menu();
    }

    //Fifth choice leaves while loop.
    else if(choice == 5)
    {
      cout << "Exiting program..." << endl;
      break;
    }

    //A random input tells user to reenter a choice, then calls menu function.
    else
    {
      cout << "Invalid input, try again" << endl;
      cout << endl;
      menu();
    }
  }
  return 0;
}
