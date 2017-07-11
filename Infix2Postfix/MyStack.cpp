#ifndef __MYSTACK_CPP__
#define __MYSTACK_CPP__
#include "Exceptions.h"
#include "MyStack.h"

// Construct the stack.
template <typename T>
myStack<T>::myStack()
{
	topOfStack = nullptr;
}
// Copy constructor.
template <typename T>
myStack<T>::myStack(const myStack<T> & rhs)
{
	topOfStack = nullptr;
	*this = rhs;    
}

// Destructor.
template <typename T>
myStack<T>::~myStack()
{
	makeEmpty();
}

// Test if the Stack is logically empty.
// Return true if empty, false, otherwise.
template <typename T>
bool myStack<T>::isEmpty() const
{
	{
		bool status;

		if (!topOfStack)
		{
			status = true;
		}
		else
		{
			status = false;
		}
		return status;
	}
}

// Make the stack logically empty.
template <typename T>
void myStack<T>::makeEmpty()
{
	// TO DO: Complete so no garbage is generated 
	delete[] topOfStack;
}

// Return the most recently inserted item in the stack.
// or throw an underflowError if empty.
template <typename T>
const T & myStack<T>::top() const
{
	if (isEmpty())
		throw underflowError();
	return topOfStack->element;
}

// Remove the most recently inserted item from the stack.
// Throw underflowError if the stack is empty.
template <typename T>
void myStack<T>::pop()
{
	// TO DO: Complete. Be sure to throw an underflowError() exception if stack is empty. 
	//         Only pop the stack. DO NOT return also return it as a top item. 

	if (isEmpty()) {

		throw underflowError();

	}

	else {

		T topItem = top();

		ListNode* temp = topOfStack;


		topOfStack = topOfStack->next;

		delete temp;

		

	}

}

// Return and remove the most recently inserted item
// from the stack.
template <typename T>
T myStack<T>::topAndPop()
{
	T topItem = top();
	pop();
	return topItem;
}

// Insert x into the stack.
template <typename T>
void myStack<T>::push(const T & x)
{
	ListNode* newTop;


	newTop = new ListNode(x, topOfStack);


	topOfStack = newTop;

}

// Deep copy.
template <typename T>
const myStack<T> & myStack<T>::operator=(const myStack<T> & rhs)
{
	if (this != &rhs)
	{
		makeEmpty();
		if (rhs.isEmpty())
			return *this;

		ListNode *rptr = rhs.topOfStack;
		ListNode *ptr = new ListNode(rptr->element);
		topOfStack = ptr;

		for (rptr = rptr->next; rptr != NULL; rptr = rptr->next)
			ptr = ptr->next = new ListNode(rptr->element);
	}
	return *this;
}
#endif