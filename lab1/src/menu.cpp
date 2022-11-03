#pragma once
#include "menu.h"
namespace Menu {
	keeper k;

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
		cout << "�������� ��������\n";
		if (menu == 2)
			set_color(RED);
		else set_color(WHITE);
		cout << "������� ����� �����\n";
		if (menu == 3)
			set_color(RED);
		else set_color(WHITE);
		cout << "����� ���� �����\n";
		if (menu == 4)
			set_color(RED);
		else set_color(WHITE);
		cout << "Delete the last element\n";
		if (menu == 5)
			set_color(RED);
		else set_color(WHITE);
		cout << "Delete by index\n";
		if (menu == 6)
			set_color(RED);
		else set_color(WHITE);
		cout << "Out keeper\n";
		if (menu == 7)
			set_color(RED);
		else set_color(WHITE);
		cout << "Change\n";
		if (menu == 8)
			set_color(RED);
		else set_color(WHITE);
		cout << "Clear\n";
		if (menu == 9)
			set_color(RED);
		else set_color(WHITE);
		cout << "Save to file\n";
		if (menu == 10)
			set_color(RED);
		else set_color(WHITE);
		cout << "Extract from file\n";
		if (menu == 11)
			set_color(RED);
		else set_color(WHITE);
		cout << "Exit\n" << endl;
	}

	void menu() {
		//test zone
		//Keeper k;

		//k.Save();
		//


		k.Read();
		menu_output(1);
		char key_tmp; //��������� ������
		char key; //�����
		short func = 1; //������ �������
		bool ENTER_;
		bool exit = false;

		while (!exit) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;

			//���������� ����
			switch (key) {
			case 80: //����
				func++;
				if (func > 11)
					func = 1;
				break;
			case 72: //�����
				func--;
				if (func < 1)
					func = 11;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}

			int del_id;

			if (ENTER_) { //������ �������
				switch (func) {
				case 1: //add a book
					add_a_writter();
					break;
				case 2: //add a textbook
					break;
				case 3: //add a chancellery
					break;
				case 4: //Delete the last element
					break;
				case 5: //Delete by index
					break;
				case 6: //Out keepe
					break;
				case 7: //Change
					break;
				case 8: //Clear
					break;
				case 9: //Save to file
					break;
				case 10: //Extract from file
					break;
				case 11: //Exit
					exit = true;
					break;
				}
			}

			menu_output(func);
		}
	}
	void add_a_writter()
	{
		char key_tmp; //��������� ������
		char key; //�����
		bool ENTER_;
		short func = 1;
		bool exit = false;

		menu_add_a_writter(func);

		while (1) {
		ENTER_ = false;
		key_tmp = _getch();
		key_tmp == 224 ? key = _getch() : key = key_tmp;


			switch (key) {
			case 80: //����
				func++;
				if (func > 7)
					func = 1;
				break;
			case 72: //�����
				func--;
				if (func < 1)
					func = 7;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}
			if (ENTER_) { //������ �������
				switch (func) {
				case 1: //�������� �����
					cout << "������� ��� �����, ��� ��� ��������, ��� ������ � ���� ��� ������������ (������� ������� �������� ��� ������������)" << endl;
					//TODO: ������� �� ������� ����, �������� ������ ����� � �������� ��� � keeper *p
					break;
				case 2: //�������� ���������

					break;
				case 3: //�������� ��������
					break;
				case 4: //������� �����
					break;
				case 5: //������� ���������
					break;
				case 6: //������� ��������
					break;
				case 7: //�����
					return;
					break;

				}
			}
			menu_add_a_writter(func);
		}
	}



	void menu_add_a_writter(short menu)
	{
		set_color(WHITE);
		system("cls");

		cout << endl << "====================================\n\n";
		if (menu == 1)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� �����\n";
		if (menu == 2)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ���������\n";
		if (menu == 3)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ��������\n";
		if (menu == 4)
			set_color(RED);
		else set_color(WHITE);
		cout << "������� ��������\n";
		if (menu == 5)
			set_color(RED);
		else set_color(WHITE);
		cout << "������� �����\n";
		if (menu == 6)
			set_color(RED);
		else set_color(WHITE);
		cout << "������� ���������\n";
		if (menu == 7)
			set_color(RED);
		else set_color(WHITE);
		cout << "�����\n";
	}
}
