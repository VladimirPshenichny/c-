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

int num_menu(Linked_list* list) {
    int symbol = 1;
    int a = 1;
    while (a) {
        std::cout << "Курсовая работа Судоку, выполнил Пшеничный Владимир гр.0373\nДля передвижений по меню используйте стрелочки вверх, вниз или цифры которые используются для нумерации\nДля выбора необходимой функции используйте Enter так же Esc для выхода" << endl;
        char arr[9][256] = { "\t Меню",
            "1) Продолжение игры",
            "2) Новая игра 2Х2",
            "3) Новая игра 3Х3",
            "4) Создать новую игру",
            "5) Изменение текущей игры",
            "6) Запомнить в библиотеку",
            "7) Загрузить из библиотеки",
            "8) Выход"
        };
        for (int i = 0; i < 9; i++) {
            std::cout << arr[i];
            if (symbol == i)
                std::cout << "\t<--";
            std::cout << endl;
        }
        int But = _getch();
        if (But == 224 || But == 0)
            But = _getch();
        symbol = move_w(But, symbol, 1, 8);
        if (But - '0' >= 1 && But - '0' <= 8) {
            symbol = But - '0';
            a = 0;
        }
        else if (But == 13)
            a = 0;
        else if (But == 27)
            return 8;
        system("cls");
    }
    return symbol;
}

void create_array(Linked_list* list, int size) {
    for (int i = 0; i < size* size* size* size; i++) {
        list->add_element(' ', i);
    }
}

int win_game(Linked_list* list) {
    int count = 0;
    for (int i = 0; i < list->Size(); i++) {
        if (list->at_index(i)->value == ' ') {
            count++;
        }
    }
    return count;
}

void print_game(Linked_list* list, int index){
    int size = sqrt(sqrt(list->Size()));
    int check = 0;
    for (int i = 0; i < size*size+size+1; i++) {
        for (int j = 0; j < size * size + size + 1; j++) {
            if (i % (size + 1) == 0 || j % (size + 1) == 0) {
                SetConsoleTextAttribute(hConsole, (WORD)((195 << 4) | 0));
                std::cout << '#';
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
            }
            else if ((check == index) && (list->at_index(index)->constanta == 1)){
                SetConsoleTextAttribute(hConsole, (WORD)((195 << 4) | 10));
                std::cout << list->at_index(check)->value;
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                check++;
            }
            else if (check == index && list->at_index(index)->constanta == 0) {
                SetConsoleTextAttribute(hConsole, (WORD)((195 << 4) | 13));
                std::cout << list->at_index(check)->value;
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                check++;
            }
            else if(check != index && list->at_index(check)->constanta == 1){
                SetConsoleTextAttribute(hConsole, (WORD)((195 << 4) | 14));
                std::cout << list->at_index(check)->value;
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                check++;
            }
            else if(check != index && list->at_index(check)->constanta == 0){
                SetConsoleTextAttribute(hConsole, (WORD)((195 << 4) | 15));
                std::cout << list->at_index(check)->value;
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                check++;
            }
        }
        std::cout << endl;
    }
}

void play_menu(Linked_list* list) {
    int a = 1;
    int index = 0;
    while (a == 1 && win_game(list)) {
        std::cout << "Судоку приветствует вас, для победы заполните все ячейти цифрами.\nДля передвижения по неме исползуйте стрелочки, цифры для заполнения ячеек, для завершения игры и возврату в меню нажмите Esc" << endl;
        print_game(list, index);
        int But = _getch();
        if (But == 224 || But == 0)
            But = _getch();
        if (But == 77)
            index = list->flex(1, But, index);
        else if (But == 75)
            index = list->flex(2, But, index);
        else if (But == 80)
            index = list->flex(3, But, index);
        else if (But == 72)
            index = list->flex(4, But, index);
        else if (isdigit(But) && But - '0' != 0)
            index = list->flex(5, But, index);
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
        std::cout << "Напишите путь и имя вайла с расширением. Пример 't.txt':\n";
        cin >> str;
        int i = 0;
        while (str[i] != '0') {
            i++;
        }
        str[i] = '\0';
    }
    return str;
}

bool  read_file(Linked_list* list, char* FileName) {
    ifstream File(FileName);
    if (!File) {
        std::cout << "Открыть файл не удалось!\n";
        return 0;
    }
    std::cout << '\n';
    int size = File.get() - '0';
    File.get();
    create_array(list, size);
    list->create_field(size);
    for (int i = 0; i < size * size; i++) {
        for (int j = 0; j < size * size; j++) {
            list->at_index(i * size * size + j)->value = File.get();
            if (isdigit(list->at_index(i * size * size + j)->value) && list->at_index(i * size * size + j)->value - '0' !=0)
                list->at_index(i * size * size + j)->constanta = 1;
        }
        File.get();
    }
}

bool write_file(Linked_list* list, char* FileName) {
    int size = sqrt(sqrt(list->Size()));
    ofstream File;
    File.open(FileName);
    if (!File.is_open()) {
        std::cout << "Открыть файл не удалось!\n";
        return 0;
    }
    std::cout << '\n';
    File << size << endl;
    for (int i = 0; i < size * size; i++) {
        for (int j = 0; j < size * size; j++) {
            File << list->at_index(i * size * size + j)->value;
        }
        File << endl;
    }
    File.close();
    return 1;
}

int main() {
    setlocale(0, "");
    system("cls");
    int symbol = 1;
    char* str = new char[1000];

    Linked_list* list = new Linked_list();

    while (symbol != 8) {
        system("cls");
        symbol = num_menu(list);
        switch (symbol) {
        case 1: {
            play_menu(list);
            break;
        }
        case 2: {
            create_array(list, 2);
            list->create_field(2);
            play_menu(list);
            break;
        }
        case 3: {
            create_array(list, 3);
            list->create_field(3);
            play_menu(list);
            break;
        }
        case 4: {
            cout << "Введите размерность поля(2 или 3)" << endl;
            int size;
            cin >> size;
            create_array(list, size);
            list->create_field(size);
            play_menu(list);
            for (int i = 0; i < list->Size(); i++) {
                list->at_index(i)->constanta = 1;
            }
            break;
        }
        case 5: {
            for (int i = 0; i < list->Size(); i++) {
                list->at_index(i)->constanta = 0;
            }
            play_menu(list);
            for (int i = 0; i < list->Size(); i++) {
                list->at_index(i)->constanta = 1;
            }
            break;
        }
        case 6: {
            system("cls");
            std::cout << "Сохранить текущую игру?(1-да, 0- нет)" << endl;
            str = read_path();
            write_file(list, str);
            std::cout << "Нажмите любую клавишу, чтобы открыть меню" << endl;
            _getch();
            system("cls");
            break;
        }
        case 7: {
            system("cls");
            std::cout << "Считать файл?(1-да, 0- нет)" << endl;
            str = read_path();
            read_file(list, str);
            std::cout << "Нажмите любую клавишу, чтобы открыть меню" << endl;
            _getch();
            system("cls");
            break;
        }
        }
    }
    return 0;
}