//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Hero.h"

extern int g_SceneNumber;
extern bool g_key_flag;

//コンストラクタ
CHero::CHero()
	:m_x(200),m_y(300)
	, m_copy_x(200), m_copy_y(300)
	,m_vx(0.0f),m_vy(0.0f)
	, m_direc(RIGHT), m_down(false), m_IsMenu(false)
	,m_ani_time (0)
	, move_x(5.0f)
	, move_dash_x(7.5f)
{
	m_name = PLAYER;

	m_point_position[0].x = 0;
	m_point_position[0].y = 0;
	m_point_position[1].x = 60;
	m_point_position[1].y = 0;
	m_point_position[2].x = 60;
	m_point_position[2].y = 100;
	m_point_position[3].x = 0;
	m_point_position[3].y = 100;

	//主人公ヒットライン作成し、値を設定(左)
	m_p_hit_line_hero[0] = Collision::HitLineInsert(this);
	m_p_hit_line_hero[0]->SetPos1(m_x, m_y);
	m_p_hit_line_hero[0]->SetPos2(m_x, m_y+100);

	//主人公ヒットライン作成し、値を設定(右)
	m_p_hit_line_hero[1] = Collision::HitLineInsert(this);
	m_p_hit_line_hero[1]->SetPos1(m_x+60, m_y);
	m_p_hit_line_hero[1]->SetPos2(m_x+60, m_y + 100);

	//主人公ヒットライン作成し、値を設定(上)
	m_p_hit_line_hero[2] = Collision::HitLineInsert(this);
	m_p_hit_line_hero[2]->SetPos1(m_x, m_y);
	m_p_hit_line_hero[2]->SetPos2(m_x + 60, m_y);
	
	//主人公ヒットライン作成し、値を設定(下)
	m_p_hit_line_hero[3] = Collision::HitLineInsert(this);
	m_p_hit_line_hero[3]->SetPos1(m_x, m_y+100);
	m_p_hit_line_hero[3]->SetPos2(m_x + 60, m_y+100);

	for (int i = 0; i < 4; i++) {
		m_p_hit_line_hero[i]->SetElement(0);		//属性を0にする
		m_p_hit_line_hero[i]->SetInvisible(false);	//無敵モード無効
	}

	//主人公ヒットラインのコピーを作成し、値を設定(左)
	m_p_hit_line_hero_copy[0] = Collision::HitLineInsert(this);
	m_p_hit_line_hero_copy[0]->SetPos1(m_x, m_y);
	m_p_hit_line_hero_copy[0]->SetPos2(m_x, m_y + 100);

	//主人公ヒットラインのコピーを作成し、値を設定(右)
	m_p_hit_line_hero_copy[1] = Collision::HitLineInsert(this);
	m_p_hit_line_hero_copy[1]->SetPos1(m_x + 60, m_y);
	m_p_hit_line_hero_copy[1]->SetPos2(m_x + 60, m_y + 100);

	//主人公ヒットラインのコピーを作成し、値を設定(上)
	m_p_hit_line_hero_copy[2] = Collision::HitLineInsert(this);
	m_p_hit_line_hero_copy[2]->SetPos1(m_x, m_y);
	m_p_hit_line_hero_copy[2]->SetPos2(m_x + 60, m_y);

	//主人公ヒットラインのコピーを作成し、値を設定(下)
	m_p_hit_line_hero_copy[3] = Collision::HitLineInsert(this);
	m_p_hit_line_hero_copy[3]->SetPos1(m_x, m_y + 100);
	m_p_hit_line_hero_copy[3]->SetPos2(m_x + 60, m_y + 100);

	for (int i = 0; i < 4; i++) {
		m_p_hit_line_hero_copy[i]->SetElement(0);		//属性を0にする
		m_p_hit_line_hero_copy[i]->SetInvisible(false);	//無敵モード無効
	}
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

	//交点までが一番短い点
	float Cross_x_min = 9999.0f, Cross_y_min = 9999.0f;

	bool IsHitGround = false;//地面に当たっているか
	bool IsHitWall = false;//壁に当たっているか

	//地面に当たったら、
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//主人公の当たり判定が他の当たり判定にあたってなかったらスキップ
			if (m_p_hit_line_hero_copy[j]->GetHitData()[i] == nullptr)
				continue;

			//主人公の当たり判定に当たってたのが地面なら
			if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetElement() == 1)
			{
				if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle() == 0.0f) {
					if (j == 2 || j == 3) {
						//初期化
						m_vx = 0.0f;
					}
				}
				else {
					//初期化
					m_vy = 0.0f;
				}

				//交点変数
				float Cross_x, Cross_y;
				//初期化
				Cross_x_min = 9999.0f, Cross_y_min = 9999.0f;

				for (int k = 0; k < 4; k++)
				{
					//主人公の移動ベクトルと地面の交点を求める
					Collision::LineCrossPoint(m_x + m_point_position[k].x, m_y + m_point_position[k].y,
						m_copy_x + m_point_position[k].x, m_copy_y + m_point_position[k].y,
						m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x,
						m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y,
						m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x,
						m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y,
						&Cross_x, &Cross_y);

					//エラーが返されなかったら
					if (Cross_x != -9999.0f && Cross_y != -9999.0f)
					{
						//主人公から交点までのベクトルを取り出す
						Cross_x -= m_x + m_point_position[k].x;
						Cross_y -= m_y + m_point_position[k].y;

						//主人公から交点までのベクトルの中から一番短いものを見つける
						if (Cross_x_min > Cross_x)
						{
							Cross_x_min = Cross_x;
						}
						if (Cross_y_min > Cross_y)
						{
							Cross_y_min = Cross_y;
						}
					}
				}

				//m_y = ground->GetGY() - 100;
				//m_y = 300;
				//m_vy = 0;

				//エラーじゃなければ主人公を交点まで移動
				if (Cross_x_min != 9999.0f) {
					m_x += Cross_x_min;
					if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle() == 0.0f) {
						IsHitWall = true;
					}
					else {
						IsHitGround = true;
					}
				}
				if (Cross_y_min != 9999.0f) {
					m_y += Cross_y_min;
					if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle() == 0.0f) {
						IsHitWall = true;
					}
					else {
						IsHitGround = true;
					}
				}

				//break;
			}
		}
		//ループの最後
		if (i == 9)
		{
			//地面に当たってたらX方向に移動可
			if (IsHitGround && IsHitWall) {
				;
			}
			else if (IsHitGround) {
				m_x = m_copy_x;
			}
			else if (IsHitWall) {
				m_y = m_copy_y;
			}
			//地面に当たってなかったらXもYも移動可
			else {
				m_x = m_copy_x;
				m_y = m_copy_y;
			}
		}
	}

	//当たり判定の位置更新
	m_p_hit_line_hero[0]->SetPos1(m_x, m_y);
	m_p_hit_line_hero[0]->SetPos2(m_x, m_y + 100);
	m_p_hit_line_hero[1]->SetPos1(m_x + 60, m_y);
	m_p_hit_line_hero[1]->SetPos2(m_x + 60, m_y + 100);
	m_p_hit_line_hero[2]->SetPos1(m_x, m_y);
	m_p_hit_line_hero[2]->SetPos2(m_x + 60, m_y);
	m_p_hit_line_hero[3]->SetPos1(m_x, m_y + 100);
	m_p_hit_line_hero[3]->SetPos2(m_x + 60, m_y + 100);

	//コピーの当たり判定の位置更新
	m_p_hit_line_hero_copy[0]->SetPoint1(m_p_hit_line_hero[0]->GetPoint1());
	m_p_hit_line_hero_copy[0]->SetPoint2(m_p_hit_line_hero[0]->GetPoint2());
	m_p_hit_line_hero_copy[1]->SetPoint1(m_p_hit_line_hero[1]->GetPoint1());
	m_p_hit_line_hero_copy[1]->SetPoint2(m_p_hit_line_hero[1]->GetPoint2());
	m_p_hit_line_hero_copy[2]->SetPoint1(m_p_hit_line_hero[2]->GetPoint1());
	m_p_hit_line_hero_copy[2]->SetPoint2(m_p_hit_line_hero[2]->GetPoint2());
	m_p_hit_line_hero_copy[3]->SetPoint1(m_p_hit_line_hero[3]->GetPoint1());
	m_p_hit_line_hero_copy[3]->SetPoint2(m_p_hit_line_hero[3]->GetPoint2());


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

		//謎の生成(西浦七不思議)--------
		//	CObjGround ground;
		//------------------------------
		for (int i = 0; i < 10; i++)
		{
			if (m_p_hit_line_hero_copy[0]->GetHitData()[i] == nullptr||
				m_p_hit_line_hero_copy[1]->GetHitData()[i] == nullptr)
				continue;

			if (m_p_hit_line_hero_copy[0]->GetHitData()[i]->GetElement() == 1 ||
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

		CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

		//左キーで移動
		if (Input::KeyPush(VK_LEFT))
		{
			if (Input::KeyPush('V'))
			{
				m_x -= move_dash_x;//Vキーでダッシュ
			}
			else
			{
				m_x -= move_x;
			}
			m_direc = LEFT;
		}
		//右キーで移動
		else if (Input::KeyPush(VK_RIGHT))
		{
			if (Input::KeyPush('V'))
			{
				m_x += move_dash_x;//Vキーでダッシュ
			}
			else
			{
				m_x += move_x;
			}
			m_direc = RIGHT;
		}

		//地面に当たってたらスペースキーでジャンプ
		if (IsHitGround) {
			if (Input::KeyPush(VK_SPACE) == true)
			{
				m_vy = -8.0f;
			}
		}

		//自由落下運動
		m_vy += 9.8 / (16.0f);

		m_copy_y += m_vy;

		m_p_hit_line_hero_copy[0]->SetPos1(m_copy_x, m_copy_y);
		m_p_hit_line_hero_copy[0]->SetPos2(m_copy_x, m_copy_y + 100);
		m_p_hit_line_hero_copy[1]->SetPos1(m_copy_x + 60, m_copy_y);
		m_p_hit_line_hero_copy[1]->SetPos2(m_copy_x + 60, m_copy_y + 100);
		m_p_hit_line_hero_copy[2]->SetPos1(m_copy_x, m_copy_y);
		m_p_hit_line_hero_copy[2]->SetPos2(m_copy_x + 60, m_copy_y);
		m_p_hit_line_hero_copy[3]->SetPos1(m_copy_x, m_copy_y + 100);
		m_p_hit_line_hero_copy[3]->SetPos2(m_copy_x + 60, m_copy_y + 100);




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
	//コピーの位置更新
	m_copy_x = m_x;
	m_copy_y = m_y;
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