//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjMoveBlock_Tank.h"
#include "ObjMoveBlock.h"
#include "ObjGround.h"
#include "BucketMeter.h"
extern int g_SceneNumber;

const float ObjMoveBlock_Tank::m_WaveSize_x = 0.25f*0.2;

//�R���X�g���N�^
ObjMoveBlock_Tank::ObjMoveBlock_Tank()
	:m_x(1600), m_y(250),m_x2(1690),m_y2(250),m_wave_x(1620),m_wave_y(384),m_water_x(1620),m_water_y(394),
	 m_ani_time1(0.0f),m_ani_time2(0.0f) ,m_water_remaining(0.0f), m_water_remaining2(0.0f)
{
	//�q�b�g���C���̍쐬(��)
	m_hit_line_MoBlTank = Collision::HitLineInsert(this);
	m_hit_line_MoBlTank->SetPos1(m_x, m_y);
	m_hit_line_MoBlTank->SetPos2(m_x, m_y + 100);
	m_hit_line_MoBlTank->SetElement(5);		//������5�ɂ���
	m_hit_line_MoBlTank->SetInvisible(false);	//���G���[�h����
	//�q�b�g���C���̍쐬2(��)
	m_hit_line_MoBlTank2 = Collision::HitLineInsert(this);
	m_hit_line_MoBlTank2->SetPos1(m_x2, m_y2);
	m_hit_line_MoBlTank2->SetPos2(m_x2, m_y2 + 100);
	m_hit_line_MoBlTank2->SetElement(6);		//������6�ɂ���
	m_hit_line_MoBlTank2->SetInvisible(false);	//���G���[�h����
}

//�f�X�g���N�^
ObjMoveBlock_Tank::~ObjMoveBlock_Tank()
{

}

//�A�N�V����
void ObjMoveBlock_Tank::Action()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	//�^���N���琅�����ށ��߂�
	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_MoBlTank->GetHitData()[i] != nullptr)
		{
			//�����̓����蔻��̒��Ɏ�l���̓����蔻�肪��������
			if (m_hit_line_MoBlTank->GetHitData()[i]->GetElement() == 0)
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
							ObjMoveBlock* mb = (ObjMoveBlock*)TaskSystem::GetObj(MOVEBLOCK);
						//	m_moveX -= 0.2f;
							mb->AddX(-1.0f);

							if (bm != nullptr) {
								//�o�P�c���[�^�[�ɃZ�b�g
								bm->PushX();
							}

							//�@�@�@�@�@�@�@�@�@�i�o�P�c���^��/75�t���[���j
							m_water_remaining -= 0.02666;
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
						if (m_water_remaining < 6.0f) {
							//����I�u�W�F�N�g�擾
							ObjMoveBlock* mb = (ObjMoveBlock*)TaskSystem::GetObj(MOVEBLOCK);
							//�n�ʂɓ������ĂȂ�������
							if (mb->GetX() <= 1972 || mb->GetY() <= 283.0f ) {
								//		m_moveY += 0.2f;
								mb->AddX(1.0f);

								if (bm != nullptr) {
									//�o�P�c���[�^�[�ɃZ�b�g
									bm->PushC();
								}

								//�i�o�P�c���^��/75�t���[���j
								m_water_remaining += 0.02666;
							}
						}
					}
				}
				break;
			}
		}
		if (m_hit_line_MoBlTank2->GetHitData()[i] != nullptr)
		{
			//�����̓����蔻��̒��Ɏ�l���̓����蔻�肪��������
			if (m_hit_line_MoBlTank2->GetHitData()[i]->GetElement() == 0)
			{
				//�^���N���琅������
				if (Input::KeyPush('X'))
				{

					//�o�P�c���[�^�[�I�u�W�F�N�g�擾
					CBucketMeter* bm = (CBucketMeter*)TaskSystem::GetObj(BUCKETMETER);
					//�o�P�c�����^������Ȃ�������
					if (bm->GetWaterRem() < 3.0f) {
						//�c�ʂ��Ȃ������狂�߂Ȃ�
						if (m_water_remaining2 > 0.0f) {
							//����I�u�W�F�N�g�擾
							ObjMoveBlock* mb = (ObjMoveBlock*)TaskSystem::GetObj(MOVEBLOCK);
							//m_moveX -= 0.2f;
							mb->AddY(-1.0f);

							if (bm != nullptr) {
								//�o�P�c���[�^�[�ɃZ�b�g
								bm->PushX();
							}

							//�@�@�@�@�@�@�@�@�@�i�o�P�c���^��/75�t���[���j
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
						//���^��������������Ȃ�
						if (m_water_remaining2 < 6.0f) {
							//����I�u�W�F�N�g�擾
							ObjMoveBlock* mb = (ObjMoveBlock*)TaskSystem::GetObj(MOVEBLOCK);
							if (mb->GetX() < 1972 || mb->GetY() <= 283.0f) {
								if (mb->GetY() < 365.0f) {

									//	m_moveY += 0.2f;
									mb->AddY(1.0f);

									if (bm != nullptr) {
										//�o�P�c���[�^�[�ɃZ�b�g
										bm->PushC();
									}

									//�i�o�P�c���^��/75�t���[���j
									m_water_remaining2 += 0.02666;
								}
							}
						}
					}
				}
				break;
			}
		}

	}

	m_WaveSize_y = m_water_remaining *0.04f;
	if (m_WaveSize_y > 0.08f)m_WaveSize_y = 0.08f;
	m_WaveSize_y2 = m_water_remaining2 *0.04f;
	if (m_WaveSize_y2 > 0.08f)m_WaveSize_y2 = 0.08f;

	//�����蔻��ʒu�̍X�V
	m_hit_line_MoBlTank->SetPos1(m_x + ground->GetScroll(), m_y);
	m_hit_line_MoBlTank->SetPos2(m_x + ground->GetScroll(), m_y + 100);

	m_hit_line_MoBlTank2->SetPos1(m_x2 + ground->GetScroll(), m_y2);
	m_hit_line_MoBlTank2->SetPos2(m_x2 + ground->GetScroll(), m_y2 + 100);
}

