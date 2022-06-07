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
        cout << "Лабораторная работа №2 двусвязный список, выполнил Пшеничный Владимир гр.0373\nДля передвижений по меню используйте стрелочки вверх, вниз или цифры которые используются для нумерации\nДля выбора необходимой функции используйте Enter так же Esc для выхода" << endl;
        char arr[9][256] = { "\t Меню",
            "1) Создание нового элемента",
            "2) Удаление элемента",
            "3) Редактирование элемента",
            "4) Получение длины списка",
            "5) Удалить все элемента после",
            "6) Удалить все с одного элемента до другого",
            "7) Добавить набор новых элементов в любое место",
            "8) Выход"
        };
        for (int i = 0; i < 9; i++) {
            cout << arr[i];
            if (symbol == i)
                cout << "\t<--";
            cout << endl;
        }
        cout << "\nСписок:" << endl;
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
            cout << "Введите значение и номер элемента:\n";
            cin >> value >> index;
            if (index < 0) {
                cout << "Ошибка, ввеледый индекс находится вне списка. Нажмите любую клавишу для перехода в меню.";
                _getch();
            }
            else {
                list->add_element(value, index);
            }
            break;
        }
        case 2: {
            cout << "Введите номер элемента:\n";
            cin >> index;
            if (index < 0) {
                cout << "Ошибка, ввеледый индекс находится вне списка. Нажмите любую клавишу для перехода в меню.";
                _getch();
            }
            else {
                list->delete_elem(index);
            }
            break;
        }
        case 3: {
            cout << "Введите номер элемента и значение для редакции:\n";
            cin >> index >> value;
            if (index < 0) {
                cout << "Ошибка, ввеледый индекс находится вне списка. Нажмите любую клавишу для перехода в меню.";
                _getch();
            }
            else {
                list->change(index, value);
            }
            break;
        }
        case 4: {
            cout << "Кол-во элементов в списке = " << list->size() << "\nНажмите любую клавишу для перехода в меню.";
            _getch();
            break;
        }
        case 5: {
            cout << "Введите номер элемента после которого удалить все элементы:\n";
            cin >> index;
            if (index < 0) {
                cout << "Ошибка, ввеледый индекс находится вне списка. Нажмите любую клавишу для перехода в меню.";
                _getch();
            }
            else {
                list->delete_from(index);
            }
            break;
        }
        case 6: {
            int to;
            cout << "Введите номера элементов после и до которого нужно удалить элементы:\n";
            cin >> index >> to;
            if (index < 0) {
                cout << "Ошибка, ввеледый индекс находится вне списка. Нажмите любую клавишу для перехода в меню.";
                _getch();
            }
            else {
                list->delete_from_to(index, to);
            }
            break;
        }
        case 7: {
            int size;
            cout << "Введите кол-во элементов сколько Вы хотите добать в список, и номер списка с которого нужно вставить элементы:\n";
            cin >> size >> index;
            if (index < 0) {
                cout << "Ошибка, ввеледый индекс находится вне списка. Нажмите любую клавишу для перехода в меню.";
                _getch();
            }
            else {
                if (index > list->size()) {
                    cout << "Ошибка, невозможно вставить список, так как индекс больше кол-ва элементов в списке. Нажмите любую клавишу для перехода в меню.";
                    _getch();
                }
                else {
                    cout << "Введите элементы которые Вы хотите добать в список:\n";
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