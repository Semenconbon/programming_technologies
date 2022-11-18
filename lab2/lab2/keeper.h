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

	void add_sign(string surname, string name, string sign, int* date);
	void delete_sign();
	//сохранение и чтение файла
	void Save();
	void Read();

	//сортировка
	void sort(SIGN* sg, int size); // TODO
};

