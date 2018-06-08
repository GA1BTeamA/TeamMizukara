#pragma once

//�K�v�ȃw�b�_
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

//�I�u�W�F�N�g�̖��O��
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

//int g_SceneNumber = TITLE;//�Q�[����ʃt���O

//�I�u�W�F�N�g�N���X
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

	unsigned int m_name;		//�I�u�W�F�N�g�̖��O
	bool is_delete;				//�폜�t���O
	unsigned long m_ActionPriority;	//�`��D�揇��
	unsigned long m_DrawPriority;	//�`��D�揇��
};

//�^�X�N�V�X�e��
typedef class CTaskSystem
{
public:
	CTaskSystem() {}
	~CTaskSystem() {}

	static void InsertObj(CObj* obj);	//�ǉ�
	static void ListAction();			//���X�g���̃A�N�V�������s
	static void ListDraw();				//���X�g���̃h���[���s
	static CObj* GetObj(unsigned int n);
	static void TaskClear();

	static void InitTaskSystem();	//������
	static void DeleteTaskSystem();	//�j��

	static void SortActionPriority();		//���X�g���̃I�u�W�F�N�g���v���C�I���e�B���Ƀ\�[�g�i�A�N�V�����p�j
	static void SortDrawPriority();		//���X�g���̃I�u�W�F�N�g���v���C�I���e�B���Ƀ\�[�g�i�h���[�p�j
private:
	//���X�g�@CObj�����I�u�W�F�N�g�̗v�f������
	static list<shared_ptr<CObj>>* m_task_list;

}TaskSystem;

