#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

void Menu();

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void cls()
{
	system("CLS");
}

void readFile(const char *filename)
{
	std::string line;
	std::vector<std::string> lines;


	//input file stream
	std::ifstream file(filename);

	//count number of total lines in the file and store the lines in the string vector
	int total_lines = 0;
	while (getline(file, line))
	{
		total_lines++;
		lines.push_back(line);
	}

	//generate a random number between 0 and count of total lines
	int random_number = rand() % total_lines;



	//fetch the line where line index (starting from 0) matches with the random number
	gotoXY(18, 5);
	std::cout << lines[random_number];

	int rightAnswer = 0, item = 0, x = 9;
	bool running = true;
	while (running)
	{
		gotoXY(20, 9);
		std::cout << "Yes";
		gotoXY(20, 10);
		std::cout << "Next question";

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && x != 10) //down button pressed
		{
			gotoXY(18, x);
			std::cout << "  ";
			x++;
			gotoXY(18, x);
			std::cout << "> ";
			item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 9) //up button pressed
		{
			gotoXY(18, x);
			std::cout << "  ";
			x--;
			gotoXY(18, x);
			std::cout << "> ";
			item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (item) {

			case 0: {
				++rightAnswer;
				break;
			}


			case 1: {
				cls();
				readFile(filename);
				break;
			}
			}
		}
	}
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
		std::cout << "1. Matan";
		gotoXY(20, 8);
		std::cout << "2. AIG";
		gotoXY(20, 9);
		std::cout << "3. Proga";
		gotoXY(20, 10);
		std::cout << "4. Return";

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && x != 10) //down button pressed
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
					cls();
					readFile("matan.txt");
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
		std::cout << "1. Input";
		gotoXY(20, 8);
		std::cout << "Quit Program";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 8) //down button pressed
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
					std::cout << "The program has now terminated!!";
					exit(0);
				
				}
			}
		}
	}

	gotoXY(20, 21);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Menu();
	return 0;
}
