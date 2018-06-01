//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjColorDoor_Tank.h"
#include "ObjGround3.h"


//コンストラクタ
ObjColorDoor_Tank::ObjColorDoor_Tank()
	:m_x(230), m_y(299), m_gx(230), m_gy(299)
{
	//ヒットラインの作成
	m_hit_line_ColorDoorTank[0] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoorTank[0]->SetPos1(m_x + 115, m_y);
	m_hit_line_ColorDoorTank[0]->SetPos2(m_x + 115, m_y + 36);
	m_hit_line_ColorDoorTank[0]->SetElement(2);		//属性を2にする
	m_hit_line_ColorDoorTank[0]->SetInvisible(false);	//無敵モード無効

	//ヒットラインの作成
	m_hit_line_ColorDoorTank[1] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoorTank[1]->SetPos1(m_x, m_y);
	m_hit_line_ColorDoorTank[1]->SetPos2(m_x, m_y+110);
	m_hit_line_ColorDoorTank[1]->SetElement(3);		//属性を2にする
	m_hit_line_ColorDoorTank[1]->SetInvisible(false);	//無敵モード無効
}

//デストラクタ
ObjColorDoor_Tank::~ObjColorDoor_Tank()
{

}

//アクション
void ObjColorDoor_Tank::Action()
{

}

//ドロー
void ObjColorDoor_Tank::Draw()
{
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	for (int i = 0; i < 10; i++)
	{
		//ギミックに近づいたらアイコンを出す
		if (m_hit_line_ColorDoorTank[0]->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_ColorDoorTank[0]->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(70, m_gx + 92 + ground3->GetScroll(), m_gy - 110);
			}
		}

		//ギミックタンクに近づいたらアイコンを出す
		if (m_hit_line_ColorDoorTank[1]->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_ColorDoorTank[1]->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(21, m_gx + ground3->GetScroll()-10, m_gy - 130);
			}
		}
	}

	//赤のWTM表示
	Draw::Draw2D(74, m_gx + ground3->GetScroll(), m_gy);

	//赤のギミックタンク表示
	Draw::Draw2D(75, m_gx+115 + ground3->GetScroll(), m_gy+36);

	//Draw::Draw2D(58, m_gx + ground3->GetScroll(), m_gy+100);
}