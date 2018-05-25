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
	m_p_hit_line_ground2[3]->Set4direc(HIT_TOP);

	m_p_hit_line_ground2[0]->SetPos1(m_scroll + 0, m_gy + 400);
	m_p_hit_line_ground2[0]->SetPos2(m_scroll + 494, m_gy + 400);
	m_p_hit_line_ground2[1]->SetPos1(m_scroll + 550, m_gy + 400);
	m_p_hit_line_ground2[1]->SetPos2(m_scroll + 1000, m_gy + 400);
	m_p_hit_line_ground2[2]->SetPos1(m_scroll + 583, m_gy + 374);
	m_p_hit_line_ground2[2]->SetPos2(m_scroll + 609, m_gy + 374);
	m_p_hit_line_ground2[3]->SetPos1(m_scroll + 583, m_gy + 374);
	m_p_hit_line_ground2[3]->SetPos2(m_scroll + 609, m_gy + 374);

	for (int i = 0; i < 4; i++) {
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
	m_p_hit_line_ground2[2]->SetPos1(m_scroll + 600, m_gy + 374);  //1段目
	m_p_hit_line_ground2[2]->SetPos2(m_scroll + 710, m_gy + 374);
	m_p_hit_line_ground2[3]->SetPos1(m_scroll + 600, m_gy + 400);  //0と1間
	m_p_hit_line_ground2[3]->SetPos2(m_scroll + 600, m_gy + 374);
}

//ドロー
void ObjGround2::Draw()
{
	//ステージ2地面描画
	Draw::Draw2D(69,0, 0);

	Draw::Draw2D(58, 693, 374);
}
