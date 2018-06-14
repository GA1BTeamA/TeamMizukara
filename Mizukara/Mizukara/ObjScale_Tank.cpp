//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjScale_Tank.h"
#include "ObjScale.h"
#include "ObjGround2.h"
#include "ObjGround3.h"
#include "BucketMeter.h"
extern int g_SceneNumber;

const float ObjScale_Tank::m_WaveSize_x = 0.25f;
const float ObjScale_Tank::m_WaveSize_y = 0.4f;

//�R���X�g���N�^
ObjScale_Tank::ObjScale_Tank(float x,float y, float r1, float r2, unsigned int n)
	:m_ScaleNo(n),m_x(x+72.5), m_y(y), m_x2(x +47.5), m_y2(y), m_wave_x(x+72.5), m_wave_y(y+28), m_water_x(x+72.5), m_water_y(y+36),
	m_wave_x2(x + 47.5), m_wave_y2(y + 28), m_water_x2(x + 47.5), m_water_y2(y + 36),
	m_angle_x(0.0f), m_angle_y(0.0f), m_angle_x2(0.0f), m_angle_y2(0.0f),
	m_ani_time1(0.0f), m_ani_time2(0.0f), m_water_remaining(r1), m_water_remaining2(r2)
{
	m_angle = 0.1f * (m_water_remaining2 - m_water_remaining) / 0.02666f;

	//�q�b�g���C���̍쐬(��)
	m_hit_line_ScaleTank[0] = Collision::HitLineInsert(this);
	m_hit_line_ScaleTank[0]->SetPos1(m_x, m_y - 50);
	m_hit_line_ScaleTank[0]->SetPos2(m_x, m_y);
	m_hit_line_ScaleTank[0]->SetElement(5);		//������5�ɂ���
	m_hit_line_ScaleTank[0]->SetInvisible(false);	//���G���[�h����

	m_hit_line_ScaleTank[1] = Collision::HitLineInsert(this);
	m_hit_line_ScaleTank[1]->SetPos1(m_x-40, m_y + 30);
	m_hit_line_ScaleTank[1]->SetPos2(m_x, m_y+30);
	m_hit_line_ScaleTank[1]->SetElement(5);		//������5�ɂ���
	m_hit_line_ScaleTank[1]->SetInvisible(false);	//���G���[�h����

												//�q�b�g���C���̍쐬2(��)
	m_hit_line_ScaleTank2[0] = Collision::HitLineInsert(this);
	m_hit_line_ScaleTank2[0]->SetPos1(m_x2+20, m_y2 - 50);
	m_hit_line_ScaleTank2[0]->SetPos2(m_x2+20, m_y2);
	m_hit_line_ScaleTank2[0]->SetElement(6);		//������6�ɂ���
	m_hit_line_ScaleTank2[0]->SetInvisible(false);	//���G���[�h����

	m_hit_line_ScaleTank2[1] = Collision::HitLineInsert(this);
	m_hit_line_ScaleTank2[1]->SetPos1(m_x2+20, m_y2 + 30);
	m_hit_line_ScaleTank2[1]->SetPos2(m_x2+60, m_y2+30);
	m_hit_line_ScaleTank2[1]->SetElement(6);		//������6�ɂ���
	m_hit_line_ScaleTank2[1]->SetInvisible(false);	//���G���[�h����

}

//�f�X�g���N�^
ObjScale_Tank::~ObjScale_Tank()
{

}

