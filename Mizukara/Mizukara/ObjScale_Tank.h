#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�V���^���N�N���X
class ObjScale_Tank :public CObj
{
public:
	ObjScale_Tank(float x,float y,float r1,float r2,unsigned int n);
	~ObjScale_Tank();
	void Action();
	void Draw();

private:
	unsigned int m_ScaleNo;//�V���̔ԍ�

	float m_x; //�M�~�b�N3�̈ʒu
	float m_y;
	float m_x2;
	float m_y2;

	float m_wave_x;  //�g�̈ʒu
	float m_wave_y;
	float m_wave_x2;  //�g�̈ʒu
	float m_wave_y2;

	float m_water_x;  //���̈ʒu
	float m_water_y;
	float m_water_x2;  //���̈ʒu
	float m_water_y2;

	float m_angle; //�X��
	float m_angle_x;//�X���̂��l
	float m_angle_y;//�X���̂��l
	float m_angle_x2;//�X���̂��l
	float m_angle_y2;//�X���̂��l

	int m_ani_time1;  //�g�A�j���[�V�����p
	int m_ani_time2;

	float m_water_remaining;
	float m_water_remaining2;

	static const float m_WaveSize_x;  //�g�̃T�C�Y�p
	static const float m_WaveSize_y;

	HitLine* m_hit_line_ScaleTank;//�����蔻��
	HitLine* m_hit_line_ScaleTank2;//�����蔻��
};

