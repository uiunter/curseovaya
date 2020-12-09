#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

void color(int color)
{
	SetConsoleTextAttribute(console, color);
}

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}// function defined below if this is new to you.

int main()
{
	int Set[] = { 7,7,7,7,7,7,7,7 };
	int menu_item = 0, run, x = 7;
	bool running = true;

	gotoXY(18, 5);
	std::cout << "Main Menu";
	color(Set[0]);
	gotoXY(18, 7);
	std::cout << "> ";

	while (running)
	{
		gotoXY(20, 7);
		color(Set[1]);
		std::cout << "1) Input";
		color(Set[2]);
		gotoXY(20, 8);
		color(Set[3]);
		std::cout << "2) Output";
		gotoXY(20, 9);
		color(Set[4]);
		std::cout << "3) ...";
		color(Set[5]);
		gotoXY(20, 10);
		color(Set[6]);
		std::cout << "4) ...";
		gotoXY(20, 11);
		color(Set[7]);
		std::cout << "Quit Program";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 11) //down button pressed
		{
			gotoXY(18, x);
			std::cout << "  ";
			x++;
			gotoXY(18, x);
			std::cout << "> ";
			menu_item++;
			continue;

		}

		if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
		{
			gotoXY(18, x);
			std::cout << "  ";
			x--;
			gotoXY(18, x);
			std::cout << "> ";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

			case 0: {

				gotoXY(20, 16);
				Set[1] = 12;
				std::cout << "You chose Input...     ";
				break;
			}


			case 1: {
				gotoXY(20, 16);
				Set[2] = 12;
				std::cout << "You chose Output...     ";
				break;
			}

			case 2: {
				gotoXY(20, 16);
				Set[3] = 12;
				std::cout << "You chose Option 3...     ";
				break;
			}

			case 3: {
				gotoXY(20, 16);
				Set[4] = 12;
				std::cout << "You chose Option 4...     ";
				break;
			}

			case 4: {
				gotoXY(20, 16);
				Set[5] = 12;
				std::cout << "The program has now terminated!!";
				running = false;
			}

			}

		}

	}

	gotoXY(20, 21);
	return 0;
}
