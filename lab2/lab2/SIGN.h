#pragma once
#include <iostream>
#include <string>

using namespace std;
class SIGN
{
private:
	string surname;
	string name;
	string sign;
	int date_of_birth[3];
public:
	//������������
	SIGN();
	SIGN(string surname, string name, string sign, int* date_of_birth);
	SIGN(const SIGN& ref_sign);
	//����������
	~SIGN();

	//�������
	string get_surname();
	string get_name();
	string get_sign();
	int *get_date_of_birth();
	//�������
	void set_surname(string fullname);
	void set_name(string name);
	void set_sign(string sign);
	void set_date_of_birth(int* date_of_birth);
	//������������� ���������
	friend ostream& operator<<(ostream& os, const SIGN& sg);
	friend istream& operator>>(istream& is,  SIGN& sg);
};

