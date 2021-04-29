#include <iostream>
#include <iomanip>

using namespace std;

// ********************************************************* //
// *            STATIC TEMPLATE OF THE STACK               * //
// ********************************************************* //

// Define static template stack class.
template <class T>
class StaticTypeStack
{
private:
    T* stackArray;
    int         stackSize;
    int         top;

public:
    // Constructor
    StaticTypeStack(int);

    // Destructor
    ~StaticTypeStack();

    // Stack Operations.
    void push(T);
    void pop(T&);
    bool isFull(void);
    bool isEmpty(void);
};

// ********************************************************* //

const int STACK_SIZE = 7;

int main()
{
	double      poped[STACK_SIZE] = { 0.0 };
	double      add[STACK_SIZE] = {
		12.323,
		2154.124,
		98.0145,
		4.0215,
		0.03258,
		11.112,
		67.3
	};
	int counter = 0;

	// Create a static stack.
	StaticTypeStack<double>     staticStack(7);

	// Demonstrate stack is empty.
	cout << "No element has been added to the stack. Checking that stack is empty...\n\n";

	if (staticStack.isEmpty())
		cout << "Stack is empty.\n\n";
	else
		cout << "Stack is not empty.\n\n";

	// Add elements to the stack.
	cout << "Adding elements to the stack...\n\n";

	for (int index = 0; index < STACK_SIZE; index++)
	{
		staticStack.push(add[index]);

		cout << add[index] << " was added to the stack.\n";
	}
	cout << "\n";

	// Check if stack is full.
	cout << "Checking if stack is full...\n\n";
	if (staticStack.isFull())
		cout << "Stack is full.\n\n";
	else
		cout << "Stack is not full.\n\n";

	// Removing elements from the stack;
	cout << "Removing elements from the stack until empty.\n\n";
	while (!staticStack.isEmpty())
	{
		staticStack.pop(poped[counter]);
		counter++;
	}

	// Display removed items.
	for (int i = 0; i < counter; i++)
	{
		cout << poped[i] << " was removed from the stack.\n";
	}
	cout << "\n";

	cout << "// **************** End of the static stack test program. **************** //\n";


	return 0;
}

// ********************************************************* //
// *            STATIC TEMPLATE OF THE STACK               * //
// ********************************************************* //

/// <summary>
/// Initialize the stack as an empty stack.
/// </summary>
/// <typeparam name="TempStack">Template variable.</typeparam>
/// <param name="_size">Size of the stack.</param>
template<class T>
StaticTypeStack<T>::StaticTypeStack(int _size)
{
	stackArray = new T[_size];
	stackSize = _size;
	top = -1;
}

/// <summary>
/// Free memory allocated for the static stack.
/// </summary>
/// <typeparam name="TempStack"></typeparam>
template<class T>
StaticTypeStack<T>::~StaticTypeStack()
{
	delete[] stackArray;
}


/// <summary>
/// This method add new data to the top of the stack only if it is not
/// already full.
/// </summary>
/// <typeparam name="TempStack"></typeparam>
/// <param name="_value">Value to be added to the stack.</param>
template<class T>
void StaticTypeStack<T>::push(T _value)
{
	// If stack is full do nothing.
	if (isFull())
	{
		cout << "Data cannot be added. Stack if full.\n";
	}
	else
	{
		// Update top of stack.
		top++;

		// Add value at the top of the stack.
		stackArray[top] = _value;
	}
}

/// <summary>
/// This method remove the element at the top of the stack.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="_value">Store the removed element.</param>
template<class T>
void StaticTypeStack<T>::pop(T& _value)
{
	if (isEmpty())
	{
		cout << "Stack is empty. Cannot remove.\n";
	}
	else
	{
		// save element removed from the stack.
		_value = stackArray[top];

		// Update the top of the stack.
		top--;
	}
}


template<class T>
bool StaticTypeStack<T>::isFull(void)
{
	return (top == stackSize - 1);
}


template<class T>
bool StaticTypeStack<T>::isEmpty(void)
{
	return (top == -1);
}

// ********************************************************* //