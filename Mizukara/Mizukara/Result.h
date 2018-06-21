#pragma once
//���j���[�N���X
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"
#include "GameEngine\\FontTex.h"

//���U���g�N���X
class CResult : public CObj
{
public:
	CResult();
	~CResult();//�g�p����w�b�_
	void Action();
	void Draw();

private:
	float m_x; //�ʒu
	float m_y;

	float m_alpha_value;//�����x�ύX�p

	unsigned int m_cursor; //�J�[�\���ʒu
	unsigned int m_BefCursor; //�O�̃J�[�\���ʒu

	bool key_flag;  //�L�[��������Ă��邩�`�F�b�N�p

	int m_ani_time;//�A�C�R���ύX�A�j���[�V����
};