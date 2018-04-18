#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//タンククラス
class CMenu : public CObj
{
public:
	CMenu();
	~CMenu();
	void Action();
	void Draw();

private:
	float m_x; //位置
	float m_y;
	unsigned int m_cursor; //カーソル位置
	unsigned int m_BefCursor; //前のカーソル位置

	bool m_IsContinue;//やり直し
	bool m_IsRetire;//リタイア
	bool m_IsRedo;//やり直し

	bool key_flag;  //キーが押されているかチェック用
};