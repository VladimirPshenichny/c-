#pragma once
#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

class Build_list {
private:
	class Node {
	public:
		int index, used;
		char value;
		Node* next, * next_w, * prev_w, * next_l, * prev_l;
		Node(char value, int used, int index) {
			this->index = index;
			this->value = value;
			this->next = nullptr;
			this->next_w = nullptr;
			this->prev_w = nullptr;
			this->next_l = nullptr;
			this->prev_l = nullptr;
		}

		Node(char value, int used, int index, Node* next) {
			this->index = index;
			this->value = value;
			this->next = next;
			this->next_w = next_w;
			this->prev_w = prev_w;
			this->next_l = next_l;
			this->prev_l = prev_l;
		}
	};
	Node* head = nullptr;

public:
	Node* at_index(int index) {
		Node* tmp = head;
		for (int i = 0; tmp != nullptr && i < index; i++)
			tmp = tmp->next;
		return tmp;
	}

	void add_element(char value, int index) {
		if (index == 0)
			head = new Node(value, 0, 0);
		else {
			Node* el = at_index(index - 1);
			el->next = new Node(value, 0, index, el->next);
		}
	}

	int move(int option, int index) {
		Node* tmp = at_index(index);
		switch (option) {
		case 1: {
			tmp = tmp->next_w;
			return tmp->index;
			break;
		}
		case 2: {
			tmp = tmp->prev_w;
			return tmp->index;
			break;
		}
		case 3: {
			tmp = tmp->next_l;
			return tmp->index;
			break;
		}
		case 4: {
			tmp = tmp->prev_l;
			return tmp->index;
			break;
		}
		}
	}

	void create_field(int size) {
		Node* tmp = head;
		tmp->prev_w = at_index(size *2 - 1);
		for (int i = 0; i < size * 2; i++) {
			if (i != 0)
				tmp->prev_w = at_index(i - 1);
			if ((i + 1) % (size * 2) != 0)
				tmp->next_w = at_index(i + 1);
			else
				tmp->next_w = at_index(0);
			tmp->next_l = at_index(i + size * 2);
			tmp->prev_l = at_index(size * 2 * size - size * 2 + i);
			tmp = tmp->next;
		}
		for (int i = 1; i < size - 1; i++)
			for (int j = 0; j < size * 2; j++) {
				if ((j + 1) % (size * 2) != 0)
					tmp->next_w = at_index(i * size * 2 + j + 1);
				else
					tmp->next_w = at_index(i * size * 2 + j + 1 - size * 2);
				if (j != 0)
					tmp->prev_w = at_index(i * size * 2 + j - 1);
				else
					tmp->prev_w = at_index((i + 1) * size * 2 - 1);
				tmp->next_l = at_index(i * size * 2 + j + size * 2);
				tmp->prev_l = at_index(i * size * 2 + j - size * 2);
				tmp = tmp->next;
			}
		for (int i = 0; i < size * 2; i++) {
			if (i != (size * 2 - 1))
				tmp->next_w = at_index(size * 2 * size - size * 2 + i + 1);
			else
				tmp->next_w = at_index(size * 2 * size - size * 2);
			if (i != 0)
				tmp->prev_w = at_index(size * 2 * size - size * 2 + i - 1);
			else
				tmp->prev_w = at_index(size * 2 * size - 1);
			tmp->next_l = at_index(i);
			tmp->prev_l = at_index(size * 2 * size - size * 2 * 2 + i);
			tmp = tmp->next;
		}
	}
};