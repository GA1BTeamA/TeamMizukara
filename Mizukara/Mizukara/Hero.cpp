//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Hero.h"
#include "Sprinkler.h"
#include "ObjGround2.h"
#include "ObjGround3.h"

extern int g_SceneNumber;
extern bool g_key_flag;

//�R���X�g���N�^
CHero::CHero()
	:m_x(130),m_y(300)
	, m_copy_x(130), m_copy_y(300)
	,m_vx(0.0f),m_vy(0.0f)
	, m_direc(RIGHT), m_down(false), m_IsMenu(false)
	,m_ani_time (0)
	, move_x(5.0f)
	, move_dash_x(7.5f)
	, m_CKey_Frag(false)
	, m_XKey_Frag(false)
	, m_IsScroll(false)
	,m_hero_delete_flag(false)
	,m_IsHit2Line(false)
{
	m_name = PLAYER;

	Audio::LoopMusicVolume(1, 0.1f);

	m_point_position[0].x = 0;
	m_point_position[0].y = 0;
	m_point_position[1].x = 60;
	m_point_position[1].y = 0;
	m_point_position[2].x = 60;
	m_point_position[2].y = 100;
	m_point_position[3].x = 0;
	m_point_position[3].y = 100;

	//��l���q�b�g���C���쐬���A�l��ݒ�(��)
	m_p_hit_line_hero[0] = Collision::HitLineInsert(this);
	m_p_hit_line_hero[0]->SetPos1(m_x, m_y);
	m_p_hit_line_hero[0]->SetPos2(m_x, m_y + 100);
	m_p_hit_line_hero[0]->Set4direc(HIT_LEFT);

	//��l���q�b�g���C���쐬���A�l��ݒ�(�E)
	m_p_hit_line_hero[1] = Collision::HitLineInsert(this);
	m_p_hit_line_hero[1]->SetPos1(m_x + 60, m_y);
	m_p_hit_line_hero[1]->SetPos2(m_x + 60, m_y + 100);
	m_p_hit_line_hero[1]->Set4direc(HIT_RIGHT);

	//��l���q�b�g���C���쐬���A�l��ݒ�(��)
	m_p_hit_line_hero[2] = Collision::HitLineInsert(this);
	m_p_hit_line_hero[2]->SetPos1(m_x, m_y);
	m_p_hit_line_hero[2]->SetPos2(m_x + 60, m_y);
	m_p_hit_line_hero[2]->Set4direc(HIT_TOP);

	//��l���q�b�g���C���쐬���A�l��ݒ�(��)
	m_p_hit_line_hero[3] = Collision::HitLineInsert(this);
	m_p_hit_line_hero[3]->SetPos1(m_x, m_y + 100);
	m_p_hit_line_hero[3]->SetPos2(m_x + 60, m_y + 100);
	m_p_hit_line_hero[3]->Set4direc(HIT_UNDER);

	for (int i = 0; i < 4; i++) {
		m_p_hit_line_hero[i]->SetElement(0);		//������0�ɂ���
		m_p_hit_line_hero[i]->SetInvisible(false);	//���G���[�h����
		m_p_hit_line_hero[i]->SetAngle();
	}

	//��l���q�b�g���C���̃R�s�[���쐬���A�l��ݒ�(��)
	m_p_hit_line_hero_copy[0] = Collision::HitLineInsert(this);
	m_p_hit_line_hero_copy[0]->SetPos1(m_x, m_y);
	m_p_hit_line_hero_copy[0]->SetPos2(m_x, m_y + 100);
	m_p_hit_line_hero_copy[0]->Set4direc(HIT_LEFT);

	//��l���q�b�g���C���̃R�s�[���쐬���A�l��ݒ�(�E)
	m_p_hit_line_hero_copy[1] = Collision::HitLineInsert(this);
	m_p_hit_line_hero_copy[1]->SetPos1(m_x + 60, m_y);
	m_p_hit_line_hero_copy[1]->SetPos2(m_x + 60, m_y + 100);
	m_p_hit_line_hero_copy[1]->Set4direc(HIT_RIGHT);

	//��l���q�b�g���C���̃R�s�[���쐬���A�l��ݒ�(��)
	m_p_hit_line_hero_copy[2] = Collision::HitLineInsert(this);
	m_p_hit_line_hero_copy[2]->SetPos1(m_x, m_y);
	m_p_hit_line_hero_copy[2]->SetPos2(m_x + 60, m_y);
	m_p_hit_line_hero_copy[2]->Set4direc(HIT_TOP);

	//��l���q�b�g���C���̃R�s�[���쐬���A�l��ݒ�(��)
	m_p_hit_line_hero_copy[3] = Collision::HitLineInsert(this);
	m_p_hit_line_hero_copy[3]->SetPos1(m_x, m_y + 100);
	m_p_hit_line_hero_copy[3]->SetPos2(m_x + 60, m_y + 100);
	m_p_hit_line_hero_copy[3]->Set4direc(HIT_UNDER);

	for (int i = 0; i < 4; i++) {
		m_p_hit_line_hero_copy[i]->SetElement(0);		//������0�ɂ���
		m_p_hit_line_hero_copy[i]->SetInvisible(false);	//���G���[�h����
		m_p_hit_line_hero_copy[i]->SetAngle();
	}
}

