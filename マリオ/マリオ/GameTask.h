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

// 画面遷移用
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
	GameTask(const GameTask&) {}		//コピーコンストラクタのprivate化
	GameTask operator=(const GameTask&) {}	//代入をprivate化
	~GameTask();

public:
	static GameTask &GetInstance(void) {
		static GameTask gInstance;	// GameTaskの実体を生成。gInstanceに保存する
		return gInstance;
	}

	int SystemInit(void);
	int GameUpDate(void);	//ゲームループメイン

	Player*p;	//プレイヤーオブジェクト
	Enemy*e;	//エネミーオブジェクト
	Stage*s;	//ステージオブジェクト
	CollisionCheck*cCheck;


	char KeyData[256], KeyDataOld[256];

	int playerObjectCnt;   // ﾌﾟﾚｲﾔｰｶｳﾝﾄ 
	int enemyObjectCnt;

	int stageObjectCnt;    // フィールドｶｳﾝﾄ 

	void addPlayerObjectCnt();    // ﾌﾟﾚｲﾔｰｶｳﾝﾄ追加 
	void removePlayerObjectCnt(); // ﾌﾟﾚｲﾔｰｶｳﾝﾄ削除 

	void addEnemyObjectCnt();    // エネミーカウント追加 
	void removeEnemyObjectCnt(); // エネミーカウント削除 

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