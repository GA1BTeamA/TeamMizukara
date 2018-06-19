#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�^�C�g���N���X
class CTitle : public CObj
{
public:
	CTitle();
	~CTitle();
	void Action();
	void Draw();
private:
	float m_x; //�ʒu
	float m_y;

	unsigned int m_cursor; //�J�[�\���ʒu
	unsigned int m_BefCursor; //�O�̃J�[�\���ʒu

	bool m_IsDrawOpe;//��������`��
	bool m_IsDrawStageSelecto;//�X�e�[�W�Z���N�g�`��

	bool key_flag;  //�L�[��������Ă��邩�`�F�b�N�p

	int m_ani_time;//�A�C�R���ύX�A�j���[�V����
};