CHero::~CHero()
{
}

void CHero::Action()
{
	if (m_hero_delete_flag == false)
	{
		////�e�X�g
		//float a, b;
		//CCollision::LineCrossPoint(0, 0, 10, 10, 0, 5, 10, 5, &a, &b);
		//int aa = 0;
		//aa++;

		//��_�܂ł���ԒZ���_
		float Move_x = -9999.0f, Move_y = -9999.0f;

		bool IsHitGround = false;//�n�ʂɓ������Ă��邩
		bool IsHitWall = false;//�ǂɓ������Ă��邩

							   //��_�܂ł���ԒZ���_
		float Cross_x_min = 9999.0f, Cross_y_min = 9999.0f;

		//�n�ʂɓ���������A
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				//��l���̓����蔻�肪���̓����蔻��ɂ������ĂȂ�������X�L�b�v
				if (m_p_hit_line_hero_copy[j]->GetHitData()[i] == nullptr)
					continue;

				//��l�����X�v�����N���[�ɓ����������l���폜
				if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetElement() == 4)
				{
					m_hero_delete_flag = true;

				}

				//��l���̓����蔻��ɓ������Ă��̂��n�ʂȂ�
				if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetElement() == 1)
				{
					//��l���̓����蔻��ƒn�ʂ̓����蔻�肪���s�Ȃ�X�L�b�v
					if (m_p_hit_line_hero_copy[j]->GetAngle() == m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle() ||
						((int)(m_p_hit_line_hero_copy[j]->GetAngle()) == 0 && (int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) == 180) ||
						((int)abs(m_p_hit_line_hero_copy[j]->GetAngle()) == (int)abs(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) == 180))
						continue;

					//�I�u�W�F�N�g�̉�����ɂ���������
					bool IsHitObjUnder = false;

					//�O�t���[����m_IsHit2Line��true�ɂȂ��Ă���n�ʂɓ������Ă���
					if (m_IsHit2Line) {
						IsHitGround = true;
						m_IsHit2Line = false;
					}

					for (int k = 0; k < 10; k++) {
						if (m_p_hit_line_hero_copy[j]->GetHitData()[k] != nullptr) {
							//���������q�b�g���C���̂Ȃ��ɓ����I�u�W�F�N�g�̓����蔻�肪�����āA
							if (/*m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetObj()->GetName() ==
								m_p_hit_line_hero_copy[j]->GetHitData()[k]->GetObj()->GetName()*/
								m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetElement() ==
								m_p_hit_line_hero_copy[j]->GetHitData()[k]->GetElement()) {
								//���ꂪ�����q�b�g���C������Ȃ��āA
								if (m_p_hit_line_hero_copy[j]->GetHitData()[i] !=
									m_p_hit_line_hero_copy[j]->GetHitData()[k]) {
									//�p�x�������Ȃ�
									if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle() ==
										m_p_hit_line_hero_copy[j]->GetHitData()[k]->GetAngle()) {
										//��ɂ�����̔���̂�
										if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y <=
											m_p_hit_line_hero_copy[j]->GetHitData()[k]->GetPoint1().y) {
											//��l���̉����肾������
											if (m_p_hit_line_hero_copy[j]->Get4direc() == HIT_UNDER) {
												m_IsHit2Line = true;
												IsHitGround = true;
											}
											//��l���̏㔻�肾������
											else if (m_p_hit_line_hero_copy[j]->Get4direc() == HIT_TOP) {
												IsHitObjUnder = true;
											}
											else {
												//��l���𓖂���������̋߂����̓_�Ɉړ��i�ǔ����h�~�j
												if (j == 0) {//��l���̍�
															 //Point1,2�̋߂��������[�u�ɓ����
													if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x) {
														Move_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x - m_x;
														IsHitWall = true;
													}
													else {
														Move_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x - m_x;
														IsHitWall = true;
													}
												}
												else if (j == 1) {//��l���̉E
													if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x) {
														Move_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x - m_x;
														IsHitWall = true;
													}
													else {
														Move_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x - m_point_position[2].x - m_x;
														IsHitWall = true;
													}
												}
											}
										}
									}
								}
							}
						}
					}

					if (IsHitObjUnder) {
						m_vy = 0.0f;
						m_copy_y = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y;
						continue;
					}

					//�c�̒n�ʔ���ɓ���������
					if ((int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) == 0 ||
						(int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) == 180) {
						//������
						m_vx = 0.0f;
						//if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->Get4direc() == HIT_LEFT){
						//	m_copy_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x - m_point_position[2].x;

						//}
					}
					//���������̂��@�I�u�W�F�N�g�̏㔻��Ł@�����x�N�g���Ł@��l���̌��ʒu����ɂ���ꍇ
					else if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->Get4direc() == HIT_TOP &&
						(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) == 90.0456467f &&
						m_y + m_point_position[2].y > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y &&
						m_y + m_point_position[2].y > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y) {
						IsHitWall = true;
					}
					else {
						//������
						//�n�ʂ̓����蔻�肪�v���C���[�̉��ɂ���ꍇ
						if (((m_p_hit_line_hero_copy[j]->GetHitData()[i]->Get4direc() == HIT_TOP) &&
							((m_y + m_point_position[2].y <= m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y) &&
							(m_y + m_point_position[2].y <= m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y))) ||
							//�n�ʂ̓����蔻�肪�v���C���[�̏�ɂ���ꍇ
								((m_p_hit_line_hero_copy[j]->GetHitData()[i]->Get4direc() == HIT_UNDER) &&
							((m_y >= m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y) &&
									(m_y >= m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y)))) {
							//!(��l���̃x�N�g���ƒn�ʂ̃x�N�g������_�����Őڂ��Ă��ꍇ)
							//��l���̍��̏ꍇ
							if (!(((m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x <= m_copy_x) &&
								(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x <= m_copy_x)) ||
								//�E�̏ꍇ
								((m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x >= m_copy_x + m_point_position[2].x) &&
								(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x >= m_copy_x + m_point_position[2].x)))) {
								m_vy = 0.0f;
								//���������n�ʂ̓����蔻�肪�I�u�W�F�N�g�̉��̕����Ȃ��̏������Ȃ�
								if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->Get4direc() == HIT_UNDER) {
									m_copy_y = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y;
									continue;
								}
							}
						}
					}

					//��_�ϐ�
					float Cross_x, Cross_y;
					////��_�܂ł���ԒZ���_
					//float Cross_x_min = 9999.0f, Cross_y_min = 9999.0f;

					if ((m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) != 90.0456467f &&
						(int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) != 0 &&
						(int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) != 180) {
						if (m_p_hit_line_hero_copy[j]->Get4direc() == HIT_RIGHT) {
							//�΂ߔ������l�������ɂ���Ə������Ȃ�
							if (m_y + m_point_position[2].y-20 <= m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y) {
								//��l���̈ړ��x�N�g���ƒn�ʃx�N�g���̌�_�����߂�
								Collision::LineCrossPoint(m_copy_x + m_point_position[2].x, m_copy_y /*+ m_point_position[2].y*/,
									m_copy_x + m_point_position[2].x, m_copy_y + m_point_position[2].y,
									m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x,
									m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y,
									m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x,
									m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y,
									&Cross_x, &Cross_y);

								//�G���[���Ԃ���Ȃ�������
								if (Cross_x != -9999.0f && Cross_y != -9999.0f)
								{
									//��l�������_�܂ł̃x�N�g�������o��
						//			Cross_x -= m_x + m_point_position[k].x;
									Cross_y = -(m_y + m_point_position[2].y - Cross_y);

									//��l�������_�܂ł̃x�N�g���̒������ԒZ�����̂�������
									//�����x�N�g���Ȃ炘����
									//if (Cross_x_min > Cross_x /*&& (int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) != 90*/)
									//{
									//	Cross_x_min = Cross_x;
									//}
									//�����x�N�g���Ȃ炙����
									if (Cross_y <= 0 && Cross_y_min > abs(Cross_y) && (int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) != 0)
									{
										if (m_x + m_point_position[2].x > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x) {
											Cross_y_min = Cross_y;
										}
										//�΂ߔ���ɉ����瓖��������~�߂�
										else {
											IsHitWall = true;
											Move_x = 0.0f;
										}
									}
								}
							}
							else {
								if (m_x + m_point_position[2].x <= m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x) {
									IsHitWall = true;
									Move_x = 0.0f;
								}
							}
						}
						else if (m_p_hit_line_hero_copy[j]->Get4direc() == HIT_LEFT) {
							//�΂ߔ������l�������ɂ���Ə������Ȃ�
							if (m_y + m_point_position[2].y-20 <= m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y) {
								//��l���̈ړ��x�N�g���ƒn�ʃx�N�g���̌�_�����߂�
								Collision::LineCrossPoint(m_copy_x, m_copy_y,
									m_copy_x, m_copy_y + m_point_position[2].y,
									m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x,
									m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y,
									m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x,
									m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y,
									&Cross_x, &Cross_y);

								//�G���[���Ԃ���Ȃ�������
								if (Cross_x != -9999.0f && Cross_y != -9999.0f)
								{
									//��l�������_�܂ł̃x�N�g�������o��
									//			Cross_x -= m_x + m_point_position[k].x;
									Cross_y = -(m_y + m_point_position[2].y - Cross_y);

									//��l�������_�܂ł̃x�N�g���̒������ԒZ�����̂�������
									//�����x�N�g���Ȃ炘����
									//if (Cross_x_min > Cross_x /*&& (int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) != 90*/)
									//{
									//	Cross_x_min = Cross_x;
									//}
									//�����x�N�g���Ȃ炙����
									if (Cross_y <= 0 && Cross_y_min > abs(Cross_y) && (int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) != 0)
									{
										if (m_x < m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x) {
											Cross_y_min = Cross_y;
										}
										//�΂ߔ���ɉ����瓖��������~�߂�
										else {
											IsHitWall = true;
											Move_x = 0.0f;
										}
									}
								}
							}
							else {
								if (m_x > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x) {
									IsHitWall = true;
									Move_x = 0.0f;
								}
							}
						}
						//���ƉE�̓����蔻��ɂ������ĂȂ��ĉ��ɓ���������[�̏�ɗ�������
						else if (Cross_y_min == 9999.0f &&
							m_p_hit_line_hero_copy[j]->Get4direc() == HIT_UNDER) {
							//if (m_x + m_point_position[2].x > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x &&
							//	m_x < m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x) {
							//	if (m_y + m_point_position[2].y <= m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y &&
							//		m_y + m_point_position[2].y <= m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y) {
							if (m_x < m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x &&
								m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x < m_x + m_point_position[2].x) {
									Move_y = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y - (m_copy_y + m_point_position[2].y);
								IsHitGround = true;
							}
							else if (m_x < m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x &&
								m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x < m_x + m_point_position[2].x) {
								Move_y = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y - (m_copy_y + m_point_position[2].y);
								IsHitGround = true;
							}

							//	}
							//}
						}
					}

					//������
					Cross_x = Cross_y = -9999.0f;
						
					//��l���̂����蔻��̒��_�����[�v
					for (int k = 0; k < 4; k++)
					{
						//��l���̏c���肩�A
						//�n�ʂ���l���̒�ӂ���ɂ���ꍇ�A�ڂ��Ă鑤�̒n�ʃx�N�g���̓_�܂ňړ��i�Z���ǔ����h�~�j
						/*	if (m_p_hit_line_hero_copy[j]->GetAngle() == 0.0f &&
						((m_y + m_point_position[2].y > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y) &&
						(m_y + m_point_position[2].y > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y))) {
						if (j == 0) {//��l���̍�
						if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x) {
						m_copy_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x;
						}
						else {
						m_copy_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x;
						}
						}
						else if (j == 1) {//��l���̉E
						if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x) {
						m_copy_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x;
						}
						else {
						m_copy_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x - m_point_position[2].x;
						}
						}
						}*/
						{
							//��l���̈ړ��x�N�g���ƒn�ʃx�N�g�����������ゾ������
							if (m_x + m_point_position[k].x
								== m_copy_x + m_point_position[k].x
								== m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x
								== m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x) {
								IsHitWall = true;
							}
							//��l���̈ړ��x�N�g���ƒn�ʃx�N�g�����������ゾ������
							else if ((m_y + m_point_position[k].y == m_copy_y + m_point_position[k].y)
								&& (m_y + m_point_position[k].y == m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y)
								&& (m_y + m_point_position[k].y == m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y)) {
								IsHitGround = true;
							}
							else {
								//���Ɉړ����Ă�Ƃ��ɃI�u�W�F�N�g�̉�����ɓ���������
								//��Ɉړ����Ă�Ƃ��ɃI�u�W�F�N�g�̏㔻��ɓ���������
								if ((m_y > m_copy_y && m_p_hit_line_hero_copy[j]->GetHitData()[i]->Get4direc() == HIT_TOP) ||
									(m_y < m_copy_y && m_p_hit_line_hero_copy[j]->GetHitData()[i]->Get4direc() == HIT_UNDER)) {
									//�����x�N�g���̏ꍇ�̂�
									if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle() == 90.0456467f) {
										if (j == 0) {//��l���̍�
													 //Point1,2�̋߂��������[�u�ɓ����
											if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x) {
												Move_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x - m_x;
												IsHitWall = true;
											}
											else {
												Move_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x - m_x;
												IsHitWall = true;
											}
										}
										else if (j == 1) {//��l���̉E
											if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x > m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x) {
												Move_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x - m_x;
												IsHitWall = true;
											}
											else {
												Move_x = m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x - m_point_position[2].x - m_x;
												IsHitWall = true;
											}
										}
									}
								}
								else {
									//��l���̈ړ��x�N�g���ƒn�ʃx�N�g���̌�_�����߂�
									Collision::LineCrossPoint(m_x + m_point_position[k].x, m_y + m_point_position[k].y,
										m_copy_x + m_point_position[k].x, m_copy_y + m_point_position[k].y,
										m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x,
										m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y,
										m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x,
										m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y,
										&Cross_x, &Cross_y);

									//�G���[���Ԃ���Ȃ�������
									if (Cross_x != -9999.0f && Cross_y != -9999.0f)
									{
										//��l�������_�܂ł̃x�N�g�������o��
										Cross_x -= m_x + m_point_position[k].x;
										Cross_y -= m_y + m_point_position[k].y;

										//��l�������_�܂ł̃x�N�g���̒������ԒZ�����̂�������
										//�����x�N�g���Ȃ炘����
										if (Cross_x_min > Cross_x && (int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) == 0 ||
																	 (int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) == 180)
										{
											Cross_x_min = Cross_x;
										}
										//�����x�N�g���Ȃ炙����
										if (Cross_y_min > Cross_y && (int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) != 0)
										{
											Cross_y_min = Cross_y;
										}
									}
								}
							}
						}
					}
					//!(��l���̏c�x�N�g���ƒn�ʂ̃x�N�g������_�����Őڂ��Ă��ꍇ)
					if ((int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) != 0 &&
						(int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) != 180) {
						//��l���̍��̏ꍇ
						if (!(((m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x <= m_copy_x) &&
							(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x <= m_copy_x)) ||
							//�E�̏ꍇ
							((m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().x >= m_copy_x + m_point_position[2].x) &&
							(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().x >= m_copy_x + m_point_position[2].x)))) {
							//�G���[����Ȃ���Ύ�l������_�܂ňړ�
							if (Cross_x_min != 9999.0f) {
								if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->Get4direc() == HIT_TOP) {
									IsHitGround = true;
								}
								if (Move_x < Cross_x_min) Move_x = Cross_x_min;
							}
							if (Cross_y_min != 9999.0f) {
								if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->Get4direc() == HIT_TOP) {
									IsHitGround = true;
								}
								if (Move_y < abs(Cross_y_min)) Move_y = Cross_y_min;
							}
						}
					}
					else {
						//��l����荂���ꍇ
						if (!(((m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y <= m_copy_y) &&
							(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y <= m_copy_y)) ||
							//�Ⴂ�ꍇ
							((m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint1().y >= m_copy_y + m_point_position[2].y) &&
							(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetPoint2().y >= m_copy_y + m_point_position[2].y)))) {
							if ((int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) == 90 ||
								(int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) == 0  ||
								(int)(m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetAngle()) == 180) {
								//�G���[����Ȃ���Ύ�l������_�܂ňړ�
								if (Cross_x_min != 9999.0f) {
									IsHitWall = true;
									if (Move_x < Cross_x_min) Move_x = Cross_x_min;
								}
								if (Cross_y_min != 9999.0f) {
									IsHitWall = true;
									if (Move_y < Cross_y_min) Move_y = Cross_y_min;
								}
							}
						}
					}

				}
			}
			//���[�v�̍Ō�
			if (i == 9)
			{

				//�O���X�N���[�����C��
				if (m_copy_x > 350.0f)
				{
					//�n�ʃI�u�W�F�N�g�擾
					CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);
					ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);
					ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);
					//�X�e�[�W1
					//�n�ʃI�u�W�F�N�g���k���|�C���^�[����Ȃ�������
					if (ground != nullptr) {
						if (ground->GetScroll() != -1600.0f) {
							if (Move_x != -9999.0f) {
								//�X�N���[���l���Z
								ground->AddScroll(m_x + Move_x - 350.0f);
								//��l�����X�N���[�����C���Ŏ~�߂�
								m_x = 350.0f;
							}
							else {
								//�X�N���[���l���Z
								ground->AddScroll(m_copy_x - 350.0f);
								//��l�����X�N���[�����C���Ŏ~�߂�
								m_x = 350.0f;
							}
							m_IsScroll = true;
						}
						else if (Move_x != -9999.0f) {
							m_x += Move_x;
						}
					}
					//�X�e�[�W2
					if (ground2 != nullptr) {
						if (ground2->GetScroll() != -2400.0f) {
							if (Move_x != -9999.0f) {
								//�X�N���[���l���Z
								ground2->AddScroll(m_x + Move_x - 350.0f);
								//��l�����X�N���[�����C���Ŏ~�߂�
								m_x = 350.0f;
							}
							else {
								//�X�N���[���l���Z
								ground2->AddScroll(m_copy_x - 350.0f);
								//��l�����X�N���[�����C���Ŏ~�߂�
								m_x = 350.0f;
							}
							m_IsScroll = true;
						}
						else if (Move_x != -9999.0f) {
							m_x += Move_x;
						}
					}
					//�X�e�[�W3
					if (ground3 != nullptr) {
						if (ground3->GetScroll() != -2400.0f) {
							if (Move_x != -9999.0f) {
								//�X�N���[���l���Z
								ground3->AddScroll(m_x + Move_x - 350.0f);
								//��l�����X�N���[�����C���Ŏ~�߂�
								m_x = 350.0f;
							}
							else {
								//�X�N���[���l���Z
								ground3->AddScroll(m_copy_x - 350.0f);
								//��l�����X�N���[�����C���Ŏ~�߂�
								m_x = 350.0f;
							}
							m_IsScroll = true;
						}
						else if (Move_x != -9999.0f) {
							m_x += Move_x;
						}
					}
				}
				//����X�N���[�����C��
				else if (m_copy_x < 200.0f)
				{
					//�n�ʃI�u�W�F�N�g�擾
					CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);
					ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);
					ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);
					//�X�e�[�W1
					//�n�ʃI�u�W�F�N�g���k���|�C���^�[����Ȃ�������
					if (ground != nullptr) {
						if (ground->GetScroll() != 0.0f) {
							if (Move_x != -9999.0f) {
								//�X�N���[���l���Z
								ground->AddScroll(m_x + Move_x - 200.0f);
								//��l�����X�N���[�����C���Ŏ~�߂�
								m_x = 200.0f;
							}
							else {
								//�X�N���[���l���Z
								ground->AddScroll(m_copy_x - 200.0f);
								//��l�����X�N���[�����C���Ŏ~�߂�
								m_x = 200.0f;
							}
							m_IsScroll = true;
						}
						else if (Move_x != -9999.0f) {
							m_x += Move_x;
						}
					}
					//�X�e�[�W2
					if (ground2 != nullptr) {
						if (ground2->GetScroll() != 0.0f) {
							if (Move_x != -9999.0f) {
								//�X�N���[���l���Z
								ground2->AddScroll(m_x + Move_x - 200.0f);
								//��l�����X�N���[�����C���Ŏ~�߂�
								m_x = 200.0f;
							}
							else {
								//�X�N���[���l���Z
								ground2->AddScroll(m_copy_x - 200.0f);
								//��l�����X�N���[�����C���Ŏ~�߂�
								m_x = 200.0f;
							}
							m_IsScroll = true;
						}
						else if (Move_x != -9999.0f) {
							m_x += Move_x;
						}
					}
					//�X�e�[�W3
					if (ground3 != nullptr) {
						if (ground3->GetScroll() != 0.0f) {
							if (Move_x != -9999.0f) {
								//�X�N���[���l���Z
								ground3->AddScroll(m_x + Move_x - 200.0f);
								//��l�����X�N���[�����C���Ŏ~�߂�
								m_x = 200.0f;
							}
							else {
								//�X�N���[���l���Z
								ground3->AddScroll(m_copy_x - 200.0f);
								//��l�����X�N���[�����C���Ŏ~�߂�
								m_x = 200.0f;
							}
							m_IsScroll = true;
						}
						else if (Move_x != -9999.0f) {
							m_x += Move_x;
						}
					}

				}
				else {
					if (Move_x != -9999.0f) {
						m_x += Move_x;
					}
				}
				if (Move_y != -9999.0f) {
					m_y += Move_y;
				}

				//�n�ʂƕǂɓ������Ă���X���[
				if (IsHitGround && IsHitWall) {
					continue;
				}
				//�n�ʂɓ������Ă���X�����Ɉړ���
				else if (IsHitGround) {
					if (m_IsScroll == false) {
						m_x = m_copy_x;
					}
				}
				//�ǂɓ������Ă���Y�����Ɉړ���
				else if (IsHitWall) {
					m_y = m_copy_y;
				}
				//�n�ʂƕǂɓ������ĂȂ�������X��Y���ړ���
				else {
					if (m_IsScroll == false) {
						m_x = m_copy_x;
					}
					m_y = m_copy_y;
				}
			}
		}

		if (g_SceneNumber == GAME_MAIN2) {
			ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);

			//��������
			//�������̗L���͈�
			if (m_x+ abs(ground2->GetScroll()) >= 2150 && 2350 >= m_x + abs(ground2->GetScroll()))
			{
				//�~�̒��S�_�@-�i�i�ΕӁ@*�@�ΕӁj-�i��Ӂ@*�@��Ӂj�j
				if (m_y > 225 - sqrt(100 * 100 - (2250 - (m_x + abs(ground2->GetScroll())))*(2250 - (m_x + abs(ground2->GetScroll()))))) {
					m_y = 225 - sqrt(100 * 100 - (2250 - (m_x + abs(ground2->GetScroll())))*(2250 - (m_x + abs(ground2->GetScroll()))));
					IsHitGround = true;
				}
			}
			//��
			if (m_x + abs(ground2->GetScroll()) >= 2350 && 3200 >= m_x + abs(ground2->GetScroll()))
			{
				if (m_y > 380 - sqrt(270 * 270 - (2675 - (m_x + abs(ground2->GetScroll())))*(2675 - (m_x + abs(ground2->GetScroll()))))) {
					m_y = 380 - sqrt(270 * 270 - (2675 - (m_x + abs(ground2->GetScroll())))*(2675 - (m_x + abs(ground2->GetScroll()))));
					IsHitGround = true;
				}
			}

		}

		//�����蔻��̈ʒu�X�V
		m_p_hit_line_hero[0]->SetPos1(m_x, m_y);
		m_p_hit_line_hero[0]->SetPos2(m_x, m_y + 100);
		m_p_hit_line_hero[1]->SetPos1(m_x + 60, m_y);
		m_p_hit_line_hero[1]->SetPos2(m_x + 60, m_y + 100);
		m_p_hit_line_hero[2]->SetPos1(m_x, m_y);
		m_p_hit_line_hero[2]->SetPos2(m_x + 60, m_y);
		m_p_hit_line_hero[3]->SetPos1(m_x, m_y + 100);
		m_p_hit_line_hero[3]->SetPos2(m_x + 60, m_y + 100);

		//�R�s�[�̈ʒu�X�V
		m_copy_x = m_x;
		m_copy_y = m_y;

		//�R�s�[�̓����蔻��̈ʒu�X�V
		m_p_hit_line_hero_copy[0]->SetPoint1(m_p_hit_line_hero[0]->GetPoint1());
		m_p_hit_line_hero_copy[0]->SetPoint2(m_p_hit_line_hero[0]->GetPoint2());
		m_p_hit_line_hero_copy[1]->SetPoint1(m_p_hit_line_hero[1]->GetPoint1());
		m_p_hit_line_hero_copy[1]->SetPoint2(m_p_hit_line_hero[1]->GetPoint2());
		m_p_hit_line_hero_copy[2]->SetPoint1(m_p_hit_line_hero[2]->GetPoint1());
		m_p_hit_line_hero_copy[2]->SetPoint2(m_p_hit_line_hero[2]->GetPoint2());
		m_p_hit_line_hero_copy[3]->SetPoint1(m_p_hit_line_hero[3]->GetPoint1());
		m_p_hit_line_hero_copy[3]->SetPoint2(m_p_hit_line_hero[3]->GetPoint2());


		//���j���[
		if (Input::KeyPush('Q'))
		{
			if (m_menu_key_flag)
			{
				//���j���[�I�u�W�F�N�g�𐶐�
				if (m_IsMenu == false)
				{
					Audio::StopLoopMusic(6);
					//menu = new CMenu();
					//�n�ʃI�u�W�F�N�g�擾
					CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);
					ObjGround2* ground2 = (ObjGround2*)TaskSystem::GetObj(GROUND2);
					ObjGround3* ground3 = (ObjGround3*)TaskSystem::GetObj(GROUND3);

					if(ground != nullptr) menu = new CMenu(1);
					else if (ground2 != nullptr) menu = new CMenu(2);
					else if (ground3 != nullptr) menu = new CMenu(3);
					menu->m_ActionPriority = 100;
					menu->m_DrawPriority = 900;
					TaskSystem::InsertObj(menu);
					m_IsMenu = true;
					Audio::StartLoopMusic(2);
					Audio::LoopMusicVolume(2, 0.05f);
				}
				//���j���[�I�u�W�F�N�g��j��
				else
				{
					//�I�u�W�F�N�g�擾
					CMenu* menu = (CMenu*)TaskSystem::GetObj(MENU);
					if (menu != nullptr)
					{
						menu->is_delete = true;
						m_IsMenu = false;
						Audio::StopLoopMusic(2);
						Audio::StartLoopMusic(6);
					}
				}
				m_menu_key_flag = false;
			}
		}
		else m_menu_key_flag = true;

		if (m_IsMenu == false)
		{
			//�f�o�b�O�p
			/*if (Input::KeyPush(VK_UP))
			{
				m_y -= 5.0f;

			}

			if (Input::KeyPush(VK_DOWN))
			{
				m_y += 5.0f;

			}*/

			//��̐���(���Y���s�v�c)--------
			//	CObjGround ground;
			//------------------------------

			//���U���g��ʂɂ�������
			//if (m_x + 60 >= 800)
			//{
			//	g_SceneNumber = RESULT;
			//	is_delete = true;
			//	g_key_flag = false;
			//}

			//if (m_p_hit_line->GetHitData()[1] != nullptr)
			//{
			//	m_x -= 1.0f;
			//}

			//CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

			//���L�[�ňړ�
			if (Input::KeyPush(VK_LEFT))
			{
				if (Input::KeyPush('V'))
				{
					m_copy_x -= move_dash_x;//V�L�[�Ń_�b�V��
				}
				else
				{
					m_copy_x -= move_x;
				}
				if (m_copy_x < 0.0f)//��l�����̈�O�𒴂������~
				{
					m_copy_x = 0.0f;
				}
				m_direc = LEFT;
			}
			//�E�L�[�ňړ�
			else if (Input::KeyPush(VK_RIGHT))
			{
				if (Input::KeyPush('V'))
				{
					m_copy_x += move_dash_x;//V�L�[�Ń_�b�V��
				}
				else
				{
					m_copy_x += move_x;
				}
				if (m_copy_x + 60.0f > 800.0f)//��l�����̈�O�𒴂������~
				{
					m_copy_x = 800.0f - 60.0f;
				}
				m_direc = RIGHT;
			}

			//�f�o�b�O�p
			//m_copy_x += move_dash_x;
			if(IsHitGround)
	//		m_vy = 0.0f;

			//�n�ʂɓ������Ă���X�y�[�X�L�[�ŃW�����v
			if (IsHitGround)
			{
				if (Input::KeyPush(VK_SPACE) == true)
				{
					m_vy = -7.8f;
				}
			}

			//C�L�[��������Ă��邩�ǂ���
			if (Input::KeyPush('C'))
			{
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						//��l���̓����蔻�肪���̓����蔻��ɂ������ĂȂ�������X�L�b�v
						if (m_p_hit_line_hero_copy[j]->GetHitData()[i] == nullptr)
							continue;

						//��l���̓����蔻��ɓ������Ă��̂��^���NorWTM�Ȃ��
						if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetElement() == 3 ||
							m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetElement() == 2 ||
							m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetElement() == 5 ||
							m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetElement() == 6)
						{
							if (m_CKey_Frag == false)
								Audio::StartLoopMusic(1);
								Audio::LoopMusicVolume(1, 0.03f);

							m_CKey_Frag = true;
						}
					}
				}
			}
			else
			{
				m_CKey_Frag = false;
			}

			//X�L�[��������Ă��邩�ǂ���
			if (Input::KeyPush('X'))
			{
				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						//��l���̓����蔻�肪���̓����蔻��ɂ������ĂȂ�������X�L�b�v
						if (m_p_hit_line_hero_copy[j]->GetHitData()[i] == nullptr)
							continue;

						//��l���̓����蔻��ɓ������Ă��̂��^���NorWTM�Ȃ��
						if (m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetElement() == 3 ||
							m_p_hit_line_hero_copy[j]->GetHitData()[i]->GetElement() == 2)
						{
							if (m_XKey_Frag == false)
								Audio::StartLoopMusic(1);

							m_XKey_Frag = true;
						}
					}
				}
			}
			else
			{
				m_XKey_Frag = false;
			}

			//C��X�������ĂȂ������特�y���~�߂�
			if (!(Input::KeyPush('C')) && !(Input::KeyPush('X')))
				Audio::StopLoopMusic(1);


			//���R�����^��
			if (IsHitGround == false) {
				m_vy += 9.8 / (16.0f);
			}

			m_copy_y += m_vy;

			/*		//�O���X�N���[�����C��
			if (m_copy_x > 350.0f)
			{
			//�n�ʃI�u�W�F�N�g�擾
			CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);
			//�n�ʃI�u�W�F�N�g���k���|�C���^�[����Ȃ�������
			if (ground != nullptr) {
			//�X�N���[���l���Z
			ground->AddScroll(m_copy_x - 350.0f);
			//��l�����X�N���[�����C���Ŏ~�߂�
			m_copy_x = 350.0f;
			}
			}
			//����X�N���[�����C��
			else if (m_copy_x < 200.0f)
			{
			//�n�ʃI�u�W�F�N�g�擾
			CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);
			//�n�ʃI�u�W�F�N�g���k���|�C���^�[����Ȃ�������
			if (ground != nullptr) {
			//�X�N���[���l���Z
			ground->AddScroll(m_copy_x - 200.0f);
			//��l�����X�N���[�����C���Ŏ~�߂�
			m_copy_x = 200;
			}
			}*/


			m_p_hit_line_hero_copy[0]->SetPos1(m_copy_x, m_copy_y);
			m_p_hit_line_hero_copy[0]->SetPos2(m_copy_x, m_copy_y + 100);
			m_p_hit_line_hero_copy[1]->SetPos1(m_copy_x + 60, m_copy_y);
			m_p_hit_line_hero_copy[1]->SetPos2(m_copy_x + 60, m_copy_y + 100);
			m_p_hit_line_hero_copy[2]->SetPos1(m_copy_x, m_copy_y);
			m_p_hit_line_hero_copy[2]->SetPos2(m_copy_x + 60, m_copy_y);
			m_p_hit_line_hero_copy[3]->SetPos1(m_copy_x, m_copy_y + 100);
			m_p_hit_line_hero_copy[3]->SetPos2(m_copy_x + 60, m_copy_y + 100);

			//������
			m_IsScroll = false;


			//�A�j���[�V����
			if (Input::KeyPush(VK_RIGHT) || Input::KeyPush(VK_LEFT))
			{
				m_ani_time++;
				if (m_ani_time >= 32)
				{
					m_ani_time = 0;
				}
			}
			else
			{
				m_ani_time = 0;
			}

		}
	}
}

