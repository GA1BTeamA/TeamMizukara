//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Title.h"
extern int g_SceneNumber;
extern bool g_key_flag;

//コンストラクタ
CTitle::CTitle()
	:m_x(0), m_y(0),m_cursor(LEFT), m_IsDrawOpe(false),m_ani_time(0.0f)
{

}

CTitle::~CTitle()
{

}

void CTitle::Action()
{
	if (m_ani_time != 0)
	{
		m_ani_time++;
	}

	Audio::StartLoopMusic(3);
	Audio::LoopMusicVolume(3, 0.05f);
	if (m_IsDrawOpe == false) {
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

	if (Input::KeyPush(VK_RETURN) == true)
	{
		m_ani_time++;
	}

	//カーソル位置が左なら
	if (m_cursor==LEFT)
	{
			if (m_ani_time==25)
			{
				Audio::StopLoopMusic(3);
				Audio::StartMusic(0);
				g_SceneNumber = STORY;
				is_delete = true;
				g_key_flag = false;
			}
	}
	//カーソル位置が右なら
	else if (m_cursor == RIGHT)
	{
			if (m_ani_time==25)
			{
				Audio::StopLoopMusic(3);
				Audio::StartMusic(0);
				g_SceneNumber = STAGESELECTO;
				is_delete = true;
				g_key_flag = false;
			}
	}
	//カーソル位置が下なら
	else 
	{
			if (m_ani_time==25)
			{
				Audio::StartMusic(0);
				m_IsDrawOpe = !(m_IsDrawOpe);
				g_key_flag = false;
				m_ani_time = 0;
			}
	}
}

void CTitle::Draw()
{
	Draw::Draw2D(13, m_x, m_y);

	if (m_cursor == LEFT)
	{
		Draw::Draw2D(14, 84, 320);
		if (Input::KeyPush(VK_RETURN) == true)
		{
			Draw::Draw2D(111, 84, 320);
		}
	}
	else if(m_cursor==RIGHT)
	{
		Draw::Draw2D(14,450, 320);
		if (Input::KeyPush(VK_RETURN) == true)
		{
			Draw::Draw2D(111, 450, 320);
		}
	}
	else 
	{
		Draw::Draw2D(14, 270, 450);
		if (Input::KeyPush(VK_RETURN) == true)
		{
			Draw::Draw2D(111, 270, 450);
		}
	}

	if (m_IsDrawOpe) 
	{
		Draw::Draw2D(17, 0, 0);
	}

	/*if (m_IsDrawStageSelecto)
	{
		Draw::Draw2D(19, 0, 0);
	}*/
}