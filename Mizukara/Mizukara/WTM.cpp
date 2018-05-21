//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "WTM.h"
#include "ObjGround.h"
#include "Hero.h"
#include "Tank.h"
extern int g_SceneNumber;

const float CWTM::m_WaveSize_x = 0.5f;
const float CWTM::m_WaveSize_y = 0.6f;

const float CWTM::m_water_amount = 0.026f;
const float CWTM::m_wave_amount = 0.35f;

CWTM::CWTM()
	:m_x(1186), m_y(234), /*m_wave_x(1190), m_wave_y(150),*/m_ani_time1(0.0f),m_ani_time2(0.0f)
	,im_x(1166), im_y(30)/*, m_water_x(1186), m_water_y(204)*/
{
	//ヒットラインの作成(左)
	m_p_hit_line_wtm = Collision::HitLineInsert(this);
	m_p_hit_line_wtm->SetPos1(m_x, m_y);
	m_p_hit_line_wtm->SetPos2(m_x, m_y+100);
	m_p_hit_line_wtm->SetElement(2);		//属性を2にする
	m_p_hit_line_wtm->SetInvisible(false);	//無敵モード無効
}

CWTM::~CWTM()
{

}

void CWTM::Action()
{
	CHero* hero = (CHero*)TaskSystem::GetObj(PLAYER);
	CTank* tank = (CTank*)TaskSystem::GetObj(TANK);

	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_wtm->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_wtm->GetHitData()[i]->GetElement() == 0)
			{
				//タンクから水を汲む
				if (Input::KeyPush('X'))
				{
					tank->SetWater_Remaining(m_water_amount);
					tank->SetWaveY(tank->GetWaveY(),m_wave_amount);
				}

				//水をタンクに戻す
				if (Input::KeyPush('C'))
				{
					tank->SetWater_Remaining(m_water_amount);
					tank->SetWaveY(tank->GetWaveY(),m_wave_amount);
				}
			}
		}
	}

	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	//当たり判定位置の更新
	m_p_hit_line_wtm->SetPos1(m_x+ground->GetScroll(), m_y);
	m_p_hit_line_wtm->SetPos2(m_x+ground->GetScroll(), m_y + 100);
}

void CWTM::Draw()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);
	CTank* tank = (CTank*)TaskSystem::GetObj(TANK);

	//WTMに近づいたらアイコンを出す
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_wtm->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_wtm->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(21, im_x + ground->GetScroll(), im_y);
			}
		}
	}

	//水表示
	Draw::Draw2D(48, (tank->GetWaterX()+1175) + ground->GetScroll(), tank->GetWaterY()-176,1.6, -tank->GetWater_Remaining()/2.6);

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
		Draw::Draw2D(36, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 20)
	{
		Draw::Draw2D(37, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 30)
	{
		Draw::Draw2D(38, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 40)
	{
		Draw::Draw2D(39, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 50)
	{
		Draw::Draw2D(40, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 60)
	{
		Draw::Draw2D(41, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 70)
	{
		Draw::Draw2D(42, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 80)
	{
		Draw::Draw2D(43, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 90)
	{
		Draw::Draw2D(44, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 100)
	{
		Draw::Draw2D(45, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 110)
	{
		Draw::Draw2D(46, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
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
		Draw::Draw2D(25, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 10)
	{
		Draw::Draw2D(26, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 15)
	{
		Draw::Draw2D(27, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 20)
	{
		Draw::Draw2D(28, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 25)
	{
		Draw::Draw2D(29, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 30)
	{
		Draw::Draw2D(30, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 35)
	{
		Draw::Draw2D(31, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 40)
	{
		Draw::Draw2D(32, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 45)
	{
		Draw::Draw2D(33, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 50)
	{
		Draw::Draw2D(34, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 55)
	{
		Draw::Draw2D(35, (tank->GetWaveX() + 1179) + ground->GetScroll(), *tank->GetWaveY() - 100, m_WaveSize_x, m_WaveSize_y);
	}

	//Draw::Draw2D(21, a, m_y);
}