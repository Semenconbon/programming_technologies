#include "SIGN.h"

SIGN::SIGN()
{
	this->surname = "null";
	this->name = "null";
	this->sign = "null";
	this->date_of_birth[0] = 0;
	this->date_of_birth[1] = 0;
	this->date_of_birth[2] = 0;
}

SIGN::SIGN(const SIGN& ref_sign)
{
	this->surname = ref_sign.surname;
	this->name = ref_sign.name;
	this->sign = ref_sign.sign;
	this->date_of_birth[0] = ref_sign.date_of_birth[0];
	this->date_of_birth[1] = ref_sign.date_of_birth[1];
	this->date_of_birth[2] = ref_sign.date_of_birth[2];
}
SIGN::SIGN(string surname, string name, string sign, int *date_of_birth)
{
	this->surname = surname;
	this->name = name;
	this->sign = sign;
	this->date_of_birth[0] = date_of_birth[0];
	this->date_of_birth[1] = date_of_birth[1];
	this->date_of_birth[2] = date_of_birth[2];
}

SIGN::~SIGN()
{
	cout << "¬ызван деструктор" << endl;
}

string SIGN::get_surname()
{
	return surname;
}

string SIGN::get_name()
{
	return name;
}

string SIGN::get_sign()
{
	return sign;
}

int* SIGN::get_date_of_birth()
{
	return date_of_birth;
}

void SIGN::set_surname(string surname)
{
	this->surname = surname;
}

void SIGN::set_name(string name)
{
	this->name = name;
}

void SIGN::set_sign(string sign)
{
	this->sign = sign;
}

void SIGN::set_date_of_birth(int* date_of_birth)
{
	*this->date_of_birth = *date_of_birth;
}


ostream& operator<<(ostream& os, const SIGN& sg)
{
	os << sg.surname <<
		"/" << sg.name <<
		"/" << sg.sign <<
		"/" << sg.date_of_birth[0] <<
		"." << sg.date_of_birth[1] <<
		"." << sg.date_of_birth[2];
	return os;
}
istream& operator>>(istream& is,  SIGN& sg)
{
	cout << "\n¬ведите фамилию" << endl;
	is >> sg.surname;
	cout << "¬ведите им€" << endl;
	is >> sg.name;
	cout << "¬ведите знак зодиака" << endl;
	is >> sg.sign;
	cout << "¬ведите дату рождени€ (день, мес€ц, год - записывать через пробел)\n" << endl;
	is >> sg.date_of_birth[0];
	is >> sg.date_of_birth[1];
	is >> sg.date_of_birth[2];
	return is;
}
