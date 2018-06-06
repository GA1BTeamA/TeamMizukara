#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//天秤タンククラス
class ObjScale_Tank :public CObj
{
public:
	ObjScale_Tank(float x,float y,float r1,float r2,unsigned int n);
	~ObjScale_Tank();
	void Action();
	void Draw();

private:
	unsigned int m_ScaleNo;//天秤の番号

	float m_x; //ギミック3の位置
	float m_y;
	float m_x2;
	float m_y2;

	float m_wave_x;  //波の位置
	float m_wave_y;
	float m_wave_x2;  //波の位置
	float m_wave_y2;

	float m_water_x;  //水の位置
	float m_water_y;
	float m_water_x2;  //水の位置
	float m_water_y2;

	float m_angle; //傾き
	float m_angle_x;//傾時のｘ値
	float m_angle_y;//傾時のｙ値
	float m_angle_x2;//傾時のｘ値
	float m_angle_y2;//傾時のｙ値

	int m_ani_time1;  //波アニメーション用
	int m_ani_time2;

	float m_water_remaining;
	float m_water_remaining2;

	static const float m_WaveSize_x;  //波のサイズ用
	static const float m_WaveSize_y;

	HitLine* m_hit_line_ScaleTank;//当たり判定
	HitLine* m_hit_line_ScaleTank2;//当たり判定
};

