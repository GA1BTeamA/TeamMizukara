//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Hero.h"

extern int g_SceneNumber;
extern bool g_key_flag;

//コンストラクタ
CHero::CHero()
	:m_x(200),m_y(300)
	,m_vx(0.0f),m_vy(0.0f)
	, m_direc(RIGHT), m_down(false), m_IsMenu(false),
	m_ani_time (0)
{
	m_name = PLAYER;

	//主人公ヒットライン作成(左)
	m_p_hit_line_hero[0] = Collision::HitLineInsert(this);
	//作成したヒットラインの値を設定
	m_p_hit_line_hero[0]->SetPos1(m_x, m_y);
	m_p_hit_line_hero[0]->SetPos2(m_x, m_y+100);
	m_p_hit_line_hero[0]->SetElement(0);		//属性を0にする
	m_p_hit_line_hero[0]->SetInvisible(false);	//無敵モード無効

	//主人公ヒットライン作成(右)
	m_p_hit_line_hero[1] = Collision::HitLineInsert(this);
	//作成したヒットラインの値を設定
	m_p_hit_line_hero[1]->SetPos1(m_x+60, m_y);
	m_p_hit_line_hero[1]->SetPos2(m_x+60, m_y + 100);
	m_p_hit_line_hero[1]->SetElement(0);		//属性を0にする
	m_p_hit_line_hero[1]->SetInvisible(false);	//無敵モード無効

	//上ヒットライン作成
	m_p_hit_line_hero[2] = Collision::HitLineInsert(this);
	//作成したヒットラインの値を設定
	m_p_hit_line_hero[2]->SetPos1(m_x, m_y);
	m_p_hit_line_hero[2]->SetPos2(m_x + 60, m_y);
	m_p_hit_line_hero[2]->SetElement(0);		//属性を0にする
	m_p_hit_line_hero[2]->SetInvisible(false);	//無敵モード無効
	
	//主人公コピーヒットライン作成(左)
	m_p_hit_line_hero_copy[0] = m_p_hit_line_hero[0];
	
	//主人公コピーヒットライン作成(右)
	m_p_hit_line_hero_copy[1] = m_p_hit_line_hero[1];
}

CHero::~CHero()
{
}

void CHero::Action()
{
	////テスト
	//float a, b;
	//CCollision::LineCrossPoint(0, 0, 10, 10, 0, 5, 10, 5, &a, &b);
	//int aa = 0;
	//aa++;

	//メニュー
	if (Input::KeyPush('Q'))
	{
		if (m_menu_key_flag)
		{
			//メニューオブジェクトを生成
			if (m_IsMenu == false)
			{
				menu = new CMenu();
				menu->m_priority = 100;
				TaskSystem::InsertObj(menu);
				m_IsMenu = true;
			}
			//メニューオブジェクトを破棄
			else
			{

				//オブジェクト取得
				CMenu* menu = (CMenu*)TaskSystem::GetObj(MENU);
				if (menu != nullptr)
				{
					menu->is_delete = true;
					m_IsMenu = false;
				}
			}
			m_menu_key_flag = false;
		}
	}
	else m_menu_key_flag = true;

	if (m_IsMenu == false)
	{
		//デバッグ用
		/*if (Input::KeyPush(VK_UP))
		{
			m_y -= 5.0f;

		}

		if (Input::KeyPush(VK_DOWN))
		{
			m_y += 5.0f;

		}*/

	//謎の生成--------------
	//	CObjGround ground;
	//----------------------


		//地面に当たったら、
		for (int i = 0; i < 10; i++)
		{
			//if (m_p_hit_line[0]->GetHitData()[i] != nullptr|| m_p_hit_line[1]->GetHitData()[i] != nullptr)
			//{
			if (m_p_hit_line_hero_copy[0]->GetHitData()[i] == nullptr)
				continue;

			if (m_p_hit_line_hero_copy[1]->GetHitData()[i] == nullptr)
				continue;

			if (m_p_hit_line_hero_copy[0]->GetHitData()[i]->GetElement() == 1||
				m_p_hit_line_hero_copy[1]->GetHitData()[i]->GetElement() == 1)
			{
				CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);
				if (ground != nullptr)
				{
					m_y = ground->GetGY() - 100;
					//m_y = 300;
					m_vy = 0;
					if (Input::KeyPush(VK_SPACE) == true)
					{
						if (m_down == false)
						{
							m_vy = -8;
						}
					}
				}
				//else if (m_p_hit_line->GetElement() == 1)
				//{
				//	m_x-=60
				//}
			}
		}

		//リザルト画面にいく処理
		//if (m_x + 60 >= 800)
		//{
		//	g_SceneNumber = RESULT;
		//	is_delete = true;
		//	g_key_flag = false;
		//}

		//if (m_p_hit_line->GetHitData()[1] != nullptr)
		//{
		//	m_x -= 1.0f;
		//}

		//左キーで移動
		if (Input::KeyPush(VK_LEFT))
		{
			if (Input::KeyPush('V'))
			{
				m_x -= 7.5f;//Vキーでダッシュ
			}
			else
			{
				m_x -= 5.0f;
			}
			m_direc = LEFT;
		}
		//右キーで移動
		else if (Input::KeyPush(VK_RIGHT))
		{
			if (Input::KeyPush('V'))
			{
				m_x += 7.5f;//Vキーでダッシュ
			}
			else
			{
				m_x += 5.0f;
			}
			m_direc = RIGHT;
		}

		//自由落下運動
		m_vy += 9.8 / (16.0f);

		m_y += m_vy;

		//当たり判定の位置更新
		m_p_hit_line_hero[0]->SetPos1(m_x, m_y);
		m_p_hit_line_hero[0]->SetPos2(m_x, m_y + 100);
		m_p_hit_line_hero[1]->SetPos1(m_x + 60, m_y);
		m_p_hit_line_hero[1]->SetPos2(m_x + 60, m_y + 100);
		m_p_hit_line_hero[2]->SetPos1(m_x, m_y);
		m_p_hit_line_hero[2]->SetPos2(m_x + 60, m_y);
		m_p_hit_line_hero_copy[0]->SetPos1(m_x, m_y);
		m_p_hit_line_hero_copy[0]->SetPos2(m_x, m_y + 100);
		m_p_hit_line_hero_copy[1]->SetPos1(m_x + 60, m_y);
		m_p_hit_line_hero_copy[1]->SetPos2(m_x + 60, m_y + 100);
	}

	//アニメーション
	if (Input::KeyPush(VK_RIGHT) || Input::KeyPush(VK_LEFT))
	{
		m_ani_time++;
		if (m_ani_time >= 24)
		{
			m_ani_time = 0;
		}
	}
	else 
    {
		m_ani_time = 0;
	}


}

