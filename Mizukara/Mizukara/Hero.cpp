//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Hero.h"

CHero::CHero()
{
	//ランダムで初期値を決める
	m_x = 200;
	m_y = 400;
	//初期移動方向
	m_vx = 0.0f;
	m_vy = 0.0f;

	//HEROオブジェクトの各当たり判定の属性をバラバラにする
	static int count = 0;
	count++;

	//ヒットボックス作成()
	m_p_hit_box = Collision::HitBoxInsert(this);
	//作成したヒットボックスの値を設定
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(60.0f, 100.0f);
	m_p_hit_box->SetElement(count);		//属性をcountにする
	m_p_hit_box->SetInvisible(false);	//無敵モード無効
}

CHero::~CHero()
{

}

void CHero::Action()
{
	//削除実行
	if (Input::KeyPush(VK_LEFT))
	{
		m_x -= 5.0f;
	}
	else if (Input::KeyPush(VK_RIGHT))
	{
		m_x += 5.0f;
	}


	//当たり判定の位置更新
	m_p_hit_box->SetPos(m_x, m_y);
}

void CHero::Draw()
{
	//描画
	Draw::Draw2D(0, m_x, m_y);
}