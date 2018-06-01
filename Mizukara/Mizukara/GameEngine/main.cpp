//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//�V�X�e���n�̃w�b�_�[�C���N���[�h-----------
#include <stdio.h>
#include <Windows.h>
#include <D3D11.h>
#include <d3dx11.h>
#include <d3dCompiler.h>
#include <process.h>

//Game�V�X�e���p�w�b�_�[(����)�C���N���[�h---
#include "WindowCreate.h"
#include "DeviceCreate.h"
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "FontTex.h"
#include "Collision.h"

//�f�o�b�O�p�I�u�W�F�N�g�w�b�_---------------
#include "..\Title.h"
#include "..\ObjStory.h"
#include "..\StageSelecto.h"
#include "..\Result.h"
#include "..\Hero.h"
#include "..\Tank.h"
#include "..\Background.h"
#include "..\BucketMeter.h"
#include "..\ObjGround.h"
#include "..\SceneMain.h"
#include "..\WTM.h"
#include "..\Menu.h"
#include "..\Sprinkler.h"
#include "..\ObjUpScaffold.h"
#include "..\ObjUpScaffold_Tank.h"
#include "..\ObjDownBlock.h"
#include "..\ObjDownBlock_Tank.h"
#include "..\ObjMoveBlock.h"
#include "..\ObjMoveBlock_Tank.h"
#include "..\ObjGround2.h"
#include "..\ObjBoat.h"
#include "..\ObjBoat_Tank.h"
#include "..\ObjGround3.h"
#include "..\ObjColorDoor.h"
#include "..\ObjColorDoor_Tank.h"
#include "..\Tank2.h"
#include "..\Tank3.h"
#include "..\ObjDownBlockStage2.h"
#include "..\ObjDownBlock_TankStage2.h"
#include "..\ObjScale.h"

//�폜����Ă��Ȃ����������o�͂Ƀ_���v����---
#include <crtdbg.h>
#ifdef _DEBUG
	#ifdef DBG_NEW
		#define DBG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)

		#define new DBG_NEW
	#endif
#endif	//DEBUG

//LIB�̓o�^--------------
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dx11.lib")
#pragma comment(lib,"d3dCompiler.lib")

//�\����-------------------

//�O���[�o���ϐ�--------------
bool g_ls_game_end = false;	//�X���b�h�p�Q�[���I���t���O
int g_SceneNumber = TITLE;//�Q�[����ʃt���O
bool g_key_flag = true;//�L�[�t���O
float Default_c[4] = { 1.0f,1.0f,1.0f,1.0f };//�f�t�H���g�J���[
bool g_clearlist = false;
float g_TankRemaining;  //�^���N�̎c��

//�v���g�^�C�v�錾------
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	//�E�B���h�E�v���W�[�V���[

