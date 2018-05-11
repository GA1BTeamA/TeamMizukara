#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//WTMクラス
class CWTM : public CObj
{
public:
	CWTM();
	~CWTM();
	void Action();
	void Draw();
private:
	float m_x; //WTMの位置
	float m_y;
	float m_x1;
	float m_y1;
	float m_x2;
	float m_y2;

	float im_x;//アイコンの位置
	float im_y;

	int m_ani_time1;
	int m_ani_time2;

	HitLine* m_p_hit_line_wtm;//当たり判定
};