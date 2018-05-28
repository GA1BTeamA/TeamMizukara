//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjGround2.h"
#include "ObjGround.h"

//コンストラクタ
ObjGround2::ObjGround2()
	:m_gx(0), m_gy(0), m_scroll(0.0f)
{
	m_name = GROUND2;

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[0] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[0]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[1] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[1]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[2] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[2]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[3] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[3]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[4] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[4]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[5] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[5]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[6] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[6]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[7] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[7]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[8] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[8]->Set4direc(HIT_LEFT);

	m_p_hit_line_ground2[0]->SetPos1(m_scroll + 0, m_gy + 400);  //最初
	m_p_hit_line_ground2[0]->SetPos2(m_scroll + /*274*/494, m_gy + 400);
	m_p_hit_line_ground2[1]->SetPos1(m_scroll + 550, m_gy + 400);  //0段目
	m_p_hit_line_ground2[1]->SetPos2(m_scroll + 1000, m_gy + 400);
	m_p_hit_line_ground2[2]->SetPos1(m_scroll + 602, m_gy + 374);  //1段目
	m_p_hit_line_ground2[2]->SetPos2(m_scroll + 700, m_gy + 374);
	m_p_hit_line_ground2[3]->SetPos1(m_scroll + 602, m_gy + 400);  //0と1間
	m_p_hit_line_ground2[3]->SetPos2(m_scroll + 602, m_gy + 374);
	m_p_hit_line_ground2[4]->SetPos1(m_scroll + 627, m_gy + 348);  //2段目
	m_p_hit_line_ground2[4]->SetPos2(m_scroll + 700, m_gy + 348);
	m_p_hit_line_ground2[5]->SetPos1(m_scroll + 627, m_gy + 374);  //1と2の間
	m_p_hit_line_ground2[5]->SetPos2(m_scroll + 627, m_gy + 348);
	m_p_hit_line_ground2[6]->SetPos1(m_scroll + 652, m_gy + 322);  //3段目
	m_p_hit_line_ground2[6]->SetPos2(m_scroll + 700, m_gy + 322);
	m_p_hit_line_ground2[7]->SetPos1(m_scroll + 652, m_gy + 348);  //2と3の間
	m_p_hit_line_ground2[7]->SetPos2(m_scroll + 652, m_gy + 322);
	m_p_hit_line_ground2[8]->SetPos1(m_scroll + 700, m_gy + 322);  //3段目反対側の壁
	m_p_hit_line_ground2[8]->SetPos2(m_scroll + 700, m_gy + 400);

	for (int i = 0; i < 9; i++) {
		m_p_hit_line_ground2[i]->SetElement(1);		//属性を1にする
		m_p_hit_line_ground2[i]->SetInvisible(false);	//無敵モード無効
		m_p_hit_line_ground2[i]->SetAngle();
	}
}

//デストラクタ
ObjGround2::~ObjGround2()
{
	
}

//アクション
void ObjGround2::Action()
{
	//位置更新
	m_p_hit_line_ground2[0]->SetPos1(m_scroll + 0, m_gy + 400);  //最初
	m_p_hit_line_ground2[0]->SetPos2(m_scroll + /*274*/494, m_gy + 400);
	m_p_hit_line_ground2[1]->SetPos1(m_scroll + 550, m_gy + 400);  //0段目
	m_p_hit_line_ground2[1]->SetPos2(m_scroll + 1000, m_gy + 400);
	m_p_hit_line_ground2[2]->SetPos1(m_scroll + 602, m_gy + 374);  //1段目
	m_p_hit_line_ground2[2]->SetPos2(m_scroll + 700, m_gy + 374);
	m_p_hit_line_ground2[3]->SetPos1(m_scroll + 602, m_gy + 400);  //0と1間
	m_p_hit_line_ground2[3]->SetPos2(m_scroll + 602, m_gy + 374);
	m_p_hit_line_ground2[4]->SetPos1(m_scroll + 627, m_gy + 348);  //2段目
	m_p_hit_line_ground2[4]->SetPos2(m_scroll + 700, m_gy + 348);
	m_p_hit_line_ground2[5]->SetPos1(m_scroll + 627, m_gy + 374);  //1と2の間
	m_p_hit_line_ground2[5]->SetPos2(m_scroll + 627, m_gy + 348);
	m_p_hit_line_ground2[6]->SetPos1(m_scroll + 652, m_gy + 322);  //3段目
	m_p_hit_line_ground2[6]->SetPos2(m_scroll + 700, m_gy + 322);
	m_p_hit_line_ground2[7]->SetPos1(m_scroll + 652, m_gy + 348);  //2と3の間
	m_p_hit_line_ground2[7]->SetPos2(m_scroll + 652, m_gy + 322);
	m_p_hit_line_ground2[8]->SetPos1(m_scroll + 700, m_gy + 322);  //3段目反対側の壁
	m_p_hit_line_ground2[8]->SetPos2(m_scroll + 700, m_gy + 400);
}

//ドロー
void ObjGround2::Draw()
{
	//ステージ2地面描画
	Draw::Draw2D(69, m_scroll, 0);

	//Draw::Draw2D(58, 635, 319);
}
