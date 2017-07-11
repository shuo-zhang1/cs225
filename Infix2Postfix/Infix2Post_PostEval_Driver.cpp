// This program inputs an infix expression until the user enters an empty
// string. 
// It uses the class infix2Postfix to convert the infix expression to postfix. It assumes no errors.
// Assuming the infix to postfix works and the postfix string is correctly formatted, class postfixEval is used
// to evaluate the postfix expression and output the result.

#include <iostream>
#include <string>
 

#include "InfixToPost.h"		// infix2Postfix class
#include "PostFixEval.h"			// postfixEval class
#include "Exceptions.h"
using namespace std;

int main()
{
	// use iexp for infix to postfix conversion
	infix2Postfix iexp;
	// infix expression input and postfix expression output
	string infixExp, postfixExp;
	// use pexp to evaluate postfix expressions
	postfixEval pexp;

	// input and evaluate infix expressions until the
	// user enters an empty string

	// get the first expression
	cout << "Enter an infix expression: ";
	getline(cin, infixExp);

	while (infixExp != "")
	{
		// an exception may occur. enclose the conversion
		// to postfix and the output of the expression
		// value in a try block
		try
		{
			// convert to postfix
			iexp.setInfixExp(infixExp);
			postfixExp = iexp.postfix();

			// output the postfix expression
			cout << "The postfix form is " << postfixExp
				<< endl;

			// use pexp to evaluate the postfix expression
			pexp.setPostfixExp(postfixExp);

			cout << "Value of the expression = "
				<< pexp.evaluate() << endl << endl;
		}

		// catch an exception and output the error
		catch (const expressionError& ee)
		{
			cout << ee.what() << endl << endl;
		}
		// input another expression
		cout << "Enter an infix expression: ";
		getline(cin, infixExp);
	}

	return 0;
}

