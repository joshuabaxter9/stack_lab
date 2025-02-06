/* This dynamic array class implements the Stack interface
 * using a dynamically resized array.
 *
 * The array will be resized when it either reaches 80% of its capacity
 * (and then the size will double) or goes below 25% (and then the size will
 * halve, with a minimum size set by a constant in the cpp file.)
 */
#ifndef DYNARRAY_H
#define DYNARRAY_H

#include "stack.h"

class DynamicArray : public Stack
{
public:
	DynamicArray();							 // default constructor
	DynamicArray(const DynamicArray &other); // copy constructor
	~DynamicArray();						 // destructor

	// ~~~~~ INHERITED VIRTUAL FUNCTIONS ~~~~~
	// we have to actually implement these

	int NumElements() { return size; } // Return the number of elements

	bool push(int val); // Inserts value at the top and return false if fails

	int pop(); // removes and returns value at the top

	bool exists(int val); // returns true if val == top of stack :: false else

	int top(); // returns but does NOT remove top val

	// and we'll inherit NumElements from our parent, unchanged

private:
	// Helper functions that shouldn't be part of public interface
	bool Resize(bool);

	// we're inheriting int size, and we need to add...
	int capacity; // the current array capacity in memory
	int *array;	  // pointer for the array itself
};

#endif
