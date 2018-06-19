#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//タイトルクラス
class CTitle : public CObj
{
public:
	CTitle();
	~CTitle();
	void Action();
	void Draw();
private:
	float m_x; //位置
	float m_y;

	unsigned int m_cursor; //カーソル位置
	unsigned int m_BefCursor; //前のカーソル位置

	bool m_IsDrawOpe;//操作説明描画
	bool m_IsDrawStageSelecto;//ステージセレクト描画

	bool key_flag;  //キーが押されているかチェック用

	int m_ani_time;//アイコン変更アニメーション
};