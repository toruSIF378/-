#pragma once
class VECTOR2
{
public:
	int Flag;
	VECTOR2();
	VECTOR2(int x, int y);
	~VECTOR2();
	int x;
	int y;
	int image;
	// ������Z�q
	VECTOR2& operator = (const VECTOR2& vec);	//���Z�q�Ƃ��Ďg��Ȃ��ꍇ�擪��"operator"������
												// �Y�������Z�q
	int& operator[](int i);	//����0����1�@����ȊO�͂�

							//��r���Z�q
	bool operator == (const VECTOR2& vec) const;		//true false�̃u�[���^��Ԃ�
	bool operator != (const VECTOR2& vec) const;

	//�P�����Z�q
	VECTOR2& operator += (const VECTOR2& vec);	//�l�������������Ȃ��悤��const������
	VECTOR2& operator -= (const VECTOR2& vec);	//�l�������������Ȃ��悤��const������
	VECTOR2& operator *= (int k);
	VECTOR2& operator /= (int k);
	VECTOR2 operator+()const;
	VECTOR2 operator-()const;
};

//	�x�N�g���̉��Z
// VECTOR2 + VECTOR2
//�Ԃ�l�̌^�@operator�@���Z�q�i����1�A�c�j;
VECTOR2 operator +(const VECTOR2& i, const VECTOR2& j);
// int + VECTOR2
VECTOR2 operator +(int j, const VECTOR2& i);
// VECTOR2 - VECTOR2
VECTOR2 operator -(const VECTOR2& i, const VECTOR2& j);
// int * VECTOR2
VECTOR2 operator *(int j, const VECTOR2& i);
// VECTOR2 *int
VECTOR2 operator *(const VECTOR2& i, int j);
// VECTOR2 / int
VECTOR2 operator /(const VECTOR2& i, int j);

VECTOR2 operator %(const VECTOR2& i, int j);