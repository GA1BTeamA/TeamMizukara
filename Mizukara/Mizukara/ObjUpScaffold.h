#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�M�~�b�N1�̏オ�鑫��N���X
class ObjUpScaffold :public CObj
{
public:
	ObjUpScaffold();
	~ObjUpScaffold();

	void Action();
	void Draw();

private:
	float m_x;//�ʒu
	float m_y;

	HitLine* m_hit_line_UpSc[4];//�����蔻��
};

