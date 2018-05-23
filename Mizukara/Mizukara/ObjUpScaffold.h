#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�M�~�b�N1(�オ�鑫��)�N���X
class ObjUpScaffold :public CObj
{
public:
	ObjUpScaffold();
	~ObjUpScaffold();

	void Action();
	void Draw();

	void AddY(float y) { m_y += y; }

private:
	float m_x;//�ʒu
	float m_y;

	float m_gx;  //�O���t�B�b�N�ʒu
	float m_gy;

	HitLine* m_hit_line_UpSc[4];//�����蔻��
};

