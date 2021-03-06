//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Background.h"
#include "ObjGround2.h"
#include "ObjGround3.h"
#include "Hero.h"

extern int g_SceneNumber;

CBackground::CBackground()
	:m_x(0), m_y(0), m_scroll(0.0f)
	, m_x2(0),m_x_2(2400),m_x2_2(2400)
{
	
}

CBackground::~CBackground()
{

}

void CBackground::Action()
{
	
	if (g_SceneNumber == GAME_MAIN)
	{
		//スクロール値加算
		m_x -= 0.15f;
		m_x2 -= 0.05f;
		m_x_2 -= 0.15f;
		m_x2_2 -= 0.05f;

		//端っこまで来たら位置を更新(雲だけ)
		if (m_x < -2400)
		{
			m_x = 2390.0f;
		}
		else if (m_x2 < -2400)
		{
			m_x2 = 2390.0f;
		}

		//2枚目端っこまで来たら位置を更新(空と雲)
		if (m_x_2 < -2400)
		{
			m_x_2 = 2390.0f;
		}
		else if (m_x2_2 < -2400)
		{
			m_x2_2 = 2390.0f;
		}
	}
}

void CBackground::Draw()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);
	ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	//背景描画
	if (ground != nullptr) {
		//Draw::Draw2D(24, m_x, m_y);
		Draw::Draw2D(24, 0, 0);
		Draw::Draw2D(100, m_x2, m_y);
		Draw::Draw2D(100, m_x2_2, m_y);
		Draw::Draw2D(114, m_x, m_y);
		Draw::Draw2D(114, m_x_2, m_y);
		Draw::Draw2D(110, ground->GetScroll()*0.2f, m_y);
	}
	else if(ground2!=nullptr)
		Draw::Draw2D(78, m_x+ground2->GetScroll(), m_y);
	else if(ground3!=nullptr)
		Draw::Draw2D(79, m_x+ground3->GetScroll(), m_y);
}