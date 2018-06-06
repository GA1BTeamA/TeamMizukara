//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjBoat.h"
#include "ObjGround2.h"



ObjBoat::ObjBoat()
	:m_x(310), m_y(410), m_gx(846), m_gy(335), m_RopeSizeScaffold(0.33f)
	,m_scroll(0.0f)
{
	m_name = BOAT;

	m_hit_line_Boat[0] = Collision::HitLineInsert(this);
	m_hit_line_Boat[0]->Set4direc(HIT_TOP);
	m_hit_line_Boat[0]->SetPos1(m_scroll + 310, m_y);  //足場上
	m_hit_line_Boat[0]->SetPos2(m_scroll + 350, m_y);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_hit_line_Boat[1] = Collision::HitLineInsert(this);
	m_hit_line_Boat[1]->Set4direc(HIT_LEFT);
	m_hit_line_Boat[1]->SetPos1(m_scroll + 310, m_y);  //左
	m_hit_line_Boat[1]->SetPos2(m_scroll + 310, m_y+100);

	m_hit_line_Boat[2] = Collision::HitLineInsert(this);
	m_hit_line_Boat[2]->Set4direc(HIT_RIGHT);
	m_hit_line_Boat[2]->SetPos1(m_scroll + 400, m_y);  //右
	m_hit_line_Boat[2]->SetPos2(m_scroll + 400, m_y-100);
	
	for (int i = 0; i < 3; i++)
	{
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
	/*m_hit_line_Boat[0]->SetPos1(m_x + ground2->GetScroll(), m_y);
	m_hit_line_Boat[0]->SetPos2(m_x + ground2->GetScroll(), m_y + 40);
	m_hit_line_Boat[1]->SetPos1(m_x + ground2->GetScroll() + 60, m_y);
	m_hit_line_Boat[1]->SetPos2(m_x + ground2->GetScroll() + 60, m_y + 40);
	m_hit_line_Boat[2]->SetPos1(m_x + ground2->GetScroll(), m_y);
	m_hit_line_Boat[2]->SetPos2(m_x + ground2->GetScroll() + 60, m_y);
	m_hit_line_Boat[3]->SetPos1(m_x + ground2->GetScroll()+70, m_y - 60);
	m_hit_line_Boat[3]->SetPos2(m_x + ground2->GetScroll() + 70, m_y - 60);*/

	m_hit_line_Boat[0]->SetPos1(ground2->GetScroll() + 310, m_y);  //足場上
	m_hit_line_Boat[0]->SetPos2(ground2->GetScroll() + 350, m_y);
	m_hit_line_Boat[1]->SetPos1(ground2->GetScroll() + 310, m_y);  //左
	m_hit_line_Boat[1]->SetPos2(ground2->GetScroll() + 310, m_y+100);
	m_hit_line_Boat[2]->SetPos1(ground2->GetScroll() + 400, m_y);  //右
	m_hit_line_Boat[2]->SetPos2(ground2->GetScroll() + 400, m_y-100);

}

void ObjBoat::Draw()
{
	ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);

	//テスト
	//Draw::Draw2D(58, 310 +ground2->GetScroll(), 395);
	
}
