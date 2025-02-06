/* Implementation of the DynamicArray class
 *
 * The array will be resized when it either reaches 80% of its capacity
 * (and then the size will double) or goes below 25% (and then the size will
 * halve, with a minimum size set by a constant in the cpp file.)
 */
// for exit errors
#include "dynamicarray.h"
const int MIN_CAPACITY = 100;            // never drop capacity below this
const double SIZE_UP_THRESHOLD = 0.8;    // size up when reach 80% of capacity
const double SIZE_DOWN_THRESHOLD = 0.25; // size down when drops to 25%

/* Default constructor:
 * The default constructor for LinearList has already run
 * and initialized size to 1
 * Now need to initialize the private data that is new to
 * DynamicArray
 */
DynamicArray::DynamicArray()
{
    capacity = MIN_CAPACITY;
    array = new int[capacity]; // actually allocate the array
    if (array == nullptr)
    {
        std::cerr << "Couldn't allocate initial array\n";
        exit(1);
    }
}

/* Copy constructor: initialize as copy of other object */
DynamicArray::DynamicArray(const DynamicArray &other)
{
    capacity = other.capacity;
    size = other.size;
    array = new int[capacity];
    if (array == nullptr)
    {
        std::cerr << "Couldn't allocate initial array\n";
        exit(1);
    }
    for (int i = 0; i < size; i++)
    {
        array[i] = other.array[i];
    }
}

/* Destructor: deallocate the dynamically allocated array */
DynamicArray::~DynamicArray() { delete[] array; }

/* Helper function for resizing array
 * True to upsize, false to downsize
 * */
bool DynamicArray::Resize(bool upsize)
{
    if (upsize)
        capacity *= 2;
    else
        capacity /= 2;

    if (capacity < MIN_CAPACITY)
        capacity = MIN_CAPACITY;

    // Allocate new array of desired capacity
    int *newarr = new int[capacity];
    if (newarr == nullptr)
    {
        return false;
    }

    // And copy the elements over
    for (int i = 0; i < size; i++)
    {
        newarr[i] = array[i];
    }
    // Deallocate memory for old array and switch the pointer
    delete[] array;
    array = newarr;
    return true;
}

/**
 * Function to push value onto stack
 *
 * @param   value    integer
 * @returns  returns true if successful
 **/
bool DynamicArray::push(int val)
{
    // resize if going beyond current capacity
    if (size + 1 > capacity * SIZE_UP_THRESHOLD)
    {
        if (!Resize(true))
            return false;
    }
    // increase the size and insert the val
    array[size++] = val;
    return true;
}

/**
 * Function to pop value off stack
 *
 * @returns  returns the top value and removes from stack
 **/
int DynamicArray::pop()
{
    // check if the stack is empty
    if (size == 0)
    {
        cerr << "Can’t remove from an empty list\n";
        exit(1); // nonzero exit codes indicate error
    }
    // store top value in val
    int val = this->array[size - 1];
    // decrement size
    size--;
    // return the val
    return val;
}

/**
 * Function to check if value is in the stack
 *
 * @param   num    integer to check
 * @returns  returns true if num is found in stack
 **/
bool DynamicArray::exists(int val)
{
    // for loop  to iterate through stack
    for (int i = 0; i < size; i++)
    {
        // if it finds the val it returns true
        if (this->array[i] == val)
            return true;
    }
    // else it return false
    return false;
}

/**
 * Function that returns value at top of stack
 *
 * @returns  returns top value if successful
 **/
int DynamicArray::top()
{
    // check if stack is empty
    if (size == 0)
    {
        cerr << "Can’t return top element from an empty list\n";
        exit(1); // nonzero exit codes indicate error
    }
    // return the top element
    return this->array[size - 1];
}