#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�M�~�b�N3�^���N�N���X
class ObjMoveBlock_Tank :public CObj
{
public:
	ObjMoveBlock_Tank();
	~ObjMoveBlock_Tank();
	void Action();
	void Draw();
};

