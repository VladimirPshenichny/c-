#include <iostream>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include <string>
#include <limits>
#include "Linked_list.h"

using namespace std;

void partition(char* equation, int i, stack* list){
    while (true)
    {

    }
}

int main() {
    setlocale(0, "");
    string equation;
    int i = 0;
    char cha;
    int count = 0;
    int count1;
    system("cls");
    cout << "Преобразователь инфиксной записи в префиксную." << endl;
    cout << "Разрешённые символы в исходном выражении : +, -, *, / , ^, sin, cos, (, ), 0, 1, 2, 3, 4, 5, 6, 7, 8, 9." << endl;
    cout << "Если скобка открывается пожалуйста закройте ее, sin( ) и cos( ) используте только со скобками." << endl;
    cout << "Введите выражение для преобразования: " << endl;
    cha = getchar();
    while (cha != '\n') {
        equation += cha;
        cha = getchar();
    }
    equation += '\0';
    while (equation[i] != '\0') {
        i++;
        if (equation[i] != ' ') {
            count++;
        }
    }
    char* ch = new char[count];
    char* ch1 = new char[count];
    count1 = count;
    while (i != 0) {
        i--;
        if (equation[i] != ' ') {
            count1--;
            ch[count1] = equation[i];
        }
    }
    stack* list = new stack();
    int j = 0;
    while (j < count) {
        if (isdigit(ch[j])) {
            ch1[i] = ch[j];
            i++;
        }
        else if (ch[j] == '(') {
            list->push(1, ch[j]);
        }
        else if (ch[j] == ')') {
            while (list->getHead() != '(') {
                ch1[i] = list->getHead();
                list->pop();
                i++;
            }
            list->pop();
        }
        else if (ch[j] == '+' || ch[j] == '-') {
            if (list->getValue() < 2) {
                list->push(1, ch[j]);
            }
            else {
                ch1[i] = list->getHead();
                list->pop();
                i++;
                list->push(1, ch[j]);
            }
        }
        else if (ch[j] == '*' || ch[j] == '/') {
            if (list->getValue() < 3) {
                list->push(2, ch[j]);
            }
            else {
                ch1[i] = list->getHead();
                list->pop();
                i++;
                list->push(2, ch[j]);
            }
        }
        else if (ch[j] == '^') {
            if (list->getValue() < 4) {
                list->push(3, ch[j]);
            }
            else {
                ch1[i] = list->getHead();
                list->pop();
                i++;
                list->push(3, ch[j]);
            }
        }
        else {
            ch1[i] = ch[j + 4];
            i++;
            ch1[i] = ch[j];
            j++;
            i++;
            ch1[i] = ch[j];
            j++;
            i++;
            ch1[i] = ch[j];
            j += 3;
            i++;
        }
        j++;
    }
    while (list->getHead() != 0) {
        ch1[i] = list->getHead();
        list->pop();
        i++;
    }
    for (int j = 0; j < i; j++) {
        cout << ch1[j];
    }
    cout << endl;
    return 0;
}
