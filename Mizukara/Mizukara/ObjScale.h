#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�M�~�b�N5(�V��)�N���X
class ObjScale :public CObj
{
public:
	ObjScale(float x,float y,unsigned int n);
	~ObjScale();

	void Action();
	void Draw();

	void SetAngle(float a) { m_angle = a; }

private:
	float m_x;//�ʒu
	float m_y;
	float m_x2;//�ʒu
	float m_y2;

	float m_angle;//�X��

	HitLine* m_hit_line_Scale[4];//�����蔻��
};


