#include "linkedlist.h"

LinkedList::LinkedList()
{
    // runs LinearList constructor, which sets size to 0
    head = nullptr;
}

LinkedList::~LinkedList()
{
    LLNode *current = head;
    LLNode *previous;
    while (current != nullptr)
    {
        LLNode *previous = current;
        current = current->next;
        delete previous;
    }
}

/**
 * Function to push value onto stack
 *
 * @param   value    integer being pushed onto stack
 * @pre value is any integer
 * @returns  returns true if successful
 **/

bool LinkedList::push(int value)
{
    // Create the new Node.
    LLNode *newNode = new LLNode(value);
    if (newNode == nullptr)
        return false;

    // Assign to head
    if (head != nullptr)
    {
        newNode->next = head;
    }
    head = newNode;
    size++;
    return true;
}

/**
 * Function to pop value off stack
 *
 * @param   none
 * @pre valid stack
 * @returns  returns the top value and removes from stack
 **/
int LinkedList::pop()
{
    // check if stack is empty
    if (head == nullptr)
    {
        cerr << "Can’t remove from an empty list\n";
        exit(1); // nonzero exit codes indicate error
    }
    // allocated temp ptr
    LLNode *doomedPtr = head;
    // get the val of the top elem
    int val = head->val;
    // move head to the next val
    head = head->next;
    // delete the memory allocated to the value being popped
    delete doomedPtr;
    // decrement size
    size--;
    // return popped val
    return val;
}

/**
 * Function to check if value is at top of stack
 *
 * @param   num    integer to check if it exists in stack
 * @pre num is an integer that exists or doesnt at top of stack
 * @returns  returns true if num is found at top of stack
 **/
bool LinkedList::exists(int num)
{
    // check if the top val equals the num
    if (head->val == num)
    {
        return true;
    }
    // else return false
    else
        return false;
}

/**
 * Function that returns value at top of stack
 *
 * @param  none
 * @pre exists a valid stack
 * @returns  returns top value if successful
 **/
int LinkedList::top()
{
    // check if it is a valid stack with elems
    if (size == 0 || head == nullptr)
    {
        cerr << "Can’t return top element from an empty list\n";
        exit(1); // nonzero exit codes indicate error
    }
    // return the top element
    return head->val;
}