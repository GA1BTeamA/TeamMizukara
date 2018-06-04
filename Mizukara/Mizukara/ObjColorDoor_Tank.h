#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�M�~�b�N8�^���N�N���X
class ObjColorDoor_Tank :public CObj
{
public:
	ObjColorDoor_Tank();
	~ObjColorDoor_Tank();
	void Action();
	void Draw();
private:
	float m_x; //�M�~�b�N2�̈ʒu
	float m_y;

	float m_gx;//�O���t�B�b�N�̈ʒu
	float m_gy;

	float m_tgx;  //�O���t�B�b�N�ʒu
	float m_tgy;

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


	HitLine* m_hit_line_ColorDoorTank[2];//�����蔻��
};

