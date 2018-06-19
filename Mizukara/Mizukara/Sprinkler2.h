#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//スプリンクラークラス
class CSPRI2 : public CObj
{
public:
	CSPRI2();
	~CSPRI2();
	void Action();
	void Draw();

	HitLine* GetHitLineSpri2() { return m_p_hit_line_spri2; }
	bool GetCrearCnt2() { return m_CrearCnt2; }
	//float GetTankRemaining() { return m_TankRemaining; }

private:
	float m_x; //Sprinklerの位置
	float m_y;
	float m_x1;
	float m_y1;

	float m_vy;
	float m_sy;

	float im_x;//アイコンの位置
	float im_y;

	float m_wave_x;
	float m_wave_y;

	float m_water_x;
	float m_water_y;

	float m_fx;  //花の位置
	float m_fy;

	int m_ani_time1;//アニメーション
	int m_ani_time2;
	int m_ani_time3;
	int m_ani_time4;
	int m_ani_time5;
	int m_ani_time6;

	bool m_BrackBackDraw;//クリア後の黒背景表示するしない用
	float m_BrackBackDrawCnt;//黒背景拡縮カウント用

	float m_BrackBack_x;//黒背景の位置
	float m_BrackBack_y;
	float m_BrackBack_sx;//黒背景拡縮
	float m_BrackBack_sy;

	int count;
	bool m_CrearCnt2;  //クリア出すためのカウント
	bool m_Flower;  //花咲かせるためのカウント卍

					//float g_TankRemaining;  //タンクの残量

	static const float m_WaveSize_x;
	static const float m_WaveSize_y;

	int m_move1;//主人公アニメーションの動き
	int m_move2;//スプリンクラーから出る水
	int m_move3;

	HitLine* m_p_hit_line_spri2;//当たり判定
};