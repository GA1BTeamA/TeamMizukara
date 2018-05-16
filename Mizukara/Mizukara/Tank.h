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

	float m_wave_x;//�g�̈ʒu
	float m_wave_y;
	
	float im_x;//�A�C�R���̈ʒu
	float im_y;

	float m_water_x;  //���̈ʒu
	float m_water_y;

	static const float m_water_amount;  //���̗ʕύX�p��
	static const float m_wave_amount;  //�g�̍����ύX�p��
	float m_water_remaining;  //���̎c��

	int m_ani_time1;//�g�A�j���[�V�����p
	int m_ani_time2;

	//float m_scroll;//���E�X�N���[���p

	HitLine* m_p_hit_line_tank;//�����蔻��
};