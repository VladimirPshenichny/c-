#include <iostream>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include <string>

using namespace std;

int num_menu(){
    int symbol = 1;
    while (true) {
        cout << "������������ ������ �2 ����������� v2.0 �������� ��� �����, �������� ��������� �������� ��.0373\n��� ������������ �� ���� ����������� ��������� �����, ���� ��� ����� ������� ������������ ��� ���������\n��� ������ ����������� ������� ����������� Enter" << endl;
        string arr[] = {"\t ����",
            "1) �������� ��������",
            "2) �������� ���������",
            "3) �������� �������",
            "4) �������� ���������",
            "5) ���� ������� �����",
            "6) ���� ������� �����",
            "7) �����"
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
            cout << "������� ������ �����" << endl;
            cin >> first;
            f++;
            system("cls");
        }
         else if (symbol == 6) {
            cout << "������� ������ �����" << endl;
            cin >> last;
            l++;
            system("cls");
        }
        else if (symbol == 7) {
                break;
        }
        else if (((f == 0) || (l == 0)) && (symbol < 5)) {
            cout << "������ ��������� �������� ��� ���� �����, ������� Enter" << endl;
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
                    printf("�����: %lf\n", first + last);;
                    break;
                }
                case 2: {
                    system("cls");
                    printf("�����: %lf\n", first - last);
                    break;
                }
                case 3: {
                    system("cls");
                    printf("�����: %lf\n", first / last);
                    break;
                }
                case 4: {
                    system("cls");
                    printf("�����: %lf\n", first * last);
                    break;
                }
            }
        }
    }
    return 0;
}