//�}���`�X���b�h�ɂ���֐�---------
//�e�N�X�`���ǂݍ��݊֐�
unsigned __stdcall TextureLoadSled(void *p)
{
	//�C���[�W�ǂݍ���
	Draw::LoadImage(0, L"Images\\BoyR.png");//0�Ԗڂ�"BoyR.png"��ǂݍ���
	Draw::LoadImage(1, L"Images\\BoyL.png");//1�Ԗڂ�"BoyL..png"��ǂݍ���
	Draw::LoadImage(2, L"Images\\BoyRW1.png");//2�Ԗڂ�"BoyRW1.png"��ǂݍ���
	Draw::LoadImage(3, L"Images\\BoyLW1.png");//3�Ԗڂ�"BoyLW1.png"��ǂݍ���
	Draw::LoadImage(7, L"Images\\BoyRW2.png");//7�Ԗڂ�"BoyRW2.png"��ǂݍ���
	Draw::LoadImage(8, L"Images\\BoyLW2.png");//8�Ԗڂ�"BoyLW2.png"��ǂݍ���
	Draw::LoadImage(6, L"Images\\BoySquat.png");//4�Ԗڂ�"BoySquat.png"��ǂݍ���
	Draw::LoadImage(4, L"Images\\BoyUp.png");//4�Ԗڂ�"BoyUp.png"��ǂݍ���
	Draw::LoadImage(5, L"Images\\BoyDown.png");//5�Ԗڂ�"BoyDown.png"��ǂݍ���
	//Draw::LoadImage(6, L"Images\\Player8.png");//6�Ԗڂ�"Player8.png"��ǂݍ���
	Draw::LoadImage(9, L"Images\\BoyJumghp.png");//5�Ԗڂ�"Player6.png"��ǂݍ���
	Draw::LoadImage(10, L"Images\\Tank.png");//10�Ԗڂ�"Tank.png"��ǂݍ���
	Draw::LoadImage(11, L"Images\\BucketMeter.png");//11�Ԗڂ�"BucketMeter.png"��ǂݍ���
	Draw::LoadImage(12, L"Images\\Background.png");//12�Ԗڂ�"Background.png"��ǂݍ���
	Draw::LoadImage(13, L"Images\\Title.png");//13�Ԗڂ�"Title.png��ǂݍ���
	Draw::LoadImage(14, L"Images\\sibuki.png");//14�Ԗڂ�"sibuki.png��ǂݍ���
	Draw::LoadImage(15, L"Images\\Menu.png");//15�Ԗڂ�"Menu.png��ǂݍ���
	//Draw::LoadImage(16, L"Images\\WTM.png");//16�Ԗڂ�"WTM.png��ǂݍ���
	Draw::LoadImage(17, L"Images\\description.png");//17�Ԗڂ�"description.png��ǂݍ���
	//Draw::LoadImage(18, L"Images\\jimen.png");//18�Ԗڂ�"jimen.png��ǂݍ���
	Draw::LoadImage(19, L"Images\\StageSelecto.png");//19�Ԗڂ�"StageSelecto.png��ǂݍ���
	Draw::LoadImage(20, L"Images\\Story.png");//20�Ԗڂ�"Story.png��ǂݍ���
	Draw::LoadImage(21, L"Images\\icon.png");//21�Ԗڂ�"icon.png��ǂݍ���
	Draw::LoadImage(22, L"Images\\Stage1.png");//22�Ԗڂ�"Stage1.png��ǂݍ���
	Draw::LoadImage(23, L"Images\\Result.png");//23�Ԗڂ�"Result.png��ǂݍ���
	Draw::LoadImage(24, L"Images\\Stage1B.png");//24�Ԗڂ�Stage1B.png��ǂݍ���
	Draw::LoadImage(25, L"Images\\Wave1.png");//25�Ԗڂ�Wave1.png��ǂݍ���
	Draw::LoadImage(26, L"Images\\Wave2.png");//26�Ԗڂ�Wave2.png��ǂݍ���
	Draw::LoadImage(27, L"Images\\Wave3.png");//27�Ԗڂ�Wave3.png��ǂݍ���
	Draw::LoadImage(28, L"Images\\Wave4.png");//28�Ԗڂ�Wave4.png��ǂݍ���
	Draw::LoadImage(29, L"Images\\Wave5.png");//29�Ԗڂ�Wave5.png��ǂݍ���
	Draw::LoadImage(30, L"Images\\Wave6.png");//30�Ԗڂ�Wave6.png��ǂݍ���
	Draw::LoadImage(31, L"Images\\Wave7.png");//31�Ԗڂ�Wave7.png��ǂݍ���
	Draw::LoadImage(32, L"Images\\Wave8.png");//32�Ԗڂ�Wave8.png��ǂݍ���
	Draw::LoadImage(33, L"Images\\Wave9.png");//33�Ԗڂ�Wave9.png��ǂݍ���
	Draw::LoadImage(34, L"Images\\Wave10.png");//34�Ԗڂ�Wave10.png��ǂݍ���
	Draw::LoadImage(35, L"Images\\Wave11.png");//35�Ԗڂ�Wave11.png��ǂݍ���
	Draw::LoadImage(36, L"Images\\Wave12.png");//36�Ԗڂ�Wave12.png��ǂݍ���
	Draw::LoadImage(37, L"Images\\Wave13.png");//37�Ԗڂ�Wave13.png��ǂݍ���
	Draw::LoadImage(38, L"Images\\Wave14.png");//38�Ԗڂ�Wave14.png��ǂݍ���
	Draw::LoadImage(39, L"Images\\Wave15.png");//39�Ԗڂ�Wave15.png��ǂݍ���
	Draw::LoadImage(40, L"Images\\Wave16.png");//40�Ԗڂ�Wave16.png��ǂݍ���
	Draw::LoadImage(41, L"Images\\Wave17.png");//41�Ԗڂ�Wave17.png��ǂݍ���
	Draw::LoadImage(42, L"Images\\Wave18.png");//42�Ԗڂ�Wave18.png��ǂݍ���
	Draw::LoadImage(43, L"Images\\Wave19.png");//43�Ԗڂ�Wave19.png��ǂݍ���
	Draw::LoadImage(44, L"Images\\Wave20.png");//44�Ԗڂ�Wave20.png��ǂݍ���
	Draw::LoadImage(45, L"Images\\Wave21.png");//45�Ԗڂ�Wave21.png��ǂݍ���
	Draw::LoadImage(46, L"Images\\Wave22.png");//46�Ԗڂ�Wave22.png��ǂݍ���
	Draw::LoadImage(47, L"Images\\icon2.png");//47�Ԗڂ�"icon2.png��ǂݍ���
	Draw::LoadImage(48, L"Images\\water.png");//48�Ԗڂ�water.png��ǂݍ���
	Draw::LoadImage(49, L"Images\\WhiteBack.png");//49�Ԗڂ�WhiteBack.png��ǂݍ���
	Draw::LoadImage(50, L"Images\\Hose.png");//50�Ԗڂ�Hose.png��ǂݍ���
	Draw::LoadImage(51, L"Images\\Mizu_karie.png");//51�Ԗ�Mizu(karie).png�̂�ǂݍ���
	Draw::LoadImage(52, L"Images\\Gimmick1tank.png");//52�Ԗ�Gimmick1tank.png�̂�ǂݍ���
	Draw::LoadImage(53, L"Images\\Gimmick1scaffold.png");//53�Ԗ�Gimmick1scaffold.png�̂�ǂݍ���
	Draw::LoadImage(54, L"Images\\Gimmick1pulley.png");//54�Ԗ�Gimmick1pulley.png�̂�ǂݍ���
	Draw::LoadImage(55, L"Images\\Gimmick1Board.png");//55�Ԗ�Gimmick1Board.png�̂�ǂݍ���
	Draw::LoadImage(56, L"Images\\Gimmick2Bucket.png");//56�Ԗ�Gimmick2Bucket.png��ǂݍ���
	Draw::LoadImage(57, L"Images\\Gimmick2pulley.png");//57�Ԗ�Gimmick2pulley.png��ǂݍ���
	Draw::LoadImage(58, L"Images\\Gimmick2stand.png");//58�Ԗ�Gimmick2stand.png��ǂݍ���
	Draw::LoadImage(59, L"Images\\Gimmick2string.png");//59�Ԗ�Gimmick2string.png��ǂݍ���
	Draw::LoadImage(60, L"Images\\Gimmick3tank.png");//60�Ԗ�Gimmick3tank.png��ǂݍ���
	Draw::LoadImage(61, L"Images\\Gimmick3stand.png");//61�Ԗ�Gimmick3stand.png��ǂݍ���
	Draw::LoadImage(62, L"Images\\rope.png");//61�Ԗ�Gimmick3stand.png��ǂݍ���
	Draw::LoadImage(63, L"Images\\crearkari.png");//63�Ԗ�crearkari.png��ǂݍ���
	Draw::LoadImage(64, L"Images\\Me.png");//64�Ԗ�Me.png��ǂݍ���
	Draw::LoadImage(65, L"Images\\CHimawari.png");//65�Ԗ�CHimawari.png��ǂݍ���
	Draw::LoadImage(66, L"Images\\BHimawari.png");//66�Ԗ�BHimawari.png��ǂݍ���
	Draw::LoadImage(67, L"Images\\AHimawari.png");//67�Ԗ�AHimawari.png��ǂݍ���
	Draw::LoadImage(68, L"Images\\SHimawari.png");//68�Ԗ�SHimawari.png��ǂݍ���
	Draw::LoadImage(69, L"Images\\Stage2.png");//69�Ԗ�Stage2.png��ǂݍ���
	Draw::LoadImage(70, L"Images\\icon3.png");//70�Ԗڂ�"icon3.png��ǂݍ���
	Draw::LoadImage(71, L"Images\\Stage3.png");//71�Ԗ�Stage3.png��ǂݍ���
	Draw::LoadImage(72, L"Images\\BoyJumpN.png");//72�Ԗڂ�"BoyJumpN.png"��ǂݍ���
	Draw::LoadImage(73, L"Images\\Hune.png");//73�Ԗڂ�"Hune.png"��ǂݍ���
	Draw::LoadImage(74, L"Images\\RedM.png");//74�Ԗڂ�"RedM.png"��ǂݍ���
	Draw::LoadImage(75, L"Images\\RedT.png");//75�Ԗڂ�"RedT.png"��ǂݍ���
	Draw::LoadImage(76, L"Images\\RedW.png");//76�Ԗڂ�"RedW.png"��ǂݍ���
	Draw::LoadImage(77, L"Images\\Baketu.png");//77�Ԗڂ�"Baketu.png"��ǂݍ���
	Draw::LoadImage(78, L"Images\\Stage2B.png");//78�Ԗ�Stage2B.png��ǂݍ���
	Draw::LoadImage(79, L"Images\\Stage3B.png");//79�Ԗ�Stage3B.png��ǂݍ���
	Draw::LoadImage(80, L"Images\\Gimmick2pulleyshort.png");//80�Ԗ�Gimmick2pulleyshort.png��ǂݍ���
	Draw::LoadImage(71, L"Images\\Stage3.png");//69�Ԗ�Stage3.png��ǂݍ���
	Draw::LoadImage(72, L"Images\\BoyJumpN.png");//71�Ԗڂ�"BoyJumpN.png"��ǂݍ���
	Draw::LoadImage(73, L"Images\\Hune.png");//72�Ԗڂ�"Hune.png"��ǂݍ���
	Draw::LoadImage(74, L"Images\\kaitendai.png");//74�Ԗڂ�"kaitendai.png"��ǂݍ���

	//Draw::LoadImage(49, L"Images\\water2.png");//49�Ԗڂ�water2.png��ǂݍ���
	_endthreadex(0);	//�X���b�h�I��
	return 0;
}

