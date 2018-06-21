//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjColorDoor_Tank.h"
#include "ObjGround3.h"
#include "BucketMeter.h"
#include "ObjColorDoor.h"

const float ObjColorDoor_Tank::m_WaveSize_x = 0.32f*0.2f;

//コンストラクタ
ObjColorDoor_Tank::ObjColorDoor_Tank(float x, float y, int color, float waveX, float waveY,unsigned int n)
	:m_x(x), m_y(y), m_gx(x), m_gy(y)
	, m_moveY(350), m_wave_x(x+3), m_wave_y(y+45)
	, m_water_x(x+3), m_water_y(y+53), m_water_remaining(0.0f)
	, m_WaveSize_y(0.4f*0.2f), m_WaterSize_y(0.0f)
	, m_ani_time1(0.0f), m_ani_time2(0.0f), m_DoorNo(n)
{

	if (color == 75)
	{
		//水の色用配列初期化(赤)
		rgba[0] = 2.0f;
		rgba[1] = 0.5f;
		rgba[2] = 0.5f;
		rgba[3] = 1.0f;
	}
	else if(color ==82)
	{
		//水の色用配列初期化(緑)
		rgba[0] = 0.0f;
		rgba[1] = 1.0f;
		rgba[2] = 0.5f;
		rgba[3] = 1.0f;
	}

	//ヒットラインの作成
	m_hit_line_ColorDoorTank[0] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoorTank[0]->SetPos1(m_x, m_y+50);
	m_hit_line_ColorDoorTank[0]->SetPos2(m_x, m_y + 100);
	m_hit_line_ColorDoorTank[0]->SetElement(2);		//属性を2にする
	m_hit_line_ColorDoorTank[0]->SetInvisible(false);	//無敵モード無効

}

//デストラクタ
ObjColorDoor_Tank::~ObjColorDoor_Tank()
{

}

//アクション
void ObjColorDoor_Tank::Action()
{
	ObjColorDoor* cd;
	switch (m_DoorNo)
	{
	case 1:	cd = (ObjColorDoor*)TaskSystem::GetObj(COLORDOOR);	break;
	case 2:	cd = (ObjColorDoor*)TaskSystem::GetObj(COLORDOOR2); break;
	case 3:	cd = (ObjColorDoor*)TaskSystem::GetObj(COLORDOOR3); break;
	case 4:	cd = (ObjColorDoor*)TaskSystem::GetObj(COLORDOOR4); break;
	case 5:	cd = (ObjColorDoor*)TaskSystem::GetObj(COLORDOOR5); break;
	}

	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	//タンクから水を汲む＆戻す
	for (int i = 0; i < 10; i++)
	{
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
							m_moveY -= 0.14f;
							cd->AddY(0.6f);

							if (cd)
								Audio::StartLoopMusic(12);
							Audio::LoopMusicVolume(12, 0.05f);

							if (bm != nullptr) {
								//バケツメーターにセット
								bm->PushX();
							}

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
					//赤タンク
					if (rgba[0]!=2.0f && bm->GetColorR() == 2.0f)
						continue;
					//緑タンク
					if (rgba[0] == 2.0f && bm->GetColorR() != 2.0f)
						continue;

					//バケツが空じゃなかったら
					if (bm->GetWaterRem() > 0.0f) {
						//満タンだったら入れれない
						if (m_water_remaining < 6.0f) {
							//足場オブジェクト取得
							m_moveY += 0.14f;
							cd->AddY(-0.6f);

							if (cd)
								Audio::StartLoopMusic(12);
							Audio::LoopMusicVolume(12, 0.05f);

							if (bm != nullptr) {
								//バケツメーターにセット
								bm->PushC();
							}

							//（バケツ満タン/75フレーム）
							m_water_remaining += 0.02666;
						}
					}
					
				}
				//CもXも押してなかったら音楽を止める
				if (!(Input::KeyPush('C')) && !(Input::KeyPush('X')))
					Audio::StopLoopMusic(12);

				break;
			}
		}
	}

	//入れ始め時の描画のための処理
	m_WaterSize_y = m_water_remaining* -0.0082f;
	
	m_WaveSize_y = m_water_remaining*0.08f*0.5f;
	if (m_WaveSize_y > 0.08f)m_WaveSize_y = 0.08f;

	//当たり判定の位置更新
	m_hit_line_ColorDoorTank[0]->SetPos1(m_x + ground3->GetScroll(), m_y+50);
	m_hit_line_ColorDoorTank[0]->SetPos2(m_x + ground3->GetScroll(), m_y + 100);
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
				Draw::Draw2D(70, m_gx-22 + ground3->GetScroll(), m_gy - 110);
			}
		}
	}

	//水表示
	Draw::Draw2D(48, m_water_x + ground3->GetScroll(), m_water_y, 0.0349, m_WaterSize_y, rgba);

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

	if (m_water_remaining>2.0f) {
		//波アニメーション(後ろ)
		Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x + ground3->GetScroll(), (m_wave_y - m_water_remaining * p_waveY), m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else {
		Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x + ground3->GetScroll(), (m_wave_y - m_water_remaining * p_waveY) + 9 * (2.0f - m_water_remaining)*0.5f, m_WaveSize_x, m_WaveSize_y, rgba);
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

	if (m_water_remaining>2.0f) {
		//波アニメーション(前)
		Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x + ground3->GetScroll(), (m_wave_y - m_water_remaining * p_waveY), m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else {
		Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x + ground3->GetScroll(), (m_wave_y - m_water_remaining * p_waveY) + 9 * (2.0f - m_water_remaining)*0.5f, m_WaveSize_x, m_WaveSize_y, rgba);
	}

	//色ごとのギミックタンク描画
	if (rgba[0] == 2.0f)
	{
		//赤のギミックタンク表示
		Draw::Draw2D(75, m_gx + ground3->GetScroll(), m_gy);
	}
	else
	{
		//緑のギミックタンク表示
		Draw::Draw2D(83, m_gx + ground3->GetScroll(), m_gy);
	}
}