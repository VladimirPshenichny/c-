#include <bios.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{

	clrscr();	// очистка экрана
	char key = 0;	// переменна€ дл€ состо€ни€ кнопки

	// координаты окна
	int X0 = 15;
	int X1 = 65;
	int Y0 = 5;
	int Y1 = 15;

	window(X0, Y0, X1, Y1);

	textbackground(4);	//	цвет заданного окна
	textcolor(14);		//	цвет символа/текста
	/*
	коды цветов
	BLACK			черный	 			0
	BLUE 			синий 				1
	GREEN 			зеленый 			2
	CYAN 			сине-зеленый 		3
	RED 			красный				4
	MAGENTA 		красно-синий 		5
	BROWN	 		коричневый 			6
	LIGHTGRAY 		светло-серый 		7
	DARKGRAY 	 	темно-серый 		8
	LIGHTBLUE 	 	€рко-синий 			9
	LIGHTGREEN		€рко-зеленый		10
	LIGHTCYAN	  	€ркий сине-зеленый	11
	LIGHTRED 		€рко-красный 		12
	LIGHTMAGENTA	€ркий красно-синий	13
	YELLOW	 		желтый	 			14
	WHITE  			белый 				15
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
		case 77:	// нажали F6
			gotoxy(curX, curY);
			clrscr();
			--curX;
			if (curX == 0)	// проверка на конец рамки
			{
				curX = winWidth;
				--curY;
			}
			if (curY == 0)
				curY = winHeight;
			gotoxy(curX, curY);
			printf("r");
			break;
		case 224://нажали F12
			gotoxy(curX, curY);
			clrscr();
			++curX;
			if (curX == winWidth + 1)	// проверка на коенц рамки
			{
				curX = 1;
				++curY;
			}
			if (curY == winHeight + 1)	// на противоположном уровне
				curY = 1;
			gotoxy(curX, curY);   //печать символа на координатах х,y
			printf("r");
			break;
		case 75:	// нажали F12
			gotoxy(curX, curY);
			clrscr();
			++curX; // из текущей позиции курсор перемещаем на один шаг вперед
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