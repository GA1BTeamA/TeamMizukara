#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//��l���N���X
class CHero : public CObj
{
public:
	CHero();
	~CHero();
	void Action();
	void Draw();
private:
	float m_x; //�ʒu
	float m_y;
	float m_vx;//�ړ��x�N�g��
	float m_vy;
	bool m_direc;//����

	bool m_down;//�Փˊm�F�p

	HitLine* m_p_hit_line;//�����蔻��
};