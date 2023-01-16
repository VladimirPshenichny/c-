#include <iostream>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include <string>

using namespace std;

void rewriting(char *first);
void my_strcat(char *first, char last[256]);
void my_strcpy(char *first, char last[256]);
void del(char *first, char last[256]);
void my_strcmp(char *first, char last[256]);
void print(char *first, char last[256]);

int num_menu() {
    int symbol = 1;
    int a = 1;
    while (a) {
        cout << "Лабораторная работа №4 редактор строк, выполнил Пшеничный Владимир гр.0373\nДля передвижений по меню используйте стрелочки вверх, вниз или цифры которые используются для нумерации\nДля выбора необходимой функции используйте Enter так же Esc для выхода" << endl;
        char arr[7][256] = { "\t Меню",
            "1) Изменение 1-ой строки",
            "2) Копирование строки в строку",
            "3) Перезапись второй строки в первую",
            "4) Удаление 1-ой строки",
            "5) Сравнение строк",
            "6) выход"
        };
        for (int i = 0; i < 7; i++) {
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
                symbol = 6;
            else
                symbol--;
        else if (But == 80)
            if (symbol + 1 > 6)
                symbol = 1;
            else
                symbol++;
        else if (But == 13)
            a = 0;
        else if (But == 27)
            return 6;
        else if (But - '0' >= 1 && But - '0' <= 6) {
            symbol = But - '0';
            a = 0;
        }
        system("cls");
    }
    return symbol;
}

int main() {
    setlocale(0, "");
    char first[256] = "";
    char last[256];
    cout << "Введите перую и вторую строгу через пробел" << endl;
    cin >> first >> last;
    system("cls");
    int a = 1;
    while (a) {
        int symbol = num_menu();
        if (symbol == 6) {
            a = 0;
        }
        else {
            switch (symbol) {
                case 1: {
                    rewriting(first);
                    system("cls");
                    print(first, last);
                    break;
                }
                case 2: {
                    system("cls");
                    my_strcat(first, last);
                    print(first, last);
                    break;
                }
                case 3: {
                    system("cls");
                    my_strcpy(first, last);
                    print(first, last);
                    break;
                }
                case 4: {
                    system("cls");
                    del(first, last);
                    print(first, last);
                    break;
                }
                case 5: {
                    system("cls");
                    my_strcmp(first, last);
                    print(first, last);
                    break;
                }
            }
        }
    }
    return 0;
}

void rewriting(char *first){
    cout << "Введите новую первую строчку" << endl;
    cin >> first;
}

void my_strcat(char* first, char last[256]) {
    int i = 0;
    int j = 0;
    while (first[j] != '\0') {
        j++;
    }
    while (last[i] != '\0'){
        first[j] = last[i];
        i++;
        j++;
    }
    first[j] = last[i];
}

void my_strcpy(char *first, char last[256]) {
    int i = 0;
    while (last[i] != '\0') {
        first[i] = last[i];
        i++;
    }
    first[i] = last[i];
}

void del(char *first, char last[256]){
    first[0] = '\0';
}

void my_strcmp(char *first, char last[256]){
    int i = 0;
    int a = 1;
    while (last[i] != '\0' && first[i] != '\0' && a != 0) {
        if (first[i] == last[i])
            i++;
        else
            a = 0;
    }
    if (last[i] == '\0' && first[i] == '\0')
        cout << "Строки одинаковые" << endl;
    else
        cout << "Строки различны" << endl;
}

void print(char *first, char last[256]){
    cout << "Первая строки: " << first << "; Вторая строки: " << last << endl << endl;
}