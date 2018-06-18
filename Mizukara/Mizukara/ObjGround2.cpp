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
	m_p_hit_line_ground2[3]->Set4direc(HIT_LEFT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[4] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[4]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[5] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[5]->Set4direc(HIT_LEFT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[6] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[6]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[7] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[7]->Set4direc(HIT_LEFT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[8] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[8]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[9] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[9]->Set4direc(HIT_LEFT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[10] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[10]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[11] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[11]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[12] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[12]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[13] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[13]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[14] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[14]->Set4direc(HIT_LEFT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[15] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[15]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[16] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[16]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[17] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[17]->Set4direc(HIT_LEFT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[18] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[18]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[19] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[19]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[20] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[20]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[21] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[21]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[22] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[22]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[23] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[23]->Set4direc(HIT_RIGHT);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[24] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[24]->Set4direc(HIT_TOP);

	//ヒットボックス作成し、作成したヒットボックスの値を設定
	m_p_hit_line_ground2[25] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[25]->Set4direc(HIT_RIGHT);

	m_p_hit_line_ground2[0]->SetPos1(m_scroll + 0, m_gy + 400);  //最初
	m_p_hit_line_ground2[0]->SetPos2(m_scroll + /*274*/494, m_gy + 400);
	m_p_hit_line_ground2[1]->SetPos1(m_scroll + 550, m_gy + 400);  //0段目
	m_p_hit_line_ground2[1]->SetPos2(m_scroll + 3250, m_gy + 400);
	m_p_hit_line_ground2[2]->SetPos1(m_scroll + 602, m_gy + 374);  //1段目
	m_p_hit_line_ground2[2]->SetPos2(m_scroll + 680, m_gy + 374);
	m_p_hit_line_ground2[3]->SetPos1(m_scroll + 602, m_gy + 400);  //0と1間
	m_p_hit_line_ground2[3]->SetPos2(m_scroll + 602, m_gy + 374);
	m_p_hit_line_ground2[4]->SetPos1(m_scroll + 627, m_gy + 348);  //2段目
	m_p_hit_line_ground2[4]->SetPos2(m_scroll + 680, m_gy + 348);
	m_p_hit_line_ground2[5]->SetPos1(m_scroll + 627, m_gy + 400);  //1と2の間
	m_p_hit_line_ground2[5]->SetPos2(m_scroll + 627, m_gy + 348);
	m_p_hit_line_ground2[6]->SetPos1(m_scroll + 652, m_gy + 322);  //3段目
	m_p_hit_line_ground2[6]->SetPos2(m_scroll + 705, m_gy + 322);
	m_p_hit_line_ground2[7]->SetPos1(m_scroll + 652, m_gy + 400);  //2と3の間
	m_p_hit_line_ground2[7]->SetPos2(m_scroll + 652, m_gy + 322);
	m_p_hit_line_ground2[8]->SetPos1(m_scroll + 705, m_gy + 450);  //3段目反対側の壁
	m_p_hit_line_ground2[8]->SetPos2(m_scroll + 705, m_gy + 322);
	m_p_hit_line_ground2[9]->SetPos1(m_scroll + 888, m_gy + 450);  //1個目ギミック超えたとこ壁
	m_p_hit_line_ground2[9]->SetPos2(m_scroll + 888, m_gy + 248);
	m_p_hit_line_ground2[10]->SetPos1(m_scroll + 888, m_gy + 248);  //1個目ギミック超えたとこ地面
	m_p_hit_line_ground2[10]->SetPos2(m_scroll + 990, m_gy + 248);
	m_p_hit_line_ground2[11]->SetPos1(m_scroll + 990, m_gy + 450);  //その地面の段差
	m_p_hit_line_ground2[11]->SetPos2(m_scroll + 990, m_gy + 248);
	m_p_hit_line_ground2[12]->SetPos1(m_scroll + 900, m_gy + 292);  //段差下の地面
	m_p_hit_line_ground2[12]->SetPos2(m_scroll + 1060, m_gy + 292);
	m_p_hit_line_ground2[13]->SetPos1(m_scroll + 1060, m_gy + 450);  //段差下地面の壁
	m_p_hit_line_ground2[13]->SetPos2(m_scroll + 1060, m_gy + 292);
	m_p_hit_line_ground2[14]->SetPos1(m_scroll + 1235, m_gy + 450);  //次の高い地面の壁
	m_p_hit_line_ground2[14]->SetPos2(m_scroll + 1235, m_gy + 191);
	m_p_hit_line_ground2[15]->SetPos1(m_scroll + 1235, m_gy + 191);  //高い地面
	m_p_hit_line_ground2[15]->SetPos2(m_scroll + 1332, m_gy + 191);
	m_p_hit_line_ground2[16]->SetPos1(m_scroll + 1332, m_gy + 450);  //高い地面反対側の壁
	m_p_hit_line_ground2[16]->SetPos2(m_scroll + 1332, m_gy + 191);
	m_p_hit_line_ground2[17]->SetPos1(m_scroll + 1846, m_gy + 450);  //洞窟最後、ぞうさん手前の壁
	m_p_hit_line_ground2[17]->SetPos2(m_scroll + 1846, m_gy + 149);
	m_p_hit_line_ground2[18]->SetPos1(m_scroll + 1846, m_gy + 149);  //ぞうさん階段1上
	m_p_hit_line_ground2[18]->SetPos2(m_scroll + 2045, m_gy + 149);
	m_p_hit_line_ground2[19]->SetPos1(m_scroll + 2045, m_gy + 249);  //ぞうさん階段1右
	m_p_hit_line_ground2[19]->SetPos2(m_scroll + 2045, m_gy + 149);
	m_p_hit_line_ground2[20]->SetPos1(m_scroll + 1945, m_gy + 176);  //ぞうさん階段2上
	m_p_hit_line_ground2[20]->SetPos2(m_scroll + 2071, m_gy + 176);
	m_p_hit_line_ground2[21]->SetPos1(m_scroll + 2071, m_gy + 253);  //ぞうさん階段2右
	m_p_hit_line_ground2[21]->SetPos2(m_scroll + 2071, m_gy + 176);
	m_p_hit_line_ground2[22]->SetPos1(m_scroll + 2000, m_gy + 203);  //ぞうさん階段3上
	m_p_hit_line_ground2[22]->SetPos2(m_scroll + 2097, m_gy + 203);
	m_p_hit_line_ground2[23]->SetPos1(m_scroll + 2097, m_gy + 280);  //ぞうさん階段3右
	m_p_hit_line_ground2[23]->SetPos2(m_scroll + 2097, m_gy + 203);
	m_p_hit_line_ground2[24]->SetPos1(m_scroll + 2000, m_gy + 230);  //ぞうさん階段終わりの地面
	m_p_hit_line_ground2[24]->SetPos2(m_scroll + 2250, m_gy + 230);
	m_p_hit_line_ground2[25]->SetPos1(m_scroll + 90, m_gy + 450);  //タンク当たり判定
	m_p_hit_line_ground2[25]->SetPos2(m_scroll + 90, m_gy);

	for (int i = 0; i < 26; i++) {
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

	//位置更新
	m_p_hit_line_ground2[0]->SetPos1(m_scroll + 0, m_gy + 400);  //最初
	m_p_hit_line_ground2[0]->SetPos2(m_scroll + /*274*/494, m_gy + 400);
	m_p_hit_line_ground2[1]->SetPos1(m_scroll + 550, m_gy + 400);  //0段目
	m_p_hit_line_ground2[1]->SetPos2(m_scroll + 3250, m_gy + 400);
	m_p_hit_line_ground2[2]->SetPos1(m_scroll + 602, m_gy + 374);  //1段目
	m_p_hit_line_ground2[2]->SetPos2(m_scroll + 680, m_gy + 374);
	m_p_hit_line_ground2[3]->SetPos1(m_scroll + 602, m_gy + 400);  //0と1間
	m_p_hit_line_ground2[3]->SetPos2(m_scroll + 602, m_gy + 374);
	m_p_hit_line_ground2[4]->SetPos1(m_scroll + 627, m_gy + 348);  //2段目
	m_p_hit_line_ground2[4]->SetPos2(m_scroll + 680, m_gy + 348);
	m_p_hit_line_ground2[5]->SetPos1(m_scroll + 627, m_gy + 400);  //1と2の間
	m_p_hit_line_ground2[5]->SetPos2(m_scroll + 627, m_gy + 348);
	m_p_hit_line_ground2[6]->SetPos1(m_scroll + 652, m_gy + 322);  //3段目
	m_p_hit_line_ground2[6]->SetPos2(m_scroll + 705, m_gy + 322);
	m_p_hit_line_ground2[7]->SetPos1(m_scroll + 652, m_gy + 400);  //2と3の間
	m_p_hit_line_ground2[7]->SetPos2(m_scroll + 652, m_gy + 322);
	m_p_hit_line_ground2[8]->SetPos1(m_scroll + 705, m_gy + 450);  //3段目反対側の壁
	m_p_hit_line_ground2[8]->SetPos2(m_scroll + 705, m_gy + 322);
	m_p_hit_line_ground2[9]->SetPos1(m_scroll + 888, m_gy + 450);  //1個目ギミック超えたとこ壁
	m_p_hit_line_ground2[9]->SetPos2(m_scroll + 888, m_gy + 248);
	m_p_hit_line_ground2[10]->SetPos1(m_scroll + 888, m_gy + 248);  //1個目ギミック超えたとこ地面
	m_p_hit_line_ground2[10]->SetPos2(m_scroll + 990, m_gy + 248);
	m_p_hit_line_ground2[11]->SetPos1(m_scroll + 990, m_gy + 450);  //その地面の段差
	m_p_hit_line_ground2[11]->SetPos2(m_scroll + 990, m_gy + 248);
	m_p_hit_line_ground2[12]->SetPos1(m_scroll + 900, m_gy + 292);  //段差下の地面
	m_p_hit_line_ground2[12]->SetPos2(m_scroll + 1060, m_gy + 292);
	m_p_hit_line_ground2[13]->SetPos1(m_scroll + 1060, m_gy + 450);  //段差下地面の壁
	m_p_hit_line_ground2[13]->SetPos2(m_scroll + 1060, m_gy + 292);
	m_p_hit_line_ground2[14]->SetPos1(m_scroll + 1235, m_gy + 450);  //次の高い地面の壁
	m_p_hit_line_ground2[14]->SetPos2(m_scroll + 1235, m_gy + 191);
	m_p_hit_line_ground2[15]->SetPos1(m_scroll + 1235, m_gy + 191);  //高い地面
	m_p_hit_line_ground2[15]->SetPos2(m_scroll + 1332, m_gy + 191);
	m_p_hit_line_ground2[16]->SetPos1(m_scroll + 1332, m_gy + 450);  //高い地面反対側の壁
	m_p_hit_line_ground2[16]->SetPos2(m_scroll + 1332, m_gy + 191);
	m_p_hit_line_ground2[17]->SetPos1(m_scroll + 1846, m_gy + 450);  //洞窟最後、ぞうさん手前の壁
	m_p_hit_line_ground2[17]->SetPos2(m_scroll + 1846, m_gy + 149);
	m_p_hit_line_ground2[18]->SetPos1(m_scroll + 1846, m_gy + 149);  //ぞうさん階段1上
	m_p_hit_line_ground2[18]->SetPos2(m_scroll + 2045, m_gy + 149);
	m_p_hit_line_ground2[19]->SetPos1(m_scroll + 2045, m_gy + 249);  //ぞうさん階段1右
	m_p_hit_line_ground2[19]->SetPos2(m_scroll + 2045, m_gy + 149);
	m_p_hit_line_ground2[20]->SetPos1(m_scroll + 1945, m_gy + 176);  //ぞうさん階段2上
	m_p_hit_line_ground2[20]->SetPos2(m_scroll + 2071, m_gy + 176);
	m_p_hit_line_ground2[21]->SetPos1(m_scroll + 2071, m_gy + 253);  //ぞうさん階段2右
	m_p_hit_line_ground2[21]->SetPos2(m_scroll + 2071, m_gy + 176);
	m_p_hit_line_ground2[22]->SetPos1(m_scroll + 2000, m_gy + 203);  //ぞうさん階段3上
	m_p_hit_line_ground2[22]->SetPos2(m_scroll + 2097, m_gy + 203);
	m_p_hit_line_ground2[23]->SetPos1(m_scroll + 2097, m_gy + 280);  //ぞうさん階段3右
	m_p_hit_line_ground2[23]->SetPos2(m_scroll + 2097, m_gy + 203);
	m_p_hit_line_ground2[24]->SetPos1(m_scroll + 2000, m_gy + 230);  //ぞうさん階段終わりの地面
	m_p_hit_line_ground2[24]->SetPos2(m_scroll + 2250, m_gy + 230);
	m_p_hit_line_ground2[25]->SetPos1(m_scroll + 90, m_gy + 450);  //タンク当たり判定
	m_p_hit_line_ground2[25]->SetPos2(m_scroll + 90, m_gy);

}

//ドロー
void ObjGround2::Draw()
{
	//ステージ2地面描画
	Draw::Draw2D(69, m_scroll, 0);


	//Draw::Draw2D(58, m_scroll+2045, 149);
}
