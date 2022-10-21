#pragma once
class float_unary
{
private:
	float value;
public:
	float_unary();
	float_unary(float);
	float_unary(const float_unary&);

	float_unary& operator--(); //���������� ����� ����������
	float_unary& operator++(); //���������� ����� ����������
	friend float_unary operator--(float_unary&, int); //����������� ������������� �����
	friend float_unary operator++(float_unary&, int); //����������� ������������� �����

	float_unary operator=(const float_unary&);
	friend float_unary& operator+(const float_unary&, float);
	friend float_unary& operator-(const float_unary&, float);
	friend float_unary& operator*(const float_unary&, float);
	friend float_unary& operator/(const float_unary&, float);
	float_unary operator+=(float);
	float_unary operator-=(float);
	float_unary operator*=(float); 
	float_unary operator/=(float);

	float& getValue();
	void setValue(float);
};

