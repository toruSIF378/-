#include"VECTOR2.h"
#include "Enemy.h"
#include"GameTask.h"
#include"Player.h"
#include"ImageMng.h"

Enemy::Enemy()
{
	SystemInit();
	Init();
	GameTask::GetInstance().addEnemyObjectCnt();	//�v���C���[�J�E���g+1
}

Enemy::~Enemy()
{
	GameTask::GetInstance().removeEnemyObjectCnt();	//�v���C���[�J�E���g-1
}

void Enemy::SystemInit()
{
}

void Enemy::Init()
{
	ImageMng::GetInstance().SetID("kameRed", "image/�m�R�m�R(��)");
	//-------�A�j���[�V�����̓o�^
	VECTOR2 divSize = { 40,64 };
	VECTOR2 divNum = { 3,1 };

	//�t���O
	lrFlag = 1;
	hitFlag = 	true;
	G = 0.9f;//�d��

	//�����֘A
	enemySpeed = 5;
	animCnt = 0;

	enemyX = 650;
	enemyY = 100;
	sizeX =  40;
	sizeY = 64;
	/*tmpX = 0;
	tmpY = 0;*/
}

void Enemy::Update()
{
	enemyX += enemySpeed;
	lrFlag = 1;
}

void Enemy::Draw()
{
	ImageMng::GetInstance().DrawImage("kameRed", enemyX - size.x / 2, enemyY - size.y / 2,
		animCnt / 15 % 3, true);
}
