#include <iostream>
#include <string>
using namespace std;

class node {
public:
	int noMhs;
	string name;
	node* next;
	node* prev;
};

class DoubleLinkedList {
private:
	node* start;
public:
	DoubleLinkedList();
	void addnote();
	bool search(int rollno, node** previous, node** current);
	bool deletednode(int rollno);
	bool ListEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

DoubleLinkedList::DoubleLinkedList() {
	start = NULL;
}

void DoubleLinkedList::addnote() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the  number of the student: ";
	cin >> nm;
	node* newnode = new node(); // step 1
	newnode->noMhs = nim; // step 2


	/*insert a node in the beginning of a doubly - Linked list*/
	if (start == NULL || nim <= start->noMhs) {
		if (start != NULL && nim == start->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newnode->next = start;//step 3
	}
}