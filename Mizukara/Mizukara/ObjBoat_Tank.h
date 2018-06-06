#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//ギミック1タンククラス
class ObjBoat_Tank : public CObj
{
public:
	ObjBoat_Tank();
	~ObjBoat_Tank();
	void Action();
	void Draw();
private:
	float m_x; //ギミック4の位置
	float m_y;

	float m_gx;//グラフィックの位置
	float m_gy;

	float m_moveY;

	float m_wave_x;  //波の位置
	float m_wave_y;
	float m_wave_x2;
	float m_wave_y2;

	float m_water_x;  //水の位置
	float m_water_y;
	float m_water_x2;  
	float m_water_y2;

	int m_move_x;//ボートを動かす

	int m_ani_time1;  //波アニメーション用
	int m_ani_time2;
	int m_ani_time3;  //ボートアニメーション用

	float m_water_remaining;
	float m_bucket_remaining;

	static const float m_WaveSize_x;  //波のサイズ用
	static const float m_WaveSize_x2;
	float m_WaveSize_y;
	static const float m_WaterSize_x;//水のサイズ
	float m_WaterSize_y;
	static const float m_WaterSize_x2;
	static const float m_WaterSize_y2;

	int m_BoatAni;//ボートアニメーション(タンク)用

	float m_RopeSizeBucket;//バケツの方のロープの長さ

	HitLine* m_hit_line_BoatTank[4];//当たり判定
};
