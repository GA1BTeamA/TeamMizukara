//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjMoveBlock.h"
#include "ObjGround.h"

//コンストラクタ
ObjMoveBlock::ObjMoveBlock()
	:m_x(1794), m_y(234)
	, m_gx(1800), m_gy(0)
{

}

//デストラクタ
ObjMoveBlock::~ObjMoveBlock()
{

}

//アクション
void ObjMoveBlock::Action()
{

}

//ドロー
void ObjMoveBlock::Draw()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	Draw::Draw2D(61, m_gx + ground->GetScroll(), m_gy);
}
