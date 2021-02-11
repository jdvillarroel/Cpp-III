//Name :
//Date:
//Problem statement:  This is a review for COSC1436, we use a multidimensional array to save grades for students (grade.txt), and a one
//dimension array of type string to save student''s f and last name.
// we use functions to read data, and store them to those two arrays.
// we use a function to find sum of grades for each students and save it a one dimensional array of type integer
//we write a function to find average of grades for each students and save it a one dimensional array of type double
//we write a function to find letter grade for each student and save it a one dimensional array of type character
//We write a function to display all datas as follow
//    Student's name       Grades             Total   Average    Letter grade
// Marisa Tobbi    100  100 100 100 100 100    600     100             A
//   ......
//   ......
//   ......
// You need to use output manipulation to have proper spacing for display
//Then we write a function using  bubble sort to sort students name, and one more sort to sort students grade
//Then display original data , and two sorting algorithm in a file (Result.txt)

//Preprocessor directive
//global variables
//function prototypes
//main program
//functions definitions

#include <iostream> // Preprocessors directive
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int NUM_OF_STUDENTS = 7; // Global Variable
const int NUM_OF_SCORES = 6;

ifstream namesFile, scoresFile;
ofstream outputFile;

// Structure definition.
struct Student
{
	string		name;
	int			scores[NUM_OF_SCORES];
	int			scoresTotal = 0;
	double		scoreAvg = 0.0;
	char		grade = ' ';
};

// Functions prototype
void readData(Student _students[NUM_OF_STUDENTS]);
void scoresAvg(Student _students[NUM_OF_STUDENTS]);
void calcGrade(Student _students[NUM_OF_STUDENTS]);
void displayData(Student _students[NUM_OF_STUDENTS]);
void saveToFile(Student _students[NUM_OF_STUDENTS], ofstream&);

//void copyStruct(Student[], Student[]);

// Sorting algorithms.
void bubbleSort(Student _students[NUM_OF_STUDENTS]);
void selectionSort(Student _students[NUM_OF_STUDENTS]);
void insertionSort(Student _students[NUM_OF_STUDENTS]);

template <class T>
void swap(T* var1, T* var2);

int main()
{
	Student		students[NUM_OF_STUDENTS];
	Student		listSortedByName[NUM_OF_STUDENTS];

	outputFile.open("Result.txt");

	readData(students);
	scoresAvg(students);
	calcGrade(students);
	displayData(students);
	saveToFile(students, outputFile);

	// Copy entire structure to avoid modifying raw data structure.
	// copyStruct(students, listSortedByName);

	// Sort structure using bubble sort algorithm and disply results.
	cout << endl << "******************** Results using Bubble Sort Algorithm **********************" << endl << endl;
	outputFile << endl << "******************** Results using Bubble Sort Algorithm **********************" << endl << endl;
	bubbleSort(students);
	displayData(students);
	saveToFile(students, outputFile);

	// Sort structure using selection sort algorithm and disply results.
	cout << endl << "******************** Results using Selection Sort Algorithm *******************" << endl << endl;
	outputFile << endl << "******************** Results using Selection Sort Algorithm *******************" << endl << endl;
	selectionSort(students);
	displayData(students);
	saveToFile(students, outputFile);

	// Sort structure using selection sort algorithm and disply results.
	cout << endl << "******************** Results using Insertion Sort Algorithm *******************" << endl << endl;
	outputFile << endl << "******************** Results using Insertion Sort Algorithm *******************" << endl << endl;
	insertionSort(students);
	displayData(students);
	saveToFile(students, outputFile);


	outputFile.close();
	return 0;
}

