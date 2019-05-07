#include "VECTOR2.h"

VECTOR2::VECTOR2()
{
	x = 0;
	y = 0;
}

VECTOR2::VECTOR2(int x, int y)
{
	this->x = x;	
	this->y = y;
}

VECTOR2::~VECTOR2()
{
}

// ������Z�q
VECTOR2 & VECTOR2::operator=(const VECTOR2 & vec)	//&�͎Q�ƎQ�Ɠn��
{
	this->x = vec.x;	//�Q�ƂŎ󂯎��ꍇ�̓R���}
	this->y = vec.y;
	return *this;		//�Q�ƂŕԂ��ۂ̓A�h���X�ł͂Ȃ����̂�Ԃ�
}

// �Y�������Z�q
int & VECTOR2::operator[](int i)
{
	if (i == 0) {
		//return this->x;
		return x;
	}
	else if(i == 1) {
		//return this->y;
		return y;
	}
	else {
		//return this->x;
		return x;
	}
	
}


//��r���Z�q
bool VECTOR2::operator==(const VECTOR2 & vec) const
{
	return((this->x == vec.x) && (this->y == vec.y));
	
}
//��r���Z�q
bool VECTOR2::operator!=(const VECTOR2 & vec) const
{
	return !((this->x == vec.x) && (this->y == vec.y));
}


//�P�����Z�q
VECTOR2 & VECTOR2::operator+=(const VECTOR2 & vec)
{
	this->x += vec.x;	
	this->y += vec.y;
	return *this;
}
//�P�����Z�q
VECTOR2 & VECTOR2::operator-=(const VECTOR2 & vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	return *this;
}
//�P�����Z�q
VECTOR2 & VECTOR2::operator*=(int k)
{
	this->x *= k;
	this->y *= k;
	return *this;
}
//�P�����Z�q
VECTOR2 & VECTOR2::operator/=(int k)
{
	this->x /= k;
	this->y /= k;
	return *this;
}
//�P�����Z�q
VECTOR2 VECTOR2::operator+() const
{
	return *this;
}
//�P�����Z�q
VECTOR2 VECTOR2::operator-() const
{
	//	������̏�����
	/*VECTOR2 vec;
	vec.x = -this->x;
	vec.y = -this->y;
	return vec;*/

	return VECTOR2(-this->x,-this->y);
}

VECTOR2 operator+(const VECTOR2 & i, const VECTOR2 & j)
{
	VECTOR2 vec;
	vec.x = i.x + j.x;
	vec.y = i.y + j.y;
	return vec;
	// ��s�ŏ������@
	//return VECTOR2(i.x + j.x, i.y + j.y);

}

VECTOR2 operator+(int j, const VECTOR2 & i)
{
	VECTOR2 vec;
	vec.x = j + i.x;
	vec.y = j + i.y;
	return vec;
}

VECTOR2 operator-(const VECTOR2 & i, const VECTOR2 & j)
{
	VECTOR2 vec;
	vec.x = i.x - j.x;
	vec.x = i.y - j.y;
	return vec;
	// ��s�ŏ������@
	//return VECTOR2(i.x - j.x, i.y - j.y);
}

VECTOR2 operator*(int j, const VECTOR2 & i)
{
	VECTOR2 vec;
	vec.x = j * i.x;
	vec.y = j * i.y;
	return vec;
	// ��s�ŏ������@
	//return VECTOR2(j * i.x,j * i.y);
}

VECTOR2 operator*(const VECTOR2 & i, int j)
{
	VECTOR2 vec;
	vec.x = i.x * j;
	vec.y = i.y *j;
	return vec;
	// ��s�ŏ������@
	//return VECTOR2(i.x * j, i.y * j);
}

VECTOR2 operator/(const VECTOR2 & i, int j)
{
	VECTOR2 vec;
	vec.x = i.x / j;
	vec.y = i.y / j;
	return vec;
	// ��s�ŏ������@
	//return VECTOR2(i.x / j, i.y / j);
}

VECTOR2 operator%(const VECTOR2 & i, int j)
{
	VECTOR2 vec;
	vec.x = i.x % j;
	vec.y = i.y % j;
	return vec;

}
