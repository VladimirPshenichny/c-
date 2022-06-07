#include <iostream>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include <string>
#include <fstream>
#include "Linked_list.h"
#include <stdio.h>
#include <Windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

int move_w(char But, int symbol, int first, int last) {
    if (But == 72)
        if (symbol - 1 < first)
            symbol = last;
        else
            symbol--;
    else if (But == 80)
        if (symbol + 1 > last)
            symbol = first;
        else
            symbol++;
    return symbol;
}

int move_l(char But, int symbol, int first, int last) {
    if (But == 75)
        if (symbol - 1 < first)
            symbol = last;
        else
            symbol--;
    else if (But == 77)
        if (symbol + 1 > last)
            symbol = first;
        else
            symbol++;
    return symbol;
}

int num_menu() {
    int symbol = 1;
    int a = 1;
    while (a) {
        cout << "Лабораторная работа №3 генератор снежинок, выполнил Пшеничный Владимир гр.0373\nДля передвижений по меню используйте стрелочки вверх, вниз или цифры которые используются для нумерации\nДля выбора необходимой функции используйте Enter так же Esc для выхода" << endl;
        char arr[8][256] = { "\t Меню",
            "1) Эшкере",
            "2) Создать преграды",
            "3) Загрузить игру из файла",
            "4) Сохранить игру в файл",
            "5) Удалить все преграды и начать с нуля",
            "6) Вызвать дворника",
            "7) Выход"
        };
        for (int i = 0; i <= 7; i++) {
            cout << arr[i];
            if (symbol == i)
                cout << "\t<--";
            cout << endl;
        }
        int But = _getch();
        if (But == 224 || But == 0)
            But = _getch();
        symbol = move_w(But, symbol, 1, 7);
        if (But - '0' >= 1 && But - '0' <= 7) {
            symbol = But - '0';
            a = 0;
        }
        else if (But == 13)
            a = 0;
        else if (But == 27)
            return 7;
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
                cout << ' ';
            }
            else if (j == 0) {
                cout << ' ';
            }
            else if (i > 0 && j > 0 && i < 25 && j < 81) {
                if (array[j - 1]->at_index(i - 1)->value == '#' || array[j - 1]->at_index(i - 1)->value == '_') {
                    SetConsoleTextAttribute(hConsole, (WORD)((195 << 4) | 0));
                    cout << array[j - 1]->at_index(i - 1)->value;
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                }
                else {
                    SetConsoleTextAttribute(hConsole, (WORD)((195 << 4) | 15));
                    cout << array[j - 1]->at_index(i - 1)->value;
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                }
            }
            else if (j == 81) {
                cout << ' ';
            }
            else if (i == 25) {
                cout << ' ';
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

void physics(Linked_list* array[80], int* column, int* index_snowflakes) {
    while ((*index_snowflakes < 23) && (array[*column]->at_index((*index_snowflakes) + 1)->value == ' ')) {
        (*index_snowflakes)++;
    }
    if ((*index_snowflakes) < 22 && (array[(*column)]->at_index((*index_snowflakes) + 1)->value != '#')) {
        if ((array[(*column)]->at_index((*index_snowflakes) + 1)->value == '*' && array[(*column)]->at_index((*index_snowflakes) + 2)->value == '*')) {
        if ((*column) < 79 && (*index_snowflakes) <= 21) {
            if (array[(*column) + 1]->at_index((*index_snowflakes) + 2)->value == ' ' && array[(*column) + 1]->at_index(*index_snowflakes)->value == ' ' && array[(*column) + 1]->at_index((*index_snowflakes) + 1)->value == ' ') {
                (*column)++;
                (*index_snowflakes) += 2;
                physics(array, column, index_snowflakes);
            }
        }
        if (*column > 0 && *index_snowflakes <= 21) {
            if (array[(*column) - 1]->at_index((*index_snowflakes) + 2)->value == ' ' && array[(*column) - 1]->at_index(*index_snowflakes)->value == ' ' && array[(*column) - 1]->at_index((*index_snowflakes) + 1)->value == ' ') {
                (*column)--;
                (*index_snowflakes) += 2;
                physics(array, column, index_snowflakes);
            }
        }
        }
    }
}

void fall(Linked_list* array[80], int column) {
    int index_snowflakes = 1;
    while (index_snowflakes < 23 && array[column]->at_index(index_snowflakes + 1)->value == ' ') {
        physics(array, &column, &index_snowflakes);
    }
    array[column]->at_index(index_snowflakes)->value = '*';
}

void play_menu(Linked_list* array[80]) {
    int column = 0;
    int a = 1;
    while (a == 1 && win_game(array)) {
        cout << "Добро пожажовать в генератор снежинок, если хоть одна снежинка коснется небес, то вы победили.\nДля передвижения по неме исползуйте стрелочки влево и вправо, для создания снежинки нажмите Enter, для завершения игры и возврату в меню нажмите Esc" << endl;
        for (int i = 0; i <= 79; i++) {
            if (column == i)
                array[i]->change(0, '*');
        }
        print_game(array);
        int But = _getch();
        if (But == 224 || But == 0)
            But = _getch();
        array[column]->change(0, ' ');
        column = move_l(But, column, 0, 79);
        if (But == 13) {
            fall(array, column);
        }
        else if (But == 27) {
            a = 0;
        }
        system("cls");
    }
}

int check(Linked_list* array[80], int column, int raw) {
    for (int i = 0; i < 80; i++) {
        for (int j = 2; j < 24; j++) {
            if (column == i && raw == j) {
                if (array[column]->at_index(raw)->value == '#') {
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }
    }
}

int change_barriers(Linked_list* array[80], int column, int raw) {
    if (array[column]->at_index(raw)->value == '#') {
        return 1;
    }
    else {
        return 0;
    }
}

void create_barriers(Linked_list* array[80]) {
    int column = 0;
    int raw = 2;
    int a = 1;
    while (a) {
        cout << "Вы пришли в редактор игрового поля.\nДля передвижения по полю исползуйте стрелочки, для создания барьера нажмите Enter, а возврата в меню нажмите Esc" << endl << endl;
        for (int i = 0; i < 80; i++) {
            for (int j = 2; j < 24; j++) {
                if (column == i && raw == j) {
                    if (array[column]->at_index(raw)->value != '#') {
                        array[column]->change(raw, '_');
                    }
                }
            }
        }
        print_game(array);
        int But = _getch();
        if (!check(array, column, raw)) {
            array[column]->change(raw, ' ');
        }
        if (But == 224 || But == 0)
            But = _getch();
        raw = move_w(But, raw, 2, 23);
        column = move_l(But, column, 0, 79);
        if (But == 13) {
            if (!change_barriers(array, column, raw)) {
                array[column]->change(raw, '#');
            }
            else {
                array[column]->change(raw, ' ');
            }
        }
        else if (But == 27) {
            a = 0;
        }
        system("cls");
    }
}

char* read_path() {
    char* str = new char[1000];
    for (int i = 0; i < 1000; i++) {
        str[i] = '0';
    }
    if (_getch() == 49) {
        cout << "Напишите путь и имя вайла с расширением. Пример 't.txt':\n";
        cin >> str;
        int i = 0;
        while (str[i] != '0') {
            i++;
        }
        str[i] = '\0';
    }
    return str;
}

bool  read_file(Linked_list* array[80], char* FileName) {
    ifstream File(FileName);
    if (!File) {
        cout << "Открыть файл не удалось!\n";
        return 0;
    }
    char S[80];
    cout << '\n';
        for (int i = 0; i < 24; i++) {
            //File.getline(S, 80);
            for (int j = 0; j < 80; j++) {
                //File >> S[j];
                File.get(S[j]);
                if (S[j] == '0' || S[j] == '*' || S[j] == ' ') {
                    array[j]->at_index(i)->value = ' ';
                }
                else if (S[j] == '#') {
                    array[j]->at_index(i)->value = '#';
                }
            }
            //File >> S[79];
            File.get (S[79]);
            //cout << S << endl;
        }
}

bool write_file(Linked_list* array[80], char* FileName){
    ofstream File;
    char Fame = '#';
    File.open(FileName);
    if (!File.is_open()) {
        cout << "Открыть файл не удалось!\n";
        return 0;
    }
    cout << '\n';
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 80; j++) {
            File << array[j]->at_index(i)->value;
        }
        File << endl;
    }
    File.close();
    return 1;
}

int main() {
    setlocale(0, "");
    system("cls");
    char Fame = '#';
    int symbol = 1;
    int index, value;
    char* str = new char[1000];

    Linked_list* array[80];

    create_array(array);
    while (symbol != 7) {
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
            //create_array(array);
            create_barriers(array);
            break;
        }
        case 3: {
            system("cls");
            cout << "Считать файл?(1-да, 0- нет)" << endl;
            str = read_path();
            read_file(array, str);
            cout << "Нажмите любую клавишу, чтобы открыть меню" << endl;
            _getch();
            system("cls");
            break;
        }
        case 4: {
            system("cls");
            cout << "сохранить текущую игру?(1-да, 0- нет)" << endl;
            str = read_path();
            write_file(array, str);
            cout << "Нажмите любую клавишу, чтобы открыть меню" << endl;
            _getch();
            system("cls");
            break;
        }
        case 5: {
            create_array(array);
            play_menu(array);
            break;
        }
        case 6: {
            create_array(array);
            break;
        }
        }
    }
    return 0;
}