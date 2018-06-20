//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Sprinkler3.h"
#include "ObjGround3.h"
#include "Hero.h"
#include "Tank3.h"
#include "BucketMeter.h"
extern int g_SceneNumber;
extern bool g_key_flag;
extern bool g_clearlist;
extern float g_TankRemaining;

const float CSPRI3::m_WaveSize_x = 0.55f;
const float CSPRI3::m_WaveSize_y = 0.6f;

CSPRI3::CSPRI3()
	:m_x(2940), m_y(250), m_wave_x(2950), m_wave_y(230),
	m_ani_time1(0.0f), m_ani_time2(0.0f), m_ani_time3(0.0f), m_ani_time4(0.0f), m_ani_time5(-1),m_ani_time6(0.0f)
	, m_move1(0.0f), m_move2(0.0f), im_x(2150), im_y(130),
	m_water_x(2950), m_water_y(242), m_vy(0.0f), m_sy(230)
	, m_CrearCnt3(false), m_Flower(false)
	, m_fx(734), m_fy(250), m_BrackBackDraw(false), m_BrackBackDrawCnt(0)
	, m_BrackBack_sx(6.0f), m_BrackBack_sy(6.0f)
	, m_BrackBack_x(-3780), m_BrackBack_y(-1425)
{
	m_name = SPRI3;

	//�q�b�g���C���̍쐬(��)
	m_p_hit_line_spri3 = Collision::HitLineInsert(this);
	m_p_hit_line_spri3->SetPos1(m_x, m_y);
	m_p_hit_line_spri3->SetPos2(m_x, m_y + 100);
	m_p_hit_line_spri3->SetElement(4);		//������4�ɂ���
	m_p_hit_line_spri3->SetInvisible(false);	//���G���[�h����
}

CSPRI3::~CSPRI3()
{

}

void CSPRI3::Action()
{
	if (m_ani_time5 > 51)m_ani_time5 = 0;
	else if (m_ani_time5 >= 0)m_ani_time5++;

	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);
	CTank3* tank3 = (CTank3*)TaskSystem::GetObj(TANK3);

	//�����蔻��ʒu�̍X�V
	m_p_hit_line_spri3->SetPos1(m_x + ground3->GetScroll(), m_y);
	m_p_hit_line_spri3->SetPos2(m_x + ground3->GetScroll(), m_y + 100);

	//�N���A��ʂ��\�����ꂽ��
	if (m_CrearCnt3 == true)
	{
		//�G���^�[�L�[�������ꂽ��
		if (Input::KeyPush(VK_RETURN) == true)
		{
			if (g_key_flag)
			{
				//���w�i�̕\����true�ɂ���
				m_BrackBackDraw = true;
			}
		}
		else
		{
			g_key_flag = true;
		}
	}

	//�j��
	if (m_BrackBackDrawCnt == 40)
	{
		Audio::StopLoopMusic(9);
		//if (m_ani_time6 >= 1000)
		//{
		g_SceneNumber = RESULT;
		//g_clearlist = true;
		g_key_flag = false;
		//g_TankRemaining = false;
		//}
	}

	//���w�i�k���ƈړ�
	if (m_BrackBackDraw == true && m_BrackBack_sx > 1.1f)
	{
		//�k��
		m_BrackBack_sx -= 0.1f;
		m_BrackBack_sy -= 0.1f;
		//�Ԓ��S�ɂȂ�悤�Ɉړ�
		m_BrackBack_x += 75.6f;//���̈ʒu��50����1�̒l
		m_BrackBack_y += 28.5f;
	}
	else if (m_BrackBack_sx<1.1f)
	{
		//�k������������J�E���g�X�^�[�g
		m_BrackBackDrawCnt++;
	}

	//�J�E���g��40�𒴂���ƃX�g�b�v����悤�ɂ��Ă����
	if (m_BrackBackDrawCnt > 41)
	{
		m_BrackBackDrawCnt = 41;
	}

	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_spri3->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_spri3->GetHitData()[i]->GetElement() == 0)
			{
				Audio::StopLoopMusic(6);

				Audio::StartLoopMusic(9);
				Audio::LoopMusicVolume(9, 0.05f);

				//�^���N�̐����X�v�����N���[����o��
				if (m_ani_time4 >= 460 && tank3->GetWater_Remaining() > 0)
				{
					tank3->SetWater_Remaining(-0.2f);
					g_TankRemaining += 0.2f;
				}
				break;
			}
		}
	}

	//�^���N�̎c�ʂ�0�ȉ��ɂȂ�����A
	if (tank3->GetWater_Remaining() < 0)
	{
		//�����N�p�̃^���N�c�ʂ���}�C�i�X��������
		g_TankRemaining += tank3->GetWater_Remaining();
		tank3->ResetWater_Remaining(0);
	}

	//m_ani_time5++;
	if (m_ani_time5 == 50 && m_sy == 230 && g_SceneNumber != RESULT_MAIN)
	{
		m_vy = -8.0f;
		m_CrearCnt3 = true;
	}
	//else if (m_ani_time5 > 200 && m_ani_time5 <= 210 && m_sy == 230)
	//{
	//	m_vy = -8.0f;
	//}
	m_vy += 9.8 / (16.0f);


	m_sy += m_vy;
	if (m_sy > 230) { m_sy = 230; m_vy = 0.0f; }

}

