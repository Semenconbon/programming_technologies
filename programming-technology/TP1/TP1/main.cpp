#include <iostream>
#include <stdio.h>
#include "queue.h"
#include "queue1.h"
#include "workWithQueue.h"
#include "element.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	/*menuOutput();*/

	int queueCount = 0; // ����������� ������ ������� ��������
	Queue* queues = new Queue[queueCount]; // ��� ��� ������ ��������
	QueueFunsks queueFunk; // � ���� ������ ���������� ������� ��� ������ � �������� ��������

	int newElementInQueue; // ����� ������� 
	int selectedQueue; // ��������� �������
	int selectedQueue2; // ��������� ������� 2
	int range; // ������

	char c = 11;
	cout << "menu output\n"
		"0 � ���������� ������� \n"
		"1 � �������� ������� \n"
		"2 � ���������� �������� ������� \n"
		"3 � ���������� �������� �������\n"
		"4 � ����� ������� �� �����\n"
		"5 � ������ ������� (�������)\n"
		"6 � �������� ����� �������\n"
		"7 � ������� �������� � ����� ���������� �� �����\n"
		"8 � ����� �� ���������\n"
		<< endl;
	do {
			switch (c)
			{
				// ���������� �������
			case '0':
				queueCount++;
				queues = queueFunk.pushQueue(queues, queueCount);
				cout << "��������� ������� � �������� " << queueCount - 1 << endl;
				break;
			case '1':
				// �������� �������
				// �������� �� ������� ������� ��������
				if (queueCount == 0) { cout << "�������� ���" << endl; break; }

				queueCount--;
				queues = queueFunk.deleteQueue(queues, queueCount);
				cout << "������� ������� � �������� " << queueCount << endl;
				break;
			case '2':
				// ���������� ��������
				// �������� �� ������� ������� ��������
				if (queueCount == 0) { cout << "�������� ���" << endl; break; }
				// ����� �������
				do {
					cout << "������� ������ �������: ";
					cin >> selectedQueue;
				} while (selectedQueue >= queueCount || selectedQueue < 0);

				cout << "�������� �������: ";
				cin >> newElementInQueue;

				queues[selectedQueue].addElement(newElementInQueue);
				cout << "�������� ������� '" << newElementInQueue <<
					"' � ������� � �������� " << selectedQueue << endl;
				break;
			case '3':
				// ���������� ��������
				if (queueCount == 0) { cout << "�������� ���" << endl; break; }

				do {
					cout << "������� ������ �������: ";
					cin >> selectedQueue;
				} while (selectedQueue >= queueCount || selectedQueue < 0);

				queues[selectedQueue].deleteElement();
				cout << "�������� �������" <<
					" �� ������� � �������� " << selectedQueue << endl;
				break;
			case '4':
				// ����� �������(��) �� �����
				if (queueCount == 0) { cout << "�������� ���" << endl; break; }
				do {
					cout <<
						"1)������� ������ �������, ���� ������ ������� ������� �� �������.\n"
						<< "2)������� '-1' - ���� ������ ������� ��� �������: ";
					cin >> selectedQueue;
				} while (selectedQueue >= queueCount || selectedQueue < -1);
				if (selectedQueue == -1) {
					for (int i = 0; i < queueCount; i++) {
						cout << "������� [" << i << "]: ";
						queues[i].printQueue();
					}
				}
				else {
					cout << "\n������� [" << selectedQueue << "]: ";
					queues[selectedQueue].printQueue();
				}
				break;
			case '5':
				// ������ �������
				if (queueCount == 0) { cout << "�������� ���" << endl; break; }

				do {
					cout << "������� ������ �������: ";
					cin >> selectedQueue;
				} while (selectedQueue >= queueCount || selectedQueue < 0);

				range = queueFunk.findRangeThroughChildClass(queues[selectedQueue]);
				cout << "������ �� ������� � �������� " << selectedQueue <<
					" ����� " << range << endl;
				break;
			case '6':
				// ���������� �������
				if (queueCount == 0) { cout << "�������� ���" << endl; break; }

				do {
					cout << "������� ������ �������: ";
					cin >> selectedQueue;
				} while (selectedQueue >= queueCount || selectedQueue < 0);

				queueCount++;
				queues = queueFunk.copyQueue(queues, queueCount, selectedQueue);
				cout << "������� ����� " << selectedQueue <<
					" ����������� � �������� " << queueCount - 1 << endl;
				break;
			case '7':
				// ������� ���� ��������
				if (queueCount < 2) { cout << "�������� ������ ����" << endl; break; }

				do {
					cout << "������� ������ 1-�� �������: ";
					cin >> selectedQueue;
					cout << "������� ������ 2-�� �������: ";
					cin >> selectedQueue2;
				} while (selectedQueue >= queueCount || selectedQueue < 0 ||
					selectedQueue2 >= queueCount || selectedQueue2 < 0 ||
					selectedQueue == selectedQueue2);

				queueCount--;
				queues = queueFunk.mergeQueue(queues, queueCount, selectedQueue, selectedQueue2);
				for (int i = 0; i < queueCount; i++) {
					cout << "������� [" << i << "]: ";
					queues[i].printQueue();
				}
				break;
			default:
				for (int i = 0; i <= 100; i++)
					cout << "_";
				cout << "\n\n�������� ��������: ";
				break;
		}
	} while ((c = getchar()) != '8');
	//�������� ��������
	delete[] queues;
}
