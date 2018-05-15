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
	

	float im_x;//�A�C�R���̈ʒu
	float im_y;

	float m_water_x;  //���̕\���ʒu
	float m_water_y;

	int m_ani_time1;
	int m_ani_time2;
	//float m_scroll;//���E�X�N���[���p

	//static const float m_Wave_Shrinking;

	HitLine* m_p_hit_line_tank;//�����蔻��
};