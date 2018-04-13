//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Collision.h"
#include "Draw2DPolygon.h"

list<shared_ptr<HitLine>>* CCollision::m_hit_line_list;//���X�g�@HitLine�p

//�f�o�b�O�p�̓����蔻��`��
void CCollision::DrawDebug()
{
	float c[4] = { 1.0f,0.0f,0.0f,0.3f };
	//list��HitLine��`��
	for (auto ip = m_hit_line_list->begin(); ip != m_hit_line_list->end(); ip++)
	{
		//CDraw2DPolygon::Draw2DHitBox((*ip)->p1.x, (*ip)->p1.y, (*ip)->p2.x, (*ip)->p2.y, c);
	}
}

//�����蔻����쐬�����X�g�ɓo�^
HitLine* CCollision::HitLineInsert(CObj* p)
{
	//�q�b�g���C���쐬
	shared_ptr<HitLine>sp(new HitLine());

	//�q�b�g���C���ɏ�������(�t�����h�Ȃ̂Œ��ڃA�N�Z�X�ł���)
	sp->m_obj = p;		//���̓����蔻������I�u�W�F�N�g�̃A�h���X(�I�u�W�F�N�g�A�h���X�͈���p������������Ă���)
	sp->p1.x = -999.0f;	//�����蔻���p1.x�ʒu
	sp->p1.y = -999.0f;	//�����蔻���p1.y�ʒu
	sp->p2.x = -999.0f;	//�����蔻���p2.x�ʒu
	sp->p2.y = -999.0f;	//�����蔻���p2.y�ʒu
	sp->m_ls_invisible = false;//�����蔻��̖��G���[�hOFF
	sp->m_element = 0;	//�����蔻��̑���

	//���X�g�ɓo�^
	m_hit_line_list->push_back(sp);

	//sp�̃t���b�V���|�C���^��Ԃ�
	return sp.get();
}

//������
void CCollision::InitHitLine()
{
	m_hit_line_list = new list<shared_ptr<HitLine>>;
	m_hit_line_list->clear();
}

//�j��
void CCollision::DeleteHitLine()
{
	m_hit_line_list->clear();
	delete m_hit_line_list;
}

//list���̓����蔻��S�`�F�b�N�J�n
void CCollision::CheckStart()
{
	//���X�g����ls_delete��true�̗v�f���폜
	auto i = m_hit_line_list->begin();
	while (i != m_hit_line_list->end())
	{
		if (i->get()->ls_delete == true)
		{
			//�C�e���[�^i�̗v�f���폜
			i = m_hit_line_list->erase(i);
		}
		else
		{
			i++;
		}
	}

	//�����Ƃ̏Փˏ�񐧌�p
	int hit_count = 0;

	//���X�g���̃q�b�g�{�b�N�X�œ����蔻������{
	for (auto ip_1= m_hit_line_list->begin(); ip_1 != m_hit_line_list->end(); ip_1++)		//A�q�b�g�{�b�N�X
	{
		//�Փˉ񐔂̏�����
		hit_count = 0;
		//A�̏��̏Փˏ��̏�����
		for (int i = 0; i < 10; i++)
		{
			(*ip_1)->m_hit[i] = nullptr;
		}

		//A��Hitbox�̓����蔻�薳���`�F�b�N
		//���G
		if ((*ip_1)->m_ls_invisible)
			continue;

		for (auto ip_2 = m_hit_line_list->begin(); ip_2 != m_hit_line_list->end(); ip_2++)	//B�q�b�g�{�b�N�X
		{
			//B��Hitbox�̓����蔻�薳���`�F�b�N
			//A��B�������q�b�g�{�b�N�X
			if (ip_1 == ip_2)
				continue;

			//���G
			if ((*ip_2)->m_ls_invisible)
				continue;

			//A��B�̃q�b�g�{�b�N�X�����Ȃ��I�u�W�F�N�g
			if ((*ip_1)->m_obj == (*ip_2)->m_obj)
				continue;

			//A��B�̃q�b�g�{�b�N�X��������
			if ((*ip_1)->m_element == (*ip_2)->m_element)
				continue;

			//�����蔻������{
			bool ls_hit = IsLinecross((*ip_1)->p1, (*ip_1)->p2,(*ip_2)->p1, (*ip_2)->p2);
			//�Փ˂��Ă���ꍇ
			if (ls_hit == true)
			{
				//a�̃q�b�g�{�b�N�X�ɓ������Ă���b�̃A�h���X�^����
				int buffer_count = hit_count % 10;				//m_hit[]���L���[�o�b�t�@�Ƃ��Ĉ���
				(*ip_1)->m_hit[buffer_count] = ip_2->get();		//b�̃A�h���X(�t���b�V���|�C���^)��n��
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
bool CCollision::IsLinecross(Point p1, Point p2, Point p3, Point p4)
{
//���t�`�F�b�N
	//X���W�ɂ��`�F�b�N
	if (p1.x >= p2.x)
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
	return true;
}
