//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjDownBlock_Tank.h"
#include "ObjDownBlock.h"
#include "ObjGround.h"
#include "ObjGround3.h"
#include "BucketMeter.h"
extern int g_SceneNumber;

const float ObjDownBlock_Tank::m_WaveSize_x = 0.23f*0.2f;

ObjDownBlock_Tank::ObjDownBlock_Tank(float x,float y)
	:m_x(x), m_y(y),m_gx(x+15),m_gy(y-15), m_wave_x(x+16), m_wave_y(y+103), m_save_x(x), m_save_y(y),
	m_ani_time1(0.0f), m_ani_time2(0.0f), m_WaveSize_y(0.3f)
	, m_water_x(x+16), m_water_y(y+109), m_moveY(y+12), 
	m_RopeSizeBucket(0.3f), m_water_remaining(2.0f)
	, m_bucket_remaining(0.4f), m_PulleyAni(0)
{
	//ヒットラインの作成(左)
	m_hit_line_DwBlTank = Collision::HitLineInsert(this);
	m_hit_line_DwBlTank->SetPos1(m_x, m_y);
	m_hit_line_DwBlTank->SetPos2(m_x, m_y + 100);
	m_hit_line_DwBlTank->SetElement(2);		//属性を2にする
	m_hit_line_DwBlTank->SetInvisible(false);	//無敵モード無効
}

ObjDownBlock_Tank::~ObjDownBlock_Tank()
{

}

void ObjDownBlock_Tank::Action()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	if (m_PulleyAni > 8) m_PulleyAni = 0;

	//タンクから水を汲む＆戻す
	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_DwBlTank->GetHitData()[i] != nullptr)
		{
			//自分の当たり判定の中に主人公の当たり判定があったら
			if (m_hit_line_DwBlTank->GetHitData()[i]->GetElement() == 0)
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
							ObjDownBlock* db = (ObjDownBlock*)TaskSystem::GetObj(DOWNBLOCK);

							m_gy -= 0.5f;  //バケツ移動
							m_RopeSizeBucket -= 0.0015f;  //バケツ側ロープ長さ変更

							db->AddY(0.5f);  //足場ブロック移動
							db->SetRopeSizeScaffold(0.002f);  //足場ロープ長さ変更

							db->SetY(0.5f);  //足場当たり判定移動

							m_bucket_remaining -= 0.006f;  //水減らす
							//波の位置
							if (m_wave_y < m_save_y+98)m_wave_y -= 0.26f;
							else m_wave_y -= 0.3f;
							m_water_y -= 0.325f;  //水の位置

							if (bm != nullptr) {
								//バケツメーターにセット
								bm->PushX();
							}

							//（バケツ満タン/75フレーム）
							m_water_remaining -= 0.02666;
							
							m_PulleyAni++;

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
						if (m_water_remaining < 2.0f) {
							//足場オブジェクト取得
							ObjDownBlock* db = (ObjDownBlock*)TaskSystem::GetObj(DOWNBLOCK);
							//m_moveY += 0.2f;
							//db->AddY(-0.2f);
							m_gy += 0.5f;  //バケツ移動
							m_RopeSizeBucket += 0.0015f;  //バケツ側ロープ長さ変更

							db->AddY(-0.5f);  //足場ブロック移動
							db->SetRopeSizeScaffold(-0.002f);  //足場ロープ長さ変更

							db->SetY(-0.5f);  //足場当たり判定移動

							m_bucket_remaining += 0.006f;  //水減らす
							//波の位置
							if (m_wave_y < m_save_y+98)m_wave_y += 0.26f;
							else m_wave_y += 0.3f;
							m_water_y += 0.325f;  //水の位置

							if (bm != nullptr) {
								//バケツメーターにセット
								bm->PushC();
							}

							//（バケツ満タン/75フレーム）
							m_water_remaining += 0.02666;

							m_PulleyAni++;

						}
					}
				}
				break;
			}
		}
	}

	m_WaveSize_y = m_water_remaining *0.06f;
	if (m_WaveSize_y > 0.6f)m_WaveSize_y = 0.6f;

	//当たり判定位置の更新
	if (ground != nullptr) {
		m_hit_line_DwBlTank->SetPos1(m_x + ground->GetScroll(), m_y);
		m_hit_line_DwBlTank->SetPos2(m_x + ground->GetScroll(), m_y + 100);
	}
	else {
		m_hit_line_DwBlTank->SetPos1(m_x + ground3->GetScroll(), m_y);
		m_hit_line_DwBlTank->SetPos2(m_x + ground3->GetScroll(), m_y + 100);
	}
}

