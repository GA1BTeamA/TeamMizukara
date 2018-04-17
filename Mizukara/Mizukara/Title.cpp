//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Title.h"
extern int g_SceneNumber;

//�R���X�g���N�^
CTitle::CTitle()
	:m_x(0), m_y(0),m_cursor(LEFT), m_IsDrawOpe(false)
{

}

CTitle::~CTitle()
{

}

void CTitle::Action()
{
	//�����������獶��
	if (Input::KeyPush(VK_LEFT)==true)
	{
		m_cursor = LEFT;
	}
	//�E����������E��
	else if (Input::KeyPush(VK_RIGHT) == true)
	{
		m_cursor = RIGHT;
	}
	//�����������牺��
	else if (Input::KeyPush(VK_DOWN) == true)
	{
		if(m_cursor!=UNDER)
			m_BefCursor = m_cursor;
		m_cursor = UNDER;
	}
	else if (Input::KeyPush(VK_UP) == true && m_cursor==UNDER)
	{
		m_cursor = m_BefCursor;
	}

	//�J�[�\���ʒu�����Ȃ�
	if (m_cursor==LEFT)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (key_flag)
			{
				g_SceneNumber = GAME;
				is_delete = true;
				key_flag = false;
			}
		}
		else
		{
			key_flag = true;
		}
	}
	//�J�[�\���ʒu���E�Ȃ�
	else if(m_cursor==RIGHT)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (key_flag)
			{
				g_SceneNumber = GAME;
				is_delete = true;
				key_flag = false;
			}
		}
		else
		{
			key_flag = true;
		}
	}
	//�J�[�\���ʒu�����Ȃ�
	else {
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (key_flag)
			{
				m_IsDrawOpe = !(m_IsDrawOpe);
				key_flag = false;
			}
		}
		else
		{
			key_flag = true;
		}
	}
}

void CTitle::Draw()
{
	Draw::Draw2D(13, m_x, m_y);
	

	if (m_cursor == LEFT)
	{
		Draw::Draw2D(14, 80, 280);
	}
	else if(m_cursor==RIGHT)
	{
		Draw::Draw2D(14,450, 280);
	}
	else {
		Draw::Draw2D(14, 280, 440);
	}

	if (m_IsDrawOpe) {
		Draw::Draw2D(17, 0, 0);
	}
}