#pragma once
//メニュークラス
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//メニュークラス
class CMenu : public CObj
{
public:
	CMenu(unsigned int n);
	~CMenu();//使用するヘッダ
	void Action();
	void Draw();

private:
	float m_x; //位置
	float m_y;

	unsigned int m_cursor; //カーソル位置
	unsigned int m_BefCursor; //前のカーソル位置
	unsigned int m_StageNo;//ステージ番号

	bool key_flag;  //キーが押されているかチェック用

	int m_ani_time;//アイコン変更アニメーション
};