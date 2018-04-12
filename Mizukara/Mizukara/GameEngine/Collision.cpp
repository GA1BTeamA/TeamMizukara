//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Collision.h"
#include "Draw2DPolygon.h"

list<shared_ptr<HitBox>>* CCollision::m_hit_box_list;//���X�g�@HitBox�p

//�f�o�b�O�p�̓����蔻��`��
void CCollision::DrawDebug()
{
	float c[4] = { 1.0f,0.0f,0.0f,0.3f };
	//list��HitBox��`��
	for (auto ip = m_hit_box_list->begin(); ip != m_hit_box_list->end(); ip++)
	{
		CDraw2DPolygon::Draw2DHitBox((*ip)->m_x, (*ip)->m_y, (*ip)->m_w, (*ip)->m_h, c);
	}
}

//�����蔻����쐬�����X�g�ɓo�^
HitBox* CCollision::HitBoxInsert(CObj* p)
{
	//�q�b�g�{�b�N�X�쐬
	shared_ptr<HitBox>sp(new HitBox());

	//�q�b�g�{�b�N�X�ɏ�������(�t�����h�Ȃ̂Œ��ڃA�N�Z�X�ł���)
	sp->m_obj = p;		//���̓����蔻������I�u�W�F�N�g�̃A�h���X(�I�u�W�F�N�g�A�h���X�͈���p������������Ă���)
	sp->m_x = -999.0f;	//�����蔻���X�ʒu
	sp->m_y = -999.0f;	//�����蔻���Y�ʒu
	sp->m_w = 64.0f;	//�����蔻��̉���
	sp->m_h = 64.0f;	//�����蔻��̏c��
	sp->m_ls_invisible = false;//�����蔻��̖��G���[�hOFF
	sp->m_element = 0;	//�����蔻��̑���

	//���X�g�ɓo�^
	m_hit_box_list->push_back(sp);

	//sp�̃t���b�V���|�C���^��Ԃ�
	return sp.get();
}

//������
void CCollision::InitHitBox()
{
	m_hit_box_list = new list<shared_ptr<HitBox>>;
	m_hit_box_list->clear();
}

//�j��
void CCollision::DeleteHitBox()
{
	m_hit_box_list->clear();
	delete m_hit_box_list;
}

//list���̓����蔻��S�`�F�b�N�J�n
void CCollision::CheckStart()
{
	//���X�g����ls_delete��true�̗v�f���폜
	auto i = m_hit_box_list->begin();
	while (i != m_hit_box_list->end())
	{
		if (i->get()->ls_delete == true)
		{
			//�C�e���[�^i�̗v�f���폜
			i = m_hit_box_list->erase(i);
		}
		else
		{
			i++;
		}
	}

	//�����Ƃ̏Փˏ�񐧌�p
	int hit_count = 0;

	//���X�g���̃q�b�g�{�b�N�X�œ����蔻������{
	for (auto ip_a=m_hit_box_list->begin();ip_a!=m_hit_box_list->end();ip_a++)		//A�q�b�g�{�b�N�X
	{
		//�Փˉ񐔂̏�����
		hit_count = 0;
		//A�̏��̏Փˏ��̏�����
		for (int i = 0; i < 10; i++)
		{
			(*ip_a)->m_hit[i] = nullptr;
		}

		//A��Hitbox�̓����蔻�薳���`�F�b�N
		//���G
		if ((*ip_a)->m_ls_invisible)
			continue;

		for (auto ip_b=m_hit_box_list->begin();ip_b!=m_hit_box_list->end();ip_b++)	//B�q�b�g�{�b�N�X
		{
			//B��Hitbox�̓����蔻�薳���`�F�b�N
			//A��B�������q�b�g�{�b�N�X
			if (ip_a == ip_b)
				continue;

			//���G
			if ((*ip_b)->m_ls_invisible)
				continue;

			//A��B�̃q�b�g�{�b�N�X��������
			if ((*ip_a)->m_element == (*ip_b)->m_element)
				continue;

			//�����蔻������{
			bool ls_hit = HitAB(
							(*ip_a)->m_x, (*ip_a)->m_y, (*ip_a)->m_w, (*ip_a)->m_h,
							(*ip_b)->m_x, (*ip_b)->m_y, (*ip_b)->m_w, (*ip_b)->m_h
			);
			//�Փ˂��Ă���ꍇ
			if (ls_hit == true)
			{
				//a�̃q�b�g�{�b�N�X�ɓ������Ă���b�̃A�h���X�^����
				int buffer_count = hit_count % 10;				//m_hit[]���L���[�o�b�t�@�Ƃ��Ĉ���
				(*ip_a)->m_hit[buffer_count] = ip_b->get();		//b�̃A�h���X(�t���b�V���|�C���^)��n��
				hit_count++;
			}
		}
	}
}

//�X�ւ̓����蔻��
bool CCollision::HitAB(float ax, float ay, float aw, float ah, float bx, float by, float bw, float bh)
{
	//�����蔻��
	if (ax < bx + bw && ax + aw > bx && ay < by + bh && ay + ah > by)
	{
		//�Փ˂��Ă���
		return true;
	}
	//�Փ˂��Ă��Ȃ�
	return false;
}

//���W p1,p2�@�����Ԑ����ƍ��W p3,p4 �����Ԑ������������Ă��邩�𒲂ׂ�
//�������A�������d�Ȃ��Ă���ꍇ(3�_�A4�_���꒼����ɂ���)�A�u�������Ă���v�A�Ɣ��肷��
bool HitBox::IsLinecross(Point p1, Point p2, Point p3, Point p4)
{
//���t�`�F�b�N
	//X���W�ɂ��`�F�b�N
	if (p1.x <= p2.x)
	{
		if ((p1.x < p3.x && p1.x < p4.x) || (p2.x > p3.x && p2.x > p4.x))
		{
			return false;
		}
		else if ((p2.x < p3.x && p2.x < p4.x) || (p1.x > p3.x && p1.x > p4.x))
		{
			return false;
		}
	}

	//Y���W�ɂ��`�F�b�N
	if (p1.y >= p2.y)
	{
		if ((p1.y < p3.y && p1.y < p4.y) || (p2.y > p3.y&&p2.y > p4.y))
		{
			return false;
		}
		else if ((p2.y < p3.y && p2.y < p4.y) || (p1.y > p3.y && p1.y > p4.y))
		{
			return false;
		}
	}

//���t�`�F�b�N�ł͂�����Ȃ����������`�F�b�N����
	if (((p1.x - p2.x)*(p3.y - p1.y) + (p1.y - p2.y)*(p1.x - p3.x))*
		((p1.x - p2.x)*(p4.y - p1.y) + (p1.y - p2.y)*(p1.x - p4.x)) > 0)
	{
		return false;
	}
	if (((p3.x - p4.x)*(p1.y - p3.y) + (p3.y - p4.y)*(p3.x - p1.x))*
		((p3.x - p4.x)*(p2.y - p3.y) + (p3.y - p4.y)*(p3.x - p2.x)) > 0)
	{
		return false;
	}
}
