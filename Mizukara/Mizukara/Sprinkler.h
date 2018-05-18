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

	HitLine* GetHitLineSpri() { return m_p_hit_line_spri; }

private:
	float m_x; //Sprinklerの位置
	float m_y;
	float m_x1;
	float m_y1;

	float im_x;//アイコンの位置
	float im_y;

	float m_wave_x;
	float m_wave_y;

	float m_water_x;
	float m_water_y;

	int m_ani_time1;//アニメーション
	int m_ani_time2;
	int m_ani_time3;
	int m_ani_time4;

	int count;

	static const float m_WaveSize_x;
	static const float m_WaveSize_y;

	int m_move1;//主人公アニメーションの動き
	int m_move2;//スプリンクラーから出る水

	HitLine* m_p_hit_line_spri;//当たり判定
};