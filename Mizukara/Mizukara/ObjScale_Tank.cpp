//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjScale_Tank.h"
#include "ObjScale.h"
#include "ObjGround2.h"
#include "BucketMeter.h"
extern int g_SceneNumber;

const float ObjScale_Tank::m_WaveSize_x = 0.25f;
const float ObjScale_Tank::m_WaveSize_y = 0.4f;

//コンストラクタ
ObjScale_Tank::ObjScale_Tank()
	:m_x(725+72.5), m_y(347), m_x2(845-72.5), m_y2(347), m_wave_x(725+72.5), m_wave_y(375), m_water_x(725+72.5), m_water_y(383),
	m_wave_x2(845-72.5), m_wave_y2(375), m_water_x2(845-72.5), m_water_y2(383), m_angle(0.0f),
	m_angle_x(0.0f), m_angle_y(0.0f), m_angle_x2(0.0f), m_angle_y2(0.0f),
	m_ani_time1(0.0f), m_ani_time2(0.0f), m_water_remaining(0.0f), m_water_remaining2(0.0f)
{
	//ヒットラインの作成(左)
	m_hit_line_ScaleTank = Collision::HitLineInsert(this);
	m_hit_line_ScaleTank->SetPos1(m_x, m_y - 30);
	m_hit_line_ScaleTank->SetPos2(m_x, m_y);
	m_hit_line_ScaleTank->SetElement(5);		//属性を5にする
	m_hit_line_ScaleTank->SetInvisible(false);	//無敵モード無効
												//ヒットラインの作成2(左)
	m_hit_line_ScaleTank2 = Collision::HitLineInsert(this);
	m_hit_line_ScaleTank2->SetPos1(m_x2, m_y2 - 30);
	m_hit_line_ScaleTank2->SetPos2(m_x2, m_y2);
	m_hit_line_ScaleTank2->SetElement(6);		//属性を6にする
	m_hit_line_ScaleTank2->SetInvisible(false);	//無敵モード無効
}

//デストラクタ
ObjScale_Tank::~ObjScale_Tank()
{

}

//アクション
void ObjScale_Tank::Action()
{
	ObjGround2* ground = (ObjGround2*)TaskSystem::GetObj(GROUND2);

	//タンクから水を汲む＆戻す
	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_ScaleTank->GetHitData()[i] != nullptr)
		{
			//自分の当たり判定の中に主人公の当たり判定があったら
			if (m_hit_line_ScaleTank->GetHitData()[i]->GetElement() == 0)
			{
				//タンクから水を汲む
				if (Input::KeyPush('X'))
				{

					//バケツメーターオブジェクト取得
					CBucketMeter* bm = (CBucketMeter*)TaskSystem::GetObj(BUCKETMETER);
					//バケツが満タンじゃなかったら
					if (bm->GetWaterRem() < 3.0f) {
						//残量がなかったら汲めない
						if (m_water_remaining > 0.0f) {
							//足場オブジェクト取得
							ObjScale* sc = (ObjScale*)TaskSystem::GetObj(SCALE);
							m_angle += 0.1f;
							sc->AddAngle(0.1f);

							if (bm != nullptr) {
								//バケツメーターにセット
								bm->PushX();
							}

							//　　　　　　　　　（バケツ満タン/75フレーム）
							m_water_remaining -= 0.02666;
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
						//満タンだったら入れれない
						if (m_water_remaining < 6.0f) {
							//足場オブジェクト取得
							ObjScale* sc = (ObjScale*)TaskSystem::GetObj(SCALE);
							//地面に当たってなかったら
				//			if (sc->GetX() <= 1972 || mb->GetY() <= 283.0f) {
							m_angle += -0.1f;
							sc->AddAngle(-0.1f);

								if (bm != nullptr) {
									//バケツメーターにセット
									bm->PushC();
								}

								//（バケツ満タン/75フレーム）
								m_water_remaining += 0.02666;
				//			}
						}
					}
				}
				break;
			}
		}
		if (m_hit_line_ScaleTank2->GetHitData()[i] != nullptr)
		{
			//自分の当たり判定の中に主人公の当たり判定があったら
			if (m_hit_line_ScaleTank2->GetHitData()[i]->GetElement() == 0)
			{
				//タンクから水を汲む
				if (Input::KeyPush('X'))
				{

					//バケツメーターオブジェクト取得
					CBucketMeter* bm = (CBucketMeter*)TaskSystem::GetObj(BUCKETMETER);
					//バケツが満タンじゃなかったら
					if (bm->GetWaterRem() < 3.0f) {
						//残量がなかったら汲めない
						if (m_water_remaining2 > 0.0f) {
							//足場オブジェクト取得
							ObjScale* sc = (ObjScale*)TaskSystem::GetObj(SCALE);
							m_angle += -0.1f;
							sc->AddAngle(-0.1f);

							if (bm != nullptr) {
								//バケツメーターにセット
								bm->PushX();
							}

							//　　　　　　　　　（バケツ満タン/75フレーム）
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
						//満タンだったら入れれない
						if (m_water_remaining2 < 6.0f) {
							//足場オブジェクト取得
							ObjScale* sc = (ObjScale*)TaskSystem::GetObj(SCALE);
				//			if (sc->GetX() < 1972 || mb->GetY() <= 283.0f) {
				//				if (sc->GetY() < 365.0f) {

							m_angle += 0.1f;
							sc->AddAngle(0.1f);

									if (bm != nullptr) {
										//バケツメーターにセット
										bm->PushC();
									}

									//（バケツ満タン/75フレーム）
									m_water_remaining2 += 0.02666;
				//				}
				//			}
						}
					}
				}
				break;
			}
		}

	}

	//傾きによる座標変更を計算
	m_angle_x = 72.5*sin(3.14 / 180 * (fmod((270.0f + 5.12316553f + m_angle), 360)));
	m_angle_y = 72.5*(-cos(3.14 / 180 * ((270.0f + 5.12316553f + m_angle))));
	m_angle_x2 = 72.5 * sin(3.14 / 180 * (fmod((90.0f - 5.12316553f + m_angle), 360)));
	m_angle_y2 = 72.5 * (-cos(3.14 / 180 * ((90.0f - 5.12316553f + m_angle))));

	//当たり判定位置の更新
	m_hit_line_ScaleTank->SetPos1(m_x + ground->GetScroll()+ m_angle_x, m_y - 30 + m_angle_y);
	m_hit_line_ScaleTank->SetPos2(m_x + ground->GetScroll()+ m_angle_x, m_y + m_angle_y);

	m_hit_line_ScaleTank2->SetPos1(m_x2-50 + ground->GetScroll() + m_angle_x2, m_y2 - 30 + m_angle_y2);
	m_hit_line_ScaleTank2->SetPos2(m_x2-50 + ground->GetScroll() + m_angle_x2, m_y2 + m_angle_y2);
}

