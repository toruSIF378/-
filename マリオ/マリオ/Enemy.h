#pragma once
#include "DxLib.h"
#include "CHARA_BASE.h"



class Enemy:public CHARA_BASE
{
public:
	Enemy();
	~Enemy();
	void SystemInit();
	void Init();
	void Update();
	void Draw();
private:
	//フラグ
	bool lrFlag;	//右を向いてるか、左を向いてるか
	bool hitFlag;//当たったか当たってないか
	bool walkFlag;//
	MOV_DIR dir;
	int kameRedImage[10];
	float G;


	float enemySpeed;//移動速度
	int animCnt;
	float sizeX,sizeY;
	float enemyX, enemyY, enemyH, enemyW;
};