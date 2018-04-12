//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Hero.h"

CHero::CHero()
	:m_x(200),m_y(400)
	,m_vx(0.0f),m_vy(0.0f)
	, m_direc(RIGHT)
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
		m_x -= 5.0f;
		m_direc = LEFT;
	}
	else if (Input::KeyPush(VK_RIGHT))
	{
		m_x += 5.0f;
		m_direc = RIGHT;
	}


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
	else if (m_direc == RIGHT)
	{
		Draw::Draw2D(0, m_x, m_y);
	}
	else if (m_direc == LEFT)
	{
		Draw::Draw2D(1, m_x, m_y);
	}
}