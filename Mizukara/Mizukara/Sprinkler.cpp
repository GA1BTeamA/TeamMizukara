//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Sprinkler.h"
#include "ObjGround.h"
#include "Hero.h"
#include "Tank.h"
#include "BucketMeter.h"
extern int g_SceneNumber;
extern bool g_key_flag;
extern bool g_clearlist;
extern float g_TankRemaining;

const float CSPRI::m_WaveSize_x = 0.55f;
const float CSPRI::m_WaveSize_y = 0.6f;

CHero* hero;

CSPRI::CSPRI()
	:m_x(2150), m_y(250), m_wave_x(2150), m_wave_y(230), 
	m_ani_time1(0.0f), m_ani_time2(0.0f),m_ani_time3(0.0f),m_ani_time4(0.0f),m_ani_time5(0.0f)
	, m_move1(0.0f),m_move2(0.0f),im_x(2150), im_y(130), 
	m_water_x(2150), m_water_y(242), m_vy(0.0f), m_sy(230)
	,m_CrearCnt(false), m_Flower(false)
	, m_fx(734), m_fy(250)
{
	m_name = SPRI;

	//ヒットラインの作成(左)
	m_p_hit_line_spri = Collision::HitLineInsert(this);
	m_p_hit_line_spri->SetPos1(m_x, m_y);
	m_p_hit_line_spri->SetPos2(m_x, m_y + 100);
	m_p_hit_line_spri->SetElement(4);		//属性を4にする
	m_p_hit_line_spri->SetInvisible(false);	//無敵モード無効
}

CSPRI::~CSPRI()
{

}

