//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjGround.h"

CObjGround::CObjGround()
	:m_x(0), m_y(405)
{
	//�q�b�g�{�b�N�X�쐬()
	m_p_hit_line = Collision::HitLineInsert(this);
	//�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line->SetPos1(m_x, m_y);
	m_p_hit_line->SetPos2(m_x+800, m_y);
	m_p_hit_line->SetElement(1);		//������1�ɂ���
	m_p_hit_line->SetInvisible(false);	//���G���[�h����
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