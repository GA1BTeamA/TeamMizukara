//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "WTM.h"
extern int g_SceneNumber;

CWTM::CWTM()
	:m_x(629), m_y(261)
	,im_x(615), im_y(161)
{
	//ヒットラインの作成
	m_p_hit_line = Collision::HitLineInsert(this);
	m_p_hit_line->SetPos1(m_x+11, m_y+110);
	m_p_hit_line->SetPos2(m_x+11, m_y+129);
	m_p_hit_line->SetElement(2);		//属性を2にする
	m_p_hit_line->SetInvisible(false);	//無敵モード無効
}

CWTM::~CWTM()
{

}

void CWTM::Action()
{
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line->GetHitData()[i]->GetElement()==0)
			{
				g_SceneNumber = STORY;
				is_delete = true;;
			}

		}
	}
}

void CWTM::Draw()
{
	Draw::Draw2D(16, m_x, m_y);

	Draw::Draw2D(21, im_x, im_y);
}