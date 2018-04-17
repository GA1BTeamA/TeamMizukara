//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Title.h"
extern int g_SceneNumber;

CTitle::CTitle()
	:m_x(0), m_y(0),m_cursor(LEFT)
{

}

CTitle::~CTitle()
{

}

void CTitle::Action()
{
	if (Input::KeyPush(VK_LEFT)==true)
	{
		m_cursor = LEFT;
	}
	else if (Input::KeyPush(VK_RIGHT) == true)
	{
		m_cursor = RIGHT;
	}

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
	else
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
}

void CTitle::Draw()
{
	Draw::Draw2D(13, m_x, m_y);
	

	if (m_cursor == LEFT)
	{
		Draw::Draw2D(14, 80, 280);
	}
	else
	{
		Draw::Draw2D(14,450, 280);
	}
}