/*
*        File: car-dealer.cc
*      Author: Joey Ferenchak
*        Date: Jun 19, 2019
*      Description: A command line based program that helps the user shop for a new car.
*      User can view car models and options. User can add and remove any option/model they want.
*      Program stores all the prices and names for options from reading in a file named options.txt
*      Program will only read up until 30 lines in the options.txt file, any lines preceding the limit is ignored.
*      Program first has user display all prices for options and models, before selecting to add any.
*      Program allows up to 6 options to be chosen.
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

void menu();
/*
*  Function: menu
*  Prints out the menu for user.
*
*/

void fillUp(vector <int> &price, vector <string> &name);
/*
*  Function: fillUp
*  Fills up the vectors with objects from the options.txt file
*
*
*  @param vector <int> &price - Stores all the prices from the options.txt file
*  @param vector <string> &name - Stores all the names from the options.txt file
*/

void showModel(vector <int> &selectedPrices, vector <string> selectedOptions, vector <char> &selectedModel);
/*
*  Function: showModel
*  Shows the current price of the car, including the model and the added options
*  Also does the math getting the total sum when a option/model is added or subtracted
*
*  @param vector <int> &selectedPrices - Stores selected prices from user
*  @param vector <string> &selectedOptions - Stores selected options from user
*  @param vector <char> &selectedModel - Stores selected model from user
*/

void selectModel(vector <int> &selectedPrices, vector <char> &selectedModel);
/*
*  Function: selectModel
*  Lets user input a model for the car 
*
*  @param vector <int> &selectedPrices - Stores selected prices from user
*  @param vector <char> &selectedModel - Stores selected model from user
*  @return
*/

void selectOption(vector <int> &selectedPrices, vector <string> &selectedOptions, vector <int> price, vector <string> name);
/*
*  Function: selectOption
*  Lets user add in an option
*
*
*  @param vector <int> &selectedPrices - Stores selected prices from user
*  @param vector <string> &selectedOptions - Stores selected options from user
*  @param vector <int> &price - Stores all the prices from the options.txt file
*  @param vector <string> &name - Stores all the names from the options.txt file
*/

void removeOption(vector <int> &selectedPrices, vector <string> &selectedOptions, vector <int> price, vector <string> name);
/*
*  Function: removeOption
*  Lets user remove an added option
*
*  @param vector <int> &selectedPrices - Stores selected prices from user
*  @param vector <string> &selectedOptions - Stores selected options from user
*  @param vector <int> &price - Stores all the prices from the options.txt file
*  @param vector <string> &name - Stores all the names from the options.txt file
*
*/

void displayOption2(vector <int> &price, vector <string> &name);
/*
*  Function: displayOption2
*  Display all the price and options for the user
*
*
*  @param vector <int> &price - Stores all the prices from the options.txt file
*  @param vector <string> &name - Stores all the names from the options.txt file
*/

void cancelOrder(vector <int> &selectedPrices, vector <string> &selectedOptions, vector <char> &selectedModel);
/*
*  Function: cancelOrder 
*  Allows user to cancel their order, deleting all their selected options and model.
*
*  @param vector <int> &selectedPrices - Stores selected prices from user
*  @param vector <string> &selectedOptions - Stores selected options from user
*  @param vector <char> &selectedModel - Stores selected model from user
*/

bool check(int &choice, vector <int> &checkNumber);

/*
*  Function: check
*  Checks to make sure if choice to display all options and prices was selected
*
*
*  @param int &choice - Stores user decision
*  @param vector <int> &checkNumber - Stores all of user's decisions throughout the entire program.
*  @return 1 - If user has selected to display options at least once
*  @return 0 - If user has not selected to display options at least once
*/

