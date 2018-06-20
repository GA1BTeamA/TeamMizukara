#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//ギミック3タンククラス
class ObjMoveBlock_Tank :public CObj
{
public:
	ObjMoveBlock_Tank();
	~ObjMoveBlock_Tank();
	void Action();
	void Draw();

private:
	float m_x; //ギミック3の位置
	float m_y;
	float m_x2;
	float m_y2;

	float m_moveX;
	float m_moveY;

	float m_wave_x;  //波の位置
	float m_wave_y;
	float m_wave_y2;

	float m_water_x;  //水の位置
	float m_water_y;

	int m_ani_time1;  //波アニメーション用
	int m_ani_time2;

	float m_water_remaining;
	float m_water_remaining2;

	static const float m_WaveSize_x;  //波のサイズ用
	float m_WaveSize_y;
	float m_WaveSize_y2;

	HitLine* m_hit_line_MoBlTank;//当たり判定
	HitLine* m_hit_line_MoBlTank2;//当たり判定
};

