#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//WTM�N���X
class CSPRI : public CObj
{
public:
	CSPRI();
	~CSPRI();
	void Action();
	void Draw();
private:
	float m_x; //Sprinkler�̈ʒu
	float m_y;

	float m_wave_x;  //�g�̈ʒu
	float m_wave_y;

	float im_x;//�A�C�R���̈ʒu
	float im_y;

	int m_ani_time1;  //�g�̃A�j���[�V�����p
	int m_ani_time2;

	float m_water_x;  //���̈ʒu
	float m_water_y;

	static const float m_WaveSize_x;  //�g�̃T�C�Y�p
	static const float m_WaveSize_y;

	HitLine* m_p_hit_line_spri;//�����蔻��
};