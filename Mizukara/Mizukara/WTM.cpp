//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "WTM.h"
#include "ObjGround.h"
extern int g_SceneNumber;

CWTM::CWTM()
	:m_x(1186), m_y(334)
	,im_x(1186), im_y(30)
{
	//ヒットラインの作成
	m_p_hit_line_wtm = Collision::HitLineInsert(this);
	m_p_hit_line_wtm->SetPos1(m_x, m_y);
	m_p_hit_line_wtm->SetPos2(m_x, m_y+100);
	m_p_hit_line_wtm->SetElement(2);		//属性を2にする
	m_p_hit_line_wtm->SetInvisible(false);	//無敵モード無効
}

CWTM::~CWTM()
{

}

void CWTM::Action()
{

}

void CWTM::Draw()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	//WTMに近づいたらアイコンを出す
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_wtm->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_wtm->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(21, im_x + ground->GetScroll(), im_y);
			}
		}
	}

	Draw::Draw2D(16, m_x + ground->GetScroll(), m_y);
}