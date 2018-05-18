//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Tank.h"
#include "ObjGround.h"
#include "Hero.h"
extern int g_SceneNumber;

const float CTank::m_water_amount = 0.01f;
const float CTank::m_wave_amount = 0.3f;

CTank::CTank()
	:m_x(40), m_y(250), m_wave_x(11), m_wave_y(250)
	,im_x(33), im_y(130),m_ani_time1(0.0f),m_ani_time2(0.0f)
	, m_water_x(11), m_water_y(380)
	, m_water_remaining(3.65f)
{
	m_name = TANK;

	//ヒットラインの作成
	m_p_hit_line_tank = Collision::HitLineInsert(this);
	m_p_hit_line_tank->SetPos1(m_x + 110, m_y);
	m_p_hit_line_tank->SetPos2(m_x + 110, m_y + 150);
	m_p_hit_line_tank->SetElement(3);		//属性を3にする
	m_p_hit_line_tank->SetInvisible(false);	//無敵モード無効
}

CTank::~CTank()
{

}

void CTank::Action()
{
	CHero* hero = (CHero*)TaskSystem::GetObj(PLAYER);

	//タンクから水を汲む＆戻す
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_tank->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_tank->GetHitData()[i]->GetElement() == 0)
			{
				//タンクから水を汲む
				if (Input::KeyPush('X'))
				{
					if (hero->GetDirec() == LEFT)
					{
						SetWater_Remaining(m_water_amount);
						SetWaveY(&m_wave_y,m_wave_amount);
					}
				}

				//水をタンクに戻す
				if (Input::KeyPush('C'))
				{
					if (hero->GetDirec() == LEFT)
					{
						SetWater_Remaining(m_water_amount);
						SetWaveY(&m_wave_y,m_wave_amount);
					}
				}
			}
		}
	}
}

void CTank::Draw()
{
	CHero* hero = (CHero*)TaskSystem::GetObj(PLAYER);

	//タンクに近づいたらアイコンを出す
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_tank->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_tank->GetHitData()[i]->GetElement() == 0)
			{
				if (hero->GetDirec() == LEFT)
				{
					Draw::Draw2D(47, im_x, im_y);
				}
			}
		}
	}

	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	//水表示
	Draw::Draw2D(48, m_water_x +ground->GetScroll(), m_water_y,2.95, -m_water_remaining);

	//波アニメーション(後ろ)
	if (m_ani_time1 >= 109)
	{
		m_ani_time1 = 0;
	}
	else
	{
		m_ani_time1++;
	}

	//波アニメーション
    if (m_ani_time1 < 10)
	{
		Draw::Draw2D(36, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 20)
	{
Draw::Draw2D(37, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 30)
	{
		Draw::Draw2D(38, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 40)
	{
		Draw::Draw2D(39, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 50)
	{
		Draw::Draw2D(40, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 60)
	{
		Draw::Draw2D(41, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 70)
	{
		Draw::Draw2D(42, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 80)
	{
		Draw::Draw2D(43, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 90)
	{
		Draw::Draw2D(44, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 100)
	{
		Draw::Draw2D(45, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 110)
	{
		Draw::Draw2D(46, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}

	//波アニメーション(前)
	if (m_ani_time2 >= 54)
	{
		m_ani_time2 = 0;
	}
	else
	{
		m_ani_time2++;
	}

	//波アニメーション
	if (m_ani_time2 < 5)
	{
		Draw::Draw2D(25, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 10)
	{
		Draw::Draw2D(26, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 15)
	{
		Draw::Draw2D(27, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 20)
	{
		Draw::Draw2D(28, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 25)
	{
		Draw::Draw2D(29, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 30)
	{
		Draw::Draw2D(30, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 35)
	{
		Draw::Draw2D(31, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 40)
	{
		Draw::Draw2D(32, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 45)
	{
		Draw::Draw2D(33, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 50)
	{
		Draw::Draw2D(34, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 55)
	{
		Draw::Draw2D(35, m_wave_x + ground->GetScroll(), m_wave_y, 1, 1);
	}
	/*else if (m_ani_time > 16)
	{
	Draw::Draw2D(32, m_x8, m_y8);
	}*/
}

//水の残量設定
void CTank::SetWater_Remaining(float water_amount)
{
	if (Input::KeyPush('X'))
	{
		m_water_remaining -= water_amount;
	}
	else if(Input::KeyPush('C'))
	{
		m_water_remaining += water_amount;
	}
}

//波の増減
void CTank::SetWaveY(float* wave_y,float wave_amount)
{
	if (Input::KeyPush('X'))
	{
		*wave_y += wave_amount;
	}
	else if (Input::KeyPush('C'))
	{
		*wave_y -= wave_amount;
	}
}