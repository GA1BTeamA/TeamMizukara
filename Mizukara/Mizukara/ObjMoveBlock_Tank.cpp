//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjMoveBlock_Tank.h"
#include "ObjMoveBlock.h"
#include "ObjGround.h"
#include "BucketMeter.h"
extern int g_SceneNumber;

const float ObjMoveBlock_Tank::m_WaveSize_x = 0.25f*0.2;

//コンストラクタ
ObjMoveBlock_Tank::ObjMoveBlock_Tank()
	:m_x(1600), m_y(250),m_x2(1690),m_y2(250),m_wave_x(1620),m_wave_y(384),m_water_x(1620),m_water_y(394),
	 m_ani_time1(0.0f),m_ani_time2(0.0f) ,m_water_remaining(0.0f), m_water_remaining2(0.0f)
{
	//ヒットラインの作成(左)
	m_hit_line_MoBlTank = Collision::HitLineInsert(this);
	m_hit_line_MoBlTank->SetPos1(m_x, m_y);
	m_hit_line_MoBlTank->SetPos2(m_x, m_y + 100);
	m_hit_line_MoBlTank->SetElement(5);		//属性を5にする
	m_hit_line_MoBlTank->SetInvisible(false);	//無敵モード無効
	//ヒットラインの作成2(左)
	m_hit_line_MoBlTank2 = Collision::HitLineInsert(this);
	m_hit_line_MoBlTank2->SetPos1(m_x2, m_y2);
	m_hit_line_MoBlTank2->SetPos2(m_x2, m_y2 + 100);
	m_hit_line_MoBlTank2->SetElement(6);		//属性を6にする
	m_hit_line_MoBlTank2->SetInvisible(false);	//無敵モード無効
}

//デストラクタ
ObjMoveBlock_Tank::~ObjMoveBlock_Tank()
{

}

//アクション
void ObjMoveBlock_Tank::Action()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	//タンクから水を汲む＆戻す
	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_MoBlTank->GetHitData()[i] != nullptr)
		{
			//自分の当たり判定の中に主人公の当たり判定があったら
			if (m_hit_line_MoBlTank->GetHitData()[i]->GetElement() == 0)
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
							ObjMoveBlock* mb = (ObjMoveBlock*)TaskSystem::GetObj(MOVEBLOCK);
						//	m_moveX -= 0.2f;
							mb->AddX(-1.0f);

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
							ObjMoveBlock* mb = (ObjMoveBlock*)TaskSystem::GetObj(MOVEBLOCK);
							//地面に当たってなかったら
							if (mb->GetX() <= 1972 || mb->GetY() <= 283.0f ) {
								//		m_moveY += 0.2f;
								mb->AddX(1.0f);

								if (bm != nullptr) {
									//バケツメーターにセット
									bm->PushC();
								}

								//（バケツ満タン/75フレーム）
								m_water_remaining += 0.02666;
							}
						}
					}
				}
				break;
			}
		}
		if (m_hit_line_MoBlTank2->GetHitData()[i] != nullptr)
		{
			//自分の当たり判定の中に主人公の当たり判定があったら
			if (m_hit_line_MoBlTank2->GetHitData()[i]->GetElement() == 0)
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
							ObjMoveBlock* mb = (ObjMoveBlock*)TaskSystem::GetObj(MOVEBLOCK);
							//m_moveX -= 0.2f;
							mb->AddY(-1.0f);

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
							ObjMoveBlock* mb = (ObjMoveBlock*)TaskSystem::GetObj(MOVEBLOCK);
							if (mb->GetX() < 1972 || mb->GetY() <= 283.0f) {
								if (mb->GetY() < 365.0f) {

									//	m_moveY += 0.2f;
									mb->AddY(1.0f);

									if (bm != nullptr) {
										//バケツメーターにセット
										bm->PushC();
									}

									//（バケツ満タン/75フレーム）
									m_water_remaining2 += 0.02666;
								}
							}
						}
					}
				}
				break;
			}
		}

	}

	m_WaveSize_y = m_water_remaining *0.04f;
	if (m_WaveSize_y > 0.08f)m_WaveSize_y = 0.08f;
	m_WaveSize_y2 = m_water_remaining2 *0.04f;
	if (m_WaveSize_y2 > 0.08f)m_WaveSize_y2 = 0.08f;

	//当たり判定位置の更新
	m_hit_line_MoBlTank->SetPos1(m_x + ground->GetScroll(), m_y);
	m_hit_line_MoBlTank->SetPos2(m_x + ground->GetScroll(), m_y + 100);

	m_hit_line_MoBlTank2->SetPos1(m_x2 + ground->GetScroll(), m_y2);
	m_hit_line_MoBlTank2->SetPos2(m_x2 + ground->GetScroll(), m_y2 + 100);
}

//ドロー
void ObjMoveBlock_Tank::Draw()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	//WTMに近づいたらアイコンを出す
	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_MoBlTank->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_MoBlTank->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(70, m_x - 10 + ground->GetScroll(), m_y - 15);
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_MoBlTank2->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_MoBlTank2->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(70, m_x + 40 + ground->GetScroll(), m_y - 15);
			}
		}
	}

	//水表示
	Draw::Draw2D(48, m_water_x + ground->GetScroll(), m_water_y, 0.025, -(0.027 * m_water_remaining *1/6));
	Draw::Draw2D(48, m_water_x + 48 + ground->GetScroll(), m_water_y, 0.025, -(0.027*m_water_remaining2 *1/6));

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
	Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x + ground->GetScroll(), m_wave_y- m_water_remaining * 2, m_WaveSize_x, m_WaveSize_y);

	//波アニメーション2(後ろ)
	Draw::Draw2D(36 + (m_ani_time2 / 10), m_wave_x + 48 + ground->GetScroll(), m_wave_y - m_water_remaining2 * 2, m_WaveSize_x, m_WaveSize_y2);

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
	Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x + ground->GetScroll(), m_wave_y - m_water_remaining * 2, m_WaveSize_x, m_WaveSize_y);

	//波アニメーション2(前)
	Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x + 48 + ground->GetScroll(), m_wave_y - m_water_remaining2 * 2, m_WaveSize_x, m_WaveSize_y2);


	Draw::Draw2D(60, 1620 + ground->GetScroll(), 334, 1, 1);
}
