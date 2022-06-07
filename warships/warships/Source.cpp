#include <iostream>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include <string>
#include <fstream>
#include "Create_list.h"
#include <stdio.h>
#include <Windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

void create_array(Create_list* list, int size) {
    for (int i = 0; i < size * size; i++) {
        list->add_element(0, i);
    }
}

int change(Create_list* list, int btn, int index) {
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
    return index;
}

void draw_field(Create_list* list, int index) {
    int size = 11;
    int check = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != 0 && j != 0) {
                if (check == index && (list->at_index(check)->value == 0)) {
                    SetConsoleTextAttribute(hConsole, (WORD)((9 << 4) | 9));
                    std::cout << ' ';
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    check++;
                }
                else if (check == index && (list->at_index(check)->value == 1)) {
                    SetConsoleTextAttribute(hConsole, (WORD)((14 << 4) | 14));
                    std::cout << ' ';
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    check++;
                }
                else if ((list->at_index(check)->value == 0)) {
                    SetConsoleTextAttribute(hConsole, (WORD)((219 << 4) | 2));
                    std::cout << ' ';
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    check++;
                }
                else if ((list->at_index(check)->value == 1)) {
                    SetConsoleTextAttribute(hConsole, (WORD)((134 << 4) | 24));
                    std::cout << ' ';
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    check++;
                }
            }
            else if (j == 0 && i != 0 && i != 10)
                std::cout << ' ' << i;
            else if (j == 0 && i == 10)
                std::cout << i;
            else if (j != 0 && i == 0 && j != 10)
                std::cout << char(j + 223);
            else if (i == 0 && j == 10)
                std::cout << char(j + 224);
            else
                std::cout << ' ' << ' ';
        }
        std::cout << endl;
    }
}

void show_game(Create_list* list, int index) {
    int size = 11;
    int check = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != 0 && j != 0) {
                if (check == index && (list->at_index(check)->value == 0)) {
                    SetConsoleTextAttribute(hConsole, (WORD)((9 << 4) | 9));
                    std::cout << ' ';
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    check++;
                }
                else if (check == index && (list->at_index(check)->value == 1)) {
                    SetConsoleTextAttribute(hConsole, (WORD)((9 << 4) | 9));
                    std::cout << ' ';
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    check++;
                }
                else if (check == index && (list->at_index(check)->value == 2)) {
                    SetConsoleTextAttribute(hConsole, (WORD)((14 << 4) | 14));
                    std::cout << ' ';
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    check++;
                }
                else if (check == index && (list->at_index(check)->value == 3)) {
                    SetConsoleTextAttribute(hConsole, (WORD)((13 << 4) | 13));
                    std::cout << ' ';
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    check++;
                }
                else if ((list->at_index(check)->value == 0)) {
                    SetConsoleTextAttribute(hConsole, (WORD)((219 << 4) | 2));
                    std::cout << ' ';
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    check++;
                }
                else if ((list->at_index(check)->value == 1)) {
                    SetConsoleTextAttribute(hConsole, (WORD)((219 << 4) | 2));
                    std::cout << ' ';
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    check++;
                }
                else if ((list->at_index(check)->value == 2)) {
                    SetConsoleTextAttribute(hConsole, (WORD)((134 << 4) | 24));
                    std::cout << ' ';
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    check++;
                }
                else if ((list->at_index(check)->value == 3)) {
                    SetConsoleTextAttribute(hConsole, (WORD)((12 << 4) | 12));
                    std::cout << ' ';
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    check++;
                }
            }
            else if (j == 0 && i != 0 && i != 10)
                std::cout << ' ' << i;
            else if (j == 0 && i == 10)
                std::cout << i;
            else if (j != 0 && i == 0 && j != 10)
                std::cout << char(j + 223);
            else if (i == 0 && j == 10)
                std::cout << char(j + 224);
            else
                std::cout << ' ' << ' ';
        }
        std::cout << endl;
    }
}

bool create_ships(Create_list* list){
    int a = 1;
    int index = 0;
    int count = 0;
    while (a == 1 && count != 20) {
        std::cout << "Морской бой.\nДля передвижения по неме исползуйте стрелочки, создать корабль Enter, для выхоа нажмите Esc" << endl;
        std::cout << "Нужно нарисовать 1 - четырехпалубник, 2 - трехпалубника, 3 - двухпалубника и 4 - однапулубника"<< endl;
        std::cout << "Все большие корабли рисуются строго по прямой и никакой корабль не должен соприкасаться с другим кораблем"<< endl;
        draw_field(list, index);
        int btn = _getch();
        index = change(list, btn, index);
        if (btn == 13) {
            if (list->at_index(index)->value == 0) {
                list->at_index(index)->value = 1;
                count++;
            }
        }
        else if (btn == 27) {
            a = 0;
            return 0;
        }
        std::system("cls");
    }
    return 1;
}

bool play_menu(Create_list* list, int *count) {
    int a = 1;
    int index = 0;
    while (a == 1 && (*count) != 0) {
        std::system("cls");
        std::cout << "Морской бой.\nДля передвижения по неме исползуйте стрелочки, чтобы попытать удачу нажмите Enter, для выхоа нажмите Esc" << endl;
        show_game(list, index);
        int btn = _getch();
        index = change(list, btn, index);
        if (btn == 13) {
            if (list->at_index(index)->value == 1) {
                list->at_index(index)->value = 2;
                (*count)--;
            }
            else if (list->at_index(index)->value == 0) {
                list->at_index(index)->value = 3;
                a = 0;
            }
        }
        else if (btn == 27) {
            a = 0;
            return 0;
        }
    }
    if ((*count) == 0) {
        std::system("cls");
        show_game(list, 101);
        std::cout << "Поздравляю, ты выбил все корабли соперника";
        _getch();
        return 0;
    }
    else {
        std::system("cls");
        show_game(list, 101);
        std::cout << "Мимо, передай ход другому игроку";
        _getch();
        return 1;
    }
}

int main() {
    setlocale(0, "");
    int *count_1 = new int;
    int *count_2 = new int;
    *count_1 = *count_2 = 20;
    bool flag;
    std::system("cls");
    Create_list* list_1 = new Create_list();
    create_array(list_1, 10);
    list_1->create_field(10);
    Create_list* list_2 = new Create_list();
    create_array(list_2, 10);
    list_2->create_field(10);
    flag = create_ships(list_1);
    if (flag)
        flag = create_ships(list_2);
    while (flag) {
        flag = play_menu(list_2, count_2);
        if(flag)
            flag = play_menu(list_1, count_1);
    }
    return 0;
}