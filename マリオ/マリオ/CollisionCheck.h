#pragma once

class CHARA_BASE;

class CollisionCheck
{
public:
	CollisionCheck() {}
	~CollisionCheck() {}
	bool RectVsRect(CHARA_BASE*,CHARA_BASE*);
	bool RectVsRectR(const CHARA_BASE&, const CHARA_BASE&);
	//const int& param(const int&, const int&);
};