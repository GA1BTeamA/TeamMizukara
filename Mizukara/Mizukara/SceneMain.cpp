//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "SceneMain.h"
#include "Hero.h"
#include "Tank.h"
#include "Background.h"
#include "BucketMeter.h"
#include "ObjGround.h"


SceneMain::SceneMain()
{
	CHero* hero = new CHero();
	hero->m_priority = 90;
	TaskSystem::InsertObj(hero);

	CTank* tank = new CTank();
	tank->m_priority = 80;
	TaskSystem::InsertObj(tank);

	CBackground* background = new CBackground();
	background->m_priority = 10;
	TaskSystem::InsertObj(background);

	CBucketMeter* bucketmeter = new CBucketMeter();
	bucketmeter->m_priority = 20;
	TaskSystem::InsertObj(bucketmeter);

	CObjGround* ground = new CObjGround();
	ground->m_priority = 10;
	TaskSystem::InsertObj(ground);
}


SceneMain::~SceneMain()
{
}

void SceneMain::Action() 
{

}

void SceneMain::Draw()
{

}
//