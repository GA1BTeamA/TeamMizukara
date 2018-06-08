//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjColorDoor.h"
#include "ObjGround3.h"


//コンストラクタ
ObjColorDoor::ObjColorDoor(float x, float y,int color_number,unsigned int n)
	:m_x(x), m_y(y), m_color_number(color_number)
{
	m_name = COLORDOOR;

	switch (n)
	{
	case 1:	m_name = COLORDOOR; break;
	case 2:	m_name = COLORDOOR2; break;
	case 3:	m_name = COLORDOOR3; break;
	}

	////ヒットライン作成し、値を設定(左)
	//m_hit_line_ColorDoor[0] = Collision::HitLineInsert(this);
	//m_hit_line_ColorDoor[0]->SetPos1(m_x+2, m_y);
	//m_hit_line_ColorDoor[0]->SetPos2(m_x+2, m_y + 140);
	//m_hit_line_ColorDoor[0]->Set4direc(HIT_LEFT);

	////ヒットライン作成し、値を設定(上)
	//m_hit_line_ColorDoor[1] = Collision::HitLineInsert(this);
	//m_hit_line_ColorDoor[1]->SetPos1(m_x+2, m_y);
	//m_hit_line_ColorDoor[1]->SetPos2(m_x+2 + 26, m_y);
	//m_hit_line_ColorDoor[1]->Set4direc(HIT_TOP);

	////ヒットライン作成し、値を設定(右)
	//m_hit_line_ColorDoor[2] = Collision::HitLineInsert(this);
	//m_hit_line_ColorDoor[2]->SetPos1(m_x + 28, m_y);
	//m_hit_line_ColorDoor[2]->SetPos2(m_x + 28, m_y + 140);
	//m_hit_line_ColorDoor[2]->Set4direc(HIT_RIGHT);

	////ヒットライン作成し、値を設定(下)
	//m_hit_line_ColorDoor[3] = Collision::HitLineInsert(this);
	//m_hit_line_ColorDoor[3]->SetPos1(m_x+2, m_y + 140);
	//m_hit_line_ColorDoor[3]->SetPos2(m_x + 28, m_y + 140);
	//m_hit_line_ColorDoor[3]->Set4direc(HIT_UNDER);

	//for (int i = 0; i < 4; i++) {
	//	m_hit_line_ColorDoor[i]->SetElement(1);		//属性を1にする
	//	m_hit_line_ColorDoor[i]->SetInvisible(false);	//無敵モード無効
	//	m_hit_line_ColorDoor[i]->SetAngle();
	//}
}

//デストラクタ
ObjColorDoor::~ObjColorDoor()
{

}

//アクション
void ObjColorDoor::Action()
{
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	////位置更新
	//m_hit_line_ColorDoor[0]->SetPos1(m_x + ground3->GetScroll(), m_y);
	//m_hit_line_ColorDoor[0]->SetPos2(m_x + ground3->GetScroll(), m_y + 140);
	//m_hit_line_ColorDoor[1]->SetPos1(m_x + ground3->GetScroll(), m_y);
	//m_hit_line_ColorDoor[1]->SetPos2(m_x + ground3->GetScroll() + 26, m_y);
	//m_hit_line_ColorDoor[2]->SetPos1(m_x + ground3->GetScroll() + 26, m_y);
	//m_hit_line_ColorDoor[2]->SetPos2(m_x + ground3->GetScroll() + 26, m_y + 140);
	//m_hit_line_ColorDoor[3]->SetPos1(m_x + ground3->GetScroll(), m_y + 140);
	//m_hit_line_ColorDoor[3]->SetPos2(m_x + ground3->GetScroll() + 26, m_y + 140);
}

//ドロー
void ObjColorDoor::Draw()
{
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	//扉表示
	Draw::Draw2D(m_color_number, m_x + ground3->GetScroll(), m_y);

	//緑の扉表示
	//Draw::Draw2D(84, m_x2 + 638 + ground3->GetScroll(), m_y2 - 87);

	//赤の扉表示
	//Draw::Draw2D(76, m_x2+491 + ground3->GetScroll(), m_y2-87);

	//Draw::Draw2D(58, m_gx+ground3->GetScroll()+30, m_gy);
}