//�h���[
void ObjMoveBlock_Tank::Draw()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	//WTM�ɋ߂Â�����A�C�R�����o��
	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_MoBlTank->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_MoBlTank->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(70, m_x - 10 + ground->GetScroll(), m_y - 15);
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_MoBlTank2->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_MoBlTank2->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(70, m_x + 40 + ground->GetScroll(), m_y - 15);
			}
		}
	}

	//���\��
	Draw::Draw2D(48, m_water_x + ground->GetScroll(), m_water_y, 0.025, -(0.027 * m_water_remaining *1/6));
	Draw::Draw2D(48, m_water_x + 48 + ground->GetScroll(), m_water_y, 0.025, -(0.027*m_water_remaining2 *1/6));

	//�g�A�j���[�V����(���)
	if (m_ani_time1 >= 109)
	{
		m_ani_time1 = 0;
	}
	else
	{
		m_ani_time1++;
	}

	//�g�A�j���[�V����(���)
	Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x + ground->GetScroll(), m_wave_y- m_water_remaining * 2, m_WaveSize_x, m_WaveSize_y);

	//�g�A�j���[�V����2(���)
	Draw::Draw2D(36 + (m_ani_time2 / 10), m_wave_x + 48 + ground->GetScroll(), m_wave_y - m_water_remaining2 * 2, m_WaveSize_x, m_WaveSize_y2);

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
	Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x + ground->GetScroll(), m_wave_y - m_water_remaining * 2, m_WaveSize_x, m_WaveSize_y);

	//�g�A�j���[�V����2(�O)
	Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x + 48 + ground->GetScroll(), m_wave_y - m_water_remaining2 * 2, m_WaveSize_x, m_WaveSize_y2);


	Draw::Draw2D(60, 1620 + ground->GetScroll(), 334, 1, 1);
}
