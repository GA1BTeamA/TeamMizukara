//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Hero.h"
#include "Sprinkler.h"
#include "ObjGround2.h"
#include "ObjGround3.h"

extern int g_SceneNumber;
extern bool g_key_flag;

//コンストラクタ
CHero::CHero()
	:m_x(130),m_y(300)
	, m_copy_x(130), m_copy_y(300)
	,m_vx(0.0f),m_vy(0.0f)
	, m_direc(RIGHT), m_down(false), m_IsMenu(false)
	,m_ani_time (0)
	, move_x(5.0f)
	, move_dash_x(7.5f)
	, m_CKey_Frag(false)
	, m_XKey_Frag(false)
	, m_IsScroll(false)
	,m_hero_delete_flag(false)
	,m_IsHit2Line(false)
{
	m_name = PLAYER;

	Audio::LoopMusicVolume(1, 0.1f);

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
	m_p_hit_line_hero[0]->SetPos2(m_x, m_y + 100);
	m_p_hit_line_hero[0]->Set4direc(HIT_LEFT);

	//主人公ヒットライン作成し、値を設定(右)
	m_p_hit_line_hero[1] = Collision::HitLineInsert(this);
	m_p_hit_line_hero[1]->SetPos1(m_x + 60, m_y);
	m_p_hit_line_hero[1]->SetPos2(m_x + 60, m_y + 100);
	m_p_hit_line_hero[1]->Set4direc(HIT_RIGHT);

	//主人公ヒットライン作成し、値を設定(上)
	m_p_hit_line_hero[2] = Collision::HitLineInsert(this);
	m_p_hit_line_hero[2]->SetPos1(m_x, m_y);
	m_p_hit_line_hero[2]->SetPos2(m_x + 60, m_y);
	m_p_hit_line_hero[2]->Set4direc(HIT_TOP);

	//主人公ヒットライン作成し、値を設定(下)
	m_p_hit_line_hero[3] = Collision::HitLineInsert(this);
	m_p_hit_line_hero[3]->SetPos1(m_x, m_y + 100);
	m_p_hit_line_hero[3]->SetPos2(m_x + 60, m_y + 100);
	m_p_hit_line_hero[3]->Set4direc(HIT_UNDER);

	for (int i = 0; i < 4; i++) {
		m_p_hit_line_hero[i]->SetElement(0);		//属性を0にする
		m_p_hit_line_hero[i]->SetInvisible(false);	//無敵モード無効
		m_p_hit_line_hero[i]->SetAngle();
	}

	//主人公ヒットラインのコピーを作成し、値を設定(左)
	m_p_hit_line_hero_copy[0] = Collision::HitLineInsert(this);
	m_p_hit_line_hero_copy[0]->SetPos1(m_x, m_y);
	m_p_hit_line_hero_copy[0]->SetPos2(m_x, m_y + 100);
	m_p_hit_line_hero_copy[0]->Set4direc(HIT_LEFT);

	//主人公ヒットラインのコピーを作成し、値を設定(右)
	m_p_hit_line_hero_copy[1] = Collision::HitLineInsert(this);
	m_p_hit_line_hero_copy[1]->SetPos1(m_x + 60, m_y);
	m_p_hit_line_hero_copy[1]->SetPos2(m_x + 60, m_y + 100);
	m_p_hit_line_hero_copy[1]->Set4direc(HIT_RIGHT);

	//主人公ヒットラインのコピーを作成し、値を設定(上)
	m_p_hit_line_hero_copy[2] = Collision::HitLineInsert(this);
	m_p_hit_line_hero_copy[2]->SetPos1(m_x, m_y);
	m_p_hit_line_hero_copy[2]->SetPos2(m_x + 60, m_y);
	m_p_hit_line_hero_copy[2]->Set4direc(HIT_TOP);

	//主人公ヒットラインのコピーを作成し、値を設定(下)
	m_p_hit_line_hero_copy[3] = Collision::HitLineInsert(this);
	m_p_hit_line_hero_copy[3]->SetPos1(m_x, m_y + 100);
	m_p_hit_line_hero_copy[3]->SetPos2(m_x + 60, m_y + 100);
	m_p_hit_line_hero_copy[3]->Set4direc(HIT_UNDER);

	for (int i = 0; i < 4; i++) {
		m_p_hit_line_hero_copy[i]->SetElement(0);		//属性を0にする
		m_p_hit_line_hero_copy[i]->SetInvisible(false);	//無敵モード無効
		m_p_hit_line_hero_copy[i]->SetAngle();
	}
}

