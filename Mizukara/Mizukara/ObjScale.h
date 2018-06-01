#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//ギミック5(天秤)クラス
class ObjScale :public CObj
{
public:
	ObjScale();
	~ObjScale();

	void Action();
	void Draw();

	void AddY(float y) { m_y += y; }

private:
	float m_x;//位置
	float m_y;

	HitLine* m_hit_line_Scale[4];//当たり判定
};


