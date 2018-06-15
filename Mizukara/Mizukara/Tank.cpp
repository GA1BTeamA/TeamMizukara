//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Tank.h"
#include "ObjGround.h"
//#include "ObjGround2.h"
#include "BucketMeter.h"
#include "Hero.h"
#include "Sprinkler.h"
extern int g_SceneNumber;
extern bool g_key_flag;

const float CTank::m_WaveSize_x = 0.2f;
const float CTank::m_WaveSize_y = 0.2f;

CTank::CTank()
	:m_x(40), m_y(250), m_wave_x(11), m_wave_y(249.3)
	,im_x(33), im_y(130),m_ani_time1(0.0f),m_ani_time2(0.0f)
	, m_water_x(11), m_water_y(387)
	, m_water_remaining2(50)
{
	m_name = TANK;

	//auto* ground = g;


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

							//　　　　　　　　　（バケツ満タン/75フレーム）
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
	m_wave_y = 249.3 + 110 * (100 - m_water_remaining2*2)*0.00981;

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
	Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);

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
	Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);

	//水表示
	Draw::Draw2D(48, m_water_x + ground->GetScroll(), m_water_y - 8,/*2.95*/0.108, -(/*3.65*/0.18*m_water_remaining2 *0.025));
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