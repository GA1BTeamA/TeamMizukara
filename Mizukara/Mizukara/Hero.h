#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"
#include "Menu.h"
#include "ObjGround.h"

//��l���N���X
class CHero : public CObj
{
public:
	CHero();
	~CHero();
	void Action();
	void Draw();

	void MenuDel() { m_IsMenu = false; }
private:
	float m_x; //�ʒu
	float m_y;
	float m_vx;//�ړ��x�N�g��
	float m_vy;
	bool m_direc;//����
	bool m_IsMenu;//���j���[���J���Ă��邩
	bool m_menu_key_flag;//���j���[�p�L�[�t���O

	bool m_down;//�Փˊm�F�p

	HitLine* m_p_hit_line[4];//�����蔻��

	CMenu* menu;

	CObjGround ground;
};