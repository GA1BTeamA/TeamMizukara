//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjGround.h"

CObjGround::CObjGround()
	:m_gx(0), m_gy(400)
{
	m_name = GROUND;

	//ヒットボックス作成()
	m_p_hit_line[0] = Collision::HitLineInsert(this);
	//作成したヒットボックスの値を設定
	m_p_hit_line[0]->SetPos1(m_gx, m_gy);
	m_p_hit_line[0]->SetPos2(m_gx+800, m_gy);

	//ヒットボックス作成()
	//m_p_hit_line[1] = Collision::HitLineInsert(this);
	////作成したヒットボックスの値を設定
	//m_p_hit_line[1]->SetPos1(m_gx+500, m_gy-90);
	//m_p_hit_line[1]->SetPos2(m_gx + 800, m_gy-90);

	//ヒットボックス作成()
	m_p_hit_line[2] = Collision::HitLineInsert(this);
	//作成したヒットボックスの値を設定
	m_p_hit_line[2]->SetPos1(m_gx + 500, m_gy - 90);
	m_p_hit_line[2]->SetPos2(m_gx + 500, m_gy+20);

	for (int i = 0; i < 3; i+=2) {
		m_p_hit_line[i]->SetElement(1);		//属性を1にする
		m_p_hit_line[i]->SetInvisible(false);	//無敵モード無効
		m_p_hit_line[i]->SetAngle();
	}

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