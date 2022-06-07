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

int change(Linked_list* list, int But, int index) {
    if (But == 224 || But == 0) { But = _getch(); }
    if (But == 77) { index = list->change(1, index); }
    else if (But == 75) { index = list->change(2, index); }
    else if (But == 80) { index = list->change(3, index); }
    else if (But == 72) { index = list->change(4, index); }
    return index;
}

void create_array(Linked_list* list, int size_w, int size_l) 
{
    for (int i = 0; i < size_w * size_l; i++) { list->add_element(0, i); }
}

void print_game(Linked_list* list, int index){
    int size_w = 25 + 6;
    int size_l = 13 + 3;
    int check = 0;
    for (int i = 0; i < size_l; i++) 
    {
        for (int j = 0; j < size_w; j++) 
        {
            if (i > 2 && j > 2 && j < size_w - 3) 
            {
                if (check == index && (list->at_index(index)->value == 0)) 
                {
                    SetConsoleTextAttribute(hConsole, (WORD)((10 << 4) | 10));
                    std::cout << ' ';
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    check++;
                }
                else if (check == index && (list->at_index(check)->value == 1))
                {
                    SetConsoleTextAttribute(hConsole, (WORD)((4 << 4) | 4));
                    std::cout << ' ';
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    check++;
                }
                else if (check == index && (list->at_index(check)->value == 2))
                {
                    SetConsoleTextAttribute(hConsole, (WORD)((9 << 4) | 9));
                    std::cout << ' ';
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    check++;
                }
                else if ((list->at_index(check)->value == 1))
                {
                    SetConsoleTextAttribute(hConsole, (WORD)((12 << 4) | 10));
                    std::cout << ' ';
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    check++;
                }
                else if ((list->at_index(check)->value == 2))
                {
                    SetConsoleTextAttribute(hConsole, (WORD)((11 << 4) | 11));
                    std::cout << ' ';
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    check++;
                }
                else if ((list->at_index(check)->value == 3))
                {
                    SetConsoleTextAttribute(hConsole, (WORD)((6 << 4) | 6));
                    std::cout << ' ';
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    check++;
                }
                else  
                {
                    SetConsoleTextAttribute(hConsole, (WORD)((200 << 4) | 0));
                    std::cout << ' ';
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    check++;
                }
            }
            else if (i == 1 && j == 2) { std::cout << '/'; }
            else if ((i == 0) && (j > 2) && (j < (size_w - 3))) { std::cout << '_'; }
            else if (i == 1 && j == size_w - 3) { std::cout << '\\'; }
            else if ((i == size_l - 1) && ((j == 0) || (j == (size_w - 1)))) { std::cout << '_'; }
            else if ((i > 2) && ((j == 1) || (j == (size_w - 2)))) { std::cout << '|'; }
            else { std::cout << ' '; }
        }
        std::cout << endl;
    }
}

void swap(Linked_list* list, int size_w, int size_l, int index, int value){
    int index_s = index;
    int size_w_1, size_w_2;
    int size_l_1, size_l_2;
    if(size_w < index_s % 25)
    {
        size_w_1 = size_w;
        size_w_2 = index_s % 25;
    }
    else
    {
        size_w_2 = size_w;
        size_w_1 = index_s % 25;
    }
    if (size_w < index_s / 25)
    {
        size_l_1 = size_l;
        size_l_2 = index_s / 25;
    }
    else
    {
        size_l_2 = size_l;
        size_l_1 = index_s / 25;
    }
    for (int i = size_l_1; i <= size_l_2; i++) 
    {
        for (int j = size_w_1; j <= size_w_2; j++)
        {
            list->at_index(i * 25 + j)->value = value;
        }
    }
}

void spase(Linked_list* list, int index){
    int index_s = index;
    int size_w = index % 25;
    int size_l = index / 25;
    int a = 1;
    while (a == 1) {
        std::system("cls");
        std::cout << "Адимн мод.\nДля передвижения по неме исползуйте стрелочки, чтобы освободить, купить или забранировать билет нажмите Enter" << endl;
        print_game(list, index);
        swap(list, size_w, size_l, index_s, 0);
        int But = _getch();
        index_s = change(list, But, index_s);
        swap(list, size_w, size_l, index_s, 3);
        if (But == 13)
        {
            cout << "Освободить, купить или зарезервирова?(0, 1 или 2)" << endl;
            int val;
            val = _getch() - '0';
            for (int i = 0; i < 25 * 13; i++) 
            {
                if (list->at_index(i)->value == 3) { list->at_index(i)->value = val; }
            }
            a = 0;
        }
    }
}

void admin(Linked_list* list) {
    int pass;
    std::cout << "Введите пароль:\n";
    cin >> pass;
    if (pass == 1234)
    {
        std::system("cls");
        int a = 1;
        int index = 0;
        while (a == 1) {
            std::cout << "Адимн мод.\nДля передвижения по неме исползуйте стрелочки, чтобы освободить, купить или забранировать билет нажмите Enter.\nДля управления группаи нажмите Tab, для выхоа нажмите Esc" << endl;
            print_game(list, index);
            int But = _getch();
            index = change(list, But, index);
            if (But == 9) { spase(list, index); }
            else if (But == 13) 
            {
                cout << "Освободить, купить или зарезервирова?(0, 1 или 2)" << endl;
                int val;
                val = _getch() - '0';
                list->at_index(index)->value = val;
            }
            else if (But == 27) { a = 0; }
            std::system("cls");
        }
    }
    else
    {
        std::cout << "Пароль введен не выерно";
        _getch();
    }
    
}

void play_menu(Linked_list* list) {
    int a = 1;
    int index = 0;
    while (a == 1) {
        std::cout << "Добро пожанывать в приложении для покупки билетов на фильм 'Курсач на миллион'.\nДля передвижения по неме исползуйте стрелочки, чтобы купить или забранировать билет нажмите Enter, для выхоа нажмите Esc" << endl;
        print_game(list, index);
        int But = _getch();
        index = change(list, But, index);
        if (But == 13) { index = list->change(5,  index); }
        else if (But - '0' == 0) { admin(list); }
        else if (But == 27) {  a = 0; }
        std::system("cls");
    }
}

int main() 
{
    setlocale(0, "");
    std::system("cls");
    Linked_list* list = new Linked_list();
    create_array(list, 25, 13);
    list->create_field(25, 13);
    play_menu(list);
    return 0;
}