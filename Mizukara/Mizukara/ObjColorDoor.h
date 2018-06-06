#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//ギミック8(色付きドア？扉？門？)クラス
class ObjColorDoor :public CObj
{
public:
	ObjColorDoor();
	~ObjColorDoor();
	void Action();
	void Draw();

	void AddY(float y) { m_y += y; }

private:
	float m_x;//位置
	float m_y;
	float m_x2;//位置
	float m_y2;

	//float m_gx;  //グラフィック位置
	//float m_gy;

	HitLine* m_hit_line_ColorDoor[4];//当たり判定
};

