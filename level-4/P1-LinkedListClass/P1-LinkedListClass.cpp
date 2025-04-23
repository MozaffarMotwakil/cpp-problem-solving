#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

int main()
{
	clsDblLinkedList<int> doublyLinkedList;

	doublyLinkedList.InsertAtEnd(1);
	doublyLinkedList.InsertAtEnd(2);
	doublyLinkedList.InsertAtEnd(3);
	doublyLinkedList.InsertAtEnd(4);
	doublyLinkedList.InsertAtEnd(5);

	cout << "List's Elements: ";
	doublyLinkedList.PrintList();

	cout << "Size: " << doublyLinkedList.Size() << endl;
	
	int item = doublyLinkedList.GetItem(4);

	if (item != NULL) {
		cout << "Node's value is: " << item << endl;
	}
	else {
		cout << "Don't Found Node" << endl;
	}

	return 0;
}