void readData(Student _students[NUM_OF_STUDENTS])
{
	namesFile.open("name.txt");
	scoresFile.open("grade.txt");

	// Get students names from file.
	for (int i = 0; i < NUM_OF_STUDENTS; i++)
	{
		getline(namesFile, _students[i].name);
	}

	// Get students scores from file.
	for (int i = 0; i < NUM_OF_STUDENTS; i++)
	{
		for (int j = 0; j < NUM_OF_SCORES; j++)
		{
			scoresFile >> _students[i].scores[j];
		}
	}

	namesFile.close();
	scoresFile.close();

	// For debugging
	//for (int i = 0; i < NUM_OF_STUDENTS; i++)
	//{
	//	cout << "Students name: " << _students[i].name;
	//	cout << " Scores: ";
	//	
	//	for (int j = 0; j < NUM_OF_SCORES; j++)
	//	{
	//		cout << _students[i].scores[j] << " ";
	//	}
	//	cout << endl;
	//}

}


void scoresAvg(Student _students[NUM_OF_STUDENTS])
{
	// Calculate the average score for each student.
	for (int i = 0; i < NUM_OF_STUDENTS; i++)
	{
		for (int j = 0; j < NUM_OF_SCORES; j++)
		{
			_students[i].scoresTotal += _students[i].scores[j];
		}
		// Divide the total by the number of test scores to get the average.
		_students[i].scoreAvg = _students[i].scoresTotal / static_cast<double>(NUM_OF_SCORES);
	}

	// For debugging
	//for (int i = 0; i < NUM_OF_STUDENTS; i++)
	//{
	//	cout << "Avg Score: " << _students[i].scoreAvg << endl;
	//}
}

void calcGrade(Student _students[NUM_OF_STUDENTS])
{
	for (int i = 0; i < NUM_OF_STUDENTS; i++)
	{
		if (_students[i].scoreAvg >= 89.5)
		{
			_students[i].grade = 'A';
		}
		else if (_students[i].scoreAvg >= 79.5)
		{
			_students[i].grade = 'B';
		}
		else if (_students[i].scoreAvg >= 69.5)
		{
			_students[i].grade = 'C';
		}
		else if (_students[i].scoreAvg >= 59.5)
		{
			_students[i].grade = 'D';
		}
		else
		{
			_students[i].grade = 'F';
		}
	}

	// For debugging
	//for (int i = 0; i < NUM_OF_STUDENTS; i++)
	//{
	//	cout << "Grades: " << _students[i].grade << endl;
	//}
}

void displayData(Student _students[NUM_OF_STUDENTS])
{
	cout << setw(20) << left << "Student Name";
	cout << setw(36) << left << "           Scores";
	cout << setw(9) << left << "Total";
	cout << setw(9) << left << "Avg";
	cout << setw(6) << left << "Grade";
	cout << endl << "-------------------------------------------------------------------------------" << endl;


	for (int i = 0; i < NUM_OF_STUDENTS; i++)
	{
		cout << setw(20) << left << _students[i].name;

		for (int j = 0; j < NUM_OF_SCORES; j++)
		{
			cout << setw(6) << left << _students[i].scores[j];
		}

		cout << setw(9) << left << _students[i].scoresTotal;
		cout << setw(9) << left << fixed <<
			showpoint << setprecision(2) << _students[i].scoreAvg;
		cout << setw(4) << left << "  " << _students[i].grade;

		cout << endl;
	}
}

void saveToFile(Student _students[NUM_OF_STUDENTS], ofstream &outputFile)
{
	outputFile << setw(20) << left << "Student Name";
	outputFile << setw(36) << left << "           Scores";
	outputFile << setw(9) << left << "Total";
	outputFile << setw(9) << left << "Avg";
	outputFile << setw(6) << left << "Grade";
	outputFile << endl << "-------------------------------------------------------------------------------" << endl;


	for (int i = 0; i < NUM_OF_STUDENTS; i++)
	{
		outputFile << setw(20) << left << _students[i].name;

		for (int j = 0; j < NUM_OF_SCORES; j++)
		{
			outputFile << setw(6) << left << _students[i].scores[j];
		}

		outputFile << setw(9) << left << _students[i].scoresTotal;
		outputFile << setw(9) << left << fixed <<
			showpoint << setprecision(2) << _students[i].scoreAvg;
		outputFile << setw(4) << left << "  " << _students[i].grade;

		outputFile << endl;
	}
}

