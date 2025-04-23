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
	
	if (doublyLinkedList.UpdateItem(4, 100)) {
		cout << "Update Seccessfuly" << endl;
	}
	else {
		cout << "Sorray, updata failed" << endl;
	}

	cout << "List's Elements: ";
	doublyLinkedList.PrintList();

	return 0;
}