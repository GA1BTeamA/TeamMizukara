//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjColorDoor_Tank.h"
#include "ObjGround3.h"
#include "BucketMeter.h"
#include "ObjColorDoor.h"

const float ObjColorDoor_Tank::m_WaveSize_x = 0.32f*0.2f;

//�R���X�g���N�^
ObjColorDoor_Tank::ObjColorDoor_Tank(float x, float y, int color, float waveX, float waveY,unsigned int n)
	:m_x(x), m_y(y), m_gx(x), m_gy(y)
	, m_moveY(350), m_wave_x(x+3), m_wave_y(y+45)
	, m_water_x(x+3), m_water_y(y+53), m_water_remaining(0.0f)
	, m_WaveSize_y(0.4f*0.2f), m_WaterSize_y(0.0f)
	, m_ani_time1(0.0f), m_ani_time2(0.0f), m_DoorNo(n)
{

	if (color == 75)
	{
		//���̐F�p�z�񏉊���(��)
		rgba[0] = 2.0f;
		rgba[1] = 0.5f;
		rgba[2] = 0.5f;
		rgba[3] = 1.0f;
	}
	else if(color ==82)
	{
		//���̐F�p�z�񏉊���(��)
		rgba[0] = 0.0f;
		rgba[1] = 1.0f;
		rgba[2] = 0.5f;
		rgba[3] = 1.0f;
	}

	//�q�b�g���C���̍쐬
	m_hit_line_ColorDoorTank[0] = Collision::HitLineInsert(this);
	m_hit_line_ColorDoorTank[0]->SetPos1(m_x, m_y+50);
	m_hit_line_ColorDoorTank[0]->SetPos2(m_x, m_y + 100);
	m_hit_line_ColorDoorTank[0]->SetElement(2);		//������2�ɂ���
	m_hit_line_ColorDoorTank[0]->SetInvisible(false);	//���G���[�h����

}

//�f�X�g���N�^
ObjColorDoor_Tank::~ObjColorDoor_Tank()
{

}

//�A�N�V����
void ObjColorDoor_Tank::Action()
{
	ObjColorDoor* cd;
	switch (m_DoorNo)
	{
	case 1:	cd = (ObjColorDoor*)TaskSystem::GetObj(COLORDOOR);	break;
	case 2:	cd = (ObjColorDoor*)TaskSystem::GetObj(COLORDOOR2); break;
	case 3:	cd = (ObjColorDoor*)TaskSystem::GetObj(COLORDOOR3); break;
	case 4:	cd = (ObjColorDoor*)TaskSystem::GetObj(COLORDOOR4); break;
	case 5:	cd = (ObjColorDoor*)TaskSystem::GetObj(COLORDOOR5); break;
	}

	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	//�^���N���琅�����ށ��߂�
	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_ColorDoorTank[0]->GetHitData()[i] != nullptr)
		{
			//�����̓����蔻��̒��Ɏ�l���̓����蔻�肪��������
			if (m_hit_line_ColorDoorTank[0]->GetHitData()[i]->GetElement() == 0)
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
							m_moveY -= 0.14f;
							cd->AddY(0.6f);

							if (cd)
								Audio::StartLoopMusic(12);
							Audio::LoopMusicVolume(12, 0.05f);

							if (bm != nullptr) {
								//�o�P�c���[�^�[�ɃZ�b�g
								bm->PushX();
							}

							if (rgba[0] == 2.0f)
							{
								bm->SetColor(2.0f, 0.5f, 0.5f, 1.0f);
							}
							else if (rgba[0] == 0.0f)
							{
								bm->SetColor(0.0f, 1.0f, 0.5f, 1.0f);
							}
							else
							{
								bm->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
							}

							//�i�o�P�c���^��/75�t���[���j
							m_water_remaining -= 0.02666;
						}
					}
				}
				//�����^���N�ɖ߂�
				else if (Input::KeyPush('C'))
				{
					//�o�P�c���[�^�[�I�u�W�F�N�g�擾
					CBucketMeter* bm = (CBucketMeter*)TaskSystem::GetObj(BUCKETMETER);
					//�ԃ^���N
					if (rgba[0]!=2.0f && bm->GetColorR() == 2.0f)
						continue;
					//�΃^���N
					if (rgba[0] == 2.0f && bm->GetColorR() != 2.0f)
						continue;

					//�o�P�c���󂶂�Ȃ�������
					if (bm->GetWaterRem() > 0.0f) {
						//���^��������������Ȃ�
						if (m_water_remaining < 6.0f) {
							//����I�u�W�F�N�g�擾
							m_moveY += 0.14f;
							cd->AddY(-0.6f);

							if (cd)
								Audio::StartLoopMusic(12);
							Audio::LoopMusicVolume(12, 0.05f);

							if (bm != nullptr) {
								//�o�P�c���[�^�[�ɃZ�b�g
								bm->PushC();
							}

							//�i�o�P�c���^��/75�t���[���j
							m_water_remaining += 0.02666;
						}
					}
					
				}
				//C��X�������ĂȂ������特�y���~�߂�
				if (!(Input::KeyPush('C')) && !(Input::KeyPush('X')))
					Audio::StopLoopMusic(12);

				break;
			}
		}
	}

	//����n�ߎ��̕`��̂��߂̏���
	m_WaterSize_y = m_water_remaining* -0.0082f;
	
	m_WaveSize_y = m_water_remaining*0.08f*0.5f;
	if (m_WaveSize_y > 0.08f)m_WaveSize_y = 0.08f;

	//�����蔻��̈ʒu�X�V
	m_hit_line_ColorDoorTank[0]->SetPos1(m_x + ground3->GetScroll(), m_y+50);
	m_hit_line_ColorDoorTank[0]->SetPos2(m_x + ground3->GetScroll(), m_y + 100);
}

