//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Menu.h"
extern int g_SceneNumber;

//コンストラクタ
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
	//左を押したら左に
	if (Input::KeyPush(VK_LEFT) == true)
	{
		m_cursor = LEFT;
	}
	//右を押したら右に
	else if (Input::KeyPush(VK_RIGHT) == true)
	{
		m_cursor = RIGHT;
	}
	//下を押したら下に
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