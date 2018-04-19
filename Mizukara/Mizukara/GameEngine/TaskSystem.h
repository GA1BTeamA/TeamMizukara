#pragma once

//必要なヘッダ
#include <memory>
#include <list>

using namespace std;

enum Scene
{
	TITLE = 10,
	TITLE_MAIN = 20,
	GAME = 30,
	GAME_MAIN = 40,
	STAGESELECTO = 50,
	STAGESELECTO_MAIN,
	STORY = 60,
	STORY_MAIN = 70,
};

enum {
	LEFT,
	RIGHT,
	UNDER,
};

//オブジェクトの名前列挙
enum {
	PLAYER,
	MENU,
};

//int g_SceneNumber = TITLE;//ゲーム画面フラグ

//オブジェクトクラス
class CObj
{
public:
	CObj() 
	{
		is_delete = false;
		m_priority = 0;
	};
	virtual ~CObj() {};
	virtual void Action() = 0;
	virtual void Draw() = 0;

	unsigned int GetName() { return m_name; };

	unsigned int m_name;		//オブジェクトの名前
	bool is_delete;				//削除フラグ
	unsigned long m_priority;	//描画優先順位
};

//タスクシステム
typedef class CTaskSystem
{
public:
	CTaskSystem() {}
	~CTaskSystem() {}

	static void InsertObj(CObj* obj);	//追加
	static void ListAction();			//リスト内のアクション実行
	static void ListDraw();				//リスト内のドロー実行
	static CObj* GetObj(unsigned int n);
	static void TaskClear();

	static void InitTaskSystem();	//初期化
	static void DeleteTaskSystem();	//破棄

	static void SortPriority();		//リスト内のオブジェクトをプライオリティ順にソート
private:
	//リスト　CObjを持つオブジェクトの要素を持つ
	static list<shared_ptr<CObj>>* m_task_list;

}TaskSystem;

