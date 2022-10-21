#include <iostream>
#include "float_unary.h"

float_unary::float_unary() 
{
	this->value = 0;
};
float_unary::float_unary(float newValue) 
{ 
	this->value = newValue;
};
float_unary::float_unary(const float_unary& copy) :
	value(copy.value)
{
};
// ������� ��������
float_unary& float_unary::operator--() {
	value -= 0.1f;
	return *this;
}
float_unary& float_unary::operator++() {
	value += 0.5f;
	return *this;
}
float_unary operator--(float_unary& oldFU, int) {
	oldFU.value -= 0.2f;
	return oldFU;
}
float_unary operator++(float_unary& oldFU, int) {
	oldFU.value += 2.5f;
	return oldFU;
}


float &float_unary::getValue() {
	return this->value;
}
void float_unary::setValue(float newValue) {
	this->value = newValue;
}

// �������� ��������
// �������� "+"
float_unary &operator+(const float_unary& f_u_value, float value) {
	float newValue = f_u_value.value + value; // ������� ����� ��������
	float_unary newFloat_unary(newValue); // ������ ����� ������
	return newFloat_unary; // �������� ������ ������ �����
}
float_unary &operator-(const float_unary& f_u_value, float value) {
	float newValue = f_u_value.value - value; // ������� ����� ��������
	float_unary newFloat_unary(newValue); // ������ ����� ������
	return newFloat_unary; // �������� ������ ������ �����
}
float_unary &operator*(const float_unary& f_u_value, float value) { 
	float newValue = f_u_value.value * value; // ������� ����� ��������
	float_unary newFloat_unary(newValue); // ������ ����� ������
	return newFloat_unary; // �������� ������ ������ �����
}
float_unary &operator/(const float_unary& f_u_value, float value) {
	float newValue = f_u_value.value / value; // ������� ����� ��������
	float_unary newFloat_unary(newValue); // ������ ����� ������
	return newFloat_unary; // �������� ������ ������ �����
}

// �������� "+="
float_unary float_unary::operator+=(float newValue) {
	value += newValue;
	return *this;
}
float_unary float_unary::operator-=(float newValue) {
	value -= newValue;
	return *this;
}
float_unary float_unary::operator*=(float newValue) {
	value *= newValue;
	return *this;
}
float_unary float_unary::operator/=(float newValue) {
	value /= newValue;
	return *this;
}

// �������� "="
float_unary float_unary::operator=(const float_unary &f_u_value) {
	if (this == &f_u_value) // �������� �� ����������������
		return *this;
	value = f_u_value.value;
	return *this;
}
