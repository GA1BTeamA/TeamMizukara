#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//ストーリークラス
class CObjStory : public CObj
{
public:
	CObjStory();
	~CObjStory();
	void Action();
	void Draw();
private:
	float m_x; //位置
	float m_y;
	unsigned int m_time;//ストーリー描画時間
};