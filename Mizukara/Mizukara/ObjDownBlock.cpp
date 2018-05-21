//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjDownBlock.h"
#include "ObjGround.h"



ObjDownBlock::ObjDownBlock()
	:m_x(840), m_y(280)
{
	//����q�b�g���C���쐬���A�l��ݒ�(��)
	m_hit_line_DwBl[0] = Collision::HitLineInsert(this);
	m_hit_line_DwBl[0]->SetPos1(m_x, m_y);
	m_hit_line_DwBl[0]->SetPos2(m_x, m_y + 40);
	m_hit_line_DwBl[0]->Set4direc(HIT_LEFT);

	//����q�b�g���C���쐬���A�l��ݒ�(�E)
	m_hit_line_DwBl[1] = Collision::HitLineInsert(this);
	m_hit_line_DwBl[1]->SetPos1(m_x + 60, m_y);
	m_hit_line_DwBl[1]->SetPos2(m_x + 60, m_y + 40);
	m_hit_line_DwBl[1]->Set4direc(HIT_RIGHT);

	//����q�b�g���C���쐬���A�l��ݒ�(��)
	m_hit_line_DwBl[2] = Collision::HitLineInsert(this);
	m_hit_line_DwBl[2]->SetPos1(m_x, m_y);
	m_hit_line_DwBl[2]->SetPos2(m_x + 60, m_y);
	m_hit_line_DwBl[2]->Set4direc(HIT_TOP);

	//����q�b�g���C���쐬���A�l��ݒ�(��)
	m_hit_line_DwBl[3] = Collision::HitLineInsert(this);
	m_hit_line_DwBl[3]->SetPos1(m_x, m_y + 40);
	m_hit_line_DwBl[3]->SetPos2(m_x + 60, m_y + 40);
	m_hit_line_DwBl[3]->Set4direc(HIT_UNDER);

	for (int i = 0; i < 4; i++) {
		m_hit_line_DwBl[i]->SetElement(1);		//������1�ɂ���
		m_hit_line_DwBl[i]->SetInvisible(false);	//���G���[�h����
		m_hit_line_DwBl[i]->SetAngle();
	}

}


ObjDownBlock::~ObjDownBlock()
{
}

void ObjDownBlock::Action()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	//�ʒu�X�V
	m_hit_line_DwBl[0]->SetPos1(m_x + ground->GetScroll(), m_y);
	m_hit_line_DwBl[0]->SetPos2(m_x + ground->GetScroll(), m_y + 40);
	m_hit_line_DwBl[1]->SetPos1(m_x + ground->GetScroll() + 60, m_y);
	m_hit_line_DwBl[1]->SetPos2(m_x + ground->GetScroll() + 60, m_y + 40);
	m_hit_line_DwBl[2]->SetPos1(m_x + ground->GetScroll(), m_y);
	m_hit_line_DwBl[2]->SetPos2(m_x + ground->GetScroll() + 60, m_y);
	m_hit_line_DwBl[3]->SetPos1(m_x + ground->GetScroll(), m_y + 40);
	m_hit_line_DwBl[3]->SetPos2(m_x + ground->GetScroll() + 60, m_y + 40);

}

void ObjDownBlock::Draw()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);


}