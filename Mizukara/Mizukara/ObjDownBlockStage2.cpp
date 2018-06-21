//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjDownBlockStage2.h"
#include "ObjGround2.h"



ObjDownBlockStage2::ObjDownBlockStage2()
	:m_x(1015), m_y(180), m_gx(1010), m_gy(135), m_RopeSizeScaffold(0.25f)
{
	m_name = DOWNBLOCKSTAGE2;

	//����q�b�g���C���쐬���A�l��ݒ�(��)
	m_hit_line_DwBlS2[0] = Collision::HitLineInsert(this);
	m_hit_line_DwBlS2[0]->SetPos1(m_x, m_y);
	m_hit_line_DwBlS2[0]->SetPos2(m_x, m_y+40);
	m_hit_line_DwBlS2[0]->Set4direc(HIT_LEFT);

	//����q�b�g���C���쐬���A�l��ݒ�(�E)
	m_hit_line_DwBlS2[1] = Collision::HitLineInsert(this);
	m_hit_line_DwBlS2[1]->SetPos1(m_x+45, m_y);
	m_hit_line_DwBlS2[1]->SetPos2(m_x+45, m_y+40);
	m_hit_line_DwBlS2[1]->Set4direc(HIT_RIGHT);

	//����q�b�g���C���쐬���A�l��ݒ�(��)
	m_hit_line_DwBlS2[2] = Collision::HitLineInsert(this);
	m_hit_line_DwBlS2[2]->SetPos1(m_x, m_y);
	m_hit_line_DwBlS2[2]->SetPos2(m_x+45, m_y);
	m_hit_line_DwBlS2[2]->Set4direc(HIT_TOP);

	//����q�b�g���C���쐬���A�l��ݒ�(��)
	m_hit_line_DwBlS2[3] = Collision::HitLineInsert(this);
	m_hit_line_DwBlS2[3]->SetPos1(m_x, m_y+40);
	m_hit_line_DwBlS2[3]->SetPos2(m_x+45, m_y+40);
	m_hit_line_DwBlS2[3]->Set4direc(HIT_UNDER);

	for (int i = 0; i < 4; i++) {
		m_hit_line_DwBlS2[i]->SetElement(1);		//������1�ɂ���
		m_hit_line_DwBlS2[i]->SetInvisible(false);	//���G���[�h����
		m_hit_line_DwBlS2[i]->SetAngle();
	}

}


ObjDownBlockStage2::~ObjDownBlockStage2()
{

}

void ObjDownBlockStage2::Action()
{
	ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);

	//�ʒu�X�V
	m_hit_line_DwBlS2[0]->SetPos1(m_x + ground2->GetScroll(), m_y);
	m_hit_line_DwBlS2[0]->SetPos2(m_x + ground2->GetScroll(), m_y+40);
	m_hit_line_DwBlS2[1]->SetPos1(m_x + ground2->GetScroll()+45, m_y);
	m_hit_line_DwBlS2[1]->SetPos2(m_x + ground2->GetScroll()+45, m_y+40);
	m_hit_line_DwBlS2[2]->SetPos1(m_x + ground2->GetScroll(), m_y);
	m_hit_line_DwBlS2[2]->SetPos2(m_x + ground2->GetScroll()+45, m_y);
	m_hit_line_DwBlS2[3]->SetPos1(m_x + ground2->GetScroll(), m_y+40);
	m_hit_line_DwBlS2[3]->SetPos2(m_x + ground2->GetScroll()+45, m_y+40);

}

void ObjDownBlockStage2::Draw()
{
	ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);

	//���[�v�\��
	Draw::Draw2D(62, m_x + 20 + ground2->GetScroll(), 100, 1, m_RopeSizeScaffold);
	//����̃u���b�N�\��
	Draw::Draw2D(58, m_x-4 + ground2->GetScroll(), m_y);
}
