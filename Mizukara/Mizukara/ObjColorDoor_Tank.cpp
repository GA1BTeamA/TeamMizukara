//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjColorDoor_Tank.h"
#include "ObjGround3.h"
#include "BucketMeter.h"
#include "ObjColorDoor.h"

const float ObjColorDoor_Tank::m_WaveSize_x = 0.32f;


//コンストラクタ
ObjColorDoor_Tank::ObjColorDoor_Tank()
	:m_x(230), m_y(299), m_gx(230), m_gy(299)
	, m_moveY(350), m_wave_x(347), m_wave_y(380)
	, m_water_x(347), m_water_y(388), m_water_remaining(0.0f)
	, m_WaveSize_y(0.4f), m_WaterSize_y(0.0f)
	, m_ani_time1(0.0f), m_ani_time2(0.0f)
	, m_x2(230), m_y2(299)
{

	//水の色用配列初期化
	rgba[0] = 2.0f;
	rgba[1] = 0.5f;
	rgba[2] = 0.5f;
	rgba[3] = 1.0f;

	//ヒットラインの作成
	m_hit_line_ColorDoorTank[0] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoorTank[0]->SetPos1(m_x + 115, m_y);
	m_hit_line_ColorDoorTank[0]->SetPos2(m_x + 115, m_y + 36);
	m_hit_line_ColorDoorTank[0]->SetElement(2);		//属性を2にする
	m_hit_line_ColorDoorTank[0]->SetInvisible(false);	//無敵モード無効

	//ヒットラインの作成
	m_hit_line_ColorDoorTank[1] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoorTank[1]->SetPos1(m_x2 + 615, m_y2-51);
	m_hit_line_ColorDoorTank[1]->SetPos2(m_x2 + 615, m_y2 + 15);
	m_hit_line_ColorDoorTank[1]->SetElement(2);		//属性を2にする
	m_hit_line_ColorDoorTank[1]->SetInvisible(false);	//無敵モード無効

	////ヒットラインの作成
	//m_hit_line_ColorDoorTank[1] = Collision::HitLineInsert(this);
	//m_hit_line_ColorDoorTank[1]->SetPos1(m_x, m_y);
	//m_hit_line_ColorDoorTank[1]->SetPos2(m_x, m_y+110);
	//m_hit_line_ColorDoorTank[1]->SetElement(3);		//属性を2にする
	//m_hit_line_ColorDoorTank[1]->SetInvisible(false);	//無敵モード無効
}

//デストラクタ
ObjColorDoor_Tank::~ObjColorDoor_Tank()
{

}

//アクション
void ObjColorDoor_Tank::Action()
{
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	//タンクから水を汲む＆戻す
	for (int i = 0; i < 10; i++)
	{
		//for (int j = 0; j < 2; j++)
		//{
			if (m_hit_line_ColorDoorTank[0]->GetHitData()[i] != nullptr)
			{
				//自分の当たり判定の中に主人公の当たり判定があったら
				if (m_hit_line_ColorDoorTank[0]->GetHitData()[i]->GetElement() == 0)
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
								ObjColorDoor* cd = (ObjColorDoor*)TaskSystem::GetObj(COLORDOOR);
								m_moveY -= 0.14f;
								//us->AddY(0.14f);
								cd->AddY(0.6f);

								if (bm != nullptr) {
									//バケツメーターにセット
									bm->PushX();
								}
								//（バケツ満タン/75フレーム）
								m_water_remaining -= 0.02666;
							}
						}
					}
					//水をタンクに戻す
					else if (Input::KeyPush('C'))
					{

						//バケツメーターオブジェクト取得
						CBucketMeter* bm = (CBucketMeter*)TaskSystem::GetObj(BUCKETMETER);
						if (bm->GetColorR() != 2.0f)
							continue;

						//バケツが空じゃなかったら
						if (bm->GetWaterRem() > 0.0f) {
							//満タンだったら入れれない
							if (m_water_remaining < 6.0f) {
								//足場オブジェクト取得
								ObjColorDoor* cd = (ObjColorDoor*)TaskSystem::GetObj(COLORDOOR);
								m_moveY += 0.14f;
								//us->AddY(-0.14f);
								cd->AddY(-0.6f);

								if (bm != nullptr) {
									//バケツメーターにセット
									bm->PushC();
								}
								//（バケツ満タン/75フレーム）
								m_water_remaining += 0.02666;
							}
						}
					}
					break;
				}
			}
		//}
	}

	////入れ始め時の描画のための処理
	//m_wave_y = 350 - m_water_remaining;
	//if (m_wave_y < 345)m_wave_y = 345;
	//m_WaveSize_y = m_water_remaining * 0.5f;
	//if (m_WaveSize_y > 0.6f)m_WaveSize_y = 0.6f;
	m_WaterSize_y = m_water_remaining* -0.1575f;
	//if (m_WaterSize_y > 1.2)m_WaterSize_y = 1.2;

	//当たり判定の位置更新
	m_hit_line_ColorDoorTank[0]->SetPos1(m_x + 115 + ground3->GetScroll(), m_y);
	m_hit_line_ColorDoorTank[0]->SetPos2(m_x + 115 + ground3->GetScroll(), m_y + 36);
	m_hit_line_ColorDoorTank[1]->SetPos1(m_x2 + 115 + ground3->GetScroll(), m_y2);
	m_hit_line_ColorDoorTank[1]->SetPos2(m_x2 + 115 + ground3->GetScroll(), m_y2 + 36);

	//m_hit_line_ColorDoorTank[1]->SetPos1(m_x + ground3->GetScroll(), m_y);
	//m_hit_line_ColorDoorTank[1]->SetPos2(m_x + ground3->GetScroll(), m_y + 110);
}

//ドロー
void ObjColorDoor_Tank::Draw()
{
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	for (int i = 0; i < 10; i++)
	{
		//ギミックに近づいたらアイコンを出す
		if (m_hit_line_ColorDoorTank[0]->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_ColorDoorTank[0]->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(70, m_gx + 92 + ground3->GetScroll(), m_gy - 110);
			}
		}
	}

	//水表示
	Draw::Draw2D(48, m_water_x + ground3->GetScroll(), m_water_y, 0.9, m_WaterSize_y, rgba);

	//波アニメーション(後ろ)
	if (m_ani_time1 >= 109)
	{
		m_ani_time1 = 0;
	}
	else
	{
		m_ani_time1++;
	}
	int p_waveY = 5;
	//波アニメーション
	Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x + ground3->GetScroll(), m_wave_y - m_water_remaining * p_waveY, m_WaveSize_x, m_WaveSize_y, rgba);

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
	Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x + ground3->GetScroll(), m_wave_y - m_water_remaining * p_waveY, m_WaveSize_x, m_WaveSize_y, rgba);

	//赤のWTM表示
	Draw::Draw2D(74, m_gx + ground3->GetScroll(), m_gy);

	//緑のWTM表示
	Draw::Draw2D(82, m_gx+525 + ground3->GetScroll(), m_gy-88);

	//赤のギミックタンク表示
	Draw::Draw2D(75, m_gx+115 + ground3->GetScroll(), m_gy+36);

	//赤のギミックタンク表示(2個目)
	Draw::Draw2D(75, m_gx + 615 + ground3->GetScroll(), m_gy - 51);

	//緑のギミックタンク表示
	Draw::Draw2D(83, m_gx + 760 + ground3->GetScroll(), m_gy - 51);

	//Draw::Draw2D(58, m_gx + ground3->GetScroll(), m_gy+100);
}