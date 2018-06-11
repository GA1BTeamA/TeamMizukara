//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Tank3.h"
#include "ObjGround.h"
#include "ObjGround3.h"
#include "BucketMeter.h"
#include "Hero.h"
#include "Sprinkler3.h"
extern int g_SceneNumber;
extern bool g_key_flag;

CTank3::CTank3()
	:m_x(40), m_y(250), m_wave_x(11), m_wave_y(250)
	, im_x(33), im_y(130), m_ani_time1(10.0f), m_ani_time2(0.0f)
	, m_water_x(11), m_water_y(384)
	, m_water_remaining2(50)
{
	m_name = TANK3;

	//auto* ground = g;


	//�q�b�g���C���̍쐬
	m_p_hit_line_tank = Collision::HitLineInsert(this);
	m_p_hit_line_tank->SetPos1(m_x + 110, m_y);
	m_p_hit_line_tank->SetPos2(m_x + 110, m_y + 150);
	m_p_hit_line_tank->SetElement(3);		//������3�ɂ���
	m_p_hit_line_tank->SetInvisible(false);	//���G���[�h����
}

CTank3::~CTank3()
{

}

void CTank3::Action()
{
	m_water_remaining2;

	CHero* hero = (CHero*)TaskSystem::GetObj(PLAYER);
	//CSPRI* spri = (CSPRI*)TaskSystem::GetObj(SPRI);

	//�^���N���琅�����ށ��߂�
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_tank->GetHitData()[i] != nullptr)
		{
			//�����̓����蔻��̒��Ɏ�l���̓����蔻�肪��������
			if (m_p_hit_line_tank->GetHitData()[i]->GetElement() == 0)
			{
				//�^���N���琅������
				if (Input::KeyPush('X'))
				{
					//�o�P�c���[�^�[�I�u�W�F�N�g�擾
					CBucketMeter* bm = (CBucketMeter*)TaskSystem::GetObj(BUCKETMETER);
					//�o�P�c�����^������Ȃ�������
					if (bm->GetWaterRem() < 3.0f) {
						//��l���̌��������̂Ƃ��������߂�
						if (hero->GetDirec() == LEFT)
						{

							if (bm != nullptr) {
								//�o�P�c���[�^�[�ɃZ�b�g
								bm->PushX();
							}

							//�i�o�P�c���^��/75�t���[���j
							m_water_remaining2 -= 0.02666;
						}
						bm->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
					}
				}
				//�����^���N�ɖ߂�
				if (Input::KeyPush('C'))
				{
					//�o�P�c���[�^�[�I�u�W�F�N�g�擾
					CBucketMeter* bm = (CBucketMeter*)TaskSystem::GetObj(BUCKETMETER);
					//�o�P�c���󂶂�Ȃ�������
					if (bm->GetWaterRem() > 0.0f) {
						//��l���̌��������̂Ƃ��������߂�
						if (hero->GetDirec() == LEFT)
						{
							//		m_water_remaining += m_water_amount;
							//		m_wave_y -= m_wave_amount;

							if (bm != nullptr) {
								//�o�P�c���[�^�[�ɃZ�b�g
								bm->PushC();
							}

							//�@�i�o�P�c���^��/75�t���[���j
							m_water_remaining2 += 0.02666;
						}
					}
				}
				break;
			}
		}
	}
	//�g�̈ʒu�ݒ�
	//���^���ʒu+�^���N�̍���*�i���^��-�c�ʁj/100
	m_wave_y = 250 + 110 * (100 - m_water_remaining2*2)*0.01;

}

void CTank3::Draw()
{
	CHero* hero = (CHero*)TaskSystem::GetObj(PLAYER);

	//�^���N�ɋ߂Â�����A�C�R�����o��
	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_tank->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_tank->GetHitData()[i]->GetElement() == 0)
			{
				if (hero->GetDirec() == LEFT)
				{
					Draw::Draw2D(47, im_x, im_y);
				}
			}
		}
	}

	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	//���\��
	Draw::Draw2D(48, m_water_x + ground3->GetScroll(), m_water_y, 2.95, -(3.65*m_water_remaining2 *0.02));

	//int g = 36;

	//for (int i = 0; i < m_ani_time1; i++)
	//{
	//	if (i < m_ani_time1)
	//	{
	//		Draw::Draw2D(g, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	//	}
	//}

	//if (g <= 46)
	//{
	//	g = 36;
	//}
	//m_ani_time1 += 10;
	//g++;

	//�g�A�j���[�V����(���)
	if (m_ani_time1 >= 109)
	{
		m_ani_time1 = 0;
	}
	else
	{
		m_ani_time1++;
	}

	//�g�A�j���[�V����
	if (m_ani_time1 < 10)
	{
		Draw::Draw2D(36, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 20)
	{
		Draw::Draw2D(37, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 30)
	{
		Draw::Draw2D(38, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 40)
	{
		Draw::Draw2D(39, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 50)
	{
		Draw::Draw2D(40, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 60)
	{
		Draw::Draw2D(41, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 70)
	{
		Draw::Draw2D(42, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 80)
	{
		Draw::Draw2D(43, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 90)
	{
		Draw::Draw2D(44, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 100)
	{
		Draw::Draw2D(45, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time1 < 110)
	{
		Draw::Draw2D(46, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
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
		Draw::Draw2D(25, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 10)
	{
		Draw::Draw2D(26, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 15)
	{
		Draw::Draw2D(27, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 20)
	{
		Draw::Draw2D(28, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 25)
	{
		Draw::Draw2D(29, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 30)
	{
		Draw::Draw2D(30, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 35)
	{
		Draw::Draw2D(31, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 40)
	{
		Draw::Draw2D(32, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 45)
	{
		Draw::Draw2D(33, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 50)
	{
		Draw::Draw2D(34, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	else if (m_ani_time2 < 55)
	{
		Draw::Draw2D(35, m_wave_x + ground3->GetScroll(), m_wave_y, 1, 1);
	}
	/*else if (m_ani_time > 16)
	{
	Draw::Draw2D(32, m_x8, m_y8);
	}*/
}

//�g�̑���
void CTank3::SetWaveY(float* wave_y, float wave_amount)
{
	if (Input::KeyPush('X'))
	{
		*wave_y += wave_amount;
	}
	else if (Input::KeyPush('C'))
	{
		*wave_y -= wave_amount;
	}
}