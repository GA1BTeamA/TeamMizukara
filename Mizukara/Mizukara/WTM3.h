#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

class CWTM3 : public CObj
{
public:
	CWTM3();
	~CWTM3();
	void Action();
	void Draw();

private:
	float m_x; //WTMの位置
	float m_y;

	float m_wave_x;  //波の位置
	float m_wave_y;

	float im_x;//アイコンの位置
	float im_y;

	float m_water_x;  //水の位置
	float m_water_y;

	int m_ani_time1;  //波アニメーション用
	int m_ani_time2;

	static const float m_WaveSize_x;  //波のサイズ用
	static const float m_WaveSize_y;

	static const float m_water_amount;  //水の量変更用卍
	static const float m_wave_amount;  //波の高さ変更用卍
	float m_water_remaining;  //水の残量

	HitLine* m_p_hit_line_wtm3;//当たり判定
};

