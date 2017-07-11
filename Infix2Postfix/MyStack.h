#ifndef _MY_STACK_H_
#define _MY_STACK_H_

#include <stdlib.h>
#include "Exceptions.h"

// myStack class -- linked list implementation.
//
// CONSTRUCTION: with no parameters.
//
// ******************PUBLIC OPERATIONS*********************
// void push( x )        --> Insert x
// void pop( )           --> Remove most recently inserted item
// T top( )         --> Return most recently inserted item
// T topAndPop( )   --> Return and remove most recently inserted item
// bool isEmpty( )       --> Return true if empty; else false
// void makeEmpty( )     --> Remove all items
// ******************ERRORS********************************
// UnderflowException thrown as needed.

template <typename T>
class myStack
{
public:
	myStack();
	myStack(const myStack & rhs);
	~myStack();

	bool isEmpty() const;
	const T & top() const;

	void makeEmpty();
	void pop();
	void push(const T & x);
	T topAndPop();

	const myStack & operator=(const myStack & rhs);

private:
	struct ListNode
	{
		T    element;
		ListNode *next;

		ListNode(const T & theElement, ListNode * n = NULL)
			: element(theElement), next(n) { }
	};

	ListNode *topOfStack;
};

#include "MyStack.cpp"
#endif

