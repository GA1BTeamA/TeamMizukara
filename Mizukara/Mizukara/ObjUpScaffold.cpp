//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjUpScaffold.h"
#include "ObjGround.h"



ObjUpScaffold::ObjUpScaffold()
	:m_x(500),m_y(350)
{
	//����q�b�g���C���쐬���A�l��ݒ�(��)
	m_hit_line_UpSc[0] = Collision::HitLineInsert(this);
	m_hit_line_UpSc[0]->SetPos1(m_x, m_y);
	m_hit_line_UpSc[0]->SetPos2(m_x, m_y + 50);
	m_hit_line_UpSc[0]->Set4direc(HIT_LEFT);

	//����q�b�g���C���쐬���A�l��ݒ�(�E)
	m_hit_line_UpSc[1] = Collision::HitLineInsert(this);
	m_hit_line_UpSc[1]->SetPos1(m_x + 100, m_y);
	m_hit_line_UpSc[1]->SetPos2(m_x + 100, m_y + 50);
	m_hit_line_UpSc[1]->Set4direc(HIT_RIGHT);

	//����q�b�g���C���쐬���A�l��ݒ�(��)
	m_hit_line_UpSc[2] = Collision::HitLineInsert(this);
	m_hit_line_UpSc[2]->SetPos1(m_x, m_y);
	m_hit_line_UpSc[2]->SetPos2(m_x + 100, m_y);
	m_hit_line_UpSc[2]->Set4direc(HIT_TOP);

	//����q�b�g���C���쐬���A�l��ݒ�(��)
	m_hit_line_UpSc[3] = Collision::HitLineInsert(this);
	m_hit_line_UpSc[3]->SetPos1(m_x, m_y + 50);
	m_hit_line_UpSc[3]->SetPos2(m_x + 100, m_y + 50);
	m_hit_line_UpSc[3]->Set4direc(HIT_UNDER);

	for (int i = 0; i < 4; i++) {
		m_hit_line_UpSc[i]->SetElement(1);		//������1�ɂ���
		m_hit_line_UpSc[i]->SetInvisible(false);	//���G���[�h����
		m_hit_line_UpSc[i]->SetAngle();
	}

}


ObjUpScaffold::~ObjUpScaffold()
{
}

void ObjUpScaffold::Action()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	//�ʒu�X�V
	m_hit_line_UpSc[0]->SetPos1(m_x + ground->GetScroll(), m_y);
	m_hit_line_UpSc[0]->SetPos2(m_x + ground->GetScroll(), m_y + 50);
	m_hit_line_UpSc[1]->SetPos1(m_x + ground->GetScroll() + 100, m_y);
	m_hit_line_UpSc[1]->SetPos2(m_x + ground->GetScroll() + 100, m_y + 50);
	m_hit_line_UpSc[2]->SetPos1(m_x + ground->GetScroll(), m_y);
	m_hit_line_UpSc[2]->SetPos2(m_x + ground->GetScroll() + 100, m_y);
	m_hit_line_UpSc[3]->SetPos1(m_x + ground->GetScroll(), m_y + 50);
	m_hit_line_UpSc[3]->SetPos2(m_x + ground->GetScroll() + 100, m_y + 50);

}

void ObjUpScaffold::Draw()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);


}
