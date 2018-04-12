//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Tank.h"

CTank::CTank()
	:m_x(0), m_y(169)
{
	
}

CTank::~CTank()
{

}

void CTank::Action()
{

}

void CTank::Draw()
{
	Draw::Draw2D(10, m_x, m_y);
}