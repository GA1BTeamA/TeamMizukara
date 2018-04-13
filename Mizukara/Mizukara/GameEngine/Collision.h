#pragma once
//�K�v�ȃw�b�_�[
#include <Windows.h>
#include <memory>
#include <list>

#include "TaskSystem.h"
using namespace std;

//���W
class Point
{
public:
	double x;
	double y;
};

//�Փ˃I�u�W�F�N�g�N���X
class HitLine
{
	//CCollision�̂݃v���C�x�[�g�����J����
	friend class CCollision;
public:
	HitLine() { Init(); }
	~HitLine() {}
	//������
	void Init()
	{
		ls_delete = false;
		p1.x = p1.y = p2.x = p2.y = -999.0f;
		//m_w = m_h = 0.0f;
		m_obj = nullptr;
		m_element = -1;
		for (int i = 0; i < 10; i++)
			m_hit[i] = nullptr;
	}

	void SetDelete(bool d) { ls_delete = d; }	//�폜�t���O�Z�b�g
	void SetPos1(float x, float y) { p1.x = x; p1.y = y; }					//�ʒu�Z�b�g
	void SetPos2(float x, float y) { p2.x = x; p2.y = y; }
	//void SetWH(float w, float h) { m_w = w; m_h = h; }					//�@���Z�b�g
	void SetElement(int element) { m_element = element; }				//�����Z�b�g
	void SetInvisible(bool invisible) { m_ls_invisible = invisible; }	//���G�Z�b�g
	HitLine** GetHitData() { return m_hit; }	//������������̃q�b�g�{�b�N�X���擾


private:
	//�폜�t���O
	bool ls_delete;
	//�ʒu
	Point p1;
	Point p2;
	////��
	//float m_w;
	//float m_h;
	//���̏Փ˃I�u�W�F�N�g�����I�u�W�F�N�g�̃|�C���^
	CObj* m_obj;
	//����(�����l���m�ł͓����蔻����s��Ȃ�)
	int m_element;
	//���G(true�ł͓����蔻����s��Ȃ�)
	bool m_ls_invisible;
	//�������������HitLine���
	//������10�I�u�W�F�N�g�܂ŏ������
	HitLine* m_hit[10];
};

//�Փ˔���N���X
typedef class CCollision
{
public:
	CCollision() {}
	~CCollision() {}

	static void InitHitLine();	//������
	static void DeleteHitLine();	//�j��

	static HitLine* HitLineInsert(CObj* p);	//�����蔻����쐬�����X�g�ɓo�^
	static void CheckStart();				//list���̓����蔻��S�`�F�b�N�J�n
	static void DrawDebug();				//�f�o�b�O�p�̓����蔻��`��p

private:
	//�X�ւ̓����蔻��
	static bool HitAB(float ax, float ay, float aw, float ah, float bx, float by, float bw, float bh);
	static bool IsLinecross(Point p1, Point p2, Point p3, Point p4);

	//���X�g�@HitBox�����I�u�W�F�N�g�̗v�f������
	static list<shared_ptr<HitLine>>* m_hit_line_list;

}Collision;