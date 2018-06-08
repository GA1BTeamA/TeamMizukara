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
	GAME2 = 50,
	GAME_MAIN2 = 60,
	GAME3 = 70,
	GAME_MAIN3 = 80,
	STAGESELECTO = 90,
	STAGESELECTO_MAIN = 100 ,
	STORY = 110,
	STORY_MAIN = 120,
	RESULT=130,
	RESULT_MAIN=140,
};

enum {
	LEFT,
	RIGHT,
	UNDER,
	UNDER_LEFT,
	UNDER_RIGHT,
};

enum {
	STAGE1,
	STAGE2,
	STAGE3,
	STAGE4,
	STAGE5,
};

//オブジェクトの名前列挙
enum {
	PLAYER,
	MENU,
	GROUND,
	SPRI,
	SPRI2,
	BUCKETMETER,
	TANK,
	TANK2,
	UPSCAFFOLD,
	MOVEBLOCK,
	DOWNBLOCK,
	GROUND2,
	BOAT,
	BOAT_TANK,
	GROUND3,
	COLORDOOR,
	COLORDOOR2,
	COLORDOOR3,
	COLORDOOR4,
	COLORDOOR5,
	DOWNBLOCKSTAGE2,
	SCALE1,
	SCALE2,
	SCALE3,
	SCALE4,
	SCALE5,
	WTM3,
};

//int g_SceneNumber = TITLE;//ゲーム画面フラグ

//オブジェクトクラス
class CObj
{
public:
	CObj() 
	{
		is_delete = false;
		m_ActionPriority = m_DrawPriority = 0;
	};
	virtual ~CObj() {};
	virtual void Action() = 0;
	virtual void Draw() = 0;

	unsigned int GetName() { return m_name; };

	unsigned int m_name;		//オブジェクトの名前
	bool is_delete;				//削除フラグ
	unsigned long m_ActionPriority;	//描画優先順位
	unsigned long m_DrawPriority;	//描画優先順位
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

	static void SortActionPriority();		//リスト内のオブジェクトをプライオリティ順にソート（アクション用）
	static void SortDrawPriority();		//リスト内のオブジェクトをプライオリティ順にソート（ドロー用）
private:
	//リスト　CObjを持つオブジェクトの要素を持つ
	static list<shared_ptr<CObj>>* m_task_list;

}TaskSystem;

