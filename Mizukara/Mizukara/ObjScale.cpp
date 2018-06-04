//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjScale.h"
#include "ObjGround2.h"
#include "Sprinkler.h"
#include <math.h>
extern bool g_key_flag;

ObjScale::ObjScale()
	:m_x(795), m_y(340),m_angle(0.0f)
{
	m_name = SCALE;

	////�V���q�b�g���C���쐬���A�l��ݒ�(��)
	//m_hit_line_Scale[0] = Collision::HitLineInsert(this);
	//m_hit_line_Scale[0]->SetPos1(m_x, m_y);
	//m_hit_line_Scale[0]->SetPos2(m_x, m_y + 13);
	//m_hit_line_Scale[0]->Set4direc(HIT_LEFT);

	////�V���q�b�g���C���쐬���A�l��ݒ�(�E)
	//m_hit_line_Scale[1] = Collision::HitLineInsert(this);
	//m_hit_line_Scale[1]->SetPos1(m_x + 145, m_y);
	//m_hit_line_Scale[1]->SetPos2(m_x + 145, m_y + 13);
	//m_hit_line_Scale[1]->Set4direc(HIT_RIGHT);

	//�V���q�b�g���C���쐬���A�l��ݒ�(��)
	m_hit_line_Scale[2] = Collision::HitLineInsert(this);
	m_hit_line_Scale[2]->SetPos1(m_x, m_y);
	m_hit_line_Scale[2]->SetPos2(m_x + 145, m_y);
	m_hit_line_Scale[2]->Set4direc(HIT_TOP);

	////�V���q�b�g���C���쐬���A�l��ݒ�(��)
	//m_hit_line_Scale[3] = Collision::HitLineInsert(this);
	//m_hit_line_Scale[3]->SetPos1(m_x, m_y + 13);
	//m_hit_line_Scale[3]->SetPos2(m_x + 145, m_y + 13);
	//m_hit_line_Scale[3]->Set4direc(HIT_UNDER);

	for (int i = 0; i < 4; i++) {
		m_hit_line_Scale[2]->SetElement(1);		//������1�ɂ���
		m_hit_line_Scale[2]->SetInvisible(false);	//���G���[�h����
		m_hit_line_Scale[2]->SetAngle();
	}

}


ObjScale::~ObjScale()
{
}

void ObjScale::Action()
{
	ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);

	//CSPRI* spri = (CSPRI*)TaskSystem::GetObj(SPRI);
	////�N���A��ʂ��\�����ꂽ��
	//if (spri->GetCrearCnt() == true)
	//{
	//	//�G���^�[�L�[�������ꂽ��
	//	if (Input::KeyPush(VK_RETURN) == true)
	//	{
	//		if (g_key_flag)
	//		{
	//			//�j��
	//			is_delete = true;
	//			g_key_flag = false;
	//		}
	//	}
	//	else
	//	{
	//		g_key_flag = true;
	//	}
	//}

	//�ʒu�X�V
	//m_hit_line_Scale[0]->SetPos1(m_x + ground2->GetScroll(), m_y);
	//m_hit_line_Scale[0]->SetPos2(m_x + ground2->GetScroll(), m_y + 13);
	//m_hit_line_Scale[1]->SetPos1(m_x + ground2->GetScroll() + 145, m_y);
	//m_hit_line_Scale[1]->SetPos2(m_x + ground2->GetScroll() + 145, m_y + 13);
	m_hit_line_Scale[2]->SetPos1(m_x + 4.0f + ground2->GetScroll()+72.5*sin(3.14 / 180 * (fmod((270.0f+5.12316553f+ m_angle),360))), m_y+ 72.5*(-cos(3.14 / 180 * ((270.0f + 5.12316553f+ m_angle)))));
	m_hit_line_Scale[2]->SetPos2(m_x + 4.0f + ground2->GetScroll() + 72.5 * sin(3.14 / 180 * (fmod((90.0f - 5.12316553f+ m_angle), 360))), m_y + 72.5 * (-cos(3.14 / 180 * ((90.0f - 5.12316553f+ m_angle)))));
	//m_hit_line_Scale[3]->SetPos1(m_x + ground2->GetScroll(), m_y + 13);
	//m_hit_line_Scale[3]->SetPos2(m_x + ground2->GetScroll() + 145, m_y + 13);

	m_hit_line_Scale[2]->SetAngle();

}

void ObjScale::Draw()
{
	ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);

	//����
	Draw::Draw2D(81, m_x-70 + ground2->GetScroll(), m_y-10,m_angle);
}
