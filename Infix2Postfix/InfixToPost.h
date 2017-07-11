#ifndef INFIX_TO_POSTFIX
#define INFIX_TO_POSTFIX

#include <iostream>
#include <string>
#include "MyStack.h"
#include <ctype.h>

#include "ExpressionSymbol.h"	// expressionSymbol class
#include "Exceptions.h"	// for expressionError exception

using namespace std;

// labels designating the parentheses characters
const char lParen = '(', rParen = ')';

class infix2Postfix
{
public:
	infix2Postfix();
	// default constructor. infix expression is NULL string
	infix2Postfix(const string& infixExp);
	// initialize the infix expression

	void setInfixExp(const string& infixExp);
	// change the infix expression

	string postfix();
	// return a string that contains the equivalent postfix
	// expression. the function throws expressionError if an
	// error occurs during conversion

private:

	string infixExpression;
	// the infix expression to convert
	string postfixExpression;
	// built to contain the postfix equivalent of infixExpression
	myStack<expressionSymbol> operatorStack;
	// stack of expressionSymbol objects

	void outputHigherOrEqual(const expressionSymbol& op);
	// the expressionSymbol object op holds the current
	// symbol. pop the stack and output as long as the symbol
	// on the top of the stack has a precedence >= that of
	// the current operator

	bool isOperator(char ch) const;
	// is ch one of '+','-','*','/', '^'
};


void infix2Postfix::outputHigherOrEqual(const expressionSymbol& op)
{
	expressionSymbol op2;

	while (!operatorStack.isEmpty() &&
		(op2 = operatorStack.top()) >= op)
	{
		operatorStack.pop();
		postfixExpression += op2.getOp();
		postfixExpression += ' ';
	}
}

bool infix2Postfix::isOperator(char ch) const
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

infix2Postfix::infix2Postfix()
{}

infix2Postfix::infix2Postfix(const string& infixExp) :
              infixExpression{ infixExp }
{}

void infix2Postfix::setInfixExp(const string& infixExp)
{
	// assign a new infix expression
	infixExpression = infixExp;
	// make postfixExpression the NULL string
	postfixExpression = "";
}

string infix2Postfix::postfix()
{
	expressionSymbol op;
	 
	size_t  i;
	char ch;
	int check = 0;


	for (i = 0; i < infixExpression.length(); i++)
	{
		ch = infixExpression[i];

			if (isdigit(ch))
		{
			postfixExpression += ch;
			postfixExpression += ' ';

			check++;
			if (check > 1)
				throw underflowError();
		}

		else if (isOperator(ch) || ch == '('){
			if (ch != '(')
				check--;
				if (check < 0)
					throw expressionError("infix2Postfix: Operand expected");
				else
			{
			op = expressionSymbol(ch);
				outputHigherOrEqual(op);
				operatorStack.push(op);
			}
		}
	else if (ch == rParen){
		op = expressionSymbol(ch);
		outputHigherOrEqual(op);
		if (operatorStack.isEmpty())
			throw expressionError("infix2Postfix: Missing '('");
		else
			operatorStack.pop();
		}

		else if (!isspace(ch))
			throw underflowError();
	}
	if (check != 1)
		throw underflowError();
	else{
		while (!operatorStack.isEmpty()){
			op = operatorStack.top();
			operatorStack.pop();
			if (op.getOp() == lParen)
				throw expressionError("infix2Postfix: Missing ')'");
			else{
				postfixExpression += op.getOp();
				postfixExpression += ' ';
			}
		}
	}
	return postfixExpression;
}

#endif	// INFIX_TO_POSTFIX
