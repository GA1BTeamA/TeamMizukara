#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//ぞうさんタンククラス
class ObjElephant_Tank :public CObj
{
public:
	ObjElephant_Tank();
	~ObjElephant_Tank();
	void Action();
	void Draw();

private:
	float m_x; //ギミック3の位置
	float m_y;

	float m_moveX;
	float m_moveY;

	float m_wave_x;  //波の位置
	float m_wave_y;

	float m_water_x;  //水の位置
	float m_water_y;

	int m_ani_time1;  //波アニメーション用
	int m_ani_time2;
	int m_ani_time_Shower;//シャワーアニメーション用

	float m_water_remaining;

	static const float m_WaveSize_x;  //波のサイズ用
	float m_WaveSize_y;

	float m_alpha;//虹用の透明度

	HitLine* m_hit_line_ZTank;//当たり判定
	HitLine* m_hit_line_ZTankWall;//当たり判定
};

