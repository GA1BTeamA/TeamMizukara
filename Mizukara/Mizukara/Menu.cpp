//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Menu.h"
#include "Hero.h"

extern int g_SceneNumber;
extern bool g_key_flag;

//コンストラクタ
CMenu::CMenu()
	:m_x(20), m_y(20), m_cursor(LEFT)
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

	//カーソル位置が左なら(続ける)
	if (m_cursor == LEFT)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				//ヒーローオブジェクト情報取得
				CHero* hero = (CHero*)TaskSystem::GetObj(PLAYER);
				if (hero != nullptr)
				{
					hero->MenuDel();
					is_delete = true;
				}
			}
		}
		else
		{
			g_key_flag = true;
		}
	}
	//カーソル位置が右(リタイア)ならタイトルへ
	else if (m_cursor == RIGHT)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				g_SceneNumber = TITLE;
				TaskSystem::TaskClear();
				g_key_flag = false;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}
	//カーソル位置が下なら(やり直し)
	else if (m_cursor == UNDER)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				g_SceneNumber = GAME;
				TaskSystem::TaskClear();
				g_key_flag = false;
			}
		}
		else
		{
			g_key_flag = true;
		}
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