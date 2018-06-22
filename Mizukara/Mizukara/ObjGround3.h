#pragma once
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"
#include "GameEngine\\FontTex.h"

//ステージ3地面クラス
class ObjGround3 : public CObj
{
public:
	ObjGround3();
	~ObjGround3();
	void Action();
	void Draw();

	void AddScroll(float as) { m_scroll -= as; }	//スクロール値加算
	float GetScroll() { return m_scroll; }  //m_scroll取得用

private:
	float m_gx; //位置
	float m_gy;

	HitLine* m_p_hit_line_ground3[28];//当たり判定
	float m_scroll;//左右スクロール用
};