CHero::~CHero()
{
}

void CHero::Action()
{
	if (m_hero_delete_flag == false)
	{
		////テスト
		//float a, b;
		//CCollision::LineCrossPoint(0, 0, 10, 10, 0, 5, 10, 5, &a, &b);
		//int aa = 0;
		//aa++;

		//交点までが一番短い点
		float Move_x = -9999.0f, Move_y = -9999.0f;

		bool IsHitGround = false;//地面に当たっているか
		bool IsHitWall = false;//壁に当たっているか

							   //交点までが一番短い点
		float Cross_x_min = 9999.0f, Cross_y_min = 9999.0f;

		//地面に当たったら、
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				//主人公の当たり判定が他の当たり判定にあたってなかったらスキップ
				if (m_p_hit_line_hero_copy[j]->GetHitData()[i] == nullptr)
					continue;

				//主人公がスプリンクラーに当たったら主人公削除
				if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetElement() == 4)
				{
					m_hero_delete_flag = true;

				}

				//主人公の当たり判定に当たってたのが地面なら
				if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetElement() == 1)
				{
					//主人公の当たり判定と地面の当たり判定が平行ならスキップ
					if (m_p_hit_line_hero_copy[j]->GetAngle() == m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle() ||
						((int)(m_p_hit_line_hero_copy[j]->GetAngle()) == 0 && (int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) == 180) ||
						((int)abs(m_p_hit_line_hero_copy[j]->GetAngle()) == (int)abs(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) == 180))
						continue;

					//オブジェクトの下判定にあたったか
					bool IsHitObjUnder = false;

					//前フレームでm_IsHit2Lineがtrueになってたら地面に当たっている
					if (m_IsHit2Line) {
						IsHitGround = true;
						m_IsHit2Line = false;
					}

					for (int k = 0; k < 10; k++) {
						if (m_p_hit_line_hero_copy[j]->GetHitData()[k] != nullptr) {
							//当たったヒットラインのなかに同じオブジェクトの当たり判定があって、
							if (/*m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetObj()->GetName() ==
								m_p_hit_line_hero_copy[j]->GetHitData()[k]->GetObj()->GetName()*/
								m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetElement() ==
								m_p_hit_line_hero_copy[j]->GetHitData()[k]->GetElement()) {
								//それが同じヒットラインじゃなくて、
								if (m_p_hit_line_hero_copy[j]->GetHitData()[i] !=
									m_p_hit_line_hero_copy[j]->GetHitData()[k]) {
									//角度が同じなら
									if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle() ==
										m_p_hit_line_hero_copy[j]->GetHitData()[k]->GetAngle()) {
										//上にある方の判定のみ
										if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y <=
											m_p_hit_line_hero_copy[j]->GetHitData()[k]->GetPoint1().y) {
											//主人公の下判定だったら
											if (m_p_hit_line_hero_copy[j]->Get4direc() == HIT_UNDER) {
												m_IsHit2Line = true;
												IsHitGround = true;
											}
											//主人公の上判定だったら
											else if (m_p_hit_line_hero_copy[j]->Get4direc() == HIT_TOP) {
												IsHitObjUnder = true;
											}
											else {
												//主人公を当たった判定の近い方の点に移動（壁抜け防止）
												if (j == 0) {//主人公の左
															 //Point1,2の近い方をムーブに入れる
													if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x) {
														Move_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x - m_x;
														IsHitWall = true;
													}
													else {
														Move_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x - m_x;
														IsHitWall = true;
													}
												}
												else if (j == 1) {//主人公の右
													if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x) {
														Move_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x - m_x;
														IsHitWall = true;
													}
													else {
														Move_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x - m_point_position[2].x - m_x;
														IsHitWall = true;
													}
												}
											}
										}
									}
								}
							}
						}
					}

					if (IsHitObjUnder) {
						m_vy = 0.0f;
						m_copy_y = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y;
						continue;
					}

					//縦の地面判定に当たったら
					if ((int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) == 0 ||
						(int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) == 180) {
						//初期化
						m_vx = 0.0f;
						//if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->Get4direc() == HIT_LEFT){
						//	m_copy_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x - m_point_position[2].x;

						//}
					}
					//あたったのが　オブジェクトの上判定で　水平ベクトルで　主人公の元位置より上にある場合
					else if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->Get4direc() == HIT_TOP &&
						(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) == 90.0456467f &&
						m_y + m_point_position[2].y > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y &&
						m_y + m_point_position[2].y > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y) {
						IsHitWall = true;
					}
					else {
						//初期化
						//地面の当たり判定がプレイヤーの下にある場合
						if (((m_p_hit_line_hero_copy[j]->GetHitData()[i]->Get4direc() == HIT_TOP) &&
							((m_y + m_point_position[2].y <= m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y) &&
							(m_y + m_point_position[2].y <= m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y))) ||
							//地面の当たり判定がプレイヤーの上にある場合
								((m_p_hit_line_hero_copy[j]->GetHitData()[i]->Get4direc() == HIT_UNDER) &&
							((m_y >= m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y) &&
									(m_y >= m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y)))) {
							//!(主人公のベクトルと地面のベクトルが一点だけで接してた場合)
							//主人公の左の場合
							if (!(((m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x <= m_copy_x) &&
								(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x <= m_copy_x)) ||
								//右の場合
								((m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x >= m_copy_x + m_point_position[2].x) &&
								(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x >= m_copy_x + m_point_position[2].x)))) {
								m_vy = 0.0f;
								//当たった地面の当たり判定がオブジェクトの下の部分なら後の処理しない
								if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->Get4direc() == HIT_UNDER) {
									m_copy_y = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y;
									continue;
								}
							}
						}
					}

					//交点変数
					float Cross_x, Cross_y;
					////交点までが一番短い点
					//float Cross_x_min = 9999.0f, Cross_y_min = 9999.0f;

					if ((m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) != 90.0456467f &&
						(int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) != 0 &&
						(int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) != 180) {
						if (m_p_hit_line_hero_copy[j]->Get4direc() == HIT_RIGHT) {
							//斜め判定より主人公が下にいると処理しない
							if (m_y + m_point_position[2].y-20 <= m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y) {
								//主人公の移動ベクトルと地面ベクトルの交点を求める
								Collision::LineCrossPoint(m_copy_x + m_point_position[2].x, m_copy_y /*+ m_point_position[2].y*/,
									m_copy_x + m_point_position[2].x, m_copy_y + m_point_position[2].y,
									m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x,
									m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y,
									m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x,
									m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y,
									&Cross_x, &Cross_y);

								//エラーが返されなかったら
								if (Cross_x != -9999.0f && Cross_y != -9999.0f)
								{
									//主人公から交点までのベクトルを取り出す
						//			Cross_x -= m_x + m_point_position[k].x;
									Cross_y = -(m_y + m_point_position[2].y - Cross_y);

									//主人公から交点までのベクトルの中から一番短いものを見つける
									//水平ベクトルならｘ無視
									//if (Cross_x_min > Cross_x /*&& (int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) != 90*/)
									//{
									//	Cross_x_min = Cross_x;
									//}
									//垂直ベクトルならｙ無視
									if (Cross_y <= 0 && Cross_y_min > abs(Cross_y) && (int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) != 0)
									{
										if (m_x + m_point_position[2].x > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x) {
											Cross_y_min = Cross_y;
										}
										//斜め判定に横から当たったら止める
										else {
											IsHitWall = true;
											Move_x = 0.0f;
										}
									}
								}
							}
							else {
								if (m_x + m_point_position[2].x <= m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x) {
									IsHitWall = true;
									Move_x = 0.0f;
								}
							}
						}
						else if (m_p_hit_line_hero_copy[j]->Get4direc() == HIT_LEFT) {
							//斜め判定より主人公が下にいると処理しない
							if (m_y + m_point_position[2].y-20 <= m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y) {
								//主人公の移動ベクトルと地面ベクトルの交点を求める
								Collision::LineCrossPoint(m_copy_x, m_copy_y,
									m_copy_x, m_copy_y + m_point_position[2].y,
									m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x,
									m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y,
									m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x,
									m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y,
									&Cross_x, &Cross_y);

								//エラーが返されなかったら
								if (Cross_x != -9999.0f && Cross_y != -9999.0f)
								{
									//主人公から交点までのベクトルを取り出す
									//			Cross_x -= m_x + m_point_position[k].x;
									Cross_y = -(m_y + m_point_position[2].y - Cross_y);

									//主人公から交点までのベクトルの中から一番短いものを見つける
									//水平ベクトルならｘ無視
									//if (Cross_x_min > Cross_x /*&& (int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) != 90*/)
									//{
									//	Cross_x_min = Cross_x;
									//}
									//垂直ベクトルならｙ無視
									if (Cross_y <= 0 && Cross_y_min > abs(Cross_y) && (int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) != 0)
									{
										if (m_x < m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x) {
											Cross_y_min = Cross_y;
										}
										//斜め判定に横から当たったら止める
										else {
											IsHitWall = true;
											Move_x = 0.0f;
										}
									}
								}
							}
							else {
								if (m_x > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x) {
									IsHitWall = true;
									Move_x = 0.0f;
								}
							}
						}
						//左と右の当たり判定にあたってなくて下に当たったら端の上に立たせる
						else if (Cross_y_min == 9999.0f &&
							m_p_hit_line_hero_copy[j]->Get4direc() == HIT_UNDER) {
							//if (m_x + m_point_position[2].x > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x &&
							//	m_x < m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x) {
							//	if (m_y + m_point_position[2].y <= m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y &&
							//		m_y + m_point_position[2].y <= m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y) {
							if (m_x < m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x &&
								m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x < m_x + m_point_position[2].x) {
									Move_y = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y - (m_copy_y + m_point_position[2].y);
								IsHitGround = true;
							}
							else if (m_x < m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x &&
								m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x < m_x + m_point_position[2].x) {
								Move_y = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y - (m_copy_y + m_point_position[2].y);
								IsHitGround = true;
							}

							//	}
							//}
						}
					}

					//初期化
					Cross_x = Cross_y = -9999.0f;
						
					//主人公のあたり判定の頂点をループ
					for (int k = 0; k < 4; k++)
					{
						//主人公の縦判定かつ、
						//地面が主人公の底辺より上にある場合、接してる側の地面ベクトルの点まで移動（短い壁抜け防止）
						/*	if (m_p_hit_line_hero_copy[j]->GetAngle() == 0.0f &&
						((m_y + m_point_position[2].y > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y) &&
						(m_y + m_point_position[2].y > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y))) {
						if (j == 0) {//主人公の左
						if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x) {
						m_copy_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x;
						}
						else {
						m_copy_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x;
						}
						}
						else if (j == 1) {//主人公の右
						if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x) {
						m_copy_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x;
						}
						else {
						m_copy_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x - m_point_position[2].x;
						}
						}
						}*/
						{
							//主人公の移動ベクトルと地面ベクトルが同直線上だったら
							if (m_x + m_point_position[k].x
								== m_copy_x + m_point_position[k].x
								== m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x
								== m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x) {
								IsHitWall = true;
							}
							//主人公の移動ベクトルと地面ベクトルが同直線上だったら
							else if ((m_y + m_point_position[k].y == m_copy_y + m_point_position[k].y)
								&& (m_y + m_point_position[k].y == m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y)
								&& (m_y + m_point_position[k].y == m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y)) {
								IsHitGround = true;
							}
							else {
								//下に移動してるときにオブジェクトの下判定に当たったら
								//上に移動してるときにオブジェクトの上判定に当たったら
								if ((m_y > m_copy_y && m_p_hit_line_hero_copy[j]->GetHitData()[i]->Get4direc() == HIT_TOP) ||
									(m_y < m_copy_y && m_p_hit_line_hero_copy[j]->GetHitData()[i]->Get4direc() == HIT_UNDER)) {
									//水平ベクトルの場合のみ
									if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle() == 90.0456467f) {
										if (j == 0) {//主人公の左
													 //Point1,2の近い方をムーブに入れる
											if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x) {
												Move_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x - m_x;
												IsHitWall = true;
											}
											else {
												Move_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x - m_x;
												IsHitWall = true;
											}
										}
										else if (j == 1) {//主人公の右
											if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x) {
												Move_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x - m_x;
												IsHitWall = true;
											}
											else {
												Move_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x - m_point_position[2].x - m_x;
												IsHitWall = true;
											}
										}
									}
								}
								else {
									//主人公の移動ベクトルと地面ベクトルの交点を求める
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
										//水平ベクトルならｘ無視
										if (Cross_x_min > Cross_x && (int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) == 0 ||
																	 (int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) == 180)
										{
											Cross_x_min = Cross_x;
										}
										//垂直ベクトルならｙ無視
										if (Cross_y_min > Cross_y && (int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) != 0)
										{
											Cross_y_min = Cross_y;
										}
									}
								}
							}
						}
					}
					//!(主人公の縦ベクトルと地面のベクトルが一点だけで接してた場合)
					if ((int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) != 0 &&
						(int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) != 180) {
						//主人公の左の場合
						if (!(((m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x <= m_copy_x) &&
							(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x <= m_copy_x)) ||
							//右の場合
							((m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x >= m_copy_x + m_point_position[2].x) &&
							(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x >= m_copy_x + m_point_position[2].x)))) {
							//エラーじゃなければ主人公を交点まで移動
							if (Cross_x_min != 9999.0f) {
								if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->Get4direc() == HIT_TOP) {
									IsHitGround = true;
								}
								if (Move_x < Cross_x_min) Move_x = Cross_x_min;
							}
							if (Cross_y_min != 9999.0f) {
								if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->Get4direc() == HIT_TOP) {
									IsHitGround = true;
								}
								if (Move_y < abs(Cross_y_min)) Move_y = Cross_y_min;
							}
						}
					}
					else {
						//主人公より高い場合
						if (!(((m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y <= m_copy_y) &&
							(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y <= m_copy_y)) ||
							//低い場合
							((m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y >= m_copy_y + m_point_position[2].y) &&
							(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y >= m_copy_y + m_point_position[2].y)))) {
							if ((int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) == 90 ||
								(int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) == 0  ||
								(int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) == 180) {
								//エラーじゃなければ主人公を交点まで移動
								if (Cross_x_min != 9999.0f) {
									IsHitWall = true;
									if (Move_x < Cross_x_min) Move_x = Cross_x_min;
								}
								if (Cross_y_min != 9999.0f) {
									IsHitWall = true;
									if (Move_y < Cross_y_min) Move_y = Cross_y_min;
								}
							}
						}
					}

				}
			}
			//ループの最後
			if (i == 9)
			{

				//前方スクロールライン
				if (m_copy_x > 350.0f)
				{
					//地面オブジェクト取得
					CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);
					ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);
					ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);
					//ステージ1
					//地面オブジェクトがヌルポインターじゃなかったら
					if (ground != nullptr) {
						if (ground->GetScroll() != -1600.0f) {
							if (Move_x != -9999.0f) {
								//スクロール値加算
								ground->AddScroll(m_x + Move_x - 350.0f);
								//主人公をスクロールラインで止める
								m_x = 350.0f;
							}
							else {
								//スクロール値加算
								ground->AddScroll(m_copy_x - 350.0f);
								//主人公をスクロールラインで止める
								m_x = 350.0f;
							}
							m_IsScroll = true;
						}
						else if (Move_x != -9999.0f) {
							m_x += Move_x;
						}
					}
					//ステージ2
					if (ground2 != nullptr) {
						if (ground2->GetScroll() != -2400.0f) {
							if (Move_x != -9999.0f) {
								//スクロール値加算
								ground2->AddScroll(m_x + Move_x - 350.0f);
								//主人公をスクロールラインで止める
								m_x = 350.0f;
							}
							else {
								//スクロール値加算
								ground2->AddScroll(m_copy_x - 350.0f);
								//主人公をスクロールラインで止める
								m_x = 350.0f;
							}
							m_IsScroll = true;
						}
						else if (Move_x != -9999.0f) {
							m_x += Move_x;
						}
					}
					//ステージ3
					if (ground3 != nullptr) {
						if (ground3->GetScroll() != -2400.0f) {
							if (Move_x != -9999.0f) {
								//スクロール値加算
								ground3->AddScroll(m_x + Move_x - 350.0f);
								//主人公をスクロールラインで止める
								m_x = 350.0f;
							}
							else {
								//スクロール値加算
								ground3->AddScroll(m_copy_x - 350.0f);
								//主人公をスクロールラインで止める
								m_x = 350.0f;
							}
							m_IsScroll = true;
						}
						else if (Move_x != -9999.0f) {
							m_x += Move_x;
						}
					}
				}
				//後方スクロールライン
				else if (m_copy_x < 200.0f)
				{
					//地面オブジェクト取得
					CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);
					ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);
					ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);
					//ステージ1
					//地面オブジェクトがヌルポインターじゃなかったら
					if (ground != nullptr) {
						if (ground->GetScroll() != 0.0f) {
							if (Move_x != -9999.0f) {
								//スクロール値加算
								ground->AddScroll(m_x + Move_x - 200.0f);
								//主人公をスクロールラインで止める
								m_x = 200.0f;
							}
							else {
								//スクロール値加算
								ground->AddScroll(m_copy_x - 200.0f);
								//主人公をスクロールラインで止める
								m_x = 200.0f;
							}
							m_IsScroll = true;
						}
						else if (Move_x != -9999.0f) {
							m_x += Move_x;
						}
					}
					//ステージ2
					if (ground2 != nullptr) {
						if (ground2->GetScroll() != 0.0f) {
							if (Move_x != -9999.0f) {
								//スクロール値加算
								ground2->AddScroll(m_x + Move_x - 200.0f);
								//主人公をスクロールラインで止める
								m_x = 200.0f;
							}
							else {
								//スクロール値加算
								ground2->AddScroll(m_copy_x - 200.0f);
								//主人公をスクロールラインで止める
								m_x = 200.0f;
							}
							m_IsScroll = true;
						}
						else if (Move_x != -9999.0f) {
							m_x += Move_x;
						}
					}
					//ステージ3
					if (ground3 != nullptr) {
						if (ground3->GetScroll() != 0.0f) {
							if (Move_x != -9999.0f) {
								//スクロール値加算
								ground3->AddScroll(m_x + Move_x - 200.0f);
								//主人公をスクロールラインで止める
								m_x = 200.0f;
							}
							else {
								//スクロール値加算
								ground3->AddScroll(m_copy_x - 200.0f);
								//主人公をスクロールラインで止める
								m_x = 200.0f;
							}
							m_IsScroll = true;
						}
						else if (Move_x != -9999.0f) {
							m_x += Move_x;
						}
					}

				}
				else {
					if (Move_x != -9999.0f) {
						m_x += Move_x;
					}
				}
				if (Move_y != -9999.0f) {
					m_y += Move_y;
				}

				//地面と壁に当たってたらスルー
				if (IsHitGround && IsHitWall) {
					continue;
				}
				//地面に当たってたらX方向に移動可
				else if (IsHitGround) {
					if (m_IsScroll == false) {
						m_x = m_copy_x;
					}
				}
				//壁に当たってたらY方向に移動可
				else if (IsHitWall) {
					m_y = m_copy_y;
				}
				//地面と壁に当たってなかったらXもYも移動可
				else {
					if (m_IsScroll == false) {
						m_x = m_copy_x;
					}
					m_y = m_copy_y;
				}
			}
		}

		if (g_SceneNumber == GAME_MAIN2) {
			ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);

			//ぞうさん
			//横方向の有効範囲
			if (m_x+ abs(ground2->GetScroll()) >= 2150 && 2350 >= m_x + abs(ground2->GetScroll()))
			{
				//円の中心点　-（（斜辺　*　斜辺）-（底辺　*　底辺））
				if (m_y > 225 - sqrt(100 * 100 - (2250 - (m_x + abs(ground2->GetScroll())))*(2250 - (m_x + abs(ground2->GetScroll()))))) {
					m_y = 225 - sqrt(100 * 100 - (2250 - (m_x + abs(ground2->GetScroll())))*(2250 - (m_x + abs(ground2->GetScroll()))));
					IsHitGround = true;
				}
			}
			//虹
			if (m_x + abs(ground2->GetScroll()) >= 2350 && 3200 >= m_x + abs(ground2->GetScroll()))
			{
				if (m_y > 380 - sqrt(270 * 270 - (2675 - (m_x + abs(ground2->GetScroll())))*(2675 - (m_x + abs(ground2->GetScroll()))))) {
					m_y = 380 - sqrt(270 * 270 - (2675 - (m_x + abs(ground2->GetScroll())))*(2675 - (m_x + abs(ground2->GetScroll()))));
					IsHitGround = true;
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

		//コピーの位置更新
		m_copy_x = m_x;
		m_copy_y = m_y;

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
					Audio::StopLoopMusic(6);
					//menu = new CMenu();
					//地面オブジェクト取得
					CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);
					ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);
					ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

					if(ground != nullptr) menu = new CMenu(1);
					else if (ground2 != nullptr) menu = new CMenu(2);
					else if (ground3 != nullptr) menu = new CMenu(3);
					menu->m_ActionPriority = 100;
					menu->m_DrawPriority = 900;
					TaskSystem::InsertObj(menu);
					m_IsMenu = true;
					Audio::StartLoopMusic(2);
					Audio::LoopMusicVolume(2, 0.05f);
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
						Audio::StopLoopMusic(2);
						Audio::StartLoopMusic(6);
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

			//CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

			//左キーで移動
			if (Input::KeyPush(VK_LEFT))
			{
				if (Input::KeyPush('V'))
				{
					m_copy_x -= move_dash_x;//Vキーでダッシュ
				}
				else
				{
					m_copy_x -= move_x;
				}
				if (m_copy_x < 0.0f)//主人公が領域外を超えたら停止
				{
					m_copy_x = 0.0f;
				}
				m_direc = LEFT;
			}
			//右キーで移動
			else if (Input::KeyPush(VK_RIGHT))
			{
				if (Input::KeyPush('V'))
				{
					m_copy_x += move_dash_x;//Vキーでダッシュ
				}
				else
				{
					m_copy_x += move_x;
				}
				if (m_copy_x + 60.0f > 800.0f)//主人公が領域外を超えたら停止
				{
					m_copy_x = 800.0f - 60.0f;
				}
				m_direc = RIGHT;
			}

			//デバッグ用
			//m_copy_x += move_dash_x;
			if(IsHitGround)
	//		m_vy = 0.0f;

			//地面に当たってたらスペースキーでジャンプ
			if (IsHitGround)
			{
				if (Input::KeyPush(VK_SPACE) == true)
				{
					m_vy = -7.8f;
				}
			}

			//Cキーが押されているかどうか
			if (Input::KeyPush('C'))
			{
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						//主人公の当たり判定が他の当たり判定にあたってなかったらスキップ
						if (m_p_hit_line_hero_copy[j]->GetHitData()[i] == nullptr)
							continue;

						//主人公の当たり判定に当たってたのがタンクorWTMなら卍
						if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetElement() == 3 ||
							m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetElement() == 2 ||
							m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetElement() == 5 ||
							m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetElement() == 6)
						{
							if (m_CKey_Frag == false)
								Audio::StartLoopMusic(1);
								Audio::LoopMusicVolume(1, 0.03f);

							m_CKey_Frag = true;
						}
					}
				}
			}
			else
			{
				m_CKey_Frag = false;
			}

			//Xキーが押されているかどうか
			if (Input::KeyPush('X'))
			{
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						//主人公の当たり判定が他の当たり判定にあたってなかったらスキップ
						if (m_p_hit_line_hero_copy[j]->GetHitData()[i] == nullptr)
							continue;

						//主人公の当たり判定に当たってたのがタンクorWTMなら卍
						if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetElement() == 3 ||
							m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetElement() == 2)
						{
							if (m_XKey_Frag == false)
								Audio::StartLoopMusic(1);

							m_XKey_Frag = true;
						}
					}
				}
			}
			else
			{
				m_XKey_Frag = false;
			}

			//CもXも押してなかったら音楽を止める
			if (!(Input::KeyPush('C')) && !(Input::KeyPush('X')))
				Audio::StopLoopMusic(1);


			//自由落下運動
			if (IsHitGround == false) {
				m_vy += 9.8 / (16.0f);
			}

			m_copy_y += m_vy;

			/*		//前方スクロールライン
			if (m_copy_x > 350.0f)
			{
			//地面オブジェクト取得
			CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);
			//地面オブジェクトがヌルポインターじゃなかったら
			if (ground != nullptr) {
			//スクロール値加算
			ground->AddScroll(m_copy_x - 350.0f);
			//主人公をスクロールラインで止める
			m_copy_x = 350.0f;
			}
			}
			//後方スクロールライン
			else if (m_copy_x < 200.0f)
			{
			//地面オブジェクト取得
			CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);
			//地面オブジェクトがヌルポインターじゃなかったら
			if (ground != nullptr) {
			//スクロール値加算
			ground->AddScroll(m_copy_x - 200.0f);
			//主人公をスクロールラインで止める
			m_copy_x = 200;
			}
			}*/


			m_p_hit_line_hero_copy[0]->SetPos1(m_copy_x, m_copy_y);
			m_p_hit_line_hero_copy[0]->SetPos2(m_copy_x, m_copy_y + 100);
			m_p_hit_line_hero_copy[1]->SetPos1(m_copy_x + 60, m_copy_y);
			m_p_hit_line_hero_copy[1]->SetPos2(m_copy_x + 60, m_copy_y + 100);
			m_p_hit_line_hero_copy[2]->SetPos1(m_copy_x, m_copy_y);
			m_p_hit_line_hero_copy[2]->SetPos2(m_copy_x + 60, m_copy_y);
			m_p_hit_line_hero_copy[3]->SetPos1(m_copy_x, m_copy_y + 100);
			m_p_hit_line_hero_copy[3]->SetPos2(m_copy_x + 60, m_copy_y + 100);

			//初期化
			m_IsScroll = false;


			//アニメーション
			if (Input::KeyPush(VK_RIGHT) || Input::KeyPush(VK_LEFT))
			{
				m_ani_time++;
				if (m_ani_time >= 32)
				{
					m_ani_time = 0;
				}
			}
			else
			{
				m_ani_time = 0;
			}

		}
	}
}

