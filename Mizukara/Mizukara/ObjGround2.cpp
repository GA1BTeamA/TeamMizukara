//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjGround2.h"
#include "ObjGround.h"

//�R���X�g���N�^
ObjGround2::ObjGround2()
	:m_gx(0), m_gy(0), m_scroll(0.0f)
{
	m_name = GROUND2;

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[0] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[0]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[1] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[1]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[2] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[2]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[3] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[3]->Set4direc(HIT_LEFT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[4] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[4]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[5] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[5]->Set4direc(HIT_LEFT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[6] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[6]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[7] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[7]->Set4direc(HIT_LEFT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[8] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[8]->Set4direc(HIT_RIGHT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[9] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[9]->Set4direc(HIT_LEFT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[10] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[10]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[11] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[11]->Set4direc(HIT_RIGHT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[12] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[12]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[13] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[13]->Set4direc(HIT_RIGHT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[14] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[14]->Set4direc(HIT_LEFT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[15] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[15]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[16] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[16]->Set4direc(HIT_RIGHT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[17] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[17]->Set4direc(HIT_LEFT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[18] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[18]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[19] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[19]->Set4direc(HIT_RIGHT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[20] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[20]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[21] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[21]->Set4direc(HIT_RIGHT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[22] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[22]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[23] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[23]->Set4direc(HIT_RIGHT);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[24] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[24]->Set4direc(HIT_TOP);

	//�q�b�g�{�b�N�X�쐬���A�쐬�����q�b�g�{�b�N�X�̒l��ݒ�
	m_p_hit_line_ground2[25] = Collision::HitLineInsert(this);
	m_p_hit_line_ground2[25]->Set4direc(HIT_RIGHT);

	m_p_hit_line_ground2[0]->SetPos1(m_scroll + 0, m_gy + 400);  //�ŏ�
	m_p_hit_line_ground2[0]->SetPos2(m_scroll + /*274*/494, m_gy + 400);
	m_p_hit_line_ground2[1]->SetPos1(m_scroll + 550, m_gy + 400);  //0�i��
	m_p_hit_line_ground2[1]->SetPos2(m_scroll + 3250, m_gy + 400);
	m_p_hit_line_ground2[2]->SetPos1(m_scroll + 602, m_gy + 374);  //1�i��
	m_p_hit_line_ground2[2]->SetPos2(m_scroll + 680, m_gy + 374);
	m_p_hit_line_ground2[3]->SetPos1(m_scroll + 602, m_gy + 400);  //0��1��
	m_p_hit_line_ground2[3]->SetPos2(m_scroll + 602, m_gy + 374);
	m_p_hit_line_ground2[4]->SetPos1(m_scroll + 627, m_gy + 348);  //2�i��
	m_p_hit_line_ground2[4]->SetPos2(m_scroll + 680, m_gy + 348);
	m_p_hit_line_ground2[5]->SetPos1(m_scroll + 627, m_gy + 400);  //1��2�̊�
	m_p_hit_line_ground2[5]->SetPos2(m_scroll + 627, m_gy + 348);
	m_p_hit_line_ground2[6]->SetPos1(m_scroll + 652, m_gy + 322);  //3�i��
	m_p_hit_line_ground2[6]->SetPos2(m_scroll + 705, m_gy + 322);
	m_p_hit_line_ground2[7]->SetPos1(m_scroll + 652, m_gy + 400);  //2��3�̊�
	m_p_hit_line_ground2[7]->SetPos2(m_scroll + 652, m_gy + 322);
	m_p_hit_line_ground2[8]->SetPos1(m_scroll + 705, m_gy + 450);  //3�i�ڔ��Α��̕�
	m_p_hit_line_ground2[8]->SetPos2(m_scroll + 705, m_gy + 322);
	m_p_hit_line_ground2[9]->SetPos1(m_scroll + 888, m_gy + 450);  //1�ڃM�~�b�N�������Ƃ���
	m_p_hit_line_ground2[9]->SetPos2(m_scroll + 888, m_gy + 248);
	m_p_hit_line_ground2[10]->SetPos1(m_scroll + 888, m_gy + 248);  //1�ڃM�~�b�N�������Ƃ��n��
	m_p_hit_line_ground2[10]->SetPos2(m_scroll + 990, m_gy + 248);
	m_p_hit_line_ground2[11]->SetPos1(m_scroll + 990, m_gy + 450);  //���̒n�ʂ̒i��
	m_p_hit_line_ground2[11]->SetPos2(m_scroll + 990, m_gy + 248);
	m_p_hit_line_ground2[12]->SetPos1(m_scroll + 900, m_gy + 292);  //�i�����̒n��
	m_p_hit_line_ground2[12]->SetPos2(m_scroll + 1060, m_gy + 292);
	m_p_hit_line_ground2[13]->SetPos1(m_scroll + 1060, m_gy + 450);  //�i�����n�ʂ̕�
	m_p_hit_line_ground2[13]->SetPos2(m_scroll + 1060, m_gy + 292);
	m_p_hit_line_ground2[14]->SetPos1(m_scroll + 1235, m_gy + 450);  //���̍����n�ʂ̕�
	m_p_hit_line_ground2[14]->SetPos2(m_scroll + 1235, m_gy + 191);
	m_p_hit_line_ground2[15]->SetPos1(m_scroll + 1235, m_gy + 191);  //�����n��
	m_p_hit_line_ground2[15]->SetPos2(m_scroll + 1332, m_gy + 191);
	m_p_hit_line_ground2[16]->SetPos1(m_scroll + 1332, m_gy + 450);  //�����n�ʔ��Α��̕�
	m_p_hit_line_ground2[16]->SetPos2(m_scroll + 1332, m_gy + 191);
	m_p_hit_line_ground2[17]->SetPos1(m_scroll + 1846, m_gy + 450);  //���A�Ō�A���������O�̕�
	m_p_hit_line_ground2[17]->SetPos2(m_scroll + 1846, m_gy + 149);
	m_p_hit_line_ground2[18]->SetPos1(m_scroll + 1846, m_gy + 149);  //��������K�i1��
	m_p_hit_line_ground2[18]->SetPos2(m_scroll + 2045, m_gy + 149);
	m_p_hit_line_ground2[19]->SetPos1(m_scroll + 2045, m_gy + 249);  //��������K�i1�E
	m_p_hit_line_ground2[19]->SetPos2(m_scroll + 2045, m_gy + 149);
	m_p_hit_line_ground2[20]->SetPos1(m_scroll + 1945, m_gy + 176);  //��������K�i2��
	m_p_hit_line_ground2[20]->SetPos2(m_scroll + 2071, m_gy + 176);
	m_p_hit_line_ground2[21]->SetPos1(m_scroll + 2071, m_gy + 253);  //��������K�i2�E
	m_p_hit_line_ground2[21]->SetPos2(m_scroll + 2071, m_gy + 176);
	m_p_hit_line_ground2[22]->SetPos1(m_scroll + 2000, m_gy + 203);  //��������K�i3��
	m_p_hit_line_ground2[22]->SetPos2(m_scroll + 2097, m_gy + 203);
	m_p_hit_line_ground2[23]->SetPos1(m_scroll + 2097, m_gy + 280);  //��������K�i3�E
	m_p_hit_line_ground2[23]->SetPos2(m_scroll + 2097, m_gy + 203);
	m_p_hit_line_ground2[24]->SetPos1(m_scroll + 2000, m_gy + 230);  //��������K�i�I���̒n��
	m_p_hit_line_ground2[24]->SetPos2(m_scroll + 2250, m_gy + 230);
	m_p_hit_line_ground2[25]->SetPos1(m_scroll + 90, m_gy + 450);  //�^���N�����蔻��
	m_p_hit_line_ground2[25]->SetPos2(m_scroll + 90, m_gy);

	for (int i = 0; i < 26; i++) {
		m_p_hit_line_ground2[i]->SetElement(1);		//������1�ɂ���
		m_p_hit_line_ground2[i]->SetInvisible(false);	//���G���[�h����
		m_p_hit_line_ground2[i]->SetAngle();
	}
}

//�f�X�g���N�^
ObjGround2::~ObjGround2()
{
	
}

//�A�N�V����
void ObjGround2::Action()
{
	//�[����������X�e�[�W�[�����Ȃ��悤�ɂ���
	if (m_scroll <= -2400)
	{
		m_scroll = -2400.0f;
	}
	//�[����������X�e�[�W�[�����Ȃ��悤�ɂ���
	if (m_scroll >= 0)
	{
		m_scroll = 0.0f;
	}

	//�ʒu�X�V
	m_p_hit_line_ground2[0]->SetPos1(m_scroll + 0, m_gy + 400);  //�ŏ�
	m_p_hit_line_ground2[0]->SetPos2(m_scroll + /*274*/494, m_gy + 400);
	m_p_hit_line_ground2[1]->SetPos1(m_scroll + 550, m_gy + 400);  //0�i��
	m_p_hit_line_ground2[1]->SetPos2(m_scroll + 3250, m_gy + 400);
	m_p_hit_line_ground2[2]->SetPos1(m_scroll + 602, m_gy + 374);  //1�i��
	m_p_hit_line_ground2[2]->SetPos2(m_scroll + 680, m_gy + 374);
	m_p_hit_line_ground2[3]->SetPos1(m_scroll + 602, m_gy + 400);  //0��1��
	m_p_hit_line_ground2[3]->SetPos2(m_scroll + 602, m_gy + 374);
	m_p_hit_line_ground2[4]->SetPos1(m_scroll + 627, m_gy + 348);  //2�i��
	m_p_hit_line_ground2[4]->SetPos2(m_scroll + 680, m_gy + 348);
	m_p_hit_line_ground2[5]->SetPos1(m_scroll + 627, m_gy + 400);  //1��2�̊�
	m_p_hit_line_ground2[5]->SetPos2(m_scroll + 627, m_gy + 348);
	m_p_hit_line_ground2[6]->SetPos1(m_scroll + 652, m_gy + 322);  //3�i��
	m_p_hit_line_ground2[6]->SetPos2(m_scroll + 705, m_gy + 322);
	m_p_hit_line_ground2[7]->SetPos1(m_scroll + 652, m_gy + 400);  //2��3�̊�
	m_p_hit_line_ground2[7]->SetPos2(m_scroll + 652, m_gy + 322);
	m_p_hit_line_ground2[8]->SetPos1(m_scroll + 705, m_gy + 450);  //3�i�ڔ��Α��̕�
	m_p_hit_line_ground2[8]->SetPos2(m_scroll + 705, m_gy + 322);
	m_p_hit_line_ground2[9]->SetPos1(m_scroll + 888, m_gy + 450);  //1�ڃM�~�b�N�������Ƃ���
	m_p_hit_line_ground2[9]->SetPos2(m_scroll + 888, m_gy + 248);
	m_p_hit_line_ground2[10]->SetPos1(m_scroll + 888, m_gy + 248);  //1�ڃM�~�b�N�������Ƃ��n��
	m_p_hit_line_ground2[10]->SetPos2(m_scroll + 990, m_gy + 248);
	m_p_hit_line_ground2[11]->SetPos1(m_scroll + 990, m_gy + 450);  //���̒n�ʂ̒i��
	m_p_hit_line_ground2[11]->SetPos2(m_scroll + 990, m_gy + 248);
	m_p_hit_line_ground2[12]->SetPos1(m_scroll + 900, m_gy + 292);  //�i�����̒n��
	m_p_hit_line_ground2[12]->SetPos2(m_scroll + 1060, m_gy + 292);
	m_p_hit_line_ground2[13]->SetPos1(m_scroll + 1060, m_gy + 450);  //�i�����n�ʂ̕�
	m_p_hit_line_ground2[13]->SetPos2(m_scroll + 1060, m_gy + 292);
	m_p_hit_line_ground2[14]->SetPos1(m_scroll + 1235, m_gy + 450);  //���̍����n�ʂ̕�
	m_p_hit_line_ground2[14]->SetPos2(m_scroll + 1235, m_gy + 191);
	m_p_hit_line_ground2[15]->SetPos1(m_scroll + 1235, m_gy + 191);  //�����n��
	m_p_hit_line_ground2[15]->SetPos2(m_scroll + 1332, m_gy + 191);
	m_p_hit_line_ground2[16]->SetPos1(m_scroll + 1332, m_gy + 450);  //�����n�ʔ��Α��̕�
	m_p_hit_line_ground2[16]->SetPos2(m_scroll + 1332, m_gy + 191);
	m_p_hit_line_ground2[17]->SetPos1(m_scroll + 1846, m_gy + 450);  //���A�Ō�A���������O�̕�
	m_p_hit_line_ground2[17]->SetPos2(m_scroll + 1846, m_gy + 149);
	m_p_hit_line_ground2[18]->SetPos1(m_scroll + 1846, m_gy + 149);  //��������K�i1��
	m_p_hit_line_ground2[18]->SetPos2(m_scroll + 2045, m_gy + 149);
	m_p_hit_line_ground2[19]->SetPos1(m_scroll + 2045, m_gy + 249);  //��������K�i1�E
	m_p_hit_line_ground2[19]->SetPos2(m_scroll + 2045, m_gy + 149);
	m_p_hit_line_ground2[20]->SetPos1(m_scroll + 1945, m_gy + 176);  //��������K�i2��
	m_p_hit_line_ground2[20]->SetPos2(m_scroll + 2071, m_gy + 176);
	m_p_hit_line_ground2[21]->SetPos1(m_scroll + 2071, m_gy + 253);  //��������K�i2�E
	m_p_hit_line_ground2[21]->SetPos2(m_scroll + 2071, m_gy + 176);
	m_p_hit_line_ground2[22]->SetPos1(m_scroll + 2000, m_gy + 203);  //��������K�i3��
	m_p_hit_line_ground2[22]->SetPos2(m_scroll + 2097, m_gy + 203);
	m_p_hit_line_ground2[23]->SetPos1(m_scroll + 2097, m_gy + 280);  //��������K�i3�E
	m_p_hit_line_ground2[23]->SetPos2(m_scroll + 2097, m_gy + 203);
	m_p_hit_line_ground2[24]->SetPos1(m_scroll + 2000, m_gy + 230);  //��������K�i�I���̒n��
	m_p_hit_line_ground2[24]->SetPos2(m_scroll + 2250, m_gy + 230);
	m_p_hit_line_ground2[25]->SetPos1(m_scroll + 90, m_gy + 450);  //�^���N�����蔻��
	m_p_hit_line_ground2[25]->SetPos2(m_scroll + 90, m_gy);

}

//�h���[
void ObjGround2::Draw()
{
	//�X�e�[�W2�n�ʕ`��
	Draw::Draw2D(69, m_scroll, 0);


	//Draw::Draw2D(58, m_scroll+2045, 149);
}
