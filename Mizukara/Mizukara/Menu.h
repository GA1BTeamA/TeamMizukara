#pragma once
//���j���[�N���X
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//���j���[�N���X
class CMenu : public CObj
{
public:
	CMenu();
	~CMenu();//�g�p����w�b�_
	void Action();
	void Draw();

private:
	float m_x; //�ʒu
	float m_y;

	unsigned int m_cursor; //�J�[�\���ʒu
	unsigned int m_BefCursor; //�O�̃J�[�\���ʒu

	bool key_flag;  //�L�[��������Ă��邩�`�F�b�N�p
};