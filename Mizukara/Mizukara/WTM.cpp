//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "WTM.h"

CWTM::CWTM()
	:m_x(629), m_y(261)
{

}

CWTM::~CWTM()
{

}

void CWTM::Action()
{

}

void CWTM::Draw()
{
	Draw::Draw2D(16, m_x, m_y);
}