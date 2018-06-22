#pragma once
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"
#include "GameEngine\\FontTex.h"

//�X�e�[�W3�n�ʃN���X
class ObjGround3 : public CObj
{
public:
	ObjGround3();
	~ObjGround3();
	void Action();
	void Draw();

	void AddScroll(float as) { m_scroll -= as; }	//�X�N���[���l���Z
	float GetScroll() { return m_scroll; }  //m_scroll�擾�p

private:
	float m_gx; //�ʒu
	float m_gy;

	HitLine* m_p_hit_line_ground3[28];//�����蔻��
	float m_scroll;//���E�X�N���[���p
};