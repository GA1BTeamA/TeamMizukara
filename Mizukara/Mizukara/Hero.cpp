//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Hero.h"

extern int g_SceneNumber;
extern bool g_key_flag;

//�R���X�g���N�^
CHero::CHero()
	:m_x(200),m_y(300)
	,m_vx(0.0f),m_vy(0.0f)
	, m_direc(RIGHT), m_down(false), m_IsMenu(false),
	m_ani_time (0)
{
	m_name = PLAYER;

	//��l���q�b�g���C���쐬(��)
	m_p_hit_line_hero[0] = Collision::HitLineInsert(this);
	//�쐬�����q�b�g���C���̒l��ݒ�
	m_p_hit_line_hero[0]->SetPos1(m_x, m_y);
	m_p_hit_line_hero[0]->SetPos2(m_x, m_y+100);
	m_p_hit_line_hero[0]->SetElement(0);		//������0�ɂ���
	m_p_hit_line_hero[0]->SetInvisible(false);	//���G���[�h����

	//��l���q�b�g���C���쐬(�E)
	m_p_hit_line_hero[1] = Collision::HitLineInsert(this);
	//�쐬�����q�b�g���C���̒l��ݒ�
	m_p_hit_line_hero[1]->SetPos1(m_x+60, m_y);
	m_p_hit_line_hero[1]->SetPos2(m_x+60, m_y + 100);
	m_p_hit_line_hero[1]->SetElement(0);		//������0�ɂ���
	m_p_hit_line_hero[1]->SetInvisible(false);	//���G���[�h����

	//��q�b�g���C���쐬
	m_p_hit_line_hero[2] = Collision::HitLineInsert(this);
	//�쐬�����q�b�g���C���̒l��ݒ�
	m_p_hit_line_hero[2]->SetPos1(m_x, m_y);
	m_p_hit_line_hero[2]->SetPos2(m_x + 60, m_y);
	m_p_hit_line_hero[2]->SetElement(0);		//������0�ɂ���
	m_p_hit_line_hero[2]->SetInvisible(false);	//���G���[�h����
	
	//��l���R�s�[�q�b�g���C���쐬(��)
	m_p_hit_line_hero_copy[0] = m_p_hit_line_hero[0];
	
	//��l���R�s�[�q�b�g���C���쐬(�E)
	m_p_hit_line_hero_copy[1] = m_p_hit_line_hero[1];
}

CHero::~CHero()
{
}

