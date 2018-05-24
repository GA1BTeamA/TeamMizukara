#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//ギミック3(動かす足場)クラス
class ObjMoveBlock :public CObj
{
public:
	ObjMoveBlock();
	~ObjMoveBlock();
	void Action();
	void Draw();

	float GetX() { return m_x; }
	float GetY() { return m_y; }

	void AddX(float x) { m_x += x; }
	void AddY(float y) { m_y += y; }

private:
	float m_x;//位置
	float m_y;

	HitLine* m_hit_line_MoBl[4];//左当たり判定
};

