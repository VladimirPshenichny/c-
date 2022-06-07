#include <iostream>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include <string>
#include "Linked_list.h"

using namespace std;

int num_menu() {
    int symbol = 1;
    int a = 1;
    while (a) {
        cout << "Лабораторная работа №3 генератор снежинок, выполнил Пшеничный Владимир гр.0373\nДля передвижений по меню используйте стрелочки вверх, вниз или цифры которые используются для нумерации\nДля выбора необходимой функции используйте Enter так же Esc для выхода" << endl;
        char arr[9][256] = { "\t Меню",
            "1) Эшкере",
            "2) Удалить все преграды и начать с нуля",
            "3) Вызвать дворника",
            "4) Выход"
        };
        for (int i = 0; i < 5; i++) {
            cout << arr[i];
            if (symbol == i)
                cout << "\t<--";
            cout << endl;
        }
        int But = _getch();
        if (But == 224 || But == 0)
            But = _getch();
        if (But == 72)
            if (symbol - 1 < 1)
                symbol = 4;
            else
                symbol--;
        else if (But == 80)
            if (symbol + 1 > 4)
                symbol = 1;
            else
                symbol++;
        else if (But == 13)
            a = 0;
        else if (But == 27)
            return 4;
        else if (But - '0' >= 1 && But - '0' <= 4) {
            symbol = But - '0';
            a = 0;
        }
        system("cls");
    }
    return symbol;
}

void create_array(Linked_list* array[80]) {
    for (int j = 0; j < 80; j++) {
        array[j] = new Linked_list();
        for (int i = 0; i < 24; i++) {
            array[j]->add_element(' ', i);
        }
    }
}

void print_game(Linked_list* array[80]) {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 82; j++) {
            if (i == 0) {
                cout << '_';
            }
            else if (j == 0) {
                cout << '|';
            }
            else if (i > 0 && j > 0  && i < 25 && j < 81) {
                cout << array[j - 1]->at_index(i - 1)->value;
            }
            else if (j == 81) {
                cout << '|';
            }
            else if(i == 25) {
                cout << '_';
            }
        }
        cout << endl;
    }
}

int win_game(Linked_list* array[80]) {
    for (int i = 0; i < 80; i++) {
        if (array[i]->at_index(1)->value == '*') {
            return 0;
        }
    }
    return 1;
}

int physics(Linked_list* array[80], int column) {
    int index_column_1 = 0;
    int index_column_2 = 0;
    int index_column_3 = 0;
    for (int i = 1; i < 24; i++) {
        if (array[column]->at_index(i)->value != '*') {
            index_column_1++;
        }
        if (column != 79 && array[column+1]->at_index(i)->value != '*') {
            index_column_2++;
        }
        if (column != 0 && array[column-1]->at_index(i)->value != '*') {
            index_column_3++;
        }
    }
    for (int i = 0; i < 24; i++) {
        if (index_column_2 - index_column_1 >= 2){
            return 2;
        }
        else if (index_column_3 - index_column_1 >= 2) {
            return 3;
        }
        else {
            return 1;
        }
    }
}

void fall(Linked_list* array[80], int column) {
    int b = 1;
    int shift = 0;
    while (b) {
        switch (physics(array, column)) {
        case 1: {
            for (int i = 1; i < 24; i++) {
                if (array[column]->at_index(i)->value != '*') {
                    array[column]->change(i, '*');
                    array[column]->change(i - 1, ' ');
                }
            }
            b = 0;
            break;
        }
        case 2: {
            array[column]->change(0, ' ');
            column++;
            shift++;
            break;
        }
        case 3: {
            array[column]->change(0, ' ');
            column--;
            shift--;
            break;
        }
        }
    }
    column = column + shift;
}

int play_menu(Linked_list* array[80]) {
    int symbol = 0;
    int a = 1;
    while (a == 1 && win_game(array)) {
        cout << "Добро пожажовать в генератор снежинок, если хоть одна снежинка коснется небес, то вы победили.\nДля передвижения по неме исползуйте стрелочки влево и вправо, для создания снежинки нажмите Enter, для завершения игры и возврату в меню нажмите Esc" << endl << endl;
        for (int i = 0; i < 80; i++) {
            if (symbol == i)
                array[i]->change(0, '*');
        }
        print_game(array);
        int But = _getch();
        if (But == 224 || But == 0)
            But = _getch();
        array[symbol]->change(0, ' ');
        if (But == 75)
            if (symbol - 1 < 0) {
                symbol = 79;
            }
            else {
                symbol--;
            }
        else if (But == 77)
            if (symbol + 1 > 79) {
                symbol = 0;
            }
            else {
                symbol++;
            }
        else if (But == 13) {
            fall(array, symbol);
        }
        else if (But == 27) {
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
    int value;

    Linked_list* array[80];

    create_array(array);
    while (symbol != 4) {
        system("cls");
        symbol = num_menu();
        switch (symbol) {
        case 1: {
            play_menu(array);
            if (!win_game(array)) {
                cout << "Поздравляю вы прошли игру, нажмите любую клавишу бля перехода в меню, если хотите сыгать вызовите дворника или начните игру с нуля";
                _getch();
            }
            break;
        }
        case 2: {
            create_array(array);
            play_menu(array);
            if (!win_game(array)) {
                cout << "Поздравляю вы прошли игру, нажмите любую клавишу бля перехода в меню, если хотите сыгать вызовите дворника или начните игру с нуля";
                _getch();
            }
            break;
        }
        case 3: {
            create_array(array);
            break;
        }
        }
    }
    return 0;
}