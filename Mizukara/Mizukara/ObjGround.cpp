//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjGround.h"
#include "Hero.h"

CObjGround::CObjGround()
	:m_gx(0), m_gy(400), m_scroll(0.0f)
{
	m_name = GROUND;

	//�q�b�g�{�b�N�X�쐬()
	m_p_hit_line_ground[0] = Collision::HitLineInsert(this);
	//�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[0]->SetPos1(m_gx, m_gy);
	m_p_hit_line_ground[0]->SetPos2(m_gx+800, m_gy);
	m_p_hit_line_ground[0]->SetElement(1);		//������1�ɂ���
	m_p_hit_line_ground[0]->SetInvisible(false);	//���G���[�h����

	/*//�q�b�g�{�b�N�X�쐬()
	m_p_hit_line[1] = Collision::HitLineInsert(this);
	//�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[1]->SetPos1(m_gx+500, m_gy-90);
	m_p_hit_line_ground[1]->SetPos2(m_gx + 800, m_gy-90);
	m_p_hit_line_ground[1]->SetElement(1);		//������1�ɂ���
	m_p_hit_line_ground[1]->SetInvisible(false);	//���G���[�h����

	////�q�b�g�{�b�N�X�쐬()
	//m_p_hit_line[2] = Collision::HitLineInsert(this);
	////�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	//m_p_hit_line_ground[2]->SetPos1(m_gx + 700, m_gy - 90);
	//m_p_hit_line_ground[2]->SetPos2(m_gx + 700, m_gy);
	//m_p_hit_line_ground[2]->SetElement(1);		//������1�ɂ���
	//m_p_hit_line_ground[2]->SetInvisible(false);	//���G���[�h����*/

}

CObjGround::~CObjGround()
{

}

void CObjGround::Action()
{
	CHero* hero = (CHero*)TaskSystem::GetObj(PLAYER);
	float m_x = hero->GetX();
	float m_y = hero->GetY();

	/*if (hero != nullptr)
	{
		hero->is_delete = true;
		//m_IsHero = false;
	}*/

	//m_scroll = -3.0f;//�X�N���[��

	//�O���X�N���[�����C��
	if (m_x > 350)
	{
		//�[����������X�e�[�W�[�����Ȃ��悤�ɂ���
		if (m_scroll <= -1600)
		{
			m_scroll = -1600.0f;
		}
		else
		{
			hero->SetX(350);   //��l�����w��̈�𒴂��Ȃ��悤��

			if (Input::KeyPush('V')) //�_�b�V�����Ă鎞�̃X�N���[��
			{
				m_scroll -= hero->GetDashX();   //��l�����{�������ׂ��l��m_scroll�ɉ�����
			}
			else  //�����Ă��鎞�̃X�N���[��
			{
				m_scroll -= hero->GetMoveX();  //��l�����{�������ׂ��l��m_scroll�ɉ�����
			}
		}
	}

		//����X�N���[�����C��
		if (m_x < 200)
		{
			//�[����������X�e�[�W�[�����Ȃ��悤�ɂ���
			if (m_scroll >= 0)
			{
				m_scroll = 0.0f;
			}
			else
			{
				hero->SetX(200);   //��l�����w��̈�𒴂��Ȃ��悤��

				if (Input::KeyPush('V')) //�_�b�V�����Ă鎞�̃X�N���[��
				{
					m_scroll += hero->GetDashX();   //��l�����{�������ׂ��l��m_scroll�ɉ�����
		
				}
				else  //�����Ă��鎞�̃X�N���[��
				{
					m_scroll += hero->GetMoveX();   //��l�����{�������ׂ��l��m_scroll�ɉ�����
				}
			}
	}
}

void CObjGround::Draw()
{


	Draw::Draw2D(22, m_gx+m_scroll, 0);
}