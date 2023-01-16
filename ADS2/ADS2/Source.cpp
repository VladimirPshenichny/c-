#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

//R - ������ �������
//massive - ������������� ��������� �� ������� �������
//minmassive - ����������� ������ ����������
//��������� ������������ ������� ����������
int getMinmassive(int R) {
	int r = 0;           // ���� ����� ��������� ����� ����� ���� �� ���� ���������, ������ 1 
	while (R >= 64) {
		r |= R & 1;
		R >>= 1;
	}
	return R + r;
}

//���������� ��������
void insertionSort(int Array[], int L, int R)  {
	for (int i = L + 1; i <= R; i++)
	{
		int temp = Array[i];
		int j = i - 1;
		while (j >= L && Array[j] > temp)
		{
			Array[j + 1] = Array[j];
			j--;
		}
		Array[j + 1] = temp;
	}
}

//���������� �����������
void merge(int Array[], int l, int m, int r) {
	//��������� ��������� �� ������ � ����� �����
	int len1 = m - l + 1; //������ ����� �����
	int len2 = r - m; //������ ������ ����� 
	int* left = new int[len1];
	int* right = new int[len2];
	for (int i = 0; i < len1; i++)
		left[i] = Array[l + i];
	for (int i = 0; i < len2; i++)
		right[i] = Array[m + 1 + i];

	int i = 0;
	int j = 0;
	int k = l;

	//����� ��������� ������������ ��� �������
	while (i < len1 && j < len2) {
		if (left[i] <= right[j]) {
			Array[k] = left[i];
			i++;
		}
		else {
			Array[k] = right[j];
			j++;
		}
		k++;
	}

	//���� �������� �������� � ����� �������, �������� �� 
	while (i < len1) { 
		Array[k] = left[i];
		k++;
		i++;
	}

	//���� �������� �������� � ������ �������, �������� ��
	while (j < len2) { 
		Array[k] = right[j];
		k++;
		j++;
	}
	delete[] left;
	delete[] right;
}

void timSort(int Array[], int R) {
	int minRun = getMinmassive(R);
	//���������� ����������� ������� MAS
	for (int i = 0; i < R; i += minRun) { 
		int min;
		if ((i + (minRun - 1)) >= (R - 1)) {
			min = R - 1;
		}
		else {
			min = i + (minRun - 1);
		}
		insertionSort(Array, i, min);
	}

	for (int size = minRun; size < R; size = 2 * size) {
		// �������� ����� ������ ������ ����������, ���������� Array[left..left+size-1] � Array[left+size, left+2*size-1] 
		// ����������� ����� ��������� �� 2*size ����� ������� �������

		for (int left = 0; left < R; left += 2 * size) {
			// ������� �������� ����� ������ ����������. mid+1 - ��������� ����� ������� ����������
			int min;
			if (((left + 2) * (size - 1)) >= (R - 1)) {
				min = R - 1;
			}
			else {
				min = (left + 2) * (size - 1);
			}
			int mid = left + size - 1;
			int right = min;

			merge(Array, left, mid, right); // ������� ���������� Array[left.....mid] � Array[mid+1....right]
		}
	}
}

void inputrandom() {
	cout << "������� ������ �������� ���������������� �������: ";
	int arrSize;
	cin >> arrSize;
	int* Array = new int[arrSize];
	for (int i = 0; i < arrSize; i++) {
		Array[i] = rand() % 10;
	}
	cout << "��������� ������: ";
	for (int i = 0; i < arrSize; i++) {
		cout << Array[i] << ' ';
	}
	timSort(Array, arrSize);
	cout << endl;
	cout << "��������������� ������: ";
	for (int i = 0; i < arrSize; i++) {
		cout << Array[i] << ' ';
	}
	_getch();
	delete[]Array;
}

void inputconsole() {
	cout << "������� ������ ������ �������: ";
	int arrSize;
	cin >> arrSize;
	int* Array = new int[arrSize];
	for (int i = 0; i < arrSize; i++) {
		cout << "Array[" << i << "] = ";
		cin >> Array[i];
	}
	cout << "��������� ������: ";
	for (int i = 0; i < arrSize; i++) {
		cout << Array[i] << ' ';
	}
	timSort(Array, arrSize);
	cout << endl;
	cout << "��������������� ������: ";
	for (int i = 0; i < arrSize; i++) {
		cout << Array[i] << ' ';
	}
	_getch();
	delete[]Array;
}


void menu() {
	system("cls");
	cout << "       ___________ " << endl;
	cout << "      |           |" << endl;
	cout << "      |  Tim$ort  |" << endl;
	cout << "      |___________|" << endl;
	cout << endl;
	cout << " ArrowUp  |  ��������� ������  |" << endl;
	cout << "ArrowDown | ����������� ������ |" << endl;
	cout << "   Esc    |       �����        |" << endl;
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	int answer;
	do {
		menu();
		answer = _getch();
		switch (answer) {
		case 72:
			inputrandom();
			break;
		case 80:
			inputconsole();
			break;
		case 27:
			break;
		}
	} while (answer != 27);
	return 0;
}