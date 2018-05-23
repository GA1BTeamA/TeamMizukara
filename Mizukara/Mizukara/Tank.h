#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�^���N�N���X
class CTank : public CObj
{
public:
	CTank();
	~CTank();
	void Action();
	void Draw();

	void SetWater_Remaining(float water_amount) { m_water_remaining2 += water_amount; }  //���c�ʃZ�b�g
	void SetWaveY(float* wave_y,float wave_amount);  //�g�̈ʒu�Z�b�g
	float* GetWaveY() { return &m_wave_y; }  //�g�̈ʒu�擾
	float GetWaveX() { return m_wave_x; }
	float GetWaterY() { return m_water_y; }  //���̈ʒu�擾
	float GetWaterX() { return m_water_x; }
	float GetWaterAmount() { return m_water_amount; }
	float GetWaveAmount() { return m_wave_amount; }
	float GetWater_Remaining() { return m_water_remaining2; };  //���c�ʃZ�b�g

private:
	float m_x; //�ʒu
	float m_y;

	float m_wave_x;//�g�̈ʒu
	float m_wave_y;
	
	float im_x;//�A�C�R���̈ʒu
	float im_y;

	float m_water_x;  //���̈ʒu
	float m_water_y;

	static const float m_water_amount;  //���̗ʕύX�p��
	static const float m_wave_amount;  //�g�̍����ύX�p��
	float m_water_remaining;  //���̎c��

	float m_water_remaining2;

	int m_ani_time1;//�g�A�j���[�V�����p
	int m_ani_time2;

	//float m_scroll;//���E�X�N���[���p

	HitLine* m_p_hit_line_tank;//�����蔻��
};