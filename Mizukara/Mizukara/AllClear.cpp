//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "AllClear.h"
extern int g_SceneNumber;
extern bool g_key_flag;
extern bool g_clearlist;

CAllClear::CAllClear()
	:m_x(0), m_y(-600), m_vy(1.0f),m_sy(450.0f),m_svy(0.0f), m_ani_time(0)
{

}

CAllClear::~CAllClear()
{

}

void CAllClear::Action()
{

	//���ԉ��Z
	if (m_ani_time < 600.0f)m_ani_time++;

	//�W�����v����^�C�~���O
	if (m_ani_time%50 == 0 && m_sy == 450.0f)
	{
		m_svy = -8.0f;
	}

	//�d��
	m_svy += 9.8 / (16.0f);
	m_sy += m_svy;
	//�n�ʂ𒴂������Ȃ�
	if (m_sy > 450) { m_sy = 450; m_svy = 0.0f; }

	if (m_ani_time > 510.0f) {
		//��X�N���[��		
		m_y = -300 + 300*(-cos(3.14 / 180 * (m_ani_time - 510)*2));
	}

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

void CAllClear::Draw()
{
	//�w�i�`��
	Draw::Draw2D(98, m_x, m_y);

	if (m_sy <= 420)
	{
		Draw::Draw2D(9, m_x + 250, m_sy + m_y + 600);//�W�����v
		Draw::Draw2D(116, m_x + 520, 370 + m_y + 600);//�����������
	}
	else
	{
		Draw::Draw2D(72, m_x + 250, m_sy + m_y + 600);
		Draw::Draw2D(115, m_x + 520, 370 + m_y + 600);
	}

}