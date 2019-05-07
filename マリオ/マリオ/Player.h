#pragma once
#include <memory>
#include<list>
#include <vector>
#include"VECTOR2.h"
#include"CollisionCheck.h"
#include"CHARA_BASE.h"

class Stage;



typedef struct {
	float speed,fallSpeed;	//�ړ����x
	float moveX,moveY;	//�ړ���
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
	// �L�����N�^���}�b�v�Ƃ̓����蔻����l�����Ȃ���ړ�����
	int CharMove(float *X, float *Y, float *DownSP,
				float MoveX, float MoveY, float Size, char *JumpFlag);
	int GetChipParam(float x, float y);
	int MapHitCheck(float X, float Y, float *MoveX, float *MoveY);
	
private:
	//�t���O
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
	
	//JumpFlag��Ԃ�
	int GetJumpFlag() {
		return jumpFlag;
	}

	//�W�����v�t���O���Z�b�g����
	int SetJumpFlag(int flag) {
		if (flag == true) {
			jumpFlag = true;//�W�����v��
		}
		else {
			jumpFlag = false;//�W�����v������Ȃ�
		}
	}

	//RunFlag��Ԃ�
	int GetRunFlag() {
		return runFlag;
	}

	//�����t���O���Z�b�g����
	int SetRunFlag(int flag) {
		if (flag == true) {
			runFlag = true;//�W�����v��
		}
		else {
			runFlag = false;//�W�����v������Ȃ�
		}
	}

	//RunFlag��Ԃ�
	int GetHitFlag() {
		return hitFlag;
	}

	//�����t���O���Z�b�g����
	int SetHitFlag(int flag) {
		if (flag == true) {
			hitFlag = true;//�W�����v��
		}
		else {
			hitFlag = false;//�W�����v������Ȃ�
		}
	}
	
};