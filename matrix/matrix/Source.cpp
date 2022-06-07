#include <iostream>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include <string>

using namespace std;

void print_arr(int d_arr);

int num_menu(int h_size, int w_size) {
    int symbol = 1;
    while (true) {
        cout << "������������ ������ �3 �������� ��������, �������� ��������� �������� ��.0373\n��� ������������ �� ���� ����������� ��������� �����, ���� ��� ����� ������� ������������ ��� ���������\n��� ������ ����������� ������� ����������� Enter ��� �� Esc ��� ������" << endl;
        cout << "\n������ ���������� ������� "<< h_size << " : " << w_size << endl;
        string arr[] = { "\n\t ����",
            "1) ������� � ������ �� ������� �������",
            "2) ������� � ������ ������ ������� �������",
            "3) ������� �� ������ �� ������� �������",
            "4) ������� �� ������ ������ ������� �������",
            "5) ��������� ������ ������� �� �����������",
            "6) ��������� ������ ������� �� �����������",
            "7) ��������� ������ ������� �� ���������",
            "8) ��������� ������ ������� �� ���������",
            "9) �����"
        };
        for (int i = 0; i < 10; i++) {
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
                symbol = 9;
            else
                symbol--;
        else if (But == 80)
            if (symbol + 1 > 9)
                symbol = 1;
            else
                symbol++;
        else if (But == 13)
            break;
        else if (But == 27)
            return 9;
        else if (But - '0' >= 1 && But - '0' <= 9) {
            symbol = But - '0';
            break;
        }
        system("cls");
    }
    return symbol;
}

int main() {
    setlocale(0, "");
    int w_size = 1, h_size = 1;
    int d_arr[10][10];
    int a = 1;
    while (a) {
        int symbol = num_menu(h_size, w_size);
        if (symbol == 9) {
            a = 0;
        }
        else {
            switch (symbol) {
                case 1: {
                    system("cls");
                    int i = 0;
                    int j = 0;
                    int k = 0;
                    int countNumb = 1;
                    while (h_size > 2 * k && w_size > 2 * k) {
                        for (i = j; i < w_size - k; i++){
                            d_arr[j][i] = countNumb;
                            countNumb++;
                        }
                        i--;
                        for (j = j + 1; j < h_size - k; j++) {
                            d_arr[j][i] = countNumb;
                            countNumb++;
                        }
                        j--;
                        for (i = i -1 ; i >= k; i--) {
                            if (countNumb < h_size* w_size + 1) {
                                d_arr[j][i] = countNumb;
                                countNumb++;
                            }
                        }
                        i++;
                        for (j = j - 1; j > k; j--) {
                            if (countNumb < h_size * w_size + 1) {
                                d_arr[j][i] = countNumb;
                                countNumb++;
                            }   
                        }
                        j++;
                        k++;
                    }
                    for (i = 0; i < h_size; i++) {
                        for (j = 0; j < w_size; j++) {
                            cout << d_arr[i][j] << "\t";
                        }
                        cout << "\n";
                    }
                    cout << "������� ����� �������, ����� ������� ����" << endl;
                    _getch();
                    system("cls");
                    break;
                }
                case 2: {
                    system("cls");
                    int i = 0;
                    int j = 0;
                    int k = 0;
                    int countNumb = 1;
                    while (h_size > 2 * k && w_size > 2 * k) {
                        for (j = i; j < h_size - k; j++) {
                            d_arr[j][i] = countNumb;
                            countNumb++;
                        }
                        j--;
                        for (i = i + 1; i < w_size - k; i++) {
                            d_arr[j][i] = countNumb;
                            countNumb++;
                        }
                        i--;
                        for (j = j - 1; j >= k; j--) {
                            if (countNumb < h_size* w_size + 1) {
                                d_arr[j][i] = countNumb;
                                countNumb++;
                            }
                        }
                        j++;
                        for (i = i - 1; i > k; i--) {
                            if (countNumb < h_size * w_size + 1) {
                                d_arr[j][i] = countNumb;
                                countNumb++;
                            }
                        }
                        i++;
                        k++;
                    }
                    for (i = 0; i < h_size; i++) {
                        for (j = 0; j < w_size; j++) {
                            cout << d_arr[i][j] << "\t";
                        }
                        cout << "\n";
                    }
                    cout << "������� ����� �������, ����� ������� ����" << endl;
                    _getch();
                    system("cls");
                    break;
                }
                case 3: {
                    system("cls");
                    int i = 0;
                    int j = 0;
                    int k = 0;
                    int countNumb = h_size * w_size;
                    while (h_size > 2 * k && w_size > 2 * k) {
                        for (j = i; j < h_size - k; j++) {
                            d_arr[j][i] = countNumb;
                            countNumb--;
                        }
                        j--;
                        for (i = i + 1; i < w_size - k; i++) {
                            d_arr[j][i] = countNumb;
                            countNumb--;
                        }
                        i--;
                        for (j = j - 1; j >= k; j--) {
                            if (countNumb > 0) {
                                d_arr[j][i] = countNumb;
                                countNumb--;
                            }
                        }
                        j++;
                        for (i = i - 1; i > k; i--) {
                            if (countNumb > 0) {
                                d_arr[j][i] = countNumb;
                                countNumb--;
                            }
                        }
                        i++;
                        k++;
                    }
                    for (i = 0; i < h_size; i++) {
                        for (j = 0; j < w_size; j++) {
                            cout << d_arr[i][j] << "\t";
                        }
                        cout << "\n";
                    }
                    cout << "������� ����� �������, ����� ������� ����" << endl;
                    _getch();
                    system("cls");
                    break;
                }
                case 4: {
                    system("cls");
                    int i = 0;
                    int j = 0;
                    int k = 0;
                    int countNumb = h_size * w_size;
                    while (h_size > 2 * k && w_size > 2 * k) {
                        for (i = j; i < w_size - k; i++) {
                            d_arr[j][i] = countNumb;
                            countNumb--;
                        }
                        i--;
                        for (j = j + 1; j < h_size - k; j++) {
                            d_arr[j][i] = countNumb;
                            countNumb--;
                        }
                        j--;
                        for (i = i - 1; i >= k; i--) {
                            if (countNumb > 0) {
                                d_arr[j][i] = countNumb;
                                countNumb--;
                            }
                        }
                        i++;
                        for (j = j - 1; j > k; j--) {
                            if (countNumb > 0) {
                                d_arr[j][i] = countNumb;
                                countNumb--;
                            }
                        }
                        j++;
                        k++;
                    }
                    for (i = 0; i < h_size; i++) {
                        for (j = 0; j < w_size; j++) {
                            cout << d_arr[i][j] << "\t";
                        }
                        cout << "\n";
                    }
                    cout << "������� ����� �������, ����� ������� ����" << endl;
                    _getch();
                    system("cls");
                    break;
                }
                case 5: {
                    system("cls");
                    if( w_size < 10)
                        w_size++;
                    else {
                        system("cls");
                        cout << "����������� ���������, ������� ����� �������, ����� ������� ����" << endl;
                        _getch();
                    }
                    break;
                }
                case 6: {
                    system("cls");
                    if (w_size > 1)
                        w_size--;
                    else {
                        system("cls");
                        cout << "����������� ���������, ������� ����� �������, ����� ������� ����" << endl;
                        _getch();
                    }
                    break;
                }
                case 7: {
                    system("cls");
                    if (h_size < 10)
                        h_size++;
                    else {
                        system("cls");
                        cout << "����������� ���������, ������� ����� �������, ����� ������� ����" << endl;
                        _getch();
                    }
                    break;
                }
                case 8: {
                    system("cls");
                    if (h_size > 1)
                        h_size--;
                    else {
                        system("cls");
                        cout << "����������� ���������, ������� ����� �������, ����� ������� ����" << endl;
                        _getch();
                    }
                    break;
                }
            }
        }
    }
    return 0;
}