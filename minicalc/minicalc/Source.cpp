#include <iostream>
#include <conio.h>

using namespace std;

int sum(int& first, int last) {
	return first + last;
}

int subtraction(int* first, int last) {
	return *first - last;
}

int division(int first, int* last) {
	return first / (*last);
}

int multiplication(int* first, int& last) {
	return (*first) * last;
}

int main() {
	setlocale(0, "");
    int *first = new int;
    int last;
	int result;
	int symbol = 0;
	while (symbol != 5) {
		cout << "1) Сумма;\n2) Разность;\n3) Деление(нацело);\n4) Перемножение;\n5) Выход.\nВведите числа, затем номер операции(ввести 3 числа надо всегда(даже если хотите выйти))" << endl;
		cin >> *first >> last >> symbol;
		switch (symbol) {
			case 1: {
				result = sum(*first, last);
				break;
			}
			case 2: {
				result = subtraction(first, last);
				break;
			}
			case 3: {
				if ((symbol == 3) && (&last == 0)) {
					printf("На ноль делить нельзя");
					return 0;
				}
				else
					result = division(*first, &last);
				break;
			}
			case 4: {
				result = multiplication(first, last);
				break;
			}
		}
		if(symbol != 5)
			cout << result << endl;
		cout << "Нажмите любую кнопку" << endl;
		_getch();
		system("cls");
	}
    return 0;
}