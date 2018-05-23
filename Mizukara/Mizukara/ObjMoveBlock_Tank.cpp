//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ObjMoveBlock_Tank.h"
#include "ObjGround.h"
extern int g_SceneNumber;

const float ObjMoveBlock_Tank::m_WaveSize_x = 0.5f;
const float ObjMoveBlock_Tank::m_WaveSize_y = 0.6f;

//コンストラクタ
ObjMoveBlock_Tank::ObjMoveBlock_Tank()
	:m_x(1300), m_y(550),m_gx(1620),m_gy(330),m_wave_x(1190),m_wave_y(150),m_water_x(1186),m_water_y(162),
	 m_ani_time1(0.0f),m_ani_time2(0.0f)
{
	//ヒットラインの作成(左)
	m_hit_line_MoBlTank = Collision::HitLineInsert(this);
	m_hit_line_MoBlTank->SetPos1(m_x, m_y);
	m_hit_line_MoBlTank->SetPos2(m_x, m_y + 100);
	m_hit_line_MoBlTank->SetElement(2);		//属性を2にする
	m_hit_line_MoBlTank->SetInvisible(false);	//無敵モード無効
}

//デストラクタ
ObjMoveBlock_Tank::~ObjMoveBlock_Tank()
{

}

//アクション
void ObjMoveBlock_Tank::Action()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	//当たり判定位置の更新
	m_hit_line_MoBlTank->SetPos1(m_x + ground->GetScroll(), m_y);
	m_hit_line_MoBlTank->SetPos2(m_x + ground->GetScroll(), m_y + 100);
}

//ドロー
void ObjMoveBlock_Tank::Draw()
{
	CObjGround* ground = (CObjGround*)TaskSystem::GetObj(GROUND);

	//WTMに近づいたらアイコンを出す
	for (int i = 0; i < 10; i++)
	{
		if (m_hit_line_MoBlTank->GetHitData()[i] != nullptr)
		{
			if (m_hit_line_MoBlTank->GetHitData()[i]->GetElement() == 0)
			{
				Draw::Draw2D(21, m_x + 20 + ground->GetScroll(), m_y + 15);
			}
		}
	}

	Draw::Draw2D(60, m_gx + ground->GetScroll(), m_gy, 1, 1);
}
