//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Hero.h"

extern bool g_key_flag;

//�R���X�g���N�^
CHero::CHero()
	:m_x(200),m_y(300)
	,m_vx(0.0f),m_vy(0.0f)
	, m_direc(RIGHT), m_down(false), m_IsMenu(false)
{
	m_name = PLAYER;
	//�q�b�g���C���쐬
	m_p_hit_line = Collision::HitLineInsert(this);
	//�쐬�����q�b�g���C���̒l��ݒ�
	m_p_hit_line->SetPos1(m_x, m_y);
	m_p_hit_line->SetPos2(m_x, m_y+100);
	m_p_hit_line->SetElement(0);		//������0�ɂ���
	m_p_hit_line->SetInvisible(false);	//���G���[�h����
}

CHero::~CHero()
{

}

void CHero::Action()
{
	//���j���[
	if (Input::KeyPush('Q'))
	{
		if (g_key_flag)
		{
			//���j���[�I�u�W�F�N�g�𐶐�
			if (m_IsMenu == false)
			{
				menu = new CMenu();
				menu->m_priority = 100;
				TaskSystem::InsertObj(menu);
				m_IsMenu = true;
			}
			//���j���[�I�u�W�F�N�g��j��
			else
			{

				//�I�u�W�F�N�g�擾
				CMenu* menu = (CMenu*)TaskSystem::GetObj(MENU);
				if (menu != nullptr)
				{
					menu->is_delete = true;
					m_IsMenu = false;
				}
			}
			g_key_flag = false;
		}
	}
	else g_key_flag = true;

	if (m_IsMenu == false)
	{
		//�f�o�b�O�p
		if (Input::KeyPush(VK_UP))
		{
			m_y -= 5.0f;

		}

		if (Input::KeyPush(VK_DOWN))
		{
			m_y += 5.0f;

		}

		//�n�ʂɓ���������A
		for (int i = 0; i < 10; i++)
		{
			if (m_p_hit_line->GetHitData()[i] != nullptr)
			{
				if (m_p_hit_line->GetElement() == 0)
				{
					m_y = 300;
					m_vy = 0;
				}
				else if (m_p_hit_line->GetElement() == 1)
				{
					//m_x -= 1.0f;
				}
			}
		}

		//if (m_p_hit_line->GetHitData()[1] != nullptr)
		//{
		//	m_x -= 1.0f;
		//}

		//�폜���s
		if (Input::KeyPush(VK_LEFT))
		{
			if (Input::KeyPush('V'))
			{
				m_x -= 7.5f;//V�L�[�Ń_�b�V��
			}
			else
			{
				m_x -= 5.0f;
			}
			m_direc = LEFT;
		}
		else if (Input::KeyPush(VK_RIGHT))
		{
			if (Input::KeyPush('V'))
			{
				m_x += 7.5f;//V�L�[�Ń_�b�V��
			}
			else
			{
				m_x += 5.0f;
			}
			m_direc = RIGHT;
		}

		//space�L�[���͂ŃW�����v
		if (Input::KeyPush(VK_SPACE) == true)
		{
			if (m_down == false)
			{
				m_vy = -5;
			}
		}

		//���R�����^��
		m_vy += 9.8 / (16.0f);

		m_y += m_vy;

		//�����蔻��̈ʒu�X�V
		m_p_hit_line->SetPos1(m_x, m_y);
		m_p_hit_line->SetPos2(m_x, m_y + 100);
	}
}

void CHero::Draw()
{
	//�`��
	if (m_IsMenu)
	{
		if (m_direc == RIGHT)
		{
			Draw::Draw2D(0, m_x, m_y);
		}
		else if (m_direc == LEFT)
		{
			Draw::Draw2D(1, m_x, m_y);
		}
	}
	else 
	{
		if (Input::KeyPush(VK_LEFT))
		{
			Draw::Draw2D(3, m_x, m_y);
		}
		else if (Input::KeyPush(VK_RIGHT))
		{
			Draw::Draw2D(2, m_x, m_y);
		}
		else if (Input::KeyPush('X'))
		{
			Draw::Draw2D(4, m_x, m_y);
		}
		else if (Input::KeyPush('C'))
		{
			Draw::Draw2D(5, m_x, m_y);
		}
		else if (Input::KeyPush(VK_SPACE))
		{
			Draw::Draw2D(6, m_x, m_y);
		}
		else if (m_direc == RIGHT)
		{
			Draw::Draw2D(0, m_x, m_y);
		}
		else if (m_direc == LEFT)
		{
			Draw::Draw2D(1, m_x, m_y);
		}

		//if (m_p_hit_line->GetHitData()[0]!=nullptr)
		//{
		//	Draw::Draw2D(6, m_x, m_y);
		//}
	}
}