#include <iostream>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include <string>
#include <fstream>
#include "Build_list.h"
#include <stdio.h>
#include <Windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

void create_array(Build_list* list, int size) {
    for (int i = 0; i < size * size * 2; i++) {
        list->add_element(i+224, i);
    }
}

void show_game(Build_list* list, int index, int sym, char* word_open, int length) {
    int size(4), check(0);
    char print[9][9];
    char s[2];
    s[0] = 'r'+ sym;
    s[1] = '\0';
    string sr = string(s);
    ifstream File(sr);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            print[i][j] = File.get();
        }
        File.get();
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            std::cout << char(print[i][j]);
        std::cout << endl;
    }
    std::cout << endl << "Искомое слово: ";
    for (int i = 0; i < length; i++)
        std::cout << word_open[i];
    std::cout << endl << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size * 2; j++) {
            if (check == index) {
                SetConsoleTextAttribute(hConsole, (WORD)((195 << 4) | 10));
                std::cout << list->at_index(check)->value;
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                check++;
            }
            else {
                std::cout << list->at_index(check)->value;
                check++;
            }
        }
        std::cout << endl;
    }
}

bool win(char* word_open, int length) {
    int flag(0);
    for (int i = 0; i < length; i++)
        if (word_open[i] == '_')
            flag++;
    return flag;
}

void play_menu(Build_list* list, string word, char *word_open) {
    int a = 1;
    int sym(0);
    int index = 0;
    while (a == 1 && win(word_open, word.length()) && sym != 8) {
        int flag(0);
        std::system("cls");
        std::cout << "Салам, попробуй не подохни.\nДля передвижения исползуй стрелочки, чтобы попытать удачу нажмите Enter, для выхоа нажмите Esc" << endl;
        show_game(list, index, sym, word_open, word.length());
        int btn = _getch();
        if (btn == 224 || btn == 0)
            btn = _getch();
        if (btn == 77)
            index = list->move(1, index);
        else if (btn == 75)
            index = list->move(2, index);
        else if (btn == 80)
            index = list->move(3, index);
        else if (btn == 72)
            index = list->move(4, index);
        if (btn == 13) {
            if (list->at_index(index)->used != 1) {
                for (int i = 0; i < word.length(); i++)
                    if (list->at_index(index)->value == word[i]) {
                        word_open[i] = word[i];
                        flag++;
                    }
                if (flag == 0)
                    sym++;
                list->at_index(index)->used = 1;
                list->at_index(index)->value = ' ';
            }
        }
        else if (btn == 27) {
            a = 0;
        }
    }
    std::system("cls");
    if (a != 0) {
        show_game(list, index, sym, word_open, word.length());
        std::cout << endl;
    }
    if (sym == 8 && a != 0)
        std::cout << "соси писю";
    else if (a != 0)
        std::cout << "хорош";
    _getch();

}

int main() {
    std::system("cls");
    setlocale(0, "");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string word;
    char* word_open;
    cout << "Введи слово на русском:" << endl;
    cin >> word;
    word_open = new char(word.length());
    for (int i = 0; i < word.length(); i++)
        word_open[i] = '_';
    Build_list* list = new Build_list();
    create_array(list, 4);
    list->create_field(4);
    play_menu(list, word, word_open);
    return 0;
}