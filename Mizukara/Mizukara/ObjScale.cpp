//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjScale.h"
#include "ObjGround2.h"
#include "ObjGround3.h"
#include "Sprinkler.h"
#include <math.h>
extern bool g_key_flag;
extern int g_SceneNumber;

ObjScale::ObjScale(float x,float y,unsigned int n)
	:m_x(x+70), m_y(y-17),m_angle(0.0f)
{
	switch (n)
	{
	case 1:	m_name = SCALE1; break;
	case 2:	m_name = SCALE2; break;
	case 3:	m_name = SCALE3; break;
	case 4:	m_name = SCALE4; break;
	case 5:	m_name = SCALE5; break;

	}

	////天秤ヒットライン作成し、値を設定(左)
	//m_hit_line_Scale[0] = Collision::HitLineInsert(this);
	//m_hit_line_Scale[0]->SetPos1(m_x, m_y);
	//m_hit_line_Scale[0]->SetPos2(m_x, m_y + 13);
	//m_hit_line_Scale[0]->Set4direc(HIT_LEFT);

	////天秤ヒットライン作成し、値を設定(右)
	//m_hit_line_Scale[1] = Collision::HitLineInsert(this);
	//m_hit_line_Scale[1]->SetPos1(m_x + 145, m_y);
	//m_hit_line_Scale[1]->SetPos2(m_x + 145, m_y + 13);
	//m_hit_line_Scale[1]->Set4direc(HIT_RIGHT);

	//天秤ヒットライン作成し、値を設定(上)
	m_hit_line_Scale[0] = Collision::HitLineInsert(this);
	m_hit_line_Scale[0]->SetPos1(m_x, m_y);
	m_hit_line_Scale[0]->SetPos2(m_x + 145, m_y);
	m_hit_line_Scale[0]->Set4direc(HIT_TOP);

	////天秤ヒットライン作成し、値を設定(上)
	//m_hit_line_Scale[1] = Collision::HitLineInsert(this);
	//m_hit_line_Scale[1]->SetPos1(m_x2, m_y2);
	//m_hit_line_Scale[1]->SetPos2(m_x2+145, m_y2);
	//m_hit_line_Scale[1]->Set4direc(HIT_TOP);

	////天秤ヒットライン作成し、値を設定(下)
	//m_hit_line_Scale[3] = Collision::HitLineInsert(this);
	//m_hit_line_Scale[3]->SetPos1(m_x, m_y + 13);
	//m_hit_line_Scale[3]->SetPos2(m_x + 145, m_y + 13);
	//m_hit_line_Scale[3]->Set4direc(HIT_UNDER);

	for (int i = 0; i < 2; i++) {
		m_hit_line_Scale[0]->SetElement(1);		//属性を1にする
		m_hit_line_Scale[0]->SetInvisible(false);	//無敵モード無効
		m_hit_line_Scale[0]->SetAngle();
	}

}


ObjScale::~ObjScale()
{
}

