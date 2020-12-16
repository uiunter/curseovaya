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
	std::ifstream in(fileName.c_str());
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

void writeInFile(const std::string& filename) {
	std::fstream myfile;
	myfile.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);
	myfile << "1" << std::endl;
	myfile.close();
}

int countPoints(const std::string& filename) {
	int count = 0;
	std::string line;
	std::ifstream file(filename);
	while (getline(file, line))
		count++;
	return count;
}

void clearFileData(const std::string& filename)
{
	std::ofstream ofs;
	ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
	ofs.close();
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
	int item = 0, x = 9;
	bool running = true;
	gotoXY(18, 9);
	std::cout << "> ";
	clearFileData("rightanswers.txt");
	clearFileData("numberoftries.txt");
	readFile(filename);
	while (running)
	{
		gotoXY(20, 9);
		std::cout << "Правильно";
		gotoXY(20, 10);
		std::cout << "Следующий вопрос";
		gotoXY(20, 11);
		std::cout << "Назад";

		gotoXY(18, 18);
		std::cout << "Правильные ответы: " << countPoints("rightanswers.txt");
		gotoXY(18, 19);
		std::cout << "Количество попыток: " << countPoints("numberoftries.txt");


		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && x != 11)
		{
			gotoXY(18, x);
			std::cout << "  ";
			x++;
			gotoXY(18, x);
			std::cout << "> ";
			item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 9)
		{
			gotoXY(18, x);
			std::cout << "  ";
			x--;
			gotoXY(18, x);
			std::cout << "> ";
			item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN))
		{

			switch (item)
			{
			case 0:
				{
				writeInFile("rightanswers.txt");
				writeInFile("numberoftries.txt");
					cls();
					readFile(filename);
					break;
				}

			case 1: 
			{
				writeInFile("numberoftries.txt");
					cls();
					readFile(filename);
					break;
				}
				
			case 2:
				{
					cls();
					clearFileData("rightanswers.txt");
					clearFileData("numberoftries.txt");
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
	std::cout << "Выберите предмет";
	gotoXY(18, 7);
	std::cout << "> ";
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

		if (GetAsyncKeyState(VK_DOWN) && x != 10)
		{
			gotoXY(18, x);
			std::cout << "  ";
			x++;
			gotoXY(18, x);
			std::cout << "> ";
			subMenu_item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 7)
		{
			gotoXY(18, x);
			std::cout << "  ";
			x--;
			gotoXY(18, x);
			std::cout << "> ";
			subMenu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN))
		{
			switch (subMenu_item)
			{
			case 0:
				{
					gotoXY(20, 16);
					cls();
					subsubMenu("matan.txt");
					break;
				}

			case 1:
				{
					gotoXY(20, 16);
					cls();
					subsubMenu("aig.txt");
					break;
				}

			case 2:
				{
					gotoXY(20, 16);
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

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && x != 8)
		{
			gotoXY(18, x);
			std::cout << "  ";
			x++;
			gotoXY(18, x);
			std::cout << "> ";
			menu_item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 7)
		{
			gotoXY(18, x);
			std::cout << "  ";
			x--;
			gotoXY(18, x);
			std::cout << "> ";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN))
		{
			switch (menu_item)
			{
			case 0:
				{
					gotoXY(20, 16);
					subMenu();
					running = false;
					break;
				}


			case 1:
				{
					gotoXY(20, 16);
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
