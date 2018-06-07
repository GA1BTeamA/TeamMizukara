#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�M�~�b�N8(�F�t���h�A�H���H��H)�N���X
class ObjColorDoor :public CObj
{
public:
	ObjColorDoor(float x,float y, int color_number, unsigned int n);
	~ObjColorDoor();
	void Action();
	void Draw();

	void AddY(float y) { m_y += y; }

private:
	float m_x;//�ʒu
	float m_y;
	float m_x2;//�ʒu
	float m_y2;

	int m_color_number;//�Ԃ��΂̃O���t�B�b�N��ID�Z�b�g�p

	//float m_gx;  //�O���t�B�b�N�ʒu
	//float m_gy;

	HitLine* m_hit_line_ColorDoor[4];//�����蔻��
};

