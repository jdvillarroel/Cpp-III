/*
* Program 8 - Analysis of Sorting Algorithms
* COSC2436
* Spring 2021
* Jesus Villarroel
*/

/*
Analysis of Sorting Algorithms

Design a class AbstractSort that can be used to analyze the number of comparisons performed by a sorting algorithm.
The class should have a member function compare that is capable of comparing two array elements, and a means of
keeping track of the number of comparisons performed. The class should be an abstract class with a pure virtual
member function

void sort(int arr[ ], int size)

which, when overridden, will sort the array by calling the compare function to determine the relative order of
pairs of numbers. Create a subclass of AbstractSort that uses a simple sorting algorithm to implement the sort
function. The class should have a member function that can be called after the sorting is done to retrieve the
number of comparisons performed.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Base class to analyze sorting algorithm.
class AbstractSort
{
public:
	// Constructor
	AbstractSort();

	// Destructor
	~AbstractSort();

	// Member functions
	bool compare(int, int);
	virtual void sort(int arr[], int size);
	int getCompCounter(void);

protected:
	int		compCounter;

};

// ***************** Sorting algorithm ****************** //
class BubbleSort : public AbstractSort
{
public:
	void sort(int arr[], int size);
	void swap(int arr[], int index1, int index2);
};



int main()
{
	BubbleSort	bubbleSort;
	const int	SIZE = 11;
	int			testArray[SIZE] = {34, 12, 79, 91, 256, 20, 20, 23, 36, 56, 4};

	// Print test array.
	cout << "Test array: [ ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << testArray[i] << " ";
	}
	cout << "]" << endl << endl;

	// Sort array.
	bubbleSort.sort(testArray, SIZE);

	// Print sorted array.
	cout << "Sorted array: [ ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << testArray[i] << " ";
	}
	cout << "]" << endl << endl;

	// Number of comparisons.
	cout << "The number of comparisons made was: " << bubbleSort.getCompCounter() << endl << endl;

	return 0;
}

AbstractSort::AbstractSort()
{
	compCounter = 0;
}

AbstractSort::~AbstractSort()
{
}

/// <summary>
/// Compare two integer values. It compares if element e1 > e2. It updates
/// the counter of the number os comparisons made.
/// </summary>
/// <param name="e1">First integer value.</param>
/// <param name="e2">Second integer value.</param>
/// <returns>true if e1 > e2, false otherwise.</returns>
bool AbstractSort::compare(int e1, int e2)
{
	compCounter++;

	return (e1 > e2);
}

/// <summary>
/// Get number of comparisons made the algorithm.
/// </summary>
/// <param name=""></param>
/// <returns>Number of comparisons.</returns>
int AbstractSort::getCompCounter(void)
{
	return compCounter;
}

/// <summary>
/// Function not implemented in base class. It must be overriden by derived class.
/// </summary>
/// <param name="arr"></param>
/// <param name="size"></param>
void AbstractSort::sort(int arr[], int size)
{
	// Not implemented. It must be overriden by derived class.
}

/// <summary>
/// Bubble sort algorithm. It sorts the array in ascending order.
/// </summary>
/// <param name="arr">Array to be sorted.</param>
/// <param name="size">Size of the array.</param>
void BubbleSort::sort(int arr[], int size)
{
	bool isSorted = false;
	int endIndex = size - 1;

	while (!isSorted)
	{
		isSorted = true;
		for (int index = 0; index < endIndex; index++)
		{
			if (compare(arr[index], arr[index  + 1]))
			{
				swap(arr, index, index + 1);
				isSorted = false;
			}
		}
		endIndex--;
	}
}

/// <summary>
/// This function swaps two elements of the array.
/// </summary>
/// <param name="arr">Array containing the elements to swap.</param>
/// <param name="index1">First element to swap.</param>
/// <param name="index2">Second element to swap.</param>
void BubbleSort::swap(int arr[], int index1, int index2)
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}