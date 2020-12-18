#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
#include <stdio.h>


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

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
	std::ifstream in(fileName);
	if (!in)
	{
		gotoXY(18, 5);
		std::cerr << "Cannot open the File : " << fileName << std::endl;
		return false;
	}
	std::string str;
	while (std::getline(in, str))
	{
		callback(str);
	}
	in.close();
	return true;
}

void readFile(const std::string& fileName)
{
	int totalLines = 0;
	std::vector<std::string> lines;
	bool res = iterateFile(fileName, [&](const std::string& str)
		{
			lines.push_back(str);
			totalLines++;
		});

	int random_number = rand() % totalLines;

	gotoXY(18, 5);
	std::cout << lines[random_number];
}

void subsubMenu(const std::string& filename) {
	int item = 0, coord_item_x = 20, coord_pointer_x = coord_item_x - 2, coord_y = 9;
	const int coord_lowest_y = coord_y * 2;
	const int highestPosition = coord_y;
	const int menuLines = 3;
	const int lowestPosition = highestPosition + 3 - 1;
	bool running = true;
	int rightAnwers = 0;
	int numberOfTries = 0;
	gotoXY(coord_pointer_x, coord_y);
	std::cout << "> ";
	readFile(filename);
	while (running)
	{
		gotoXY(coord_item_x, highestPosition);
		std::cout << "Правильно";
		gotoXY(coord_item_x, highestPosition + 1);
		std::cout << "Следующий вопрос";
		gotoXY(coord_item_x, lowestPosition);
		std::cout << "Назад";

		gotoXY(coord_item_x, coord_lowest_y);
		std::cout << "Правильные ответы: " << rightAnwers;
		gotoXY(coord_item_x, coord_lowest_y + 1);
		std::cout << "Количество попыток: " << numberOfTries;


		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && coord_y < lowestPosition)
		{
			gotoXY(coord_pointer_x, coord_y);
			std::cout << "  ";
			coord_y++;
			gotoXY(coord_pointer_x, coord_y);
			std::cout << "> ";
			item++;
		} else if (GetAsyncKeyState(VK_DOWN) && coord_y == lowestPosition)
		{
			gotoXY(coord_pointer_x, lowestPosition);
			std::cout << "  ";
			gotoXY(coord_pointer_x, highestPosition);
			std::cout << "  ";
			coord_y = highestPosition;
			gotoXY(coord_pointer_x, coord_y);
			std::cout << "> ";
			item = 0;
		}

		if (GetAsyncKeyState(VK_UP) && coord_y > highestPosition)
		{
			gotoXY(coord_pointer_x, coord_y);
			std::cout << "  ";
			coord_y--;
			gotoXY(coord_pointer_x, coord_y);
			std::cout << "> ";
			item--;
		} else if (GetAsyncKeyState(VK_UP) && coord_y == highestPosition)
		{
			gotoXY(coord_pointer_x, highestPosition);
			std::cout << "  ";
			gotoXY(coord_pointer_x, lowestPosition);
			std::cout << "  ";
			coord_y = lowestPosition;
			gotoXY(coord_pointer_x, lowestPosition);
			std::cout << "> ";
			item = menuLines - 1;
		}

		if (GetAsyncKeyState(VK_RETURN))
		{

			switch (item)
			{
			case 0:
				{
				rightAnwers++;
				numberOfTries++;
					cls();
					readFile(filename);
					break;
				}

			case 1: 
			{
				numberOfTries++;
					cls();
					readFile(filename);
					break;
				}
				
			case 2:
				{
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
	bool running_subMenu = true;
	int menuLines = 4;
	int subMenu_item = 0, coord_item_x = 20, coord_pointer_x = coord_item_x - 2, coord_y = 7;
	const int highestPosition = coord_y;
	const int lowestPosition = highestPosition + menuLines - 1;
	gotoXY(coord_pointer_x, coord_y - 2);
	std::cout << "Выберите предмет";
	gotoXY(coord_pointer_x, coord_y);
	std::cout << "> ";
	while (running_subMenu)
	{
		gotoXY(coord_item_x, highestPosition);
		std::cout << "1. Математический Анализ";
		gotoXY(coord_item_x, highestPosition + 1);
		std::cout << "2. Алгебра и Геометрия";
		gotoXY(coord_item_x, highestPosition + 2);
		std::cout << "3. Программирование";
		gotoXY(coord_item_x, lowestPosition);
		std::cout << "4. Назад";

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && (coord_y < lowestPosition))
		{
			gotoXY(coord_pointer_x, coord_y);
			std::cout << "  ";
			coord_y++;
			gotoXY(coord_pointer_x, coord_y);
			std::cout << "> ";
			subMenu_item++;
		} else if (GetAsyncKeyState(VK_DOWN) && coord_y == lowestPosition)
			{
				gotoXY(coord_pointer_x, lowestPosition);
				std::cout << "  ";
				gotoXY(coord_pointer_x, highestPosition);
				std::cout << "  ";
				coord_y = highestPosition;
				gotoXY(coord_pointer_x, coord_y);
				std::cout << "> ";
				subMenu_item = 0;
			}

		if (GetAsyncKeyState(VK_UP) && (coord_y > highestPosition))
		{
			gotoXY(coord_pointer_x, coord_y);
			std::cout << "  ";
			coord_y--;
			gotoXY(coord_pointer_x, coord_y);
			std::cout << "> ";
			subMenu_item--;
		} else if (GetAsyncKeyState(VK_UP) && coord_y == highestPosition)
		{
			gotoXY(coord_pointer_x, highestPosition);
			std::cout << "  ";
			gotoXY(coord_pointer_x, lowestPosition);
			std::cout << "  ";
			coord_y = lowestPosition;
			gotoXY(coord_pointer_x, lowestPosition);
			std::cout << "> ";
			subMenu_item = menuLines - 1;
		}

		if (GetAsyncKeyState(VK_RETURN))
		{
			switch (subMenu_item)
			{
			case 0:
				{
					gotoXY(coord_item_x, coord_y * 3);
					cls();
					subsubMenu("matan.txt");
					break;
				}

			case 1:
				{
					gotoXY(coord_item_x, coord_y * 3);
					cls();
					subsubMenu("aig.txt");
					break;
				}

			case 2:
				{
					gotoXY(coord_item_x, coord_y * 3);
					cls();
					subsubMenu("prog.txt");
					break;
				}

			case 3:
				{
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
	int menu_item = 0, coord_item_x = 20, coord_pointer_x = coord_item_x - 2, coord_y = 7;
	const int coord_lowest_y = coord_y * 2;
	const int highestPosition = coord_y;
	const int menuLines = 2;
	const int lowestPosition = highestPosition + (menuLines - 1);
	bool running = true;

	gotoXY(coord_pointer_x, coord_y - 2);
	std::cout << "Главное меню";
	gotoXY(coord_pointer_x, coord_y);
	std::cout << "> ";

	while (running)
	{
		gotoXY(coord_item_x, highestPosition);
		std::cout << "1. Начать";
		gotoXY(coord_item_x, lowestPosition);
		std::cout << "   Выйти";

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && (coord_y < lowestPosition))
		{
			gotoXY(coord_pointer_x,coord_y);
			std::cout << "  ";
			coord_y++;
			gotoXY(coord_pointer_x, coord_y);
			std::cout << "> ";
			menu_item++;
		} else if (GetAsyncKeyState(VK_DOWN) && coord_y == lowestPosition)
			{
				gotoXY(coord_pointer_x, lowestPosition);
				std::cout << "  ";
				gotoXY(coord_pointer_x, highestPosition);
				std::cout << "  ";
				coord_y = highestPosition;
				gotoXY(coord_pointer_x, coord_y);
				std::cout << "> ";
				menu_item = 0;
			}

		if (GetAsyncKeyState(VK_UP) && (coord_y > highestPosition))
		{
			gotoXY(coord_pointer_x, coord_y);
			std::cout << "  ";
			coord_y--;
			gotoXY(coord_pointer_x, coord_y);
			std::cout << "> ";
			menu_item--;
		} else if (GetAsyncKeyState(VK_UP) && coord_y == highestPosition)
				{
					gotoXY(coord_pointer_x, highestPosition);
					std::cout << "  ";
					gotoXY(coord_pointer_x, lowestPosition);
					std::cout << "  ";
					coord_y = lowestPosition;
					gotoXY(coord_pointer_x, lowestPosition);
					std::cout << "> ";
					menu_item = menuLines - 1;
				}

		if (GetAsyncKeyState(VK_RETURN))
		{
			switch (menu_item)
			{
			case 0:
				{
					gotoXY(coord_item_x, coord_lowest_y);
					subMenu();
					break;
				}


			case 1:
				{
					gotoXY(coord_item_x, coord_lowest_y);
					std::cout << "Программа завершила свое действие.";
					exit(0);
				}
			}
		}
	}

}

int main()
{
	setlocale(LC_ALL, "Russian");
	Menu();
	return 0;
}
