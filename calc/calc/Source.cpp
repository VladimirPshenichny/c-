#include <iostream>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include <string>

using namespace std;

int num_menu(){
    int symbol = 1;
    while (true) {
        cout << "Лабораторная работа №2 калькулятор v2.0 работает для чисел, выполнил Пшеничный Владимир гр.0373\nДля передвижений по меню используйте стрелочки вверх, вниз или цифры которые используются для нумерации\nДля выбора необходимой функции используйте Enter" << endl;
        string arr[] = {"\t Меню",
            "1) Операция сложения",
            "2) Операция вычитание",
            "3) Операция деления",
            "4) Операция умножения",
            "5) ввод первого числа",
            "6) ввод второго числа",
            "7) выход"
        }; 
        for (int i = 0; i < 8; i++) {
            cout << arr[i];
            if (symbol == i)
                cout << "\t<--";
            cout << endl;
        }
        int But = getch();
        if (But == 224 || But == 0)
            But = getch();
        if (But == 72)
            if (symbol - 1 < 1)
                symbol = 7;
            else
                symbol--;
        else if (But == 80)
            if (symbol + 1 > 7)
                symbol = 1;
            else
                symbol++;
        else if (But == 13)
            break;
        else if (But - '0' >= 1 && But - '0' <= 7) {
            symbol = But - '0';
            break;
        }
        system("cls");
    }
    return symbol;
}

int main() {
    setlocale(0, "");
    int f = 0, l = 0;
    double first, last;
    while (true) {
        int symbol = num_menu();
        if(symbol == 5) {
            cout << "Введите первое число" << endl;
            cin >> first;
            f++;
            system("cls");
        }
         else if (symbol == 6) {
            cout << "Введите второе число" << endl;
            cin >> last;
            l++;
            system("cls");
        }
        else if (symbol == 7) {
                break;
        }
        else if (((f == 0) || (l == 0)) && (symbol < 5)) {
            cout << "Нельзя выполнить операцию без двух чисел, нажмите Enter" << endl;
            char but;
            do {
                but = getch();
            } while (but != 13);
            system("cls");
        }
        else {
            switch (symbol) {
                case 1: {
                    system("cls");
                    printf("Ответ: %lf\n", first + last);;
                    break;
                }
                case 2: {
                    system("cls");
                    printf("Ответ: %lf\n", first - last);
                    break;
                }
                case 3: {
                    system("cls");
                    printf("Ответ: %lf\n", first / last);
                    break;
                }
                case 4: {
                    system("cls");
                    printf("Ответ: %lf\n", first * last);
                    break;
                }
            }
        }
    }
    return 0;
}