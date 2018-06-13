//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "WTM2.h"
#include "ObjGround2.h"
#include "Hero.h"
#include "Tank2.h"
#include "BucketMeter.h"
extern int g_SceneNumber;
extern bool g_key_flag;

const float CWTM2::m_WaveSize_x = 0.5f;
const float CWTM2::m_WaveSize_y = 0.6f;

const float CWTM2::m_water_amount = 0.01f*0.04f;
const float CWTM2::m_wave_amount = 0.3f*0.04f;

//const float CWTM::m_water_amount = 0.026f;
//const float CWTM::m_wave_amount = 0.3f;

CWTM2::CWTM2(float x,float y)
	:m_x(x), m_y(y), m_wave_x(x+4), m_wave_y(y-84), m_ani_time1(0.0f), m_ani_time2(0.0f)
	, im_x(x-20), im_y(y-204), m_water_x(x), m_water_y(y-30), m_water_remaining(1.4)
{
	//�q�b�g���C���̍쐬(��)
	m_p_hit_line_wtm = Collision::HitLineInsert(this);
	m_p_hit_line_wtm->SetPos1(m_x, m_y);
	m_p_hit_line_wtm->SetPos2(m_x, m_y + 100);
	m_p_hit_line_wtm->SetElement(2);		//������2�ɂ���
	m_p_hit_line_wtm->SetInvisible(false);	//���G���[�h����
}

CWTM2::~CWTM2()
{

}

void CWTM2::Action()
{
	CHero* hero = (CHero*)TaskSystem::GetObj(PLAYER);
	CTank2* tank2 = (CTank2*)TaskSystem::GetObj(TANK2);

	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_wtm->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_wtm->GetHitData()[i]->GetElement() == 0)
			{
				//�^���N���琅������
				if (Input::KeyPush('X'))
				{
					CBucketMeter* bm = (CBucketMeter*)TaskSystem::GetObj(BUCKETMETER);
					if (bm != nullptr) {
						if (bm->GetWaterRem() < 3.0f) {
							bm->PushX();
							tank2->SetWater_Remaining(-0.02666);
						}
					}
				}

				//�����^���N�ɖ߂�
				if (Input::KeyPush('C'))
				{
					CBucketMeter* bm = (CBucketMeter*)TaskSystem::GetObj(BUCKETMETER);
					if (bm != nullptr) {
						if (bm->GetWaterRem() > 0.0f) {
							bm->PushC();
							tank2->SetWater_Remaining(0.02666);
						}
					}
				}
				break;
			}
		}
	}

	m_wave_y = m_y - 84 + 42 * (100 - tank2->GetWater_Remaining()*2)*0.01;

	ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);

	//�����蔻��ʒu�̍X�V
	m_p_hit_line_wtm->SetPos1(m_x + ground2->GetScroll(), m_y);
	m_p_hit_line_wtm->SetPos2(m_x + ground2->GetScroll(), m_y + 100);
}

void CWTM2::Draw()
{
	ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);
	CTank2* tank2 = (CTank2*)TaskSystem::GetObj(TANK2);

	//WTM�ɋ߂Â�����A�C�R�����o��
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_wtm->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_wtm->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(21, im_x + ground2->GetScroll(), im_y);
			}
		}
	}

	//���\��
	Draw::Draw2D(48, m_water_x + ground2->GetScroll(), m_water_y, 1.7, -(2.7*tank2->GetWater_Remaining()*0.01));

	//�g�A�j���[�V����(���)
	if (m_ani_time1 >= 109)
	{
		m_ani_time1 = 0;
	}
	else
	{
		m_ani_time1++;
	}

	float a = 103.65;
	//float b = *tank->GetWaveY() - a + tank->GetWater_Remaining();

	//�g�A�j���[�V����
	if (m_ani_time1 < 10)
	{
		Draw::Draw2D(36, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 20)
	{
		Draw::Draw2D(37, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 30)
	{
		Draw::Draw2D(38, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 40)
	{
		Draw::Draw2D(39, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 50)
	{
		Draw::Draw2D(40, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 60)
	{
		Draw::Draw2D(41, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 70)
	{
		Draw::Draw2D(42, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 80)
	{
		Draw::Draw2D(43, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 90)
	{
		Draw::Draw2D(44, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 100)
	{
		Draw::Draw2D(45, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 110)
	{
		Draw::Draw2D(46, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}

	//�g�A�j���[�V����(�O)
	if (m_ani_time2 >= 54)
	{
		m_ani_time2 = 0;
	}
	else
	{
		m_ani_time2++;
	}

	//�g�A�j���[�V����
	if (m_ani_time2 < 5)
	{
		Draw::Draw2D(25, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 10)
	{
		Draw::Draw2D(26, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 15)
	{
		Draw::Draw2D(27, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 20)
	{
		Draw::Draw2D(28, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 25)
	{
		Draw::Draw2D(29, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 30)
	{
		Draw::Draw2D(30, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 35)
	{
		Draw::Draw2D(31, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 40)
	{
		Draw::Draw2D(32, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 45)
	{
		Draw::Draw2D(33, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 50)
	{
		Draw::Draw2D(34, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 55)
	{
		Draw::Draw2D(35, m_wave_x + ground2->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}

	//Draw::Draw2D(21, a, m_y);
}