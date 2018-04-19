#pragma once
//�g�p����w�b�_
#include "GameEngine\\Draw2DPolygon.h"
#include "GameEngine\\Input.h"
#include "GameEngine\\Audio.h"
#include "GameEngine\\TaskSystem.h"
#include "GameEngine\\Collision.h"

//�X�g�[���[�N���X
class CObjStory : public CObj
{
public:
	CObjStory();
	~CObjStory();
	void Action();
	void Draw();
private:
	float m_x; //�ʒu
	float m_y;
	unsigned int m_time;//�X�g�[���[�`�掞��
};