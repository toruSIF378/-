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
	//�t���O
	bool lrFlag;	//�E�������Ă邩�A���������Ă邩
	bool hitFlag;//�����������������ĂȂ���
	bool walkFlag;//
	MOV_DIR dir;
	int kameRedImage[10];
	float G;


	float enemySpeed;//�ړ����x
	int animCnt;
	float sizeX,sizeY;
	float enemyX, enemyY, enemyH, enemyW;
};