void CHero::Draw()
{
	//描画
	if (m_IsMenu)
	{
		if (m_direc == RIGHT)
		{
				Draw::Draw2D(7, m_x, m_y);
		}
		else if (m_direc == LEFT)
		{
				Draw::Draw2D(8, m_x, m_y);
		}
	}
	else 
	{
		if (Input::KeyPush(VK_LEFT))
		{
			if (m_ani_time <= 6) {
				Draw::Draw2D(3, m_x, m_y);
			}
			else if (m_ani_time <= 12) {
				Draw::Draw2D(1, m_x, m_y);
			}
			else if (m_ani_time <= 18) {
				Draw::Draw2D(8, m_x, m_y);
			}
			else {
				Draw::Draw2D(1, m_x, m_y);
			}
		}
		else if (Input::KeyPush(VK_RIGHT))
		{
			if (m_ani_time <= 6) {
				Draw::Draw2D(2, m_x, m_y);
			}
			else if (m_ani_time <= 12) {
				Draw::Draw2D(0, m_x, m_y);
			}
			else if (m_ani_time <= 18) {
				Draw::Draw2D(7, m_x, m_y);
			}
			else {
				Draw::Draw2D(0, m_x, m_y);
			}
		}
		else if (Input::KeyPush('X'))
		{
			Draw::Draw2D(0, m_x, m_y);
		}
		else if (Input::KeyPush('C'))
		{
			Draw::Draw2D(0, m_x, m_y);
		}
		/*else if (Input::KeyPush(VK_SPACE))
		{
			Draw::Draw2D(6, m_x, m_y);
		}*/
		else if (m_direc == RIGHT)
		{
			Draw::Draw2D(0, m_x, m_y);
		}
		else if (m_direc == LEFT)
		{
			Draw::Draw2D(1, m_x, m_y);
		}

		/*if (RIGHT || LEFT) {
			if (m_ani_time <= 6) {
				Draw::Draw2D(7, m_x, m_y);
			}
			else {
				Draw::Draw2D(8, m_x, m_y);
			}
		}*/
		//if (m_p_hit_line->GetHitData()[0]!=nullptr)
		//{
		//	Draw::Draw2D(6, m_x, m_y);
		//}
	}
}