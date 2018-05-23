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

	float m_gx;//グラフィックの位置
	float m_gy;

	float m_wave_x;  //波の位置
	float m_wave_y;

	float m_water_x;  //水の位置
	float m_water_y;

	int m_ani_time1;  //波アニメーション用
	int m_ani_time2;

	static const float m_WaveSize_x;  //波のサイズ用
	static const float m_WaveSize_y;

	HitLine* m_hit_line_MoBlTank;//当たり判定
};

