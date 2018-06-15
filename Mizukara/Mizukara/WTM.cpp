//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "WTM.h"
#include "ObjGround.h"
#include "Hero.h"
#include "Tank.h"
#include "BucketMeter.h"
extern int g_SceneNumber;
extern bool g_key_flag;

//波サイズ初期化
const float CWTM::m_WaveSize_x = 0.5f;
const float CWTM::m_WaveSize_y = 0.6f;

const float CWTM::m_water_amount = 0.01f*0.04f;
const float CWTM::m_wave_amount = 0.3f*0.04f;

CWTM::CWTM(float x,float y)
	:m_x(x), m_y(y), m_wave_x(x+4), m_wave_y(y-85),m_ani_time1(0.0f),m_ani_time2(0.0f)
	,im_x(x-20), im_y(y-204), m_water_x(x), m_water_y(y-30), m_water_remaining(1.4)
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
					CBucketMeter* bm = (CBucketMeter*)TaskSystem::GetObj(BUCKETMETER);
					if (bm != nullptr) {
						if (bm->GetWaterRem() < 3.0f) {
							bm->PushX();
							tank->SetWater_Remaining(-0.02666);
						}
					}
				}

				//水をタンクに戻す
				if (Input::KeyPush('C'))
				{
					CBucketMeter* bm = (CBucketMeter*)TaskSystem::GetObj(BUCKETMETER);
					if (bm != nullptr) {
						if (bm->GetWaterRem() > 0.0f) {
							bm->PushC();
							tank->SetWater_Remaining(0.02666);
						}
					}
				}
				break;
			}
		}
	}

	//波の位置更新
	m_wave_y = m_y-85 + 42 * (100 - tank->GetWater_Remaining()*2)*0.01;

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

	//波アニメーション(後ろ)
	if (m_ani_time1 >= 109)
	{
		m_ani_time1 = 0;
	}
	else
	{
		m_ani_time1++;
	}
	//波アニメーション描画(後ろ)
	Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x*0.2, m_WaveSize_y*0.2);

	//波アニメーション(前)
	if (m_ani_time2 >= 54)
	{
		m_ani_time2 = 0;
	}
	else
	{
		m_ani_time2++;
	}
	//波アニメーション描画(前)
	Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x*0.2, m_WaveSize_y*0.2);

	//水表示
	Draw::Draw2D(48, m_water_x + ground->GetScroll(), m_water_y, 0.059, -(/*2.7**/tank->GetWater_Remaining()*0.00139));
}