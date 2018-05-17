#pragma once
//�K�v�ȃw�b�_�[
#include <Windows.h>
#include <memory>
#include <list>
#include <math.h>

#include "TaskSystem.h"
using namespace std;

enum HitDirec {
	HIT_LEFT,
	HIT_RIGHT,
	HIT_TOP,
	HIT_UNDER,
};

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
		m_angle = -999.0f;
		m_4direc = 999;
		m_obj = nullptr;
		m_element = -1;
		for (int i = 0; i < 10; i++)
			m_hit[i] = nullptr;
	}

	void SetDelete(bool d) { ls_delete = d; }	//�폜�t���O�Z�b�g
	void SetPos1(float x, float y) { p1.x = x; p1.y = y; }				//�ʒu�Z�b�g
	void SetPos2(float x, float y) { p2.x = x; p2.y = y; }
	Point GetPoint1() { return p1; }									//�_1�Q�b�g
	Point GetPoint2() { return p2; }									//�_2�Q�b�g
	void SetPoint1(Point p) { p1 = p; }									//�_1�Z�b�g
	void SetPoint2(Point p) { p2 = p; }									//�_2�Z�b�g
	void SetAngle() { m_angle = atan2(p2.x - p1.x, p2.y - p1.y)*180.0f/3.14f; }		//�p�x�Z�b�g
	float GetAngle() { return m_angle; }								//�p�x�Q�b�g
	void Set4direc(unsigned int d) { m_4direc = d; }					//�I�u�W�F�N�g�ɑ΂�������Z�b�g
	unsigned int Get4direc() { return m_4direc; }						//�I�u�W�F�N�g�ɑ΂�������Q�b�g
	void SetElement(int element) { m_element = element; }				//�����Z�b�g
	void SetInvisible(bool invisible) { m_ls_invisible = invisible; }	//���G�Z�b�g
	HitLine** GetHitData() { return m_hit; }	//������������̃q�b�g�{�b�N�X���擾
 	int GetElement() { return m_element; }  //�����擾�p
	CObj* GetObj() { return m_obj; }

private:
	//�폜�t���O
	bool ls_delete;
	//�ʒu
	Point p1;
	Point p2;
	//�p�x
	float m_angle;
	//�I�u�W�F�N�g�ɑ΂��铖���蔻��̈ʒu
	unsigned int m_4direc;
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
	static void ClearHitLine() { m_hit_line_list->clear(); }

	static HitLine* HitLineInsert(CObj* p);	//�����蔻����쐬�����X�g�ɓo�^
	static void CheckStart();				//list���̓����蔻��S�`�F�b�N�J�n
	static void DrawDebug();				//�f�o�b�O�p�̓����蔻��`��p

	static float Dot(float ax, float ay, float bx, float by);  //����
	static float Cross(float ax, float ay, float bx, float by);  //�O��
	static bool LineCrossPoint(
		float a1x, float a1y, float a2x, float a2y,
		float b1x, float b1y, float b2x, float b2y,
		float* out_px, float* out_py
	);  //���Ɛ��̌�������

private:
	//�X�ւ̓����蔻��
	static bool HitAB(float ax, float ay, float aw, float ah, float bx, float by, float bw, float bh);
	static bool IsLinecross(Point p1, Point p2, Point p3, Point p4);

	//���X�g�@HitBox�����I�u�W�F�N�g�̗v�f������
	static list<shared_ptr<HitLine>>* m_hit_line_list;

}Collision;