#pragma once
#define PI 3.14159265 

class Curves // ��� ����������� �����
{
protected:
	float x; // ����������, �������� �������������
	float y; // ���������� y
public:
	virtual ~Curves();
	virtual void calculateY() = 0;
	virtual void setX(float newX);	
	virtual float getY();
};

