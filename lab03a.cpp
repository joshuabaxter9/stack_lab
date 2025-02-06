/* Driver code to illustrate performance differences between
 * the two implementations of Stack
 */
#include "dynamicarray.h"
#include "linkedlist.h"
#include <iostream>
#include <chrono>
#include <unistd.h>
using namespace std;

// const int SIZE = 10000;
//  const int SIZE = 100;
const int SIZE = 1000000;

void timedTest(Stack *ll);

int main()
{
    /* Creates a dynamic array, then a linked list,
     *     and compares timing results */
    Stack *arr = new DynamicArray();
    timedTest(arr);
    Stack *linkedlist = new LinkedList();
    timedTest(linkedlist);
    return 0;
}

void timedTest(Stack *ll)
{

    /* We have to use the arrow notation instead of the .
     * because ll is a pointer to a linear list, not a LinearList object
     */
    for (int i = 0; i < SIZE; i++)
    {
        ll->push(i);
    }
    auto start = chrono::steady_clock::now();

    for (int i = 0; i < SIZE; i++)
    {
        ll->pop();
    }

    auto end = chrono::steady_clock::now();

    cout << "Elapsed time in nanoseconds: "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
         << " ns" << endl;
}
