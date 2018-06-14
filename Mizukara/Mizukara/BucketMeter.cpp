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
	, m_wave_x(605), m_wave_y(578)
	, m_water_x(605), m_water_y(597)
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
	if (m_water_remaining <= 0)
	{
		//水の色用配列初期化
		rgba[0] = 1.0f;
		rgba[1] = 1.0f;
		rgba[2] = 1.0f;
		rgba[3] = 1.0f;
	}

	if (Input::KeyPush('C'))
	{
		if (rgba[0] == 2.0f)
		{
			SetColor(2.0f, 0.5f, 0.5f, 1.0f);
		}
		else if (rgba[0] == 0.0f)
		{
			SetColor(0.0f, 1.0f, 0.5f, 1.0f);
		}
		else
		{
			SetColor(1.0f, 1.0f, 1.0f, 1.0f);
		}
	}
}

//ドロー
void CBucketMeter::Draw()
{
	//描画
	Draw::Draw2D(49, m_x, m_y);

	//水表示
	Draw::Draw2D(48, m_water_x, m_water_y, 0.22, -(m_water_remaining-(3- m_water_remaining)*0.27)*0.0535,rgba);

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
	Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x, m_wave_y, 2.1*0.2, 2*0.2, rgba);

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
	Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x, m_wave_y, 2.1*0.2, 2*0.2, rgba);

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
