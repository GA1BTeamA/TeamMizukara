#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�M�~�b�N1�^���N�N���X
class ObjUpScaffold_Tank : public CObj
{
public:
	ObjUpScaffold_Tank();
	~ObjUpScaffold_Tank();
	void Action();
	void Draw();
private:
	float m_x; //�M�~�b�N1�̈ʒu
	float m_y;

	float m_gx;  //�O���t�B�b�N�ʒu
	float m_gy;

	float m_moveY;

	float m_wave_x;  //�g�̈ʒu
	float m_wave_y;

	float m_water_x;  //���̈ʒu
	float m_water_y;

	int m_ani_time1;  //�g�A�j���[�V�����p
	int m_ani_time2;

	float m_water_remaining;

	static const float m_WaveSize_x;  //�g�̃T�C�Y�p

	float m_WaterSize_y;//���p
	float m_WaveSize_y;//�g�p

	float m_RopeSizeBoard;//�W�̕��̃��[�v�̒���
	float m_RopeSizeScaffold;//����̕��̃��[�v�̒���

	int m_PulleyAni;//���ԃA�j���[�V�����p

	HitLine* m_hit_line_UpScTank;//�����蔻��
};
