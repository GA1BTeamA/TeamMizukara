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
CWTM3::CWTM3(float x, float y,int color)
	:m_x(x), m_y(y), m_wave_x(x+6), m_wave_y(y+36), m_ani_time1(0.0f), m_ani_time2(0.0f)
	, im_x(x), im_y(y-180), m_water_x(x+3), m_water_y(y+136), m_water_remaining(1.4)
	,m_gx(x),m_gy(y+65)
{
	if (color == 74)
	{
		//水の色用配列初期化(赤)
		rgba[0] = 2.0f;
		rgba[1] = 0.5f;
		rgba[2] = 0.5f;
		rgba[3] = 1.0f;
	}
	else if(color==82)
	{
		//水の色用配列初期化(緑)
		rgba[0] = 0.0f;
		rgba[1] = 1.0f;
		rgba[2] = 0.5f;
		rgba[3] = 1.0f;
	}
	else if(color == 0)
	{
		//水の色用配列初期化
		rgba[0] = 1.0f;
		rgba[1] = 1.0f;
		rgba[2] = 1.0f;
		rgba[3] = 1.0f;
	}

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
	CTank3* tank = (CTank3*)TaskSystem::GetObj(TANK3);
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
							else if (rgba[0] == 0.0f)
							{
								bm->SetColor(0.0f, 1.0f, 0.5f, 1.0f);
							}
							else
							{
								bm->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
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

							////バケツメーターの水の色変更
							//if (rgba[0] == 2.0f)
							//{
							//	bm->SetColor(2.0f, 0.5f, 0.5f, 1.0f);
							//}
							//else if (rgba[0] == 0.0f)
							//{
							//	bm->SetColor(0.0f, 1.0f, 0.5f, 1.0f);
							//}
							//else
							//{
							//	bm->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
							//}
						}
					}
				}
				break;
			}
			//else
			//{
			//	bm->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
			//}
		}
	}

	m_wave_y = m_y+81+42 * (100 - tank->GetWater_Remaining()*2)*0.01;

	ObjGround3* ground = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	//当たり判定位置の更新
	m_p_hit_line_wtm3->SetPos1(m_x + ground->GetScroll(), m_y);
	m_p_hit_line_wtm3->SetPos2(m_x + ground->GetScroll(), m_y + 100);
}

void CWTM3::Draw()
{
	ObjGround3* ground = (ObjGround3*)TaskSystem::GetObj(GROUND3);
	CTank3* tank = (CTank3*)TaskSystem::GetObj(TANK3);

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
	Draw::Draw2D(48, m_water_x + ground->GetScroll(), m_water_y, 0.059, -(tank->GetWater_Remaining()*0.00138),rgba);

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
	Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);

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
	Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y, rgba);

	if (rgba[0] == 2.0f)
	{
		//赤のWTM表示
		Draw::Draw2D(74, m_gx + ground->GetScroll(), m_gy);
	}
	else if(rgba[0]==0.0f)
	{
		//緑のWTM表示
		Draw::Draw2D(82, m_gx + ground->GetScroll(), m_gy);
	}
	else if(rgba[0]==1.0f)
	{
		;
	}

	//Draw::Draw2D(21, a, m_y);
}