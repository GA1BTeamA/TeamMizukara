//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjColorDoor_Tank.h"
#include "ObjGround3.h"


//�R���X�g���N�^
ObjColorDoor_Tank::ObjColorDoor_Tank()
	:m_x(230), m_y(299), m_gx(230), m_gy(299)
{
	//�q�b�g���C���̍쐬
	m_hit_line_ColorDoorTank[0] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoorTank[0]->SetPos1(m_x + 115, m_y);
	m_hit_line_ColorDoorTank[0]->SetPos2(m_x + 115, m_y + 36);
	m_hit_line_ColorDoorTank[0]->SetElement(2);		//������2�ɂ���
	m_hit_line_ColorDoorTank[0]->SetInvisible(false);	//���G���[�h����

	//�q�b�g���C���̍쐬
	m_hit_line_ColorDoorTank[1] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoorTank[1]->SetPos1(m_x, m_y);
	m_hit_line_ColorDoorTank[1]->SetPos2(m_x, m_y+110);
	m_hit_line_ColorDoorTank[1]->SetElement(3);		//������2�ɂ���
	m_hit_line_ColorDoorTank[1]->SetInvisible(false);	//���G���[�h����
}

//�f�X�g���N�^
ObjColorDoor_Tank::~ObjColorDoor_Tank()
{

}

//�A�N�V����
void ObjColorDoor_Tank::Action()
{

}

//�h���[
void ObjColorDoor_Tank::Draw()
{
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	for (int i = 0; i < 10; i++)
	{
		//�M�~�b�N�ɋ߂Â�����A�C�R�����o��
		if (m_hit_line_ColorDoorTank[0]->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_ColorDoorTank[0]->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(70, m_gx + 92 + ground3->GetScroll(), m_gy - 110);
			}
		}

		//�M�~�b�N�^���N�ɋ߂Â�����A�C�R�����o��
		if (m_hit_line_ColorDoorTank[1]->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_ColorDoorTank[1]->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(21, m_gx + ground3->GetScroll()-10, m_gy - 130);
			}
		}
	}

	//�Ԃ�WTM�\��
	Draw::Draw2D(74, m_gx + ground3->GetScroll(), m_gy);

	//�Ԃ̃M�~�b�N�^���N�\��
	Draw::Draw2D(75, m_gx+115 + ground3->GetScroll(), m_gy+36);

	//Draw::Draw2D(58, m_gx + ground3->GetScroll(), m_gy+100);
}