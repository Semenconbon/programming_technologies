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
	cout << "Вызван деструктор ~keeper" << endl;
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
void keeper::add_sign()
{
	this->size++;
	SIGN* new_sg = new SIGN[size];
	for (int i = 0; i < size - 1; i++)
		new_sg[i] = sg[i];
	int date[3] = { 0, 0, 0 };
	new_sg[size - 1].set_surname("null");
	new_sg[size - 1].set_name("null");
	new_sg[size - 1].set_sign("null");
	new_sg[size - 1].set_date_of_birth(date);
	sg = new_sg;
}

void keeper::Save()
{
	ofstream out;          // поток для записи
	out.open("data.txt");  // окрываем файл для записи
	bool firstIteration = true;   // проверка на первую строку в сохранение (избежание первого \n)
	if (out.is_open())
	{
		for (int i = 0; i < size; i++) {
			if (firstIteration == true) firstIteration = false;
			else out << "\n";
			//фамилия;имя;знак зодиака;дата рождения
			out << sg[i].get_surname() << " ";
			out << sg[i].get_name() << " ";
			out << sg[i].get_sign() << " ";
			for (int j = 0; j < 3; j++)
			{
				out << sg[i].get_date_of_birth()[j];
				if (j != 2) { out << " "; }
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
			//проверка на пропуск \n
		}
	}
	in.close();

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
int keeper::get_size()
{
	return size;
}
void keeper::search_info_by_surname(string surname)
{
	for (int i = 0; i < size; i++) {
		if (sg[i].get_surname() == surname)
			cout << sg[i] << endl;
	}
}
void keeper::sort() {
	SIGN temp; // временная переменная для обмена элементов местами

	// Сортировка массива пузырьком
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			// проверка на год рождения
			if (sg[j].get_date_of_birth()[2] > sg[j + 1].get_date_of_birth()[2]) {
				temp = sg[j];
				sg[j] = sg[j + 1];
				sg[j + 1] = temp;
			}
			else if (sg[j].get_date_of_birth()[2] == sg[j + 1].get_date_of_birth()[2]) {
				// проверка на месяц рождения
				if (sg[j].get_date_of_birth()[1] > sg[j + 1].get_date_of_birth()[1]) {
					temp = sg[j];
					sg[j] = sg[j + 1];
					sg[j + 1] = temp;
				}
				else if (sg[j].get_date_of_birth()[1] == sg[j + 1].get_date_of_birth()[1]) {
					// проверка на день рождения
					if (sg[j].get_date_of_birth()[0] > sg[j + 1].get_date_of_birth()[0]) {
						// меняем элементы местами
						temp = sg[j];
						sg[j] = sg[j + 1];
						sg[j + 1] = temp;
					}
				}
			}
		}
	}
}
void keeper::find_biggest_word()
{
	string word = "";
	string biggest_word = word;
	int count = 0;

	ifstream in("data.txt");
	if (in.is_open())
	{
		while (!in.eof()) {
			in >> word;
			if (word.length() > biggest_word.length()) {
				biggest_word = word;
				count = 1;
			}
			else if (word == biggest_word) {
				biggest_word = word;
				count++;
			}
		}
	}
	if (biggest_word == "") { cout << "В файле нет слов" << endl; return; }
	cout << "Самое большое слово: " << biggest_word << endl;
	cout << "Оно повторяется: " << count << endl;

	in.close();
}
void keeper::change_data(string surname) {
	for (int i = 0; i < size; i++) {
		if (sg[i].get_surname() == surname) {
			cout << sg[i] << endl;
			cout << "Введите его новые данные:" << endl;
			cout << "_______________________________" << endl;
			try {
			cin >> sg[i];
			}
			catch (invalid_argument& e)
			{
				cerr << e.what() << endl;
				return;
			}
		}
		cout << "Новые данные:" << endl;
		cout << sg[i] << endl;
		break;
	}
}
