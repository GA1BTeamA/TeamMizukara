//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Tank.h"
extern int g_SceneNumber;

CTank::CTank()
	:m_x(0), m_y(169)
	, im_x(3), im_y(130)
{

	/*
	m_p_hit_line->SetPos1(m_x-11, m_y);
	m_p_hit_line->SetPos2(m_x+11, m_y+139);
	*/
	//ヒットラインの作成
	m_p_hit_line_tank = Collision::HitLineInsert(this);
	m_p_hit_line_tank->SetPos1(m_x + 110, m_y);
	m_p_hit_line_tank->SetPos2(m_x + 110, m_y + 150);
	m_p_hit_line_tank->SetElement(3);		//属性を3にする
	m_p_hit_line_tank->SetInvisible(false);	//無敵モード無効
}

CTank::~CTank()
{

}

void CTank::Action()
{

}

void CTank::Draw()
{
	//WTMに近づいたらアイコンを出す
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_tank->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_tank->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(21, im_x, im_y);
			}
		}
	}

	//Draw::Draw2D(10, m_x, m_y);
}