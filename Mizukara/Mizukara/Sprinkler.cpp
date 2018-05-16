//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Sprinkler.h"
#include "ObjGround.h"
#include "Hero.h"
extern int g_SceneNumber;

CSPRI::CSPRI()
	:m_x(2150), m_y(250), m_x1(2152), m_y1(230), m_ani_time1(0.0f), m_ani_time2(0.0f),m_ani_time3(0.0f)
	, im_x(2150), im_y(130)
{
	//ヒットラインの作成(左)
	m_p_hit_line_spri = Collision::HitLineInsert(this);
	m_p_hit_line_spri->SetPos1(m_x, m_y);
	m_p_hit_line_spri->SetPos2(m_x, m_y + 100);
	m_p_hit_line_spri->SetElement(4);		//属性を4にする
	m_p_hit_line_spri->SetInvisible(false);	//無敵モード無効
}

CSPRI::~CSPRI()
{

}

void CSPRI::Action()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	//当たり判定位置の更新
	m_p_hit_line_spri->SetPos1(m_x + ground->GetScroll(), m_y);
	m_p_hit_line_spri->SetPos2(m_x + ground->GetScroll(), m_y + 100);
}

void CSPRI::Draw()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	if (m_ani_time1 >= 69)
	{
		m_ani_time1 = 0;
	}
	else
	{
		m_ani_time1++;
	}


	if (m_ani_time1 < 10)
	{
		Draw::Draw2D(35, m_x1 + ground->GetScroll(), m_y1, 0.5, 0.4);
	}
	else if (m_ani_time1 < 20)
	{
		Draw::Draw2D(36, m_x1 + ground->GetScroll(), m_y1, 0.5, 0.4);
	}
	else if (m_ani_time1 < 30)
	{
		Draw::Draw2D(37, m_x1 + ground->GetScroll(), m_y1, 0.5, 0.4);
	}
	else if (m_ani_time1 < 40)
	{
		Draw::Draw2D(38, m_x1 + ground->GetScroll(), m_y1, 0.5, 0.4);
	}
	else if (m_ani_time1 < 50)
	{
		Draw::Draw2D(32, m_x1 + ground->GetScroll(), m_y1, 0.5, 0.4);
	}
	else if (m_ani_time1 < 60)
	{
		Draw::Draw2D(33, m_x1 + ground->GetScroll(), m_y1, 0.5, 0.4);
	}
	else if (m_ani_time1 < 70)
	{
		Draw::Draw2D(34, m_x1 + ground->GetScroll(), m_y1, 0.5, 0.4);
	}


	if (m_ani_time2 >= 34)
	{
		m_ani_time2 = 0;
	}
	else
	{
		m_ani_time2++;
	}

	if (m_ani_time2 < 5)
	{
		Draw::Draw2D(25, m_x1 + ground->GetScroll(), m_y1, 0.5, 0.4);
	}
	else if (m_ani_time2 < 10)
	{
		Draw::Draw2D(26, m_x1 + ground->GetScroll(), m_y1, 0.5, 0.4);
	}
	else if (m_ani_time2 < 15)
	{
		Draw::Draw2D(27, m_x1 + ground->GetScroll(), m_y1, 0.5, 0.4);
	}
	else if (m_ani_time2 < 20)
	{
		Draw::Draw2D(28, m_x1 + ground->GetScroll(), m_y1, 0.5, 0.4);
	}
	else if (m_ani_time2 < 25)
	{
		Draw::Draw2D(29, m_x1 + ground->GetScroll(), m_y1, 0.5, 0.4);
	}
	else if (m_ani_time2 < 30)
	{
		Draw::Draw2D(30, m_x1 + ground->GetScroll(), m_y1, 0.5, 0.4);
	}
	else if (m_ani_time2 < 35)
	{
		Draw::Draw2D(31, m_x1 + ground->GetScroll(), m_y1, 0.5, 0.4);
	}

	if (m_ani_time3 >= 29)
	{
		m_ani_time3 = 0;
	}
	else
	{
		m_ani_time3++;
	}

	//Sprinklerに近づいたらアイコンを出す
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_spri->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_spri->GetHitData()[i]->GetElement() == 0)
			{	
				if (m_ani_time3 < 10)
				{
					Draw::Draw2D(0, m_x1 + ground->GetScroll(), m_y1-12, 1, 1);
				}
				else if (m_ani_time3 < 20)
				{
					Draw::Draw2D(2, m_x1 + ground->GetScroll(), m_y1-12, 1, 1);
				}
				else if (m_ani_time3 < 30)
				{
					Draw::Draw2D(7, m_x1 + ground->GetScroll(), m_y1-12, 1, 1);
				}
			}
		}
	}

	//Draw::Draw2D(21, a, m_y);
}