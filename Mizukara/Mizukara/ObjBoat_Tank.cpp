//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjBoat_Tank.h"
#include "ObjBoat.h"
#include "ObjGround2.h"
#include "BucketMeter.h"
#include "Hero.h"
//#include "Tank.h"
extern int g_SceneNumber;

const float ObjBoat_Tank::m_WaveSize_x = 0.18f*0.2f;
const float ObjBoat_Tank::m_WaveSize_x2 = 3.23f*0.2f;
const float ObjBoat_Tank::m_WaterSize_x = 0.0183f;
//const float ObjBoat_Tank::m_WaterSize_y = 0.1f;
const float ObjBoat_Tank::m_WaterSize_x2 = 0.344f;
const float ObjBoat_Tank::m_WaterSize_y2 = 0.182f;

ObjBoat_Tank::ObjBoat_Tank()
	:m_x(276), m_y(400), m_gx(275), m_gy(330), m_wave_x(293), m_wave_y(356),m_wave_x2(275),m_wave_y2(400), m_ani_time_x(0.0f),m_move_x(0.0f),
	m_ani_time1(0.0f), m_ani_time2(0.0f), m_ani_time3(0.0f), m_WaveSize_y(0.5f*0.2f),m_WaterSize_y(0.69f)
	, m_water_x(292),m_water_x2(275),m_water_y2(421), m_water_y(356), m_moveY(162),
	m_RopeSizeBucket(0.3f), m_water_remaining(0.0f)
	, m_bucket_remaining(0.4f), m_BoatAni(0),m_scroll(0.0f)
{
	m_name = BOAT_TANK;
	//ヒットラインの作成(左)
	m_hit_line_BoatTank[0] = Collision::HitLineInsert(this);
	m_hit_line_BoatTank[0]->SetPos1(m_x+70, m_y);
	m_hit_line_BoatTank[0]->SetPos2(m_x+70, m_y + 100);
	m_hit_line_BoatTank[0]->SetElement(2);		//属性を2にする
	m_hit_line_BoatTank[0]->SetInvisible(false);	//無敵モード無効

	//ボートのタンクヒットライン
	/*m_hit_line_BoatTank[1] = Collision::HitLineInsert(this);
	m_hit_line_BoatTank[1]->SetPos1(m_x+113, m_y);
	m_hit_line_BoatTank[1]->SetPos2(m_x+113, m_y + 100);
	m_hit_line_BoatTank[1]->SetElement(3);		//属性を2にする
	m_hit_line_BoatTank[1]->SetInvisible(false);	//無敵モード無効

	//ボートのタンクヒットライン						
	m_hit_line_BoatTank[2] = Collision::HitLineInsert(this);
	m_hit_line_BoatTank[2]->SetPos1(m_x, m_y);
	m_hit_line_BoatTank[2]->SetPos2(m_x, m_y + 100);
	m_hit_line_BoatTank[2]->SetElement(3);		//属性を2にする
	m_hit_line_BoatTank[2]->SetInvisible(false);	//無敵モード無効*/

	//ボートの左側のヒットライン
	m_hit_line_Boat[0] = Collision::HitLineInsert(this);
	m_hit_line_Boat[0]->Set4direc(HIT_LEFT);
	m_hit_line_Boat[0]->SetPos1(m_scroll + m_ani_time_x + 300, m_y + 20);  //左
	m_hit_line_Boat[0]->SetPos2(m_scroll + m_ani_time_x + 300, m_y - 300);
	m_hit_line_Boat[0]->SetElement(1);		//属性を2にする
	m_hit_line_Boat[0]->SetInvisible(true);	//無敵モード無効
	m_hit_line_Boat[0]->SetAngle();


	//ボートの右側のヒットライン
	m_hit_line_Boat[1] = Collision::HitLineInsert(this);
	m_hit_line_Boat[1]->Set4direc(HIT_RIGHT);
	m_hit_line_Boat[1]->SetPos1(m_scroll + m_ani_time_x + 400, m_y + 20);  //右
	m_hit_line_Boat[1]->SetPos2(m_scroll + m_ani_time_x + 400, m_y - 100);
	m_hit_line_Boat[1]->SetElement(1);		//属性を2にする
	m_hit_line_Boat[1]->SetInvisible(false);	//無敵モード無効
	m_hit_line_Boat[1]->SetAngle();

}

