//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Hero.h"

CHero::CHero()
	:m_x(200),m_y(310)
	,m_vx(0.0f),m_vy(0.0f)
	, m_direc(RIGHT), m_down(false)
{
	//HERO�I�u�W�F�N�g�̊e�����蔻��̑������o���o���ɂ���
	static int count = 0;
	count++;

	//�q�b�g�{�b�N�X�쐬()
	m_p_hit_box = Collision::HitBoxInsert(this);
	//�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_box->SetPos(m_x, m_y);
	m_p_hit_box->SetWH(60.0f, 100.0f);
	m_p_hit_box->SetElement(count);		//������count�ɂ���
	m_p_hit_box->SetInvisible(false);	//���G���[�h����
}

CHero::~CHero()
{

}

void CHero::Action()
{
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
			m_vy = -20;
		}
	}

	/*//���R�����^��
	m_vy += 9.8 / (16.0f);

	m_y += m_vy;
	*/
	//�����蔻��̈ʒu�X�V
	m_p_hit_box->SetPos(m_x, m_y);
}

void CHero::Draw()
{
	//�`��
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
}