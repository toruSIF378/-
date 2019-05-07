#pragma once
#include "VECTOR2.h"

class CHARA_BASE
{
protected:

	enum REMOVE_NAME
	{
		REMOVE_FALSE = 0,
		REMOVE_TRUE,
		REMOVE_MAX
	};

	enum MOV_DIR {
		DIR_RIGHT,	//�E
		DIR_LEFT,	//��
		DIR_NON,	//
	};
	int flag;

public:
	VECTOR2 pos;
	VECTOR2 size;
	VECTOR2 mov;
	int removeFlag;

public:
	CHARA_BASE() {}	//�ݽ�׸��͏������z�֐��ɂł��Ȃ� ���Ԃ�{}�ŏȗ��ł���
	virtual ~CHARA_BASE() {}
	virtual void SystemInit() = 0;
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	void SetHitFlag(bool b) {
		if (b == true) {
			flag = 0;
		}
	}
	int Getflag() {	//flag�̏�Ԃ�int�ŕԂ�
		return flag;
	}

	int func() {
		flag = 1;
		return flag;
	}

	int func() const {
		//flag = 1;	//���������͕s�\
		return flag;
	}

	void SetRemoveFlag(bool flag) {
		if (flag == 0) {
			removeFlag = REMOVE_FALSE;	//�����Ȃ�
		}
		else {
			removeFlag = REMOVE_TRUE;	//����
		}
	}
	//removeFlag��Ԃ�
	bool GetRemoveFlag() {
		return removeFlag;
	}
};

