/* Stack abstract class for CS 315 Lab 3 (originally written by Suzanne Rivoire)
 * This data structure only stores integer values.
 *
 * This is an **abstract** class because it contains one or more
 * **pure virtual functions** -- functions whose implementations are just
 * "= 0; ".
 * This means you can't directly instantiate objects of this class.
 *
 * So why does it exist??? So that it can be used as a parent class for
 * child classes that will take this interface in different directions.
 * Those child classes need to, like, actually define these functions, and then
 * you can instantiate those.
 *
 * You CAN create a pointer to an abstract class. But the object it points to
 * needs to be one of the subclasses that you can actually instantiate.
 *
 * To be maximally useful, it would be a template class so you can store
 * objects of arbitrary data type (hence the "Template" in "Standard
 * TEMPLATE Library")
 */

/* The first 2 lines and last 1 line of source code are the header guards
 * that keep this file from being included twice in the same .o file.
 */
#ifndef STACK_H
#define STACK_H

#include <iostream>
using std::cerr;

class Stack
{
public:
  // Your usual constructors and destructor -- these
  // are called implicitly when objects are created or destroyed
  Stack() : size(0) {}
  virtual ~Stack() {}; // empty - no dynamically allocated memory

  int NumElements() { return size; } // Return the number of elements

  virtual bool push(int val) = 0; // Inserts value at the top and return false if fails

  virtual int pop() = 0; // removes and returns value at the top

  virtual bool exists(int val) = 0; // returns true if val == top of stack :: false else

  virtual int top() = 0; // returns but does NOT remove top val

protected:
  // all other private data will be specific to subclasses
  int size;
};

#endif
