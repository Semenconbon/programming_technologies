#pragma once
#include "Writter.h"
class Poet : public Writter
{
public:
	Poet();
	Poet(string fullname, int* years_of_live, string name_books);// ����������� � �����-��
	Poet(const Poet &ref_Poet); // ����������� �����������
};

