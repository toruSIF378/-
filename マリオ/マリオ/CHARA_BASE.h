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
		DIR_RIGHT,	//右
		DIR_LEFT,	//左
		DIR_NON,	//
	};
	int flag;

public:
	VECTOR2 pos;
	VECTOR2 size;
	VECTOR2 mov;
	int removeFlag;

public:
	CHARA_BASE() {}	//ｺﾝｽﾄﾗｸﾀは純粋仮想関数にできない 実態を{}で省略できる
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
	int Getflag() {	//flagの状態をintで返す
		return flag;
	}

	int func() {
		flag = 1;
		return flag;
	}

	int func() const {
		//flag = 1;	//書き換えは不可能
		return flag;
	}

	void SetRemoveFlag(bool flag) {
		if (flag == 0) {
			removeFlag = REMOVE_FALSE;	//消さない
		}
		else {
			removeFlag = REMOVE_TRUE;	//消す
		}
	}
	//removeFlagを返す
	bool GetRemoveFlag() {
		return removeFlag;
	}
};

