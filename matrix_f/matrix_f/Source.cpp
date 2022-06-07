#include <iostream>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

int num_menu(int h_size, int w_size); 
int **create_array(int h_size, int w_size);
void print_array(int h_size, int w_size, int** double_array);
char *read_path();
bool save_in_file(int h_size, int w_size, int **double_array);
bool  read_file(char* FileName);

int main() {
    setlocale(0, "");
    int w_size = 1, h_size = 1;
    int count = 1;
    while (count) {
        int symbol = num_menu(h_size, w_size);
        if (symbol == 9) {
            count = 0;
        }
        else {
            int **double_array = create_array(h_size, w_size);
            switch (symbol) {
                case 1: {
                    system("cls");
                    int i = 0;
                    int j = 0;
                    int num_of_loops = 0;
                    int countNumb = 1;
                    while (h_size > 2 * num_of_loops && w_size > 2 * num_of_loops) {
                        for (i = j; i < w_size - num_of_loops; i++) {
                            double_array[j][i] = countNumb;
                            countNumb++;
                        }
                        i--;
                        for (j = j + 1; j < h_size - num_of_loops; j++) {
                            double_array[j][i] = countNumb;
                            countNumb++;
                        }
                        j--;
                        for (i = i - 1; i >= num_of_loops; i--) {
                            if (countNumb < h_size* w_size + 1) {
                                double_array[j][i] = countNumb;
                                countNumb++;
                            }
                        }
                        i++;
                        for (j = j - 1; j > num_of_loops; j--) {
                            if (countNumb < h_size * w_size + 1) {
                                double_array[j][i] = countNumb;
                                countNumb++;
                            }
                        }
                        j++;
                        num_of_loops++;
                    }
                    print_array(h_size, w_size, double_array);
                    cout << "Нажмите любую клавишу, чтобы открыть меню" << endl;
                    _getch();
                    system("cls");
                    break;
                }
                case 2: {
                    system("cls");
                    int i = 0;
                    int j = 0;
                    int num_of_loops = 0;
                    int countNumb = 1;
                    while (h_size > 2 * num_of_loops && w_size > 2 * num_of_loops) {
                        for (j = i; j < h_size - num_of_loops; j++) {
                            double_array[j][i] = countNumb;
                            countNumb++;
                        }
                        j--;
                        for (i = i + 1; i < w_size - num_of_loops; i++) {
                            double_array[j][i] = countNumb;
                            countNumb++;
                        }
                        i--;
                        for (j = j - 1; j >= num_of_loops; j--) {
                            if (countNumb < h_size* w_size + 1) {
                                double_array[j][i] = countNumb;
                                countNumb++;
                            }
                        }
                        j++;
                        for (i = i - 1; i > num_of_loops; i--) {
                            if (countNumb < h_size * w_size + 1) {
                                double_array[j][i] = countNumb;
                                countNumb++;
                            }
                        }
                        i++;
                        num_of_loops++;
                    }
                    print_array(h_size, w_size, double_array);
                    cout << "Нажмите любую клавишу, чтобы открыть меню" << endl;
                    _getch();
                    system("cls");
                    break;
                }
                case 3: {
                    system("cls");
                    int i = 0;
                    int j = 0;
                    int num_of_loops = 0;
                    int countNumb = h_size * w_size;
                    while (h_size > 2 * num_of_loops && w_size > 2 * num_of_loops) {
                        for (j = i; j < h_size - num_of_loops; j++) {
                            double_array[j][i] = countNumb;
                            countNumb--;
                        }
                        j--;
                        for (i = i + 1; i < w_size - num_of_loops; i++) {
                            double_array[j][i] = countNumb;
                            countNumb--;
                        }
                        i--;
                        for (j = j - 1; j >= num_of_loops; j--) {
                            if (countNumb > 0) {
                                double_array[j][i] = countNumb;
                                countNumb--;
                            }
                        }
                        j++;
                        for (i = i - 1; i > num_of_loops; i--) {
                            if (countNumb > 0) {
                                double_array[j][i] = countNumb;
                                countNumb--;
                            }
                        }
                        i++;
                        num_of_loops++;
                    }
                    print_array(h_size, w_size, double_array);
                    cout << "Нажмите любую клавишу, чтобы открыть меню" << endl;
                    _getch();
                    system("cls");
                    break;
                }
                case 4: {
                    system("cls");
                    int i = 0;
                    int j = 0;
                    int num_of_loops = 0;
                    int countNumb = h_size * w_size;
                    while (h_size > 2 * num_of_loops && w_size > 2 * num_of_loops) {
                        for (i = j; i < w_size - num_of_loops; i++) {
                            double_array[j][i] = countNumb;
                            countNumb--;
                        }
                        i--;
                        for (j = j + 1; j < h_size - num_of_loops; j++) {
                            double_array[j][i] = countNumb;
                            countNumb--;
                        }
                        j--;
                        for (i = i - 1; i >= num_of_loops; i--) {
                            if (countNumb > 0) {
                                double_array[j][i] = countNumb;
                                countNumb--;
                            }
                        }
                        i++;
                        for (j = j - 1; j > num_of_loops; j--) {
                            if (countNumb > 0) {
                                double_array[j][i] = countNumb;
                                countNumb--;
                            }
                        }
                        j++;
                        num_of_loops++;
                    }
                    print_array(h_size, w_size, double_array);
                    cout << "Нажмите любую клавишу, чтобы открыть меню" << endl;
                    _getch();
                    system("cls");
                    break;
                }
                case 5: {
                    system("cls");
                    if (w_size < 15)
                        w_size++;
                    else {
                        system("cls");
                        cout << "Невозможное изменение, нажмите любую клавишу, чтобы открыть меню" << endl;
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
                        cout << "Невозможное изменение, нажмите любую клавишу, чтобы открыть меню" << endl;
                        _getch();
                    }
                    break;
                }
                case 7: {
                    system("cls");
                    if (h_size < 15)
                        h_size++;
                    else {
                        system("cls");
                        cout << "Невозможное изменение, нажмите любую клавишу, чтобы открыть меню" << endl;
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
                        cout << "Невозможное изменение, нажмите любую клавишу, чтобы открыть меню" << endl;
                        _getch();
                    }
                    break;
                }
                case 0: {
                    system("cls");
                    char *str = new char[1000];
                    cout << "Считать файл?(1-да, 0- нет)" << endl;
                    str = read_path();
                    read_file(str);
                    cout << "Нажмите любую клавишу, чтобы открыть меню" << endl;
                    _getch();
                    system("cls");
                    break;
                }
            }
        }
    }
    return 0;
}

