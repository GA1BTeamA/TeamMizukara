//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjColorDoor.h"
#include "ObjGround3.h"


//コンストラクタ
ObjColorDoor::ObjColorDoor()
	:m_x(425), m_y(261), m_x2(425), m_y2(261)
{
	m_name = COLORDOOR;

	//ヒットライン作成し、値を設定(左)
	m_hit_line_ColorDoor[0] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoor[0]->SetPos1(m_x+2, m_y);
	m_hit_line_ColorDoor[0]->SetPos2(m_x+2, m_y + 140);
	m_hit_line_ColorDoor[0]->Set4direc(HIT_LEFT);

	//ヒットライン作成し、値を設定(上)
	m_hit_line_ColorDoor[1] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoor[1]->SetPos1(m_x+2, m_y);
	m_hit_line_ColorDoor[1]->SetPos2(m_x+2 + 26, m_y);
	m_hit_line_ColorDoor[1]->Set4direc(HIT_TOP);

	//ヒットライン作成し、値を設定(右)
	m_hit_line_ColorDoor[2] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoor[2]->SetPos1(m_x + 28, m_y);
	m_hit_line_ColorDoor[2]->SetPos2(m_x + 28, m_y + 140);
	m_hit_line_ColorDoor[2]->Set4direc(HIT_RIGHT);

	//ヒットライン作成し、値を設定(下)
	m_hit_line_ColorDoor[3] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoor[3]->SetPos1(m_x+2, m_y + 140);
	m_hit_line_ColorDoor[3]->SetPos2(m_x + 28, m_y + 140);
	m_hit_line_ColorDoor[3]->Set4direc(HIT_UNDER);

	for (int i = 0; i < 4; i++) {
		m_hit_line_ColorDoor[i]->SetElement(1);		//属性を1にする
		m_hit_line_ColorDoor[i]->SetInvisible(false);	//無敵モード無効
		m_hit_line_ColorDoor[i]->SetAngle();
	}
}

//デストラクタ
ObjColorDoor::~ObjColorDoor()
{

}

//アクション
void ObjColorDoor::Action()
{
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	//位置更新
	m_hit_line_ColorDoor[0]->SetPos1(m_x + ground3->GetScroll(), m_y);
	m_hit_line_ColorDoor[0]->SetPos2(m_x + ground3->GetScroll(), m_y + 140);
	m_hit_line_ColorDoor[1]->SetPos1(m_x + ground3->GetScroll(), m_y);
	m_hit_line_ColorDoor[1]->SetPos2(m_x + ground3->GetScroll() + 26, m_y);
	m_hit_line_ColorDoor[2]->SetPos1(m_x + ground3->GetScroll() + 26, m_y);
	m_hit_line_ColorDoor[2]->SetPos2(m_x + ground3->GetScroll() + 26, m_y + 140);
	m_hit_line_ColorDoor[3]->SetPos1(m_x + ground3->GetScroll(), m_y + 140);
	m_hit_line_ColorDoor[3]->SetPos2(m_x + ground3->GetScroll() + 26, m_y + 140);
}

//ドロー
void ObjColorDoor::Draw()
{
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	//赤の扉表示
	Draw::Draw2D(76, m_x + ground3->GetScroll(), m_y);

	//赤の扉表示
	Draw::Draw2D(76, m_x2+491 + ground3->GetScroll(), m_y2-87);

	//緑の扉表示
	Draw::Draw2D(84, m_x2 + 638 + ground3->GetScroll(), m_y2 - 87);

	//Draw::Draw2D(58, m_gx+ground3->GetScroll()+30, m_gy);
}