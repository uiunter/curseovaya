#include <iostream>
#include <windows.h>
#include <conio.h>

void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}













int main()
{
	int Set[] = { 7,7,7 };
	int counter = 2;
	char key;

	for (int i = 0 ;;)
	{
		key = _getch();
		gotoxy(10, 5);
		color(Set[0]);
		std::cout << "1. Start ";

		gotoxy(10, 6);
		color(Set[1]);
		std::cout << "2. Info ";

		gotoxy(10, 7);
		color(Set[2]);
		std::cout << "3. Help ";

		if (key == 72 && (counter >= 2 && counter <= 3))
		{
			counter--;
		}
		
		if (key == 80 && (counter >= 1 && counter <= 2))
		{
			counter++;
		}

		if(key == '\r')
		{
			if (counter == 1)
			{
				std::cout << "Menu 1 is open";
			}
			
			if (counter == 2)
			{
				std::cout << "Menu 2 is open";
			}

			if (counter == 3)
			{
				std::cout << "Menu 3 is open";
			}
		}

		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;
		if (counter == 1)
		{
			Set[0] = 12;
		}

		if (counter == 2)
		{
			Set[1] = 12;
		}

		if (counter == 3)
		{
			Set[2] = 12;
		}
	}
	return 0;
	

}
