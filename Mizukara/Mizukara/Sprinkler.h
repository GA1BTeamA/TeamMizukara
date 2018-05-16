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

	int m_ani_time1;
	int m_ani_time2;
	int m_ani_time3;

	HitLine* m_p_hit_line_spri;//�����蔻��
};