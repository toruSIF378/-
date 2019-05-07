#include "KeyMng.h"
#include"Player.h"

void KeyMng::Init()
{
	//フラグ全クリア
	for(int i=0;i<KEY_MAX;i++){
		newKey[i]=0;
		trgKey[i]=0;
		oldKey[i] = 0;
		upKey[i]=0;
	}
}

bool KeyMng::Update()
{
	//キー情報更新
	newKey[P1_RIGHT] = 0;
	newKey[P1_LEFT] = 0;
	newKey[P1_A] = 0;
	newKey[P1_B] = 0;
	newKey[P1_C] = 0;

	if (CheckHitKey(KEY_INPUT_RIGHT)) newKey[P1_RIGHT] = 1;
	if (CheckHitKey(KEY_INPUT_LEFT)) newKey[P1_LEFT] = 1;
	if (CheckHitKey(KEY_INPUT_LSHIFT)) newKey[P1_B] = 1;
	if (CheckHitKey(KEY_INPUT_SPACE)) newKey[P1_A] = 1;
	if (CheckHitKey(KEY_INPUT_C)) newKey[P1_C] = 1;


	//p2
	//省略

	//トリガand アップ
	for (int i = 0; i < KEY_MAX; i++) {
		trgKey[i] = newKey[i] & ~oldKey[i];//トリガ
		upKey[i] = ~newKey[i] & oldKey[i];//アップ

		//次ループの準備
		oldKey[i] = newKey[i];
	}
	return true;
}
