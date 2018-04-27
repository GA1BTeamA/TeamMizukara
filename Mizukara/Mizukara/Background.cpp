//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Background.h"

CBackground::CBackground()
	:m_x(0), m_y(0)
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
	Draw::Draw2D(22, m_x, m_y);
}