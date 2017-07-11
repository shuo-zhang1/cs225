#ifndef __POSTFIX_EVALUATION__
#define __POSTFIX_EVALUATION__

#include <iostream>
#include <string>
#include <ctype.h>
#include "MyStack.h"
#include "Exceptions.h"	// for expressionError exception

using namespace std;

class postfixEval
{
public:
	postfixEval();
	// default constructor. postfix expression is NULL string

	string getPostfixExp() const;
	// return the postfix expression

	void setPostfixExp(const string& postfixExp);
	// change the postfix expression

	int evaluate();
	// evaluate the postfix expression and return TO DO
	// its value. the function throws expressionError
	// if an error (e.g. divison by zero) occurs during evaluation
private:
	string postfixExpression;
	// the postfix expression to evaluate
	myStack<int> operandStack;
	// stack of operands

	void getOperands(int& left, int& right);
	// pop left and right operands from stack.
	// Precondition: the stack must have at least two entries.
	// if the stack is empty prior to a pop() operation, the
	// function throws the exception expressionError

	int compute(int left, int right, char op) const;
	// compute "left op right". if right is 0 and op TO DO
	// is '/' , the function throws expressionError

	bool isOperator(char ch) const;
	// is ch one of '+','-','*','/' ,'^'
};

void postfixEval::getOperands(int& left, int& right)
{
	// can we pop the right operand?
	if (operandStack.isEmpty())
		throw  expressionError("postfixEval: Too many operators");

	// pop right operand
	right = operandStack.top();
	operandStack.pop();

	// can we pop the left operand?
	if (operandStack.isEmpty())
		throw  expressionError("postfixEval: Too many operators");

	// pop left operand
	left = operandStack.top();
	operandStack.pop();
}

int postfixEval::compute(int left, int right, char op) const
{
	int value;

	// evaluate "left op right"
	switch (op)
	{
	case '+':	value = left + right;
		break;

	 // ******TO DO: complete the rest of the evaluation of the other operators '-', '*', '/' and '^'
	case '-':   value = left - right;
		break;
	case '*':   value = left * right;
		break;
	case '/':   if (right == 0)
			throw
			expressionError("postfixEval: divide by 0");
		value = left / right;
		break;
	case '^':   
		if (left == 0 && right == 0)
			throw
			expressionError("postfixEval: 0^0 undefined");

		value = 1;
		while (right > 0)
		{
			value *= left;
			right--;
		}
		break;

	}

	return value;
}

bool postfixEval::isOperator(char ch) const
{
	return ch == '+' || ch == '-' || ch == '*' ||  ch == '/' || ch == '^';
}

// default constructor
postfixEval::postfixEval()
{}

string postfixEval::getPostfixExp() const
{
	return postfixExpression;
}

void postfixEval::setPostfixExp(const string& postfixExp)
{
	postfixExpression = postfixExp;
}

int postfixEval::evaluate()
{
	// expValue contains the evaluated expression
	int left, right, expValue;
	char ch;
	size_t i;


	for (i = 0; i < postfixExpression.length(); i++)
	{
		// get the current character
		ch = postfixExpression[i];

		if (isdigit(ch))
			operandStack.push(ch - '0');
		else if (isOperator(ch))
		{
			getOperands(left, right);
			operandStack.push(compute(left, right, ch));
		}
		else if (!isspace(ch))
			throw underflowError();
	}

	expValue = operandStack.top();
	operandStack.pop();

	if (!operandStack.isEmpty())
		throw underflowError();
		return expValue;
}

#endif	// POSTFIX_EVALUATION
