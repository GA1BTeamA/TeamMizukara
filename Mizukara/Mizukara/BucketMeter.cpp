//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "BucketMeter.h"

CBucketMeter::CBucketMeter()
	:m_x(600), m_y(430)
{
	
}

CBucketMeter::~CBucketMeter()
{

}

void CBucketMeter::Action()
{
	
}

void CBucketMeter::Draw()
{
	//描画
	Draw::Draw2D(11, m_x, m_y);
}