/// <summary>
/// It sorts the array structure by name in ascending order. It uses bubble sort algorithm.
/// </summary>
/// <param name="_students"></param>
void bubbleSort(Student _students[NUM_OF_STUDENTS])
{
	bool sorted = false;
	int size = NUM_OF_STUDENTS;

	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i < size - 1; i++)
		{
			if (_students[i].name > _students[i + 1].name)
			{
				swap(_students[i].name, _students[i + 1].name);

				// Swap the rest of the values that correspond to the same student.
				swap(_students[i].grade, _students[i + 1].grade);
				swap(_students[i].scoreAvg, _students[i + 1].scoreAvg);
				swap(_students[i].scoresTotal, _students[i + 1].scoresTotal);

				// Scan the data to swap them to the new position in the array.
				for (int j = 0; j < NUM_OF_SCORES; j++)
				{
					swap(_students[i].scores[j], _students[i + 1].scores[j]);
				}
				sorted = false;
			}
		}
		size--;
	}
}

/// <summary>
/// Selection Sort algorithm to sort the array structure by the sum of all scores
/// in ascending order.
/// </summary>
/// <param name="_students"></param>
void selectionSort(Student _students[NUM_OF_STUDENTS])
{
	int minIndex;

	for (int i = 0; i < NUM_OF_STUDENTS - 1; i++)
	{
		minIndex = i;

		for (int j = i + 1; j < NUM_OF_STUDENTS; j++)
		{
			if (_students[j].scoresTotal < _students[minIndex].scoresTotal)
			{
				// Found new minimum value.
				minIndex = j;
			}
		}

		// Swap the rest of the values that correspond to the same student.
		swap(_students[i].name, _students[minIndex].name);
		swap(_students[i].grade, _students[minIndex].grade);
		swap(_students[i].scoreAvg, _students[minIndex].scoreAvg);
		swap(_students[i].scoresTotal, _students[minIndex].scoresTotal);

		// Scan the data to swap them to the new position in the array.
		for (int k = 0; k < NUM_OF_SCORES; k++)
		{
			swap(_students[i].scores[k], _students[minIndex].scores[k]);
		}
	}
}

/// <summary>
/// It takes the Student structure and sort the structure array by the final grade(letter).
/// It sort them in descending order.
/// </summary>
/// <param name="_students"></param>
void insertionSort(Student _students[NUM_OF_STUDENTS])
{
	char current;

	for (int i = 1; i < NUM_OF_STUDENTS; i++)
	{
		current = _students[i].grade;

		for (int j = i - 1; j >= 0; j--)
		{
			if (_students[j].grade > current)
			{
				_students[j + 1].grade = _students[j].grade;

				// Swap the rest of the values that correspond to the same student.
				swap(_students[j + 1].name, _students[j].name);
				swap(_students[j + 1].scoreAvg, _students[j].scoreAvg);
				swap(_students[j + 1].scoresTotal, _students[j].scoresTotal);

				// Scan the data to swap them to the new position in the array.
				for (int k = 0; k < NUM_OF_SCORES; k++)
				{
					swap(_students[j + 1].scores[k], _students[j].scores[k]);
				}
				_students[j].grade = current;
			}
		}
	}
}

/// <summary>
/// Function template used to swap different data types inside the Student structure.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="var1"></param>
/// <param name="var2"></param>
template<class T>
void swap(T* var1, T* var2)
{
	T temp;
	temp = *var1;
	*var1 = *var2;
	*var2 = temp;
}


//void copyStruct(Student from[], Student to[])
//{
//	for (int i = 0; i < NUM_OF_STUDENTS; i++)
//	{
//		to[i].grade = from[i].grade;
//		to[i].name = from[i].name;
//		to[i].scoreAvg = from[i].scoreAvg;
//		to[i].scoresTotal = from[i].scoresTotal;
//
//		for (int j = 0; j < NUM_OF_STUDENTS; j++)
//		{
//			to[i].scores[j] = from[i].scores[j];
//		}
//	}
//}