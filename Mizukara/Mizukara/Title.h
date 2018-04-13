#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//タンククラス
class CTitle : public CObj
{
public:
	CTitle();
	~CTitle();
	void Action();
	void Draw();
private:
	float m_x; //位置
	float m_y;

	bool key_flag;  //キーが押されているかチェック用
};