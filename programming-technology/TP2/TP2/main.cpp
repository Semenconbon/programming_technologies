#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "funksForStack.cpp"
#include "stack.h"
#include <stdlib.h>

using namespace std;

void menu_oputput(Stack&, HANDLE, short); //��������� ����
void set_color(HANDLE, WORD); //��������� �����
void clrscr(HANDLE); //������� ������(������� cls)
enum colors_ {
	RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
	WHITE = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED
};

int main() {
	setlocale(LC_ALL, "Russian");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int sizeStack;
	do {
		cout << "������� ������ �����: " << endl;
		cin >> sizeStack;
	} while (sizeStack <= 0);
	Stack s(sizeStack); //����
	bool clearConsole = 0;
	menu_oputput(s, hConsole, 1);
	char tmp; //��������� ��������� ��������
	char key; //����� �����
	short function = 1; //������ �������
	bool ENTER_;
	bool exit = false;

	while (!exit) {
		ENTER_ = false;
		tmp = _getch();
		if (tmp == 224) //�������� �� ���������
			key = _getch();
		else key = tmp;

		switch (key) {
		case 80: //��������� ����
			function++;
			if (function > 15)
				function = 1;
			break;
		case 72: //��������� �����
			function--;
			if (function < 1)
				function = 15;
			break;
		case 13: //enter
			ENTER_ = true;
			break;
		}

		if (ENTER_) { //������ �������
			float_unary yourFU;

			if (s.getSize() != 0) {
				yourFU = s.getLastElement();
			}
			else {
				cout << "���� ���� - ���������� �������� ����!" 
					<< "������� ������� � ������ ��������� � ����" << endl;
				s.pushElement();
				yourFU = s.getLastElement();
			}
			float_unary helper;
			float f_u_value;
			switch (function) {
			case 1:
				// ���������� ��������
				s.pushElement();
				clearConsole = 1;
				break;
			case 2:
				// ���������� ��������
				if (s.getSize() == 0) {
					cout << "���� ����" << endl;
					clearConsole = 0;
					break;
				}
				s.pop();
				clearConsole = 1;
				break;
			case 3:
				// fu++
				s.getLastElement()++;
				clearConsole = 1;
				break;
			case 4:
				// fu--
				s.getLastElement()--;
				clearConsole = 1;
				break;
			case 5:
				// ++fu
				++s.getLastElement();
				clearConsole = 1;
				break;
			case 6:
				// --fu
				--s.getLastElement();
				clearConsole = 1;
				break;
			case 7:
				// +
				cout << "������� ������������ �������� � ������� ������ �������� ������: " << endl;
				cin >> f_u_value;
				helper = f_u_value + yourFU.getValue();
				yourFU = helper;
				s.setLastValue(yourFU.getValue());
				cout << "�����: " << yourFU.getValue() << endl;
				clearConsole = 1;
				break;
			case 8:
				// -
				cout << "������� ������������ �������� � ������� ������ �������� ������: " << endl;
				cin >> f_u_value;
				helper = yourFU.getValue() - f_u_value;
				yourFU = helper;
				s.setLastValue(yourFU.getValue());
				cout << "�����: " << yourFU.getValue() << endl;
				clearConsole = 1;
				break;
			case 9:
				// *
				cout << "������� ������������ �������� � ������� ������ �������� ������: " << endl;
				cin >> f_u_value;
				helper = yourFU.getValue() * f_u_value;
				yourFU = helper;
				s.setLastValue(yourFU.getValue());
				cout << "�����: " << yourFU.getValue() << endl;
				clearConsole = 1;
				break;
			case 10:
				// /
				cout << "������� ������������ �������� � ������� ������ �������� ������: " << endl;
				cin >> f_u_value;
				helper = yourFU.getValue() / f_u_value;
				yourFU = helper;
				s.setLastValue(yourFU.getValue());
				cout << "�����: " << yourFU.getValue() << endl;
				clearConsole = 1;
				break;
			case 11:
				// +=
				cout << "������� ������������ �������� � ������� ������ �������� ������: " << endl;
				cin >> f_u_value;
				yourFU += f_u_value;
				s.setLastValue(yourFU.getValue());
				cout << "�����: " << yourFU.getValue() << endl;
				clearConsole = 1;
				break;
			case 12:
				// -=
				cout << "������� ������������ �������� � ������� ������ �������� ������: " << endl;
				cin >> f_u_value;
				yourFU -= f_u_value;
				s.setLastValue(yourFU.getValue());
				cout << "�����: " << yourFU.getValue() << endl;
				clearConsole = 1;
				break;
			case 13:
				// *=
				cout << "������� ������������ �������� � ������� ������ �������� ������: " << endl;
				cin >> f_u_value;
				yourFU *= f_u_value;
				s.setLastValue(yourFU.getValue());
				cout << "�����: " << yourFU.getValue() << endl;
				clearConsole = 1;
				break;
			case 14:
				// /=
				cout << "������� ������������ �������� � ������� ������ �������� ������: " << endl;
				cin >> f_u_value;
				yourFU /= f_u_value;
				s.setLastValue(yourFU.getValue());
				cout << "�����: " << yourFU.getValue() << endl;
				clearConsole = 1;
				break;
			case 15:
				// +=
				return 0;
			}
		}
		if (clearConsole == 1) {
			system("cls");
			clearConsole = 0;
		}
		menu_oputput(s, hConsole, function);
	}
	return 0;
}

void menu_oputput(Stack& s, HANDLE console, short menu) {
	clrscr(console);
	set_color(console, WHITE);
	//����� ������� �� �����
	cout << "����: ";
	s.printStack();

	cout << endl << "====================================\n";
	if (menu == 1)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "���������� �������� � ����" << endl;
	if (menu == 2)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "���������� �������� �� �����" << endl;
	if (menu == 3)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "<��������� ������� �����>++" << endl;
	if (menu == 4)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "<��������� ������� �����>--" << endl;
	if (menu == 5)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "++<��������� ������� �����>" << endl;
	if (menu == 6)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "--<��������� ������� �����>" << endl;
	if (menu == 7)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "<��������� ������� �����(float_unary) = "
		"<��������� ������� �����(float_unary) + <��� float>" << endl;
	if (menu == 8)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "<��������� ������� �����(float_unary) = "
		"<��������� ������� �����(float_unary) - <��� float>" << endl;
	if (menu == 9)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "<��������� ������� �����(float_unary) = "
		"<��������� ������� �����(float_unary) * <��� float>" << endl;
	if (menu == 10)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "<��������� ������� �����(float_unary) = "
		"<��������� ������� �����(float_unary) / <��� float>" << endl;
	if (menu == 11)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "<��������� ������� �����(float_unary) += <��� float>" << endl;
	if (menu == 12)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "<��������� ������� �����(float_unary) -= <��� float>" << endl;
	if (menu == 13)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "<��������� ������� �����(float_unary) *= <��� float>" << endl;
	if (menu == 14)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "<��������� ������� �����(float_unary) /= <��� float>" << endl;
	if (menu == 15)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "exit\n\n";
}

void set_color(HANDLE console, WORD color) {
	SetConsoleTextAttribute(console, color);
}

void clrscr(HANDLE console) {
	COORD cur_pos;
	cur_pos.X = 0;
	cur_pos.Y = 0;
	SetConsoleCursorPosition(console, cur_pos);
}