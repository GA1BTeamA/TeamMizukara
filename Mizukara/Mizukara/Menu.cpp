//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Menu.h"
extern int g_SceneNumber;

//�R���X�g���N�^
CMenu::CMenu()
	:m_x(20), m_y(20), m_cursor(LEFT)
	, m_IsContinue(false), m_IsRetire(false), m_IsRedo(false)
{
	m_name = MENU;
}

CMenu::~CMenu()
{

}

void CMenu::Action()
{
	//�����������獶��
	if (Input::KeyPush(VK_LEFT) == true)
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
		if (m_cursor != UNDER)
			m_BefCursor = m_cursor;
		m_cursor = UNDER;
	}
	else if (Input::KeyPush(VK_UP) == true && m_cursor == UNDER)
	{
		m_cursor = m_BefCursor;
	}
}

void CMenu::Draw()
{
	Draw::Draw2D(15, m_x, m_y);

	if (m_cursor == LEFT)
	{
		Draw::Draw2D(14, 115, 330);
	}
	else if (m_cursor == RIGHT)
	{
		Draw::Draw2D(14, 460, 330);
	}
	else {
		Draw::Draw2D(14, 285, 420);
	}
}