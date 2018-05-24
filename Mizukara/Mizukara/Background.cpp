//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Background.h"
#include "Hero.h"
extern int g_SceneNumber;

CBackground::CBackground()
	:m_x(0), m_y(0), m_scroll(0.0f)
	, m_x2(2400), m_y2(0)
{
	
}

CBackground::~CBackground()
{

}

void CBackground::Action()
{
	////リザルト画面になったら破棄
	//if (g_SceneNumber == RESULT)
	//{
	//	is_delete = true;
	//}

	//m_scroll -= 5.0f;//スクロール
	m_x -= 0.1f;
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

void CBackground::Draw()
{
	Draw::Draw2D(24, m_x, m_y);
	Draw::Draw2D(24, m_x2, m_y);

}