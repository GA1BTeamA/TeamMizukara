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

	int GetGY() { return m_gy; }  //m_gy�擾�p
	int GetGX() { return m_gx; }  //m_gy�擾�p

private:
	float m_gx; //�ʒu
	float m_gy;

	HitLine* m_p_hit_line[5];//�����蔻��
};