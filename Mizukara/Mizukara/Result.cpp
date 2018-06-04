//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Result.h"
#include "Hero.h"

extern int g_SceneNumber;
extern bool g_key_flag;
extern float g_TankRemaining;

//�R���X�g���N�^
CResult::CResult()
	:m_x(0), m_y(0), m_cursor(LEFT)
{
	//m_name = RESULT;
}

CResult::~CResult()
{

}

void CResult::Action()
{
	Audio::StopLoopMusic(6);

	Audio::StartLoopMusic(10);
	Audio::LoopMusicVolume(10, 0.07f);

	//�����������獶��
	if (Input::KeyPush(VK_LEFT) == true)
	{
		m_cursor = LEFT;
	}
	//�E����������E��
	else if (Input::KeyPush(VK_RIGHT) == true)
	{
		m_cursor = RIGHT;
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

	//�J�[�\���ʒu�����Ȃ�^�C�g����
	if (m_cursor == LEFT)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				Audio::StartMusic(0);
				Audio::StopLoopMusic(10);
				g_SceneNumber = TITLE;
				TaskSystem::TaskClear();
				g_key_flag = false;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}
	//�J�[�\���ʒu���E�Ȃ�X�e�[�W�Z���N�g��
	else if (m_cursor == RIGHT)
	{
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				Audio::StartMusic(0);
				Audio::StopLoopMusic(10);
				g_SceneNumber = STAGESELECTO;
				TaskSystem::TaskClear();
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
	CSPRI* spri = (CSPRI*)TaskSystem::GetObj(SPRI);

	Draw::Draw2D(23, m_x, m_y);

	if (m_cursor == LEFT)
	{
		Draw::Draw2D(14, 100, 345);
	}
	else if (m_cursor == RIGHT)
	{
		Draw::Draw2D(14, 460, 345);
	}
	else {
		;
	}

	//�����N�\��
	if (g_TankRemaining >= 80)
	{
		Font::StrDraw(L"S", 100, 100, 1, 1, 0, 0, 1);
	}
	else if (g_TankRemaining >= 70)
	{
		Font::StrDraw(L"A", 100, 100, 1, 1, 0, 0, 1);
	}
	else if (g_TankRemaining >= 50)
	{
		Font::StrDraw(L"B", 100, 100, 1, 1, 0, 0, 1);
	}
	else if (g_TankRemaining >= 30)
	{
		Font::StrDraw(L"C", 100, 100, 1, 1, 0, 0, 1);
	}
	else if (g_TankRemaining >= 10)
	{
		Font::StrDraw(L"D", 100, 100, 1, 1, 0, 0, 1);
	}
}