//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Hero.h"

CHero::CHero()
	:m_x(200),m_y(310)
	,m_vx(0.0f),m_vy(0.0f)
	, m_direc(RIGHT), m_down(false)
{
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

	//spaceキー入力でジャンプ
	if (Input::KeyPush(VK_SPACE) == true)
	{
		if (m_down == false)
		{
			m_vy = -20;
		}
	}

	/*//自由落下運動
	m_vy += 9.8 / (16.0f);

	m_y += m_vy;
	*/
	//当たり判定の位置更新
	m_p_hit_box->SetPos(m_x, m_y);
}

void CHero::Draw()
{
	//描画
	if (Input::KeyPush(VK_LEFT))
	{
		Draw::Draw2D(3, m_x, m_y);
	}
	else if (Input::KeyPush(VK_RIGHT))
	{
		Draw::Draw2D(2, m_x, m_y);
	}
	else if (Input::KeyPush('X'))
	{
		Draw::Draw2D(4, m_x, m_y);
	}
	else if (Input::KeyPush('C'))
	{
		Draw::Draw2D(5, m_x, m_y);
	}
	else if (Input::KeyPush(VK_SPACE))
	{
		Draw::Draw2D(6, m_x, m_y);
	}
	else if (m_direc == RIGHT)
	{
		Draw::Draw2D(0, m_x, m_y);
	}
	else if (m_direc == LEFT)
	{
		Draw::Draw2D(1, m_x, m_y);
	}
}