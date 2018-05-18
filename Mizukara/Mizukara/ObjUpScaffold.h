#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//ギミック1の上がる足場クラス
class ObjUpScaffold :public CObj
{
public:
	ObjUpScaffold();
	~ObjUpScaffold();

	void Action();
	void Draw();

private:
	float m_x;//位置
	float m_y;

	HitLine* m_hit_line_UpSc[4];//当たり判定
};

