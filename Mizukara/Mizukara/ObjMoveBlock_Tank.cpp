//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjMoveBlock_Tank.h"
#include "ObjMoveBlock.h"
#include "ObjGround.h"
#include "BucketMeter.h"
extern int g_SceneNumber;

const float ObjMoveBlock_Tank::m_WaveSize_x = 0.25f;
const float ObjMoveBlock_Tank::m_WaveSize_y = 0.4f;

//�R���X�g���N�^
ObjMoveBlock_Tank::ObjMoveBlock_Tank()
	:m_x(1600), m_y(250),m_x2(1690),m_y2(250),m_gx(1620),m_gy(330),m_wave_x(1620),m_wave_y(364),m_water_x(1620),m_water_y(372),
	 m_ani_time1(0.0f),m_ani_time2(0.0f) ,m_water_remaining(0.0f), m_moveY(350),
	 m_RopeSizeScaffold(0.27)
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
							ObjMoveBlock* us = (ObjMoveBlock*)TaskSystem::GetObj(MOVEBLOCK);
							m_moveX -= 0.2f;
							us->MddY(0.2f);

							//m_RopeSizeBoard -= 0.0006f;
							m_RopeSizeScaffold += 0.0006f;

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
							ObjMoveBlock* us = (ObjMoveBlock*)TaskSystem::GetObj(UPSCAFFOLD);
							m_moveY += 0.2f;
							us->MddY(-0.2f);

							//m_RopeSizeBoard += 0.0006f;
							m_RopeSizeScaffold -= 0.0006f;

							if (bm != nullptr) {
								//�o�P�c���[�^�[�ɃZ�b�g
								bm->PushC();
							}

						    //�i�o�P�c���^��/75�t���[���j
							m_water_remaining += 0.02666;
						}
					}
				}
				break;
			}
		}
	}

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
				Draw::Draw2D(21, m_x + ground->GetScroll(), m_y - 20);
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_MoBlTank2->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_MoBlTank2->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(21, m_x + 50 + ground->GetScroll(), m_y - 20);
			}
		}
	}

	//���\��
	Draw::Draw2D(48, m_water_x + ground->GetScroll(), m_water_y, 0.74, 0.64);
	Draw::Draw2D(48, m_water_x + 48 + ground->GetScroll(), m_water_y, 0.74, 0.64);

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
		Draw::Draw2D(36, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 20)
	{
		Draw::Draw2D(37, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 30)
	{
		Draw::Draw2D(38, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 40)
	{
		Draw::Draw2D(39, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 50)
	{
		Draw::Draw2D(40, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 60)
	{
		Draw::Draw2D(41, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 70)
	{
		Draw::Draw2D(42, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 80)
	{
		Draw::Draw2D(43, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 90)
	{
		Draw::Draw2D(44, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 100)
	{
		Draw::Draw2D(45, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 110)
	{
		Draw::Draw2D(46, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}

	//�g�A�j���[�V����2
	if (m_ani_time1 < 10)
	{
		Draw::Draw2D(36, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 20)
	{
		Draw::Draw2D(37, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 30)
	{
		Draw::Draw2D(38, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 40)
	{
		Draw::Draw2D(39, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 50)
	{
		Draw::Draw2D(40, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 60)
	{
		Draw::Draw2D(41, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 70)
	{
		Draw::Draw2D(42, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 80)
	{
		Draw::Draw2D(43, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 90)
	{
		Draw::Draw2D(44, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 100)
	{
		Draw::Draw2D(45, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time1 < 110)
	{
		Draw::Draw2D(46, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
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
		Draw::Draw2D(25, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 10)
	{
		Draw::Draw2D(26, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 15)
	{
		Draw::Draw2D(27, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 20)
	{
		Draw::Draw2D(28, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 25)
	{
		Draw::Draw2D(29, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 30)
	{
		Draw::Draw2D(30, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 35)
	{
		Draw::Draw2D(31, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 40)
	{
		Draw::Draw2D(32, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 45)
	{
		Draw::Draw2D(33, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 50)
	{
		Draw::Draw2D(34, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 55)
	{
		Draw::Draw2D(35, m_wave_x + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}

	//�g�A�j���[�V����2
	if (m_ani_time2 < 5)
	{
		Draw::Draw2D(25, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 10)
	{
		Draw::Draw2D(26, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 15)
	{
		Draw::Draw2D(27, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 20)
	{
		Draw::Draw2D(28, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 25)
	{
		Draw::Draw2D(29, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 30)
	{
		Draw::Draw2D(30, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 35)
	{
		Draw::Draw2D(31, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 40)
	{
		Draw::Draw2D(32, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 45)
	{
		Draw::Draw2D(33, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 50)
	{
		Draw::Draw2D(34, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}
	else if (m_ani_time2 < 55)
	{
		Draw::Draw2D(35, m_wave_x + 48 + ground->GetScroll(), m_wave_y, m_WaveSize_x, m_WaveSize_y);
	}

	Draw::Draw2D(60, m_gx + ground->GetScroll(), m_gy, 1, 1);
}
