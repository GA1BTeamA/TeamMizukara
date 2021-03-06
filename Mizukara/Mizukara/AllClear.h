#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//全クリクラス
class CAllClear : public CObj
{
public:
	CAllClear();
	~CAllClear();
	void Action();
	void Draw();
private:
	float m_x; //位置
	float m_y;

	float m_vy;//ベクトル
	float m_sy;//主人公のジャンプ用
	float m_svy;//主人公のジャンプ用ベクトル

	int m_ani_time;
};