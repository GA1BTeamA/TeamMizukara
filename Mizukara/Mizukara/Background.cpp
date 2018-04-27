//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Background.h"

CBackground::CBackground()
	:m_x(0), m_y(0), m_scroll(0.0f)
{
	
}

CBackground::~CBackground()
{

}

void CBackground::Action()
{

}

void CBackground::Draw()
{
	m_scroll = -10.0f;//スクロール

	

	//Draw::Draw2D(22, m_x, m_y);
}