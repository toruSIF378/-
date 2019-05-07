#pragma once
#include "DxLib.h"
#include"VECTOR2.h"
#include"Player.h"

#define CHIP_SIZE	32			// マップチップ一つのドットサイズ
#define MAP_W	16		// マップの幅
#define MAP_H	19			// マップの縦長さ

typedef struct{
	int x, y,h,w ;
}BLOCK;
extern BLOCK block;

class Stage
{
public:
	Stage();
	~Stage();
	void Init();
	void Update();
	void Draw();
	int i, j;
	
	int stage1Image;
	
	int MapData[MAP_H][MAP_W];
	
private:

};