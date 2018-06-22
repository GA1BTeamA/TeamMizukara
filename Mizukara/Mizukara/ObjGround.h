#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"
#include "GameEngine\\FontTex.h"

//�n�ʃN���X
class CObjGround : public CObj
{
public:
	CObjGround();
	~CObjGround();
	void Action();
	void Draw();

	float GetGY() { return m_gy; }  //m_gy�擾�p
	void AddScroll(float as) { m_scroll -= as; }	//�X�N���[���l���Z
	float GetScroll() { return m_scroll; }  //m_scroll�擾�p
	float GetGX() { return m_gx; }  //m_gy�擾�p

private:
	float m_gx; //�ʒu
	float m_gy;

	HitLine* m_p_hit_line_ground[25];//�����蔻��

	float m_scroll;//���E�X�N���[���p
};