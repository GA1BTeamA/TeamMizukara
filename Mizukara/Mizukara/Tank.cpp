//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Tank.h"
#include "ObjGround.h"
//#include "ObjGround2.h"
#include "BucketMeter.h"
#include "Hero.h"
#include "Sprinkler.h"
extern int g_SceneNumber;
extern bool g_key_flag;

const float CTank::m_WaveSize_x = 0.2f;
const float CTank::m_WaveSize_y = 0.2f;

CTank::CTank()
	:m_x(40), m_y(250), m_wave_x(11), m_wave_y(249.3)
	,im_x(33), im_y(130),m_ani_time1(0.0f),m_ani_time2(0.0f)
	, m_water_x(11), m_water_y(387)
	, m_water_remaining2(50)
{
	m_name = TANK;

	//auto* ground = g;


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

							//�@�@�@�@�@�@�@�@�@�i�o�P�c���^��/75�t���[���j
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
	m_wave_y = 249.3 + 110 * (100 - m_water_remaining2*2)*0.00981;

}

void CTank::Draw()
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

	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

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
	Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);

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
	Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);

	//���\��
	Draw::Draw2D(48, m_water_x + ground->GetScroll(), m_water_y - 8,/*2.95*/0.108, -(/*3.65*/0.18*m_water_remaining2 *0.025));
}

//�g�̑���
void CTank::SetWaveY(float* wave_y,float wave_amount)
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