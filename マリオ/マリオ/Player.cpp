#include "DxLib.h"
#include"VECTOR2.h"
#include "Player.h"
#include"GameTask.h"
#include"Stage.h"
#include"ImageMng.h"
#include"KeyMng.h"


//�ϐ���`
CHARACTER player;
BLOCK block;

Player::Player()
{
	SystemInit();
	Init();
	GameTask::GetInstance().addPlayerObjectCnt();	//�v���C���[�J�E���g+1
}
Player::Player(int a, int b)
{
	SystemInit();
	player.x = a;
	player.y = b;
}
Player::~Player()
{
	GameTask::GetInstance().removePlayerObjectCnt();	//�v���C���[�J�E���g-1
}

void Player::SystemInit()
{
	
}

void Player::Init()
{
	

	//-------�A�j���[�V�����̓o�^
	VECTOR2 divSize = {40,64 };
	VECTOR2 divNum = { 3,1};

	//�摜�o�^
	ImageMng::GetInstance().SetID("pStopImage", "image/�}���Istop.png");
	ImageMng::GetInstance().SetID("pRunImage", "image/�}���Irun.png", divSize, divNum);
	ImageMng::GetInstance().SetID("pRunImage2", "image/�}���Irun2.png", divSize, divNum);
	ImageMng::GetInstance().SetID("jumpImage", "image/�}���Ijump.png", divSize, divNum);
	
	player.speed = 5;
	player.moveY = 0;
	player.moveX = 0;
	player.animCnt = 0;
	player.JumpPow = 10;
	G = 0.9f;//�d��

	//�t���O
	lrFlag = 1;
	hitFlag = true;
	jumpFlag = false;
	movFlag = false;

	abs(player.x - block.x) < player.w + block.w;
	player.x = 450;
	player.y = 373;
	player.w = 40;
	player.h = 64;
	//�A�j���[�V�������[�v���Z�b�g����
	size = { 40,64 };
	tmpX = 0;
	tmpY = 0;
	player.y_prev = 0;
	Dummy = 0.0f; 
	
}

void Player::Update()
{
	//���E�ړ�����
	if (KeyMng::GetInstance().newKey[P1_RIGHT]) {
		player.x+=player.speed;
		movFlag = true;
		lrFlag = true;
	}
	else {
		movFlag = false;
	}
	if (KeyMng::GetInstance().newKey[P1_LEFT]) {
		player.x -= player.speed;
		movFlag = true;
		lrFlag = false;
	}
	else {
		movFlag = false;
	}

	//�W�����v����
	if ((KeyMng::GetInstance().newKey[P1_C]) && (jumpFlag == false))
	{
		jumpFlag = true;
		hitFlag = false;
		player.JumpPow;

	}
	//�W�����v��
	if (jumpFlag == true) {
		player.JumpPow -= G;
		player.y -= player.JumpPow;
	}
	else {
		jumpFlag == false;
		if (jumpFlag == false) {
			HitCheck();
		}
		if ((jumpFlag == false) && (hitFlag == false)) {
			HitCheck();
		}
	}
	//player.JumpPow -= 1;
	if (hitFlag == false) {
		//��������
		player.y += G;
		// ���������x��������
		player.y -= player.JumpPow;
	}
	
	if (player.x > SCREEN_SIZE_X) {
		player.x = 0;
	}
	
	//�����蔻��
	if((abs(player.x - block.x) < player.w + block.w)
		&& (abs(player.y - block.y) < player.h + block.h))
	{
		if (hitFlag == true)
		{
			jumpFlag = false;
		}
	}

	DrawFormatString(250, 430, 0xffffff, "JumpFlagCount = %d", GetJumpFlag());
	DrawFormatString(250, 450, 0xffffff, "walkFlagCount  = %d", GetRunFlag());
	DrawFormatString(250, 470, 0xffffff, "hitFlagCount  = %d", GetHitFlag());
	DrawFormatString(50, 470, 0xffffff, "Player.y  = %d", player.y);
}

bool Player::HitCheck(/*int x, int y*/)
{
	if (hitFlag==true) {
		//�ڒn���Ă��牺�����̑��x�̓��Z�b�g
			player.y -= player.size;
	}
	return true;
	
}

