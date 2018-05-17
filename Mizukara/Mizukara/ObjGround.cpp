//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjGround.h"
#include "Hero.h"

CObjGround::CObjGround()
	:m_gx(0), m_gy(0), m_scroll(0.0f)
{
	m_name = GROUND;

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[0] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[0]->SetPos1(m_scroll + 0, m_gy + 400);
	m_p_hit_line_ground[0]->SetPos2(m_scroll + 500, m_gy + 400);
	m_p_hit_line_ground[0]->Set4direc(HIT_TOP);

	//�f�o�b�O�p
	m_p_hit_line_ground[0]->SetElement(2);		//������1�ɂ���
	m_p_hit_line_ground[0]->SetInvisible(false);	//���G���[�h����
	m_p_hit_line_ground[0]->SetAngle();

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[1] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[1]->SetPos1(m_scroll + 500, m_gy + 350);
	m_p_hit_line_ground[1]->SetPos2(m_scroll + 500, m_gy + 400);
	m_p_hit_line_ground[1]->Set4direc(HIT_LEFT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[2] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[2]->SetPos1(m_scroll + 500, m_gy + 350);
	m_p_hit_line_ground[2]->SetPos2(m_scroll + 600, m_gy + 350);
	m_p_hit_line_ground[2]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[3] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[3]->SetPos1(m_scroll + 600, m_gy + 320);
	m_p_hit_line_ground[3]->SetPos2(m_scroll + 600, m_gy + 350);
	m_p_hit_line_ground[3]->Set4direc(HIT_LEFT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[4] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[4]->SetPos1(m_scroll + 600, m_gy + 320);
	m_p_hit_line_ground[4]->SetPos2(m_scroll + 850, m_gy + 320);
	m_p_hit_line_ground[4]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[5] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[5]->SetPos1(m_scroll + 850, m_gy + 320);
	m_p_hit_line_ground[5]->SetPos2(m_scroll + 850, m_gy + 280);
	m_p_hit_line_ground[5]->Set4direc(HIT_LEFT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[6] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[6]->SetPos1(m_scroll + 850, m_gy + 280);
	m_p_hit_line_ground[6]->SetPos2(m_scroll + 900, m_gy + 280);
	m_p_hit_line_ground[6]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[7] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[7]->SetPos1(m_scroll + 900, m_gy + 280);
	m_p_hit_line_ground[7]->SetPos2(m_scroll + 900, m_gy + 240);
	m_p_hit_line_ground[7]->Set4direc(HIT_LEFT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[8] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[8]->SetPos1(m_scroll + 900, m_gy + 240);
	m_p_hit_line_ground[8]->SetPos2(m_scroll + 1700, m_gy + 240);
	m_p_hit_line_ground[8]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[9] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[9]->SetPos1(m_scroll + 1307, m_gy + 264);
	m_p_hit_line_ground[9]->SetPos2(m_scroll + 1307, m_gy + 237);
	m_p_hit_line_ground[9]->Set4direc(HIT_RIGHT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[10] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[10]->SetPos1(m_scroll + 1207, m_gy + 264);
	m_p_hit_line_ground[10]->SetPos2(m_scroll + 1333, m_gy + 264);
	m_p_hit_line_ground[10]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[11] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[11]->SetPos1(m_scroll + 1333, m_gy + 291);
	m_p_hit_line_ground[11]->SetPos2(m_scroll + 1333, m_gy + 264);
	m_p_hit_line_ground[11]->Set4direc(HIT_RIGHT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[12] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[12]->SetPos1(m_scroll + 1233, m_gy + 291);
	m_p_hit_line_ground[12]->SetPos2(m_scroll + 1359, m_gy + 291);
	m_p_hit_line_ground[12]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[13] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[13]->SetPos1(m_scroll + 1359, m_gy + 318);
	m_p_hit_line_ground[13]->SetPos2(m_scroll + 1359, m_gy + 291);
	m_p_hit_line_ground[13]->Set4direc(HIT_RIGHT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[14] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[14]->SetPos1(m_scroll + 1259, m_gy + 318);
	m_p_hit_line_ground[14]->SetPos2(m_scroll + 1385, m_gy + 318);
	m_p_hit_line_ground[14]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[15] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[15]->SetPos1(m_scroll + 1385, m_gy + 318);
	m_p_hit_line_ground[15]->SetPos2(m_scroll + 1385, m_gy + 346);
	m_p_hit_line_ground[15]->Set4direc(HIT_RIGHT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[16] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[16]->SetPos1(m_scroll + 1285, m_gy + 346);
	m_p_hit_line_ground[16]->SetPos2(m_scroll + 1411, m_gy + 346);
	m_p_hit_line_ground[16]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[17] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[17]->SetPos1(m_scroll + 1411, m_gy + 346);
	m_p_hit_line_ground[17]->SetPos2(m_scroll + 1411, m_gy + 373);
	m_p_hit_line_ground[17]->Set4direc(HIT_RIGHT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[18] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[18]->SetPos1(m_scroll + 1311, m_gy + 373);
	m_p_hit_line_ground[18]->SetPos2(m_scroll + 1437, m_gy + 373);
	m_p_hit_line_ground[18]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[19] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[19]->SetPos1(m_scroll + 1437, m_gy + 373);
	m_p_hit_line_ground[19]->SetPos2(m_scroll + 1437, m_gy + 400);
	m_p_hit_line_ground[19]->Set4direc(HIT_RIGHT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[20] = Collision::HitLineInsert(this);
	m_p_hit_line_ground[20]->SetPos1(m_scroll + 1337, m_gy + 400);
	m_p_hit_line_ground[20]->SetPos2(m_scroll + 1900, m_gy + 400);
	m_p_hit_line_ground[20]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground[21] = Collision::HitLineInsert(this);
	//m_p_hit_line_ground[21]->SetPos1(m_scroll + 900, m_gy + 240);
	//m_p_hit_line_ground[21]->SetPos2(m_scroll + 1700, m_gy + 240);
	m_p_hit_line_ground[21]->Set4direc(HIT_TOP);


	for (int i = 1; i < 22; i++) {
		m_p_hit_line_ground[i]->SetElement(1);		//������1�ɂ���
		m_p_hit_line_ground[i]->SetInvisible(false);	//���G���[�h����
		m_p_hit_line_ground[i]->SetAngle();
	}

}

CObjGround::~CObjGround()
{

}

void CObjGround::Action()
{
	/*CHero* hero = (CHero*)TaskSystem::GetObj(PLAYER);
	float m_x = hero->GetX();
	float m_y = hero->GetY();

	/*if (hero != nullptr)
	{
	hero->is_delete = true;
	//m_IsHero = false;
	}*/

	//m_scroll = -3.0f;//�X�N���[��


	/*	if (Input::KeyPush(VK_RIGHT)) {
	//�O���X�N���[�����C��
	if (m_x > 350)
	{
	else
	{
	hero->SetX(350);   //��l�����w��̈�𒴂��Ȃ��悤��

	if (Input::KeyPush('V')) //�_�b�V�����Ă鎞�̃X�N���[��
	{
	m_scroll -= hero->GetDashX();   //��l�����{�������ׂ��l��m_scroll�ɉ�����
	//�n�ʔ���ɃX�N���[�����f
	m_gx -= hero->GetDashX();
	}
	else  //�����Ă��鎞�̃X�N���[��
	{
	m_scroll -= hero->GetMoveX();  //��l�����{�������ׂ��l��m_scroll�ɉ�����
	//�n�ʔ���ɃX�N���[�����f
	m_gx -= hero->GetMoveX();
	}
	}
	}
	}
	else if (Input::KeyPush(VK_LEFT)) {
	//����X�N���[�����C��
	if (m_x < 200)
	{
	//�[����������X�e�[�W�[�����Ȃ��悤�ɂ���
	if (m_scroll >= 0)
	{
	m_scroll = 0.0f;
	}
	else
	{
	hero->SetX(200);   //��l�����w��̈�𒴂��Ȃ��悤��

	if (Input::KeyPush('V')) //�_�b�V�����Ă鎞�̃X�N���[��
	{
	m_scroll += hero->GetDashX();   //��l�����{�������ׂ��l��m_scroll�ɉ�����
	//�n�ʔ���ɃX�N���[�����f
	m_gx += hero->GetDashX();
	}
	else  //�����Ă��鎞�̃X�N���[��
	{
	m_scroll += hero->GetMoveX();   //��l�����{�������ׂ��l��m_scroll�ɉ�����
	//�n�ʔ���ɃX�N���[�����f
	m_gx += hero->GetMoveX();
	}
	}
	}
	}*/

	//�[����������X�e�[�W�[�����Ȃ��悤�ɂ���
	if (m_scroll <= -1600)
	{
		m_scroll = -1600.0f;
	}
	//�[����������X�e�[�W�[�����Ȃ��悤�ɂ���
	if (m_scroll >= 0)
	{
		m_scroll = 0.0f;
	}


	//�ʒu�X�V
	m_p_hit_line_ground[0]->SetPos1(m_scroll + 0, m_gy + 400);
	m_p_hit_line_ground[0]->SetPos2(m_scroll + 500, m_gy + 400);
	m_p_hit_line_ground[1]->SetPos1(m_scroll + 500, m_gy + 350);
	m_p_hit_line_ground[1]->SetPos2(m_scroll + 500, m_gy + 500);
	m_p_hit_line_ground[2]->SetPos1(m_scroll + 500, m_gy + 350);
	m_p_hit_line_ground[2]->SetPos2(m_scroll + 600, m_gy + 350);
	m_p_hit_line_ground[3]->SetPos1(m_scroll + 600, m_gy + 320);
	m_p_hit_line_ground[3]->SetPos2(m_scroll + 600, m_gy + 350);
	m_p_hit_line_ground[4]->SetPos1(m_scroll + 600, m_gy + 320);
	m_p_hit_line_ground[4]->SetPos2(m_scroll + 850, m_gy + 320);
	m_p_hit_line_ground[5]->SetPos1(m_scroll + 850, m_gy + 350);
	m_p_hit_line_ground[5]->SetPos2(m_scroll + 850, m_gy + 280);
	m_p_hit_line_ground[6]->SetPos1(m_scroll + 850, m_gy + 280);
	m_p_hit_line_ground[6]->SetPos2(m_scroll + 1100, m_gy + 280);
	m_p_hit_line_ground[7]->SetPos1(m_scroll + 900, m_gy + 280);
	m_p_hit_line_ground[7]->SetPos2(m_scroll + 900, m_gy + 237);
	m_p_hit_line_ground[8]->SetPos1(m_scroll + 900, m_gy + 237);
	m_p_hit_line_ground[8]->SetPos2(m_scroll + 1307, m_gy + 237);
	m_p_hit_line_ground[9]->SetPos1(m_scroll + 1307, m_gy + 264);
	m_p_hit_line_ground[9]->SetPos2(m_scroll + 1307, m_gy + 237);
	m_p_hit_line_ground[10]->SetPos1(m_scroll + 1207, m_gy + 264);
	m_p_hit_line_ground[10]->SetPos2(m_scroll + 1333, m_gy + 264);
	m_p_hit_line_ground[11]->SetPos1(m_scroll + 1333, m_gy + 291);
	m_p_hit_line_ground[11]->SetPos2(m_scroll + 1333, m_gy + 264);
	m_p_hit_line_ground[12]->SetPos1(m_scroll + 1233, m_gy + 291);
	m_p_hit_line_ground[12]->SetPos2(m_scroll + 1359, m_gy + 291);
	m_p_hit_line_ground[13]->SetPos1(m_scroll + 1359, m_gy + 318);
	m_p_hit_line_ground[13]->SetPos2(m_scroll + 1359, m_gy + 291);
	m_p_hit_line_ground[14]->SetPos1(m_scroll + 1259, m_gy + 318);
	m_p_hit_line_ground[14]->SetPos2(m_scroll + 1385, m_gy + 318);
	m_p_hit_line_ground[15]->SetPos1(m_scroll + 1385, m_gy + 318);
	m_p_hit_line_ground[15]->SetPos2(m_scroll + 1385, m_gy + 346);
	m_p_hit_line_ground[16]->SetPos1(m_scroll + 1285, m_gy + 346);
	m_p_hit_line_ground[16]->SetPos2(m_scroll + 1411, m_gy + 346);
	m_p_hit_line_ground[17]->SetPos1(m_scroll + 1411, m_gy + 346);
	m_p_hit_line_ground[17]->SetPos2(m_scroll + 1411, m_gy + 373);
	m_p_hit_line_ground[18]->SetPos1(m_scroll + 1311, m_gy + 373);
	m_p_hit_line_ground[18]->SetPos2(m_scroll + 1437, m_gy + 373);
	m_p_hit_line_ground[19]->SetPos1(m_scroll + 1437, m_gy + 373);
	m_p_hit_line_ground[19]->SetPos2(m_scroll + 1437, m_gy + 400);
	m_p_hit_line_ground[20]->SetPos1(m_scroll + 1337, m_gy + 400);
	m_p_hit_line_ground[20]->SetPos2(m_scroll + 1900, m_gy + 400);


}

void CObjGround::Draw()
{


	Draw::Draw2D(22, m_scroll, 0);
}