void CHero::Draw()
{
	if (m_hero_delete_flag == false)
	{
		//描画
		if (m_IsMenu)
		{
			//メニュー開いてるとき
			if (m_direc == RIGHT)
			{
				//主人公左向き
				Draw::Draw2D(0, m_x, m_y);
			}
			else if (m_direc == LEFT)
			{
				//主人公右向き
				Draw::Draw2D(1, m_x, m_y);
			}
		}
		else
		{
			if (Input::KeyPush(VK_LEFT))
			{
				//左歩き
				if (m_ani_time <= 8) {
					Draw::Draw2D(3, m_x, m_y);
				}
				else if (m_ani_time <= 16) {
					Draw::Draw2D(1, m_x, m_y);
				}
				else if (m_ani_time <= 24) {
					Draw::Draw2D(8, m_x, m_y);
				}
				else {
					Draw::Draw2D(1, m_x, m_y);
				}
			}
			else if (Input::KeyPush(VK_RIGHT))
			{
				//右歩き
				if (m_ani_time <= 8) {
					Draw::Draw2D(2, m_x, m_y);
				}
				else if (m_ani_time <= 16) {
					Draw::Draw2D(0, m_x, m_y);
				}
				else if (m_ani_time <= 24) {
					Draw::Draw2D(7, m_x, m_y);
				}
				else {
					Draw::Draw2D(0, m_x, m_y);
				}
			}
			else if (m_XKey_Frag == true)
			{
				if (m_direc == RIGHT)
				{
					//水汲む右向き
					Draw::Draw2D(5, m_x, m_y);
				}
				else if (m_direc == LEFT)
				{
					//水汲む左向き卍
					Draw::Draw2D(5, m_x + 60, m_y, -1, 1);
				}
			}
			else if (m_CKey_Frag == true)
			{
				if (m_direc == RIGHT)
				{
					//水戻す右向き
					Draw::Draw2D(4, m_x, m_y);
				}
				else if (m_direc == LEFT)
				{
					//水戻す左向き
					Draw::Draw2D(4, m_x + 60, m_y, -1, 1);
				}
			}
			else if (m_CKey_Frag == false)
			{
				//左向き
				if (m_direc == RIGHT)
				{
					Draw::Draw2D(0, m_x, m_y,1.0f,1.0f,0.0f);
				}
				else if (m_direc == LEFT)
				{
					//右向き
					Draw::Draw2D(1, m_x, m_y);
				}
			}
			/*else if (Input::KeyPush(VK_SPACE))
			{
				Draw::Draw2D(6, m_x, m_y);
			}*/
		}
	}
}