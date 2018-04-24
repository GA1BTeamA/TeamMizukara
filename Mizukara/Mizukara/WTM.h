#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//WTM�N���X
class CWTM : public CObj
{
public:
	CWTM();
	~CWTM();
	void Action();
	void Draw();
private:
	float m_x; //WTM�̈ʒu
	float m_y;

	float im_x;//�A�C�R���̈ʒu
	float im_y;

	HitLine* m_p_hit_line;//�����蔻��
};