//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjGround2.h"
#include "ObjGround.h"

//�R���X�g���N�^
ObjGround2::ObjGround2()
	:m_gx(0), m_gy(0), m_scroll(0.0f)
{
	m_name = GROUND2;

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[0] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[0]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[1] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[1]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[2] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[2]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[3] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[3]->Set4direc(HIT_TOP);

	m_p_hit_line_ground2[0]->SetPos1(m_scroll + 0, m_gy + 400);
	m_p_hit_line_ground2[0]->SetPos2(m_scroll + 494, m_gy + 400);
	m_p_hit_line_ground2[1]->SetPos1(m_scroll + 550, m_gy + 400);
	m_p_hit_line_ground2[1]->SetPos2(m_scroll + 1000, m_gy + 400);
	m_p_hit_line_ground2[2]->SetPos1(m_scroll + 583, m_gy + 374);
	m_p_hit_line_ground2[2]->SetPos2(m_scroll + 609, m_gy + 374);
	m_p_hit_line_ground2[3]->SetPos1(m_scroll + 583, m_gy + 374);
	m_p_hit_line_ground2[3]->SetPos2(m_scroll + 609, m_gy + 374);

	for (int i = 0; i < 4; i++) {
		m_p_hit_line_ground2[i]->SetElement(1);		//������1�ɂ���
		m_p_hit_line_ground2[i]->SetInvisible(false);	//���G���[�h����
		m_p_hit_line_ground2[i]->SetAngle();
	}
}

//�f�X�g���N�^
ObjGround2::~ObjGround2()
{
	
}

//�A�N�V����
void ObjGround2::Action()
{
	//�ʒu�X�V
	m_p_hit_line_ground2[0]->SetPos1(m_scroll + 0, m_gy + 400);  //�ŏ�
	m_p_hit_line_ground2[0]->SetPos2(m_scroll + /*274*/494, m_gy + 400);
	m_p_hit_line_ground2[1]->SetPos1(m_scroll + 550, m_gy + 400);  //0�i��
	m_p_hit_line_ground2[1]->SetPos2(m_scroll + 1000, m_gy + 400);
	m_p_hit_line_ground2[2]->SetPos1(m_scroll + 600, m_gy + 374);  //1�i��
	m_p_hit_line_ground2[2]->SetPos2(m_scroll + 710, m_gy + 374);
	m_p_hit_line_ground2[3]->SetPos1(m_scroll + 600, m_gy + 400);  //0��1��
	m_p_hit_line_ground2[3]->SetPos2(m_scroll + 600, m_gy + 374);
}

//�h���[
void ObjGround2::Draw()
{
	//�X�e�[�W2�n�ʕ`��
	Draw::Draw2D(69,0, 0);

	Draw::Draw2D(58, 693, 374);
}
