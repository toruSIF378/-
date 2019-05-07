#pragma once
#include<vector>
#include<list>
#include<map>


const int SCREEN_SIZE_X(700);
const int SCREEN_SIZE_Y (500);
class Player;
class Stage;
class Enemy;

class CollisionCheck;

// ��ʑJ�ڗp
enum GAME_MODE {
	GAME_INIT,
	GAME_TITLE,
	GAME_MAIN,
	GAME_OVER,
	GAME_CLEAR
};
class GameTask
{
private:
	GameTask();
	GameTask(const GameTask&) {}		//�R�s�[�R���X�g���N�^��private��
	GameTask operator=(const GameTask&) {}	//�����private��
	~GameTask();

public:
	static GameTask &GetInstance(void) {
		static GameTask gInstance;	// GameTask�̎��̂𐶐��BgInstance�ɕۑ�����
		return gInstance;
	}

	int SystemInit(void);
	int GameUpDate(void);	//�Q�[�����[�v���C��

	Player*p;	//�v���C���[�I�u�W�F�N�g
	Enemy*e;	//�G�l�~�[�I�u�W�F�N�g
	Stage*s;	//�X�e�[�W�I�u�W�F�N�g
	CollisionCheck*cCheck;


	char KeyData[256], KeyDataOld[256];

	int playerObjectCnt;   // ��ڲ԰���� 
	int enemyObjectCnt;

	int stageObjectCnt;    // �t�B�[���h���� 

	void addPlayerObjectCnt();    // ��ڲ԰���Ēǉ� 
	void removePlayerObjectCnt(); // ��ڲ԰���č폜 

	void addEnemyObjectCnt();    // �G�l�~�[�J�E���g�ǉ� 
	void removeEnemyObjectCnt(); // �G�l�~�[�J�E���g�폜 

	void addStageObjectCnt();
	void removeStageObjectCnt();

	int animCnt;
	bool runFlag, lrFlag, jumpFlag, hitFlag;
	int TitleX, TitleY;
	

private:

	int GameInit(void);
	int GameTitle(void);
	int GameMain(void);
	int GameOver(void);
	int GameClear(void);

	GAME_MODE gameMode;
	int newKey;
	int oldKey;
	int trgKey;


	float X, Y, *MoveX, *MoveY;

	
};