//�~���[�W�b�N�ǂݍ��݊֐�
unsigned __stdcall MusicLoadSled(void *p)
{
	//�~���[�W�b�N���擾
	//Audio::LoadBackMusic("Sounds\\Test.ogg");
	Audio::LoadSEMusic(0, "Sounds\\splash.ogg");
	_endthreadex(0);	//�X���b�h�I��
	return 0;
}

//�Q�[�����C���֐�
unsigned __stdcall GameMainSled(void *p)
{
	while (1)
	{
		//�Q�[�����C��
		TaskSystem::SortActionPriority();//�`�揇�ʕύX(�A�N�V�����p)
		TaskSystem::ListAction();	//���X�g���̃A�N�V�������s

		//�Փ˔�����s
		Collision::CheckStart();

		//�����_�����O�^�[�Q�b�g�Z�b�g�ƃ����_�����O��ʃN���A
		float color[] = { 0.0f,0.25f,0.45f,1.0f };
		Dev::GetDeviceContext()->OMSetRenderTargets(1, Dev::GetppRTV(), NULL);//�����_�����O����J���[�o�b�t�@(�o�b�N�o�b�t�@)�ɃZ�b�g
		Dev::GetDeviceContext()->ClearRenderTargetView(Dev::GetRTV(), color);//��ʂ�color�ŃN���A
		Dev::GetDeviceContext()->RSSetState(Dev::GetRS());//���X�^���C�Y���Z�b�g
		//�������烌���_�����O�J�n

		TaskSystem::SortDrawPriority();//�`�揇�ʕύX(�h���[�p)
		TaskSystem::ListDraw();		//���X�g���̃h���[���s
		Collision::DrawDebug();

		if (g_clearlist) {
			CCollision::ClearHitLine();
			TaskSystem::TaskClear();
		}
		g_clearlist = false;

		CTitle* title;
		CObjStory* story;
		CStageSelecto* stageselecto;
		CResult* result;
		CHero* hero;
		CTank* tank;
		CBackground* background;
		CBucketMeter* bucketmeter;
		CObjGround* ground;
		CWTM* wtm;
		CSPRI* spri;
		ObjUpScaffold* upsc;
		ObjUpScaffold_Tank* upsct;
		ObjDownBlock* dwbl;
		ObjDownBlock_Tank* dwblt;
		ObjMoveBlock* mobl;
		ObjMoveBlock_Tank* moblt;
		ObjGround2* ground2;
		ObjBoat* boat;
		ObjBoat_Tank* boat_t;
		ObjGround3* ground3;
		ObjColorDoor* colordoor;
		ObjColorDoor_Tank* colordoort;
		CTank2* tank2;
		CTank3* tank3;
		ObjDownBlockStage2* dwblS2;
		ObjDownBlock_TankStage2* dwbltS2;
		ObjScale* scale;

		switch (g_SceneNumber)
		{
		case TITLE://�^�C�g��������
			title = new CTitle();
			title->m_ActionPriority = 0;
			title->m_DrawPriority = 100;
			TaskSystem::InsertObj(title);
			g_SceneNumber = TITLE_MAIN;
			break;

		case TITLE_MAIN://�^�C�g��
			break;

		case STORY:
			story = new CObjStory();
			story->m_ActionPriority = 0;
			story->m_DrawPriority = 100;
			TaskSystem::InsertObj(story);
			g_SceneNumber = STORY_MAIN;
			break;

		case STORY_MAIN:
			break;

		case STAGESELECTO://�X�e�[�W�Z���N�g������
			stageselecto = new CStageSelecto();
			stageselecto->m_ActionPriority = 10;
			stageselecto->m_DrawPriority = 110;
			TaskSystem::InsertObj(stageselecto);
			g_SceneNumber = STAGESELECTO_MAIN;
			break;

		case STAGESELECTO_MAIN://�X�e�[�W�Z���N�g
			break;

		case RESULT://���U���g��ʏ�����
			result = new CResult();
			result->m_ActionPriority = 20;
			result->m_DrawPriority = 20;
			TaskSystem::InsertObj(result);
			g_SceneNumber = RESULT_MAIN;
			break;

		case RESULT_MAIN://���U���g���
			break;

		case GAME://�Q�[����ʏ�����
			background = new CBackground();
			background->m_ActionPriority = 10;
			background->m_DrawPriority = 10;
			TaskSystem::InsertObj(background);

			wtm = new CWTM();
			wtm->m_ActionPriority = 70;
			wtm->m_DrawPriority = 60;
			TaskSystem::InsertObj(wtm);

			hero = new CHero();
			hero->m_ActionPriority = 60;
			hero->m_DrawPriority = 150;
			TaskSystem::InsertObj(hero);

			tank = new CTank();
			tank->m_ActionPriority = 80;
			tank->m_DrawPriority = 70;
			TaskSystem::InsertObj(tank);

			ground = new CObjGround();
			ground->m_ActionPriority = 90;
			ground->m_DrawPriority = 80;
			TaskSystem::InsertObj(ground);

			mobl = new ObjMoveBlock();
			mobl->m_ActionPriority = 110;
			mobl->m_DrawPriority = 40;
			TaskSystem::InsertObj(mobl);

			moblt = new ObjMoveBlock_Tank();
			moblt->m_ActionPriority = 110;
			moblt->m_DrawPriority = 70;
			TaskSystem::InsertObj(moblt);

			upsc = new ObjUpScaffold();
			upsc->m_ActionPriority = 120;
			upsc->m_DrawPriority = 120;
			TaskSystem::InsertObj(upsc);

			upsct = new ObjUpScaffold_Tank();
			upsct->m_ActionPriority = 120;
			upsct->m_DrawPriority = 120;
			TaskSystem::InsertObj(upsct);

			dwbl = new ObjDownBlock();
			dwbl->m_ActionPriority = 130;
			dwbl->m_DrawPriority = 130;
			TaskSystem::InsertObj(dwbl);

			dwblt = new ObjDownBlock_Tank();
			dwblt->m_ActionPriority = 130;
			dwblt->m_DrawPriority = 130;
			TaskSystem::InsertObj(dwblt);

			bucketmeter = new CBucketMeter();
			bucketmeter->m_ActionPriority = 140;
			bucketmeter->m_DrawPriority = 170;
			TaskSystem::InsertObj(bucketmeter);

			spri = new CSPRI();
			spri->m_ActionPriority = 150;
			spri->m_DrawPriority = 60;
			TaskSystem::InsertObj(spri);

			g_SceneNumber = GAME_MAIN;
			break;

		case GAME_MAIN:
			break;

		case GAME2:
			background = new CBackground();
			background->m_ActionPriority = 10;
			background->m_DrawPriority = 10;
			TaskSystem::InsertObj(background);

			ground2 = new ObjGround2();
			ground2->m_ActionPriority = 90;
			ground2->m_DrawPriority = 90;
			TaskSystem::InsertObj(ground2);

			boat = new ObjBoat();
			boat->m_ActionPriority = 50;
			boat->m_DrawPriority = 160;
			TaskSystem::InsertObj(boat);

			boat_t = new ObjBoat_Tank();
			boat_t->m_ActionPriority = 70;
			boat_t->m_DrawPriority = 160;
			TaskSystem::InsertObj(boat_t);

			hero = new CHero();
			hero->m_ActionPriority = 60;
			hero->m_DrawPriority = 150;
			TaskSystem::InsertObj(hero);

			tank2 = new CTank2();
			tank2->m_ActionPriority = 80;
			tank2->m_DrawPriority = 80;
			TaskSystem::InsertObj(tank2);

			dwblS2 = new ObjDownBlockStage2();
			dwblS2->m_ActionPriority = 130;
			dwblS2->m_DrawPriority = 130;
			TaskSystem::InsertObj(dwblS2);

			dwbltS2 = new ObjDownBlock_TankStage2();
			dwbltS2->m_ActionPriority = 130;
			dwbltS2->m_DrawPriority = 130;
			TaskSystem::InsertObj(dwbltS2);


			scale = new ObjScale();
			scale->m_ActionPriority = 90;
			scale->m_DrawPriority = 80;
			TaskSystem::InsertObj(scale);

			g_SceneNumber = GAME_MAIN2;
			break;
		case GAME_MAIN2:
			break;

		case GAME3:
			background = new CBackground();
			background->m_ActionPriority = 10;
			background->m_DrawPriority = 10;
			TaskSystem::InsertObj(background);

			ground3 = new ObjGround3();
			ground3->m_ActionPriority = 90;
			ground3->m_DrawPriority = 90;
			TaskSystem::InsertObj(ground3);

			hero = new CHero();
			hero->m_ActionPriority = 60;
			hero->m_DrawPriority = 150;
			TaskSystem::InsertObj(hero);

			tank3 = new CTank3();
			tank3->m_ActionPriority = 80;
			tank3->m_DrawPriority = 80;
			TaskSystem::InsertObj(tank3);

			colordoor = new ObjColorDoor();
			colordoor->m_ActionPriority = 100;
			colordoor->m_DrawPriority = 100;
			TaskSystem::InsertObj(colordoor);

			colordoort = new ObjColorDoor_Tank();
			colordoort->m_ActionPriority = 110;
			colordoort->m_DrawPriority = 110;
			TaskSystem::InsertObj(colordoort);

			g_SceneNumber = GAME_MAIN3;
			break;

		case GAME_MAIN3:
			break;
		}


		//�����_�����O�I��
		Dev::GetSwapChain()->Present(1, 0);//60FPS�Ńo�b�N�o�b�t�@�ƃv���C�}���o�b�t�@�̌���


		//�I��
		if (g_ls_game_end==true)
		{
			break;
		}
	}
	_endthreadex(0);	//�X���b�h�I��
	return 0;
}


