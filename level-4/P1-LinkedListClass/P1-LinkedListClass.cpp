#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

int main()
{
	clsDblLinkedList<int> doublyLinkedList;

	if (doublyLinkedList.IsEmpty())
		cout << "Yes Is Empty" << endl;
	else
		cout << "No Is Not Empty" << endl;
	doublyLinkedList.InsertAtEnd(1);
	doublyLinkedList.InsertAtEnd(2);
	doublyLinkedList.InsertAtEnd(3);
	doublyLinkedList.InsertAtEnd(4);
	doublyLinkedList.InsertAtEnd(5);

	cout << "List's Elements: ";
	
	doublyLinkedList.PrintList();

	cout << "Size: " << doublyLinkedList.Size() << endl;

	if (doublyLinkedList.IsEmpty())
		cout << "Yes Is Empty" << endl;
	else
		cout << "No Is Not Empty" << endl;

	return 0;
}