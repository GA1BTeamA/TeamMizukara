//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Menu.h"
#include "Hero.h"

extern int g_SceneNumber;
extern bool g_key_flag;
extern bool g_clearlist;

//コンストラクタ
CMenu::CMenu(unsigned int n)
	:m_x(20), m_y(20), m_cursor(LEFT),m_StageNo(n), m_ani_time(0.0f)
{
	m_name = MENU;
}

CMenu::~CMenu()
{

}

void CMenu::Action()
{
	if (m_ani_time != 0)
	{
		m_ani_time++;
	}

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

	if (Input::KeyPush(VK_RETURN) == true)
	{
		if (g_key_flag)
		{
			m_ani_time++;
		}
	}
	else
	{
		g_key_flag = true;
	}

	//カーソル位置が左なら(続ける)
	if (m_cursor == LEFT)
	{
		if (m_ani_time >= 25)
		{
			Audio::StartMusic(0);
			//ヒーローオブジェクト情報取得
			CHero* hero = (CHero*)TaskSystem::GetObj(PLAYER);
			if (hero != nullptr)
			{
				hero->MenuDel();
				is_delete = true;
				Audio::StopLoopMusic(2);
				switch (m_StageNo)
				{
				case 1:
					Audio::StartLoopMusic(6);
					break;
				case 2:
					Audio::StartLoopMusic(7);
					break;
				case 3:
					Audio::StartLoopMusic(8);
					break;
				}
			}
		}
	}
	//カーソル位置が右(リタイア)ならタイトルへ
	else if (m_cursor == RIGHT)
	{
		if (m_ani_time >= 25)
		{
				Audio::StartMusic(0);
				g_SceneNumber = TITLE;
				g_clearlist = true;
				g_key_flag = false;
				Audio::StopLoopMusic(2);
		}
	}
	//カーソル位置が下なら(やり直し)
	else if (m_cursor == UNDER)
	{
		if (m_ani_time >= 25)
		{
				Audio::StartMusic(0);
				//同じステージをやり直す
				switch (m_StageNo)
				{
				case 1:
					g_SceneNumber = GAME;
					Audio::StartLoopMusic(6);
					break;
				case 2:
					g_SceneNumber = GAME2;
					Audio::StartLoopMusic(7);
					break;
				case 3:
					g_SceneNumber = GAME3;
					Audio::StartLoopMusic(8);
					break;

				}
				g_clearlist = true;
				g_key_flag = false;
				Audio::StopLoopMusic(2);
		}
	}
}

void CMenu::Draw()
{
	Draw::Draw2D(15, m_x, m_y);

	if (m_cursor == LEFT)
	{
		if (m_ani_time)
			Draw::Draw2D(111, 115, 315);
		else
			Draw::Draw2D(14, 115, 315);
	}
	else if (m_cursor == RIGHT)
	{
		if (m_ani_time)
			Draw::Draw2D(111, 460, 315);
		else
			Draw::Draw2D(14, 460, 315);
	}
	else {
		if (m_ani_time)
			Draw::Draw2D(111, 285, 400);
		else
			Draw::Draw2D(14, 285, 400);
	}
}