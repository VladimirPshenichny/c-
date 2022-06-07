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
		int index;
		bool constanta;
		char value;
		Node* next;
		Node* next_w;
		Node* prev_w;
		Node* next_l;
		Node* prev_l;
		Node(bool constanta, char value, int index) {
			this->index = index;
			this->constanta = constanta;
			this->value = value;
			this->next = nullptr;
			this->next_w = nullptr;
			this->prev_w = nullptr;
			this->next_l = nullptr;
			this->prev_l = nullptr;
		}

		Node(bool constanta, char value, int index, Node* next) {
			this->index = index;
			this->constanta = constanta;
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
		Node* cur_elem = head;
		for (int i = 0; cur_elem != nullptr && i < index; i++) {
			cur_elem = cur_elem->next;
		}
		return cur_elem;
	}

	int Size() {
		Node* cur_element = head;
		int count = 0;
		while (cur_element != nullptr) {
			count++;
			cur_element = cur_element->next;
		}
		return count;
	}

	void add_element(char value, int index) {
		if (index == 0) {
			head = new Node(0, value, 0);

		}
		else {
			Node* el = at_index(index - 1);
			el->next = new Node(0, value, el->index + 1, el->next);
		}
	}

	void change(int index, int value) {
		Node* changing_el = at_index(index);
		changing_el->value = value;
	}

	int flex(int option, char But, int index) {
		Node* cur_elem = at_index(index);
		switch (option) {
		case 1:{
			cur_elem = cur_elem->next_w;
			return cur_elem->index;
			break;
		}
		case 2: {
			cur_elem = cur_elem->prev_w;
			return cur_elem->index;
			break;
		}
		case 3: {
			cur_elem = cur_elem->next_l;
			return cur_elem->index;
			break;
		}
		case 4: {
			cur_elem = cur_elem->prev_l;
			return cur_elem->index;
			break;
		}
		case 5: {
			if (cur_elem->constanta == 0 && rules(index, But) &&  But - '0' <= sqrt(Size()))
				cur_elem->value = But;
			else {
				std::cout << "Нельзя изменять исходные цифры, или повторная цифра, или цифра больше чем допустимая ";
				_getch();
			}
			return cur_elem->index;
			break;
		}
		}
	}

	void create_field(int size) {
		Node* cur_elem = head;
		cur_elem->prev_w = at_index(size * size - 1);
		for (int i = 0; i < size * size; i++) {
			if (i != 0)
				cur_elem->prev_w = at_index(i - 1);
			if((i + 1) % (size * size) != 0)
				cur_elem->next_w = at_index(i + 1);
			else
				cur_elem->next_w = at_index(i + 1 - size * size);
			cur_elem->next_l = at_index(i + size * size);
			cur_elem->prev_l = at_index(size * size * size * size - size * size + i);
			cur_elem = cur_elem->next;
		}
		for (int i = 1; i < size * size - 1; i++) {
			for (int j = 0; j < size * size; j++) {
				if ((j + 1) % (size * size) != 0)
					cur_elem->next_w = at_index(i * size * size + j + 1);
				else
					cur_elem->next_w = at_index(i * size * size + j + 1 - size * size);
				if(j != 0)
					cur_elem->prev_w = at_index(i * size * size + j - 1);
				else
					cur_elem->prev_w = at_index((i + 1) * size * size - 1);
				cur_elem->next_l = at_index(i * size * size + j + size * size);
				cur_elem->prev_l = at_index(i * size * size + j - size * size);
				cur_elem = cur_elem->next;
			}
		}
		for (int i = 0; i < size * size; i++) {
			if (i != size * size - 1)
				cur_elem->next_w = at_index(size * size * size * size - size * size + i + 1);
			else
				cur_elem->next_w = at_index(size * size * size * size - size * size);
			if (i != 0)
				cur_elem->prev_w = at_index(size * size * size * size - size * size + i - 1);
			else
				cur_elem->prev_w = at_index(size * size * size * size - 1);
			cur_elem->next_l = at_index(i);
			cur_elem->prev_l = at_index(size * size * size * size - size * size * 2 + i);
			cur_elem = cur_elem->next;
		}
	}

	int rules(int index, char But) {
		int size = sqrt(sqrt(Size()));
		int raw = index / (size * size);
		int colonm = index % (size * size);
		int pos_r = 0;
		int pos_c = 0;
		Node* cur_elem_l = at_index(index);
		Node* cur_elem_w = at_index(index);
		for (int i = 0; i < size * size - 1; i++) {
			if (But == cur_elem_l->next_l->value || But == cur_elem_w->next_w->value)
				return 0;
			cur_elem_l = cur_elem_l->next_l;
			cur_elem_w = cur_elem_w->next_w;
		}
		while (raw / size) {
			raw -= size;
			pos_r += size;
		}
		while (colonm / size) {
			colonm -= size;
			pos_c += size;
		}
		cur_elem_l = at_index(size * size * pos_r + pos_c);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (But == cur_elem_l->value)
					return 0;
				if (i % 2 == 0 && j < size - 1)
					cur_elem_l = cur_elem_l->next_l;
				else if (i % 2 == 1 && j < size - 1)
					cur_elem_l = cur_elem_l->prev_l;
			}
			cur_elem_l = cur_elem_l->next_w;
		}
		return 1;
	}

};