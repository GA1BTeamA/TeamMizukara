//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjGround.h"
#include "Hero.h"
extern int g_SceneNumber;

//コンストラクタ
CObjGround::CObjGround()
	:m_gx(0), m_gy(0), m_scroll(0.0f)
{
	m_name = GROUND;

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[0] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[0]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[1] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[1]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[2] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[2]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[3] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[3]->Set4direc(HIT_LEFT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[4] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[4]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[5] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[5]->Set4direc(HIT_LEFT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[6] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[6]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[7] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[7]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[8] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[8]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[9] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[9]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[10] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[10]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[11] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[11]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[12] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[12]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[13] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[13]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[14] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[14]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[15] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[15]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[16] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[16]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[17] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[17]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[18] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[18]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[19] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[19]->Set4direc(HIT_LEFT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground[20] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[20]->Set4direc(HIT_TOP);

	m_p_hit_line_ground[0]->SetPos1(m_scroll + 0, m_gy + 0);
	m_p_hit_line_ground[0]->SetPos2(m_scroll + 90, m_gy + 0);
	m_p_hit_line_ground[1]->SetPos1(m_scroll + 90, m_gy + 0);
	m_p_hit_line_ground[1]->SetPos2(m_scroll + 90, m_gy + 500);
	m_p_hit_line_ground[2]->SetPos1(m_scroll + 0, m_gy + 400);
	m_p_hit_line_ground[2]->SetPos2(m_scroll + 600, m_gy + 400);
	m_p_hit_line_ground[3]->SetPos1(m_scroll + 600, m_gy + 320);
	m_p_hit_line_ground[3]->SetPos2(m_scroll + 600, m_gy + 400);
	m_p_hit_line_ground[4]->SetPos1(m_scroll + 600, m_gy + 320);
	m_p_hit_line_ground[4]->SetPos2(m_scroll + 900, m_gy + 320);
	m_p_hit_line_ground[5]->SetPos1(m_scroll + 900, m_gy + 320);
	m_p_hit_line_ground[5]->SetPos2(m_scroll + 900, m_gy + 237);
	m_p_hit_line_ground[6]->SetPos1(m_scroll + 900, m_gy + 237);
	m_p_hit_line_ground[6]->SetPos2(m_scroll + 1307 - 10, m_gy + 237);
	m_p_hit_line_ground[7]->SetPos1(m_scroll + 1307 - 10, m_gy + 264);
	m_p_hit_line_ground[7]->SetPos2(m_scroll + 1307 - 10, m_gy + 237);
	m_p_hit_line_ground[8]->SetPos1(m_scroll + 1207 - 10, m_gy + 264);
	m_p_hit_line_ground[8]->SetPos2(m_scroll + 1333 - 10, m_gy + 264);
	m_p_hit_line_ground[9]->SetPos1(m_scroll + 1333 - 10, m_gy + 291);
	m_p_hit_line_ground[9]->SetPos2(m_scroll + 1333 - 10, m_gy + 264);
	m_p_hit_line_ground[10]->SetPos1(m_scroll + 1233 - 10, m_gy + 291);
	m_p_hit_line_ground[10]->SetPos2(m_scroll + 1359 - 10, m_gy + 291);
	m_p_hit_line_ground[11]->SetPos1(m_scroll + 1359 - 10, m_gy + 318);
	m_p_hit_line_ground[11]->SetPos2(m_scroll + 1359 - 10, m_gy + 291);
	m_p_hit_line_ground[12]->SetPos1(m_scroll + 1259 - 10, m_gy + 318);
	m_p_hit_line_ground[12]->SetPos2(m_scroll + 1385 - 10, m_gy + 318);
	m_p_hit_line_ground[13]->SetPos1(m_scroll + 1385 - 10, m_gy + 318);
	m_p_hit_line_ground[13]->SetPos2(m_scroll + 1385 - 10, m_gy + 346);
	m_p_hit_line_ground[14]->SetPos1(m_scroll + 1285 - 10, m_gy + 346);
	m_p_hit_line_ground[14]->SetPos2(m_scroll + 1411 - 10, m_gy + 346);
	m_p_hit_line_ground[15]->SetPos1(m_scroll + 1411 - 10, m_gy + 346);
	m_p_hit_line_ground[15]->SetPos2(m_scroll + 1411 - 10, m_gy + 373);
	m_p_hit_line_ground[16]->SetPos1(m_scroll + 1311 - 10, m_gy + 373);
	m_p_hit_line_ground[16]->SetPos2(m_scroll + 1437 - 10, m_gy + 373);
	m_p_hit_line_ground[17]->SetPos1(m_scroll + 1437 - 10, m_gy + 373);
	m_p_hit_line_ground[17]->SetPos2(m_scroll + 1437 - 10, m_gy + 400);
	m_p_hit_line_ground[18]->SetPos1(m_scroll + 1337 - 10, m_gy + 400);
	m_p_hit_line_ground[18]->SetPos2(m_scroll + 2022, m_gy + 400);
	m_p_hit_line_ground[19]->SetPos1(m_scroll + 2022, m_gy + 400);
	m_p_hit_line_ground[19]->SetPos2(m_scroll + 2022, m_gy + 320);
	m_p_hit_line_ground[20]->SetPos1(m_scroll + 2022, m_gy + 320);
	m_p_hit_line_ground[20]->SetPos2(m_scroll + 2400, m_gy + 320);


	for (int i = 0; i < 21; i++) {
		m_p_hit_line_ground[i]->SetElement(1);		//属性を1にする
		m_p_hit_line_ground[i]->SetInvisible(false);	//無敵モード無効
		m_p_hit_line_ground[i]->SetAngle();
	}

}

//デストラクタ
CObjGround::~CObjGround()
{

}

//アクション
void CObjGround::Action()
{
	////リザルト画面になったら破棄
	//if (g_SceneNumber == RESULT)
	//{
	//	is_delete = true;
	//}

	/*CHero* hero = (CHero*)TaskSystem::GetObj(PLAYER);
	float m_x = hero->GetX();
	float m_y = hero->GetY();

	/*if (hero != nullptr)
	{
	hero->is_delete = true;
	//m_IsHero = false;
	}*/

	//m_scroll = -3.0f;//スクロール


	/*	if (Input::KeyPush(VK_RIGHT)) {
	//前方スクロールライン
	if (m_x > 350)
	{
	else
	{
	hero->SetX(350);   //主人公が指定領域を超えないように

	if (Input::KeyPush('V')) //ダッシュしてる時のスクロール
	{
	m_scroll -= hero->GetDashX();   //主人公が本来動くべき値をm_scrollに加える
	//地面判定にスクロール反映
	m_gx -= hero->GetDashX();
	}
	else  //歩いている時のスクロール
	{
	m_scroll -= hero->GetMoveX();  //主人公が本来動くべき値をm_scrollに加える
	//地面判定にスクロール反映
	m_gx -= hero->GetMoveX();
	}
	}
	}
	}
	else if (Input::KeyPush(VK_LEFT)) {
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
	//地面判定にスクロール反映
	m_gx += hero->GetDashX();
	}
	else  //歩いている時のスクロール
	{
	m_scroll += hero->GetMoveX();   //主人公が本来動くべき値をm_scrollに加える
	//地面判定にスクロール反映
	m_gx += hero->GetMoveX();
	}
	}
	}
	}*/

	//端っこ来たらステージ端見えないようにする
	if (m_scroll <= -1600)
	{
		m_scroll = -1600.0f;
	}
	//端っこ来たらステージ端見えないようにする
	if (m_scroll >= 0)
	{
		m_scroll = 0.0f;
	}


	//位置更新
	m_p_hit_line_ground[0]->SetPos1(m_scroll + 0, m_gy + 0);
	m_p_hit_line_ground[0]->SetPos2(m_scroll + 90, m_gy + 0);
	m_p_hit_line_ground[1]->SetPos1(m_scroll + 90, m_gy + 0);
	m_p_hit_line_ground[1]->SetPos2(m_scroll + 90, m_gy + 500);
	m_p_hit_line_ground[2]->SetPos1(m_scroll + 0, m_gy + 400);
	m_p_hit_line_ground[2]->SetPos2(m_scroll + 600, m_gy + 400);
	m_p_hit_line_ground[3]->SetPos1(m_scroll + 600, m_gy + 320);
	m_p_hit_line_ground[3]->SetPos2(m_scroll + 600, m_gy + 400);
	m_p_hit_line_ground[4]->SetPos1(m_scroll + 600, m_gy + 320);
	m_p_hit_line_ground[4]->SetPos2(m_scroll + 900, m_gy + 320);
	m_p_hit_line_ground[5]->SetPos1(m_scroll + 900, m_gy + 320);
	m_p_hit_line_ground[5]->SetPos2(m_scroll + 900, m_gy + 237);
	m_p_hit_line_ground[6]->SetPos1(m_scroll + 900, m_gy + 237);
	m_p_hit_line_ground[6]->SetPos2(m_scroll + 1307 - 10, m_gy + 237);
	m_p_hit_line_ground[7]->SetPos1(m_scroll + 1307 - 10, m_gy + 264);
	m_p_hit_line_ground[7]->SetPos2(m_scroll + 1307 - 10, m_gy + 237);
	m_p_hit_line_ground[8]->SetPos1(m_scroll + 1207 - 10, m_gy + 264);
	m_p_hit_line_ground[8]->SetPos2(m_scroll + 1333 - 10, m_gy + 264);
	m_p_hit_line_ground[9]->SetPos1(m_scroll + 1333 - 10, m_gy + 291);
	m_p_hit_line_ground[9]->SetPos2(m_scroll + 1333 - 10, m_gy + 264);
	m_p_hit_line_ground[10]->SetPos1(m_scroll + 1233 - 10, m_gy + 291);
	m_p_hit_line_ground[10]->SetPos2(m_scroll + 1359 - 10, m_gy + 291);
	m_p_hit_line_ground[11]->SetPos1(m_scroll + 1359 - 10, m_gy + 318);
	m_p_hit_line_ground[11]->SetPos2(m_scroll + 1359 - 10, m_gy + 291);
	m_p_hit_line_ground[12]->SetPos1(m_scroll + 1259 - 10, m_gy + 318);
	m_p_hit_line_ground[12]->SetPos2(m_scroll + 1385 - 10, m_gy + 318);
	m_p_hit_line_ground[13]->SetPos1(m_scroll + 1385 - 10, m_gy + 318);
	m_p_hit_line_ground[13]->SetPos2(m_scroll + 1385 - 10, m_gy + 346);
	m_p_hit_line_ground[14]->SetPos1(m_scroll + 1285 - 10, m_gy + 346);
	m_p_hit_line_ground[14]->SetPos2(m_scroll + 1411 - 10, m_gy + 346);
	m_p_hit_line_ground[15]->SetPos1(m_scroll + 1411 - 10, m_gy + 346);
	m_p_hit_line_ground[15]->SetPos2(m_scroll + 1411 - 10, m_gy + 373);
	m_p_hit_line_ground[16]->SetPos1(m_scroll + 1311 - 10, m_gy + 373);
	m_p_hit_line_ground[16]->SetPos2(m_scroll + 1437 - 10, m_gy + 373);
	m_p_hit_line_ground[17]->SetPos1(m_scroll + 1437 - 10, m_gy + 373);
	m_p_hit_line_ground[17]->SetPos2(m_scroll + 1437 - 10, m_gy + 400);
	m_p_hit_line_ground[18]->SetPos1(m_scroll + 1337 - 10, m_gy + 400);
	m_p_hit_line_ground[18]->SetPos2(m_scroll + 2022, m_gy + 400);
	m_p_hit_line_ground[19]->SetPos1(m_scroll + 2022, m_gy + 400);
	m_p_hit_line_ground[19]->SetPos2(m_scroll + 2022, m_gy + 320);
	m_p_hit_line_ground[20]->SetPos1(m_scroll + 2022, m_gy + 320);
	m_p_hit_line_ground[20]->SetPos2(m_scroll + 2400, m_gy + 320);

}

//ドロー
void CObjGround::Draw()
{

	//ステージ1地面描画
	Draw::Draw2D(22, m_scroll, 0);
}