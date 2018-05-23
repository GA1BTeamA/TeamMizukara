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

private:
	float m_x;//位置
	float m_y;

	float m_gx;//グラフィックの位置
	float m_gy;

	HitLine* m_hit_line_MoBl[4];//当たり判定
};

