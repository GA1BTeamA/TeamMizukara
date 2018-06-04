//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjColorDoor.h"
#include "ObjGround3.h"


//�R���X�g���N�^
ObjColorDoor::ObjColorDoor()
	:m_x(427), m_y(261),m_gx(425), m_gy(261)
{
	m_name = COLORDOOR;

	//�q�b�g���C���쐬���A�l��ݒ�(��)
	m_hit_line_ColorDoor[0] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoor[0]->SetPos1(m_x, m_y);
	m_hit_line_ColorDoor[0]->SetPos2(m_x, m_y + 140);
	m_hit_line_ColorDoor[0]->Set4direc(HIT_LEFT);

	//�q�b�g���C���쐬���A�l��ݒ�(��)
	m_hit_line_ColorDoor[1] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoor[1]->SetPos1(m_x, m_y);
	m_hit_line_ColorDoor[1]->SetPos2(m_x + 26, m_y);
	m_hit_line_ColorDoor[1]->Set4direc(HIT_TOP);

	//�q�b�g���C���쐬���A�l��ݒ�(�E)
	m_hit_line_ColorDoor[2] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoor[2]->SetPos1(m_x + 26, m_y);
	m_hit_line_ColorDoor[2]->SetPos2(m_x + 26, m_y + 140);
	m_hit_line_ColorDoor[2]->Set4direc(HIT_RIGHT);

	//�q�b�g���C���쐬���A�l��ݒ�(��)
	m_hit_line_ColorDoor[3] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoor[3]->SetPos1(m_x, m_y + 140);
	m_hit_line_ColorDoor[3]->SetPos2(m_x + 26, m_y + 140);
	m_hit_line_ColorDoor[3]->Set4direc(HIT_UNDER);

	for (int i = 0; i < 4; i++) {
		m_hit_line_ColorDoor[i]->SetElement(1);		//������1�ɂ���
		m_hit_line_ColorDoor[i]->SetInvisible(false);	//���G���[�h����
		m_hit_line_ColorDoor[i]->SetAngle();
	}
}

//�f�X�g���N�^
ObjColorDoor::~ObjColorDoor()
{

}

//�A�N�V����
void ObjColorDoor::Action()
{
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	//�ʒu�X�V
	m_hit_line_ColorDoor[0]->SetPos1(m_x + ground3->GetScroll(), m_y);
	m_hit_line_ColorDoor[0]->SetPos2(m_x + ground3->GetScroll(), m_y + 140);
	m_hit_line_ColorDoor[1]->SetPos1(m_x + ground3->GetScroll(), m_y);
	m_hit_line_ColorDoor[1]->SetPos2(m_x + ground3->GetScroll() + 26, m_y);
	m_hit_line_ColorDoor[2]->SetPos1(m_x + ground3->GetScroll() + 26, m_y);
	m_hit_line_ColorDoor[2]->SetPos2(m_x + ground3->GetScroll() + 26, m_y + 140);
	m_hit_line_ColorDoor[3]->SetPos1(m_x + ground3->GetScroll(), m_y + 140);
	m_hit_line_ColorDoor[3]->SetPos2(m_x + ground3->GetScroll() + 26, m_y + 140);
}

//�h���[
void ObjColorDoor::Draw()
{
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	//�Ԃ̔��\��
	Draw::Draw2D(76, m_gx + ground3->GetScroll(), m_gy);

	//Draw::Draw2D(58, m_gx+ground3->GetScroll()+30, m_gy);
}