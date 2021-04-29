#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Declare dynamic stack template class.
template<class T>
class DynamicTypeStack
{
private:
	// Structure for the stack nodes.
	struct StackNode
	{
		T value;			// Value in the node.
		StackNode* next;	// Points to the next node in the stack.
	};

	// Pointer to the top of the stack.
	StackNode* top;

public:
	// Contructor
	DynamicTypeStack();

	// Destructor
	~DynamicTypeStack();

	// Stack Operations
	void push(T);
	void pop(T&);
	bool isEmpty(void);
};

// Function prototypes.
void getStackSize(int&);

int main()
{
	int stackSize = 0;
	string item;
	

	// Create dynamic stack.
	DynamicTypeStack<string>	dynamicStack;

	// Initial message.
	cout << "This is a test program to verify the behavior of a dynamic stack template class.\n\n";

	// Get size of the stack from user.
	getStackSize(stackSize);

	// Enter the items into the stack.
	cout << "\n// ************** Insert the values into the stack. Values are string type. **************** //\n\n";
	for (int i = 0; i < stackSize; i++)
	{
		cout << "Enter value " << (i + 1) << ": ";
		getline(cin, item);
		dynamicStack.push(item);

		cout << item << " -> Addedto the stack.\n\n";
	}

	// Remove items from the stack.
	cout << "\n// ************** Removing items from the stack *************** //\n\n";
	while (!dynamicStack.isEmpty())
	{
		dynamicStack.pop(item);

		cout << item << " was removed from the stack.\n";
	}

	cout << "\n// ************* Ending test program ****************** //\n";

	return 0;
}

/// <summary>
/// Initialize the top of the stack as null since the stack is empty.
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
DynamicTypeStack<T>::DynamicTypeStack()
{
	// As the stack is empty, top is null.
	top = nullptr;
}

/// <summary>
/// Free the memory allocated for the stack.
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
DynamicTypeStack<T>::~DynamicTypeStack()
{
	StackNode* currentNode = nullptr;
	StackNode* nextNode = nullptr;

	// Initialize the node at the top of the stack.
	currentNode = top;

	// Traverse the stack to delete elements.
	while (currentNode != nullptr)
	{
		nextNode = currentNode->next;
		delete currentNode;
		currentNode = nextNode;
	}
}

/// <summary>
/// This methos add a new node element to the top of the stack.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="_value">Value to be added.</param>
template<class T>
void DynamicTypeStack<T>::push(T _value)
{
	StackNode* newNode = nullptr;

	// Allocate new node and save the value passed in it.
	newNode = new StackNode;
	newNode->value = _value;

	// Check is the list is empty to determine where to store the new node.
	if (isEmpty())
	{
		top = newNode;
		newNode->next = nullptr;
	}
	else
	{
		// Make the new node point to the existing node (position it on top of it).
		newNode->next = top;
		top = newNode;
	}
}

template<class T>
void DynamicTypeStack<T>::pop(T& _value)
{
	StackNode* tempNode;		// Temporary node to store next value before deleting current.

	// Check if stack is empty before trying to remove.
	if (isEmpty())
		cout << "Stack is empty. Nothing to remove.\n";
	else
	{
		// Stores value to be removed.
		_value = top->value;
		tempNode = top->next;
		delete top;
		top = tempNode;
	}
}

/// <summary>
/// Check if the stack is empty.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name=""></param>
/// <returns>True if stack is empty, false otherwise.</returns>
template<class T>
bool DynamicTypeStack<T>::isEmpty(void)
{
	return !top;
}

/// <summary>
/// Get the stack size from user.
/// </summary>
/// <param name="_size">Size of the stack.</param>
void getStackSize(int &_size)
{
	cout << "Please, enter the size of the stack: ";
	cin >> _size;
	cin.ignore(100, '\n');

	while (_size <= 0)
	{
		cout << "Please, enter the size of the stack: (greater or equal to one)";
		cin >> _size;
		cin.ignore(100, '\n');
	}

	cout << '\n';
}