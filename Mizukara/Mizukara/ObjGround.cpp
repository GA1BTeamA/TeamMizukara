//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjGround.h"

CObjGround::CObjGround()
	:m_x(0), m_y(405)
{
	//ヒットボックス作成()
	m_p_hit_line = Collision::HitLineInsert(this);
	//作成したヒットボックスの値を設定
	m_p_hit_line->SetPos1(m_x, m_y);
	m_p_hit_line->SetPos2(m_x+800, m_y);
	m_p_hit_line->SetElement(1);		//属性を1にする
	m_p_hit_line->SetInvisible(false);	//無敵モード無効
}

CObjGround::~CObjGround()
{

}

void CObjGround::Action()
{

}

void CObjGround::Draw()
{
	Draw::Draw2D(18, 0, 0);
}