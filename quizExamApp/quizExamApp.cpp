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
void Menu();

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}// function defined below if this is new to you.

void cls()
{
	system("CLS");
}

void subMenu()
{
	cls();
	gotoXY(18, 5);
	std::cout << "Submenu";
	bool running_subMenu = true;
	int subMenu_item = 0, run, x = 7;
	while (running_subMenu)
	{
		gotoXY(20, 7);
		std::cout << "1) Matan";
		gotoXY(20, 8);
		std::cout << "2) AIG";
		gotoXY(20, 9);
		std::cout << "3) Proga";
		gotoXY(20, 10);
		std::cout << "4) Return";

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && x != 11) //down button pressed
		{
			gotoXY(18, x);
			std::cout << "  ";
			x++;
			gotoXY(18, x);
			std::cout << "> ";
			subMenu_item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
		{
			gotoXY(18, x);
			std::cout << "  ";
			x--;
			gotoXY(18, x);
			std::cout << "> ";
			subMenu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (subMenu_item) {

				case 0: {

					gotoXY(20, 16);
					std::cout << "You chose Matan    ";
					break;
				}


				case 1: {
					gotoXY(20, 16);
					std::cout << "You chose AIG     ";
					break;
				}

				case 2: {
					gotoXY(20, 16);
					std::cout << "You chose Proga    ";
					break;
				}

				case 3: {
					cls();
					Menu();
					break;
					}
			}
		}
	}
}

void Menu()
{
	int menu_item = 0, run, x = 7;
	bool running = true;

	gotoXY(18, 5);
	std::cout << "Main Menu";
	gotoXY(18, 7);
	std::cout << "> ";

	while (running)
	{
		gotoXY(20, 7);
		std::cout << "1) Input";
		gotoXY(20, 8);
		std::cout << "2) Output";
		gotoXY(20, 9);
		std::cout << "3) ...";
		gotoXY(20, 10);
		std::cout << "4) ...";
		gotoXY(20, 11);
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
				subMenu();
				running = false;
				break;
			}


			case 1: {
				gotoXY(20, 16);
				std::cout << "You chose Output...     ";
				break;
			}

			case 2: {
				gotoXY(20, 16);
				std::cout << "You chose Option 3...     ";
				break;
			}

			case 3: {
				gotoXY(20, 16);
				std::cout << "You chose Option 4...     ";
				break;
			}

			case 4: {
				gotoXY(20, 16);
				std::cout << "The program has now terminated!!";
				running = false;
			}

			}

		}

	}

	gotoXY(20, 21);
}

int main()
{
	Menu();
	return 0;
}
