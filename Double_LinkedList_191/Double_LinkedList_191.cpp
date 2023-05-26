#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START;
public:
	DoubleLinkedList();
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	Node* newNode = new Node(); //step1
	newNode->noMhs = nim;//step2
	newNode->name = nm; //step2

	/*insert a node in the biginning of a doubly - linked list*/
		if (START == NULL || nim <= START->noMhs) {
			if (START != NULL && nim == START->noMhs) {
				cout << "\nDuplicate number not allowed" << endl;
				return;
			}
			newNode->next = START; //step3
			if (START != NULL)
				START->prev = newNode; //step4
			newNode->prev = NULL; //step5
			START = newNode; //step6
			return;
		}
	/* Inserting a Node Beetwen The Nodes in the List */
		Node * current = START; //step1.a
	Node* previous = NULL; //step1.b
	while (current->next != NULL && current->next->noMhs < nim) //step1.c
	{
		previous = current; //1.d
		current = current->next; //1.e
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}
	newNode->next = current->next; //step4
	newNode->prev = current; //step5
	if (current->next != NULL)
		current->next->prev = newNode; //step6
	current->next = newNode; //step7
}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = NULL; //step1.a
	*current = START; //step1.b
	while (*current != NULL && (*current)->noMhs != rollNo) { //step1.c
		*previous = *current; //step1.d
		*current = (*current)->next; //step1.e
	}
	return (*current != NULL);
}

bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous; //step2
	if (previous != NULL)
		previous->next = current->next; //step3
	else
		START = current->next;

	delete current; //step4
	return true;
}

bool DoubleLinkedList::listEmpty() {
	return (START == NULL);
}

void DoubleLinkedList::traverse() {
	if (listEmpty())
		cout << "\nList is Empty" << endl;
	else {
		cout << "\nRecords in ascending order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void DoubleLinkedList::revtraverse() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;
	}

	else {
		cout << "\nRecords in descending order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->prev << endl;
			currentNode = currentNode->prev;
		}
	}
}

void DoubleLinkedList::hapus() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;

	}
	cout << "\nEnter the roll number of the student whose record is to be deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedList::deleteNode(rollNo) == false)
		cout << "Record wnot found" << endl;
	else
		cout << "Record with roll number " << rollNo << "deleted" << endl;
}
void DoubleLinkedList::searchData() {
	if (listEmpty() == true) {
		cout << "\nList is empty" << endl;

	}
	