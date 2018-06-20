//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjStory.h"

extern int g_SceneNumber;
extern bool g_key_flag;

CObjStory::CObjStory()
	:m_x(0), m_y(0),m_time(0), m_StoryScene(0)
{

}

CObjStory::~CObjStory()
{

}

void CObjStory::Action()
{
	Audio::StartLoopMusic(4);
	Audio::LoopMusicVolume(4, 0.05f);

	//エンターキーでスキップ
	if (Input::KeyPush(VK_RETURN) == true)
	{
		if (g_key_flag)
		{
			switch (m_StoryScene)
			{
			case 0:
				m_StoryScene++;
				g_key_flag = false;
				break;

			case 1:
				m_StoryScene++;
				g_key_flag = false;
				break;

			case 2:
				Audio::StopLoopMusic(4);
				g_SceneNumber = STAGESELECTO;
				is_delete = true;
				g_key_flag = false;
				break;
			}
		}
	}
	else
	{
		g_key_flag = true;
	}


}

void CObjStory::Draw()
{
	switch (m_StoryScene)
	{
	case 0:
		Draw::Draw2D(20, m_x, m_y);
		break;

	case 1:
		Draw::Draw2D(85, m_x, m_y);
		break;

	case 2:
		Draw::Draw2D(86, m_x, m_y);
		break;
	}

}