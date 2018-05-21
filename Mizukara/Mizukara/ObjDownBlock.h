#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�M�~�b�N2�̉�����u���b�N�N���X
class ObjDownBlock :public CObj
{
public:
	ObjDownBlock();
	~ObjDownBlock();

	void Action();
	void Draw();

private:
	float m_x;//�ʒu
	float m_y;

	HitLine* m_hit_line_DwBl[4];//�����蔻��
};