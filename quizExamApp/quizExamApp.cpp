#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
#include <stdio.h>


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

void subMenu();
bool iterateFile(const std::string& fileName, std::function<void(const std::string&)> callback)
{
	// Open the File
	std::ifstream in(fileName.c_str());
	// Check if object is valid
	if (!in)
	{
		std::cerr << "Cannot open the File : " << fileName << std::endl;
		return false;
	}
	std::string str;
	// Read the next line from File untill it reaches the end.
	while (std::getline(in, str))
	{
		// Call the given callback
		callback(str);
	}
	//Close The File
	in.close();
	return true;
}

void readFile(std::string fileName)
{
	//std::string line;
	int totalLines = 0;
	std::vector<std::string> lines;
	bool res = iterateFile(fileName, [&](const std::string& str) {
		// Add to vector
		lines.push_back(str);
		totalLines++;
		});

	int random_number = rand() % totalLines;

	gotoXY(18, 5);
	std::cout << lines[random_number];

	int item = 0, x = 9;
	bool running = true, run = true;
	while (running)
	{
		gotoXY(20, 9);
		std::cout << "Yes";
		gotoXY(20, 10);
		//std::cout << "Next question";
		//gotoXY(20, 11);
		std::cout << "Return";
		//gotoXY(18, 18);
		//std::cout << "Right Answers: " << rightAnswers;

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && x != 11) //down button pressed
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
					cls();
					readFile(fileName);
					break;
				}

				/*case 1: {
					cls();
					readFile(fileName);
					break;
				}
				*/
				case 2: {
					cls();
					subMenu();
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
	int subMenu_item = 0, x = 7;
	while (running_subMenu)
	{
		gotoXY(20, 7);
		std::cout << "1. Математический Анализ";
		gotoXY(20, 8);
		std::cout << "2. Алгебра и Геометрия";
		gotoXY(20, 9);
		std::cout << "3. Программирование";
		gotoXY(20, 10);
		std::cout << "4. Назад";

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
					cls();
					readFile("aig.txt");
					break;
				}

				case 2: {
					gotoXY(20, 16);
					cls();
					readFile("prog.txt");
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
	int menu_item = 0, x = 7;
	bool running = true;

	gotoXY(18, 5);
	std::cout << "Главное меню";
	gotoXY(18, 7);
	std::cout << "> ";

	while (running)
	{
		gotoXY(20, 7);
		std::cout << "1. Начать";
		gotoXY(20, 8);
		std::cout << "   Выйти";

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
					std::cout << "Программа завершила свое действие.";
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
