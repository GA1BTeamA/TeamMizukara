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
private:
	float m_x; //位置
	float m_y;

	HitLine* m_p_hit_line;//当たり判定
};