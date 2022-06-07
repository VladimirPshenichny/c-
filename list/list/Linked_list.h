#pragma once
#include <iostream>
#include <math.h>
#include <conio.h>
#include <string>
#include <limits>

using namespace std;

class Linked_list {
private:
	class Node {
	public:
		int value;
		Node* next;
		Node(int value) {
			this->value = value;
			this->next = nullptr;
		}

		Node(int value, Node* next) {
			this->value = value;
			this->next = next;
		}
	};
	
	Node* head = nullptr;

	Node* at_index(int index) {
		Node* cur_elem = head;
		for (int i = 0; cur_elem != nullptr && i < index; i++) {
			cur_elem = cur_elem->next;
		}
		return cur_elem;
	}

public:
	void print_list() {
		Node* cur_elem = head;
		for (int i = 0; cur_elem != nullptr; i++) {
			cout << i << ")" << cur_elem->value << "\t";
			cur_elem = cur_elem->next;
		}
	}

	void add_element(int value, int index) {
		if (head == nullptr) {
			if (index == 0) {
				head = new Node(value);
			}
			else {
				cout << "Ошибка. Невозможно создать элемент, так как нет ни одного элемента, сперва создайте нулевой элемент. Нажмите любую клавишу для перехода в меню.";
				_getch();
			}
		}
		else {
			if (index != 0) {
				Node* el = at_index(index - 1);
				if (el == nullptr) {
					cout << "Ошибка. Невозможно создать элемент, так как индекс нового элемента больше количества элементов. Нажмите любую клавишу для перехода в меню.";
					_getch();
				}
				else {
					el->next = new Node(value, el->next);
				}
			}
			else {
				head = new Node(value, head);
			}
		}

	}

	void change(int index, int value) {
		Node* changing_el = at_index(index);
		if (changing_el == nullptr) {
			cout << "Ошибка, невозможно изменить элемент(его не существует). Нажмите любую клавишу для перехода в меню.";
			_getch();
		}
		else {
			changing_el->value = value;
		}
	}

	int size() {
		Node* cur_element = head;
		int count = 0;
		while (cur_element != nullptr) {
			count++;
			cur_element = cur_element->next;
		}
		return count;
	}

	void delete_elem(int index) {
		if (index == 0) {
			if (head != nullptr) {
				Node* head_copy = head;
				head_copy = (head)->next;
				delete head;
				head = head_copy;
			}
			else {
				cout << "Ошибка, невозможно удалить элемент, так как его не существует.  Нажмите любую клавишу для перехода в меню.";
				_getch();
			}
		}
		else if (at_index(index) == nullptr) {
			if (size() == index + 1) {
				delete at_index(index - 1);
				at_index(index - 2)->next = nullptr;
			}
			else {
				cout << "Ошибка, невозможно удалить элемент, так как его не существует.  Нажмите любую клавишу для перехода в меню.";
				_getch();
			}
		}
		else {
			Node* prev_delete = at_index(index - 1);
			Node* deleting_element = prev_delete->next;
			prev_delete->next = deleting_element->next;
			delete deleting_element;
		}
	}

	void delete_from_to(int from, int to) {
		if (from > to) {
			cout << "Ошибка, невозможно удалить элементы, так как индекс последнего элемента меньше первого элемента удаления. Нажмите любую клавишу для перехода в меню.";
			_getch();
		}
		else if (to > size() - 1) {
			cout << "Ошибка, невозможно удалить элементы, так как последний удаляемый элемент больше количесва элементов списка. Нажмите любую клавишу для перехода в меню.";
			_getch();
		}
		else if (from == 0) {
			for (int i = from; i <= to; i++) {
				Node* tmp = head;
				head = tmp->next;
				delete tmp;
			}
		}
		else {
			Node* cur_node = at_index(from - 1);
			for (int i = from; i <= to; i++) {
				Node* tmp = cur_node->next;
				cur_node->next = tmp->next;
				delete tmp;
			}
		}
	}
	
	void delete_from(int index) {
		delete_from_to(index, size() - 1);
	}
};