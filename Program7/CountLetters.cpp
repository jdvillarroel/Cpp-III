#include "CountLetters.h"


CountLetters::CountLetters()
{
	// Initialize array. This array will contain the number of times a letter
	// appears in the text file. The index of the array represents the ASCII
	// code of a particular letter.
	for (int i = 0; i < 128; i++) {
		lettersCount[i] = 0;
	}

	totalLetters = 0;
}

CountLetters::~CountLetters()
{
	cout << "\n\nDestructor called.\n\n";
}

/// <summary>
/// This function gets the file name and count the number of times each letter of the
/// alphabet appears in the file. It counts separately uppercase and lowercase letters.
/// </summary>
/// <param name="_inFile">Input file object to open.</param>
/// <param name="_inFileName">File name specified by the user.</param>
void CountLetters::getLetters(ifstream& _inFile, char* _inFileName)
{
	char	letter;
	int		letterIndex = 0;
	

	// Get file name to open.
	cout << "Enter file name you would like to open: ";
	cin.getline(_inFileName, fileNameLength);

	// Attempt to open file provided.
	_inFile.open(_inFileName);

	while (_inFile.fail())
	{
		cout << "Error opening " << _inFileName << ". Please, ckech name and try again.\n\n";

		// Get file name to open.
		cout << "Enter file name you would like to open: ";
		cin.getline(_inFileName, fileNameLength);

		// Attempt to open file provided.
		_inFile.open(_inFileName);
	}

	// Get characters from file and count everytime a characters appear in the file.
	while (_inFile.get(letter))
	{
		letterIndex = int(letter);

		// Check that ASCII code of the character read is inside the bounds of the array.
		if (letterIndex < 128)
		{
			// Increment count for corresponding index.
			incrementCount(letterIndex);

			// Count total letters in file.
			updateTotal();
		}
	}

	cout << endl;

	// Close file before ending program.
	_inFile.close();
}

/// <summary>
/// Increment count for the specific letter in the array.
/// </summary>
/// <param name="_letterIndex">Index of the letter to update count.</param>
void CountLetters::incrementCount(int _letterIndex)
{
	lettersCount[_letterIndex]++;
}

/// <summary>
/// Count the total letters in the file.
/// </summary>
/// <param name=""></param>
void CountLetters::updateTotal(void)
{
	totalLetters++;
}

/// <summary>
/// This function prints the report of the letter count obtained from the file.
/// </summary>
/// <param name="_report">File to output the report.</param>
void CountLetters::printReport(ofstream& _report)
{
	char	ch = 'A';

	// Open output file.
	_report.open("report.txt");

	cout << "// ************************************************* //\n"
		<< "//              LETTER COUNT REPORT                  //\n"
		<< "// ************************************************* //\n\n";

	// Header output to the console.
	cout << setw(8) << left << "Letter" << "| "
		<< setw(17) << left << "Uppercase Count" << "| "
		<< setw(17) << left << "Percentage (%)" << "| "
		<< setw(17) << left << "Lowercase Count" << "| "
		<< setw(17) << left << "Percentage(%)" << "| "
		<< setw(7) << left << "Total" << "| "
		<< setw(17) << left << "Percentage (%)" << "\n";

	// Print separator line to the console.
	for (int i = 0; i < 112; i++)
	{
		cout << "-";
	}
	cout << endl;

	_report << "// ************************************************* //\n"
		<< "//              LETTER COUNT REPORT                  //\n"
		<< "// ************************************************* //\n\n";

	// Header output to the file.
	_report << setw(8) << left << "Letter" << "| "
		<< setw(17) << left << "Uppercase Count" << "| "
		<< setw(17) << left << "Percentage (%)" << "| "
		<< setw(17) << left << "Lowercase Count" << "| "
		<< setw(17) << left << "Percentage(%)" << "| "
		<< setw(8) << left << "Total" << "| "
		<< setw(17) << left << "Percentage (%)" << "\n";

	// Print separator line to the file.
	for (int i = 0; i < 112; i++)
	{
		_report << "-";
	}
	_report << endl;

	// Cycle through all the letters in the alphabet and print the count and percentage
	// for each letter (lowercase and uppercase).
	for (int index = 65; index <= 90; index++)
	{
		int lowercase = getLetterCount(index + 32);
		int uppercase = getLetterCount(index);

		// Print the statistics for the letters count.
		cout << setw(7) << left << (ch = index) << " | "
			<< setw(16) << right << uppercase << " | "
			<< setw(16) << right << setprecision(2) << showpoint << fixed << static_cast<double>(uppercase) * 100 / totalLetters << " | "
			<< setw(16) << right << lowercase << " | "
			<< setw(16) << right << setprecision(2) << showpoint << fixed << static_cast<double>(lowercase) * 100 / totalLetters << " | "
			<< setw(6) << right << (lowercase + uppercase) << " | "
			<< setw(16) << right << static_cast<double>((lowercase + uppercase)) * 100 / totalLetters << "\n";

		// Print separator line to the console.
		for (int i = 0; i < 112; i++)
		{
			cout << "-";
		}
		cout << endl;

		// Print the statistics for the letters count.
		_report << setw(7) << left << (ch = index) << " | "
			<< setw(16) << right << uppercase << " | "
			<< setw(16) << right << setprecision(2) << showpoint << fixed << static_cast<double>(uppercase) * 100 / totalLetters << " | "
			<< setw(16) << right << lowercase << " | "
			<< setw(16) << right << setprecision(2) << showpoint << fixed << static_cast<double>(lowercase) * 100 / totalLetters << " | "
			<< setw(6) << right << (lowercase + uppercase) << " | "
			<< setw(16) << right << static_cast<double>((lowercase + uppercase)) * 100 / totalLetters << "\n";

		// Print separator line to the console.
		for (int i = 0; i < 112; i++)
		{
			_report << "-";
		}
		_report << endl;
	}


	_report.close();
}

/// <summary>
/// Return the letter count obtained from the file.
/// </summary>
/// <param name="_index">Index in the array of the letter count to fetch</param>
/// <returns>Letter count.</returns>
int CountLetters::getLetterCount(int _index)
{
	return lettersCount[_index];
}