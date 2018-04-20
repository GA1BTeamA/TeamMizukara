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

	void MenuDel() { m_IsMenu = false; }
private:
	float m_x; //位置
	float m_y;
	float m_vx;//移動ベクトル
	float m_vy;
	bool m_direc;//向き
	bool m_IsMenu;//メニューを開いているか
	bool m_menu_key_flag;//メニュー用キーフラグ

	bool m_down;//衝突確認用

	HitLine* m_p_hit_line[4];//当たり判定

	CMenu* menu;

	CObjGround ground;
};