//ドロー
void ObjScale_Tank::Draw()
{
	ObjGround2* ground = (ObjGround2*)TaskSystem::GetObj(GROUND2);

	//WTMに近づいたらアイコンを出す
	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_ScaleTank->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_ScaleTank->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(70, m_x - 20 + ground->GetScroll() + m_angle_x, m_y - 150 + m_angle_y);
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_ScaleTank2->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_ScaleTank2->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(70, m_x2-10 + ground->GetScroll() + m_angle_x2, m_y2 - 150 + m_angle_y2);
			}
		}
	}

	//水表示
	Draw::Draw2D(48, m_water_x + ground->GetScroll() + m_angle_x, m_water_y + m_angle_y, 0.74, -(0.64 * m_water_remaining * 1 / 6));
	Draw::Draw2D(48, m_water_x2 + ground->GetScroll() + m_angle_x2, m_water_y + m_angle_y2, 0.74, -(0.64*m_water_remaining2 * 1 / 6));

	//波アニメーション(後ろ)
	if (m_ani_time1 >= 109)
	{
		m_ani_time1 = 0;
	}
	else
	{
		m_ani_time1++;
	}

	//波アニメーション(後ろ)
	Draw::Draw2D(36+(m_ani_time1/10), m_wave_x + ground->GetScroll() + m_angle_x,(m_wave_y - m_water_remaining * 2) + m_angle_y, m_WaveSize_x, m_WaveSize_y);

	//波アニメーション2(後ろ)
	Draw::Draw2D(36+(m_ani_time1/10), m_wave_x2 + ground->GetScroll() + m_angle_x2, (m_wave_y - m_water_remaining2 * 2) + m_angle_y2, m_WaveSize_x, m_WaveSize_y);

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
	Draw::Draw2D(25+(m_ani_time2/5), m_wave_x + ground->GetScroll() + m_angle_x, (m_wave_y - m_water_remaining * 2) + m_angle_y, m_WaveSize_x, m_WaveSize_y);

	//波アニメーション2(前)
	Draw::Draw2D(25+(m_ani_time2/5), m_wave_x2 + ground->GetScroll() + m_angle_x2, (m_wave_y - m_water_remaining2) + m_angle_y2, m_WaveSize_x, m_WaveSize_y);

	Draw::Draw2D(56, m_x + ground->GetScroll() + m_angle_x, m_y + m_angle_y, 1, 1);
	Draw::Draw2D(56, m_x2 + ground->GetScroll() + m_angle_x2, m_y2 + m_angle_y2, 1, 1);
}
