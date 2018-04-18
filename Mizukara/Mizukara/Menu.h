#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�^���N�N���X
class CMenu : public CObj
{
public:
	CMenu();
	~CMenu();
	void Action();
	void Draw();

private:
	float m_x; //�ʒu
	float m_y;
	unsigned int m_cursor; //�J�[�\���ʒu
	unsigned int m_BefCursor; //�O�̃J�[�\���ʒu

	bool m_IsContinue;//��蒼��
	bool m_IsRetire;//���^�C�A
	bool m_IsRedo;//��蒼��

	bool key_flag;  //�L�[��������Ă��邩�`�F�b�N�p
};