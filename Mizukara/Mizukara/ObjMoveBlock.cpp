//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjMoveBlock.h"
#include "ObjGround.h"

//�R���X�g���N�^
ObjMoveBlock::ObjMoveBlock()
	:m_x(1794), m_y(234)
{
	m_name = MOVEBLOCK;

	//����q�b�g���C���쐬���A�l��ݒ�(��)
	m_hit_line_MoBl[0] = Collision::HitLineInsert(this);
	m_hit_line_MoBl[0]->SetPos1(m_x, m_y);
	m_hit_line_MoBl[0]->SetPos2(m_x, m_y + 32);
	m_hit_line_MoBl[0]->Set4direc(HIT_LEFT);

	//����q�b�g���C���쐬���A�l��ݒ�(�E)
	m_hit_line_MoBl[1] = Collision::HitLineInsert(this);
	m_hit_line_MoBl[1]->SetPos1(m_x + 50, m_y);
	m_hit_line_MoBl[1]->SetPos2(m_x + 50, m_y + 32);
	m_hit_line_MoBl[1]->Set4direc(HIT_RIGHT);

	//����q�b�g���C���쐬���A�l��ݒ�(��)
	m_hit_line_MoBl[2] = Collision::HitLineInsert(this);
	m_hit_line_MoBl[2]->SetPos1(m_x, m_y);
	m_hit_line_MoBl[2]->SetPos2(m_x + 50, m_y);
	m_hit_line_MoBl[2]->Set4direc(HIT_TOP);

	//����q�b�g���C���쐬���A�l��ݒ�(��)
	m_hit_line_MoBl[3] = Collision::HitLineInsert(this);
	m_hit_line_MoBl[3]->SetPos1(m_x, m_y + 32);
	m_hit_line_MoBl[3]->SetPos2(m_x + 50, m_y + 32);
	m_hit_line_MoBl[3]->Set4direc(HIT_UNDER);

	for (int i = 0; i < 4; i++) {
		m_hit_line_MoBl[i]->SetElement(1);		//������1�ɂ���
		m_hit_line_MoBl[i]->SetInvisible(false);	//���G���[�h����
		m_hit_line_MoBl[i]->SetAngle();
	}
}

//�f�X�g���N�^
ObjMoveBlock::~ObjMoveBlock()
{

}

//�A�N�V����
void ObjMoveBlock::Action()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	//�ʒu�X�V
	m_hit_line_MoBl[0]->SetPos1(m_x + ground->GetScroll(), m_y);
	m_hit_line_MoBl[0]->SetPos2(m_x + ground->GetScroll(), m_y + 32);
	m_hit_line_MoBl[1]->SetPos1(m_x + ground->GetScroll() + 50, m_y);
	m_hit_line_MoBl[1]->SetPos2(m_x + ground->GetScroll() + 50, m_y + 32);
	m_hit_line_MoBl[2]->SetPos1(m_x + ground->GetScroll(), m_y);
	m_hit_line_MoBl[2]->SetPos2(m_x + ground->GetScroll() + 50, m_y);
	m_hit_line_MoBl[3]->SetPos1(m_x + ground->GetScroll(), m_y + 32);
	m_hit_line_MoBl[3]->SetPos2(m_x + ground->GetScroll() + 50, m_y + 32);

}

//�h���[
void ObjMoveBlock::Draw()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	Draw::Draw2D(62, m_x + 23 + ground->GetScroll(), m_y-360, 1, 1);

	Draw::Draw2D(61, m_x + ground->GetScroll(), m_y-20);
}
