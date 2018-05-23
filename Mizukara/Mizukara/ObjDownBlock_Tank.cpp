//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjDownBlock_Tank.h"
#include "ObjGround.h"
extern int g_SceneNumber;

const float ObjDownBlock_Tank::m_WaveSize_x = 0.5f;
const float ObjDownBlock_Tank::m_WaveSize_y = 0.6f;

ObjDownBlock_Tank::ObjDownBlock_Tank()
	:m_x(676), m_y(150),m_gx(691),m_gy(135), m_wave_x(1190), m_wave_y(150), m_ani_time1(0.0f), m_ani_time2(0.0f)
	, m_water_x(1186), m_water_y(162)
{
	//ヒットラインの作成(左)
	m_hit_line_DwBlTank = Collision::HitLineInsert(this);
	m_hit_line_DwBlTank->SetPos1(m_x, m_y);
	m_hit_line_DwBlTank->SetPos2(m_x, m_y + 100);
	m_hit_line_DwBlTank->SetElement(2);		//属性を2にする
	m_hit_line_DwBlTank->SetInvisible(false);	//無敵モード無効
}

ObjDownBlock_Tank::~ObjDownBlock_Tank()
{

}

void ObjDownBlock_Tank::Action()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	//当たり判定位置の更新
	m_hit_line_DwBlTank->SetPos1(m_x + ground->GetScroll(), m_y);
	m_hit_line_DwBlTank->SetPos2(m_x + ground->GetScroll(), m_y + 100);
}

void ObjDownBlock_Tank::Draw()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	//WTMに近づいたらアイコンを出す
	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_DwBlTank->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_DwBlTank->GetHitData()[i]->GetElement() == 0)
		    {
				Draw::Draw2D(21, m_x + 20 + ground->GetScroll(), m_y);
			}
		}
	}

	//水表示
	Draw::Draw2D(48, m_water_x + ground->GetScroll(), m_water_y, 1.6, 1.4);

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
		Draw::Draw2D(36, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 20)
	{
		Draw::Draw2D(37, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 30)
	{
		Draw::Draw2D(38, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 40)
	{
		Draw::Draw2D(39, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 50)
	{
		Draw::Draw2D(40, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 60)
	{
		Draw::Draw2D(41, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 70)
	{
		Draw::Draw2D(42, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 80)
	{
		Draw::Draw2D(43, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 90)
	{
		Draw::Draw2D(44, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 100)
	{
		Draw::Draw2D(45, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 110)
	{
		Draw::Draw2D(46, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
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
		Draw::Draw2D(25, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 10)
	{
		Draw::Draw2D(26, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 15)
	{
		Draw::Draw2D(27, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 20)
	{
		Draw::Draw2D(28, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 25)
	{
		Draw::Draw2D(29, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 30)
	{
		Draw::Draw2D(30, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 35)
	{
		Draw::Draw2D(31, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 40)
	{
		Draw::Draw2D(32, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 45)
	{
		Draw::Draw2D(33, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 50)
	{
		Draw::Draw2D(34, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 55)
	{
		Draw::Draw2D(35, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}

	//Draw::Draw2D(21, a, m_y);

	Draw::Draw2D(56, m_gx + ground->GetScroll(), m_gy, 1, 1);
	Draw::Draw2D(59, m_gx + 25 + ground->GetScroll(), m_gy - 23, 1, 1);
	Draw::Draw2D(57, m_gx + 5 + ground->GetScroll(), m_gy - 25, 1, 1);
}