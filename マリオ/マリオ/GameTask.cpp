#include "DxLib.h"
#include"VECTOR2.h"
#include "CHARA_BASE.h"
#include "GameTask.h"
#include "Player.h"
#include"Enemy.h"
#include "Stage.h"
#include"KeyMng.h"
#include"ImageMng.h"
#include"CollisionCheck.h"




int GameTask::GameUpDate(void)
{
	//キー情報更新
	KeyMng::GetInstance().Update();

	switch (gameMode) {
	case GAME_INIT:
		GameInit();
		break;
	case GAME_TITLE:
		GameTitle();
		break;
	case GAME_MAIN:
		GameMain();
		break;
	case GAME_OVER:
		GameOver();
		break;
	case GAME_CLEAR:
		GameClear();
		//default;
		break;
		return 0;
	}
}

GameTask::GameTask()
{
	SystemInit();

	gameMode = GAME_INIT;
	oldKey = 0;
}

GameTask::~GameTask()
{
	delete p;
	delete s;
	delete e;
}


int GameTask::SystemInit(void)
{
	SetWindowText("1701335_吉住　達");
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1) {
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);
	return 0;
}

int GameTask::GameInit(void)
{
	DrawString(0, 0, "INIT", 0xffff00);
	if (KeyMng::GetInstance().trgKey[P1_A])gameMode = GAME_TITLE;
	ImageMng::GetInstance().SetID("TITLE", "image/タイトル.png");
	return 0;
}

int GameTask::GameTitle(void)
{
	//プレイヤー生成
	if (KeyMng::GetInstance().trgKey[P1_A])
	{
		if (p == nullptr) {
			p = new Player();	//Playerオブジェクトの生成
		}
	}

	//ステージ生成
	if (KeyMng::GetInstance().trgKey[P1_A])
	{
		if (s == nullptr) {
			s = new Stage();	//Playerオブジェクトの生成
		}
	}

	//エネミー生成
	if (KeyMng::GetInstance().trgKey[P1_A])
	{
		if (e == nullptr) {
			e = new Enemy();	//Playerオブジェクトの生成
		}
	}
	//当たり判定のインスタンス
	cCheck = new CollisionCheck();
	ImageMng::GetInstance().DrawImage("TITLE",TitleX,TitleY, true);
	DrawString(0, 0, "TITLE", 0xffff00);

	//ゲームモード移行
	if (KeyMng::GetInstance().trgKey[P1_A])gameMode = GAME_MAIN;
	return 0;
}

int GameTask::GameMain(void)
{
	
	//プレイヤー削除
	if (KeyMng::GetInstance().trgKey[P1_B])
	{
		if (p != nullptr) {
			p->SetRemoveFlag(true);
			delete(p);//実体を消す
			p = nullptr;
		}
	}

	//エネミー削除
	if (KeyMng::GetInstance().trgKey[P1_B])
	{
		if (e != nullptr) {
			e->SetRemoveFlag(true);
			delete(e);//実体を消す
			e = nullptr;
		}
	}
	//アップデート
	//-----プレイヤー
	if (p != nullptr)
	{
		p->Update();
		p->Draw();
	}
	//-----ステージ
	if (s != nullptr)
	{
		s->Update();
		s->Draw();
	}
	//-----エネミー
	if (e != nullptr) 
	{
		e->Update();
		e->Draw();
	}

	

	DrawString(0, 0, "GAME_MAIN", 0xffffff);
	return 0;
}

int GameTask::GameOver(void)
{
	DrawString(0, 0, "GameOver", 0xffffff);
	return 0;
}

int GameTask::GameClear(void)
{
	DrawString(0, 0, "GAME_CLEAR", 0xffff00);
	if (KeyMng::GetInstance().trgKey[P1_A])gameMode = GAME_TITLE;
	return 0;
}

void GameTask::addPlayerObjectCnt()
{
	playerObjectCnt++;
}

void GameTask::removePlayerObjectCnt()
{
	playerObjectCnt--;
}

void GameTask::addEnemyObjectCnt()
{
	enemyObjectCnt++;
}

void GameTask::removeEnemyObjectCnt()
{
	enemyObjectCnt--;
}

void GameTask::addStageObjectCnt()
{
	stageObjectCnt++;
}

void GameTask::removeStageObjectCnt()
{
	stageObjectCnt--;
}





