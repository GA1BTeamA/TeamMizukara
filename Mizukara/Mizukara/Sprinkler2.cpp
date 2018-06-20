//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Sprinkler2.h"
#include "ObjGround2.h"
#include "Hero.h"
#include "Tank2.h"
#include "BucketMeter.h"
extern int g_SceneNumber;
extern bool g_key_flag;
extern bool g_clearlist;
extern float g_TankRemaining;

const float CSPRI2::m_WaveSize_x = 0.55f;
const float CSPRI2::m_WaveSize_y = 0.6f;

CSPRI2::CSPRI2()
	:m_x(2920), m_y(250), m_wave_x(2950), m_wave_y(230),
	m_ani_time1(0.0f), m_ani_time2(0.0f), m_ani_time3(0.0f), m_ani_time4(0.0f), m_ani_time5(-1)
	, m_move1(0.0f), m_move2(0.0f), im_x(2150), im_y(130),
	m_water_x(2950), m_water_y(242), m_vy(0.0f), m_sy(230)
	, m_CrearCnt2(false), m_Flower(false)
	, m_fx(734), m_fy(250), m_BrackBackDraw(false), m_BrackBackDrawCnt(0)
	, m_BrackBack_sx(6.0f), m_BrackBack_sy(6.0f)
	, m_BrackBack_x(-3780), m_BrackBack_y(-1425)
{
	m_name = SPRI2;

	//ヒットラインの作成(左)
	m_p_hit_line_spri2 = Collision::HitLineInsert(this);
	m_p_hit_line_spri2->SetPos1(m_x, m_y);
	m_p_hit_line_spri2->SetPos2(m_x, m_y + 100);
	m_p_hit_line_spri2->SetElement(4);		//属性を4にする
	m_p_hit_line_spri2->SetInvisible(false);	//無敵モード無効
}

CSPRI2::~CSPRI2()
{

}

void CSPRI2::Action()
{
	if (m_ani_time5 > 51)m_ani_time5 = 0;
	else if (m_ani_time5 >= 0)m_ani_time5++;

	ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);
	CTank2* tank = (CTank2*)TaskSystem::GetObj(TANK2);

	//当たり判定位置の更新
	m_p_hit_line_spri2->SetPos1(m_x + ground2->GetScroll(), m_y);
	m_p_hit_line_spri2->SetPos2(m_x + ground2->GetScroll(), m_y + 100);

	//クリア画面が表示されたら
	if (m_CrearCnt2 == true)
	{
		//エンターキーが押されたら
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				//黒背景の表示をtrueにする
				m_BrackBackDraw = true;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}

	//破棄
	if (m_BrackBackDrawCnt == 40)
	{
		Audio::StopLoopMusic(9);
		g_SceneNumber = RESULT;
		//g_clearlist = true;
		g_key_flag = false;
		//g_TankRemaining = false;
	}

	//黒背景縮小と移動
	if (m_BrackBackDraw == true && m_BrackBack_sx > 1.1f)
	{
		//縮小
		m_BrackBack_sx -= 0.1f;
		m_BrackBack_sy -= 0.1f;
		//花中心になるように移動
		m_BrackBack_x += 75.6f;//元の位置の50分の1の値
		m_BrackBack_y += 28.5f;
	}
	else if (m_BrackBack_sx<1.1f)
	{
		//縮小しきったらカウントスタート
		m_BrackBackDrawCnt++;
	}

	//カウントが40を超えるとストップするようにしてるつもり
	if (m_BrackBackDrawCnt > 41)
	{
		m_BrackBackDrawCnt = 41;
	}

	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_spri2->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_spri2->GetHitData()[i]->GetElement() == 0)
			{
				Audio::StopLoopMusic(6);

				Audio::StartLoopMusic(9);
				Audio::LoopMusicVolume(9, 0.05f);

				//タンクの水をスプリンクラーから出す
				if (m_ani_time4 >= 460 && tank->GetWater_Remaining() > 0)
				{
					tank->SetWater_Remaining(-0.2f);
					g_TankRemaining += 0.2f;
				}
				break;
			}
		}
	}

	//タンクの残量が0以下になったら、
	if (tank->GetWater_Remaining() < 0)
	{
		//ランク用のタンク残量からマイナス分を引く
		g_TankRemaining += tank->GetWater_Remaining();
		tank->ResetWater_Remaining(0);
	}

	//m_ani_time5++;
	if (m_ani_time5 == 50 && m_sy == 230 && g_SceneNumber != RESULT_MAIN)
	{
		m_vy = -8.0f;
		m_CrearCnt2 = true;
	}
	//else if (m_ani_time5 > 200 && m_ani_time5 <= 210 && m_sy == 230)
	//{
	//	m_vy = -8.0f;
	//}
	m_vy += 9.8 / (16.0f);


	m_sy += m_vy;
	if (m_sy > 230) { m_sy = 230; m_vy = 0.0f; }

}

