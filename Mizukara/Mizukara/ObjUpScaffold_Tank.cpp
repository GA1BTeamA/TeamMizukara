//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjUpScaffold_Tank.h"
#include "ObjUpScaffold.h"
#include "ObjGround.h"
#include "BucketMeter.h"
extern int g_SceneNumber;

const float ObjUpScaffold_Tank::m_WaveSize_x = 0.35f;
//const float ObjUpScaffold_Tank::m_WaveSize_y = 0.6f;

ObjUpScaffold_Tank::ObjUpScaffold_Tank()
	:m_x(295), m_y(249), m_wave_x(300), m_wave_y(350), m_ani_time1(0.0f), m_ani_time2(0.0f)
	, m_water_x(300), m_water_y(350), m_gx(490), m_gy(249), m_water_remaining(0.0f), m_moveY(350)
	, m_RopeSizeBoard(0.3f), m_RopeSizeScaffold(0.27),m_PulleyAni(0),m_WaveSize_y(0.0f), m_WaterSize_y(0.0f)
{
	//ヒットラインの作成(左)
	m_hit_line_UpScTank = Collision::HitLineInsert(this);
	m_hit_line_UpScTank->SetPos1(m_x, m_y);
	m_hit_line_UpScTank->SetPos2(m_x, m_y + 100);
	m_hit_line_UpScTank->SetElement(2);		//属性を2にする
	m_hit_line_UpScTank->SetInvisible(false);	//無敵モード無効
}

ObjUpScaffold_Tank::~ObjUpScaffold_Tank()
{

}

void ObjUpScaffold_Tank::Action()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	if (m_PulleyAni > 8) m_PulleyAni = 0;

	//タンクから水を汲む＆戻す
	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_UpScTank->GetHitData()[i] != nullptr)
		{
			//自分の当たり判定の中に主人公の当たり判定があったら
			if (m_hit_line_UpScTank->GetHitData()[i]->GetElement() == 0)
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
							ObjUpScaffold* us = (ObjUpScaffold*)TaskSystem::GetObj(UPSCAFFOLD);
							m_moveY -= 0.14f;
							us->AddY(0.14f);

							m_RopeSizeBoard -= 0.0004f;
							m_RopeSizeScaffold += 0.0004f;

							if (bm != nullptr) {
								//バケツメーターにセット
								bm->PushX();
							}

							//　　　　　　　　　（バケツ満タン/75フレーム）
							m_water_remaining -= 0.02666;

							m_PulleyAni++;
						}
					}
				}
				//水をタンクに戻す
				else if (Input::KeyPush('C'))
				{

					//バケツメーターオブジェクト取得
					CBucketMeter* bm = (CBucketMeter*)TaskSystem::GetObj(BUCKETMETER);
					//バケツが空じゃなかったら
					if (bm->GetWaterRem() > 0.0f) {
						//満タンだったら入れれない
						if (m_water_remaining < 6.0f) {
							//足場オブジェクト取得
							ObjUpScaffold* us = (ObjUpScaffold*)TaskSystem::GetObj(UPSCAFFOLD);
							m_moveY += 0.14f;
							us->AddY(-0.14f);

							m_RopeSizeBoard += 0.0004f;
							m_RopeSizeScaffold -= 0.0004f;

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
	//入れ始め時の描画のための処理
	m_wave_y = 350 - m_water_remaining;
	if (m_wave_y < 345)m_wave_y = 345;
	m_WaveSize_y = m_water_remaining *0.5f;
	if (m_WaveSize_y > 0.6f)m_WaveSize_y = 0.6f;
	m_WaterSize_y = m_water_remaining*0.01f;
	if (m_WaterSize_y > 1)m_WaterSize_y = 1;

	//当たり判定位置の更新
	m_hit_line_UpScTank->SetPos1(m_x + ground->GetScroll(), m_y);
	m_hit_line_UpScTank->SetPos2(m_x + ground->GetScroll(), m_y + 100);
}

//ドロー
void ObjUpScaffold_Tank::Draw()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	//ギミックに近づいたらアイコンを出す
	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_UpScTank->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_UpScTank->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(70, m_x - 15 + ground->GetScroll(), m_y - 110);
			}
		}
	}

	//水表示
	Draw::Draw2D(48, m_water_x + ground->GetScroll(), m_water_y, 0.039, m_WaterSize_y);

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
	Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x*0.2, m_WaveSize_y*0.2);
	//if (m_ani_time1 < 10)
	//{
	//}
	//else if (m_ani_time1 < 20)
	//{
	//	Draw::Draw2D(37, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	//}
	//else if (m_ani_time1 < 30)
	//{
	//	Draw::Draw2D(38, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	//}
	//else if (m_ani_time1 < 40)
	//{
	//	Draw::Draw2D(39, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	//}
	//else if (m_ani_time1 < 50)
	//{
	//	Draw::Draw2D(40, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	//}
	//else if (m_ani_time1 < 60)
	//{
	//	Draw::Draw2D(41, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	//}
	//else if (m_ani_time1 < 70)
	//{
	//	Draw::Draw2D(42, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	//}
	//else if (m_ani_time1 < 80)
	//{
	//	Draw::Draw2D(43, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	//}
	//else if (m_ani_time1 < 90)
	//{
	//	Draw::Draw2D(44, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	//}
	//else if (m_ani_time1 < 100)
	//{
	//	Draw::Draw2D(45, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	//}
	//else if (m_ani_time1 < 110)
	//{
	//	Draw::Draw2D(46, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	//}

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
	Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x*0.2, m_WaveSize_y*0.2);
	//if (m_ani_time2 < 5)
	//{
	//}
	//else if (m_ani_time2 < 10)
	//{
	//	Draw::Draw2D(26, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	//}
	//else if (m_ani_time2 < 15)
	//{
	//	Draw::Draw2D(27, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	//}
	//else if (m_ani_time2 < 20)
	//{
	//	Draw::Draw2D(28, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	//}
	//else if (m_ani_time2 < 25)
	//{
	//	Draw::Draw2D(29, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	//}
	//else if (m_ani_time2 < 30)
	//{
	//	Draw::Draw2D(30, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	//}
	//else if (m_ani_time2 < 35)
	//{
	//	Draw::Draw2D(31, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	//}
	//else if (m_ani_time2 < 40)
	//{
	//	Draw::Draw2D(32, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	//}
	//else if (m_ani_time2 < 45)
	//{
	//	Draw::Draw2D(33, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	//}
	//else if (m_ani_time2 < 50)
	//{
	//	Draw::Draw2D(34, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	//}
	//else if (m_ani_time2 < 55)
	//{
	//	Draw::Draw2D(35, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	//}

	//Draw::Draw2D(21, a, m_y);

	//タンク側 板のロープ表示
	Draw::Draw2D(62, m_gx - 176 + ground->GetScroll(), m_gy,1, m_RopeSizeBoard);
	//足場のロープ表示
	Draw::Draw2D(62, m_gx+50 + ground->GetScroll(), m_gy,1, m_RopeSizeScaffold);

	//板表示
	Draw::Draw2D(55, m_gx - 189 + ground->GetScroll(), m_moveY);
	//横ロープ表示
	Draw::Draw2D(52, m_gx - 190 + ground->GetScroll(), m_gy - 19);

	if(m_PulleyAni<=4)
		Draw::Draw2D(54, m_gx+56 + ground->GetScroll(), m_gy - 20,-1,1);
	else
		Draw::Draw2D(54, m_gx - 180 + ground->GetScroll(), m_gy - 20);



}