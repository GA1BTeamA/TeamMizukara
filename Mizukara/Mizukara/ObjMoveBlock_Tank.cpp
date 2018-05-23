//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjMoveBlock_Tank.h"
#include "ObjGround.h"
extern int g_SceneNumber;

const float ObjMoveBlock_Tank::m_WaveSize_x = 0.5f;
const float ObjMoveBlock_Tank::m_WaveSize_y = 0.6f;

//�R���X�g���N�^
ObjMoveBlock_Tank::ObjMoveBlock_Tank()
	:m_x(1300), m_y(550),m_gx(1620),m_gy(330)
{
	//�q�b�g���C���̍쐬(��)
	m_hit_line_MoBlTank = Collision::HitLineInsert(this);
	m_hit_line_MoBlTank->SetPos1(m_x, m_y);
	m_hit_line_MoBlTank->SetPos2(m_x, m_y + 100);
	m_hit_line_MoBlTank->SetElement(2);		//������2�ɂ���
	m_hit_line_MoBlTank->SetInvisible(false);	//���G���[�h����
}

//�f�X�g���N�^
ObjMoveBlock_Tank::~ObjMoveBlock_Tank()
{

}

//�A�N�V����
void ObjMoveBlock_Tank::Action()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);
}

//�h���[
void ObjMoveBlock_Tank::Draw()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	Draw::Draw2D(60, m_gx + ground->GetScroll(), m_gy, 1, 1);
}
