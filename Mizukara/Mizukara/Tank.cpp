//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Tank.h"
extern int g_SceneNumber;

CTank::CTank()
	:m_x(0), m_y(169)
{
	//ヒットラインの作成
	/*m_p_hit_line = Collision::HitLineInsert(this);
	m_p_hit_line->SetPos1(m_x + 40, m_y + 0);
	m_p_hit_line->SetPos2(m_x + 40, m_y + 69);
	m_p_hit_line->SetElement(2);		//属性を2にする
	m_p_hit_line->SetInvisible(false);	//無敵モード無効*/
}

CTank::~CTank()
{

}

void CTank::Action()
{
	
}

void CTank::Draw()
{
	//Draw::Draw2D(10, m_x, m_y);
}