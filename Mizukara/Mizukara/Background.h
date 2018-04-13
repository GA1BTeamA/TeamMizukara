#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�w�i�N���X
class CBackground : public CObj
{
public:
	CBackground();
	~CBackground();
	void Action();
	void Draw();
private:
	float m_x; //�ʒu
	float m_y;
};