void CSPRI2::Draw()
{
	ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);
	CTank2* tank2 = (CTank2*)TaskSystem::GetObj(TANK2);

	//クリア画面表示
	if (m_CrearCnt2 == true)
	{
		Draw::Draw2D(63, 300, 140);
	}

	//水表示
	//Draw::Draw2D(48, m_water_x + ground2->GetScroll(), m_water_y, 1.6, 1.4);

	//波の表示(後ろ)
	if (m_ani_time1 >= 109)
	{
		m_ani_time1 = 0;
	}
	else
	{
		m_ani_time1++;
	}

	//Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);

	//波の表示(前)
	if (m_ani_time2 >= 54)
	{
		m_ani_time2 = 0;
	}
	else
	{
		m_ani_time2++;
	}

	//Sprinklerに近づいたら主人公アニメーションを出す
	if (m_ani_time3 >= 29)
	{
		m_ani_time3 = 0;
	}
	else
	{
		m_ani_time3++;
	}

	//花表示
	if (g_TankRemaining >= 40)
	{
		Draw::Draw2D(92, m_fx, m_fy);  //Sランク
	}
	else if (g_TankRemaining >= 35)
	{
		Draw::Draw2D(91, m_fx, m_fy);  //Aランク
	}
	else if (g_TankRemaining >= 25)
	{
		Draw::Draw2D(90, m_fx, m_fy);  //Bランク
	}
	else if (g_TankRemaining >= 10)
	{
		Draw::Draw2D(89, m_fx, m_fy);  //Cランク
	}
	else if (g_TankRemaining >= 1)
	{
		Draw::Draw2D(64, m_fx, m_fy);  //Dランク
	}


	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_spri2->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_spri2->GetHitData()[i]->GetElement() == 0)
			{
				if (m_move1 >= 120)
				{
					m_ani_time4++;
					//m_ani_time5++;

					if (m_ani_time4 < 200)//スプリンクラー前で主人公が立ち止まる
					{
						Draw::Draw2D(0, m_wave_x + ground2->GetScroll() - 50 + m_move1, m_wave_y - 10, 1, 1);
					}
					else if (m_ani_time4 > 200 && m_ani_time4 < 300)//ホースをつなげる
					{
						Draw::Draw2D(6, m_wave_x + ground2->GetScroll() - 50 + m_move1, m_wave_y - 10, 1, 1);//しゃがむ
					}
					else if (m_ani_time4 > 300)//ホースを付け終わり再び主人公静止
					{
						Draw::Draw2D(50, m_wave_x - 36 + ground2->GetScroll() - 50 + m_move1, 300, 1, 1);
						
						Draw::Draw2D(77, m_wave_x - 8 + ground2->GetScroll() + m_move1, 307, 1, 1);

						if (g_SceneNumber == RESULT_MAIN&&m_vy == 0.0f)
						{
							Draw::Draw2D(0, m_wave_x + ground2->GetScroll() - 50 + m_move1, 220, 1, 1);
						}
						else if (m_sy <= 200)
						{
							Draw::Draw2D(9, m_wave_x + ground2->GetScroll() - 50 + m_move1, m_sy - 10, 1, 1);//ジャンプ
						}
						else
						{
							Draw::Draw2D(72, m_wave_x + ground2->GetScroll() - 50 + m_move1, m_sy - 10, 1, 1);
						}

						if (m_ani_time4 >= 460)
						{
							m_move2++;
							//Draw::Draw2D(0, m_wave_x + ground2->GetScroll() - 50 + m_move1, m_sy - 10, 1, 1);
							if (tank2->GetWater_Remaining() > 0)
							{
								Audio::StartLoopMusic(13);
								Audio::LoopMusicVolume(13, 0.1f);

								if (m_move2 <= 10)//スプリンクラーから水が出る
								{
									Draw::Draw2D(51, m_wave_x + ground2->GetScroll() + 60 + m_move1, m_wave_y-4, 1, 1);
								}
								else if (m_move2 >= 11 && m_move2 < 20)
								{
									Draw::Draw2D(51, m_wave_x + ground2->GetScroll() + 97 + m_move1, m_wave_y - 6, -1, 1);
								}
								else
								{
									m_move2 = 0;
								}
							}
							else
							{
								if (m_ani_time5 == -1)m_ani_time5++;
								Audio::StopLoopMusic(13);
							}
						}
					}
				}
				else
				{
					m_move1++;

					if (m_ani_time3 < 10)
					{
						Draw::Draw2D(2, m_wave_x + ground2->GetScroll() - 50 + m_move1, m_wave_y - 10, 1, 1);
					}
					else if (m_ani_time3 < 20)
					{
						Draw::Draw2D(7, m_wave_x + ground2->GetScroll() - 50 + m_move1, m_wave_y - 10, 1, 1);
					}
					else if (m_ani_time3 < 30)
					{
						Draw::Draw2D(0, m_wave_x + ground2->GetScroll() - 50 + m_move1, m_wave_y - 10, 1, 1);
					}
				}
			}
		}
	}

	//黒背景表示
	if (m_BrackBackDraw == true)
	{
		Draw::Draw2D(117, m_BrackBack_x, m_BrackBack_y, m_BrackBack_sx, m_BrackBack_sy);  //クリア後の黒背景
	}

}