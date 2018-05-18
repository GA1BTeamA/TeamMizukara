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

	HitLine* GetHitLineSpri() { return m_p_hit_line_spri; }

private:
	float m_x; //Sprinkler�̈ʒu
	float m_y;
	float m_x1;
	float m_y1;

	float im_x;//�A�C�R���̈ʒu
	float im_y;

	float m_wave_x;
	float m_wave_y;

	float m_water_x;
	float m_water_y;

	int m_ani_time1;//�A�j���[�V����
	int m_ani_time2;
	int m_ani_time3;
	int m_ani_time4;

	int count;

	static const float m_WaveSize_x;
	static const float m_WaveSize_y;

	int m_move1;//��l���A�j���[�V�����̓���
	int m_move2;//�X�v�����N���[����o�鐅

	HitLine* m_p_hit_line_spri;//�����蔻��
};