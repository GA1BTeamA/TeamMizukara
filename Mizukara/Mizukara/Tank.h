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

	float m_x1;//水位置
	float m_y1;
	

	float im_x;//アイコンの位置
	float im_y;

	float m_water_x;  //水の表示位置
	float m_water_y;

	int m_ani_time1;
	int m_ani_time2;
	//float m_scroll;//左右スクロール用

	//static const float m_Wave_Shrinking;

	HitLine* m_p_hit_line_tank;//当たり判定
};