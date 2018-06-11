//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Tank3.h"
#include "ObjGround.h"
#include "ObjGround3.h"
#include "BucketMeter.h"
#include "Hero.h"
#include "Sprinkler3.h"
extern int g_SceneNumber;
extern bool g_key_flag;

CTank3::CTank3()
	:m_x(40), m_y(250), m_wave_x(11), m_wave_y(250)
	, im_x(33), im_y(130), m_ani_time1(10.0f), m_ani_time2(0.0f)
	, m_water_x(11), m_water_y(384)
	, m_water_remaining2(50)
{
	m_name = TANK3;

	//auto* ground = g;


	//ヒットラインの作成
	m_p_hit_line_tank = Collision::HitLineInsert(this);
	m_p_hit_line_tank->SetPos1(m_x + 110, m_y);
	m_p_hit_line_tank->SetPos2(m_x + 110, m_y + 150);
	m_p_hit_line_tank->SetElement(3);		//属性を3にする
	m_p_hit_line_tank->SetInvisible(false);	//無敵モード無効
}

CTank3::~CTank3()
{

}

void CTank3::Action()
{
	m_water_remaining2;

	CHero* hero = (CHero*)TaskSystem::GetObj(PLAYER);
	//CSPRI* spri = (CSPRI*)TaskSystem::GetObj(SPRI);

	//タンクから水を汲む＆戻す
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_tank->GetHitData()[i] != nullptr)
		{
			//自分の当たり判定の中に主人公の当たり判定があったら
			if (m_p_hit_line_tank->GetHitData()[i]->GetElement() == 0)
			{
				//タンクから水を汲む
				if (Input::KeyPush('X'))
				{
					//バケツメーターオブジェクト取得
					CBucketMeter* bm = (CBucketMeter*)TaskSystem::GetObj(BUCKETMETER);
					//バケツが満タンじゃなかったら
					if (bm->GetWaterRem() < 3.0f) {
						//主人公の向きが左のときだけ汲める
						if (hero->GetDirec() == LEFT)
						{

							if (bm != nullptr) {
								//バケツメーターにセット
								bm->PushX();
							}

							//（バケツ満タン/75フレーム）
							m_water_remaining2 -= 0.02666;
						}
						bm->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
					}
				}
				//水をタンクに戻す
				if (Input::KeyPush('C'))
				{
					//バケツメーターオブジェクト取得
					CBucketMeter* bm = (CBucketMeter*)TaskSystem::GetObj(BUCKETMETER);
					//バケツが空じゃなかったら
					if (bm->GetWaterRem() > 0.0f) {
						//主人公の向きが左のときだけ汲める
						if (hero->GetDirec() == LEFT)
						{
							//		m_water_remaining += m_water_amount;
							//		m_wave_y -= m_wave_amount;

							if (bm != nullptr) {
								//バケツメーターにセット
								bm->PushC();
							}

							//　（バケツ満タン/75フレーム）
							m_water_remaining2 += 0.02666;
						}
					}
				}
				break;
			}
		}
	}
	//波の位置設定
	//満タン位置+タンクの高さ*（満タン-残量）/100
	m_wave_y = 250 + 110 * (100 - m_water_remaining2*2)*0.01;

}

void CTank3::Draw()
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

	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	//水表示
	Draw::Draw2D(48, m_water_x + ground3->GetScroll(), m_water_y, 2.95, -(3.65*m_water_remaining2 *0.02));

	//int g = 36;

	//for (int i = 0; i < m_ani_time1; i++)
	//{
	//	if (i < m_ani_time1)
	//	{
	//		Draw::Draw2D(g, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	//	}
	//}

	//if (g <= 46)
	//{
	//	g = 36;
	//}
	//m_ani_time1 += 10;
	//g++;

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
		Draw::Draw2D(36, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 20)
	{
		Draw::Draw2D(37, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 30)
	{
		Draw::Draw2D(38, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 40)
	{
		Draw::Draw2D(39, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 50)
	{
		Draw::Draw2D(40, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 60)
	{
		Draw::Draw2D(41, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 70)
	{
		Draw::Draw2D(42, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 80)
	{
		Draw::Draw2D(43, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 90)
	{
		Draw::Draw2D(44, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 100)
	{
		Draw::Draw2D(45, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 110)
	{
		Draw::Draw2D(46, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
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
		Draw::Draw2D(25, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 10)
	{
		Draw::Draw2D(26, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 15)
	{
		Draw::Draw2D(27, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 20)
	{
		Draw::Draw2D(28, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 25)
	{
		Draw::Draw2D(29, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 30)
	{
		Draw::Draw2D(30, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 35)
	{
		Draw::Draw2D(31, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 40)
	{
		Draw::Draw2D(32, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 45)
	{
		Draw::Draw2D(33, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 50)
	{
		Draw::Draw2D(34, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 55)
	{
		Draw::Draw2D(35, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	/*else if (m_ani_time > 16)
	{
	Draw::Draw2D(32, m_x8, m_y8);
	}*/
}

//波の増減
void CTank3::SetWaveY(float* wave_y, float wave_amount)
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