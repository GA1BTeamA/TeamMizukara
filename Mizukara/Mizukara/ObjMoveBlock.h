#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//ギミック3(動かす足場)クラス
class ObjMoveBlock :public CObj
{
public:
	ObjMoveBlock();
	~ObjMoveBlock();
	void Action();
	void Draw();
};

