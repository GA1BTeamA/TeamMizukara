#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�M�~�b�N3(����������)�N���X
class ObjMoveBlock :public CObj
{
public:
	ObjMoveBlock();
	~ObjMoveBlock();
	void Action();
	void Draw();

	float GetX() { return m_x; }
	float GetY() { return m_y; }

	void AddX(float x) { m_x += x; }
	void AddY(float y) { m_y += y; }

private:
	float m_x;//�ʒu
	float m_y;

	HitLine* m_hit_line_MoBl[4];//�������蔻��
};

