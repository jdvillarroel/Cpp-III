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

const int row = 6; // Global Variable
const int col = 6;

ifstream inputName, inputGrade;
ofstream output;

//Functions prototype
void readData(string stname[row], int stgrade[row][col]);
void sum(int stGrade[row][col], int totalG[row]);
// void average(int totalg[row], double staverage[row]);
// void letterGrade(double staverage[row], char stletter[row]);
void display(string stName[row], int stGrade[row][col], int totalG[row], double stAverage[row], char stLetter[row]);

int main()
{
	string	names[row] = {};
	int		scores[row][col] = { {0},{0} };
	int		scoresSum[row] = {0};
	char	grades[row] = {};

	readData(names, scores);
	sum(scores, scoresSum);

	//display(names, scores, 0, 0, grades);


	return 0;
}
//=========================== Read Function ==============================
void readData(string stname[row], int stgrade[row][col])
{
	inputName.open("name.txt");
	inputGrade.open("grade.txt");

	for (int r = 0; r < row; r++) //Read names form file
		getline(inputName, stname[r]);

	for (int r = 0; r < row; r++) // Read grades from file
		for (int c = 0; c < col; c++)
			inputGrade >> stgrade[r][c];

	inputName.close();
	inputGrade.close();
}
//================================= Calculate sum ===========
void sum(int stGrade[row][col], int totalG[row])
{
	// Calculate the sum of the scores of each student.
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			totalG[r] += stGrade[r][c];
		}
	}

	// Just for debugging
	for (int i = 0; i < row; i++) {
		cout << totalG[i] << endl;
	}
}

//================================= Calculate average ===========


//================================= Calculate letter grade ===========


//================================= display result ===========

void display(string stName[row], int stGrade[row][col], int totalG[row], double stAverage[row], char stLetter[row])
{
	for (int r = 0; r < row; r++) {
		cout << stName[r] << endl;
	}

	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			cout << stGrade[r][c] << " ";
		}
		cout << endl;
	}
}