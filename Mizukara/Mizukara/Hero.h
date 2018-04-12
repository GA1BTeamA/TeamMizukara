#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

enum {
	LEFT,
	RIGHT,
};

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

	HitBox* m_p_hit_box;//当たり判定
};