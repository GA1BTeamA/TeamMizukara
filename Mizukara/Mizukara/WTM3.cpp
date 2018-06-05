//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "WTM3.h"
#include "ObjGround3.h"
#include "Hero.h"
#include "Tank3.h"
#include "BucketMeter.h"

extern int g_SceneNumber;
extern bool g_key_flag;

const float CWTM3::m_WaveSize_x = 0.5f;
const float CWTM3::m_WaveSize_y = 0.6f;

const float CWTM3::m_water_amount = 0.01f*0.04f;
const float CWTM3::m_wave_amount = 0.3f*0.04f;


//コンストラクタ
CWTM3::CWTM3()
	:m_x(250), m_y(234), m_wave_x(236), m_wave_y(350), m_ani_time1(0.0f), m_ani_time2(0.0f)
	, im_x(230), im_y(139), m_water_x(235), m_water_y(370), m_water_remaining(1.4)
{
	//for (int i = 0; i < 4; i++)
	//{
	//	rgba[i] = 1;
	//}

	//水の色用配列初期化
	rgba[0] = 2.0f;
	rgba[1] = 0.5f;
	rgba[2] = 0.5f;
	rgba[3] = 1.0f;

	//ヒットラインの作成(左)
	m_p_hit_line_wtm3 = Collision::HitLineInsert(this);
	m_p_hit_line_wtm3->SetPos1(m_x, m_y);
	m_p_hit_line_wtm3->SetPos2(m_x, m_y + 100);
	m_p_hit_line_wtm3->SetElement(2);		//属性を2にする
	m_p_hit_line_wtm3->SetInvisible(false);	//無敵モード無効
}

//デストラクタ
CWTM3::~CWTM3()
{

}

//アクション
void CWTM3::Action()
{
	CHero* hero = (CHero*)TaskSystem::GetObj(PLAYER);
	CTank3* tank = (CTank3*)TaskSystem::GetObj(TANK);
	CBucketMeter* bm = (CBucketMeter*)TaskSystem::GetObj(BUCKETMETER);

	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_wtm3->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_wtm3->GetHitData()[i]->GetElement() == 0)
			{
				//タンクから水を汲む
				if (Input::KeyPush('X'))
				{
					if (bm != nullptr) {
						if (bm->GetWaterRem() < 3.0f) {
							bm->PushX();
							tank->SetWater_Remaining(-0.02666);

							//バケツメーターの水の色変更
							if (rgba[0] == 2.0f)
							{
								bm->SetColor(2.0f, 0.5f, 0.5f, 1.0f);
							}
						}
					}
				}

				//水をタンクに戻す
				if (Input::KeyPush('C'))
				{
					//CBucketMeter* bm = (CBucketMeter*)TaskSystem::GetObj(BUCKETMETER);
					if (bm != nullptr) {
						if (bm->GetWaterRem() > 0.0f) {
							bm->PushC();
							tank->SetWater_Remaining(0.02666);

							//バケツメーターの水の色変更
							if (rgba[0] == 2.0f)
							{
								bm->SetColor(2.0f, 0.5f, 0.5f, 1.0f);
							}
						}
					}
				}
				break;
			}
			else
			{
				bm->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
			}
		}
	}

	m_wave_y = 315+42 * (100 - tank->GetWater_Remaining())*0.01;

	ObjGround3* ground = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	//当たり判定位置の更新
	m_p_hit_line_wtm3->SetPos1(m_x + ground->GetScroll(), m_y);
	m_p_hit_line_wtm3->SetPos2(m_x + ground->GetScroll(), m_y + 100);
}

void CWTM3::Draw()
{
	ObjGround3* ground = (ObjGround3*)TaskSystem::GetObj(GROUND3);
	CTank3* tank = (CTank3*)TaskSystem::GetObj(TANK);

	//WTMに近づいたらアイコンを出す
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_wtm3->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_wtm3->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(21, im_x + ground->GetScroll(), im_y);
			}
		}
	}

	//水表示
	Draw::Draw2D(48, m_water_x + ground->GetScroll(), m_water_y, 1.6, -(1.4*tank->GetWater_Remaining()*0.01),rgba);

	//波アニメーション(後ろ)
	if (m_ani_time1 >= 109)
	{
		m_ani_time1 = 0;
	}
	else
	{
		m_ani_time1++;
	}

	float a = 103.65;
	//float b = *tank->GetWaveY() - a + tank->GetWater_Remaining();

	//波アニメーション
	if (m_ani_time1 < 10)
	{
		Draw::Draw2D(36, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y,rgba);
	}
	else if (m_ani_time1 < 20)
	{
		Draw::Draw2D(37, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else if (m_ani_time1 < 30)
	{
		Draw::Draw2D(38, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else if (m_ani_time1 < 40)
	{
		Draw::Draw2D(39, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else if (m_ani_time1 < 50)
	{
		Draw::Draw2D(40, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else if (m_ani_time1 < 60)
	{
		Draw::Draw2D(41, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else if (m_ani_time1 < 70)
	{
		Draw::Draw2D(42, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else if (m_ani_time1 < 80)
	{
		Draw::Draw2D(43, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else if (m_ani_time1 < 90)
	{
		Draw::Draw2D(44, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else if (m_ani_time1 < 100)
	{
		Draw::Draw2D(45, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else if (m_ani_time1 < 110)
	{
		Draw::Draw2D(46, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
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
		Draw::Draw2D(25, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else if (m_ani_time2 < 10)
	{
		Draw::Draw2D(26, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else if (m_ani_time2 < 15)
	{
		Draw::Draw2D(27, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else if (m_ani_time2 < 20)
	{
		Draw::Draw2D(28, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else if (m_ani_time2 < 25)
	{
		Draw::Draw2D(29, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else if (m_ani_time2 < 30)
	{
		Draw::Draw2D(30, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else if (m_ani_time2 < 35)
	{
		Draw::Draw2D(31, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else if (m_ani_time2 < 40)
	{
		Draw::Draw2D(32, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else if (m_ani_time2 < 45)
	{
		Draw::Draw2D(33, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else if (m_ani_time2 < 50)
	{
		Draw::Draw2D(34, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else if (m_ani_time2 < 55)
	{
		Draw::Draw2D(35, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);
	}

	//Draw::Draw2D(21, a, m_y);
}