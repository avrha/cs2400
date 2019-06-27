/*                                                                    
*  Program: lab7.cc
*  
*  Author: Joey Ferenchak    
*  Email: jf440918@ohio.edu     
*  
*  Description: 
*  Uses classes to compare a computer chosen computer build vs a user chosen computer build. 
* 
*  Date: June 12, 2019       
*/

#include <iostream>
using namespace std;

class Computer
{
  public:
    //Constructs prototype
    Computer();

    /*
    * Initializes all variables to their default values
    */

    Computer(int tempRam, int tempHd, float tempSpeed, string tempType);

    /*
    * Initializes all variables to the member variables 
    */

    //Getter function prototypes
    int getRam();
    int getHd();
    string getType();
    float getSpeed();

    //Setter function prototypes
    void setRam(int val);
    void setHd(int val);
    void setType(string str);
    void setSpeed(float val);

    //Operator overload prototypes
    friend ostream& operator << (ostream &out, Computer &comp);
    /*
    * Overload: << 
    * Outputs all data in object
    *
    * @param ostream &out - streams out data from object
    * @param Computer &comp - temporary object defined by class.
    * @return out - returns output from object
    *
    */

    friend istream& operator >> (istream &in, Computer &comp);
    /*
    * Overload: >>
    * Inputs data into object
    *
    * @param istream &in - streams in data from user to object
    * @param Computer &comp - temporary object defined by class
    * @returns input - return input from object
    */

    friend bool operator < (Computer &comp, Computer &comp2);
    /*
    * Overload: <
    * Compares one object to another
    * 
    * @param comp - temporary object defined by class
    * @param comp2 - temporary object defined by class
    @ @return 1 or 0 - returns true or false depending if objects are greater or less than  to each other
    */
    friend bool operator == (Computer &comp, Computer &comp2);
    /*
    * Overload: ==
    * Sees if two objects are the same
    * 
    * @param comp - temporary object defined by class
    * @param comp2 - temporary object defined by class
    @ @return 1 or 0 - returns true or false depending if objects are similar to each other
    */

    //Calculation function prototypes
    double price();
    /*
    *   Function: Price
    *   Member function, gets the total price of a computer build
    *
    *   @return price - assigns the function the price of the computer build
    */

  private:
    int ram, hd; //stores ram and hard drive values
    float speed; //stores processor speed (GHz) value
    string type; //stores the name of the laptop
};

//Constructs definitions
Computer::Computer()
{
  //Default values
  ram = 8;
  hd = 500;
  speed = 1.6;
  type = "Desktop";
}

Computer::Computer(int tempRam, int tempHd, float tempSpeed, string tempType)
{
  //Assigns values from the parameters 
  ram = tempRam;
  hd = tempHd;
  speed = tempSpeed;
  type = tempType;
}

//Getters definitions
int Computer::getRam()
{
  return ram;
}

int Computer::getHd()
{
  return hd;
}

string Computer::getType()
{
  return type;
}

float Computer::getSpeed()
{
  return speed;
}

//Setters definitions
void Computer::setRam(int val)
{
  ram = val;
}

void Computer::setHd(int val)
{
  hd = val;
}

void Computer::setType(string str)
{
  type = str;
}

void Computer::setSpeed(float val)
{
  speed = val;
}

//Operator overload definition
ostream& operator << (ostream &out, Computer &comp)
{
  out << comp.ram << " " << comp.hd << " " << comp.speed << " " << comp.type;
  return out;
}

istream& operator >> (istream &in, Computer &comp)
{
  in >> comp.ram >> comp.hd >> comp.speed >> comp.type;
  return in;
}

bool operator < (Computer &comp, Computer &comp2)
{
  if(comp.price() < comp2.price())
  {
    return 1;
  }
  return 0;
}

bool operator == (Computer &comp, Computer &comp2)
{
  if(comp.price() == comp2.price())
  {
    return 1;
  }
  return 0;
}

//Calculation function definition
double Computer::price()
{
  if(type == "desktop" || type == "Desktop")
  {
    double price = 400;
    price += (ram * 4.00);
    price += (hd * 0.10);
    price += (speed - 1.6) * 200;
    return price;

  }

  else
  {
    double price = 600;
    price += (ram * 5.00);
    price += (hd * 0.15);
    price += (speed - 1.6) * 200;
    return price;
  }
}

int main()
{
  Computer comp; //use default constructor
  Computer comp1(16, 1000, 1.6, "Laptop");
  cout << comp << endl; //output defaults
  cout << endl;
  cout << comp1 << endl;
  cout << endl;
  comp1.setRam(32);
  comp1.setHd(2000);
  cout << "The computer ram was changed to " << comp1.getRam() << endl;
  cout << "The computer hd was changed to " << comp1.getHd() << endl;
  cout << "Updated info" << endl << endl;
  cout << comp1 << endl;
  cout << endl;
  comp1.setType("desktop");
  cout << "Computer type was changed to Desktop" << endl;
  cout << comp1 << endl;
  Computer comp2;
  cout << "Enter specs of a computer (Ram, HD, Speed, Type)" << endl;
  cin >> comp2;
  cout << comp2 << endl;
  if (comp1 < comp2)
  {
    cout << "Computer 2 is more expensive" << endl;
  }

  else
  {
    cout << "Computer 1 is more expensive" << endl;
  }

  if (comp1 == comp2)
  {
    cout << "comp1 and comp2 have the same specifications" << endl;
  }
  return 0;
}
