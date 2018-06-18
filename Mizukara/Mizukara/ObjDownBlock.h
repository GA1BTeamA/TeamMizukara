#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�M�~�b�N2(������u���b�N)�N���X
class ObjDownBlock :public CObj
{
public:
	ObjDownBlock(float x,float y);
	~ObjDownBlock();

	void Action();
	void Draw();

	void AddY(float y) { m_gy += y; }  //�����Y���������
	void SetRopeSizeScaffold(float rss) { m_RopeSizeScaffold += rss; }
	void SetY(float y) { m_y += y; }  //����u���b�N�̓����蔻�蓮�������

private:
	float m_x;//�ʒu
	float m_y;

	float m_gx;//�O���t�B�b�N�̈ʒu
	float m_gy;

	float m_rope_y;//���[�v�̈ʒu
	float m_RopeSizeScaffold;

	HitLine* m_hit_line_DwBl[4];//�����蔻��
};