//Main�֐�---------
int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR szCmdLine, int nCmdShow)
{
	//�������_���v�J�n
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CoInitializeEx(NULL,COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	wchar_t name[] = { L"GameEngine" };	//�E�B���h�E&�^�C�g���l�[��
	MSG msg;							//���b�Z�[�W�n���h��

	//�E�B���h�E�X�e�[�^�X
	WNDCLASSEX wcex = {
		sizeof(WNDCLASSEX),CS_HREDRAW | CS_VREDRAW,
		WndProc,0,0,hInstance,NULL,NULL,
		(HBRUSH)(COLOR_WINDOW + 1),NULL,name,NULL
	};

	//�E�B���h�E�N���X�쐬
	RegisterClassEx(&wcex);

	//�Q�[���e�V�X�e��������----
	CWindowCreate::NewWindow(800, 600, name, hInstance);//�E�B���h�E�쐬
	CDeviceCreate::InitDevice(CWindowCreate::GethWnd(), 800, 600);//DirectX Device�̏�����
	//CDeviceCreate::Init3DEnviroment();//3D���\�z
	Audio::InitAudio();//�I�[�f�B�I�쐬
	Input::InitInput();//���͗p�̃N���X������
	Draw::InitPolygonRender();//�|���S���\�����̏�����
	TaskSystem::InitTaskSystem();//�^�X�N�V�X�e��������
	Font::InitFontTex();//�t�H���g������
	Collision::InitHitLine();//�R���W�����̏�����
	//���\�[�X�ǂݍ���-------------
	HANDLE handoru[2];
	handoru[0] = (HANDLE)_beginthreadex(NULL, 0, TextureLoadSled, NULL, 0, NULL);//�e�N�X�`���ǂݍ���
	handoru[1] = (HANDLE)_beginthreadex(NULL, 0, MusicLoadSled, NULL, 0, NULL);//�~���[�W�b�N�ǂݍ���
	WaitForMultipleObjects(2, handoru, TRUE, INFINITE);//�ǂݍ��݃X���b�h���I���܂őҋ@
	CloseHandle(handoru[0]);//�n���h��[0]�����
	CloseHandle(handoru[1]);//�n���h��[1]�����

	//Audio::StartLoopMusic();//�o�b�N�~���[�W�b�N�X�^�[�g

	//�f�o�b�O�p�I�u�W�F�N�g�쐬
	SceneMain* scenemain = new SceneMain();
	scenemain->m_ActionPriority = 0;
	scenemain->m_DrawPriority = 0;
	TaskSystem::InsertObj(scenemain);

	HANDLE game_handoru;
	game_handoru = (HANDLE)_beginthreadex(NULL, 0, GameMainSled, NULL, 0, NULL);//�Q�[�����C���X���b�h���s

	//���b�Z�[�W���[�v
	do
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

	} while (msg.message != WM_QUIT);
	WaitForSingleObject(game_handoru, INFINITE);//�Q�[�����C���X���b�h�I���҂�
	CloseHandle(game_handoru);//�n���h�������

	//�Q�[���V�X�e���j��
	Collision::DeleteHitLine();//�R���W�����̔j��
	Font::DeleteFontTex();//�t�H���g�̔j��
	TaskSystem::DeleteTaskSystem();//�^�X�N�V�X�e���̔j��
	Draw::DeletePolygonRender();//�|���S���\�����̔j��
	//CDeviceCreate::Delete3DEnviroment();//3D���j��
	CDeviceCreate::ShutDown();//DirectX�̊��j��
	Audio::DeleteAudio();//�I�[�f�B�I���̔j��

	CoUninitialize();
	//���̎��_�ŊJ������Ă��Ȃ��������̏��̕\��
	_CrtDumpMemoryLeaks();
	return true;

}

//�R�[���o�b�N�֐�
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	Input::SetMouPos(&uMsg, &lParam);

	switch (uMsg)
	{
	case WM_KEYDOWN:		//ESC�L�[�ŏI��
		switch (wParam)
		{
		case VK_ESCAPE:
			g_ls_game_end = true;
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_CLOSE:			//�E�B���h�E�����ꍇ
		g_ls_game_end = true;
		PostQuitMessage(0);
	case WM_DESTROY:
		return 0;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
//