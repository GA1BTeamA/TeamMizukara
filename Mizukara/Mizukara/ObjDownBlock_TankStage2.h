#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�M�~�b�N1�^���N�N���X
class ObjDownBlock_TankStage2 : public CObj
{
public:
	ObjDownBlock_TankStage2();
	~ObjDownBlock_TankStage2();
	void Action();
	void Draw();
private:
	float m_x; //�M�~�b�N2�̈ʒu
	float m_y;

	float m_gx;//�O���t�B�b�N�̈ʒu
	float m_gy;

	float m_moveY;

	float m_wave_x;  //�g�̈ʒu
	float m_wave_y;

	float m_water_x;  //���̈ʒu
	float m_water_y;

	int m_ani_time1;  //�g�A�j���[�V�����p
	int m_ani_time2;

	float m_water_remaining;
	float m_bucket_remaining;

	static const float m_WaveSize_x;  //�g�̃T�C�Y�p
	float m_WaveSize_y;

	int m_PulleyAni;//���ԃA�j���[�V�����p

	float m_RopeSizeBucket;//�o�P�c�̕��̃��[�v�̒���

	HitLine* m_hit_line_DwBlS2Tank;//�����蔻��
};