#pragma once
//必要なヘッダー
#include <Windows.h>
#include <memory>
#include <list>

#include "TaskSystem.h"
using namespace std;

//座標
class Point
{
public:
	double x;
	double y;
};

//衝突オブジェクトクラス
class HitLine
{
	//CCollisionのみプライベートを公開する
	friend class CCollision;
public:
	HitLine() { Init(); }
	~HitLine() {}
	//初期化
	void Init()
	{
		ls_delete = false;
		p1.x = p1.y = p2.x = p2.y = -999.0f;
		//m_w = m_h = 0.0f;
		m_obj = nullptr;
		m_element = -1;
		for (int i = 0; i < 10; i++)
			m_hit[i] = nullptr;
	}

	void SetDelete(bool d) { ls_delete = d; }	//削除フラグセット
	void SetPos1(float x, float y) { p1.x = x; p1.y = y; }					//位置セット
	void SetPos2(float x, float y) { p2.x = x; p2.y = y; }
	//void SetWH(float w, float h) { m_w = w; m_h = h; }					//　幅セット
	void SetElement(int element) { m_element = element; }				//属性セット
	void SetInvisible(bool invisible) { m_ls_invisible = invisible; }	//無敵セット
	HitLine** GetHitData() { return m_hit; }	//当たった相手のヒットボックス情報取得


private:
	//削除フラグ
	bool ls_delete;
	//位置
	Point p1;
	Point p2;
	////幅
	//float m_w;
	//float m_h;
	//この衝突オブジェクトを持つオブジェクトのポインタ
	CObj* m_obj;
	//属性(同じ値同士では当たり判定を行わない)
	int m_element;
	//無敵(trueでは当たり判定を行わない)
	bool m_ls_invisible;
	//当たった相手のHitLine情報
	//同時に10オブジェクトまで情報を取る
	HitLine* m_hit[10];
};

//衝突判定クラス
typedef class CCollision
{
public:
	CCollision() {}
	~CCollision() {}

	static void InitHitLine();	//初期化
	static void DeleteHitLine();	//破棄

	static HitLine* HitLineInsert(CObj* p);	//当たり判定を作成しリストに登録
	static void CheckStart();				//list内の当たり判定全チェック開始
	static void DrawDebug();				//デバッグ用の当たり判定描画用

private:
	//個々への当たり判定
	static bool HitAB(float ax, float ay, float aw, float ah, float bx, float by, float bw, float bh);
	static bool IsLinecross(Point p1, Point p2, Point p3, Point p4);

	//リスト　HitBoxを持つオブジェクトの要素を持つ
	static list<shared_ptr<HitLine>>* m_hit_line_list;

}Collision;