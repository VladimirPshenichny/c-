#include <iostream>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include <string>
#include <limits>
#include "linker_list.h"

using namespace std;

int num_menu(linker_list* list) {
    int symbol = 1;
    int a = 1;
    while (a) {
        cout << "������������ ������ �2 ���������� ������, �������� ��������� �������� ��.0373\n��� ������������ �� ���� ����������� ��������� �����, ���� ��� ����� ������� ������������ ��� ���������\n��� ������ ����������� ������� ����������� Enter ��� �� Esc ��� ������" << endl;
        char arr[9][256] = { "\t ����",
            "1) �������� ������ ��������",
            "2) �������� ��������",
            "3) �������������� ��������",
            "4) ��������� ����� ������",
            "5) ������� ��� �������� �����",
            "6) ������� ��� � ������ �������� �� �������",
            "7) �������� ����� ����� ��������� � ����� �����",
            "8) �����"
        };
        for (int i = 0; i < 9; i++) {
            cout << arr[i];
            if (symbol == i)
                cout << "\t<--";
            cout << endl;
        }
        cout << "\n������:" << endl;
        list->print_list();
        int But = _getch();
        if (But == 224 || But == 0)
            But = _getch();
        if (But == 72)
            if (symbol - 1 < 1)
                symbol = 8;
            else
                symbol--;
        else if (But == 80)
            if (symbol + 1 > 8)
                symbol = 1;
            else
                symbol++;
        else if (But == 13)
            a = 0;
        else if (But == 27)
            return 8;
        else if (But - '0' >= 1 && But - '0' <= 8) {
            symbol = But - '0';
            a = 0;
        }
        system("cls");
    }
    return symbol;
}

int main() {
    setlocale(0, "");
    system("cls");
    int symbol = 1;
    int index, value;

    linker_list* list = new linker_list();

    while (symbol != 8) {
        system("cls");
        symbol = num_menu(list);
        switch (symbol) {
        case 1: {
            cout << "������� �������� � ����� ��������:\n";
            cin >> value >> index;
            if (index < 0) {
                cout << "������, �������� ������ ��������� ��� ������. ������� ����� ������� ��� �������� � ����.";
                _getch();
            }
            else {
                list->add_element(value, index);
            }
            break;
        }
        case 2: {
            cout << "������� ����� ��������:\n";
            cin >> index;
            if (index < 0) {
                cout << "������, �������� ������ ��������� ��� ������. ������� ����� ������� ��� �������� � ����.";
                _getch();
            }
            else {
                list->delete_elem(index);
            }
            break;
        }
        case 3: {
            cout << "������� ����� �������� � �������� ��� ��������:\n";
            cin >> index >> value;
            if (index < 0) {
                cout << "������, �������� ������ ��������� ��� ������. ������� ����� ������� ��� �������� � ����.";
                _getch();
            }
            else {
                list->change(index, value);
            }
            break;
        }
        case 4: {
            cout << "���-�� ��������� � ������ = " << list->size() << "\n������� ����� ������� ��� �������� � ����.";
            _getch();
            break;
        }
        case 5: {
            cout << "������� ����� �������� ����� �������� ������� ��� ��������:\n";
            cin >> index;
            if (index < 0) {
                cout << "������, �������� ������ ��������� ��� ������. ������� ����� ������� ��� �������� � ����.";
                _getch();
            }
            else {
                list->delete_from(index);
            }
            break;
        }
        case 6: {
            int to;
            cout << "������� ������ ��������� ����� � �� �������� ����� ������� ��������:\n";
            cin >> index >> to;
            if (index < 0) {
                cout << "������, �������� ������ ��������� ��� ������. ������� ����� ������� ��� �������� � ����.";
                _getch();
            }
            else {
                list->delete_from_to(index, to);
            }
            break;
        }
        case 7: {
            int size;
            cout << "������� ���-�� ��������� ������� �� ������ ������ � ������, � ����� ������ � �������� ����� �������� ��������:\n";
            cin >> size >> index;
            if (index < 0) {
                cout << "������, �������� ������ ��������� ��� ������. ������� ����� ������� ��� �������� � ����.";
                _getch();
            }
            else {
                if (index > list->size()) {
                    cout << "������, ���������� �������� ������, ��� ��� ������ ������ ���-�� ��������� � ������. ������� ����� ������� ��� �������� � ����.";
                    _getch();
                }
                else {
                    cout << "������� �������� ������� �� ������ ������ � ������:\n";
                    for (int i = 0; i < size; i++) {
                        cin >> value;
                        list->add_element(value, index + i);
                    }
                }
            }
            break;
        }
        }
    }
    return 0;
}