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

	int GetX() { return m_x; }//��l���ʒu�擾�p
	int GetY() { return m_y; }
	int GetVX() { return m_vx; }
	int GetVY() { return m_vy; }

	int GetMoveX() { return move_x; }

	void SetX(int x) { m_x = x; }
	void SetY(int y) { m_y = y; }

	void MenuDel() { m_IsMenu = false; }
private:
	float m_x; //�ʒu
	float m_y;

	float move_x;

	float m_vx;//�ړ��x�N�g��
	float m_vy;

	bool m_direc;//����

	bool m_IsMenu;//���j���[���J���Ă��邩
	bool m_menu_key_flag;//���j���[�p�L�[�t���O

	bool m_down;//�Փˊm�F�p

	int m_ani_time;//��l���A�j���[�V����

	HitLine* m_p_hit_line_hero[4];//�����蔻��
	HitLine* m_p_hit_line_hero_copy[4];//�����蔻��(�R�s�[)

	CMenu* menu;

	//CObjGround ground;
};