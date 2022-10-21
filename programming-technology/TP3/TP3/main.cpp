#include <iostream>
#include "straight.h"
#include "hyperbola.h"
#include "ellipse.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");


	Straight line; // ������ ������ "������"
	Hyperbola hyphyp; // ������ ������ "���������"
	Ellipse ellipse; // ������ ������ "������"

	char c = -1;

	cout << "1 - ��������� 'y' ������ �����\n"
		"2 - ��������� 'y' ���������\n"
		"3 - ��������� 'y' �������\n"
		"0 - �����"
		<< endl;
	int angle; // ����
	float b;// ��������
	float x;// x
	float k;// ���������� ���������
	float ellipseA, ellipseB;// ������� �������
	do {
		switch (c) {
			// ������
		case '1':
			// ������ ����
			do {
				cout << "������� ������ ����: " << endl;
				cin >> angle;
			} while (angle < -360 || angle > 360);
			line.setAngle(angle);

			if (angle == 90 || angle == 270 ||
				angle == -90 || angle == -270) {
				cout << "y = ������������� ��� ����������� �� �"
					" ��� b." << endl;
				cout << "�������� ��������: ";
				break;
			}
			// ������ �������� b
			cout << "������� �������� - 'b'" << endl;
			cin >> b;
			line.setB(b);
			if (angle == 0 || angle == 180 || angle == 360
				|| angle == -360 || angle == -180) {
				cout << "� ������������� �� �, y = " << b << endl;
				cout << "�������� ��������: ";
				break;
			}
			// ������ �
			cout << "������� '�'" << endl;
			cin >> x;
			line.setX(x);

			line.calculateY();
			cout << "y = " << line.getY() << endl;
			cout << "�������� ��������: ";
			break;

			// ���������
		case '2':
			do {
				cout << "������� ���������� ��������� (�������: y = k / x)" << endl;
				cin >> k;
				hyphyp.setK(k);
			} while (k == 0);

			cout << "������� x" << endl;
			cin >> x;
			hyphyp.setX(x);
			if (x == 0) {
				cout << "��������� ��������� � ����, �� �� ��������� ���" << endl;
				break;
			}

			hyphyp.calculateY();
			(k > 0) ?
				cout << "��������� ����������� � 1 � 3 ���������" << endl :
				cout << "��������� ����������� � 2 � 4 ���������" << endl;
			cout << "y = " << hyphyp.getY() << endl;

			cout << "�������� ��������: ";
			break;
			// ������
		case '3':
			// ����� ����� �������
			do {
				cout << "������� ������� a: " << endl;
				cin >> ellipseA;
				ellipse.setA(ellipseA);
			} while (ellipseA <= 0);
			// ����� ������� ������� (������ ���� ������ �����)
			do {
				cout << "������� ������� b: " << endl;
				cin >> ellipseB;
				ellipse.setB(ellipseB);
			} while (ellipseB <= 0);

			// ����� �
			cout << "������� x: " << endl;
			cin >> x;
			ellipse.setX(x);
			if (abs(x) > ellipseA)
				cout << "���� ������ Y � �������, ������� ������������� ������ x" << endl;
			else if (abs(x) == ellipseA) {
				ellipse.calculateY();
				cout << "y = " << ellipse.getY() << endl;
			}
			else {
				ellipse.calculateY();
				cout << "y = " << ellipse.getY() << " � y = " << -ellipse.getY() << endl;
			}
			cout << "�������� ��������: ";
			break;
		}
	} while ((c = getchar()) != '0');
}

