//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "SceneMain.h"
#include "Hero.h"


SceneMain::SceneMain()
{
	CHero* hero = new CHero();
	hero->m_priority = 90;
	TaskSystem::InsertObj(hero);

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