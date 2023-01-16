#pragma warning(disable: 4996) 
#include <iostream> 
#include <windows.h> 

using namespace std;

void SetColorOutput(int counter, int field, bool console)
{
	if (console)
	{
		char color[] = "color 00";
		itoa(field, color + 6, 16);
		itoa(counter, color + 7, 16);
		system(color);
	}
	else
	{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, (WORD)((field << 4) | counter));
	}
}

void gotoxy(int x, int y)
{
	COORD point;
	point.X = x;
	point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void GetScroll(int px, int py, int pxx, int pyy, int dx, int dy)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
	SMALL_RECT srctScrollRect;
	if (px != NULL)
		srctScrollRect.Left = px;
	else
		srctScrollRect.Left = 0;
	if (pxx != NULL)
		srctScrollRect.Right = pxx;
	else
		srctScrollRect.Right = csbiInfo.dwSize.X;
	if (py != NULL)
		srctScrollRect.Top = py;
	else
		srctScrollRect.Top = 0;
	if (pyy != NULL)
		srctScrollRect.Bottom = pyy;
	else
		srctScrollRect.Bottom = csbiInfo.dwSize.Y;
	COORD coordDest;
	coordDest.X = 0 + dx;
	coordDest.Y = 0 + dy;
	SMALL_RECT srctClipRect;
	srctClipRect = srctScrollRect;
	CHAR_INFO chiFill;
	chiFill.Attributes = 0 | 0;
	chiFill.Char.UnicodeChar = '*';
	ScrollConsoleScreenBuffer(hStdout, &srctScrollRect, &srctClipRect, coordDest, &chiFill); // Прокрутка
}

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

void GetPrintColor(int text, int background)
{
	switch (background)
	{
	case Black:			std::cout << "01 ";   break;
	case Blue:			std::cout << "02 ";   break;
	case Green:			std::cout << "03 ";   break;
	case Cyan:			std::cout << "04 ";   break;
	case Red:			std::cout << "05 ";   break;
	case Magenta:		std::cout << "06 ";   break;
	case Brown:			std::cout << "07 ";   break;
	case LightGray:		std::cout << "08 ";   break;
	case DarkGray:		std::cout << "09 ";   break;
	case LightBlue:		std::cout << "10 ";  break;
	case LightGreen:	std::cout << "11 ";  break;
	case LightCyan:		std::cout << "12 ";  break;
	case LightRed:		std::cout << "13 ";  break;
	case LightMagenta:	std::cout << "14 ";  break;
	case Yellow:		std::cout << "15 ";  break;
	case White:			std::cout << "16 ";  break;
	}
	switch (text)
	{
	case Black:
		std::cout << "Черный             ";
		break;
	case Blue:
		std::cout << "Синий              ";
		break;
	case Green:
		std::cout << "Зеленый            ";
		break;
	case Cyan:
		std::cout << "Циановый           ";
		break;
	case Red:
		std::cout << "Красный            ";
		break;
	case Magenta:
		std::cout << "Пурпурный          ";
		break;
	case Brown:
		std::cout << "Коричневый         ";
		break;
	case LightGray:
		std::cout << "Светло-серый       ";
		break;
	case DarkGray:
		std::cout << "Темно-серый        ";
		break;
	case LightBlue:
		std::cout << "Светло-голубой     ";
		break;
	case LightGreen:
		std::cout << "Светло-зеленый     ";
		break;
	case LightCyan:
		std::cout << "Светло-циановый    ";
		break;
	case LightRed:
		std::cout << "Светло-красный     ";
		break;
	case LightMagenta:
		std::cout << "Яркий красно-синий ";
		break;
	case Yellow:
		std::cout << "Желтый             ";
		break;
	case White:
		std::cout << "Белый              ";
		break;
	}
	gotoxy(15, 6);
	std::cout << "                      ";
	gotoxy(15, 7);
	std::cout << "                      ";


}
int main()
{
	setlocale(LC_ALL, "ru");
	system("CLS");
	for (int field = 0; field <= 15; field++)
	{
		for (int counter = 0; counter <= 15; counter++)
		{
			gotoxy(15, 5);
			SetColorOutput(counter, field, FALSE);
			GetPrintColor(counter, field);
			GetScroll(0, 1, 65, 15, 0, 4);
			Sleep(100);
		}
		SetColorOutput(15, 0, FALSE);
	}
	return 0;
}