void CHero::Action()
{
	////�e�X�g
	//float a, b;
	//CCollision::LineCrossPoint(0, 0, 10, 10, 0, 5, 10, 5, &a, &b);
	//int aa = 0;
	//aa++;

	//���j���[
	if (Input::KeyPush('Q'))
	{
		if (m_menu_key_flag)
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
			m_menu_key_flag = false;
		}
	}
	else m_menu_key_flag = true;

	if (m_IsMenu == false)
	{
		//�f�o�b�O�p
		/*if (Input::KeyPush(VK_UP))
		{
			m_y -= 5.0f;

		}

		if (Input::KeyPush(VK_DOWN))
		{
			m_y += 5.0f;

		}*/

	//��̐���--------------
	//	CObjGround ground;
	//----------------------


		//�n�ʂɓ���������A
		for (int i = 0; i < 10; i++)
		{
			//if (m_p_hit_line[0]->GetHitData()[i] != nullptr|| m_p_hit_line[1]->GetHitData()[i] != nullptr)
			//{
			if (m_p_hit_line_hero_copy[0]->GetHitData()[i] == nullptr)
				continue;

			if (m_p_hit_line_hero_copy[1]->GetHitData()[i] == nullptr)
				continue;

			if (m_p_hit_line_hero_copy[0]->GetHitData()[i]->GetElement() == 1||
				m_p_hit_line_hero_copy[1]->GetHitData()[i]->GetElement() == 1)
			{
				CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);
				if (ground != nullptr)
				{
					m_y = ground->GetGY() - 100;
					//m_y = 300;
					m_vy = 0;
					if (Input::KeyPush(VK_SPACE) == true)
					{
						if (m_down == false)
						{
							m_vy = -8;
						}
					}
				}
				//else if (m_p_hit_line->GetElement() == 1)
				//{
				//	m_x-=60
				//}
			}
		}

		//���U���g��ʂɂ�������
		//if (m_x + 60 >= 800)
		//{
		//	g_SceneNumber = RESULT;
		//	is_delete = true;
		//	g_key_flag = false;
		//}

		//if (m_p_hit_line->GetHitData()[1] != nullptr)
		//{
		//	m_x -= 1.0f;
		//}

		//���L�[�ňړ�
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
		//�E�L�[�ňړ�
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

		//���R�����^��
		m_vy += 9.8 / (16.0f);

		m_y += m_vy;

		//�����蔻��̈ʒu�X�V
		m_p_hit_line_hero[0]->SetPos1(m_x, m_y);
		m_p_hit_line_hero[0]->SetPos2(m_x, m_y + 100);
		m_p_hit_line_hero[1]->SetPos1(m_x + 60, m_y);
		m_p_hit_line_hero[1]->SetPos2(m_x + 60, m_y + 100);
		m_p_hit_line_hero[2]->SetPos1(m_x, m_y);
		m_p_hit_line_hero[2]->SetPos2(m_x + 60, m_y);
		m_p_hit_line_hero_copy[0]->SetPos1(m_x, m_y);
		m_p_hit_line_hero_copy[0]->SetPos2(m_x, m_y + 100);
		m_p_hit_line_hero_copy[1]->SetPos1(m_x + 60, m_y);
		m_p_hit_line_hero_copy[1]->SetPos2(m_x + 60, m_y + 100);
	}

	//�A�j���[�V����
	if (Input::KeyPush(VK_RIGHT) || Input::KeyPush(VK_LEFT))
	{
		m_ani_time++;
		if (m_ani_time >= 24)
		{
			m_ani_time = 0;
		}
	}
	else 
    {
		m_ani_time = 0;
	}


}

void CHero::Draw()
{
	//�`��
	if (m_IsMenu)
	{
		if (m_direc == RIGHT)
		{
				Draw::Draw2D(7, m_x, m_y);
		}
		else if (m_direc == LEFT)
		{
				Draw::Draw2D(8, m_x, m_y);
		}
	}
	else 
	{
		if (Input::KeyPush(VK_LEFT))
		{
			if (m_ani_time <= 6) {
				Draw::Draw2D(3, m_x, m_y);
			}
			else if (m_ani_time <= 12) {
				Draw::Draw2D(1, m_x, m_y);
			}
			else if (m_ani_time <= 18) {
				Draw::Draw2D(8, m_x, m_y);
			}
			else {
				Draw::Draw2D(1, m_x, m_y);
			}
		}
		else if (Input::KeyPush(VK_RIGHT))
		{
			if (m_ani_time <= 6) {
				Draw::Draw2D(2, m_x, m_y);
			}
			else if (m_ani_time <= 12) {
				Draw::Draw2D(0, m_x, m_y);
			}
			else if (m_ani_time <= 18) {
				Draw::Draw2D(7, m_x, m_y);
			}
			else {
				Draw::Draw2D(0, m_x, m_y);
			}
		}
		else if (Input::KeyPush('X'))
		{
			Draw::Draw2D(0, m_x, m_y);
		}
		else if (Input::KeyPush('C'))
		{
			Draw::Draw2D(0, m_x, m_y);
		}
		/*else if (Input::KeyPush(VK_SPACE))
		{
			Draw::Draw2D(6, m_x, m_y);
		}*/
		else if (m_direc == RIGHT)
		{
			Draw::Draw2D(0, m_x, m_y);
		}
		else if (m_direc == LEFT)
		{
			Draw::Draw2D(1, m_x, m_y);
		}

		/*if (RIGHT || LEFT) {
			if (m_ani_time <= 6) {
				Draw::Draw2D(7, m_x, m_y);
			}
			else {
				Draw::Draw2D(8, m_x, m_y);
			}
		}*/
		//if (m_p_hit_line->GetHitData()[0]!=nullptr)
		//{
		//	Draw::Draw2D(6, m_x, m_y);
		//}
	}
}