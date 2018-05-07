#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//タンククラス
class CTank : public CObj
{
public:
	CTank();
	~CTank();
	void Action();
	void Draw();
private:
	float m_x; //位置
	float m_y;

	float im_x;//アイコンの位置
	float im_y;

	HitLine* m_p_hit_line_tank;//当たり判定
};