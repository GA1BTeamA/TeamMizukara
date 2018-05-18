//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjUpScaffold.h"
#include "ObjGround.h"



ObjUpScaffold::ObjUpScaffold()
	:m_x(500),m_y(350)
{
	//足場ヒットライン作成し、値を設定(左)
	m_hit_line_UpSc[0] = Collision::HitLineInsert(this);
	m_hit_line_UpSc[0]->SetPos1(m_x, m_y);
	m_hit_line_UpSc[0]->SetPos2(m_x, m_y + 50);
	m_hit_line_UpSc[0]->Set4direc(HIT_LEFT);

	//足場ヒットライン作成し、値を設定(右)
	m_hit_line_UpSc[1] = Collision::HitLineInsert(this);
	m_hit_line_UpSc[1]->SetPos1(m_x + 100, m_y);
	m_hit_line_UpSc[1]->SetPos2(m_x + 100, m_y + 50);
	m_hit_line_UpSc[1]->Set4direc(HIT_RIGHT);

	//足場ヒットライン作成し、値を設定(上)
	m_hit_line_UpSc[2] = Collision::HitLineInsert(this);
	m_hit_line_UpSc[2]->SetPos1(m_x, m_y);
	m_hit_line_UpSc[2]->SetPos2(m_x + 100, m_y);
	m_hit_line_UpSc[2]->Set4direc(HIT_TOP);

	//足場ヒットライン作成し、値を設定(下)
	m_hit_line_UpSc[3] = Collision::HitLineInsert(this);
	m_hit_line_UpSc[3]->SetPos1(m_x, m_y + 50);
	m_hit_line_UpSc[3]->SetPos2(m_x + 100, m_y + 50);
	m_hit_line_UpSc[3]->Set4direc(HIT_UNDER);

	for (int i = 0; i < 4; i++) {
		m_hit_line_UpSc[i]->SetElement(1);		//属性を1にする
		m_hit_line_UpSc[i]->SetInvisible(false);	//無敵モード無効
		m_hit_line_UpSc[i]->SetAngle();
	}

}


ObjUpScaffold::~ObjUpScaffold()
{
}

void ObjUpScaffold::Action()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	//位置更新
	m_hit_line_UpSc[0]->SetPos1(m_x + ground->GetScroll(), m_y);
	m_hit_line_UpSc[0]->SetPos2(m_x + ground->GetScroll(), m_y + 50);
	m_hit_line_UpSc[1]->SetPos1(m_x + ground->GetScroll() + 100, m_y);
	m_hit_line_UpSc[1]->SetPos2(m_x + ground->GetScroll() + 100, m_y + 50);
	m_hit_line_UpSc[2]->SetPos1(m_x + ground->GetScroll(), m_y);
	m_hit_line_UpSc[2]->SetPos2(m_x + ground->GetScroll() + 100, m_y);
	m_hit_line_UpSc[3]->SetPos1(m_x + ground->GetScroll(), m_y + 50);
	m_hit_line_UpSc[3]->SetPos2(m_x + ground->GetScroll() + 100, m_y + 50);

}

void ObjUpScaffold::Draw()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);


}
