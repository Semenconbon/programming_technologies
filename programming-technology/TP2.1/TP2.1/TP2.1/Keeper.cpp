#include "Keeper.h"

int Keeper::get_of_number_poet()
{
	return size_p;
}

void Keeper::add_poet(string fullname, int* years_of_live, string name_books)
{
	p[size_p].set_fullname(fullname);
	p[size_p].set_years_of_live(years_of_live);
	p[size_p].set_name_books(name_books);
	this->size_p++;
}

Keeper::Keeper()
{
	this->size_p = 0;
	p = new Poet[10];
}


Poet Keeper::get_poet(int id)
{
	if (id >= size_p) { cout << "������ �� ��������!" << endl; return p[0]; }//TODO: ������ �� ��������! 
	return p[id];
}

void Keeper::Save()
{
    //ifstream in("data"); // ��������� ���� ��� ����������
	ofstream out("data", ios::binary); // ��������� ���� ��� ������
	int x = 100;
	double y = 5.6;
	out.write((char*)&x, sizeof(x));        //���������� � ���� �������� "x"
	out.write((char*)&y, sizeof(y));        //���������� � ���� �������� "y"
	out.write((char*)&y, sizeof(y));        //���������� � ���� �������� "y"
	out.close();
}

void Keeper::Read()
{
	ifstream in("data");
}
