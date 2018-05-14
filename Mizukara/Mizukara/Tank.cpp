//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Tank.h"
#include "ObjGround.h"
extern int g_SceneNumber;

const float CTank::m_Wave_Shrinking = 0.7f;


CTank::CTank()
	:m_x(40), m_y(250),m_x1(12),m_y1(250)
	,im_x(3), im_y(130),m_ani_time1(0.0f),m_ani_time2(0.0f)
{


	/*
	m_p_hit_line->SetPos1(m_x-11, m_y);
	m_p_hit_line->SetPos2(m_x+11, m_y+139);
	*/
	//�q�b�g���C���̍쐬
	m_p_hit_line_tank = Collision::HitLineInsert(this);
	m_p_hit_line_tank->SetPos1(m_x + 110, m_y);
	m_p_hit_line_tank->SetPos2(m_x + 110, m_y + 150);
	m_p_hit_line_tank->SetElement(3);		//������3�ɂ���
	m_p_hit_line_tank->SetInvisible(false);	//���G���[�h����
}

CTank::~CTank()
{

}

void CTank::Action()
{

}

void CTank::Draw()
{
	//�^���N�ɋ߂Â�����A�C�R�����o��
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_tank->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_tank->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(47, im_x, im_y);
			}
		}
	}

	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);


	if (m_ani_time1 >= 109)
	{
		m_ani_time1 = 0;
	}
	else
	{
		m_ani_time1++;
	}

	//�g�A�j���[�V����(���)
    if (m_ani_time1 < 10)
	{
		Draw::Draw2D(36, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	else if (m_ani_time1 < 20)
	{
		Draw::Draw2D(37, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	else if (m_ani_time1 < 30)
	{
		Draw::Draw2D(38, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	else if (m_ani_time1 < 40)
	{
		Draw::Draw2D(39, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	else if (m_ani_time1 < 50)
	{
		Draw::Draw2D(40, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	else if (m_ani_time1 < 60)
	{
		Draw::Draw2D(41, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	else if (m_ani_time1 < 70)
	{
		Draw::Draw2D(42, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	else if (m_ani_time1 < 80)
	{
		Draw::Draw2D(43, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	else if (m_ani_time1 < 90)
	{
		Draw::Draw2D(44, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	else if (m_ani_time1 < 100)
	{
		Draw::Draw2D(45, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	else if (m_ani_time1 < 110)
	{
		Draw::Draw2D(46, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}


	if (m_ani_time2 >= 54)
	{
		m_ani_time2 = 0;
	}
	else
	{
		m_ani_time2++;
	}

	//�g�A�j���[�V����(�O)
	if (m_ani_time2 < 5)
	{
		Draw::Draw2D(25, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	else if (m_ani_time2 < 10)
	{
		Draw::Draw2D(26, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	else if (m_ani_time2 < 15)
	{
		Draw::Draw2D(27, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	else if (m_ani_time2 < 20)
	{
		Draw::Draw2D(28, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	else if (m_ani_time2 < 25)
	{
		Draw::Draw2D(29, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	else if (m_ani_time2 < 30)
	{
		Draw::Draw2D(30, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	else if (m_ani_time2 < 35)
	{
		Draw::Draw2D(31, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	else if (m_ani_time2 < 40)
	{
		Draw::Draw2D(32, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	else if (m_ani_time2 < 45)
	{
		Draw::Draw2D(33, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	else if (m_ani_time2 < 50)
	{
		Draw::Draw2D(34, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	else if (m_ani_time2 < 55)
	{
		Draw::Draw2D(35, m_x1 + ground->GetScroll(), m_y1, 1, m_Wave_Shrinking);
	}
	/*else if (m_ani_time > 16)
	{
	Draw::Draw2D(32, m_x8, m_y8);
	}*/
}