int num_menu(int h_size, int w_size) {
    int symbol = 1;
    int count = 1;
    while (count) {
        cout << "Лабораторная работа №5 создание и сохранение спиралей, выполнил Пшеничный Владимир гр.0373\nДля передвижений по меню используйте стрелочки вверх, вниз или цифры которые используются для нумерации\nДля выбора необходимой функции используйте Enter так же Esc для выхода" << endl;
        cout << "\nРазмер спиральной матрицы " << h_size << " : " << w_size << endl;
        string arr[] = { "\n\t Меню",
            "1) Спираль к центра по часовой стрелке",
            "2) Спираль к центра против часовой стрелки",
            "3) Спираль от центру по часовой стрелке",
            "4) Спираль от центру против часовой стрелки",
            "5) Увеличить размер спирали по горизонтали",
            "6) Уменьшить размер спирали по горизонтали",
            "7) Увеличить размер спирали по вертикали",
            "8) Уменьшить размер спирали по вертикали",
            "9) Выход",
            "0) Считать из файла"
        };
        for (int i = 0; i < 11; i++) {
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
                symbol = 10;
            else
                symbol--;
        else if (But == 80)
            if (symbol + 1 > 10)
                symbol = 1;
            else
                symbol++;
        else if (But == 13)
            count = 0;
        else if (But == 27)
            return 9;
        else if (But - '0' >= 0 && But - '0' <= 9) {
            symbol = But - '0';
            count = 0;
        }
        system("cls");
    }
    return symbol;
}

int **create_array(int h_size, int w_size){
    int **double_array;
    double_array = new int* [h_size];
    for (int i = 0; i < h_size; i++)
        double_array[i] = new int[w_size];
    for (int i = 0; i < h_size; i++)
        for (int j = 0; j < w_size; j++)
            double_array[i][j] = 0;
    return double_array;
}

void print_array(int h_size, int w_size, int** double_array) {
    for (int i = 0; i < h_size; i++) {
        for (int j = 0; j < w_size; j++) {
            cout << double_array[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "Сохранить в файл?(1-да, 0- нет)" << endl;
    save_in_file(h_size, w_size, double_array);
}

char *read_path() {
    char *str;
    str = new char[1000];
    for (int i = 0; i < 1000; i++) {
        str[i] = '0';
    }
    if (_getch() == 49) {
        cout << "Напишите путь и имя вайла с расширением. Пример 'c:\\t.txt':\n";
        cin >> str;
        int i = 0;
        while (str[i] != '0') {
            i++;
        }
        str[i - 1] = '\0';
    }
    return str;
}

bool save_in_file(int h_size, int w_size, int** double_array) {
    char *str = read_path();
    ofstream File;
    File.open(str);
    if (!File.is_open()) {
        cout << "Открыть файл не удалось! \n";
        return 0;
    }
    for (int i = 0; i < h_size; i++) {
        for (int j = 0; j < w_size; j++) {
            File << double_array[i][j] << "\t";
        }
        File << "\n";
    }
    File.close();
    cout << "Файл сохранен\n";
    return 1;
}


bool  read_file(char* FileName){
    ifstream File;
    File.open(FileName);
    if (!File.is_open()){
        cout << "Открыть файл не удалось!\n";
        return 0;
    }
    char S[225];
    cout << '\n';
    while (!File.eof()){
        File.getline(S, 225);
        cout << S << endl;
    }
    File.close();
    return 1;
}