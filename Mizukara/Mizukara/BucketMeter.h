#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//バケツメータークラス
class CBucketMeter : public CObj
{
public:
	CBucketMeter();
	~CBucketMeter();
	void Action();
	void Draw();
	void PushX();
	void PushC();
	float GetWaterRem() { return m_water_remaining; }
private:
	float m_x; //位置
	float m_y;

	float m_wave_x;//波の位置
	float m_wave_y;

	float m_water_x;  //水の位置
	float m_water_y;

	int m_ani_time1;//波アニメーション用
	int m_ani_time2;

	static const float m_BM_water_amount;  //水の量変更用卍
	static const float m_BM_wave_amount;  //波の高さ変更用卍
	float m_water_remaining;  //水の残量

};