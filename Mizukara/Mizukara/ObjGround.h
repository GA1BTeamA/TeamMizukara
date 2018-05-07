#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//地面クラス
class CObjGround : public CObj
{
public:
	CObjGround();
	~CObjGround();
	void Action();
	void Draw();

	int GetGY() { return m_gy; }  //m_gy取得用
	int GetScroll() { return m_scroll; }  //m_scroll取得用
	int GetGX() { return m_gx; }  //m_gy取得用

private:
	float m_gx; //位置
	float m_gy;

	HitLine* m_p_hit_line_ground[5];//当たり判定

	float m_scroll;//左右スクロール用
};