#include "keeper.h"

string* keeper::split(string str, char ch)
{
	stringstream stream(str);
	string* s = new string();
	int size = 0;
	std::string item;
	while (getline(stream, item, ch)) {
		size++;
		string* new_s = new string[size];
		for (int i = 0; i < size - 1; i++) {
			new_s[i] = s[i];
		}
		new_s[size - 1] = item;
		s = new_s;
	}
	stream.flush();
	return s;
}

keeper::keeper()
{
	size = 0;
	sg = new SIGN[size];
}

keeper::keeper(int size)
{
	this->size = size;
	sg = new SIGN[this->size];
}

keeper::keeper(const keeper& ref)
{
	this->sg = ref.sg;
	this->size = ref.size;
}

keeper::~keeper()
{
	cout << "������ ���������� ~keeper" << endl;
}

void keeper::add_sign(string surname, string name, string sign, int* date)
{
	this->size++;
	SIGN* new_sg = new SIGN[size];
	for (int i = 0; i < size - 1; i++)
		new_sg[i] = sg[i];
	new_sg[size - 1].set_surname(surname);
	new_sg[size - 1].set_name(name);
	new_sg[size - 1].set_sign(sign);
	new_sg[size - 1].set_date_of_birth(date);
	sg = new_sg;
}

void keeper::Save()
{
	ofstream out;          // ����� ��� ������
	out.open("data.txt");  // �������� ���� ��� ������
	bool firstIteration = true;   // �������� �� ������ ������ � ���������� (��������� ������� \n)
	if (out.is_open())
	{
		for (int i = 0; i < size; i++) {
			if (firstIteration == true) firstIteration = false;
			else out << "\n";
			//�������;���;���� �������;���� ��������
			out << sg->get_surname() << " ";
			out << sg->get_name() << " ";
			out << sg->get_sign() << " ";
			for (int i = 0; i < 3; i++)
			{
				out << sg->get_date_of_birth()[i] << " ";
			}
		}
	}
	out.close();
}

SIGN* keeper::get_sign()
{
	return sg;
}

void keeper::Read()
{
	string surname;
	string name;
	string sign;
	string date_str;
	int date[3];
	ifstream in("data.txt");
	if (in.is_open())
	{
		while (!in.eof()) {
			in >> surname;
			in >> name;
			in >> sign;
			in >> date[0];
			in >> date[1];
			in >> date[2];
			add_sign(surname, name, sign, date);
			//�������� �� ������� \n
		}
	}
}
void keeper::delete_sign()
{
	if (size == 0) { return; }
	this->size--;
	SIGN* new_sg = new SIGN[size];
	for (int i = 0; i < size; i++)
		new_sg[i] = sg[i];
	sg = new_sg;
}
void sort(SIGN* sg, int size) {
	SIGN temp; // ��������� ���������� ��� ������ ��������� �������

	// ���������� ������� ���������
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (sg[j].get_date_of_birth()[2] > sg[j + 1].get_date_of_birth()[2]) {
				// ������ �������� �������
				temp = sg[j];
				sg[j] = sg[j + 1];
				sg[j + 1] = temp;
			}
		}
	}
}
