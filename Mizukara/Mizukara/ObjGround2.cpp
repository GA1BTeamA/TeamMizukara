//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjGround2.h"
#include "ObjGround.h"

//�R���X�g���N�^
ObjGround2::ObjGround2()
{

}

//�f�X�g���N�^
ObjGround2::~ObjGround2()
{
	
}

//�A�N�V����
void ObjGround2::Action()
{

}

//�h���[
void ObjGround2::Draw()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	//�X�e�[�W2�n�ʕ`��
	Draw::Draw2D(69,0, 0);
}
