//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "StageSelecto.h"
extern int g_SceneNumber;
extern bool g_key_flag;

//�R���X�g���N�^
CStageSelecto::CStageSelecto()
	:m_x(0), m_y(0), m_cursor(STAGE1), m_IsDrawStageSelecto(false)
{

}

CStageSelecto::~CStageSelecto()
{

}

void CStageSelecto::Action()
{

		//�����������獶��
		if (Input::KeyPush(VK_LEFT) == true)
		{
			if (key_flag)
			{

				if (m_cursor > 0)
				{
					m_cursor--;
					key_flag = false;
				}
			}
		}
		//�E����������E��
		else if (Input::KeyPush(VK_RIGHT) == true)
		{
			if (key_flag)
			{
				if (m_cursor < 4)
				{
					m_cursor++;
					key_flag = false;
				}
			}
		}
		else key_flag = true;
	
	//�����������牺��
	/*else if (Input::KeyPush(VK_DOWN) == true)
	{
		if (m_cursor != UNDER)
			m_BefCursor = m_cursor;
		m_cursor = UNDER;
	}

	else if (Input::KeyPush(VK_DOWN) == true)
	{
		m_BefCursor = m_cursor;
		m_cursor = UNDER_LEFT;
	}

	else if(Input::KeyPush(VK_DOWN) == true)
	{
		m_BefCursor = m_cursor;
		m_cursor = UNDER_RIGHT;
	}*/

	/*else if(Input::KeyPush(VK_UP) == true && m_cursor == UNDER)
	{
	    m_cursor = m_BefCursor;	
	}*/

	//�J�[�\���ʒu�����Ȃ�
	if (m_cursor == LEFT)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				g_SceneNumber = GAME;
				is_delete = true;
				g_key_flag = false;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}
	//�J�[�\���ʒu���E�Ȃ�
	else if (m_cursor == RIGHT)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				g_SceneNumber = GAME;
				is_delete = true;
				g_key_flag = false;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}
	//�J�[�\���ʒu�����Ȃ�
	else if (m_cursor == UNDER)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				g_SceneNumber = GAME;
				is_delete = true;
				g_key_flag = false;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}

	else if (m_cursor == UNDER_RIGHT)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				g_SceneNumber = GAME;
				is_delete = true;
				g_key_flag = false;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}

	else if(m_cursor == UNDER_LEFT)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				g_SceneNumber = GAME;
				is_delete = true;
				g_key_flag = false;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}
}

void CStageSelecto::Draw()
{
	Draw::Draw2D(19, m_x, m_y);


	if (m_cursor == LEFT)
	{
		Draw::Draw2D(14, 85, 80);
	}
	else if (m_cursor == RIGHT)
	{
		Draw::Draw2D(14, 470, 80);
	}
	else if (m_cursor == UNDER){
		Draw::Draw2D(14, 280, 220);
	}
	else if (m_cursor == UNDER_LEFT) {
		Draw::Draw2D(14, 90, 340);
	}
	else if (m_cursor == UNDER_RIGHT) {
		Draw::Draw2D(14, 470, 340);
	}


	
}