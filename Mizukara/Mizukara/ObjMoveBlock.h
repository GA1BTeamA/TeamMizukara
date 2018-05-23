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

private:
	float m_x;//�ʒu
	float m_y;

	float m_gx;//�O���t�B�b�N�̈ʒu
	float m_gy;

	HitLine* m_hit_line_MoBl[4];//�����蔻��
};