//�h���[
void ObjColorDoor_Tank::Draw()
{
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

	for (int i = 0; i < 10; i++)
	{
		//�M�~�b�N�ɋ߂Â�����A�C�R�����o��
		if (m_hit_line_ColorDoorTank[0]->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_ColorDoorTank[0]->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(70, m_gx-22 + ground3->GetScroll(), m_gy - 110);
			}
		}
	}

	//���\��
	Draw::Draw2D(48, m_water_x + ground3->GetScroll(), m_water_y, 0.0349, m_WaterSize_y, rgba);

	//�g�A�j���[�V����(���)
	if (m_ani_time1 >= 109)
	{
		m_ani_time1 = 0;
	}
	else
	{
		m_ani_time1++;
	}
	int p_waveY = 5;

	if (m_water_remaining>2.0f) {
		//�g�A�j���[�V����(���)
		Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x + ground3->GetScroll(), (m_wave_y - m_water_remaining * p_waveY), m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else {
		Draw::Draw2D(36 + (m_ani_time1 / 10), m_wave_x + ground3->GetScroll(), (m_wave_y - m_water_remaining * p_waveY) + 9 * (2.0f - m_water_remaining)*0.5f, m_WaveSize_x, m_WaveSize_y, rgba);
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

	if (m_water_remaining>2.0f) {
		//�g�A�j���[�V����(�O)
		Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x + ground3->GetScroll(), (m_wave_y - m_water_remaining * p_waveY), m_WaveSize_x, m_WaveSize_y, rgba);
	}
	else {
		Draw::Draw2D(25 + (m_ani_time2 / 5), m_wave_x + ground3->GetScroll(), (m_wave_y - m_water_remaining * p_waveY) + 9 * (2.0f - m_water_remaining)*0.5f, m_WaveSize_x, m_WaveSize_y, rgba);
	}

	//�F���Ƃ̃M�~�b�N�^���N�`��
	if (rgba[0] == 2.0f)
	{
		//�Ԃ̃M�~�b�N�^���N�\��
		Draw::Draw2D(75, m_gx + ground3->GetScroll(), m_gy);
	}
	else
	{
		//�΂̃M�~�b�N�^���N�\��
		Draw::Draw2D(83, m_gx + ground3->GetScroll(), m_gy);
	}
}