ObjBoat_Tank::~ObjBoat_Tank()
{

}

void ObjBoat_Tank::Action()
{
	ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);

	if (m_BoatAni > 8) m_BoatAni = 0;

	//タンクから水を汲む＆戻す
	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_BoatTank[0]->GetHitData()[i] != nullptr)
		{
			//ボートの当たり判定の中に主人公の当たり判定があったら
			if (m_hit_line_BoatTank[0]->GetHitData()[i]->GetElement() == 0)
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
							ObjBoat* bt = (ObjBoat*)TaskSystem::GetObj(BOAT);

							//m_gy -= 0.5f;  //バケツ移動
							m_RopeSizeBucket -= 0.0015f;  //バケツ側ロープ長さ変更

							//bt->AddY(0.5f);  //足場ブロック移動
							bt->SetRopeSizeScaffold(0.002f);  //足場ロープ長さ変更

							//bt->SetY(0.5f);  //足場当たり判定移動

							m_bucket_remaining -= 0.006f;  //水減らす
							//波の位置
							if (m_wave_y < 248)m_wave_y += 0.26f;
							else if(m_wave_y > 356)m_wave_y += 0;
							else m_wave_y += 0.13f;

							//m_water_y += 0.03f;  //水の位置
												  //m_WaveSize_y -= 0.01f;
												  //m_RopeSizeBoard -= 0.0006f;
												  //m_RopeSizeBucket += 0.0006f;

							if (bm != nullptr) {
								//バケツメーターにセット
								bm->PushX();
							}

							//（バケツ満タン/75フレーム）
							m_water_remaining -= 0.02666;

							m_BoatAni++;

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
						if (m_water_remaining < 4.0f) {
							//足場オブジェクト取得
							ObjBoat* bt = (ObjBoat*)TaskSystem::GetObj(BOAT);
							//m_moveY += 0.2f;
							//db->AddY(-0.2f);
							//m_gy += 0.5f;  //バケツ移動
							//m_RopeSizeBucket += 0.0015f;  //バケツ側ロープ長さ変更

							//bt->AddY(-0.5f);  //足場ブロック移動
							//bt->SetRopeSizeScaffold(-0.002f);  //足場ロープ長さ変更

						//	db->SetY(-0.5f);  //足場当たり判定移動

							m_bucket_remaining += 0.006f;  //水減らす
														   //波の位置
							if (m_wave_y < 248)m_wave_y -= 0.26f;
							else m_wave_y -= 0.13f;
							//m_water_y -= 0.03f;  //水の位置
												  //m_WaveSize_y += 0.01f;
												  ////m_RopeSizeBoard += 0.0006f;
												  //m_RopeSizeBucket -= 0.0006f;

							if (bm != nullptr) {
								//バケツメーターにセット
								bm->PushC();
							}

							//（バケツ満タン/75フレーム）
							m_water_remaining += 0.02666;

							m_BoatAni++;

						}
					}
				}
				break;
			}
		}
	}

	//if(m_wave_y>250)
	//if (m_wave_y > 356)
		m_WaveSize_y = m_water_remaining *0.02f;
	if (m_WaveSize_y > 0.6f)m_WaveSize_y = 0.6f;
	m_WaterSize_y = -(m_water_remaining *0.0045f);
	if (m_WaterSize_y > 0.6f)m_WaterSize_y = 0.6f;

	//当たり判定位置の更新
	m_hit_line_BoatTank[0]->SetPos1(m_x + ground2->GetScroll()+70, m_y);
	m_hit_line_BoatTank[0]->SetPos2(m_x + ground2->GetScroll()+70, m_y + 100);
	/*m_hit_line_BoatTank[1]->SetPos1(m_x + 113 + ground2->GetScroll(), m_y);
	m_hit_line_BoatTank[1]->SetPos2(m_x + 113 + ground2->GetScroll(), m_y + 100);*/

	//ボートの左右の当たり判定位置の更新
	m_hit_line_Boat[0]->SetPos1(ground2->GetScroll() + m_ani_time_x + 300, m_y + 20);  //左
	m_hit_line_Boat[0]->SetPos2(ground2->GetScroll() + m_ani_time_x + 300, m_y - 300);
	m_hit_line_Boat[1]->SetPos1(ground2->GetScroll() + m_ani_time_x + 400, m_y + 20);  //右
	m_hit_line_Boat[1]->SetPos2(ground2->GetScroll() + m_ani_time_x + 400, m_y - 100);
}

