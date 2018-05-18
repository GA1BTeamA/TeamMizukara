#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�o�P�c���[�^�[�N���X
class CBucketMeter : public CObj
{
public:
	CBucketMeter();
	~CBucketMeter();
	void Action();
	void Draw();
	void PushX();
	void PushC();
	float GetWaterRem() { return m_water_remaining; }
private:
	float m_x; //�ʒu
	float m_y;

	float m_wave_x;//�g�̈ʒu
	float m_wave_y;

	float m_water_x;  //���̈ʒu
	float m_water_y;

	int m_ani_time1;//�g�A�j���[�V�����p
	int m_ani_time2;

	static const float m_BM_water_amount;  //���̗ʕύX�p��
	static const float m_BM_wave_amount;  //�g�̍����ύX�p��
	float m_water_remaining;  //���̎c��

};