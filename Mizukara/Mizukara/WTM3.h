#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

class CWTM3 : public CObj
{
public:
	CWTM3();
	~CWTM3();
	void Action();
	void Draw();

private:
	float m_x; //WTM�̈ʒu
	float m_y;

	float m_wave_x;  //�g�̈ʒu
	float m_wave_y;

	float im_x;//�A�C�R���̈ʒu
	float im_y;

	float m_water_x;  //���̈ʒu
	float m_water_y;

	int m_ani_time1;  //�g�A�j���[�V�����p
	int m_ani_time2;

	static const float m_WaveSize_x;  //�g�̃T�C�Y�p
	static const float m_WaveSize_y;

	static const float m_water_amount;  //���̗ʕύX�p��
	static const float m_wave_amount;  //�g�̍����ύX�p��
	float m_water_remaining;  //���̎c��

	HitLine* m_p_hit_line_wtm3;//�����蔻��
};

