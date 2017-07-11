#ifndef __SINGLY_LINKED_LIST__
#define __SINGLY_LINKED_LIST__
#include <iostream>
using namespace std;
struct IntNode
{
	int data;
	IntNode * next;
	IntNode(const int & d = 0, IntNode *n = nullptr) : data(d), next(n) {}
};

class singleListInt
{
public:
	singleListInt() { init(); } //default constructor and only constructor
	~singleListInt() { eraseList(head); } //destructor
	singleListInt(const singleListInt & rhs) { //Copy Constructor {
		eraseList(head);
		init();
		*this = rhs;
	}
	bool add(int x) {


		if (contains(x)) {
			return false;
		}
		else {

			IntNode* ptr = head->next;
			IntNode* myNode = head;

			while (ptr && ptr->data < x) {
				myNode = ptr;
				ptr = ptr->next;
			}
			myNode->next = new IntNode(x);
			myNode->next->next = ptr;
			theSize++;

		}
		return true;
	}
	bool remove(int x) {
		if (!contains(x)) {
			return false;
		}
		else {
			IntNode* ptr = head;
			theSize--;
			if (head->data == x) {
				head = head->next;
				delete ptr;
			}
			else {
				IntNode* myNode = head;
				ptr = head->next;
				while (ptr != nullptr) {
					if (ptr->data == x) {
						myNode->next = ptr->next;
						delete ptr;
						return true;
					}
					ptr = ptr->next;
					myNode = myNode->next;
				}
			}
			return true;
		}
	}

	int size() { //To Do: Implement : Done
		return theSize;

	}
	void print() {
		IntNode *ptr = head->next;
		//To Do: Print list in ascending order with one space between values
		while (ptr != nullptr) {
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}
	bool contains(const int & x) {
		IntNode * ptr = head->next;

		while (ptr != nullptr && ptr->data <= x) {
			if (x == ptr->data)
				return true;
			else
				ptr = ptr->next;
		}

		return false;
	}
	void clearList() {
		eraseList(head);
		init();
		return;
	}
private:
	void init() {
		theSize = 0;
		head = new IntNode;
		head->next = nullptr;
	}
	void eraseList(IntNode * h) {
		//To Do: remove all the nodes in the list : Done.
		for (int i = 0; i < theSize; i++) {
			remove(i);
		}
		return;
	};
	IntNode *head;
	int theSize;
};
#endif 