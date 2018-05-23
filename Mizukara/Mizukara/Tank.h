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

	void SetWater_Remaining(float water_amount) { m_water_remaining2 += water_amount; }  //水残量セット
	void SetWaveY(float* wave_y,float wave_amount);  //波の位置セット
	float* GetWaveY() { return &m_wave_y; }  //波の位置取得
	float GetWaveX() { return m_wave_x; }
	float GetWaterY() { return m_water_y; }  //水の位置取得
	float GetWaterX() { return m_water_x; }
	float GetWaterAmount() { return m_water_amount; }
	float GetWaveAmount() { return m_wave_amount; }
	float GetWater_Remaining() { return m_water_remaining2; };  //水残量セット

private:
	float m_x; //位置
	float m_y;

	float m_wave_x;//波の位置
	float m_wave_y;
	
	float im_x;//アイコンの位置
	float im_y;

	float m_water_x;  //水の位置
	float m_water_y;

	static const float m_water_amount;  //水の量変更用卍
	static const float m_wave_amount;  //波の高さ変更用卍
	float m_water_remaining;  //水の残量

	float m_water_remaining2;

	int m_ani_time1;//波アニメーション用
	int m_ani_time2;

	//float m_scroll;//左右スクロール用

	HitLine* m_p_hit_line_tank;//当たり判定
};