void CSPRI3::Draw()
{
	ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);
	CTank3* tank3 = (CTank3*)TaskSystem::GetObj(TANK3);

	//�N���A��ʕ\��
	if (m_CrearCnt3 == true)
	{
		Draw::Draw2D(63, 300, 200);
	}

	//if (m_CrearCnt == true)
	//{
	//	//�G���^�[�L�[�������ꂽ��
	//	if (Input::KeyPush(VK_RETURN) == true)
	//	{
	//		//�j��
	//		if (g_key_flag)
	//		{
	//			Audio::StopLoopMusic(9);
	//			m_ani_time6++;
	//			Draw::Draw2D(98, m_wave_x + ground3->GetScroll(), m_wave_y - 230 + m_ani_time6, 1, 1);
	//			/*g_SceneNumber = RESULT;
	//			g_clearlist = true;
	//			g_key_flag = false;
	//			g_TankRemaining = false;*/
	//		}
	//	}
	//	else
	//	{
	//		g_key_flag = true;
	//	}
	//}
	//���\��
	//Draw::Draw2D(48, m_water_x + ground3->GetScroll(), m_water_y, 1.6, 1.4);

	//�g�̕\��(���)
	if (m_ani_time1 >= 109)
	{
		m_ani_time1 = 0;
	}
	else
	{
		m_ani_time1++;
	}

	//�g�̕\��(�O)
	if (m_ani_time2 >= 54)
	{
		m_ani_time2 = 0;
	}
	else
	{
		m_ani_time2++;
	}

	//Sprinkler�ɋ߂Â������l���A�j���[�V�������o��
	if (m_ani_time3 >= 29)
	{
		m_ani_time3 = 0;
	}
	else
	{
		m_ani_time3++;
	}

	//�ԕ\��
	if (g_TankRemaining >= 40)
	{
		Draw::Draw2D(97, m_fx, m_fy);  //S�����N
	}
	else if (g_TankRemaining >= 35)
	{
		Draw::Draw2D(96, m_fx, m_fy);  //A�����N
	}
	else if (g_TankRemaining >= 25)
	{
		Draw::Draw2D(95, m_fx, m_fy);  //B�����N
	}
	else if (g_TankRemaining >= 10)
	{
		Draw::Draw2D(94, m_fx, m_fy);  //C�����N
	}
	else if (g_TankRemaining >= 1)
	{
		Draw::Draw2D(93, m_fx, m_fy);  //D�����N
	}


	for (int i = 0; i < 10; i++)
	{
		if (m_p_hit_line_spri3->GetHitData()[i] != nullptr)
		{
			if (m_p_hit_line_spri3->GetHitData()[i]->GetElement() == 0)
			{
				if (m_move1 >= 120)
				{
					m_ani_time4++;
					//m_ani_time5++;

					if (m_ani_time4 < 200)//�X�v�����N���[�O�Ŏ�l���������~�܂�
					{
						Draw::Draw2D(0, m_wave_x + ground3->GetScroll() - 50 + m_move1, m_wave_y - 10, 1, 1);
					}
					else if (m_ani_time4 > 200 && m_ani_time4 < 300)//�z�[�X���Ȃ���
					{
						Draw::Draw2D(6, m_wave_x + ground3->GetScroll() - 50 + m_move1, m_wave_y - 10, 1, 1);//���Ⴊ��
					}
					else if (m_ani_time4 > 300)//�z�[�X��t���I���Ăю�l���Î~
					{
						Draw::Draw2D(50, m_wave_x - 36 + ground3->GetScroll() - 50 + m_move1, 300, 1, 1);
						
						Draw::Draw2D(77, m_wave_x - 8 + ground3->GetScroll() + m_move1, 307, 1, 1);
					
						if (g_SceneNumber == RESULT_MAIN&&m_vy == 0.0f)
						{
							Draw::Draw2D(0, m_wave_x + ground3->GetScroll() - 50 + m_move1, 220, 1, 1);
						}
						else if (m_sy <= 200)
						{
							Draw::Draw2D(9, m_wave_x + ground3->GetScroll() - 50 + m_move1, m_sy - 10, 1, 1);//�W�����v
						}
						else
						{
							Draw::Draw2D(72, m_wave_x + ground3->GetScroll() - 50 + m_move1, m_sy - 10, 1, 1);
						}
						
						if (m_ani_time4 >= 460)
						{
							m_move2++;
							//Draw::Draw2D(0, m_wave_x + ground2->GetScroll() - 50 + m_move1, m_sy - 10, 1, 1);
							if (tank3->GetWater_Remaining() > 0)
							{
								Audio::StartLoopMusic(13);
								Audio::LoopMusicVolume(13, 0.1f);

								if (m_move2 <= 10)//�X�v�����N���[���琅���o��
								{
									Draw::Draw2D(51, m_wave_x + ground3->GetScroll() + 60 + m_move1, m_wave_y-4, 1, 1);
								}
								else if (m_move2 >= 11 && m_move2 < 20)
								{
									Draw::Draw2D(51, m_wave_x + ground3->GetScroll() + 97 + m_move1, m_wave_y - 6, -1, 1);
								}
								else
								{
									m_move2 = 0;
								}
							}
							else
							{
								if (m_ani_time5 == -1)m_ani_time5++;
								Audio::StopLoopMusic(13);
							}
						}
					}
				}
				else
				{
					m_move1++;

					if (m_ani_time3 < 10)
					{
						Draw::Draw2D(2, m_wave_x + ground3->GetScroll() - 50 + m_move1, m_wave_y - 10, 1, 1);
					}
					else if (m_ani_time3 < 20)
					{
						Draw::Draw2D(7, m_wave_x + ground3->GetScroll() - 50 + m_move1, m_wave_y - 10, 1, 1);
					}
					else if (m_ani_time3 < 30)
					{
						Draw::Draw2D(0, m_wave_x + ground3->GetScroll() - 50 + m_move1, m_wave_y - 10, 1, 1);
					}
				}
			}
		}
	}

	//���w�i�\��
	if (m_BrackBackDraw == true)
	{
		Draw::Draw2D(117, m_BrackBack_x, m_BrackBack_y, m_BrackBack_sx, m_BrackBack_sy);  //�N���A��̍��w�i
	}

}