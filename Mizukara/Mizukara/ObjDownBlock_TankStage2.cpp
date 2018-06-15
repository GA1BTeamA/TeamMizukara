//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjDownBlock_TankStage2.h"
#include "ObjDownBlockStage2.h"
#include "ObjGround2.h"
#include "BucketMeter.h"
extern int g_SceneNumber;

const float ObjDownBlock_TankStage2::m_WaveSize_x = 0.23f;

ObjDownBlock_TankStage2::ObjDownBlock_TankStage2()
	:m_x(889), m_y(210), m_gx(691), m_gy(135), m_wave_x(889), m_wave_y(210),
	m_ani_time1(0.0f), m_ani_time2(0.0f), m_WaveSize_y(0.3f)
	, m_water_x(889), m_water_y(220), m_moveY(162),
	m_RopeSizeBucket(0.3f), m_water_remaining(2.0f)
	, m_bucket_remaining(0.4f), m_PulleyAni(0)
{
	//�q�b�g���C���̍쐬(��)
	m_hit_line_DwBlS2Tank = Collision::HitLineInsert(this);
	m_hit_line_DwBlS2Tank->SetPos1(m_x, m_y);
	m_hit_line_DwBlS2Tank->SetPos2(m_x, m_y + 100);
	m_hit_line_DwBlS2Tank->SetElement(2);		//������2�ɂ���
	m_hit_line_DwBlS2Tank->SetInvisible(false);	//���G���[�h����
}

ObjDownBlock_TankStage2::~ObjDownBlock_TankStage2()
{

}

void ObjDownBlock_TankStage2::Action()
{
	ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);

	if (m_PulleyAni > 8) m_PulleyAni = 0;

	//�^���N���琅�����ށ��߂�
	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_DwBlS2Tank->GetHitData()[i] != nullptr)
		{
			//�����̓����蔻��̒��Ɏ�l���̓����蔻�肪��������
			if (m_hit_line_DwBlS2Tank->GetHitData()[i]->GetElement() == 0)
			{
				//�^���N���琅������
				if (Input::KeyPush('X'))
				{

					//�o�P�c���[�^�[�I�u�W�F�N�g�擾
					CBucketMeter* bm = (CBucketMeter*)TaskSystem::GetObj(BUCKETMETER);
					//�o�P�c�����^������Ȃ�������
					if (bm->GetWaterRem() < 3.0f) {
						//�c�ʂ��Ȃ������狂�߂Ȃ�
						if (m_water_remaining > 0.0f) {
							//����I�u�W�F�N�g�擾
							ObjDownBlockStage2* db = (ObjDownBlockStage2*)TaskSystem::GetObj(DOWNBLOCKSTAGE2);

							m_gy -= 0.5f;  //�o�P�c�ړ�
							m_RopeSizeBucket -= 0.0015f;  //�o�P�c�����[�v�����ύX

							db->AddY(0.8f);  //����u���b�N�ړ�
							db->SetRopeSizeScaffold(0.0025f);  //���ꃍ�[�v�����ύX

							db->SetY(0.8f);  //���ꓖ���蔻��ړ�

							m_bucket_remaining -= 0.006f;  //�����炷
														   //�g�̈ʒu
							if (m_wave_y < 248)m_wave_y -= 0.26f;
							else m_wave_y -= 0.3f;
							m_water_y -= 0.325f;  //���̈ʒu
												  //m_WaveSize_y -= 0.01f;
												  //m_RopeSizeBoard -= 0.0006f;
												  //m_RopeSizeBucket += 0.0006f;

							if (bm != nullptr) {
								//�o�P�c���[�^�[�ɃZ�b�g
								bm->PushX();
							}

							//�i�o�P�c���^��/75�t���[���j
							m_water_remaining -= 0.02666;

							m_PulleyAni++;

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
						//���^��������������Ȃ�
						if (m_water_remaining < 2.0f) {
							//����I�u�W�F�N�g�擾
							ObjDownBlockStage2* db = (ObjDownBlockStage2*)TaskSystem::GetObj(DOWNBLOCKSTAGE2);
							//m_moveY += 0.2f;
							//db->AddY(-0.2f);
							m_gy += 0.5f;  //�o�P�c�ړ�
							m_RopeSizeBucket += 0.0015f;  //�o�P�c�����[�v�����ύX

							db->AddY(-0.8f);  //����u���b�N�ړ�
							db->SetRopeSizeScaffold(-0.0025f);  //���ꃍ�[�v�����ύX

							db->SetY(-0.8f);  //���ꓖ���蔻��ړ�

							m_bucket_remaining += 0.006f;  //�����炷
														   //�g�̈ʒu
							if (m_wave_y < 248)m_wave_y += 0.26f;
							else m_wave_y += 0.3f;
							m_water_y += 0.325f;  //���̈ʒu
												  //m_WaveSize_y += 0.01f;
												  ////m_RopeSizeBoard += 0.0006f;
												  //m_RopeSizeBucket -= 0.0006f;

							if (bm != nullptr) {
								//�o�P�c���[�^�[�ɃZ�b�g
								bm->PushC();
							}

							//�i�o�P�c���^��/75�t���[���j
							m_water_remaining += 0.02666;

							m_PulleyAni++;

						}
					}
				}
				break;
			}
		}
	}

	m_WaveSize_y = m_water_remaining *0.5f;
	if (m_WaveSize_y > 0.6f)m_WaveSize_y = 0.6f;

	//�����蔻��ʒu�̍X�V
	m_hit_line_DwBlS2Tank->SetPos1(m_x + ground2->GetScroll(), m_y);
	m_hit_line_DwBlS2Tank->SetPos2(m_x + ground2->GetScroll(), m_y + 100);
}

void ObjDownBlock_TankStage2::Draw()
{
	ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);

	//���[�v�\��
	Draw::Draw2D(62, m_gx + 206 + ground2->GetScroll(), 100, 1, m_RopeSizeBucket);
	//�o�P�c�\��
	Draw::Draw2D(56, m_gx + 197 + ground2->GetScroll(), m_gy + 64, 1, 1);
	//�����[�v�\��
	Draw::Draw2D(59, m_gx + 205 + ground2->GetScroll(), 85, 0.9, 1);
	//���ԕ\��
	if (m_PulleyAni <= 4)
		Draw::Draw2D(80, m_gx + 200 + ground2->GetScroll(), 80, 1, 1);
	else
		Draw::Draw2D(80, m_gx + 350 + ground2->GetScroll(), 80, -1, 1);

	//�M�~�b�N�ɋ߂Â�����A�C�R�����o��
	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_DwBlS2Tank->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_DwBlS2Tank->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(70, m_x-20 + ground2->GetScroll(), m_y-195);
			}
		}
	}

	//���\��
	Draw::Draw2D(48, m_water_x + ground2->GetScroll(), m_water_y, 0.025, m_bucket_remaining/18);

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