void ObjScale::Action()
{
	ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	//CSPRI* spri = (CSPRI*)TaskSystem::GetObj(SPRI);
	////クリア画面が表示されたら
	//if (spri->GetCrearCnt() == true)
	//{
	//	//エンターキーが押されたら
	//	if (Input::KeyPush(VK_RETURN) == true)
	//	{
	//		if (g_key_flag)
	//		{
	//			//破棄
	//			is_delete = true;
	//			g_key_flag = false;
	//		}
	//	}
	//	else
	//	{
	//		g_key_flag = true;
	//	}
	//}

	//位置更新
	//m_hit_line_Scale[0]->SetPos1(m_x + ground2->GetScroll(), m_y);
	//m_hit_line_Scale[0]->SetPos2(m_x + ground2->GetScroll(), m_y + 13);
	//m_hit_line_Scale[1]->SetPos1(m_x + ground2->GetScroll() + 145, m_y);
	//m_hit_line_Scale[1]->SetPos2(m_x + ground2->GetScroll() + 145, m_y + 13);

	switch (g_SceneNumber)
	{
	case GAME_MAIN2:
		m_hit_line_Scale[0]->SetPos1(m_x + 4.0f + ground2->GetScroll() + 72.5*sin(3.14 / 180 * (fmod((270.0f + 5.12316553f + m_angle), 360))), m_y + 72.5*(-cos(3.14 / 180 * ((270.0f + 5.12316553f + m_angle)))));;
		m_hit_line_Scale[0]->SetPos2(m_x + 4.0f + ground2->GetScroll() + 72.5 * sin(3.14 / 180 * (fmod((90.0f - 5.12316553f + m_angle), 360))), m_y + 72.5 * (-cos(3.14 / 180 * ((90.0f - 5.12316553f + m_angle)))));
		//m_hit_line_Scale[1]->SetPos1(m_x2 + 4.0f + ground2->GetScroll() + 72.5*sin(3.14 / 180 * (fmod((270.0f + 5.12316553f + m_angle), 360))), m_y2 + 72.5*(-cos(3.14 / 180 * ((270.0f + 5.12316553f + m_angle)))));
		//m_hit_line_Scale[1]->SetPos2(m_x2 + 4.0f + ground2->GetScroll() + 72.5 * sin(3.14 / 180 * (fmod((90.0f - 5.12316553f + m_angle), 360))), m_y2 + 72.5 * (-cos(3.14 / 180 * ((90.0f - 5.12316553f + m_angle)))));
			break;

	case GAME_MAIN3:
		m_hit_line_Scale[0]->SetPos1(m_x + 4.0f + ground3->GetScroll() + 72.5*sin(3.14 / 180 * (fmod((270.0f + 5.12316553f + m_angle), 360))), m_y + 72.5*(-cos(3.14 / 180 * ((270.0f + 5.12316553f + m_angle)))));
		m_hit_line_Scale[0]->SetPos2(m_x + 4.0f + ground3->GetScroll() + 72.5 * sin(3.14 / 180 * (fmod((90.0f - 5.12316553f + m_angle), 360))), m_y + 72.5 * (-cos(3.14 / 180 * ((90.0f - 5.12316553f + m_angle)))));
		break;
	}
	//m_hit_line_Scale[2]->SetPos1(m_x + 4.0f + ground2->GetScroll()+72.5*sin(3.14 / 180 * (fmod((270.0f+5.12316553f+ m_angle),360))), m_y+ 72.5*(-cos(3.14 / 180 * ((270.0f + 5.12316553f+ m_angle)))));
	//m_hit_line_Scale[2]->SetPos2(m_x + 4.0f + ground2->GetScroll() + 72.5 * sin(3.14 / 180 * (fmod((90.0f - 5.12316553f+ m_angle), 360))), m_y + 72.5 * (-cos(3.14 / 180 * ((90.0f - 5.12316553f+ m_angle)))));
	//m_hit_line_Scale[3]->SetPos1(m_x + ground2->GetScroll(), m_y + 13);
	//m_hit_line_Scale[3]->SetPos2(m_x + ground2->GetScroll() + 145, m_y + 13);

	m_hit_line_Scale[0]->SetAngle();
	//m_hit_line_Scale[1]->SetAngle();

}

void ObjScale::Draw()
{
	ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	switch (g_SceneNumber)
	{
	case GAME_MAIN2:
		//足場
		Draw::Draw2D(81, m_x - 70 + ground2->GetScroll(), m_y - 10, m_angle);
		Draw::Draw2D(81, m_x2 - 70 + ground2->GetScroll(), m_y2 - 10, m_angle);

		break;

	case GAME_MAIN3:
		//足場
		Draw::Draw2D(81, m_x - 70 + ground3->GetScroll(), m_y - 10, m_angle);
	}
}
