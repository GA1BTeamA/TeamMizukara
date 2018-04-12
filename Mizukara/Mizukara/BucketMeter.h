#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

enum 
{

};

//主人公クラス
class CBucketMeter : public CObj
{
public:
	CBucketMeter();
	~CBucketMeter();
	void Action();
	void Draw();
private:
	float m_x; //位置
	float m_y;
};