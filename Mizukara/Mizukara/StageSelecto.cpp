//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "StageSelecto.h"
extern int g_SceneNumber;
extern bool g_key_flag;

//コンストラクタ
CStageSelecto::CStageSelecto()
	:m_x(0), m_y(0), m_cursor(STAGE1), m_IsDrawStageSelecto(false)
{

}

CStageSelecto::~CStageSelecto()
{

}

void CStageSelecto::Action()
{
	Audio::StartLoopMusic(5);
	Audio::LoopMusicVolume(5, 0.05f);

		//左を押したら左に
		if (Input::KeyPush(VK_LEFT) == true ||
			Input::KeyPush(VK_UP) == true)
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
		//右を押したら右に
		else if (Input::KeyPush(VK_RIGHT) == true ||
				Input::KeyPush(VK_DOWN) == true)
		{
			if (key_flag)
			{
				if (m_cursor < 2)
				{
					m_cursor++;
					key_flag = false;
				}
			}
		}
		else key_flag = true;
	
	//下を押したら下に
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

	//カーソル位置が左なら
	if (m_cursor == LEFT)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				Audio::StopLoopMusic(5);
				Audio::StartMusic(0);
				g_SceneNumber = GAME;
				Audio::StartLoopMusic(6);
				Audio::LoopMusicVolume(6, 0.05f);
				is_delete = true;
				g_key_flag = false;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}
	//カーソル位置が右なら
	else if (m_cursor == RIGHT)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				Audio::StopLoopMusic(5);
				Audio::StartMusic(0);
				g_SceneNumber = GAME2;
				Audio::StartLoopMusic(7);
				Audio::LoopMusicVolume(7, 0.05f);
				is_delete = true;
				g_key_flag = false;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}
	//カーソル位置が下なら
	else if (m_cursor == UNDER)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				Audio::StopLoopMusic(5);
				Audio::StartMusic(0);
				g_SceneNumber = GAME3;
				Audio::StartLoopMusic(8);
				Audio::LoopMusicVolume(8, 0.05f);
				is_delete = true;
				g_key_flag = false;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}
	/*//カーソル位置が右下なら
	else if (m_cursor == UNDER_RIGHT)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				Audio::StopLoopMusic(5);
				Audio::StartMusic(0);
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
	//カーソル位置が左下なら
	else if(m_cursor == UNDER_LEFT)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				Audio::StopLoopMusic(5);
				Audio::StartMusic(0);
				g_SceneNumber = GAME3;
				Audio::StartLoopMusic(8);
				Audio::LoopMusicVolume(8, 0.05f);
				is_delete = true;
				g_key_flag = false;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}*/
}

void CStageSelecto::Draw()
{
	Draw::Draw2D(19, m_x, m_y);


	if (m_cursor == LEFT)
	{
		Draw::Draw2D(14, 87, 68);
	}
	else if (m_cursor == RIGHT)
	{
		Draw::Draw2D(14, 279, 206);
	}
	else if (m_cursor == UNDER){
		Draw::Draw2D(14, 470, 333);
	}
	/*else if (m_cursor == UNDER_LEFT) {
		Draw::Draw2D(14, 90, 330);
	}
	else if (m_cursor == UNDER_RIGHT) {
		Draw::Draw2D(14, 470, 330);
	}*/


	
}