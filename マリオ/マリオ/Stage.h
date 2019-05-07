#pragma once
#include "DxLib.h"
#include"VECTOR2.h"
#include"Player.h"

#define CHIP_SIZE	32			// �}�b�v�`�b�v��̃h�b�g�T�C�Y
#define MAP_W	16		// �}�b�v�̕�
#define MAP_H	19			// �}�b�v�̏c����

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