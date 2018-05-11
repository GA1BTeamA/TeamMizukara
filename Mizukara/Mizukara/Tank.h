#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�^���N�N���X
class CTank : public CObj
{
public:
	CTank();
	~CTank();
	void Action();
	void Draw();
private:
	float m_x; //�ʒu
	float m_y;

	float m_x1;//���ʒu
	float m_y1;
	float m_x2;
	float m_y2;
	float m_x3;
	float m_y3;
	float m_x4;
	float m_y4;
	float m_x5;
	float m_y5;
	float m_x6;
	float m_y6;
	float m_x7;
	float m_y7;
	float m_x8;
	float m_y8;

	float im_x;//�A�C�R���̈ʒu
	float im_y;

	int m_ani_time;
	//float m_scroll;//���E�X�N���[���p

	HitLine* m_p_hit_line_tank;//�����蔻��
};