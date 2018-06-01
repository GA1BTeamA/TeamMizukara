//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjGround3.h"


//コンストラクタ
ObjGround3::ObjGround3()
	:m_gx(0), m_gy(0), m_scroll(0.0f)
{
	m_name = GROUND3;

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[0] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[0]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[1] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[1]->Set4direc(HIT_LEFT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[2] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[2]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[3] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[3]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[4] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[4]->Set4direc(HIT_LEFT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[5] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[5]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[6] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[6]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[7] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[7]->Set4direc(HIT_LEFT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[8] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[8]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[9] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[9]->Set4direc(HIT_LEFT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[10] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[10]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[11] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[11]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[12] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[12]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[13] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[13]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[14] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[14]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[15] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[15]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[16] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[16]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[17] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[17]->Set4direc(HIT_UNDER);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[18] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[18]->Set4direc(HIT_LEFT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[19] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[19]->Set4direc(HIT_LEFT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[20] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[20]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[21] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[21]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground3[22] = Collision::HitLineInsert(this);
	m_p_hit_line_ground3[22]->Set4direc(HIT_TOP);

	m_p_hit_line_ground3[0]->SetPos1(m_scroll + 0, m_gy + 400);  //最初地面
	m_p_hit_line_ground3[0]->SetPos2(m_scroll + 3300, m_gy + 400);
	m_p_hit_line_ground3[1]->SetPos1(m_scroll + 524, m_gy + 450);  //最初の箱左側
	m_p_hit_line_ground3[1]->SetPos2(m_scroll + 524, m_gy + 372);
	m_p_hit_line_ground3[2]->SetPos1(m_scroll + 524, m_gy + 372);  //最初の箱上
	m_p_hit_line_ground3[2]->SetPos2(m_scroll + 553, m_gy + 372);
	m_p_hit_line_ground3[3]->SetPos1(m_scroll + 553, m_gy + 450);  //最初の箱右側
	m_p_hit_line_ground3[3]->SetPos2(m_scroll + 553, m_gy + 372);
	m_p_hit_line_ground3[4]->SetPos1(m_scroll + 730, m_gy + 450);  //最初のコンテナ左側
	m_p_hit_line_ground3[4]->SetPos2(m_scroll + 730, m_gy + 314);
	m_p_hit_line_ground3[5]->SetPos1(m_scroll + 730, m_gy + 314);  //最初のコンテナ上
	m_p_hit_line_ground3[5]->SetPos2(m_scroll + 1479, m_gy + 314);
	m_p_hit_line_ground3[6]->SetPos1(m_scroll + 1479, m_gy + 450);  //最初のコンテナ右側
	m_p_hit_line_ground3[6]->SetPos2(m_scroll + 1479, m_gy + 314);
	m_p_hit_line_ground3[7]->SetPos1(m_scroll + 1655, m_gy + 450);  //その次のコンテナ下部分左側
	m_p_hit_line_ground3[7]->SetPos2(m_scroll + 1655, m_gy + 314);
	m_p_hit_line_ground3[8]->SetPos1(m_scroll + 1655, m_gy + 314);  //その次のコンテナ下部分上
	m_p_hit_line_ground3[8]->SetPos2(m_scroll + 2186, m_gy + 314);
	m_p_hit_line_ground3[9]->SetPos1(m_scroll + 1770, m_gy + 450);  //コンテナ山の部分左側
	m_p_hit_line_ground3[9]->SetPos2(m_scroll + 1770, m_gy + 227);
	m_p_hit_line_ground3[10]->SetPos1(m_scroll + 1770, m_gy + 227);  //コンテナ山の部分上
	m_p_hit_line_ground3[10]->SetPos2(m_scroll + 1982, m_gy + 227);
	m_p_hit_line_ground3[11]->SetPos1(m_scroll + 1982, m_gy + 450);  //コンテナ山の部分右側
	m_p_hit_line_ground3[11]->SetPos2(m_scroll + 1982, m_gy + 227);
	m_p_hit_line_ground3[12]->SetPos1(m_scroll + 1982, m_gy + 256);  //コンテナ上の階段2段目上
	m_p_hit_line_ground3[12]->SetPos2(m_scroll + 2022, m_gy + 256);
	m_p_hit_line_ground3[13]->SetPos1(m_scroll + 2022, m_gy + 450);  //コンテナ上の階段2段目右側
	m_p_hit_line_ground3[13]->SetPos2(m_scroll + 2022, m_gy + 256);
	m_p_hit_line_ground3[14]->SetPos1(m_scroll + 2186, m_gy + 450);  //コンテナ下部分右側
	m_p_hit_line_ground3[14]->SetPos2(m_scroll + 2186, m_gy + 314);
	m_p_hit_line_ground3[15]->SetPos1(m_scroll + 2022, m_gy + 285);  //コンテナ上の階段1段目上
	m_p_hit_line_ground3[15]->SetPos2(m_scroll + 2062, m_gy + 285);
	m_p_hit_line_ground3[16]->SetPos1(m_scroll + 2062, m_gy + 285);  //コンテナ上の階段1段目右側
	m_p_hit_line_ground3[16]->SetPos2(m_scroll + 2062, m_gy + 450);
	m_p_hit_line_ground3[17]->SetPos1(m_scroll + 2530, m_gy + 262);  //最終ギミック黄黒の下部分
	m_p_hit_line_ground3[17]->SetPos2(m_scroll + 2816, m_gy + 262);
	m_p_hit_line_ground3[18]->SetPos1(m_scroll + 2814, m_gy + 450);  //最終ギミック黄黒の下左部分
	m_p_hit_line_ground3[18]->SetPos2(m_scroll + 2814, m_gy + 256);
	m_p_hit_line_ground3[19]->SetPos1(m_scroll + 2530, m_gy + 262);  //最終ギミック黄黒の左部分
	m_p_hit_line_ground3[19]->SetPos2(m_scroll + 2530, m_gy + 250);
	m_p_hit_line_ground3[20]->SetPos1(m_scroll + 2530, m_gy + 250);  //最終ギミック黄黒の上(足場)部分
	m_p_hit_line_ground3[20]->SetPos2(m_scroll + 2820, m_gy + 250);
	m_p_hit_line_ground3[21]->SetPos1(m_scroll + 2820, m_gy + 450);  //最終ギミック黄黒の右部分
	m_p_hit_line_ground3[21]->SetPos2(m_scroll + 2820, m_gy + 250);
	m_p_hit_line_ground3[22]->SetPos1(m_scroll + 2817, m_gy + 319);  //ゴールの足場
	m_p_hit_line_ground3[22]->SetPos2(m_scroll + 3300, m_gy + 319);

	for (int i = 0; i < 23; i++) {
		m_p_hit_line_ground3[i]->SetElement(1);		//属性を1にする
		m_p_hit_line_ground3[i]->SetInvisible(false);	//無敵モード無効
		m_p_hit_line_ground3[i]->SetAngle();
	}
}

//デストラクタ
ObjGround3::~ObjGround3()
{

}

//アクション
void ObjGround3::Action()
{
	//端っこ来たらステージ端見えないようにする
	if (m_scroll <= -2400)
	{
		m_scroll = -2400.0f;
	}
	//端っこ来たらステージ端見えないようにする
	if (m_scroll >= 0)
	{
		m_scroll = 0.0f;
	}

	m_p_hit_line_ground3[0]->SetPos1(m_scroll + 0, m_gy + 400);  //最初地面
	m_p_hit_line_ground3[0]->SetPos2(m_scroll + 3300, m_gy + 400);
	m_p_hit_line_ground3[1]->SetPos1(m_scroll + 524, m_gy + 450);  //最初の箱左側
	m_p_hit_line_ground3[1]->SetPos2(m_scroll + 524, m_gy + 372);
	m_p_hit_line_ground3[2]->SetPos1(m_scroll + 524, m_gy + 372);  //最初の箱上
	m_p_hit_line_ground3[2]->SetPos2(m_scroll + 553, m_gy + 372);
	m_p_hit_line_ground3[3]->SetPos1(m_scroll + 553, m_gy + 450);  //最初の箱右側
	m_p_hit_line_ground3[3]->SetPos2(m_scroll + 553, m_gy + 372);
	m_p_hit_line_ground3[4]->SetPos1(m_scroll + 730, m_gy + 450);  //最初のコンテナ左側
	m_p_hit_line_ground3[4]->SetPos2(m_scroll + 730, m_gy + 314);
	m_p_hit_line_ground3[5]->SetPos1(m_scroll + 730, m_gy + 314);  //最初のコンテナ上
	m_p_hit_line_ground3[5]->SetPos2(m_scroll + 1479, m_gy + 314);
	m_p_hit_line_ground3[6]->SetPos1(m_scroll + 1479, m_gy + 450);  //最初のコンテナ右側
	m_p_hit_line_ground3[6]->SetPos2(m_scroll + 1479, m_gy + 314);
	m_p_hit_line_ground3[7]->SetPos1(m_scroll + 1655, m_gy + 450);  //その次のコンテナ下部分左側
	m_p_hit_line_ground3[7]->SetPos2(m_scroll + 1655, m_gy + 314);
	m_p_hit_line_ground3[8]->SetPos1(m_scroll + 1655, m_gy + 314);  //その次のコンテナ下部分上
	m_p_hit_line_ground3[8]->SetPos2(m_scroll + 2186, m_gy + 314);
	m_p_hit_line_ground3[9]->SetPos1(m_scroll + 1770, m_gy + 450);  //コンテナ山の部分左側
	m_p_hit_line_ground3[9]->SetPos2(m_scroll + 1770, m_gy + 227);
	m_p_hit_line_ground3[10]->SetPos1(m_scroll + 1770, m_gy + 227);  //コンテナ山の部分上
	m_p_hit_line_ground3[10]->SetPos2(m_scroll + 1982, m_gy + 227);
	m_p_hit_line_ground3[11]->SetPos1(m_scroll + 1982, m_gy + 450);  //コンテナ山の部分右側
	m_p_hit_line_ground3[11]->SetPos2(m_scroll + 1982, m_gy + 227);
	m_p_hit_line_ground3[12]->SetPos1(m_scroll + 1982, m_gy + 256);  //コンテナ上の階段2段目上
	m_p_hit_line_ground3[12]->SetPos2(m_scroll + 2022, m_gy + 256);
	m_p_hit_line_ground3[13]->SetPos1(m_scroll + 2022, m_gy + 450);  //コンテナ上の階段2段目右側
	m_p_hit_line_ground3[13]->SetPos2(m_scroll + 2022, m_gy + 256);
	m_p_hit_line_ground3[14]->SetPos1(m_scroll + 2186, m_gy + 450);  //コンテナ下部分右側
	m_p_hit_line_ground3[14]->SetPos2(m_scroll + 2186, m_gy + 314);
	m_p_hit_line_ground3[15]->SetPos1(m_scroll + 2022, m_gy + 285);  //コンテナ上の階段1段目上
	m_p_hit_line_ground3[15]->SetPos2(m_scroll + 2062, m_gy + 285);
	m_p_hit_line_ground3[16]->SetPos1(m_scroll + 2062, m_gy + 285);  //コンテナ上の階段1段目右側
	m_p_hit_line_ground3[16]->SetPos2(m_scroll + 2062, m_gy + 450);
	m_p_hit_line_ground3[17]->SetPos1(m_scroll + 2530, m_gy + 262);  //最終ギミック黄黒の下部分
	m_p_hit_line_ground3[17]->SetPos2(m_scroll + 2816, m_gy + 262);
	m_p_hit_line_ground3[18]->SetPos1(m_scroll + 2814, m_gy + 450);  //最終ギミック黄黒の下左部分
	m_p_hit_line_ground3[18]->SetPos2(m_scroll + 2814, m_gy + 256);
	m_p_hit_line_ground3[19]->SetPos1(m_scroll + 2530, m_gy + 262);  //最終ギミック黄黒の左部分
	m_p_hit_line_ground3[19]->SetPos2(m_scroll + 2530, m_gy + 250);
	m_p_hit_line_ground3[20]->SetPos1(m_scroll + 2530, m_gy + 250);  //最終ギミック黄黒の上(足場)部分
	m_p_hit_line_ground3[20]->SetPos2(m_scroll + 2820, m_gy + 250);
	m_p_hit_line_ground3[21]->SetPos1(m_scroll + 2820, m_gy + 450);  //最終ギミック黄黒の右部分
	m_p_hit_line_ground3[21]->SetPos2(m_scroll + 2820, m_gy + 250);
	m_p_hit_line_ground3[22]->SetPos1(m_scroll + 2817, m_gy + 319);  //ゴールの足場
	m_p_hit_line_ground3[22]->SetPos2(m_scroll + 3300, m_gy + 319);


}

//ドロー
void ObjGround3::Draw()
{
	//ステージ3地面描画
	Draw::Draw2D(71, m_scroll, 0);

	Draw::Draw2D(58, m_scroll + 2820, 319);
}
