//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjGround2.h"
#include "ObjGround.h"

//コンストラクタ
ObjGround2::ObjGround2()
{

}

//デストラクタ
ObjGround2::~ObjGround2()
{
	
}

//アクション
void ObjGround2::Action()
{

}

//ドロー
void ObjGround2::Draw()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	//ステージ2地面描画
	Draw::Draw2D(69,0, 0);
}
