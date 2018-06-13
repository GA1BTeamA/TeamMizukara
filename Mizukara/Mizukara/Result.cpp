//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Result.h"
#include "Hero.h"

extern int g_SceneNumber;
extern bool g_key_flag;
extern float g_TankRemaining;
extern bool g_clearlist;

//�R���X�g���N�^
CResult::CResult()
	:m_x(0), m_y(0), m_cursor(UP)
{
	m_name = RESULT;
}

CResult::~CResult()
{

}

void CResult::Action()
{
	Audio::StopLoopMusic(6);

	Audio::StartLoopMusic(10);
	Audio::LoopMusicVolume(10, 0.07f);

	//����������獶��
	if (Input::KeyPush(VK_UP) == true)
	{
		m_cursor = UP;
	}
	//������������E��
	else if (Input::KeyPush(VK_DOWN) == true)
	{
		m_cursor = UNDER;
	}
	/*//�����������牺��
	else if (Input::KeyPush(VK_DOWN) == true)
	{
		if (m_cursor != UNDER)
			m_BefCursor = m_cursor;
		m_cursor = UNDER;
	}
	else if (Input::KeyPush(VK_UP) == true && m_cursor == UNDER)
	{
		m_cursor = m_BefCursor;
	}*/

	//�J�[�\���ʒu����Ȃ�^�C�g����
	if (m_cursor == UP)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				Audio::StartMusic(0);
				Audio::StopLoopMusic(10);
				g_SceneNumber = TITLE;
				g_clearlist = true;
				TaskSystem::TaskClear();
				is_delete = true;
				g_key_flag = false;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}
	//�J�[�\���ʒu�����Ȃ�X�e�[�W�Z���N�g��
	else if (m_cursor == UNDER)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				Audio::StartMusic(0);
				Audio::StopLoopMusic(10);
				g_SceneNumber = STAGESELECTO;
				g_clearlist = true;
				TaskSystem::TaskClear();
				is_delete = true;
				g_key_flag = false;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}
	//�J�[�\���ʒu�����Ȃ�(��蒼��)
	/*else if (m_cursor == UNDER)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				g_SceneNumber = GAME;
				TaskSystem::TaskClear();
				g_key_flag = false;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}*/
}

void CResult::Draw()
{
	//CSPRI* spri = (CSPRI*)TaskSystem::GetObj(SPRI);

	Draw::Draw2D(101, m_x, m_y);

	if (m_cursor == UP)
	{
		Draw::Draw2D(14, 295, 90);
	}
	else if (m_cursor == UNDER)
	{
		Draw::Draw2D(14, 300, 215);
	}
	else {
		Draw::Draw2D(14,295, 90);
	}

	//�����N�\��
	if (g_TankRemaining >= 80)
	{
		Draw::Draw2D(108, 100, 200);
	}
	else if (g_TankRemaining >= 70)
	{
		Draw::Draw2D(107, 100, 200);
	}
	else if (g_TankRemaining >= 50)
	{
		Draw::Draw2D(106, 100, 200);
	}
	else if (g_TankRemaining >= 30)
	{
		Draw::Draw2D(105, 100, 200);
	}
	else if (g_TankRemaining >= 10)
	{
		Draw::Draw2D(104, 100, 200);
	}
}