#pragma once

using namespace std;

template <class T> class clsDoublyLinkedList {
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

		_size++;
	}

	bool InsertAfter(Node* prevNode, T data) {
		if (prevNode == nullptr) 
			return false;

		Node* newNode = new Node{ prevNode, data, prevNode->next };

		if (prevNode->next != nullptr) {
			prevNode->next->prev = newNode;
		}

		prevNode->next = newNode;

		_size++;
		return true;
	}

	bool InsertAfter(int index, T data) {
		return InsertAfter(GetNode(index), data);
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
		
		_size++;
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

		_size--;
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

		_size--;
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

		_size--;
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
		return _size;
	}

	bool IsEmpty() {
		return _size == 0;
	}

	void Clear() {
		while (_size > 0) {
			DeleteFirstNode();
		}
	}

	void Reveres() {
		if (head->next == nullptr)
			return;

		Node* prevNode = head;

		while (head != nullptr) {
			prevNode = head->prev;
			head->prev = head->next;
			head->next = prevNode;

			head = head->prev;
		}

		head = prevNode->prev;
	}

	Node* GetNode(int index) {
		if (index < 0 || index >= _size)
			return nullptr;

		int i = 0;
		Node* current = head;

		while (current != nullptr) {
			if (i == index) {
				return current;
			}

			i++;
			current = current->next;
		}

		return nullptr;
	}

	T GetItem(int index) {
		Node* node = GetNode(index);
		return node != nullptr ? node->data : NULL;
	}

	bool UpdateItem(int index, T newData) {
		Node* node = GetNode(index);
		return node != nullptr ? (node->data = newData) : false;
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
	 int _size;

	 Node* GetLastNode() {
		if (head == nullptr)
			return nullptr;

		Node* lastNode = head;

		while (lastNode->next != nullptr)
			lastNode = lastNode->next;

		return lastNode;
	}
};