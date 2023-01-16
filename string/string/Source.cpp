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
        cout << "������������ ������ �4 �������� �����, �������� ��������� �������� ��.0373\n��� ������������ �� ���� ����������� ��������� �����, ���� ��� ����� ������� ������������ ��� ���������\n��� ������ ����������� ������� ����������� Enter ��� �� Esc ��� ������" << endl;
        char arr[7][256] = { "\t ����",
            "1) ��������� 1-�� ������",
            "2) ����������� ������ � ������",
            "3) ���������� ������ ������ � ������",
            "4) �������� 1-�� ������",
            "5) ��������� �����",
            "6) �����"
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
    cout << "������� ����� � ������ ������ ����� ������" << endl;
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
    cout << "������� ����� ������ �������" << endl;
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
        cout << "������ ����������" << endl;
    else
        cout << "������ ��������" << endl;
}

void print(char *first, char last[256]){
    cout << "������ ������: " << first << "; ������ ������: " << last << endl << endl;
}