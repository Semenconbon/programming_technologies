#pragma once
#include "curves.h"

class Ellipse : public Curves
{
private:
	float a, b; // ������� � ����� �������
public:
	virtual ~Ellipse();
	
	virtual void calculateY();
	virtual void setX(float newX);

	void setA(float);
	void setB(float);
};

