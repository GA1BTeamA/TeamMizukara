//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "AllClear.h"
extern int g_SceneNumber;
extern bool g_key_flag;
extern bool g_clearlist;

CAllClear::CAllClear()
	:m_x(0), m_y(-600), m_vy(1.0f)
{

}

CAllClear::~CAllClear()
{

}

void CAllClear::Action()
{
	if (m_y < -300) m_vy *= 1.1f;
	else m_vy *= 0.95f;

	m_y += m_vy;

	if (m_y > 0.0f)m_y = 0.0f;

	if (Input::KeyPush(VK_RETURN) == true)
	{
		if (g_key_flag)
		{
			Audio::StartMusic(0);
			Audio::StopLoopMusic(10);
			g_SceneNumber = TITLE;
			g_clearlist = true;
			TaskSystem::TaskClear();
			is_delete = true;
			g_key_flag = false;
		}
	}
	else
	{
		g_key_flag = true;
	}

}

void CAllClear::Draw()
{
	//背景描画
	Draw::Draw2D(98, m_x, m_y);
}