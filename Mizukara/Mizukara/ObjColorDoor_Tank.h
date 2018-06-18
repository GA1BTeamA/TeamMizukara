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
	ObjColorDoor_Tank(float x,float y,int color,float waveX,float waveY, unsigned int n);
	~ObjColorDoor_Tank();
	void Action();
	void Draw();
private:
	float m_x; //�M�~�b�N2�̈ʒu
	float m_y;
	//float m_x2; //�M�~�b�N2�̈ʒu
	//float m_y2;


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

	static const float m_WaveSize_x;  //�g�̃T�C�Y�p

	float m_WaterSize_y;//���p
	float m_WaveSize_y;//�g�p

	float rgba[4];  //���̐F

	unsigned int m_DoorNo;//�V���̔ԍ�

	HitLine* m_hit_line_ColorDoorTank[2];//�����蔻��
};

