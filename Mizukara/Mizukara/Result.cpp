//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Result.h"
#include "Hero.h"
#include "ObjGround.h"
#include "ObjGround2.h"
#include "ObjGround3.h"
#include "Sprinkler.h"
#include "Sprinkler2.h"
#include "Sprinkler3.h"

extern int g_SceneNumber;
extern bool g_key_flag;
extern float g_TankRemaining;
extern bool g_clearlist;
extern bool GetCrearCnt1;
extern bool GetCrearCnt2;
extern bool GetCrearCnt3;

//コンストラクタ
CResult::CResult()
	:m_x(0), m_y(0), m_cursor(UP)
{
	m_name = RESULT;
}

CResult::~CResult()
{

}

void CResult::Action()
{
	Audio::StopLoopMusic(6);

	Audio::StartLoopMusic(10);
	Audio::LoopMusicVolume(10, 0.07f);

	//上を押したら左に
	if (Input::KeyPush(VK_UP) == true)
	{
		m_cursor = UP;
	}
	//下を押したら右に
	else if (Input::KeyPush(VK_DOWN) == true)
	{
		m_cursor = UNDER;
	}

	//カーソル位置が上ならタイトルへ
	if (m_cursor == UP)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				Audio::StartMusic(0);
				Audio::StopLoopMusic(10);
				g_SceneNumber = TITLE;
				g_clearlist = true;
				TaskSystem::TaskClear();
				is_delete = true;
				g_key_flag = false;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}
	//カーソル位置が下ならステージセレクトへ
	else if (m_cursor == UNDER)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				Audio::StartMusic(0);
				Audio::StopLoopMusic(10);
				g_SceneNumber = STAGESELECTO;
				g_clearlist = true;
				TaskSystem::TaskClear();
				is_delete = true;
				g_key_flag = false;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}
	
}

void CResult::Draw()
{
	CSPRI* spri = (CSPRI*)TaskSystem::GetObj(SPRI);
	CSPRI2* spri2 = (CSPRI2*)TaskSystem::GetObj(SPRI2);
	CSPRI3* spri3 = (CSPRI3*)TaskSystem::GetObj(SPRI3);
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);
	ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	if (spri!=nullptr && spri->GetCrearCnt1())
	{
		Draw::Draw2D(101, m_x, m_y);
	}
	else if (spri2 != nullptr && spri2->GetCrearCnt2())
	{
		Draw::Draw2D(102, m_x, m_y);
	}
	else if (spri3 != nullptr && spri3->GetCrearCnt3())
	{
		Draw::Draw2D(103, m_x, m_y);
	}

	if (m_cursor == UP)
	{
		Draw::Draw2D(14, 295, 90);
	}
	else if (m_cursor == UNDER)
	{
		Draw::Draw2D(14, 300, 215);
	}
	else {
		Draw::Draw2D(14,295, 90);
	}

	//ランク表示
	if (g_TankRemaining >= 40)
	{
		Draw::Draw2D(108, 83, 243);
	}
	else if (g_TankRemaining >= 35)
	{
		Draw::Draw2D(107, 83, 243);
	}
	else if (g_TankRemaining >= 25)
	{
		Draw::Draw2D(106, 83, 243);
	}
	else if (g_TankRemaining >= 10)
	{
		Draw::Draw2D(105, 83, 243);
	}
	else if (g_TankRemaining >= 1)
	{
		Draw::Draw2D(104, 83, 243);
	}
}