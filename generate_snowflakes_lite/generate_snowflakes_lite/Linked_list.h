#pragma once
#include <iostream>
#include <math.h>
#include <conio.h>
#include <string>

using namespace std;

class Linked_list {
private:
	class Node {
	public:
		char value;
		Node* next;
		Node* prev;
		Node(int value) {
			this->value = value;
			this->next = nullptr;
			this->prev = nullptr;
		}

		Node(char value, Node* next) {
			this->value = value;
			this->next = next;
			this->prev = prev;
		}
	};

	Node* head = nullptr;

public:
	Node* at_index(int index) {
		Node* cur_elem = head;
		for (int i = 0; cur_elem != nullptr && i < index; i++) {
			cur_elem = cur_elem->next;
		}
		return cur_elem;
	}

	void add_element(char value, int index) {
		if (index == 0) {
			head = new Node(value);
		}
		else {
			Node* el = at_index(index - 1);
			el->next = new Node(value, el->next);
			el->next->prev = el;
		}
	}

	void change(int index, int value) {
		Node* changing_el = at_index(index);
		changing_el->value = value;
	}
};

