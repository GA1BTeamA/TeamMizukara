#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�X�v�����N���[�N���X
class CSPRI : public CObj
{
public:
	CSPRI();
	~CSPRI();
	void Action();
	void Draw();

	HitLine* GetHitLineSpri() { return m_p_hit_line_spri; }
	bool GetCrearCnt1() { return m_CrearCnt1; }
	//float GetTankRemaining() { return m_TankRemaining; }

private:
	float m_x; //Sprinkler�̈ʒu
	float m_y;
	float m_x1;
	float m_y1;

	float m_vy;
	float m_sy;

	float im_x;//�A�C�R���̈ʒu
	float im_y;

	float m_wave_x;
	float m_wave_y;

	float m_water_x;
	float m_water_y;

	float m_fx;  //�Ԃ̈ʒu
	float m_fy;

	int m_ani_time1;//�A�j���[�V����
	int m_ani_time2;
	int m_ani_time3;
	int m_ani_time4;
	int m_ani_time5;
	int m_ani_time6;

	int count;
	bool m_CrearCnt1;  //�N���A�o�����߂̃J�E���g
	bool m_Flower;  //�ԍ炩���邽�߂̃J�E���g��

	//float g_TankRemaining;  //�^���N�̎c��

	static const float m_WaveSize_x;
	static const float m_WaveSize_y;

	int m_move1;//��l���A�j���[�V�����̓���
	int m_move2;//�X�v�����N���[����o�鐅
	int m_move3;

	HitLine* m_p_hit_line_spri;//�����蔻��
};