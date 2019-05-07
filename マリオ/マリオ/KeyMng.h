#pragma once
#include"DxLib.h"
#include"VECTOR2.h"

enum KEY_CODE {
	P1_RIGHT = 0,
	P1_LEFT,
	P1_A,
	P1_B,
	P1_C,
	
	P2_RIGHT,
	P2_LEFT,
	P2_A,
	P2_B,
	P2_C,
	KEY_MAX
};

class KeyMng
{
private:
	KeyMng() { 
		Init();
	}
	KeyMng(const KeyMng&) {}
	KeyMng& operator=(const KeyMng& k) {}
	~KeyMng() {}

public:
	static KeyMng& GetInstance() {
		static KeyMng keyInst;
		return keyInst;
	}
	void Init(void);
	bool Update();	//キー情報更新

	int newKey[KEY_MAX];
	int trgKey[KEY_MAX];
	int oldKey[KEY_MAX];
	int upKey[KEY_MAX];
};