void CHero::Draw()
{
	if (m_hero_delete_flag == false)
	{
		//�`��
		if (m_IsMenu)
		{
			//���j���[�J���Ă�Ƃ�
			if (m_direc == RIGHT)
			{
				//��l��������
				Draw::Draw2D(0, m_x, m_y);
			}
			else if (m_direc == LEFT)
			{
				//��l���E����
				Draw::Draw2D(1, m_x, m_y);
			}
		}
		else
		{
			if (Input::KeyPush(VK_LEFT))
			{
				//������
				if (m_ani_time <= 8) {
					Draw::Draw2D(3, m_x, m_y);
				}
				else if (m_ani_time <= 16) {
					Draw::Draw2D(1, m_x, m_y);
				}
				else if (m_ani_time <= 24) {
					Draw::Draw2D(8, m_x, m_y);
				}
				else {
					Draw::Draw2D(1, m_x, m_y);
				}
			}
			else if (Input::KeyPush(VK_RIGHT))
			{
				//�E����
				if (m_ani_time <= 8) {
					Draw::Draw2D(2, m_x, m_y);
				}
				else if (m_ani_time <= 16) {
					Draw::Draw2D(0, m_x, m_y);
				}
				else if (m_ani_time <= 24) {
					Draw::Draw2D(7, m_x, m_y);
				}
				else {
					Draw::Draw2D(0, m_x, m_y);
				}
			}
			else if (m_XKey_Frag == true)
			{
				if (m_direc == RIGHT)
				{
					//�����މE����
					Draw::Draw2D(5, m_x, m_y);
				}
				else if (m_direc == LEFT)
				{
					//�����ލ�������
					Draw::Draw2D(5, m_x + 60, m_y, -1, 1);
				}
			}
			else if (m_CKey_Frag == true)
			{
				if (m_direc == RIGHT)
				{
					//���߂��E����
					Draw::Draw2D(4, m_x, m_y);
				}
				else if (m_direc == LEFT)
				{
					//���߂�������
					Draw::Draw2D(4, m_x + 60, m_y, -1, 1);
				}
			}
			else if (m_CKey_Frag == false)
			{
				//������
				if (m_direc == RIGHT)
				{
					Draw::Draw2D(0, m_x, m_y,1.0f,1.0f,0.0f);
				}
				else if (m_direc == LEFT)
				{
					//�E����
					Draw::Draw2D(1, m_x, m_y);
				}
			}
			/*else if (Input::KeyPush(VK_SPACE))
			{
				Draw::Draw2D(6, m_x, m_y);
			}*/
		}
	}
}