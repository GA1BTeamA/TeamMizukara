//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "BucketMeter.h"
#include "ObjGround.h"
#include "ObjGround2.h"
#include "Sprinkler.h"
#include "WTM3.h"
extern int g_SceneNumber;
extern bool g_key_flag;

const float CBucketMeter::m_BM_water_amount = 0.04f;
const float CBucketMeter::m_BM_wave_amount = 1.6f;

//コンストラクタ
CBucketMeter::CBucketMeter()
	:m_x(600), m_y(430)
	, m_wave_x(605), m_wave_y(580)
	, m_water_x(605), m_water_y(582)
	, m_ani_time1(0.0f), m_ani_time2(0.0f)
	, m_water_remaining(0.0f)
{
	m_name = BUCKETMETER;

	//水の色用配列初期化
	rgba[0] = 1.0f;
	rgba[1] = 1.0f;
	rgba[2] = 1.0f;
	rgba[3] = 1.0f;
}

//デストラクタ
CBucketMeter::~CBucketMeter()
{

}

//アクション
void CBucketMeter::Action()
{
	//CWTM3* wtm3 = (CWTM3*)TaskSystem::GetObj(WTM3);

	//if (wtm3 != nullptr)
	//{
	//	if (wtm3->GetColorR() == 2.0f)
	//	{
	//		rgba[0] = 2.0f;
	//		rgba[1] = 0.5f;
	//		rgba[2] = 0.5f;
	//		rgba[3] = 1.0f;
	//	}
	//}
}

//ドロー
void CBucketMeter::Draw()
{
	//描画
	Draw::Draw2D(49, m_x, m_y);

	//水表示
	Draw::Draw2D(48, m_water_x, m_water_y, 6.3, -(m_water_remaining-(3.7f- m_water_remaining)*0.35),rgba);

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
		Draw::Draw2D(36, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}
	else if (m_ani_time1 < 20)
	{
		Draw::Draw2D(37, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}
	else if (m_ani_time1 < 30)
	{
		Draw::Draw2D(38, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}
	else if (m_ani_time1 < 40)
	{
		Draw::Draw2D(39, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}
	else if (m_ani_time1 < 50)
	{
		Draw::Draw2D(40, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}
	else if (m_ani_time1 < 60)
	{
		Draw::Draw2D(41, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}
	else if (m_ani_time1 < 70)
	{
		Draw::Draw2D(42, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}
	else if (m_ani_time1 < 80)
	{
		Draw::Draw2D(43, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}
	else if (m_ani_time1 < 90)
	{
		Draw::Draw2D(44, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}
	else if (m_ani_time1 < 100)
	{
		Draw::Draw2D(45, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}
	else if (m_ani_time1 < 110)
	{
		Draw::Draw2D(46, m_wave_x, m_wave_y, 2.1, 2, rgba);
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
		Draw::Draw2D(25, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}
	else if (m_ani_time2 < 10)
	{
		Draw::Draw2D(26, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}
	else if (m_ani_time2 < 15)
	{
		Draw::Draw2D(27, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}
	else if (m_ani_time2 < 20)
	{
		Draw::Draw2D(28, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}
	else if (m_ani_time2 < 25)
	{
		Draw::Draw2D(29, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}
	else if (m_ani_time2 < 30)
	{
		Draw::Draw2D(30, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}
	else if (m_ani_time2 < 35)
	{
		Draw::Draw2D(31, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}
	else if (m_ani_time2 < 40)
	{
		Draw::Draw2D(32, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}
	else if (m_ani_time2 < 45)
	{
		Draw::Draw2D(33, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}
	else if (m_ani_time2 < 50)
	{
		Draw::Draw2D(34, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}
	else if (m_ani_time2 < 55)
	{
		Draw::Draw2D(35, m_wave_x, m_wave_y, 2.1, 2, rgba);
	}



	Draw::Draw2D(11, m_x, m_y);
}

void CBucketMeter::PushX()
{
	m_water_remaining += m_BM_water_amount;
	m_wave_y -= m_BM_wave_amount;
}

void CBucketMeter::PushC()
{
	m_water_remaining -= m_BM_water_amount;
	m_wave_y += m_BM_wave_amount;
}
