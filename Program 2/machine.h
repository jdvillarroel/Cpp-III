#pragma once

#ifndef MACHINE_H_
#define MACHINE_H_

#include	"main.h"

struct Drink {
    string      name;
    double      price;
    int         quantity;
};

const   int     DRINKS_TYPE = 5;

class SoftDrinkMachine
{
public:
    // Default Constructor
	SoftDrinkMachine();

    // Default Destructor
	~SoftDrinkMachine();

    // Custom Functions
    int displayChoices(void);
    void buyDrink(int);
    void returnMoney(double);

    // Getter Functions
    Drink getDrink(int);

    // Setter Function.
    void setDrinkQuantity(int);

private:
    // Drinks available
    Drink   drinks[DRINKS_TYPE];

    // Private functions
    double inputMoney(int);
    void dailyReport(void);
};





#endif