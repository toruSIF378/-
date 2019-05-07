#pragma once
#include <memory>
#include<list>
#include <vector>
#include"VECTOR2.h"
#include"CollisionCheck.h"
#include"CHARA_BASE.h"

class Stage;



typedef struct {
	float speed,fallSpeed;	//移動速度
	float moveX,moveY;	//移動量
	int animCnt;
	int JumpPow;
	
	float size;
	float x, y,h,w,image;
	float y_prev;
} CHARACTER;


extern CHARACTER player;
extern RECT Pl, Bl;
//extern IMAGE mario;



class Player:public CHARA_BASE
{
public:
	Player();
	Player(int,int);
	~Player();

	void SystemInit();	
	void Init();
	void Update();
	bool HitCheck(/*int,int*/);
	void Draw();
	// キャラクタをマップとの当たり判定を考慮しながら移動する
	int CharMove(float *X, float *Y, float *DownSP,
				float MoveX, float MoveY, float Size, char *JumpFlag);
	int GetChipParam(float x, float y);
	int MapHitCheck(float X, float Y, float *MoveX, float *MoveY);
	
private:
	//フラグ
	bool movFlag; 
	bool jumpFlag; 
	bool lrFlag;	
	bool hitFlag;
	bool runFlag;
	 
	float G; 

	float left, right, top, bottom;
	MOV_DIR dir;
	int tmpX,tmpY;
	float Dummy;
	float hsize;

	
	float afX, afY;
	
	//JumpFlagを返す
	int GetJumpFlag() {
		return jumpFlag;
	}

	//ジャンプフラグをセットする
	int SetJumpFlag(int flag) {
		if (flag == true) {
			jumpFlag = true;//ジャンプ中
		}
		else {
			jumpFlag = false;//ジャンプ中じゃない
		}
	}

	//RunFlagを返す
	int GetRunFlag() {
		return runFlag;
	}

	//ランフラグをセットする
	int SetRunFlag(int flag) {
		if (flag == true) {
			runFlag = true;//ジャンプ中
		}
		else {
			runFlag = false;//ジャンプ中じゃない
		}
	}

	//RunFlagを返す
	int GetHitFlag() {
		return hitFlag;
	}

	//ランフラグをセットする
	int SetHitFlag(int flag) {
		if (flag == true) {
			hitFlag = true;//ジャンプ中
		}
		else {
			hitFlag = false;//ジャンプ中じゃない
		}
	}
	
};