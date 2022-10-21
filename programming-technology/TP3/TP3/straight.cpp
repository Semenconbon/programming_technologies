#include "straight.h"
#include <iostream>

Straight::~Straight() {}

void Straight::calculateY() {
	y = tan(angle * PI / 180) * x + b; // kx + b - ����������� �������
}
void Straight::setX(float newX) {
	Curves::setX(newX);
}
// ��������� ��������� ��� ����

void Straight::setAngle(int newAngle) {
	this->angle = newAngle; // ������������ ���������� �� ��������� ������ Curves
}

void Straight::setB(float newB) {
	this->b = newB;
}


