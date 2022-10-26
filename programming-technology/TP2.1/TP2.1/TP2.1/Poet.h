#pragma once
#include "Writter.h"
class Poet : public Writter
{
public:
	Poet();
	Poet(string fullname, int year_of_birth, int year , string name_books);// ����������� � �����-��
	Poet(const Poet &ref_Poet); // ����������� �����������

	//���� �����
	int year_of_birth;
	int year_of_death;

	//�������
	string get_fullname() override;
	int get_years_of_birth();
	int get_years_of_death();
	string get_name_books() override;

	//�������
	void set_fullname(string fullname)override;
	void set_years_of_live(int years_of_birth, int year_of_death);
	void set_name_books(string name_books)override;

	//��������� ������
	void change_fullname(string);
	void change_year_of_birth(int);
	void change_year_of_death(int);
	void change_name_of_book(string);
	//TODO: void add_book(string);
};

