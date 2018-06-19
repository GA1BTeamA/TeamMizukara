//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ZTank.h"
#include "ObjGround2.h"
#include "BucketMeter.h"
extern int g_SceneNumber;

const float ObjElephant_Tank::m_WaveSize_x = 0.3f*0.2f;
const float ObjElephant_Tank::m_WaveSize_y = 0.4f*0.2f;

//�R���X�g���N�^
ObjElephant_Tank::ObjElephant_Tank()
	:m_x(2230), m_y(175), m_wave_x(2230), m_wave_y(200), m_water_x(2232), m_water_y(215),
	m_ani_time1(0), m_ani_time2(0), m_ani_time_Shower(0), m_water_remaining(0.0f),m_alpha(0.0f)
{
	//�q�b�g���C���̍쐬(��)
	m_hit_line_ZTank = Collision::HitLineInsert(this);
	m_hit_line_ZTank->SetPos1(m_x, m_y);
	m_hit_line_ZTank->SetPos2(m_x, m_y + 100);
	m_hit_line_ZTank->SetElement(5);		//������5�ɂ���
	m_hit_line_ZTank->SetInvisible(false);	//���G���[�h����
	m_hit_line_ZTank->SetAngle();
												//�q�b�g���C���̍쐬2(��)
	m_hit_line_ZTankWall = Collision::HitLineInsert(this);
	m_hit_line_ZTankWall->SetPos1(m_x+60, m_y+100);
	m_hit_line_ZTankWall->SetPos2(m_x+60, m_y-200);
	m_hit_line_ZTankWall->SetElement(1);		//������6�ɂ���
	m_hit_line_ZTankWall->SetInvisible(false);	//���G���[�h����
	m_hit_line_ZTankWall->SetAngle();
	m_hit_line_ZTankWall->Set4direc(HIT_LEFT);
}

//�f�X�g���N�^
ObjElephant_Tank::~ObjElephant_Tank()
{

}

//�A�N�V����
void ObjElephant_Tank::Action()
{
	ObjGround2* ground = (ObjGround2*)TaskSystem::GetObj(GROUND2);

	//0����Ȃ������玞�ԉ��Z
	if (m_ani_time_Shower != 0 && m_ani_time_Shower < 150) {
		m_water_remaining -= 0.02f;
		m_ani_time_Shower++;
	}

	//�^���N���琅�����ށ��߂�
	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_ZTank->GetHitData()[i] != nullptr)
		{
			//�����̓����蔻��̒��Ɏ�l���̓����蔻�肪��������
			if (m_hit_line_ZTank->GetHitData()[i]->GetElement() == 0)
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

							if (bm != nullptr) {
								//�o�P�c���[�^�[�ɃZ�b�g
								bm->PushC();
							}

							//�i�o�P�c���^��/75�t���[���j
							m_water_remaining += 0.02666;
						}
						else{
							//���^���ɂȂ�����V�����[�A�j���[�V�����J�n
							m_ani_time_Shower++;
							//m_hit_line_ZTankWall->SetInvisible(true);	//���G���[�h����
							//m_alpha += 0.01f;
						}
					}
				}
				break;
			}
		}

	}

	//�����蔻��ʒu�̍X�V
	m_hit_line_ZTank->SetPos1(m_x + ground->GetScroll(), m_y);
	m_hit_line_ZTank->SetPos2(m_x + ground->GetScroll(), m_y + 100);

	m_hit_line_ZTankWall->SetPos1(m_x+60 + ground->GetScroll(), m_y+100);
	m_hit_line_ZTankWall->SetPos2(m_x+60 + ground->GetScroll(), m_y-200);

	//�V�����[�A�j���[�V�������I�������ǂ������ē����o��
	if (m_ani_time_Shower == 150) {
		m_hit_line_ZTankWall->SetInvisible(true);	//���G���[�h����
		m_alpha += 0.01f;
	}

	if (m_alpha!= 0.0f && m_alpha < 1.0f)m_alpha += 0.01f;

}

//�h���[
void ObjElephant_Tank::Draw()
{
	ObjGround2* ground = (ObjGround2*)TaskSystem::GetObj(GROUND2);

	//WTM�ɋ߂Â�����A�C�R�����o��
	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_ZTank->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_ZTank->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(70, m_x - 30 + ground->GetScroll(), m_y - 50);
			}
		}
	}

	//���\��
	Draw::Draw2D(48, m_water_x + ground->GetScroll(), m_water_y, 0.03, -(0.027 * m_water_remaining * 1 / 6));

	//�g�A�j���[�V����(���)
	if (m_ani_time1 >= 109)
	{
		m_ani_time1 = 0;
	}
	else
	{
		m_ani_time1++;
	}
	//�g�A�j���[�V�����`��(���)
	Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x + ground->GetScroll(), m_wave_y - m_water_remaining * 2, m_WaveSize_x, m_WaveSize_y);

	//�g�A�j���[�V����(�O)
	if (m_ani_time2 >= 54)
	{
		m_ani_time2 = 0;
	}
	else
	{
		m_ani_time2++;
	}
	//�g�A�j���[�V�����`��(�O)
	Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x + ground->GetScroll(), m_wave_y - m_water_remaining * 2, m_WaveSize_x, m_WaveSize_y);

	//�ۃ^���N�`��
	Draw::Draw2D(88, m_x + ground->GetScroll(), m_y, 1, 1);

	float c[4] = { 1.0f,1.0f,1.0f,m_alpha };

	//���`��
	Draw::Draw2D(87, ground->GetScroll() + 2450, 202,c);

	//�V�����[�`��
	if (m_ani_time_Shower != 0 && m_ani_time_Shower != 150) {
		//10�t���[�����؂�ւ�
		if((m_ani_time_Shower/10)%2)
			Draw::Draw2D(109, ground->GetScroll() + 2400, 230);
		else
			Draw::Draw2D(109, ground->GetScroll() + 2430, 240);
	}
}
