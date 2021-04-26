#include "main.h"
#include "CountLetters.h"

// Input/output file objects.
ifstream	inFile;
ofstream	report;

// File name max length.
const int	MAX_LENGTH = 81;

// Function prototypes.
void displayInitMsg(void);

int main()
{
	CountLetters	counter;

	char	inFileName[MAX_LENGTH];
	char*	pFileName = inFileName;

	// Display initial message.
	displayInitMsg();

	// Set the maximum length of the file name in the object.
	counter.fileNameLength = MAX_LENGTH;

	// Get input file name and the letters the file contains.
	counter.getLetters(inFile, pFileName);

	// Display the results in the screen and output file.
	counter.printReport(report);

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
		<< "//     Program 7 - Letters Count     //\n"
		<< "//        Jesus Villarroel           //\n"
		<< "//***********************************//\n\n";

	cout << "This program takes a file name where it will count how often"
		<< "each letter of the alphabet appears in it. The count is made"
		<< "considering uppercase and lowercase letters. Then, a report is"
		<< "printed to the console and to a file.\n\n";
}