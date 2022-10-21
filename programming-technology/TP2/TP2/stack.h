#pragma once

#include "float_unary.h"

class Stack
{
private:
	struct Cell{
		float_unary float_unary_element;
		Cell* nextElem;
		~Cell();
	} C;
	Cell* top = nullptr;
	int size;
public:
	explicit Stack();
	explicit Stack(int);
	explicit Stack(const Stack&);

	~Stack();


	// ���������� ��������
	void pushElement(float); 
	void pushElement();
	void pop();

	// set ���������
	void setLastValue(float);
	//void setElement(float_unary);

	// ��������� ��������� ���������
	int getSize();
	float& getLastValue();
	float_unary& getLastElement();
	float_unary& getElements();
	void printStack();
	void output(Cell* a);
};

