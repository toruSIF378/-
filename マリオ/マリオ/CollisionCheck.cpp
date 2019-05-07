#include"DxLib.h"
#include"CollisionCheck.h"
#include"CHARA_BASE.h"

bool CollisionCheck::RectVsRect(CHARA_BASE *a, CHARA_BASE*b)
{
	if (a->Getflag() != 1) return false;
	if (b->Getflag() != 1) return false;
	if ((a->pos.x - a->size.x / 2 < b->pos.x + b->size.x / 2)
		&& (a->pos.x + a->size.x / 2 > b->pos.x - b->size.x / 2)
		&& (a->pos.y - a->size.y / 2 < b->pos.y + b->size.y / 2)
		&& (a->pos.y + a->size.y / 2 > b->pos.y - b->size.y / 2)
		) {
		return true;
	}
	return false;
}

bool CollisionCheck::RectVsRectR(const CHARA_BASE & a, const CHARA_BASE & b)
{
	if(a.func()==1){}
	b.func();

	if ((a.pos.x - a.size.x / 2 < b.pos.x + b.size.x / 2)
		&& (a.pos.x + a.size.x / 2 > b.pos.x - b.size.x / 2)
		&& (a.pos.y - a.size.y / 2 < b.pos.y + b.size.y / 2)
		&& (a.pos.y + a.size.y / 2 > b.pos.y - b.size.y / 2)
		) {
		return true;
	}
	return false;
	return false;
}

/*const int & CollisionCheck::param(const int & a, const int & b)
{
	int ans = a + b;
	return ans;

}*/
