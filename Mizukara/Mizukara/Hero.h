#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"
#include "Menu.h"
#include "ObjGround.h"

//主人公クラス
class CHero : public CObj
{
public:
	CHero();
	~CHero();
	void Action();
	void Draw();

	int GetX() { return m_x; }//主人公位置取得用
	int GetY() { return m_y; }
	int GetVX() { return m_vx; }
	int GetVY() { return m_vy; }

	int GetMoveX() { return move_x; }
	int GetDashX() { return move_dash_x; }

	void SetX(int x) { m_copy_x = x; }
	void SetY(int y) { m_y = y; }

	void MenuDel() { m_IsMenu = false; }
private:
	float m_x; //位置
	float m_y;
	float m_copy_x; //位置(コピー)
	float m_copy_y;

	Point m_point_position[4];

	float move_x;  //歩く速度
	float move_dash_x;  //歩く速度に加算すればダッシュ時の速度になる

	float m_vx;//移動ベクトル
	float m_vy;

	bool m_direc;//向き

	bool m_IsMenu;//メニューを開いているか
	bool m_menu_key_flag;//メニュー用キーフラグ

	bool m_down;//衝突確認用

	int m_ani_time;//主人公アニメーション

	HitLine* m_p_hit_line_hero[4];//当たり判定
	HitLine* m_p_hit_line_hero_copy[4];//当たり判定(コピー)

	CMenu* menu;

	//CObjGround ground;
};