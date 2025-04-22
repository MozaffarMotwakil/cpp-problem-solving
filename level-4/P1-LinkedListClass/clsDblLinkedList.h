#pragma once

using namespace std;

template <class T> class clsDblLinkedList {
public:
	class Node {
	public:
		Node* prev;
		T data;
		Node* next;
	};

	Node* head = nullptr;

	void InsertAtBeginning(T data) {
		Node* newNode = new Node{ nullptr , data, head };

		if (head != nullptr)
			head->prev = newNode;

		head = newNode;
	}

	bool InsertAfter(Node* &prevNode, T data) {
		if (prevNode == nullptr) 
			return false;

		Node* newNode = new Node{ prevNode, data, prevNode->next };

		if (prevNode->next != nullptr) {
			prevNode->next->prev = newNode;
		}

		prevNode->next = newNode;

		return true;
	}

	void InsertAtEnd(T data) {
		Node* newNode = new Node{ nullptr, data, nullptr};

		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node* lastNode = GetLastNode();

			newNode->prev = lastNode;
			lastNode->next = newNode;
		}
		
	}

	bool DeleteNode(Node* node) {
		if (head == nullptr || node == nullptr)
			return false;

		if (head == node) 
			head = node->next;

		if (node->next != nullptr)
			node->next->prev = node->prev;

		if (node->prev !=nullptr)
			node->prev->next = node->next;

		delete node;

		return true;
	}
	
	bool DeleteFirstNode() {
		if (head == nullptr) 
			return false;

		Node* firstNode = head;

		head = firstNode->next;

		if (head != nullptr)
			head->prev = nullptr;

		delete firstNode;

		return true;
	}

	bool DeleteLastNode() {
		if (head == nullptr)
			return false;

		Node* lastNode = GetLastNode();

		if (lastNode->prev != nullptr)
			lastNode->prev->next = nullptr;
		else
			head = nullptr;

		delete lastNode;
		return true;
	}

	Node* Find(T data) {
		Node* current = head;

		while (current != nullptr) {
			if (data == current->data) {
				return current;
			}

			current = current->next;
		}

		return current;
	}

	int Size() {
		Node* current = head;

		int size = 0;

		while (current != nullptr) {
			size++;
			current = current->next;
		}
		
		return size;
	}


	void PrintList() {
		Node* current = head;

		while (current != NULL) {
			cout << current->data << " ";
			current = current->next;
		}

		cout << endl;
	}

private:
	 Node* GetLastNode() {
		if (head == nullptr)
			return nullptr;

		Node* lastNode = head;

		while (lastNode->next != nullptr)
			lastNode = lastNode->next;

		return lastNode;
	}

};