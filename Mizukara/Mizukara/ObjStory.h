#pragma once
//使用するヘッダ
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//ストーリークラス
class CObjStory : public CObj
{
public:
	CObjStory();
	~CObjStory();
	void Action();
	void Draw();
private:
	float m_x; //位置
	float m_y;

	float m_story_alpha;//透明度変更用
	float m_story_alpha2;



	int m_StoryScene;

	unsigned int m_time;//ストーリー描画時間
};