//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Collision.h"
#include "Draw2DPolygon.h"

list<shared_ptr<HitLine>>* CCollision::m_hit_line_list;//リスト　HitLine用

//デバッグ用の当たり判定描画
void CCollision::DrawDebug()
{
	float c[4] = { 1.0f,0.0f,0.0f,0.3f };
	//listのHitLineを描画
	for (auto ip = m_hit_line_list->begin(); ip != m_hit_line_list->end(); ip++)
	{
		//CDraw2DPolygon::Draw2DHitBox((*ip)->p1.x, (*ip)->p1.y, (*ip)->p2.x, (*ip)->p2.y, c);
	}
}

//当たり判定を作成しリストに登録
HitLine* CCollision::HitLineInsert(CObj* p)
{
	//ヒットライン作成
	shared_ptr<HitLine>sp(new HitLine());

	//ヒットラインに情報を入れる(フレンドなので直接アクセスできる)
	sp->m_obj = p;		//この当たり判定を持つオブジェクトのアドレス(オブジェクトアドレスは引数pから引っ張ってくる)
	sp->p1.x = -999.0f;	//当たり判定のp1.x位置
	sp->p1.y = -999.0f;	//当たり判定のp1.y位置
	sp->p2.x = -999.0f;	//当たり判定のp2.x位置
	sp->p2.y = -999.0f;	//当たり判定のp2.y位置
	sp->m_ls_invisible = false;//当たり判定の無敵モードOFF
	sp->m_element = 0;	//当たり判定の属性

	//リストに登録
	m_hit_line_list->push_back(sp);

	//spのフレッシュポインタを返す
	return sp.get();
}

//初期化
void CCollision::InitHitLine()
{
	m_hit_line_list = new list<shared_ptr<HitLine>>;
	m_hit_line_list->clear();
}

//破棄
void CCollision::DeleteHitLine()
{
	m_hit_line_list->clear();
	delete m_hit_line_list;
}

//list内の当たり判定全チェック開始
void CCollision::CheckStart()
{
	//リスト内のls_deleteがtrueの要素を削除
	auto i = m_hit_line_list->begin();
	while (i != m_hit_line_list->end())
	{
		if (i->get()->ls_delete == true)
		{
			//イテレータiの要素を削除
			i = m_hit_line_list->erase(i);
		}
		else
		{
			i++;
		}
	}

	//複数との衝突情報制御用
	int hit_count = 0;

	//リスト内のヒットボックスで当たり判定を実施
	for (auto ip_1= m_hit_line_list->begin(); ip_1 != m_hit_line_list->end(); ip_1++)		//Aヒットボックス
	{
		//衝突回数の初期化
		hit_count = 0;
		//Aの情報の衝突情報の初期化
		for (int i = 0; i < 10; i++)
		{
			(*ip_1)->m_hit[i] = nullptr;
		}

		//AのHitboxの当たり判定無視チェック
		//無敵
		if ((*ip_1)->m_ls_invisible)
			continue;

		for (auto ip_2 = m_hit_line_list->begin(); ip_2 != m_hit_line_list->end(); ip_2++)	//Bヒットボックス
		{
			//BのHitboxの当たり判定無視チェック
			//AとBが同じヒットボックス
			if (ip_1 == ip_2)
				continue;

			//無敵
			if ((*ip_2)->m_ls_invisible)
				continue;

			//AとBのヒットボックスがおなじオブジェクト
			if ((*ip_1)->m_obj == (*ip_2)->m_obj)
				continue;

			//AとBのヒットボックスが同属性
			if ((*ip_1)->m_element == (*ip_2)->m_element)
				continue;

			//当たり判定を実施
			bool ls_hit = IsLinecross((*ip_1)->p1, (*ip_1)->p2,(*ip_2)->p1, (*ip_2)->p2);
			//衝突している場合
			if (ls_hit == true)
			{
				//aのヒットボックスに当たっているbのアドレス与える
				int buffer_count = hit_count % 10;				//m_hit[]をキューバッファとして扱う
				(*ip_1)->m_hit[buffer_count] = ip_2->get();		//bのアドレス(フレッシュポインタ)を渡す
				hit_count++;
			}
		}
	}
}

//個々への当たり判定
bool CCollision::HitAB(float ax, float ay, float aw, float ah, float bx, float by, float bw, float bh)
{
	//当たり判定
	if (ax < bx + bw && ax + aw > bx && ay < by + bh && ay + ah > by)
	{
		//衝突している
		return true;
	}
	//衝突していない
	return false;
}

