//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjBoat.h"
#include "ObjGround2.h"



ObjBoat::ObjBoat()
	:m_x(854), m_y(245), m_gx(846), m_gy(135), m_RopeSizeScaffold(0.33f)
{
	m_name = BOAT;

	//足場ヒットライン作成し、値を設定(左)
	m_hit_line_Boat[0] = Collision::HitLineInsert(this);
	m_hit_line_Boat[0]->SetPos1(m_x, m_y);
	m_hit_line_Boat[0]->SetPos2(m_x, m_y + 40);
	m_hit_line_Boat[0]->Set4direc(HIT_LEFT);

	//足場ヒットライン作成し、値を設定(右)
	m_hit_line_Boat[1] = Collision::HitLineInsert(this);
	m_hit_line_Boat[1]->SetPos1(m_x + 60, m_y);
	m_hit_line_Boat[1]->SetPos2(m_x + 60, m_y + 40);
	m_hit_line_Boat[1]->Set4direc(HIT_RIGHT);

	//足場ヒットライン作成し、値を設定(上)
	m_hit_line_Boat[2] = Collision::HitLineInsert(this);
	m_hit_line_Boat[2]->SetPos1(m_x, m_y);
	m_hit_line_Boat[2]->SetPos2(m_x + 60, m_y);
	m_hit_line_Boat[2]->Set4direc(HIT_TOP);

	//足場ヒットライン作成し、値を設定(下)
	m_hit_line_Boat[3] = Collision::HitLineInsert(this);
	m_hit_line_Boat[3]->SetPos1(m_x, m_y + 40);
	m_hit_line_Boat[3]->SetPos2(m_x + 60, m_y + 40);
	m_hit_line_Boat[3]->Set4direc(HIT_UNDER);

	for (int i = 0; i < 4; i++) {
		m_hit_line_Boat[i]->SetElement(1);		//属性を1にする
		m_hit_line_Boat[i]->SetInvisible(false);	//無敵モード無効
		m_hit_line_Boat[i]->SetAngle();
	}

}


ObjBoat::~ObjBoat()
{

}

void ObjBoat::Action()
{
	ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);

	//位置更新
	m_hit_line_Boat[0]->SetPos1(m_x + ground2->GetScroll(), m_y);
	m_hit_line_Boat[0]->SetPos2(m_x + ground2->GetScroll(), m_y + 40);
	m_hit_line_Boat[1]->SetPos1(m_x + ground2->GetScroll() + 60, m_y);
	m_hit_line_Boat[1]->SetPos2(m_x + ground2->GetScroll() + 60, m_y + 40);
	m_hit_line_Boat[2]->SetPos1(m_x + ground2->GetScroll(), m_y);
	m_hit_line_Boat[2]->SetPos2(m_x + ground2->GetScroll() + 60, m_y);
	m_hit_line_Boat[3]->SetPos1(m_x + ground2->GetScroll(), m_y + 40);
	m_hit_line_Boat[3]->SetPos2(m_x + ground2->GetScroll() + 60, m_y + 40);

}

void ObjBoat::Draw()
{
	ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);

	//ロープ表示
	//Draw::Draw2D(62, m_gx + 24 + ground2->GetScroll(), 135, 1, m_RopeSizeScaffold);
	
}
