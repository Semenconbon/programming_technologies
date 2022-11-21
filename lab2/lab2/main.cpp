/*1. Стандартные потоки
Определить класс с именем SIGN, содержащий следующие поля :
● фамилия, имя;
● знак зодиака;
● день рождения(массив из трех чисел).
Определить методы доступа к этим полям и перегруженные операции
извлечения и вставки для объектов типа SIGN.
Заранее число объектов не известно.
Написать программу, выполняющую следующие действия :
● записи должны быть упорядочены по датам дней рождения;
● вывод на экран информации о человеке, чья фамилия введена с
клавиатуры;
● если такого нет, выдать на дисплей соответствующее сообщение.
2. Файловые и строковые потоки
С использованием файловых и строковых потоков написать программу,
которая считывает текст из файла, находит самое длинное слово и
определяет, сколько раз оно встретилось в тексте.*/

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "SIGN.h"
#include "keeper.h"
void set_color(WORD color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); }
enum colors {
	RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
	WHITE = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED
};
void menu_output(short menu) {
	set_color(WHITE);
	system("cls");

	cout << endl << "====================================\n\n";
	if (menu == 1)
		set_color(RED);
	else set_color(WHITE);
	cout << "Добавить запись\n";
	if (menu == 2)
		set_color(RED);
	else set_color(WHITE);
	cout << "Удалить запись\n";
	if (menu == 3)
		set_color(RED);
	else set_color(WHITE);
	cout << "Вывести все записи\n";
	if (menu == 4)
		set_color(RED);
	else set_color(WHITE);
	cout << "изменить данные\n";
	if (menu == 5)
		set_color(RED);
	else set_color(WHITE);
	cout << "сохранить данные\n";
	if (menu == 6)
		set_color(RED);
	else set_color(WHITE);
	cout << "прочитать данные\n";
	if (menu == 7)
		set_color(RED);
	else set_color(WHITE);
	cout << "поиск по фамилии\n";
	if (menu == 8)
		set_color(RED);
	else set_color(WHITE);
	cout << "найти самое длинное слово в файле и указать, сколько раз оно встретилось\n";
	if (menu == 9)
		set_color(RED);
	else set_color(WHITE);
	cout << "Exit\n" << endl;
}
int main()
{
    setlocale(LC_ALL, "Russian");
	menu_output(1);
	char key_tmp; //временный символ
	char key; //опция
	short func = 1; //запуск функции
	bool ENTER_;
	bool exit = false;
	keeper k;
	bool isRead = false;
	string str;

	while (!exit) {
		ENTER_ = false;
		key_tmp = _getch();
		key_tmp == 224 ? key = _getch() : key = key_tmp;

		//управление меню
		switch (key) {
		case 80: //вниз
			func++;
			if (func > 9)
				func = 1;
			break;
		case 72: //вверх
			func--;
			if (func < 1)
				func = 9;
			break;
		case 13: //enter
			ENTER_ = true;
			break;
		}

		int del_id;

		if (ENTER_) { //запуск функций
			switch (func) {
			case 1: 
				try{
				k.add_sign();
				cin >> k.get_sign()[k.get_size() - 1];
				}
				catch (invalid_argument& e)
				{
					cerr << e.what() << endl;
					return -1;
				}
				break;
			case 2: 
				k.delete_sign();
				break;
			case 3:
				for (int i = 0; i < k.get_size(); i++) {
					cout << k.get_sign()[i] << endl;
				}
				_getch();
				break;
			case 4: 
				cout << "Введите фамилию человека, чтобы изменить его данные: ";
				cin >> str;
				k.change_data(str);
				_getch();
				break;
			case 5: //сохранить данные
				k.Save();
				cout << "Данные сохранены" << endl;
				_getch();
				break;
			case 6: // прочитать данные
				if (!isRead)
					k.Read();
				cout << "Данные загруженны" << endl;
				_getch();
				break;
			case 7:
				cout << "Введите фамилию: " << endl;
				cin >> str;
				k.search_info_by_surname(str);
				_getch();
				break;
			case 8:
				k.find_biggest_word();
				_getch();
				break;
			case 9:
				exit = true;
				break;
			}

		}

		menu_output(func);
	}
}
