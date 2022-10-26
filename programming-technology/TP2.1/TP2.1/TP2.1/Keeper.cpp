#include "Keeper.h"

int Keeper::get_size()
{
	return size_p;
}

void Keeper::add_poet(Poet new_p)
{
	p[size_p] = new_p;
	size_p++;
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
			out << p[i].get_years_of_birth() << endl;
			out << p[i].get_years_of_death() << endl;
			out << p[i].get_name_books() << endl;
		}
	}
	out.close();
}

void Keeper::Read()
{
	string fn;//����� ���
	int yob;//����
	int yod;//����
	string new_name_of_book;
	ifstream in("data.txt");
	if (in.is_open())
	{
		for (int i = 0; i < size_p; i++) {
			getline(in, fn);
			in >> yob;
			in >> yod;
			getline(in, new_name_of_book);//TODO: ������� ������� - ������ ����������� ��� �������� �� ������ ������
			getline(in, new_name_of_book);

			Poet new_p(fn, yob, yod, new_name_of_book);
			p[i] = new_p;

			cout << p[i].get_fullname() << p[i].get_years_of_birth() << p[i].get_years_of_death() << p[i].get_name_books() << endl;
		}
	}
	in.close(); // ��������� ����
}

void Keeper::print_poet(int id)
{
	cout << p[id].get_fullname() << endl;
	cout << p[id].get_years_of_birth() << endl;
	cout << p[id].get_years_of_death() << endl;
	cout << p[id].get_name_books() << endl;
}



