#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�S�N���N���X
class CAllClear : public CObj
{
public:
	CAllClear();
	~CAllClear();
	void Action();
	void Draw();
private:
	float m_x; //�ʒu
	float m_y;

	float m_vy;//�x�N�g��
	float m_sy;//��l���̃W�����v�p
	float m_svy;//��l���̃W�����v�p�x�N�g��

	int m_ani_time;
};