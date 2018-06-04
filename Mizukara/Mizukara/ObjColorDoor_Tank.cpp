//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjColorDoor_Tank.h"
#include "ObjGround3.h"
#include "BucketMeter.h"

const float ObjColorDoor_Tank::m_WaveSize_x = 0.35f;


//コンストラクタ
ObjColorDoor_Tank::ObjColorDoor_Tank()
	:m_x(230), m_y(299), m_gx(230), m_gy(299)
	, m_moveY(350), m_wave_x(100), m_wave_y(350)
	, m_water_x(300), m_water_y(350), m_water_remaining(0.0f)
	, m_WaveSize_y(0.0f), m_WaterSize_y(0.0f)
{
	//ヒットラインの作成
	m_hit_line_ColorDoorTank[0] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoorTank[0]->SetPos1(m_x + 115, m_y);
	m_hit_line_ColorDoorTank[0]->SetPos2(m_x + 115, m_y + 36);
	m_hit_line_ColorDoorTank[0]->SetElement(2);		//属性を2にする
	m_hit_line_ColorDoorTank[0]->SetInvisible(false);	//無敵モード無効

	//ヒットラインの作成
	m_hit_line_ColorDoorTank[1] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoorTank[1]->SetPos1(m_x, m_y);
	m_hit_line_ColorDoorTank[1]->SetPos2(m_x, m_y+110);
	m_hit_line_ColorDoorTank[1]->SetElement(3);		//属性を2にする
	m_hit_line_ColorDoorTank[1]->SetInvisible(false);	//無敵モード無効
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
		for (int j = 0; j < 2; j++)
		{
			if (m_hit_line_ColorDoorTank[j]->GetHitData()[i] != nullptr)
			{
				//自分の当たり判定の中に主人公の当たり判定があったら
				if (m_hit_line_ColorDoorTank[j]->GetHitData()[i]->GetElement() == 0)
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
								//ObjDownBlock* db = (ObjDownBlock*)TaskSystem::GetObj(DOWNBLOCK);

								m_gy -= 0.5f;  //バケツ移動
								//m_RopeSizeBucket -= 0.0015f;  //バケツ側ロープ長さ変更

								//db->AddY(0.5f);  //足場ブロック移動
								//db->SetRopeSizeScaffold(0.002f);  //足場ロープ長さ変更

								//db->SetY(0.5f);  //足場当たり判定移動

								//m_bucket_remaining -= 0.006f;  //水減らす
								//波の位置
								if (m_wave_y < 248)m_wave_y -= 0.26f;
								else m_wave_y -= 0.3f;
								m_water_y -= 0.325f;  //水の位置
													  //m_WaveSize_y -= 0.01f;
													  //m_RopeSizeBoard -= 0.0006f;
													  //m_RopeSizeBucket += 0.0006f;

								if (bm != nullptr) {
									//バケツメーターにセット
									bm->PushX();
								}

								//（バケツ満タン/75フレーム）
								m_water_remaining -= 0.02666;

								//m_PulleyAni++;

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
								//ObjDownBlock* db = (ObjDownBlock*)TaskSystem::GetObj(DOWNBLOCK);
								//m_moveY += 0.2f;
								//db->AddY(-0.2f);
								m_gy += 0.5f;  //バケツ移動
								//m_RopeSizeBucket += 0.0015f;  //バケツ側ロープ長さ変更

								//db->AddY(-0.5f);  //足場ブロック移動
								//db->SetRopeSizeScaffold(-0.002f);  //足場ロープ長さ変更

								//db->SetY(-0.5f);  //足場当たり判定移動

								//m_bucket_remaining += 0.006f;  //水減らす
								//波の位置
								if (m_wave_y < 248)m_wave_y += 0.26f;
								else m_wave_y += 0.3f;
								m_water_y += 0.325f;  //水の位置
													  //m_WaveSize_y += 0.01f;
													  ////m_RopeSizeBoard += 0.0006f;
													  //m_RopeSizeBucket -= 0.0006f;

								if (bm != nullptr) {
									//バケツメーターにセット
									bm->PushC();
								}

								//（バケツ満タン/75フレーム）
								m_water_remaining += 0.02666;

								//m_PulleyAni++;

							}
						}
					}
					break;
				}
			}
		}
	}
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

		//ギミックタンクに近づいたらアイコンを出す
		if (m_hit_line_ColorDoorTank[1]->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_ColorDoorTank[1]->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(21, m_gx + ground3->GetScroll()-10, m_gy - 130);
			}
		}
	}

	//水表示
	Draw::Draw2D(48, m_water_x + ground3->GetScroll(), m_water_y, 1.05, m_WaterSize_y);

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
		Draw::Draw2D(36, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 20)
	{
		Draw::Draw2D(37, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 30)
	{
		Draw::Draw2D(38, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 40)
	{
		Draw::Draw2D(39, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 50)
	{
		Draw::Draw2D(40, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 60)
	{
		Draw::Draw2D(41, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 70)
	{
		Draw::Draw2D(42, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 80)
	{
		Draw::Draw2D(43, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 90)
	{
		Draw::Draw2D(44, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 100)
	{
		Draw::Draw2D(45, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 110)
	{
		Draw::Draw2D(46, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
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
		Draw::Draw2D(25, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 10)
	{
		Draw::Draw2D(26, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 15)
	{
		Draw::Draw2D(27, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 20)
	{
		Draw::Draw2D(28, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 25)
	{
		Draw::Draw2D(29, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 30)
	{
		Draw::Draw2D(30, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 35)
	{
		Draw::Draw2D(31, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 40)
	{
		Draw::Draw2D(32, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 45)
	{
		Draw::Draw2D(33, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 50)
	{
		Draw::Draw2D(34, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 55)
	{
		Draw::Draw2D(35, m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}

	//赤のWTM表示
	Draw::Draw2D(74, m_gx + ground3->GetScroll(), m_gy);

	//赤のギミックタンク表示
	Draw::Draw2D(75, m_gx+115 + ground3->GetScroll(), m_gy+36);

	//Draw::Draw2D(58, m_gx + ground3->GetScroll(), m_gy+100);
}