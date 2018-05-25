#pragma once
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�X�e�[�W2�n�ʃN���X
class ObjGround2 : public CObj
{
public:
	ObjGround2();
	~ObjGround2();
	void Action();
	void Draw();

	float GetScroll() { return m_scroll; }  //m_scroll�擾�p

private:
	float m_gx; //�ʒu
	float m_gy;

	HitLine* m_p_hit_line_ground2[25];//�����蔻��
	float m_scroll;//���E�X�N���[���p
};

