//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjGround.h"
#include "Hero.h"

CObjGround::CObjGround()
	:m_gx(0), m_gy(400), m_scroll(0.0f)
{
	m_name = GROUND;

	//ヒットボックス作成()
	m_p_hit_line_ground[0] = Collision::HitLineInsert(this);
	//作成したヒットボックスの値を設定
	m_p_hit_line_ground[0]->SetPos1(m_gx, m_gy);
	m_p_hit_line_ground[0]->SetPos2(m_gx+800, m_gy);
	m_p_hit_line_ground[0]->SetElement(1);		//属性を1にする
	m_p_hit_line_ground[0]->SetInvisible(false);	//無敵モード無効

	/*//ヒットボックス作成()
	m_p_hit_line[1] = Collision::HitLineInsert(this);
	//作成したヒットボックスの値を設定
	m_p_hit_line_ground[1]->SetPos1(m_gx+500, m_gy-90);
	m_p_hit_line_ground[1]->SetPos2(m_gx + 800, m_gy-90);
	m_p_hit_line_ground[1]->SetElement(1);		//属性を1にする
	m_p_hit_line_ground[1]->SetInvisible(false);	//無敵モード無効

	////ヒットボックス作成()
	//m_p_hit_line[2] = Collision::HitLineInsert(this);
	////作成したヒットボックスの値を設定
	//m_p_hit_line_ground[2]->SetPos1(m_gx + 700, m_gy - 90);
	//m_p_hit_line_ground[2]->SetPos2(m_gx + 700, m_gy);
	//m_p_hit_line_ground[2]->SetElement(1);		//属性を1にする
	//m_p_hit_line_ground[2]->SetInvisible(false);	//無敵モード無効*/

}

CObjGround::~CObjGround()
{

}

void CObjGround::Action()
{
	CHero* hero = (CHero*)TaskSystem::GetObj(PLAYER);
	float m_x = hero->GetX();
	float m_y = hero->GetY();

	/*if (hero != nullptr)
	{
		hero->is_delete = true;
		//m_IsHero = false;
	}*/

	//m_scroll = -3.0f;//スクロール

	//前方スクロールライン
	if (m_x > 350)
	{
		//端っこ来たらステージ端見えないようにする
		if (m_scroll <= -1600)
		{
			m_scroll = -1600.0f;
		}
		else
		{
			hero->SetX(350);   //主人公が指定領域を超えないように

			if (Input::KeyPush('V')) //ダッシュしてる時のスクロール
			{
				m_scroll -= hero->GetDashX();   //主人公が本来動くべき値をm_scrollに加える
			}
			else  //歩いている時のスクロール
			{
				m_scroll -= hero->GetMoveX();  //主人公が本来動くべき値をm_scrollに加える
			}
		}
	}

		//後方スクロールライン
		if (m_x < 200)
		{
			//端っこ来たらステージ端見えないようにする
			if (m_scroll >= 0)
			{
				m_scroll = 0.0f;
			}
			else
			{
				hero->SetX(200);   //主人公が指定領域を超えないように

				if (Input::KeyPush('V')) //ダッシュしてる時のスクロール
				{
					m_scroll += hero->GetDashX();   //主人公が本来動くべき値をm_scrollに加える
		
				}
				else  //歩いている時のスクロール
				{
					m_scroll += hero->GetMoveX();   //主人公が本来動くべき値をm_scrollに加える
				}
			}
	}
}

void CObjGround::Draw()
{


	Draw::Draw2D(22, m_gx+m_scroll, 0);
}