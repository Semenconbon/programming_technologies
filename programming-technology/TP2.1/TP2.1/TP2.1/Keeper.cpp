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
	ofstream out;          // ����� ��� ������
	out.open("data.txt"); // �������� ���� ��� ������
	if (out.is_open())
	{
		for (int i = 0; i < size_p; i++) {
			out << p[i].get_fullname() << endl;
			out << p[i].get_years_of_live() << endl;
			out << p[i].get_name_books() << endl;
		}
	}
	out.close();
}

void Keeper::Read()
{
	string fn;//����� ���
	int yol;//����
	string new_name_of_book;
	ifstream in("data.txt");
	if (in.is_open())
	{

		for (int i = 0; 0 < size_p; i++) {
			//�������
			p[i].set_fullname("NULL");
			p[i].set_years_of_live(nullptr);
			p[i].set_name_books("NULL");

			getline(in, fn);

			in >> yol;
			//getline(in, yol);
			getline(in, new_name_of_book);

			

			p[i].set_fullname(fn);
			p[i].set_years_of_live(&yol);
			p[i].set_name_books(new_name_of_book);

			cout << p[i].get_fullname() << p[i].get_years_of_live() << p->get_name_books() << endl;
		}
		
	}
	in.close();     // ��������� ����
}
