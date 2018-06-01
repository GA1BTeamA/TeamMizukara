#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//ギミック8タンククラス
class ObjColorDoor_Tank :public CObj
{
public:
	ObjColorDoor_Tank();
	~ObjColorDoor_Tank();
	void Action();
	void Draw();
private:
	float m_x; //ギミック2の位置
	float m_y;

	float m_gx;//グラフィックの位置
	float m_gy;

	HitLine* m_hit_line_ColorDoorTank[2];//当たり判定
};