int Player::CharMove(float * X, float * Y,float * DownSP, float MoveX, float MoveY, float Size, char * JumpFlag)
{
	// �����̃T�C�Y���Z�o
	hsize = Size * 0.5f;

	// �悸�㉺�ړ����������Ń`�F�b�N
	{
		// �����̃`�F�b�N�A�����u���b�N�̏�ӂɒ����Ă����痎�����~�߂�
		if (MapHitCheck(*X - hsize, *Y + hsize, &Dummy, &MoveY) == 3) *DownSP = 0.0F;

		// �E���̃`�F�b�N�A�����u���b�N�̏�ӂɒ����Ă����痎�����~�߂�
		if (MapHitCheck(*X + hsize, *Y + hsize, &Dummy, &MoveY) == 3) *DownSP = 0.0F;

		// ����̃`�F�b�N�A�����u���b�N�̉��ӂɓ������Ă����痎��������
		if (MapHitCheck(*X - hsize, *Y - hsize, &Dummy, &MoveY) == 4) *DownSP *= -1.0F;

		// �E��̃`�F�b�N�A�����u���b�N�̉��ӂɓ������Ă����痎��������
		if (MapHitCheck(*X + hsize, *Y - hsize, &Dummy, &MoveY) == 4) *DownSP *= -1.0F;

		// �㉺�ړ����������Z
		*Y += MoveY;
	}

	//��ɍ��E�ړ����������Ń`�F�b�N
	{
		//�����̃`�F�b�N
		MapHitCheck(*X - hsize, *Y + hsize, &MoveX, &Dummy);

		//�E���̃`�F�b�N
		MapHitCheck(*X + hsize, *Y + hsize, &MoveX, &Dummy);

		//����̃`�F�b�N
		MapHitCheck(*X - hsize, *Y - hsize, &MoveX, &Dummy);

		//�E��̃`�F�b�N
		MapHitCheck(*X + hsize, *Y - hsize, &MoveX, &Dummy);

		*X += MoveX;
	}

	// �ڒn����
	{
		// �L�����N�^�̍����ƉE���̉��ɒn�ʂ����邩���ׂ�
		if (GetChipParam(*X - Size * 0.5F, *Y + Size * 0.5F +  1.0F) == 0 &&
			GetChipParam(*X + Size * 0.5F, *Y + Size * 0.5F + 1.0F) == 0)
		{
			// ���ꂪ����������W�����v���ɂ���
			*JumpFlag = true;
		}
		else
		{
			// ���ꂪ�݂�����ڒn���ɂ���
			*JumpFlag = false;
		}
	}
	return 0;
}

int Player::GetChipParam(float x, float y)
{
	//int MapData[MAP_W][MAP_H];
	player.x = x / CHIP_SIZE;
	player.y = y / CHIP_SIZE;

	if (player.x >= MAP_W || player.y >= MAP_H || player.x < 0 || player.y < 0) {
		return 0;
	}
	return 0;
}

int Player::MapHitCheck(float X, float Y, float * MoveX, float * MoveY)
{
	return 0;
}

void Player::Draw()
{
	player.animCnt++;
	if ((KeyMng::GetInstance().newKey[P1_LEFT])&&(lrFlag == false)) {
		ImageMng::GetInstance().DrawImage("pRunImage", player.x - size.x / 2, player.y - size.y / 2,
			player.animCnt /10 % 3 , true);
	}
	else if ((KeyMng::GetInstance().newKey[P1_RIGHT])&&(lrFlag == true))
	{
		ImageMng::GetInstance().DrawImage("pRunImage2", player.x - size.x / 2, player.y - size.y / 2,
			player.animCnt / 10 % 3 , true);
	}else if (jumpFlag == true) {
		ImageMng::GetInstance().DrawImage("jumpImage", player.x - size.x / 2, player.y - size.y / 2,
			player.animCnt / 10 % 3, true);
	}
	else {
		ImageMng::GetInstance().DrawImage("pStopImage", player.x - size.x / 2, player.y - size.y / 2, true);
	}
	
	
	ImageMng::GetInstance().DrawImage("pJumpImage", player.x - size.x / 2, player.y - size.y / 2,
		player.animCnt / 10 % 4, true);

	DrawBox(player.x - size.x / 2, player.y - size.y / 2,
		player.x + size.x / 2, player.y + size.y /22,
		0xffff00, false);
}



