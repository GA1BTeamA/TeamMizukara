#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//WTMクラス
class CSPRI : public CObj
{
public:
	CSPRI();
	~CSPRI();
	void Action();
	void Draw();
private:
	float m_x; //Sprinklerの位置
	float m_y;

	float m_wave_x;  //波の位置
	float m_wave_y;

	float im_x;//アイコンの位置
	float im_y;

	int m_ani_time1;  //波のアニメーション用
	int m_ani_time2;

	float m_water_x;  //水の位置
	float m_water_y;

	static const float m_WaveSize_x;  //波のサイズ用
	static const float m_WaveSize_y;

	HitLine* m_p_hit_line_spri;//当たり判定
};