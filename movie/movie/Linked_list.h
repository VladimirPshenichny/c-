#pragma once
#include <iostream>
#include <math.h>
#include <conio.h>
#include <string>
#include <limits>

using namespace std;

class Linked_list 
{
private:
	class Node 
	{
	public:
		int index;
		int value;
		Node* next;
		Node* right;
		Node* left;
		Node* down;
		Node* up;
		Node(int value, int index) 
		{
			this->index = index;
			this->value = value;
			this->next = nullptr;
			this->right = nullptr;
			this->left = nullptr;
			this->down = nullptr;
			this->up = nullptr;
		}

		Node(int value, int index, Node* next) 
		{
			this->index = index;
			this->value = value;
			this->next = next;
			this->right = right;
			this->left = left;
			this->down = down;
			this->up = up;
		}
	};

	Node* head = nullptr;

public:
	Node* at_index(int index) {
		Node* temporary = head;
		for (int i = 0; temporary != nullptr && i < index; i++) { temporary = temporary->next; }
		return temporary;
	}

	void add_element(char value, int index) {
		if (index == 0) { head = new Node(value, 0); }
		else 
		{
			Node* el = at_index(index - 1);
			el->next = new Node(value, index, el->next);
		}
	}

	int change(int option, int index) 
	{
		Node* temporary = at_index(index);
		switch (option) 
		{
		case 1: 
		{
			temporary = temporary->right;
			return temporary->index;
			break;
		}
		case 2: 
		{
			temporary = temporary->left;
			return temporary->index;
			break;
		}
		case 3: 
		{
			temporary = temporary->down;
			return temporary->index;
			break;
		}
		case 4: 
		{
			temporary = temporary->up;
			return temporary->index;
			break;
		}
		case 5: 
		{
			if (temporary->value == 0) 
			{
				cout << "Купить или зарезервирова?(1 или 2)" << endl;
				int val;
				val= _getch() - '0';
				temporary->value = val;
			}
			else 
			{
				std::cout << "Нельзя купить или зарезервировать";
				_getch();
			}
			return temporary->index;
			break;
		}
		}
	}

	void create_field(int size_w, int size_l) 
	{
		Node* temporary = head;
		temporary->left = at_index(size_w - 1);
		for (int i = 0; i < size_w; i++) 
		{
			if (i != 0) { temporary->left = at_index(i - 1); }
			if ((i + 1) % (size_w) != 0) { temporary->right = at_index(i + 1); }
			else { temporary->right = at_index(0); }
			temporary->down = at_index(i + size_w);
			temporary->up = at_index(size_w * size_l - size_w + i);
			temporary = temporary->next;
		}
		for (int i = 1; i < size_l - 1; i++) 
		{
			for (int j = 0; j < size_w; j++) 
			{
				if ((j + 1) % (size_w) != 0) { temporary->right = at_index(i * size_w + j + 1); }
				else { temporary->right = at_index(i * size_w + j + 1 - size_w); }
				if (j != 0) { temporary->left = at_index(i * size_w + j - 1); }
				else { temporary->left = at_index((i + 1) * size_w - 1); }
				temporary->down = at_index(i * size_w + j + size_w);
				temporary->up = at_index(i * size_w + j - size_w);
				temporary = temporary->next;
			}
		}
		for (int i = 0; i < size_w; i++) 
		{
			if (i != (size_w - 1)) { temporary->right = at_index(size_w * size_l - size_w + i + 1); }
			else { temporary->right = at_index(size_w * size_l - size_w); }
			if (i != 0) { temporary->left = at_index(size_w * size_l - size_w + i - 1); }
			else { temporary->left = at_index(size_w * size_l - 1); }
			temporary->down = at_index(i);
			temporary->up = at_index(size_w * size_l - size_w * 2 + i);
			temporary = temporary->next;
		}
	}

};