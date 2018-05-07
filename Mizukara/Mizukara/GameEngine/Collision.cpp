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

//���ϊ֐�
//����1,2 float  ax , ay :A�x�N�g��
//����3,4 float  bx , by :B�x�N�g��
//�߂�l�@float :�ˉe
//���e�@A�x�N�g����B�x�N�g���œ��ς��s���ˉe�����߂�
float CCollision::Dot(float ax, float ay, float bx, float by)
{
	float t = 0.0f;

	t = ax * bx + ay * by;

	return t;
}

//�O�ϊ֐�
//����1,2 float  ax , ay :A�x�N�g��
//����3,4 float  bx , by :B�x�N�g��
//�߂�l�@float :�ˉe
//���e�@A�x�N�g����B�x�N�g���ŊO�ς��s���ˉe�����߂�
float CCollision::Cross(float ax, float ay, float bx, float by)
{
	float t = 0.0f;

	t = ax * by - ay * bx;

	return t;
}

#define SGN(x) 1-(x<=0)-(x<0)

//���Ɛ��̌�������֐�
//���� float 1,2   a1x , a1y      :���x�N�g��A�̎n�_
//���� float 3,4   a2x , a2y      :���x�N�g��A�̏I�_
//���� float 5,6   b1x , b1y      :�x�N�g��B�̎n�_
//���� float 7,8   b2x , b2y      :�x�N�g��B�̏I�_
//���� float 9,10  out_px,out_py  :��������x�N�g���̌�_�ʒu
//�߂�l bool   :true=��_�L��@false=��_����
//���e:������A�EB�x�N�g���̌�_�������Aout_px��out_py�ɕԂ�
bool CCollision::LineCrossPoint(
	float a1x, float a1y, float a2x, float a2y,
	float b1x, float b1y, float b2x, float b2y,
	float* out_px, float* out_py
)
{
	//�G���[�R�[�h
	*out_px = -9999.0f;  *out_py = -9999.0f;

	//A�x�N�g���쐬(a2��a1)
	float ax = a2x - a1x;  float ay = a2y - a1y;

	//B�x�N�g���쐬(b2��b1)
	float bx = b2x - b1x;  float by = b2y - b1y;

	//C�x�N�g���쐬(b1��a1)
	float cx = b1x - a1x;  float cy = b1y - a1y;

	//D�x�N�g���쐬(b2��a1)
	float dx = b2x - a1x;  float dy = b2y - a1y;

	//A�~C�̎ˉe��A�~B�̎ˉe�����߂�
	float t1 = Cross(ax, ay, cx, cy);
	float t2 = Cross(ax, ay, dx, dy);

	//���������������ɂȂ��Ă��邩�ǂ������`�F�b�N
	if (SGN(t1) == SGN(t2))
 		return false;  //��_����

	//�ˉe���Βl��
	t1 = abs(t1);  t2 = abs(t2);

	//��_�����߂�
	float px = bx*(t1 / (t1 + t2)) + b1x;
	float py = by*(t1 / (t1 + t2)) + b1y;

	//AP�x�N�g��(p��a1)
	float apx = px - a1x;  float apy = py - a1y;

	//BP�x�N�g��(p��a2)
	float bpx = px - a2x;  float bpy = py - a2y;

	//A�EAP�̎ˉe��A�EBP�̎ˉe�����߂�
	float w1 = Dot(ax, ay, apx, apy);
	float w2 = Dot(ax, ay, bpx, bpy);

	//�����`�F�b�N
	if (SGN(w1) == SGN(w2))
		return false;  //��_���O

	//��_��Ԃ�
	*out_px = px; *out_py = py;

	return true;
}