//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjGround.h"

CObjGround::CObjGround()
	:m_gx(0), m_gy(400)
{
	m_name = GROUND;

	//�q�b�g�{�b�N�X�쐬()
	m_p_hit_line[0] = Collision::HitLineInsert(this);
	//�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line[0]->SetPos1(m_gx, m_gy);
	m_p_hit_line[0]->SetPos2(m_gx+800, m_gy);
	m_p_hit_line[0]->SetElement(1);		//������1�ɂ���
	m_p_hit_line[0]->SetInvisible(false);	//���G���[�h����

	//�q�b�g�{�b�N�X�쐬()
	m_p_hit_line[1] = Collision::HitLineInsert(this);
	//�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line[1]->SetPos1(m_gx+500, m_gy-90);
	m_p_hit_line[1]->SetPos2(m_gx + 800, m_gy-90);
	m_p_hit_line[1]->SetElement(1);		//������1�ɂ���
	m_p_hit_line[1]->SetInvisible(false);	//���G���[�h����

	////�q�b�g�{�b�N�X�쐬()
	//m_p_hit_line[2] = Collision::HitLineInsert(this);
	////�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	//m_p_hit_line[2]->SetPos1(m_gx + 700, m_gy - 90);
	//m_p_hit_line[2]->SetPos2(m_gx + 700, m_gy);
	//m_p_hit_line[2]->SetElement(1);		//������1�ɂ���
	//m_p_hit_line[2]->SetInvisible(false);	//���G���[�h����

}

CObjGround::~CObjGround()
{

}

void CObjGround::Action()
{

}

void CObjGround::Draw()
{
	Draw::Draw2D(18, 0, 0);
}