//�A�N�V����
void ObjScale_Tank::Action()
{
	ObjGround2* ground = (ObjGround2*)TaskSystem::GetObj(GROUND2);
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	//�^���N���琅�����ށ��߂�
	for (int i = 0; i < 20; i++)
	{
		if (m_hit_line_ScaleTank[i/10]->GetHitData()[i%10] != nullptr)
		{
			//�����̓����蔻��̒��Ɏ�l���̓����蔻�肪��������
			if (m_hit_line_ScaleTank[i / 10]->GetHitData()[i % 10]->GetElement() == 0)
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
							
							m_angle += 0.1f;

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
							//�n�ʂɓ������ĂȂ�������
				//			if (sc->GetX() <= 1972 || mb->GetY() <= 283.0f) {
							m_angle += -0.1f;

								if (bm != nullptr) {
									//�o�P�c���[�^�[�ɃZ�b�g
									bm->PushC();
								}

								//�i�o�P�c���^��/75�t���[���j
								m_water_remaining += 0.02666;
				//			}
						}
					}
				}
				break;
			}
		}
		if (m_hit_line_ScaleTank2[i / 10]->GetHitData()[i % 10] != nullptr)
		{
			//�����̓����蔻��̒��Ɏ�l���̓����蔻�肪��������
			if (m_hit_line_ScaleTank2[i / 10]->GetHitData()[i % 10]->GetElement() == 0)
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
							m_angle += -0.1f;

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
							//			if (sc->GetX() < 1972 || mb->GetY() <= 283.0f) {
				//				if (sc->GetY() < 365.0f) {

							m_angle += 0.1f;

									if (bm != nullptr) {
										//�o�P�c���[�^�[�ɃZ�b�g
										bm->PushC();
									}

									//�i�o�P�c���^��/75�t���[���j
									m_water_remaining2 += 0.02666;
				//				}
				//			}
						}
					}
				}
				break;
			}
		}

	}

	//����I�u�W�F�N�g�擾
	ObjScale* sc;
	switch (m_ScaleNo)
	{
	case 1:	sc = (ObjScale*)TaskSystem::GetObj(SCALE1);	break;
	case 2:	sc = (ObjScale*)TaskSystem::GetObj(SCALE2); break;
	case 3:	sc = (ObjScale*)TaskSystem::GetObj(SCALE3); break;
	case 4:	sc = (ObjScale*)TaskSystem::GetObj(SCALE4); break;
	case 5:	sc = (ObjScale*)TaskSystem::GetObj(SCALE5); break;
	}
	sc->SetAngle(m_angle);

	//�X���ɂ����W�ύX���v�Z
	m_angle_x = 72.5*sin(3.14 / 180 * (fmod((270.0f + 5.12316553f + m_angle), 360)));
	m_angle_y = 72.5*(-cos(3.14 / 180 * ((270.0f + 5.12316553f + m_angle))));
	m_angle_x2 = 72.5 * sin(3.14 / 180 * (fmod((90.0f - 5.12316553f + m_angle), 360)));
	m_angle_y2 = 72.5 * (-cos(3.14 / 180 * ((90.0f - 5.12316553f + m_angle))));


	switch (g_SceneNumber)
	{
	case GAME_MAIN2:
		//�����蔻��ʒu�̍X�V
		m_hit_line_ScaleTank[0]->SetPos1(m_x + ground->GetScroll() + m_angle_x, m_y - 50 + m_angle_y);
		m_hit_line_ScaleTank[0]->SetPos2(m_x + ground->GetScroll() + m_angle_x, m_y + m_angle_y);
		m_hit_line_ScaleTank[1]->SetPos1(m_x-40 + ground->GetScroll() + m_angle_x, m_y + 30 + m_angle_y);
		m_hit_line_ScaleTank[1]->SetPos2(m_x + ground->GetScroll() + m_angle_x, m_y+30 + m_angle_y);

		m_hit_line_ScaleTank2[0]->SetPos1(m_x2 + ground->GetScroll() + m_angle_x2, m_y2 - 50 + m_angle_y2);
		m_hit_line_ScaleTank2[0]->SetPos2(m_x2 + ground->GetScroll() + m_angle_x2, m_y2 + m_angle_y2);
		m_hit_line_ScaleTank2[1]->SetPos1(m_x2 + 20 + ground->GetScroll() + m_angle_x2, m_y2 + 30 + m_angle_y2);
		m_hit_line_ScaleTank2[1]->SetPos2(m_x2 + 60 + ground->GetScroll() + m_angle_x2, m_y2+30 + m_angle_y2);
		break;

	case GAME_MAIN3:
		//�����蔻��ʒu�̍X�V
		m_hit_line_ScaleTank[0]->SetPos1(m_x + ground3->GetScroll() + m_angle_x, m_y - 50 + m_angle_y);
		m_hit_line_ScaleTank[0]->SetPos2(m_x + ground3->GetScroll() + m_angle_x, m_y + m_angle_y);
		m_hit_line_ScaleTank[1]->SetPos1(m_x - 40 + ground3->GetScroll() + m_angle_x, m_y + 30 + m_angle_y);
		m_hit_line_ScaleTank[1]->SetPos2(m_x + ground3->GetScroll() + m_angle_x, m_y + 30 + m_angle_y);

		m_hit_line_ScaleTank2[0]->SetPos1(m_x2 + ground3->GetScroll() + m_angle_x2, m_y2 - 50 + m_angle_y2);
		m_hit_line_ScaleTank2[0]->SetPos2(m_x2 + ground3->GetScroll() + m_angle_x2, m_y2 + m_angle_y2);
		m_hit_line_ScaleTank2[1]->SetPos1(m_x2 + 20 + ground3->GetScroll() + m_angle_x2, m_y2 + 30 + m_angle_y2);
		m_hit_line_ScaleTank2[1]->SetPos2(m_x2 + 60 + ground3->GetScroll() + m_angle_x2, m_y2 + 30 + m_angle_y2);
		break;
	}
	////�����蔻��ʒu�̍X�V
	//m_hit_line_ScaleTank->SetPos1(m_x + ground->GetScroll()+ m_angle_x, m_y - 30 + m_angle_y);
	//m_hit_line_ScaleTank->SetPos2(m_x + ground->GetScroll()+ m_angle_x, m_y + m_angle_y);

	//m_hit_line_ScaleTank2->SetPos1(m_x2-50 + ground->GetScroll() + m_angle_x2, m_y2 - 30 + m_angle_y2);
	//m_hit_line_ScaleTank2->SetPos2(m_x2-50 + ground->GetScroll() + m_angle_x2, m_y2 + m_angle_y2);
}

