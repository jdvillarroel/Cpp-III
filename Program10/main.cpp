/*
* Program 10 - Linked List
* COSC2436
* Spring 2021
* Jesus Villarroel
*/

/*

    1. Using an appropriate definition of ListNode, design a simple linked list class with only two member functions and a default constructor:

    void add(double x);

    boolean isMember(double x);

    LinkedList( );

    The add function adds a new node containing x to the front (head) of the list, while the isMember function tests to see if the list contains
    a node with the value x. Test your linked list class by adding various numbers to the list and then testing for membership.

    List Copy Constructor Modify your list class of Previous Programming to add a copy constructor. Test your class by making a copy of a list
    and then testing membership on the copy.
    List Print Modify the list class you created in the previous programming challenges to add a print member function. Test the class by
    starting with an empty list, adding some elements, and then printing the resulting list out.
    Recursive Member Check Modify the list class you created in the previous programming challenges to use a recursive method to check for list
    membership. Test your class.
    List Member Deletion Modify the list class you created in the previous programming challenges by adding a function to remove an item from
    the list and by adding a destructor:

    void remove(double x);

    ~LinkedList();

    Test the class by adding a sequence of instructions that mixes operations for adding items, removing items, and printing the list.

    List Reverse Modify the list class you created in the previous programming challenges by adding a member function for reversing the list:

    void reverse();

    The member function rearranges the nodes in the list so that their order is reversed. You should do this without creating or destroying nodes.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Linked List class.
class DoubleList
{
private:
    // Declare node structure.
    struct ListNode
    {
        double              value;
        ListNode*    next;
    };

    // Head of the linked list.
    ListNode*       head;

public:
    // Constructor
    DoubleList();

    // Destructore
    ~DoubleList();

    // Linked list operations
    void add(double);
    bool isMember(double);
    void print(void);
    void remove(double);
    ListNode* reverse(ListNode*);
    ListNode* getHead(void);
    void setHead(ListNode*);
};

int main()
{
    DoubleList numberList;
    char       repeat;
    char       wantRemove;
    double     number;
    
    // Add test values to the linked list.
    numberList.add(2.2);
    numberList.add(7.25);
    numberList.add(0.31);
    numberList.add(742.948);
    numberList.add(1.78);
    numberList.add(20.36);
    
    // Display list to confirm added values are in the correct order.
    numberList.print();

    // Remove item from list.
    cout << "\n// ********************** Remove node from the list. *********************** //\n\n";

    cout << "Would you like to remove an item from list? (y/n): ";
    cin >> wantRemove;
    cin.ignore(100, '\n');

    if (wantRemove == 'y' || wantRemove == 'Y')
    {
        do
        {
            // Propmt user to enter number he/she would like to check.
            cout << "Enter the number you want to remove: ";
            cin >> number;
            cin.ignore(100, '\n');
            cout << "\n";

            // Remove node
            numberList.remove(number);

            numberList.print();

            cout << "\n// ********************************************************************* //\n";

            // Ask user if he/she wants to continue.
            cout << "\nWould you like to enter a new number? (y/n): ";
            cin >> repeat;
            cin.ignore(100, '\n');
            cout << "\n";
        } while (repeat == 'y' || repeat == 'Y');
    }

    // Reversing the list.
    cout << "\n// *********** Reversing the linked list ************** //\n\n";
    numberList.reverse(numberList.getHead());

    // Print reversed list.
    numberList.print();
    

	return 0;
}

/// <summary>
/// Default constructor. Initialize head of the list as null pointer (empty list).
/// </summary>
DoubleList::DoubleList()
{
    head = nullptr;
}

/// <summary>
/// Destructor. Free the memory used to allocate the linked list.
/// </summary>
DoubleList::~DoubleList()
{
    ListNode* nodePtr;      // To traverse the list
    ListNode* nextNode;     // To point to next node

    // Position the pointer at the head of the list.
    nodePtr = head;

    while (nodePtr != nullptr)
    {
        // Next node points to the next node, so the current can be deleted.
        nextNode = nodePtr->next;

        // Delete current node.
        delete nodePtr;

        // Set next node.
        nodePtr = nextNode;
    }
}

/// <summary>
/// This function adds a new node to the front of the list.
/// </summary>
/// <param name="_value">Value to be added.</param>
void DoubleList::add(double _value)
{
    ListNode* newNode;          // Pointer to a new node.
    //ListNode* tempPtr;          // Temporal pointer to store list head.

    //tempPtr = head;

    // Allocate new node and store the value.
    newNode = new ListNode;
    newNode->value = _value;
    newNode->next = head;

    // Head points to new node inserted.
    head = newNode;

}

/// <summary>
/// Display the linked list.
/// </summary>
/// <param name=""></param>
void DoubleList::print(void)
{
    ListNode* nodePtr;

    nodePtr = head;

    cout << "Linked list => ";

    // Traverse the list.
    while (nodePtr)
    {
        cout << nodePtr->value << "  ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}

/// <summary>
/// Checks if a value belongs to the linked list.
/// </summary>
/// <param name="_value">Value to be checked.</param>
/// <returns>True if value is member of the list, false otherwise.</returns>
bool DoubleList::isMember(double _value)
{
    ListNode* nodePtr;

    // Initialize pointer to the beggining of the list.
    nodePtr = head;

    // Traverse the list.
    while (nodePtr)
    {
        // If _value is in the list return true and stop traversing the list.
        if (nodePtr->value == _value)
            return true;

        // Point to next node.
        nodePtr = nodePtr->next;
    }

    // _value is not a member.
    return false;
}

/// <summary>
/// Removes a node from the linked list. If list is empty or the value is not a member
/// the function returns.
/// </summary>
/// <param name="_value">Value to be removed.</param>
void DoubleList::remove(double _value)
{
    ListNode* nodePtr;
    ListNode* prevNode = nullptr;

    // Check if list is empty or the _value is not member of the list.
    // If _value is not member the program do not waste time traversing the list.
    if (!head || !isMember(_value))
    {
        cout << "// **** ATENTION!. List is empty or number is not member of the list. *** //\n\n";
        return;
    }
        

    // Check if first node is the one to delete.
    if (head->value == _value)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        // Initialize node to the head.
        nodePtr = head;

        // Traverse the list looking for the node that contains the value.
        while (nodePtr != nullptr && nodePtr->value != _value)
        {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // Check if nodePtr is not the last node in the list, and assign the next node
        // nodePtr is pointing to to the previous node and delete the current node.
        if (nodePtr)
        {
            prevNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}


/// <summary>
/// This function reverse the list implementing recursion.
/// </summary>
/// <param name="_head"></param>
/// <returns></returns>
DoubleList::ListNode* DoubleList::reverse(ListNode* _head)
{
    // Base case. List is empty or list contains only one node.
    if (_head == nullptr || _head->next == nullptr)
    {
        return _head;
    }

    ListNode* reversedListHead = reverse(_head->next);
    _head->next->next = _head;
    _head->next = nullptr;

    // Set the new head of the linked list.
    head = reversedListHead;
    return reversedListHead;
}

/// <summary>
/// Get head of the linked list.
/// </summary>
/// <param name=""></param>
/// <returns>Head of the linked list.</returns>
DoubleList::ListNode* DoubleList::getHead(void)
{
    return head;
}