int main() 
{
  int choice; //Stores in user choice

  vector <int> price; //Stores in the prices of the options/model from the options.txt file
  vector <int> selectedPrices; //Stores in the prices from the added options the user has selected
  vector <string> name; //Stores in the names  of the options from the options.txt file
  vector <string> selectedOptions; //Stores in the options' names from the added options the user has selected
  vector <char> selectedModel; //Stores the chosen model name from the user
  vector <int> checkNumber; //Stores in user inputs for selecting choices in menu

  fillUp(price, name); //Load objects from options.txt file
  showModel(selectedPrices, selectedOptions, selectedModel); //Display model, total price, and added options
  menu(); //Display menu

  //Have user input a choice
  while(cin >> choice)
  {
    cin.ignore();

    //First choice
    if(choice == 1)
    {
      //Checks to make sure options were already displayed. Result if user did print out options
      if(check(choice, checkNumber) == 1)
      {
        selectModel(selectedPrices, selectedModel); //Have user select model
        cout << endl;
        showModel(selectedPrices, selectedOptions, selectedModel); //Display model, total price, and added options
        menu(); //Display menu
      }

      //Result if user did not print out options
      else
      {
        cout << "Please Display options first" << endl << endl; //Prompts user to display options first
        showModel(selectedPrices, selectedOptions, selectedModel); //Display model, total price, and added options
        menu(); //Display menu
      }
    }
    
    //Choice 2
    else if(choice == 2)
    {
      check(choice,checkNumber); //Reads in the user has selected choice 2
      cout << endl;
      displayOption2(price, name); //Display options and prices
      showModel(selectedPrices, selectedOptions, selectedModel); //Display model, total price, and added options
      menu(); //Display menu
    }

    //Choice 3
    else if(choice == 3)
    {
      //Executes following code if no model is selected
      if(selectedModel.empty())
      {
        cout << "Please select a Model first" << endl << endl; //Tells user to first select model
        showModel(selectedPrices, selectedOptions, selectedModel); //Display model, total price, and added options
        menu(); //Display menu
      }

      //Executes following code a model is selected
      else
      {
        selectOption(selectedPrices, selectedOptions, price, name); //Have user add an option
        cout << endl;
        showModel(selectedPrices, selectedOptions, selectedModel); //Display model, total price, and added options
        menu(); //Display menu
      }
    }

    //Choice 4
    else if(choice == 4)
    {
      removeOption(selectedPrices, selectedOptions, price, name); //Have user remove option
      cout << endl;
      showModel(selectedPrices, selectedOptions, selectedModel); //Display model, total price, and added options
      menu();
    }

    //Choice 5
    else if(choice == 5)
    {
      //Executes following code if no model is selected
      if(selectedModel.empty())
      {
        cout << "Please Select a Model first" << endl << endl; //Tells user to first select model
        showModel(selectedPrices, selectedOptions, selectedModel); //Display model, total price, and added options
        menu(); //Displays menu
      }

      //Executes following code a model is selected
      else
      {
        cancelOrder(selectedPrices, selectedOptions, selectedModel); //Cancels order
        menu(); //Displays menu
      }
    }

    //Choice 6
    else if(choice == 6)
    {
      cout << "Exiting program..." << endl; //Tells user program is exiting
      break; //Breaks out of while loop
    }

    //Misc input
    else
    {
      cout << "Wrong input, try again" << endl << endl; //Tells user to enter a choice again
      showModel(selectedPrices, selectedOptions, selectedModel); //Display model, total price, and added options
      menu(); //Displays menu
    }
  }
  return 0; //Exits main function, causing the program to close
}

void menu()
{
  //Displaying choices with brief description about what they do
  cout << "1. Select a model (E, L, X)" << endl;
  cout << "2. Display available options and prices." << endl;
  cout << "3. Add an option." << endl;
  cout << "4. Remove an option." << endl;
  cout << "5. Cancel order." << endl;
  cout << "6. Quit. " << endl;
  cout << "Enter a choice: ";
}

