#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�M�~�b�N1�^���N�N���X
class ObjDownBlock_Tank : public CObj
{
public:
	ObjDownBlock_Tank();
	~ObjDownBlock_Tank();
	void Action();
	void Draw();
private:
	float m_x; //�M�~�b�N2�̈ʒu
	float m_y;

	float m_wave_x;  //�g�̈ʒu
	float m_wave_y;

	float m_water_x;  //���̈ʒu
	float m_water_y;

	int m_ani_time1;  //�g�A�j���[�V�����p
	int m_ani_time2;

	static const float m_WaveSize_x;  //�g�̃T�C�Y�p
	static const float m_WaveSize_y;

	HitLine* m_hit_line_DwBlTank;//�����蔻��
};
