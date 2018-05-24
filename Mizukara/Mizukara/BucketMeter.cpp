//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "BucketMeter.h"
#include "ObjGround.h"
#include "Sprinkler.h"
extern int g_SceneNumber;
extern bool g_key_flag;

const float CBucketMeter::m_BM_water_amount = 0.04f;
const float CBucketMeter::m_BM_wave_amount = 1.2f;

CBucketMeter::CBucketMeter()
	:m_x(600), m_y(430)
	, m_wave_x(605), m_wave_y(546)
	, m_water_x(605), m_water_y(585)
	, m_ani_time1(0.0f), m_ani_time2(0.0f)
	, m_water_remaining(0.0f)
{
	m_name = BUCKETMETER;
}

CBucketMeter::~CBucketMeter()
{

}

void CBucketMeter::Action()
{
	//リザルト画面になったら破棄
	if (g_SceneNumber == RESULT)
	{
		is_delete = true;
	}

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
}

void CBucketMeter::Draw()
{
	//描画
	Draw::Draw2D(49, m_x, m_y);

	//水表示
	Draw::Draw2D(48, m_water_x, m_water_y, 6.3, -m_water_remaining);

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
		Draw::Draw2D(36, m_wave_x, m_wave_y, 2.1, 2);
	}
	else if (m_ani_time1 < 20)
	{
		Draw::Draw2D(37, m_wave_x, m_wave_y, 2.1, 2);
	}
	else if (m_ani_time1 < 30)
	{
		Draw::Draw2D(38, m_wave_x, m_wave_y, 2.1, 2);
	}
	else if (m_ani_time1 < 40)
	{
		Draw::Draw2D(39, m_wave_x, m_wave_y, 2.1, 2);
	}
	else if (m_ani_time1 < 50)
	{
		Draw::Draw2D(40, m_wave_x, m_wave_y, 2.1, 2);
	}
	else if (m_ani_time1 < 60)
	{
		Draw::Draw2D(41, m_wave_x, m_wave_y, 2.1, 2);
	}
	else if (m_ani_time1 < 70)
	{
		Draw::Draw2D(42, m_wave_x, m_wave_y, 2.1, 2);
	}
	else if (m_ani_time1 < 80)
	{
		Draw::Draw2D(43, m_wave_x, m_wave_y, 2.1, 2);
	}
	else if (m_ani_time1 < 90)
	{
		Draw::Draw2D(44, m_wave_x, m_wave_y, 2.1, 2);
	}
	else if (m_ani_time1 < 100)
	{
		Draw::Draw2D(45, m_wave_x, m_wave_y, 2.1, 2);
	}
	else if (m_ani_time1 < 110)
	{
		Draw::Draw2D(46, m_wave_x, m_wave_y, 2.1, 2);
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
		Draw::Draw2D(25, m_wave_x, m_wave_y, 2.1, 2);
	}
	else if (m_ani_time2 < 10)
	{
		Draw::Draw2D(26, m_wave_x, m_wave_y, 2.1, 2);
	}
	else if (m_ani_time2 < 15)
	{
		Draw::Draw2D(27, m_wave_x, m_wave_y, 2.1, 2);
	}
	else if (m_ani_time2 < 20)
	{
		Draw::Draw2D(28, m_wave_x, m_wave_y, 2.1, 2);
	}
	else if (m_ani_time2 < 25)
	{
		Draw::Draw2D(29, m_wave_x, m_wave_y, 2.1, 2);
	}
	else if (m_ani_time2 < 30)
	{
		Draw::Draw2D(30, m_wave_x, m_wave_y, 2.1, 2);
	}
	else if (m_ani_time2 < 35)
	{
		Draw::Draw2D(31, m_wave_x, m_wave_y, 2.1, 2);
	}
	else if (m_ani_time2 < 40)
	{
		Draw::Draw2D(32, m_wave_x, m_wave_y, 2.1, 2);
	}
	else if (m_ani_time2 < 45)
	{
		Draw::Draw2D(33, m_wave_x, m_wave_y, 2.1, 2);
	}
	else if (m_ani_time2 < 50)
	{
		Draw::Draw2D(34, m_wave_x, m_wave_y, 2.1, 2);
	}
	else if (m_ani_time2 < 55)
	{
		Draw::Draw2D(35, m_wave_x, m_wave_y, 2.1, 2);
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