//�h���[
void ObjScale_Tank::Draw()
{
	ObjGround2* ground = (ObjGround2*)TaskSystem::GetObj(GROUND2);
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	switch (g_SceneNumber)
	{
	case GAME_MAIN2:
		//WTM�ɋ߂Â�����A�C�R�����o��
		for (int i = 0; i < 20; i++)
		{
			if (m_hit_line_ScaleTank[i / 10]->GetHitData()[i % 10] != nullptr)
			{
				if (m_hit_line_ScaleTank[i / 10]->GetHitData()[i % 10]->GetElement() == 0)
				{
					Draw::Draw2D(70, m_x - 20 + ground->GetScroll() + m_angle_x, m_y - 150 + m_angle_y);
				}
			}
		}

		for (int i = 0; i < 20; i++)
		{
			if (m_hit_line_ScaleTank2[i / 10]->GetHitData()[i % 10] != nullptr)
			{
				if (m_hit_line_ScaleTank2[i / 10]->GetHitData()[i % 10]->GetElement() == 0)
				{
					Draw::Draw2D(70, m_x2 - 10 + ground->GetScroll() + m_angle_x2, m_y2 - 150 + m_angle_y2);
				}
			}
		}

		//���\��
		Draw::Draw2D(48, m_water_x + ground->GetScroll() + m_angle_x, m_water_y + m_angle_y, 0.025, -(0.019 * m_water_remaining * 1 / 6));
		Draw::Draw2D(48, m_water_x2 + ground->GetScroll() + m_angle_x2, m_water_y + m_angle_y2, 0.025, -(0.019*m_water_remaining2 * 1 / 6));

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
		Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x + ground->GetScroll() + m_angle_x, (m_wave_y - m_water_remaining * 2) + m_angle_y, m_WaveSize_x, m_WaveSize_y);

		//�g�A�j���[�V����2(���)
		Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x2 + ground->GetScroll() + m_angle_x2, (m_wave_y - m_water_remaining2 * 2) + m_angle_y2, m_WaveSize_x, m_WaveSize_y);

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
		Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x + ground->GetScroll() + m_angle_x, (m_wave_y - m_water_remaining * 2) + m_angle_y, m_WaveSize_x, m_WaveSize_y);

		//�g�A�j���[�V����2(�O)
		Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x2 + ground->GetScroll() + m_angle_x2, (m_wave_y - m_water_remaining2*2) + m_angle_y2, m_WaveSize_x, m_WaveSize_y);
	
		Draw::Draw2D(56, m_x + ground->GetScroll() + m_angle_x, m_y + m_angle_y, 1, 1);
		Draw::Draw2D(56, m_x2 + ground->GetScroll() + m_angle_x2, m_y2 + m_angle_y2, 1, 1);
		break;

	case GAME_MAIN3:
		//WTM�ɋ߂Â�����A�C�R�����o��
		for (int i = 0; i < 20; i++)
		{
			if (m_hit_line_ScaleTank[i / 10]->GetHitData()[i % 10] != nullptr)
			{
				if (m_hit_line_ScaleTank[i / 10]->GetHitData()[i % 10]->GetElement() == 0)
				{
					Draw::Draw2D(70, m_x - 20 + ground3->GetScroll() + m_angle_x, m_y - 150 + m_angle_y);
				}
			}
		}

		for (int i = 0; i < 20; i++)
		{
			if (m_hit_line_ScaleTank2[i / 10]->GetHitData()[i % 10] != nullptr)
			{
				if (m_hit_line_ScaleTank2[i / 10]->GetHitData()[i % 10]->GetElement() == 0)
				{
					Draw::Draw2D(70, m_x2 - 10 + ground3->GetScroll() + m_angle_x2, m_y2 - 150 + m_angle_y2);
				}
			}
		}

		//���\��
		Draw::Draw2D(48, m_water_x + ground3->GetScroll() + m_angle_x, m_water_y + m_angle_y, 0.025, -(0.019 * m_water_remaining * 1 / 6));
		Draw::Draw2D(48, m_water_x2 + ground3->GetScroll() + m_angle_x2, m_water_y + m_angle_y2, 0.025, -(0.019*m_water_remaining2 * 1 / 6));

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
		Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x + ground3->GetScroll() + m_angle_x, (m_wave_y - m_water_remaining * 2) + m_angle_y, m_WaveSize_x, m_WaveSize_y);

		//�g�A�j���[�V����2(���)
		Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x2 + ground3->GetScroll() + m_angle_x2, (m_wave_y - m_water_remaining2 * 2) + m_angle_y2, m_WaveSize_x, m_WaveSize_y);

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
		Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x + ground3->GetScroll() + m_angle_x, (m_wave_y - m_water_remaining * 2) + m_angle_y, m_WaveSize_x, m_WaveSize_y);

		//�g�A�j���[�V����2(�O)
		Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x2 + ground3->GetScroll() + m_angle_x2, (m_wave_y - m_water_remaining2) + m_angle_y2, m_WaveSize_x, m_WaveSize_y);

		Draw::Draw2D(56, m_x + ground3->GetScroll() + m_angle_x, m_y + m_angle_y, 1, 1);
		Draw::Draw2D(56, m_x2 + ground3->GetScroll() + m_angle_x2, m_y2 + m_angle_y2, 1, 1);
		break;
	}
}