void fillUp(vector <int> &price, vector <string> &name)
{
  ifstream inStream("options.txt"); //Declares inStream to open and stream objects from the file options.txt
  string line; //Takes a string from a specific line in options.txt
  int tempPrice, fileSize = 0; //tempPrice takes in the temporary price from the current line in options.txt, fileSize store current line number
  
  //Executes following code if options.txt fails to open
  if(inStream.fail())
  {
    cout << "File name not found" << endl; //Tells user file name not found
    exit(1); //Exits the main program
  }

  //Streams every object in options.txt
  while(inStream >> tempPrice)
  {
    //Reads every line number that is less than 30
    if(fileSize < 30)
    {
      price.push_back(tempPrice); //Stores current price from the current line in options.txt into the vector price
      getline(inStream, line); //Streams the rest of the objects in current line, then inputs the objects into line
      line.erase(line.begin()); //Removes first character in line
      name.push_back(line); //Stores the objects in line into the vector name
      fileSize++; //fileSize adds itself by one
    }
    
    //Exits while loop when streaming in objects is done
    else
    {
      break; 
    }
  }
  inStream.close(); //Closes the file options.txt
}

void displayOption2(vector <int> &price, vector <string> &name)
{
  //Show all available options
  cout << "Prices for model E, L, & X: $10000.00, $12000.00, $18000.00" << endl; 
  cout << "Available Options:" << endl << endl;

  //Prints out three options then inserts a new line
  for(size_t i = 0; i < price.size(); i++)
  {
    if(i % 3 == 2)
    {
      cout << name[i] << " ($" << price[i] << ") " << endl; //Prints out name of option and price of option, then inserts a newline
    }
    else
    {
      cout << name[i] << " ($" << price[i] << ") "; //Prints out name of option and price of option,
    }
  }
  cout << endl;
}

void showModel(vector <int> &selectedPrices, vector <string> selectedOptions, vector <char> &selectedModel)
{
  //Checks if a model was selected
  if(selectedModel.empty())
  {
    cout << "NO MODEL SELECTED" << endl << endl;
  }

  //Executes following code if a model was selected
  else
  {
    int sum = selectedPrices[0]; //Sum is initially equal to the price of the model

    //Sum adds itself to the integers in the vector selectedPrices
    for(size_t i = 1; i < selectedPrices.size(); i++)
    {
      sum += selectedPrices[i];
    }

    cout << "Model: " << selectedModel[0] << ", $" << sum << ","; // Displays the selected model, the total price;

    //Prints out "Options: None" if user did not select any options
    if(selectedOptions.empty())
    {
      cout << " Options: None" << endl;
    }

    //Executes following code if a model was selected
    else
    {
      cout << " Options: ";

      //Displays all the strings in the vector selectedOptions
      for(size_t i = 0; i < selectedOptions.size(); i++)
      {
          cout << selectedOptions[i] << ", ";
      }
      cout << endl;
    }
    cout << endl;
  }
}

void selectModel(vector <int> &selectedPrices, vector <char> &selectedModel)
{
  //Checks to see if user has already chosen a model
  if(!selectedModel.empty())
  {
    cout << "You have already chosen a model" << endl;
    return;
  }

  char tempModel; //Stores user's input
  cout << "Enter the model (E, L, X): ";
  cin >> tempModel;
  tempModel = toupper(tempModel); //Converts user's input to uppercase, so selecting a model is not case sensitive 

  //Executes following code if user has selected an existing model letter
  if(tempModel == 'E' || tempModel == 'L' || tempModel == 'X')  
  {
    double e = 10000, l = 12000, x = 18000; //Variables that represent each model's cost

    selectedModel.insert(selectedModel.begin(), tempModel); //inserts the value of tempModel into the first element in vector selectedModel 

    //Executes following code if tempModel equals e
    if(tempModel== 'E')
    {
      selectedPrices.insert(selectedPrices.begin(), e); //inserts the value of e into the vector of selectedPrices
    }

    //Executes following code if tempModel equals l
    else if(tempModel== 'L')
    {
      selectedPrices.insert(selectedPrices.begin(), l); //inserts the value of e into the vector of selectedPrices
    }

    //Executes following code if tempModel equals x
    else if(tempModel== 'X')
    {
      selectedPrices.insert(selectedPrices.begin(), x); //inserts the value of e into the vector of selectedPrices
    }
  }

  //Executes following code if user has not selected an existing model letter
  else
  {
    selectModel(selectedPrices, selectedModel); //Have user enter another input
  }
}

