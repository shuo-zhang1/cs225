#include <iostream>
#include <string>
#include "Linked.h"

using namespace std;

char getAction(string prompt) {
	string answer = "";
	char firstChar = '?';
	cout << endl << prompt;
	getline(cin, answer);
	while (answer.length() == 0) {
		getline(cin, answer);
	}
	firstChar = tolower(answer[0]);
	return firstChar;
}

int main() {
	singleListInt lst;
	int value;
	string prompt = "Enter (a)dd, (d)elete, (f)ind, (p)rint, (c)lear list, (s)ize of list or (q)uit: ";
	char action;
	do {
		action = getAction(prompt);
		switch (action) {
		case 'a':
		{
			cout << "Enter int to add to list: ";
			cin >> value;
			//To Do: Finish
			lst.add(value);
			break;
			
		}
		case 'd':
		{
			cout << "Enter int to be deleted from list: ";
			cin >> value;
			//To Do: Finish
			lst.remove(value);
			break;
			
		}
		case 'f':
		{
			cout << "Enter int to be search in list: ";
			cin >> value;
			//To Do: Finish
			lst.contains(value);
			break;
		
		}
		case 'p':
		{
			cout << "The list is\n";
			//To Do: Finish
			lst.print();
			break;
		
		}
		case 'c':
		{
			cout << "The list will be erased.\n";
			//To Do: Finish
			lst.clearList();
			break;
		
		}
		case 's':
		{
			cout << "The number of ints in the list is " << lst.size() << endl;
			break;
		}
		case 'q':
		{
			cout << "Quitting...\n";
			break;
		}
		default:
		{
			//do nothing
		}
		}
	} while (action != 'q');
	cout << "Done.\n";
	return 0;
}