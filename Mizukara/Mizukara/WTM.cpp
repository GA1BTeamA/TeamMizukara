//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "WTM.h"
extern int g_SceneNumber;

CWTM::CWTM()
	/*:m_x(629), m_y(261)
	,im_x(615), im_y(161)*/
{
	/*//ヒットラインの作成
	m_p_hit_line_wtm = Collision::HitLineInsert(this);
	m_p_hit_line_wtm->SetPos1(m_x-11, m_y);
	m_p_hit_line_wtm->SetPos2(m_x+11, m_y+139);
	m_p_hit_line_wtm->SetElement(2);		//属性を2にする
	m_p_hit_line_wtm->SetInvisible(false);	//無敵モード無効*/
}

CWTM::~CWTM()
{

}

void CWTM::Action()
{
	
}

void CWTM::Draw()
{
	/*
	//WTMに近づいたらアイコンを出す
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_wtm->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_wtm->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(21, im_x, im_y);
			}
		}
	}*/

	//Draw::Draw2D(16, m_x, m_y);
}