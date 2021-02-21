/*
*   Author: Jesus Villarroel
*   Spring 2021
*   Class: COSC 2436
*   Project: Program #1 - Review
*/
 
/* 
	Write a class named Car that has the following member variables:

    year. An int that holds the car’s model year.
    make. A string object that holds the make of the car.
    speed. An int that holds the car’s current speed. 

    In addition, the class should have the following member functions. 

    Constructor. The constructor should accept the car’s year and make as arguments and assign these values to
    the object’s year and make member variables. The constructor should initialize the speed member variable to 0.
    Accessors. Appropriate accessor functions should be created to allow values to be retrieved from an object’s
    year, make, and speed member variables.
    accelerate. The accelerate function should add 5 to the speed member variable each time it is called.
    brake. The brake function should subtract 5 from the speed member variable each time it is called. 

    Demonstrate the class in a program that creates a Car object and then calls the accelerate function five times.
    After each call to the accelerate function, get the current speed of the car and display it. Then, call the
    brake function five times. After each call to the brake function, get the current speed of the car and display it.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Define Car class
class Car
{
public:
    // Constructors
	Car();
    Car(int, string);

    // Destructor
	~Car();

    // Accesor functions
    int getYear(void);
    string getMake(void);
    int getSpeed(void);

    // Modifier functions
    void accelerate(void);
    void brake(void);


private:
    int     year;
    string  make;
    int  speed;

};

// Function prototypes
void displayData(Car);

int main()
{
    Car myCar(2007, "Toyota");
    char userSel = ' ';

    // Display initial message.
    cout << "Program 1 to demonstrate the use of classes.\n\n"
        << "The program consist of a car that accelerate or brake according to user selection.\n\n"
        << "The car accelerate and brake in steps of 5mph.\n"
        << "Press --> \"a\" to accelerate\n"
        << "Press --> \"b\" to brake\n"
        << "Any other selection will terminate the program.\n\n";

    

    do
    {
        // Display car's information and speed.
        displayData(myCar);

        // Get user selection.
        cin.get(userSel);
        cin.ignore(100, '\n');

        // Execute user's selection.
        switch (userSel)
        {
        case 'a':
        case 'A':
            myCar.accelerate();
            break;

        case 'b':
        case 'B':
            myCar.brake();
            break;

        default:
            break;
        }
    } while (userSel == 'a' || userSel == 'A' || userSel == 'b' || userSel == 'B');

	return 0;
}

/// <summary>
/// Default cosntructor.
/// </summary>
Car::Car()
{
    year = 0;
    make = "";
    speed = 0;
}

/// <summary>
/// Constructor accepts two arguments to initialize variables. Year must be a positive number.
/// </summary>
/// <param name="_year"></param>
/// <param name="_make"></param>
Car::Car(int _year, string _make)
{
    if (_year >= 0)
        year = _year;
    else
        year = 0;

    make = _make;

    speed = 0;
}

/// <summary>
/// Default destructor.
/// </summary>
Car::~Car()
{
}

/// <summary>
/// Return car year.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
int Car::getYear(void)
{
    return year;
}

/// <summary>
/// Return car make.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
string Car::getMake(void)
{
    return make;
}

/// <summary>
/// Get car's speed.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
int Car::getSpeed(void)
{
    return speed;
}

/// <summary>
/// Accelerate car's speed by 5mph.
/// </summary>
/// <param name=""></param>
void Car::accelerate(void)
{
    // Checks if cars speed is maximum.
    if (speed <= 140)
        speed += 5;
}

/// <summary>
/// Decrease 5mph on car's speed. 
/// </summary>
/// <param name=""></param>
void Car::brake(void)
{
    // Checks if speed is already 0.
    if (speed > 0)
        speed -= 5;
}

/// <summary>
/// Display car's information and speed.
/// </summary>
/// <param name="_car"></param>
void displayData(Car _car)
{
    cout << "The " << _car.getYear() << " " << _car.getMake() << " speed is: " << _car.getSpeed() << "mph\t\t";
}