void CSPRI::Action()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);
	CTank* tank = (CTank*)TaskSystem::GetObj(TANK);

	//当たり判定位置の更新
	m_p_hit_line_spri->SetPos1(m_x + ground->GetScroll(), m_y);
	m_p_hit_line_spri->SetPos2(m_x + ground->GetScroll(), m_y + 100);

	//クリア画面が表示されたら
	if (m_CrearCnt == true)
	{
		//エンターキーが押されたら
		if (Input::KeyPush(VK_RETURN) == true)
		{
			//破棄
			if (g_key_flag)
			{
				g_SceneNumber = RESULT;
				g_clearlist = true;
				g_key_flag = false;
				g_TankRemaining = false;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_spri->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_spri->GetHitData()[i]->GetElement() == 0)
			{
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
	if (m_ani_time5 > 1300 && m_ani_time5 <=1310 && m_sy==230)
	{
		m_vy = -8.0f;
		m_CrearCnt = true;
	}
	else if (m_ani_time5 > 1400 && m_ani_time5 <= 1410 && m_sy == 230)
	{
		m_vy = -8.0f;
	}
	else if (m_ani_time5 >= 1411)
	{
		m_ani_time5 = 1200;
	}
		m_vy += 9.8 / (16.0f);


		m_sy += m_vy;
	if (m_sy > 230) { m_sy = 230; m_vy = 0.0f; }

}

void CSPRI::Draw()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);
	CTank* tank = (CTank*)TaskSystem::GetObj(TANK);

	//クリア画面表示
	if (m_CrearCnt == true)
	{
		Draw::Draw2D(63, 300, 200);
	}

	//水表示
	Draw::Draw2D(48, m_water_x + ground->GetScroll(), m_water_y, 1.6, 1.4);

	//波の表示(後ろ)
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
		Draw::Draw2D(36, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 20)
	{
		Draw::Draw2D(37, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 30)
	{
		Draw::Draw2D(38, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 40)
	{
		Draw::Draw2D(39, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 50)
	{
		Draw::Draw2D(40, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 60)
	{
		Draw::Draw2D(41, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 70)
	{
		Draw::Draw2D(42, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 80)
	{
		Draw::Draw2D(43, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 90)
	{
		Draw::Draw2D(44, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 100)
	{
		Draw::Draw2D(45, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 110)
	{
		Draw::Draw2D(46, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}

	//波の表示(前)
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
		Draw::Draw2D(25, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 10)
	{
		Draw::Draw2D(26, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 15)
	{
		Draw::Draw2D(27, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 20)
	{
		Draw::Draw2D(28, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 25)
	{
		Draw::Draw2D(29, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 30)
	{
		Draw::Draw2D(30, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 35)
	{
		Draw::Draw2D(31, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 40)
	{
		Draw::Draw2D(32, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 45)
	{
		Draw::Draw2D(33, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 50)
	{
		Draw::Draw2D(34, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 55)
	{
		Draw::Draw2D(35, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
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

	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_spri->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_spri->GetHitData()[i]->GetElement() == 0)
			{
				if (m_move1 >= 120)
				{
					m_ani_time4++;
					//m_ani_time5++;

					if (m_ani_time4 < 200)//スプリンクラー前で主人公が立ち止まる
					{
						Draw::Draw2D(0, m_wave_x + ground->GetScroll() - 50 + m_move1, m_wave_y - 10, 1, 1);
					}
					else if (m_ani_time4 > 200 && m_ani_time4 < 300)//ホースをつなげる
					{
						Draw::Draw2D(6, m_wave_x + ground->GetScroll() - 50 + m_move1, m_wave_y - 10, 1, 1);//しゃがむ
					}
					else if (m_ani_time4 > 300)//ホースを付け終わり再び主人公静止
					{
						Draw::Draw2D(50, m_wave_x - 36 + ground->GetScroll() - 50 + m_move1, 300, 1, 1);
						Draw::Draw2D(77, m_wave_x - 8 + ground->GetScroll() + m_move1, 307, 1, 1);
						
						if (m_sy <=200)
						{
							Draw::Draw2D(9, m_wave_x + ground->GetScroll() - 50 + m_move1, m_sy - 10, 1, 1);//ジャンプ
						}
						else
						{
							Draw::Draw2D(72, m_wave_x + ground->GetScroll() - 50 + m_move1, m_sy - 10, 1, 1);
						}

						if (m_ani_time4 >= 460)
						{
							m_ani_time5++;
							m_move2++;
							//Draw::Draw2D(0, m_wave_x + ground->GetScroll() - 50 + m_move1, m_sy - 10, 1, 1);
							if (tank->GetWater_Remaining() > 0)
							{
								if (m_move2 <= 10)//スプリンクラーから水が出る
								{
									Draw::Draw2D(51, m_wave_x + ground->GetScroll() + 60 + m_move1, m_wave_y, 1, 1);
								}
								else if (m_move2 >= 11 && m_move2 < 20)
								{
									Draw::Draw2D(51, m_wave_x + ground->GetScroll() + 97 + m_move1, m_wave_y + 2, -1, 1);
								}
								else
								{
									m_move2 = 0;
								}
							}

						}
					}
				}
				
				else
				{
					m_move1++;

					if (m_ani_time3 < 10)
					{
						Draw::Draw2D(2, m_wave_x + ground->GetScroll() - 50 + m_move1, m_wave_y - 10, 1, 1);
					}
					else if (m_ani_time3 < 20)
					{
						Draw::Draw2D(7, m_wave_x + ground->GetScroll() - 50 + m_move1, m_wave_y - 10, 1,1);
					}
					else if (m_ani_time3 < 30)
					{
						Draw::Draw2D(0, m_wave_x + ground->GetScroll() - 50 + m_move1, m_wave_y - 10, 1,1);
					}
				}
			}
		}
	}

	//花表示
	if (g_TankRemaining >= 80)
	{
		Draw::Draw2D(68, m_fx, m_fy);  //Sランク
	}
	else if (g_TankRemaining >= 70)
	{
		Draw::Draw2D(67, m_fx, m_fy);  //Aランク
	}
	else if (g_TankRemaining >= 50)
	{
		Draw::Draw2D(66, m_fx, m_fy);  //Bランク
	}
	else if (g_TankRemaining >= 30)
	{
		Draw::Draw2D(65, m_fx, m_fy);  //Cランク
	}
	else if (g_TankRemaining >=10)
	{
		Draw::Draw2D(64, m_fx, m_fy);  //Dランク
	}

	/*if (m_ani_time3 >= 29)
	{
		m_ani_time3 = 0;
	}
	else
	{
		m_ani_time3++;
	}*/

	//Sprinklerに近づいたらアイコンを出す
	/*for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_spri->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_spri->GetHitData()[i]->GetElement() == 0)
			{	
				if (m_ani_time3 < 10)
				{
					Draw::Draw2D(0, m_x1 + ground->GetScroll(), m_y1-12, 1, 1);
				}
				else if (m_ani_time3 < 20)
				{
					Draw::Draw2D(2, m_x1 + ground->GetScroll(), m_y1-12, 1, 1);
				}
				else if (m_ani_time3 < 30)
				{
					Draw::Draw2D(7, m_x1 + ground->GetScroll(), m_y1-12, 1, 1);
				}
			}
		}
	}*/

	//Draw::Draw2D(21, a, m_y);
}