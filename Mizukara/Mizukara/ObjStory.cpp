//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjStory.h"

extern int g_SceneNumber;
extern bool g_key_flag;

CObjStory::CObjStory()
	:m_x(0), m_y(0),m_time(0)
{

}

CObjStory::~CObjStory()
{

}

void CObjStory::Action()
{
	//アニメーション終了でステージセレクトへ
	if (m_time++ > 300) {
		g_SceneNumber = STAGESELECTO;
		is_delete = true;
	}

	//エンターキーでスキップ
	if (Input::KeyPush(VK_RETURN) == true)
	{
		if (g_key_flag)
		{
			g_SceneNumber = STAGESELECTO;
			is_delete = true;
			g_key_flag = false;
		}
	}
	else
	{
		g_key_flag = true;
	}


}

void CObjStory::Draw()
{
	Draw::Draw2D(20, m_x, m_y);
}