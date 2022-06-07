#include <iostream>
#include <math.h>
#include <conio.h>
#include <string>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <stdio.h>
#include <Windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

class List {
private:
	class Node {
	public:
		int index;
		char value;
		Node* next;
		Node* next_w;
		Node* next_l;
		Node(bool constanta, char value, int index) {
			this->index = index;
			this->value = value;
			this->next = nullptr;
			this->next_w = nullptr;
			this->next_l = nullptr;
		}

		Node(bool constanta, char value, int index, Node* next) {
			this->index = index;
			this->value = value;
			this->next = next;
			this->next_w = next_w;
			this->next_l = next_l;
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
			head = new Node(0, value, 0);

		}
		else {
			Node* el = at_index(index - 1);
			el->next = new Node(0, value, el->index + 1, el->next);
		}
	}

	void create_field(int size) {
		Node* cur_elem = head;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (j < 2) { cur_elem->next_w = at_index(size * i + j + 1); }
				else { cur_elem->next_w = at_index(size * i); }
				if (i < 2) { cur_elem->next_l = at_index(size * (i + 1) + j); }
				else { cur_elem->next_l = at_index(j); }
				cur_elem = cur_elem->next;
			}
		}
	}

	int flex(int But, int index) {
		Node* cur_elem = head;
		switch (But) {
		case 1: {
			cur_elem = at_index(index);
			cur_elem = cur_elem->next_w;
			return cur_elem->index;
			break;
		}
		case 2: {
			if (index % 3 != 0 ) {
				while (cur_elem->index + 3 < index) {
					cur_elem = cur_elem->next_l;
				}
				while (cur_elem->index + 1 < index) {
					cur_elem = cur_elem->next_w;
				}
				return cur_elem->index;
			}
			else { return (index + 2); }
			break;
		}
		case 3: {
			cur_elem = at_index(index);
			cur_elem = cur_elem->next_l;
			return cur_elem->index;
			break;
		}
		case 4: {
			if (index > 2) {
				while (cur_elem->index + 5 < index) {
					cur_elem = cur_elem->next_l;
				}
				while (cur_elem->index + 3 < index) {
					cur_elem = cur_elem->next_w;
				}
				return cur_elem->index;
			}
			else { return (index + 6); }
			break;
		}
		}
	}
};

void create_array(List* list, int size) {
    for (int i = 0; i < size * size; i++) {
        list->add_element(' ', i);
    }
}

int win_game(List* list) {
	if ((list->at_index(0)->value == list->at_index(4)->value) &&(list->at_index(4)->value == list->at_index(8)->value) && (list->at_index(0)->value != ' ')) { return 0; }
	else if ((list->at_index(2)->value == list->at_index(4)->value) && (list->at_index(4)->value == list->at_index(6)->value) && (list->at_index(2)->value != ' ')) { return 0; }
	else if ((list->at_index(0)->value == list->at_index(1)->value) && (list->at_index(1)->value == list->at_index(2)->value) && (list->at_index(0)->value != ' ')) { return 0; }
	else if ((list->at_index(3)->value == list->at_index(4)->value) && (list->at_index(4)->value == list->at_index(5)->value) && (list->at_index(3)->value != ' ')) { return 0; }
	else if ((list->at_index(6)->value == list->at_index(7)->value) && (list->at_index(7)->value == list->at_index(8)->value) && (list->at_index(6)->value != ' ')) { return 0; }
	else if ((list->at_index(0)->value == list->at_index(3)->value) && (list->at_index(3)->value == list->at_index(6)->value) && (list->at_index(6)->value != ' ')) { return 0; }
	else if ((list->at_index(1)->value == list->at_index(4)->value) && (list->at_index(4)->value == list->at_index(7)->value) && (list->at_index(1)->value != ' ')) { return 0; }
	else if ((list->at_index(2)->value == list->at_index(5)->value) && (list->at_index(5)->value == list->at_index(8)->value) && (list->at_index(2)->value != ' ')) { return 0; }
	else { return 1; }
}

int draw(List* list) {
	int count = 0;
	for (int i = 0; i < 9; i++) {
		if (list->at_index(i)->value == ' ') { count++; }
	}
	return count;
}

bool  read_file(List* list) {
	ifstream File("t.txt");
	int size = 3;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			list->at_index(i * size + j)->value = File.get();
		}
		File.get();
	}
	return 1;
}

bool write_file(List* list) {
	int size = 3;
	ofstream File;
	File.open("t.txt");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			File << list->at_index(i * size + j)->value;
		}
		File << endl;
	}
	File.close();
	return 1;
}

void print_game(List* list, int  index){
	int size = 3;
	int check = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (check == index) {
				SetConsoleTextAttribute(hConsole, (WORD)((195 << 4) | 10));
				std::cout << list->at_index(check)->value;
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
				check++;
			}
			else{
				SetConsoleTextAttribute(hConsole, (WORD)((195 << 4) | 195));
				std::cout << list->at_index(check)->value;
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
				check++;
			}
		}
		std::cout << endl;
	}
}

int rules(List* list){
	int count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (list->at_index(3 * i + j)->value != ' ') { count++; }
		}
	}
	return count;
}

void play_menu(List* list) {
	int a = 1;
	int index = 0;
	while (a == 1 && win_game(list) && (rules(list)!=9)) {
		std::cout << "Добро пожаловать в крестики-нолики.\nДля передвижения по ячейкам исползуйте стрелочки, Enter для заполнения ячеек, для завершения игры нажмите Esc" << endl;
		print_game(list, index);
		int But = _getch();
		if (But == 224 || But == 0)
			But = _getch();
		if (But == 77) { index = list->flex(1, index); }
		else if (But == 75) { index = list->flex(2, index); }
		else if (But == 80) { index = list->flex(3, index); }
		else if (But == 72) { index = list->flex(4, index); }
		else if (But == 13) {
			if (rules(list) % 2 && list->at_index(index)->value == ' ') { list->at_index(index)->value = 'O'; }
			else if (list->at_index(index)->value == ' ') { list->at_index(index)->value = 'X'; }
			write_file(list);
		}
		else if (But == 27) {
			a = 0;
		}
		system("cls");
	}
	if (!win_game(list) && rules(list) % 2) { std::cout << "Победил первый(X) игрок" << endl; }
	else if (!win_game(list)) { std::cout << "Победил второй(O) игрок" << endl; }
	else if (rules(list) == 9) { std::cout << "Ничья" << endl; }
}

int main() {
    setlocale(0, "");
    system("cls");
	int answer;
    List* list = new List();
    create_array(list, 3);
    list->create_field(3);
	cout << "Продолжитть предыдущую игру?(1 - да; 0 - нет)" << endl;
	cin >> answer;
	if (answer) { read_file(list); }
	system("cls");
    play_menu(list);
    return 0;
}