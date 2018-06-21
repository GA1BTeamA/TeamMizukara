//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjColorDoor.h"
#include "ObjGround3.h"


//�R���X�g���N�^
ObjColorDoor::ObjColorDoor(float x, float y,int color_number,bool ud, unsigned int n)
	:m_x(x), m_y(y),m_Up_or_Down(ud), m_color_number(color_number)
{
	m_name = COLORDOOR;

	switch (n)
	{
	case 1:	m_name = COLORDOOR; break;
	case 2:	m_name = COLORDOOR2; break;
	case 3:	m_name = COLORDOOR3; break;
	case 4:	m_name = COLORDOOR4; break;
	case 5:	m_name = COLORDOOR5; break;
	}

	//�q�b�g���C���쐬���A�l��ݒ�(��)
	m_hit_line_ColorDoor[0] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoor[0]->SetPos1(m_x+2, m_y);
	m_hit_line_ColorDoor[0]->SetPos2(m_x+2, m_y + 140);
	m_hit_line_ColorDoor[0]->Set4direc(HIT_LEFT);

	//�q�b�g���C���쐬���A�l��ݒ�(��)
	m_hit_line_ColorDoor[1] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoor[1]->SetPos1(m_x+2, m_y);
	m_hit_line_ColorDoor[1]->SetPos2(m_x+2 + 26, m_y);
	m_hit_line_ColorDoor[1]->Set4direc(HIT_TOP);

	//�q�b�g���C���쐬���A�l��ݒ�(�E)
	m_hit_line_ColorDoor[2] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoor[2]->SetPos1(m_x + 28, m_y);
	m_hit_line_ColorDoor[2]->SetPos2(m_x + 28, m_y + 140);
	m_hit_line_ColorDoor[2]->Set4direc(HIT_RIGHT);

	//�q�b�g���C���쐬���A�l��ݒ�(��)
	m_hit_line_ColorDoor[3] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoor[3]->SetPos1(m_x+2, m_y + 140);
	m_hit_line_ColorDoor[3]->SetPos2(m_x + 28, m_y + 140);
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

	//���\��
	Draw::Draw2D(m_color_number, m_x + ground3->GetScroll(), m_y);

}

void ObjColorDoor::AddY(float y)
{
	if(m_Up_or_Down)m_y += y;
	else m_y -= y;
}