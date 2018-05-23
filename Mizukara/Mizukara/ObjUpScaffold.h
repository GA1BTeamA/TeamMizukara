#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//ギミック1(上がる足場)クラス
class ObjUpScaffold :public CObj
{
public:
	ObjUpScaffold();
	~ObjUpScaffold();

	void Action();
	void Draw();

	void AddY(float y) { m_y += y; }

private:
	float m_x;//位置
	float m_y;

	float m_gx;  //グラフィック位置
	float m_gy;

	HitLine* m_hit_line_UpSc[4];//当たり判定
};

