//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Background.h"
#include "Hero.h"

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
	//m_scroll -= 5.0f;//スクロール
	m_x -= 5.0f;
	if (m_x < -2400.f)
	{
		m_x = 3200.f;
	}

	m_x2 -= 5.0f;
	if (m_x2 < -2400.f)
	{
		m_x2 = 3200.f;
	}
}

void CBackground::Draw()
{
	Draw::Draw2D(24, m_x, m_y);
	Draw::Draw2D(24, m_x2, m_y);

}