#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//主人公クラス
class CHero : public CObj
{
public:
	CHero();
	~CHero();
	void Action();
	void Draw();
private:
	float m_x; //位置
	float m_y;
	float m_vx;//移動ベクトル
	float m_vy;
	bool m_direc;//向き

	bool m_down;//衝突確認用

	HitLine* m_p_hit_line;//当たり判定
};