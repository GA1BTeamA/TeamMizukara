#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//ギミック2の下がるブロッククラス
class ObjDownBlock :public CObj
{
public:
	ObjDownBlock();
	~ObjDownBlock();

	void Action();
	void Draw();

private:
	float m_x;//位置
	float m_y;

	HitLine* m_hit_line_DwBl[4];//当たり判定
};