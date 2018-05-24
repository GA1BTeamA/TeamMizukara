//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjMoveBlock.h"
#include "ObjGround.h"

//コンストラクタ
ObjMoveBlock::ObjMoveBlock()
	:m_x(1794), m_y(234)
{
	m_name = MOVEBLOCK;

	//足場ヒットライン作成し、値を設定(左)
	m_hit_line_MoBl[0] = Collision::HitLineInsert(this);
	m_hit_line_MoBl[0]->SetPos1(m_x, m_y);
	m_hit_line_MoBl[0]->SetPos2(m_x, m_y + 32);
	m_hit_line_MoBl[0]->Set4direc(HIT_LEFT);

	//足場ヒットライン作成し、値を設定(右)
	m_hit_line_MoBl[1] = Collision::HitLineInsert(this);
	m_hit_line_MoBl[1]->SetPos1(m_x + 50, m_y);
	m_hit_line_MoBl[1]->SetPos2(m_x + 50, m_y + 32);
	m_hit_line_MoBl[1]->Set4direc(HIT_RIGHT);

	//足場ヒットライン作成し、値を設定(上)
	m_hit_line_MoBl[2] = Collision::HitLineInsert(this);
	m_hit_line_MoBl[2]->SetPos1(m_x, m_y);
	m_hit_line_MoBl[2]->SetPos2(m_x + 50, m_y);
	m_hit_line_MoBl[2]->Set4direc(HIT_TOP);

	//足場ヒットライン作成し、値を設定(下)
	m_hit_line_MoBl[3] = Collision::HitLineInsert(this);
	m_hit_line_MoBl[3]->SetPos1(m_x, m_y + 32);
	m_hit_line_MoBl[3]->SetPos2(m_x + 50, m_y + 32);
	m_hit_line_MoBl[3]->Set4direc(HIT_UNDER);

	for (int i = 0; i < 4; i++) {
		m_hit_line_MoBl[i]->SetElement(1);		//属性を1にする
		m_hit_line_MoBl[i]->SetInvisible(false);	//無敵モード無効
		m_hit_line_MoBl[i]->SetAngle();
	}
}

//デストラクタ
ObjMoveBlock::~ObjMoveBlock()
{

}

//アクション
void ObjMoveBlock::Action()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	//位置更新
	m_hit_line_MoBl[0]->SetPos1(m_x + ground->GetScroll(), m_y);
	m_hit_line_MoBl[0]->SetPos2(m_x + ground->GetScroll(), m_y + 32);
	m_hit_line_MoBl[1]->SetPos1(m_x + ground->GetScroll() + 50, m_y);
	m_hit_line_MoBl[1]->SetPos2(m_x + ground->GetScroll() + 50, m_y + 32);
	m_hit_line_MoBl[2]->SetPos1(m_x + ground->GetScroll(), m_y);
	m_hit_line_MoBl[2]->SetPos2(m_x + ground->GetScroll() + 50, m_y);
	m_hit_line_MoBl[3]->SetPos1(m_x + ground->GetScroll(), m_y + 32);
	m_hit_line_MoBl[3]->SetPos2(m_x + ground->GetScroll() + 50, m_y + 32);

}

//ドロー
void ObjMoveBlock::Draw()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	Draw::Draw2D(62, m_x + 23 + ground->GetScroll(), m_y-360, 1, 1);

	Draw::Draw2D(61, m_x + ground->GetScroll(), m_y-20);
}
