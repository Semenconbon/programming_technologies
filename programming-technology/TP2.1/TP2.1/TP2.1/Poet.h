#pragma once
#include "Writter.h"
class Poet : public Writter
{
public:
	Poet();
	Poet(string fullname, int* years_of_live, string name_books);// ����������� � �����-��
	Poet(const Poet &ref_Poet); // ����������� �����������

	//���� �����
	int* years_of_live;

	//�������
	string get_fullname() override;
	int* get_years_of_live();
	string get_name_books() override;

	//�������
	void set_fullname(string fullname)override;
	void set_years_of_live(int* years_of_live);
	void set_name_books(string name_books)override;
};