//座標 p1,p2　を結ぶ線分と座標 p3,p4 を結ぶ線分が交差しているかを調べる
//ただし、線分が重なっている場合(3点、4点が一直線上にある)、「交差している」、と判定する
bool CCollision::IsLinecross(Point p1, Point p2, Point p3, Point p4)
{
//ラフチェック
	//X座標によるチェック
	if (p1.x >= p2.x)
	{
		if ((p1.x < p3.x && p1.x < p4.x) || (p2.x > p3.x && p2.x > p4.x))
		{
			return false;
		}
		else if ((p2.x < p3.x && p2.x < p4.x) || (p1.x > p3.x && p1.x > p4.x))
		{
			return false;
		}
	}

	//Y座標によるチェック
	if (p1.y >= p2.y)
	{
		if ((p1.y < p3.y && p1.y < p4.y) || (p2.y > p3.y&&p2.y > p4.y))
		{
			return false;
		}
		else if ((p2.y < p3.y && p2.y < p4.y) || (p1.y > p3.y && p1.y > p4.y))
		{
			return false;
		}
	}

//ラフチェックではじかれなかった分をチェックする
	if (((p1.x - p2.x)*(p3.y - p1.y) + (p1.y - p2.y)*(p1.x - p3.x))*
		((p1.x - p2.x)*(p4.y - p1.y) + (p1.y - p2.y)*(p1.x - p4.x)) > 0)
	{
		return false;
	}
	if (((p3.x - p4.x)*(p1.y - p3.y) + (p3.y - p4.y)*(p3.x - p1.x))*
		((p3.x - p4.x)*(p2.y - p3.y) + (p3.y - p4.y)*(p3.x - p2.x)) > 0)
	{
		return false;
	}
	return true;
}

//内積関数
//引数1,2 float  ax , ay :Aベクトル
//引数3,4 float  bx , by :Bベクトル
//戻り値　float :射影
//内容　AベクトルとBベクトルで内積を行い射影を求める
float CCollision::Dot(float ax, float ay, float bx, float by)
{
	float t = 0.0f;

	t = ax * bx + ay * by;

	return t;
}

//外積関数
//引数1,2 float  ax , ay :Aベクトル
//引数3,4 float  bx , by :Bベクトル
//戻り値　float :射影
//内容　AベクトルとBベクトルで外積を行い射影を求める
float CCollision::Cross(float ax, float ay, float bx, float by)
{
	float t = 0.0f;

	t = ax * by - ay * bx;

	return t;
}

#define SGN(x) 1-(x<=0)-(x<0)

//線と線の交差判定関数
//引数 float 1,2   a1x , a1y      :軸ベクトルAの始点
//引数 float 3,4   a2x , a2y      :軸ベクトルAの終点
//引数 float 5,6   b1x , b1y      :ベクトルBの始点
//引数 float 7,8   b2x , b2y      :ベクトルBの終点
//引数 float 9,10  out_px,out_py  :交差するベクトルの交点位置
//戻り値 bool   :true=交点有り　false=交点無し
//内容:引数のA・Bベクトルの交点を見つけ、out_pxとout_pyに返す
bool CCollision::LineCrossPoint(
	float a1x, float a1y, float a2x, float a2y,
	float b1x, float b1y, float b2x, float b2y,
	float* out_px, float* out_py
)
{
	//エラーコード
	*out_px = -9999.0f;  *out_py = -9999.0f;

	//Aベクトル作成(a2←a1)
	float ax = a2x - a1x;  float ay = a2y - a1y;

	//Bベクトル作成(b2←b1)
	float bx = b2x - b1x;  float by = b2y - b1y;

	//Cベクトル作成(b1←a1)
	float cx = b1x - a1x;  float cy = b1y - a1y;

	//Dベクトル作成(b2←a1)
	float dx = b2x - a1x;  float dy = b2y - a1y;

	//A×Cの射影とA×Bの射影を求める
	float t1 = Cross(ax, ay, cx, cy);
	float t2 = Cross(ax, ay, dx, dy);

	//符号が同じ方向になっているかどうかをチェック
	if (SGN(t1) == SGN(t2))
 		return false;  //交点無し

	//射影を絶対値化
	t1 = abs(t1);  t2 = abs(t2);

	//交点を求める
	float px = bx*(t1 / (t1 + t2)) + b1x;
	float py = by*(t1 / (t1 + t2)) + b1y;

	//APベクトル(p←a1)
	float apx = px - a1x;  float apy = py - a1y;

	//BPベクトル(p←a2)
	float bpx = px - a2x;  float bpy = py - a2y;

	//A・APの射影とA・BPの射影を求める
	float w1 = Dot(ax, ay, apx, apy);
	float w2 = Dot(ax, ay, bpx, bpy);

	//符号チェック
	if (SGN(w1) == SGN(w2))
		return false;  //交点が外

	//交点を返す
	*out_px = px; *out_py = py;

	return true;
}