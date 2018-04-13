#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�n�ʃN���X
class CObjGround : public CObj
{
public:
	CObjGround();
	~CObjGround();
	void Action();
	void Draw();
private:
	float m_x; //�ʒu
	float m_y;

	HitLine* m_p_hit_line;//�����蔻��
};