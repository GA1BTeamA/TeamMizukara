#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�M�~�b�N8�^���N�N���X
class ObjColorDoor_Tank :public CObj
{
public:
	ObjColorDoor_Tank();
	~ObjColorDoor_Tank();
	void Action();
	void Draw();
private:
	float m_x; //�M�~�b�N2�̈ʒu
	float m_y;

	float m_gx;//�O���t�B�b�N�̈ʒu
	float m_gy;

	HitLine* m_hit_line_ColorDoorTank[2];//�����蔻��
};

