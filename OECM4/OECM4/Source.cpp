#include <bios.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{

	clrscr();	// ������� ������
	char key = 0;	// ���������� ��� ��������� ������

	// ���������� ����
	int X0 = 15;
	int X1 = 65;
	int Y0 = 5;
	int Y1 = 15;

	window(X0, Y0, X1, Y1);

	textbackground(4);	//	���� ��������� ����
	textcolor(14);		//	���� �������/������
	/*
	���� ������
	BLACK			������	 			0
	BLUE 			����� 				1
	GREEN 			������� 			2
	CYAN 			����-������� 		3
	RED 			�������				4
	MAGENTA 		������-����� 		5
	BROWN	 		���������� 			6
	LIGHTGRAY 		������-����� 		7
	DARKGRAY 	 	�����-����� 		8
	LIGHTBLUE 	 	����-����� 			9
	LIGHTGREEN		����-�������		10
	LIGHTCYAN	  	����� ����-�������	11
	LIGHTRED 		����-������� 		12
	LIGHTMAGENTA	����� ������-�����	13
	YELLOW	 		������	 			14
	WHITE  			����� 				15
	*/

	clrscr();

	int winWidth = X1 - X0 + 1;
	int winHeight = Y1 - Y0 + 1;

	int curX = 1, curY = 1;
	gotoxy(curX, curY);

	printf("r");
	gotoxy(curX, curY);

	while (key != 39)
	{
		key = 0;
		unsigned int temp = 0;
		while (kbhit() == 0);
		temp = getch();

		clrscr();

		switch (temp)
		{
		case 77:	// ������ F6
			gotoxy(curX, curY);
			clrscr();
			--curX;
			if (curX == 0)	// �������� �� ����� �����
			{
				curX = winWidth;
				--curY;
			}
			if (curY == 0)
				curY = winHeight;
			gotoxy(curX, curY);
			printf("r");
			break;
		case 224://������ F12
			gotoxy(curX, curY);
			clrscr();
			++curX;
			if (curX == winWidth + 1)	// �������� �� ����� �����
			{
				curX = 1;
				++curY;
			}
			if (curY == winHeight + 1)	// �� ��������������� ������
				curY = 1;
			gotoxy(curX, curY);   //������ ������� �� ����������� �,y
			printf("r");
			break;
		case 75:	// ������ F12
			gotoxy(curX, curY);
			clrscr();
			++curX; // �� ������� ������� ������ ���������� �� ���� ��� ������
			if (curX == winWidth + 1)
			{
				curX = 1;
				++curY;
			}
			if (curY == winHeight + 1)
				curY = 1;
			gotoxy(curX, curY);
			printf("r");
			break;
		default: continue; break;
			break;
		}
	}
}