//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Tank.h"
extern int g_SceneNumber;

CTank::CTank()
	:m_x(40), m_y(250),m_x1(12),m_y1(250),m_x3(12),m_y3(250),m_x4(12),m_y4(250),m_x5(12)
	, m_y5(250), m_x6(12), m_y6(250), m_x7(12), m_y7(250), m_x8(12), m_y8(250)
	,im_x(3), im_y(130),m_ani_time(0.0f)
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
	m_ani_time++;

	if (m_ani_time > 2)
	{
		Draw::Draw2D(26, m_x1, m_y1);
	}
	else if (m_ani_time > 4)
	{
		Draw::Draw2D(26, m_x2, m_y2);
	}
	else if (m_ani_time > 6)
	{
		Draw::Draw2D(26, m_x3, m_y3);
	}
	else if (m_ani_time > 8)
	{
		Draw::Draw2D(26, m_x4, m_y4);
	}
	else if (m_ani_time > 10)
	{
		Draw::Draw2D(26, m_x5, m_y5);
	}
	else if (m_ani_time > 12)
	{
		Draw::Draw2D(26, m_x6, m_y6);
	}
	else if (m_ani_time > 14)
	{
		Draw::Draw2D(26, m_x7, m_y7);
	}
	else if (m_ani_time > 16)
	{
		Draw::Draw2D(26, m_x8, m_y8);
	}
	else
	{
		m_ani_time = 0;
	}
	/*m_x1 -= 0.4f;
	if (m_x1 < 0.0f)
	{
		m_x1 = 30.0f;
	}

	m_x2 -= 0.4f;
	if (m_x2 < 0.0f)
	{
		m_x2 = 30.0f;
	}

	m_x3 -= 0.2f;
	if (m_x3 < 0.0f)
	{
		m_x3 = 30.0f;
	}

	m_x4 -= 0.2f;
	if (m_x4 < 0.0f)
	{
		m_x4 = 30.0f;
	}*/

}

void CTank::Draw()
{
	//タンクに近づいたらアイコンを出す
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

		Draw::Draw2D(26, m_x1, m_y1);
		Draw::Draw2D(26, m_x2, m_y2);
		Draw::Draw2D(25, m_x3, m_y3);
		Draw::Draw2D(25, m_x4, m_y4);
}