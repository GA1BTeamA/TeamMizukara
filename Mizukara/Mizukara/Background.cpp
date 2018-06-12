//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Background.h"
#include "ObjGround2.h"
#include "ObjGround3.h"
#include "Hero.h"

extern int g_SceneNumber;

CBackground::CBackground()
	:m_x(0), m_y(0), m_scroll(0.0f)
	, m_x2(2400), m_y2(0), m_x_scroll(0)
{
	
}

CBackground::~CBackground()
{

}

void CBackground::Action()
{
	if (g_SceneNumber == GAME_MAIN||g_SceneNumber == RESULT_MAIN)
	{
		m_x -= 0.1f;
		m_x_scroll -= 0.1f;
		if (m_x < -2400.f)
		{
			m_x = 2390.f;
		}

		m_x2 -= 0.1f;
		if (m_x2 < -2400.f)
		{
			m_x2 = 2390.f;
		}
	}
}

void CBackground::Draw()
{
	ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	switch (g_SceneNumber)
	{
	case RESULT_MAIN:
	case GAME_MAIN:
		Draw::Draw2D(24, m_x+m_x_scroll, m_y);
		Draw::Draw2D(100, m_x, m_y);
		break;

	case GAME_MAIN2:
		Draw::Draw2D(78, m_x+ground2->GetScroll(), m_y);
		break;

	case GAME_MAIN3:
		Draw::Draw2D(79, m_x+ground3->GetScroll(), m_y);
		break;
	}
}