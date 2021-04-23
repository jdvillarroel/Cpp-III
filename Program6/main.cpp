/*
* Jesus Villarroel
* COSC2436
* Spring 2021
*/

/*
* A corporation has six divisions, each responsible for sales to different geographic locations.
  Design a DivSales class that keeps sales data for a division, with the following members:

  An array with four elements for holding four quarters of sales figures for the division. A private
  static variable for holding the total corporate sales for all divisions for the entire year. A member
  function that takes four arguments, each assumed to be the sales for a quarter. The value of the
  arguments should be copied into the array that holds the sales data. The total of the four arguments
  should be added to the static variable that holds the total yearly corporate sales. A function that
  takes an integer argument within the range of 0 to 3. The argument is to be used as a subscript into
  the division quarterly sales array. The function should return the value of the array element with
  that subscript.

  Write a program that creates an array of six DivSales objects. The program should ask the user to
  enter the sales for four quarters for each division. After the data is entered, the program should
  display a table showing the division sales for each quarter. The program should then display the
  total corporate sales for the year.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "DivSales.h"

using namespace std;

// *************** Global Variables ************* //
const int	N_DIVISIONS = 6;
double	DivSales::totalCorpSales = 0.0;

// *************** Function Prototypes ************* //
void displayInitMsg(void);
void printSalesData(DivSales*);

int main()
{
	// Create divisions
	DivSales	divisionSales[N_DIVISIONS];
	double		qSales[4] = { 0.0 };

	// Initial msg
	displayInitMsg();

	// Prompt user to enter the sales data corresponding to each division.
	for (int i = 0; i < N_DIVISIONS; i++)
	{
		cout << "//******* Enter sales for division #" << (i + 1) << " *******//\n\n";

		for (int j = 0; j < 4; j++)
		{
			cout << "\nEnter sales for Quater - Q" << (j + 1) << " : $";
			cin >> qSales[j];
			cin.ignore(100, '\n');
		}
		cout << endl << endl;

		// Set sales for the corresponding division.
		divisionSales[i].setQuaterSales(qSales[0], qSales[1], qSales[2], qSales[3]);
	}

	printSalesData(divisionSales);

	return 0;
}

/// <summary>
/// Displays an initial message to the user describing the basic functionality
/// of the program.
/// </summary>
/// <param name=""></param>
void displayInitMsg(void)
{
	cout << "//***********************************//\n"
		<< "//    Program 6 - Divisions Sales    //\n"
		<< "//        Jesus Villarroel           //\n"
		<< "//***********************************//\n\n";

	cout << "This program proccess the sales of each of the divisions\n"
		<< "of the corporation corresponding to each qaurter and summarize\n"
		<< "the data in a table. The user manually ingress the data into\n"
		<< "the program.\n\n";
}

/// <summary>
/// Print a table with the corresponding quater sales for each division.
/// </summary>
/// <param name="ptrDivSales">
/// Pointer to the array of objects (DivSales) containing the data.
/// </param>
void printSalesData(DivSales* ptrDivSales)
{
	cout << setw(12) << left << "Division" << "|";
	cout << setw(12) << left << "   Q1 ($)   " << "|";
	cout << setw(12) << left << "   Q2 ($)   " << "|";
	cout << setw(12) << left << "   Q3 ($)   " << "|";
	cout << setw(12) << left << "   Q4 ($)   " << "|";
	cout << setw(12) << left << " Total($)/Div" << "\n";

	cout << setprecision(2) << showpoint << fixed;

	for (int i = 0; i < N_DIVISIONS; i++)
	{
		cout << left << "Div # " << setw(6) << left << (i + 1) << "|";

		for (int j = 0; j < 4; j++)
		{
			cout << setw(12) << right << (ptrDivSales + i)->getQuaterSales(j) << "|";
		}
		cout << setw(12) << right << (ptrDivSales + i)->getDivSales();
		cout << endl;
	}

	cout << "\nTotal Corporate Sales: $" << ptrDivSales->getCorpSales() << "\n\n";
}