void selectOption(vector <int> &selectedPrices, vector <string> &selectedOptions, vector <int> price, vector <string> name)
{
  //Checks if the user has added more than five options
  if(selectedOptions.size() > 5)
  {
    cout << "Maxed out number of options." << endl;
    return; //Exits out of function
  }

  string option; //Stores user input for choosing an option to add
  cout << "Enter in an option: "; //Ask user to enter in an option
  getline(cin, option); //Gets the entire user's input, including whitespaces

  //Counts through the vector selectedOptions to make sure user is not adding an already added option
  for(size_t i = 0; i < selectedOptions.size(); i++)
  {
    //Executes the following code if user's inputted string is the same as one in the vector selectedOptions
    if(option == selectedOptions[i])
    {
      cout << option << " already added" << endl; //Tells user the option was already added
      return; //Exits out of function
    }
  }

  //Counts through the vector name to find a match for the inputted string
  for (size_t i = 0 ; i < name.size(); i++)
  {
    //Executes following code if match was found
    if(option == name[i])
    {
      cout << option << " added" << endl; //Tells user the option was added

      selectedOptions.push_back(name[i]); //Stores the value of the specific element in the vector name into the vector selectedOptions
      selectedPrices.push_back(price[i]); //Stores the value of the specific element in the vector price into the vector selectedPrices
      return; //Exits the function
    }
  }
  
  //Executes following code if no option was found
  if(option != name.back())
  {
    cout << "Option not found, try again." << endl; //Tells user no option was found
    selectOption(selectedPrices, selectedOptions, price, name); //Display model, total price, and added options
  }
}

void removeOption(vector <int> &selectedPrices, vector <string> &selectedOptions, vector <int> price, vector <string> name)
{
  //Executes following code if no options were chosen
  if(selectedPrices.empty())
  {
    cout << "No options chosen" << endl; //Tells user no options were chosen
    return; //Exits out of function
  }

  string option; //Stores user input for choosing an option to remove
  cout << endl;
  cout << "Enter what option you want to remove: "; //Ask user to remove an option
  getline(cin, option); //Gets the entire user's input, including whitespaces

  //Counts through the vector selectedOptions to find a match for the inputted string
  for(size_t i = 0; i < selectedOptions.size(); i++)
  {
    //Executes following code if match was found
    if(option == selectedOptions[i])
    {
      cout << option << " removed" << endl; //Tells user option was removed
      selectedOptions.erase(selectedOptions.begin()+i); //Erases the specific element in the vector selectedOptions
      selectedPrices.erase(selectedPrices.begin()+i+1); //Erases the specific element in the vector selectedPrices
      return; //Exits out of function
    }
  }

  //Executes following code if match was not found
  if(option != selectedOptions.back())
  {
    cout << "Option not found, try again."; //Tells user option was not found
    removeOption(selectedPrices, selectedOptions, price, name); //Calls function again to have user input an option again
  }
}
void cancelOrder(vector <int> &selectedPrices, vector <string> &selectedOptions, vector <char> &selectedModel)
{
  //Clears all the contents in the vectors selectedPrices, selectedOptions, and selectedModel.
  selectedPrices.erase(selectedPrices.begin(), selectedPrices.end());
  selectedOptions.erase(selectedOptions.begin(), selectedOptions.end());
  selectedModel.erase(selectedModel.begin(), selectedModel.end());
  cout << "Order cancelled" << endl << endl; //Tells user that the order was cancelled
  showModel(selectedPrices, selectedOptions, selectedModel); //Display model, total price, and added options
}

bool check(int &choice, vector <int> &checkNumber)
{
  checkNumber.push_back(choice); //Stores the user's input for choice into vector checkNumber

  //Goes through all the elements in checkNumber to find match for the user's input and the number 2
  for(size_t i = 0; i < checkNumber.size(); i++)
  {
    //If the match was found
    if(checkNumber[i] == 2)
    {
      return 1; //Assign the function a true value
    }
  }

  //If the match was not found
  if(checkNumber.back() != 2)
  {
    return 0; //Assign the function a false value
  }
 return 0;  //By default assign the function a false value
}