void ObjDownBlock_Tank::Draw()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	if (ground != nullptr) {
		//ギミックに近づいたらアイコンを出す
		for (int i = 0; i < 10; i++)
		{
			if (m_hit_line_DwBlTank->GetHitData()[i] != nullptr)
			{
				if (m_hit_line_DwBlTank->GetHitData()[i]->GetElement() == 0)
				{
					Draw::Draw2D(70, m_x - 10 + ground->GetScroll(), m_y - 130);
				}
			}
		}

		//水表示
		if(m_bucket_remaining>=0.0f)
			Draw::Draw2D(48, m_water_x + ground->GetScroll(), m_water_y, 0.025, m_bucket_remaining/18);

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
		if (m_bucket_remaining >= 0.0f)
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
		if (m_bucket_remaining >= 0.0f)
			Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);

		//Draw::Draw2D(21, a, m_y);

		//ロープ表示
		Draw::Draw2D(62, m_gx + 10 + ground->GetScroll(), 135, 1, m_RopeSizeBucket);
		//バケツ表示
		Draw::Draw2D(56, m_gx + 1 + ground->GetScroll(), m_gy + 100, 1, 1);
		//横ロープ表示
		Draw::Draw2D(59, m_gx + 25 + ground->GetScroll(), m_save_y - 38, 1, 1);
		//滑車表示
		if (m_PulleyAni <= 4)
			Draw::Draw2D(57, m_gx + 5 + ground->GetScroll(), m_save_y - 40, 1, 1);
		else
			Draw::Draw2D(57, m_gx + 189 + ground->GetScroll(), m_save_y - 40, -1, 1);
	}
	else {
		//ギミックに近づいたらアイコンを出す
		for (int i = 0; i < 10; i++)
		{
			if (m_hit_line_DwBlTank->GetHitData()[i] != nullptr)
			{
				if (m_hit_line_DwBlTank->GetHitData()[i]->GetElement() == 0)
				{
					Draw::Draw2D(70, m_x - 10 + ground3->GetScroll(), m_y - 130);
				}
			}
		}

		//水表示
		if (m_bucket_remaining >= 0.0f)
		Draw::Draw2D(48, m_water_x + ground3->GetScroll(), m_water_y, 0.025, m_bucket_remaining/18);

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
		if (m_bucket_remaining >= 0.0f)
		Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);

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
		if (m_bucket_remaining >= 0.0f)
		Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x + ground3->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);

		//ロープ表示
		Draw::Draw2D(62, m_gx + 10 + ground3->GetScroll(), m_save_y-15, 1, m_RopeSizeBucket);
		//バケツ表示
		Draw::Draw2D(56, m_gx + 1 + ground3->GetScroll(), m_gy + 100, 1, 1);
		//横ロープ表示
		Draw::Draw2D(59, m_gx + 25 + ground3->GetScroll(), m_save_y - 38, 1, 1);
		//滑車表示
		if (m_PulleyAni <= 4)
			Draw::Draw2D(57, m_gx + 5 + ground3->GetScroll(), m_save_y - 40, 1, 1);
		else
			Draw::Draw2D(57, m_gx + 189 + ground3->GetScroll(), m_save_y - 40, -1, 1);
	}

}