void ObjBoat_Tank::Draw()
{
	ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);
	//CTank* tank = (CTank*)TaskSystem::GetObj(TANK);
	CHero* hero = (CHero*)TaskSystem::GetObj(PLAYER);

	//Draw::Draw2D(0, m_gx + m_move_x + ground2->GetScroll() + 20, m_gy - 30, 1, 1);
	
	/*for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_BoatTank[0]->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_BoatTank[0]->GetHitData()[i]->GetElement() == 0)
			{*/
				if (m_water_remaining >= 4.0f)
				{
					m_hit_line_Boat[0]->SetInvisible(false);//ボート左の当たり判定
					m_ani_time_x++;
					if (m_ani_time_x > 1 && m_ani_time_x <= 160)
					{
						Draw::Draw2D(0, m_gx + m_ani_time_x + ground2->GetScroll() + 50, m_gy - 30, 1, 1);
						if (m_wave_y < 248)m_wave_y += 0.26f;
						else if (m_wave_y > 356)m_wave_y += 0;
						else m_wave_y += 0.08f;
					}
					else if (m_ani_time_x >= 161)
					{
						Draw::Draw2D(0, m_gx + 161 + ground2->GetScroll() + 50, m_gy - 30, 1, 1);
						m_water_remaining = 0.0f;
						hero->SetHeroDeleteFlag();
						hero->SetHeroPositionFlag();
						hero->SetX(455);
						m_hit_line_Boat[1]->SetInvisible(true);//ボート右の当たり判定
					}
				}
		/*	}
		}
	}*/

	//ギミックに近づいたらアイコンを出す
	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_BoatTank[0]->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_BoatTank[0]->GetHitData()[i]->GetElement() == 0)
			{
				if (m_ani_time_x <= 0.0f )
				{
					Draw::Draw2D(70, m_x - 15 + ground2->GetScroll(), m_y - 150);
				}
			}
		}
	}

	//水表示(ボートタンク)
	Draw::Draw2D(48, m_water_x + ground2->GetScroll() + m_ani_time_x, m_water_y, m_WaterSize_x, m_WaterSize_y);
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
	Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x + ground2->GetScroll() + m_ani_time_x, m_wave_y, m_WaveSize_x, m_WaveSize_y);

	//波アニメーション(前)
	if (m_ani_time2 >= 111)
	{
		m_ani_time2 = 0;
	}
	else
	{
		m_ani_time2++;
	}
	//波アニメーション描画(後ろ)
	Draw::Draw2D(25 + (m_ani_time2 / 10), m_wave_x + ground2->GetScroll() + m_ani_time_x, m_wave_y, m_WaveSize_x, m_WaveSize_y);

	//ボート描画
	Draw::Draw2D(73, m_gx + m_ani_time_x + ground2->GetScroll(), m_gy, 1, 1);
	
	//水描画(海)
	Draw::Draw2D(48, m_water_x2 + ground2->GetScroll(), m_water_y2, m_WaterSize_x2, m_WaterSize_y2);
	//波アニメーション2(後ろ)
	Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x2 + ground2->GetScroll(), m_wave_y2, m_WaveSize_x2, 0.2f);

	//波アニメーション(前)
	if (m_ani_time2 >= 101)
	{
		m_ani_time2 = 0;
	}
	else
	{
		m_ani_time2++;
	}
	//波アニメーション2(前)
	Draw::Draw2D(25 + (m_ani_time2 / 10), m_wave_x2 + ground2->GetScroll(), m_wave_y2, m_WaveSize_x2, 0.2f);
}