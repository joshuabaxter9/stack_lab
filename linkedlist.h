/* This linked list class implements the Stack interface.
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "stack.h"

class LinkedList : public Stack
{
public:
	LinkedList(); // default constructor
	LinkedList(const LinkedList &other) {}
	~LinkedList(); // destructor

	// ~~~~~ INHERITED VIRTUAL FUNCTIONS ~~~~~
	// we have to actually implement these

	int NumElements() { return size; } // Return the number of elements

	bool push(int val); // Inserts value at the top and return false if fails

	int pop(); // removes and returns value at the top

	bool exists(int val); // returns true if val == top of stack :: false else

	int top(); // returns but does NOT remove top val
			   // and we'll inherit NumElements from our parent, unchanged
private:
	// we're inheriting int size, and we need to add...
	class LLNode
	{
	public:
		int val;
		LLNode *next;

		// Default and parameterized constructors
		LLNode()
		{
			val = 0;
			next = nullptr;
		}
		LLNode(int data)
		{
			val = data;
			next = nullptr;
		}
	};
	LLNode *head;
};

#endif
