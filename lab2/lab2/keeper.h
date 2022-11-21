#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>  
#include "SIGN.h"
using namespace std;
class keeper
{
private:
	SIGN* sg;
	int size;

	string* split(string str, char ch);
public:
	//конструкторы
	keeper();
	keeper(int size);
	keeper(const keeper&);
	~keeper();

	SIGN* get_sign();
	int get_size();
	
	void add_sign();
	void add_sign(string surname, string name, string sign, int* date);
	void delete_sign();

	//
	void change_data(string surname);
	//сохранение и чтение файла
	void Save();
	void Read();

	//сортировка
	void sort(); // проверить

	void search_info_by_surname(string surname);

	// задание 2
	void find_biggest_word();
};

