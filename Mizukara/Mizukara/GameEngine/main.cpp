//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//システム系のヘッダーインクルード-----------
#include <stdio.h>
#include <Windows.h>
#include <D3D11.h>
#include <d3dx11.h>
#include <d3dCompiler.h>
#include <process.h>

//Gameシステム用ヘッダー(自作)インクルード---
#include "WindowCreate.h"
#include "DeviceCreate.h"
#include "Draw2DPolygon.h"
#include "Input.h"
#include "Audio.h"
#include "TaskSystem.h"
#include "FontTex.h"
#include "Collision.h"

//デバッグ用オブジェクトヘッダ---------------
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
#include "..\WTM2.h"
#include "..\Menu.h"
#include "..\Sprinkler.h"
#include "..\Sprinkler2.h"
#include "..\Sprinkler3.h"
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
#include "..\ObjScale_Tank.h"
#include "..\WTM3.h"
#include "..\ZTank.h"

//削除されていないメモリを出力にダンプする---
#include <crtdbg.h>
#ifdef _DEBUG
	#ifdef DBG_NEW
		#define DBG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)

		#define new DBG_NEW
	#endif
#endif	//DEBUG

//LIBの登録--------------
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dx11.lib")
#pragma comment(lib,"d3dCompiler.lib")

//構造体-------------------

//グローバル変数--------------
bool g_ls_game_end = false;	//スレッド用ゲーム終了フラグ
int g_SceneNumber = TITLE;//ゲーム画面フラグ
bool g_key_flag = true;//キーフラグ
float Default_c[4] = { 1.0f,1.0f,1.0f,1.0f };//デフォルトカラー
bool g_clearlist = false;
float g_TankRemaining;  //タンクの残量

//プロトタイプ宣言------
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	//ウィンドウプロジーシャー

//マルチスレッドにする関数---------
//テクスチャ読み込み関数
unsigned __stdcall TextureLoadSled(void *p)
{
	//イメージ読み込み
	Draw::LoadImage(0, L"Images\\BoyR.png");//0番目に"BoyR.png"を読み込み
	Draw::LoadImage(1, L"Images\\BoyL.png");//1番目に"BoyL..png"を読み込み
	Draw::LoadImage(2, L"Images\\BoyRW1.png");//2番目に"BoyRW1.png"を読み込み
	Draw::LoadImage(3, L"Images\\BoyLW1.png");//3番目に"BoyLW1.png"を読み込み
	Draw::LoadImage(7, L"Images\\BoyRW2.png");//7番目に"BoyRW2.png"を読み込み
	Draw::LoadImage(8, L"Images\\BoyLW2.png");//8番目に"BoyLW2.png"を読み込み
	Draw::LoadImage(6, L"Images\\BoySquat.png");//4番目に"BoySquat.png"を読み込み
	Draw::LoadImage(4, L"Images\\BoyUp.png");//4番目に"BoyUp.png"を読み込み
	Draw::LoadImage(5, L"Images\\BoyDown.png");//5番目に"BoyDown.png"を読み込み
	//Draw::LoadImage(6, L"Images\\Player8.png");//6番目に"Player8.png"を読み込み
	Draw::LoadImage(9, L"Images\\BoyJump.png");//5番目に"Player6.png"を読み込み
	Draw::LoadImage(10, L"Images\\Tank.png");//10番目に"Tank.png"を読み込み
	Draw::LoadImage(11, L"Images\\BucketMeter.png");//11番目に"BucketMeter.png"を読み込み
	Draw::LoadImage(12, L"Images\\Background.png");//12番目に"Background.png"を読み込み
	Draw::LoadImage(13, L"Images\\Title.png");//13番目に"Title.pngを読み込み
	Draw::LoadImage(14, L"Images\\sibuki.png");//14番目に"sibuki.pngを読み込み
	Draw::LoadImage(15, L"Images\\Menu.png");//15番目に"Menu.pngを読み込み
	//Draw::LoadImage(16, L"Images\\WTM.png");//16番目に"WTM.pngを読み込み
	Draw::LoadImage(17, L"Images\\description.png");//17番目に"description.pngを読み込み
	//Draw::LoadImage(18, L"Images\\jimen.png");//18番目に"jimen.pngを読み込み
	Draw::LoadImage(19, L"Images\\StageSelecto.png");//19番目に"StageSelecto.pngを読み込み
	Draw::LoadImage(20, L"Images\\Story.png");//20番目に"Story.pngを読み込み
	Draw::LoadImage(21, L"Images\\icon.png");//21番目に"icon.pngを読み込み
	Draw::LoadImage(22, L"Images\\Stage1.png");//22番目に"Stage1.pngを読み込み
	Draw::LoadImage(23, L"Images\\Result.png");//23番目に"Result.pngを読み込み
	Draw::LoadImage(24, L"Images\\Stage1B.png");//24番目にStage1B.pngを読み込み
	Draw::LoadImage(25, L"Images\\Wave1.png");//25番目のWave1.pngを読み込み
	Draw::LoadImage(26, L"Images\\Wave2.png");//26番目のWave2.pngを読み込み
	Draw::LoadImage(27, L"Images\\Wave3.png");//27番目のWave3.pngを読み込み
	Draw::LoadImage(28, L"Images\\Wave4.png");//28番目のWave4.pngを読み込み
	Draw::LoadImage(29, L"Images\\Wave5.png");//29番目のWave5.pngを読み込み
	Draw::LoadImage(30, L"Images\\Wave6.png");//30番目のWave6.pngを読み込み
	Draw::LoadImage(31, L"Images\\Wave7.png");//31番目のWave7.pngを読み込み
	Draw::LoadImage(32, L"Images\\Wave8.png");//32番目のWave8.pngを読み込み
	Draw::LoadImage(33, L"Images\\Wave9.png");//33番目のWave9.pngを読み込み
	Draw::LoadImage(34, L"Images\\Wave10.png");//34番目のWave10.pngを読み込み
	Draw::LoadImage(35, L"Images\\Wave11.png");//35番目のWave11.pngを読み込み
	Draw::LoadImage(36, L"Images\\Wave12.png");//36番目のWave12.pngを読み込み
	Draw::LoadImage(37, L"Images\\Wave13.png");//37番目のWave13.pngを読み込み
	Draw::LoadImage(38, L"Images\\Wave14.png");//38番目のWave14.pngを読み込み
	Draw::LoadImage(39, L"Images\\Wave15.png");//39番目のWave15.pngを読み込み
	Draw::LoadImage(40, L"Images\\Wave16.png");//40番目のWave16.pngを読み込み
	Draw::LoadImage(41, L"Images\\Wave17.png");//41番目のWave17.pngを読み込み
	Draw::LoadImage(42, L"Images\\Wave18.png");//42番目のWave18.pngを読み込み
	Draw::LoadImage(43, L"Images\\Wave19.png");//43番目のWave19.pngを読み込み
	Draw::LoadImage(44, L"Images\\Wave20.png");//44番目のWave20.pngを読み込み
	Draw::LoadImage(45, L"Images\\Wave21.png");//45番目のWave21.pngを読み込み
	Draw::LoadImage(46, L"Images\\Wave22.png");//46番目のWave22.pngを読み込み
	Draw::LoadImage(47, L"Images\\icon2.png");//47番目に"icon2.pngを読み込み
	Draw::LoadImage(48, L"Images\\water.png");//48番目のwater.pngを読み込み
	Draw::LoadImage(49, L"Images\\WhiteBack.png");//49番目のWhiteBack.pngを読み込み
	Draw::LoadImage(50, L"Images\\Hose.png");//50番目のHose.pngを読み込み
	Draw::LoadImage(51, L"Images\\Mizu_karie.png");//51番目Mizu(karie).pngのを読み込み
	Draw::LoadImage(52, L"Images\\Gimmick1tank.png");//52番目Gimmick1tank.pngのを読み込み
	Draw::LoadImage(53, L"Images\\Gimmick1scaffold.png");//53番目Gimmick1scaffold.pngのを読み込み
	Draw::LoadImage(54, L"Images\\Gimmick1pulley.png");//54番目Gimmick1pulley.pngのを読み込み
	Draw::LoadImage(55, L"Images\\Gimmick1Board.png");//55番目Gimmick1Board.pngのを読み込み
	Draw::LoadImage(56, L"Images\\Gimmick2Bucket.png");//56番目Gimmick2Bucket.pngを読み込み
	Draw::LoadImage(57, L"Images\\Gimmick2pulley.png");//57番目Gimmick2pulley.pngを読み込み
	Draw::LoadImage(58, L"Images\\Gimmick2stand.png");//58番目Gimmick2stand.pngを読み込み
	Draw::LoadImage(59, L"Images\\Gimmick2string.png");//59番目Gimmick2string.pngを読み込み
	Draw::LoadImage(60, L"Images\\Gimmick3tank.png");//60番目Gimmick3tank.pngを読み込み
	Draw::LoadImage(61, L"Images\\Gimmick3stand.png");//61番目Gimmick3stand.pngを読み込み
	Draw::LoadImage(62, L"Images\\rope.png");//61番目Gimmick3stand.pngを読み込み
	Draw::LoadImage(63, L"Images\\clear.png");//63番目clear.pngを読み込み
	Draw::LoadImage(64, L"Images\\Me.png");//64番目Me.pngを読み込み
	Draw::LoadImage(65, L"Images\\CHimawari.png");//65番目CHimawari.pngを読み込み
	Draw::LoadImage(66, L"Images\\BHimawari.png");//66番目BHimawari.pngを読み込み
	Draw::LoadImage(67, L"Images\\AHimawari.png");//67番目AHimawari.pngを読み込み
	Draw::LoadImage(68, L"Images\\SHimawari.png");//68番目SHimawari.pngを読み込み
	Draw::LoadImage(69, L"Images\\Stage2.png");//69番目Stage2.pngを読み込み
	Draw::LoadImage(70, L"Images\\icon3.png");//70番目に"icon3.pngを読み込み
	Draw::LoadImage(71, L"Images\\Stage3.png");//71番目Stage3.pngを読み込み
	Draw::LoadImage(72, L"Images\\BoyJumpN.png");//72番目に"BoyJumpN.png"を読み込み
	Draw::LoadImage(73, L"Images\\Hune.png");//73番目に"Hune.png"を読み込み
	Draw::LoadImage(74, L"Images\\RedM.png");//74番目に"RedM.png"を読み込み
	Draw::LoadImage(75, L"Images\\RedT.png");//75番目に"RedT.png"を読み込み
	Draw::LoadImage(76, L"Images\\RedW.png");//76番目に"RedW.png"を読み込み
	Draw::LoadImage(77, L"Images\\Baketu.png");//77番目に"Baketu.png"を読み込み
	Draw::LoadImage(78, L"Images\\Stage2B.png");//78番目Stage2B.pngを読み込み
	Draw::LoadImage(79, L"Images\\Stage3B.png");//79番目Stage3B.pngを読み込み
	Draw::LoadImage(80, L"Images\\Gimmick2pulleyshort.png");//80番目Gimmick2pulleyshort.pngを読み込み
	Draw::LoadImage(81, L"Images\\kaitendai.png");//81番目に"kaitendai.png"を読み込み
	Draw::LoadImage(82, L"Images\\GreenM.png");//82番目に"GreenM.png"を読み込み
	Draw::LoadImage(83, L"Images\\GreenT.png");//83番目に"GreenT.png"を読み込み
	Draw::LoadImage(84, L"Images\\GreenW.png");//84番目に"GreenW.png"を読み込み
	Draw::LoadImage(85, L"Images\\Story2.png");//85番目に"Story2.png"を読み込み
	Draw::LoadImage(86, L"Images\\Story3.png");//86番目に"Story3.png"を読み込み
	Draw::LoadImage(87, L"Images\\Rainbow.png");//87番目に"Rainbow.png"を読み込み
	Draw::LoadImage(88, L"Images\\Ztank.png");//88番目に"Ztank.png"を読み込み
	Draw::LoadImage(89, L"Images\\CTeiboku.png");//89番目に"CTeiboku.png"を読み込み
	Draw::LoadImage(90, L"Images\\BTeiboku.png");//90番目に"BTeiboku.png"を読み込み
	Draw::LoadImage(91, L"Images\\AHaibisukasu.png");//91番目に"AHaibisukasu.png"を読み込み
	Draw::LoadImage(92, L"Images\\SHaibisukasu.png");//92番目に"SHaibisukasu.png"を読み込み
	Draw::LoadImage(93, L"Images\\SMe.png");//93番目に"SMe.png"を読み込み
	Draw::LoadImage(94, L"Images\\CSuzuran.png");//94番目に"CSuzuran.png"を読み込み
	Draw::LoadImage(95, L"Images\\BSuzuran.png");//95番目に"BSuzuran.png"を読み込み
	Draw::LoadImage(96, L"Images\\ASuzuran.png");//96番目に"ASuzuran.png"を読み込み
	Draw::LoadImage(97, L"Images\\SSuzuran.png");//97番目に"SSuzuran.png"を読み込み
	Draw::LoadImage(98, L"Images\\AllClear.png");//98番目に"AllClear.png"を読み込み
	Draw::LoadImage(99, L"Images\\Box.png");//99番目に"Box.png"を読み込み
	Draw::LoadImage(100, L"Images\\Stage1BK.png");//100番目に"Stage1BK.png"を読み込み
	Draw::LoadImage(101, L"Images\\Stage1clear.png");//101番目に"Stage1clear.png"を読み込み
	Draw::LoadImage(102, L"Images\\Stage2clear.png");//102番目に"Stage2clear.png"を読み込み
	Draw::LoadImage(103, L"Images\\Stage3clear.png");//103番目に"Stage3clear.png"を読み込み
	Draw::LoadImage(104, L"Images\\DRank.png");//104番目に"DRank.png"を読み込み
	Draw::LoadImage(105, L"Images\\CRank.png");//105番目に"CRank.png"を読み込み
	Draw::LoadImage(106, L"Images\\BRank.png");//106番目に"BRank.png"を読み込み
	Draw::LoadImage(107, L"Images\\ARank.png");//107番目に"ARank.png"を読み込み
	Draw::LoadImage(108, L"Images\\SRank.png");//108番目に"SRank.png"を読み込み


	//Draw::LoadImage(49, L"Images\\water2.png");//49番目のwater2.pngを読み込み
	_endthreadex(0);	//スレッド終了
	return 0;
}

//ミュージック読み込み関数
unsigned __stdcall MusicLoadSled(void *p)
{
	//ミュージック情報取得
	//Audio::LoadBackMusic("Sounds\\Test.ogg");
	Audio::LoadSEMusic(0, "Sounds\\Splash.ogg");
	Audio::LoadBackMusic(1, "Sounds\\Water.ogg");
	Audio::LoadBackMusic(2, "Sounds\\Menu.ogg");
	Audio::LoadBackMusic(3, "Sounds\\Title.ogg");
	Audio::LoadBackMusic(4, "Sounds\\Story.ogg");
	Audio::LoadBackMusic(5, "Sounds\\StageSerect.ogg");
	Audio::LoadBackMusic(6, "Sounds\\Stage1.ogg");
	Audio::LoadBackMusic(7, "Sounds\\Stage2.ogg");
	Audio::LoadBackMusic(8, "Sounds\\Stage3.ogg");
	Audio::LoadBackMusic(9, "Sounds\\Clear.ogg");
	Audio::LoadBackMusic(10, "Sounds\\Result.ogg");
	Audio::LoadBackMusic(11, "Sounds\\Ending.ogg");
	Audio::LoadBackMusic(12, "Sounds\\CDoor.ogg");
	Audio::LoadBackMusic(13, "Sounds\\WSound.ogg");

	_endthreadex(0);	//スレッド終了
	return 0;
}

//ゲームメイン関数
unsigned __stdcall GameMainSled(void *p)
{
	while (1)
	{
		//ゲームメイン
		TaskSystem::SortActionPriority();//描画順位変更(アクション用)
		TaskSystem::ListAction();	//リスト内のアクション実行

		//衝突判定実行
		Collision::CheckStart();

		//レンダリングターゲットセットとレンダリング画面クリア
		float color[] = { 0.0f,0.25f,0.45f,1.0f };
		Dev::GetDeviceContext()->OMSetRenderTargets(1, Dev::GetppRTV(), NULL);//レンダリング先をカラーバッファ(バックバッファ)にセット
		Dev::GetDeviceContext()->ClearRenderTargetView(Dev::GetRTV(), color);//画面をcolorでクリア
		Dev::GetDeviceContext()->RSSetState(Dev::GetRS());//ラスタライズをセット
		//ここからレンダリング開始

		TaskSystem::SortDrawPriority();//描画順位変更(ドロー用)
		TaskSystem::ListDraw();		//リスト内のドロー実行
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
		CWTM* wtm_Clear;
		CWTM2* wtm2_1;
		CWTM2* wtm2_2;
		CWTM2* wtm2_3;
		CWTM2* wtm2_Clear;
		CSPRI* spri;
		CSPRI2* spri2;
		CSPRI3* spri3;
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
		ObjColorDoor* colordoor2;
		ObjColorDoor* colordoor3;
		ObjColorDoor* colordoor4;
		ObjColorDoor* colordoor5;
		ObjColorDoor_Tank* colordoort;
		ObjColorDoor_Tank* colordoort2;
		ObjColorDoor_Tank* colordoort3;
		ObjColorDoor_Tank* colordoort4;
		ObjColorDoor_Tank* colordoort5;
		CTank2* tank2;
		CTank3* tank3;
		ObjDownBlockStage2* dwblS2;
		ObjDownBlock_TankStage2* dwbltS2;
		ObjScale* scale;
		ObjScale_Tank* scale_t;
		ObjScale* scale2;
		ObjScale_Tank* scale_t2;
		ObjScale* scale3;
		ObjScale_Tank* scale_t3;
		ObjScale* scale4;
		ObjScale_Tank* scale_t4;
		ObjScale* scale5;
		ObjScale_Tank* scale_t5;
		ObjElephant_Tank* ztank;


		CWTM3* wtm3;
		CWTM3* wtm3_1;
		CWTM3* wtm3_2;
		CWTM3* wtm3_3;

		switch (g_SceneNumber)
		{
		case TITLE://タイトル初期化
			title = new CTitle();
			title->m_ActionPriority = 0;
			title->m_DrawPriority = 100;
			TaskSystem::InsertObj(title);
			g_SceneNumber = TITLE_MAIN;
			break;

		case TITLE_MAIN://タイトル
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

		case STAGESELECTO://ステージセレクト初期化
			stageselecto = new CStageSelecto();
			stageselecto->m_ActionPriority = 10;
			stageselecto->m_DrawPriority = 110;
			TaskSystem::InsertObj(stageselecto);
			g_SceneNumber = STAGESELECTO_MAIN;

			g_TankRemaining = 0;
			break;

		case STAGESELECTO_MAIN://ステージセレクト
			break;

		case RESULT://リザルト画面初期化
			result = new CResult();
			result->m_ActionPriority = 1;
			result->m_DrawPriority = 200;
			TaskSystem::InsertObj(result);
			g_SceneNumber = RESULT_MAIN;
			break;

		case RESULT_MAIN://リザルト画面
			break;

		case GAME://ゲーム画面初期化
			background = new CBackground();
			background->m_ActionPriority = 10;
			background->m_DrawPriority = 10;
			TaskSystem::InsertObj(background);

			wtm = new CWTM(1186.0f, 234.0f);
			wtm->m_ActionPriority = 70;
			wtm->m_DrawPriority = 60;
			TaskSystem::InsertObj(wtm);

			wtm_Clear = new CWTM(2147.0f,315.0f);
			wtm_Clear->m_ActionPriority = 70;
			wtm_Clear->m_DrawPriority = 60;
			TaskSystem::InsertObj(wtm_Clear);

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

			dwbl = new ObjDownBlock(854.0f,245.0f);
			dwbl->m_ActionPriority = 130;
			dwbl->m_DrawPriority = 130;
			TaskSystem::InsertObj(dwbl);

			dwblt = new ObjDownBlock_Tank(676.0f,150.0f);
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
			dwblS2->m_DrawPriority = 80;
			TaskSystem::InsertObj(dwblS2);

			dwbltS2 = new ObjDownBlock_TankStage2();
			dwbltS2->m_ActionPriority = 130;
			dwbltS2->m_DrawPriority = 80;
			TaskSystem::InsertObj(dwbltS2);

			scale = new ObjScale(725.0f, 347.0f,1);
			scale->m_ActionPriority = 90;
			scale->m_DrawPriority = 80;
			TaskSystem::InsertObj(scale);
			scale_t = new ObjScale_Tank(725.0f, 347.0f,1.0f,6.0f,1);
			scale_t->m_ActionPriority = 90;
			scale_t->m_DrawPriority = 80;
			TaskSystem::InsertObj(scale_t);

			scale2 = new ObjScale(1075.0f, 190.0f,2);
			scale2->m_ActionPriority = 90;
			scale2->m_DrawPriority = 80;
			TaskSystem::InsertObj(scale2);
			scale_t2 = new ObjScale_Tank(1075.0f, 190.0f,0.0f,6.0f,2);
			scale_t2->m_ActionPriority = 90;
			scale_t2->m_DrawPriority = 80;
			TaskSystem::InsertObj(scale_t2);

			scale3 = new ObjScale(/*1355.0f*/1415.0f, 270.0f, 3);
			scale3->m_ActionPriority = 90;
			scale3->m_DrawPriority = 80;
			TaskSystem::InsertObj(scale3);
			scale_t3 = new ObjScale_Tank(1415.0f, 270.0f,0.0f,4.0f, 3);
			scale_t3->m_ActionPriority = 90;
			scale_t3->m_DrawPriority = 80;
			TaskSystem::InsertObj(scale_t3);

			//scale4 = new ObjScale(1520.0f, 167.0f, 4);
			//scale4->m_ActionPriority = 90;
			//scale4->m_DrawPriority = 80;
			//TaskSystem::InsertObj(scale4);
			//scale_t4 = new ObjScale_Tank(1520.0f, 167.0f,0.0f,6.0f, 4);
			//scale_t4->m_ActionPriority = 90;
			//scale_t4->m_DrawPriority = 80;
			//TaskSystem::InsertObj(scale_t4);

			scale5 = new ObjScale(/*1685.0f*/1625.0f, 230.0f, 5);
			scale5->m_ActionPriority = 90;
			scale5->m_DrawPriority = 80;
			TaskSystem::InsertObj(scale5);
			scale_t5 = new ObjScale_Tank(1625.0f, 230.0f,0.0f,4.0f, 5);
			scale_t5->m_ActionPriority = 90;
			scale_t5->m_DrawPriority = 80;
			TaskSystem::InsertObj(scale_t5);

			wtm2_1 = new CWTM2(650.0f,315.0f);
			wtm2_1->m_ActionPriority = 70;
			wtm2_1->m_DrawPriority = 60;
			TaskSystem::InsertObj(wtm2_1);

			wtm2_2 = new CWTM2(1260.0f, 188.0f);
			wtm2_2->m_ActionPriority = 70;
			wtm2_2->m_DrawPriority = 60;
			TaskSystem::InsertObj(wtm2_2);

			wtm2_3 = new CWTM2(1940.0f, 145.0f);
			wtm2_3->m_ActionPriority = 70;
			wtm2_3->m_DrawPriority = 60;
			TaskSystem::InsertObj(wtm2_3);

			ztank = new ObjElephant_Tank();
			ztank->m_ActionPriority = 70;
			ztank->m_DrawPriority = 50;
			TaskSystem::InsertObj(ztank);

			bucketmeter = new CBucketMeter();
			bucketmeter->m_ActionPriority = 140;
			bucketmeter->m_DrawPriority = 170;
			TaskSystem::InsertObj(bucketmeter);

			wtm2_Clear = new CWTM2(2947.0f, 315.0f);
			wtm2_Clear->m_ActionPriority = 70;
			wtm2_Clear->m_DrawPriority = 60;
			TaskSystem::InsertObj(wtm2_Clear);

			spri2 = new CSPRI2();
			spri2->m_ActionPriority = 150;
			spri2->m_DrawPriority = 60;
			TaskSystem::InsertObj(spri2);

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

			//赤WTM
			wtm3 = new CWTM3(211,234,74);
			wtm3->m_ActionPriority = 70;
			wtm3->m_DrawPriority = 60;
			TaskSystem::InsertObj(wtm3);

			//緑WTM
			wtm3_1 = new CWTM3(745,146,82);
			wtm3_1->m_ActionPriority = 70;
			wtm3_1->m_DrawPriority = 60;
			TaskSystem::InsertObj(wtm3_1);

			//赤WTM
			wtm3_2 = new CWTM3(2550, 84, 74);
			wtm3_2->m_ActionPriority = 70;
			wtm3_2->m_DrawPriority = 60;
			TaskSystem::InsertObj(wtm3_2);

			wtm3_3 = new CWTM3(1195, 146, 0);
			wtm3_3->m_ActionPriority = 70;
			wtm3_3->m_DrawPriority = 60;
			TaskSystem::InsertObj(wtm3_3);

			hero = new CHero();
			hero->m_ActionPriority = 60;
			hero->m_DrawPriority = 150;
			TaskSystem::InsertObj(hero);

			tank3 = new CTank3();
			tank3->m_ActionPriority = 80;
			tank3->m_DrawPriority = 80;
			TaskSystem::InsertObj(tank3);

			//赤門
			colordoor = new ObjColorDoor(425,261,76,true,1);
			colordoor->m_ActionPriority = 100;
			colordoor->m_DrawPriority = 100;
			TaskSystem::InsertObj(colordoor);

			//赤門(2個め)
			colordoor2 = new ObjColorDoor(916,174,76,true,2);
			colordoor2->m_ActionPriority = 100;
			colordoor2->m_DrawPriority = 100;
			TaskSystem::InsertObj(colordoor2);

			//緑門
			colordoor3 = new ObjColorDoor(1062, 174, 84,true, 3);
			colordoor3->m_ActionPriority = 100;
			colordoor3->m_DrawPriority = 100;
			TaskSystem::InsertObj(colordoor3);

			//赤門(3個め)
			colordoor4 = new ObjColorDoor(2618, 260, 76,true, 4);
			colordoor4->m_ActionPriority = 100;
			colordoor4->m_DrawPriority = 100;
			TaskSystem::InsertObj(colordoor4);

			//緑門(2個め)
			colordoor5 = new ObjColorDoor(2778, 110, 84,false, 5);
			colordoor5->m_ActionPriority = 100;
			colordoor5->m_DrawPriority = 100;
			TaskSystem::InsertObj(colordoor5);

			//赤タンク
			colordoort = new ObjColorDoor_Tank(345,335,75,347,380,1);
			colordoort->m_ActionPriority = 110;
			colordoort->m_DrawPriority = 110;
			TaskSystem::InsertObj(colordoort);

			//赤タンク
			colordoort2 = new ObjColorDoor_Tank(845, 248, 75, 847, 380,2);
			colordoort2->m_ActionPriority = 110;
			colordoort2->m_DrawPriority = 110;
			TaskSystem::InsertObj(colordoort2);

			//緑タンク
			colordoort3 = new ObjColorDoor_Tank(990, 248, 82,992,292,3);
			colordoort3->m_ActionPriority = 110;
			colordoort3->m_DrawPriority = 110;
			TaskSystem::InsertObj(colordoort3);

			//赤タンク
			colordoort4 = new ObjColorDoor_Tank(2550, 334, 75, 847, 380, 4);
			colordoort4->m_ActionPriority = 110;
			colordoort4->m_DrawPriority = 110;
			TaskSystem::InsertObj(colordoort4);

			//緑タンク
			colordoort5 = new ObjColorDoor_Tank(2700, 334, 82, 992, 292, 5);
			colordoort5->m_ActionPriority = 110;
			colordoort5->m_DrawPriority = 110;
			TaskSystem::InsertObj(colordoort5);

			bucketmeter = new CBucketMeter();
			bucketmeter->m_ActionPriority = 140;
			bucketmeter->m_DrawPriority = 170;
			TaskSystem::InsertObj(bucketmeter);

			//天秤ギミック
			scale = new ObjScale(570.0f, 336.0f, 1);
			scale->m_ActionPriority = 90;
			scale->m_DrawPriority = 80;
			TaskSystem::InsertObj(scale);
			scale_t = new ObjScale_Tank(568.0f, 333.0f, 3.0f, 3.0f, 1);
			scale_t->m_ActionPriority = 90;
			scale_t->m_DrawPriority = 80;
			TaskSystem::InsertObj(scale_t);

			//天秤ギミック
			scale2 = new ObjScale(1500.0f, 326.0f, 2);
			scale2->m_ActionPriority = 90;
			scale2->m_DrawPriority = 80;
			TaskSystem::InsertObj(scale2);
			scale_t2 = new ObjScale_Tank(1500.0f, 323.0f, 0.0f, 6.0f, 2);
			scale_t2->m_ActionPriority = 90;
			scale_t2->m_DrawPriority = 80;
			TaskSystem::InsertObj(scale_t2);

			//天秤ギミック
			scale3 = new ObjScale(2350.0f, 286.0f, 3);
			scale3->m_ActionPriority = 90;
			scale3->m_DrawPriority = 80;
			TaskSystem::InsertObj(scale3);
			scale_t3 = new ObjScale_Tank(2345.0f, 283.0f, 3.0f, 3.0f, 3);
			scale_t3->m_ActionPriority = 90;
			scale_t3->m_DrawPriority = 80;
			TaskSystem::InsertObj(scale_t3);

			dwbl = new ObjDownBlock(1545.0f+178, 150.0f+95);
			dwbl->m_ActionPriority = 130;
			dwbl->m_DrawPriority = 130;
			TaskSystem::InsertObj(dwbl);
			dwblt = new ObjDownBlock_Tank(1545.0f, 150.0f);
			dwblt->m_ActionPriority = 130;
			dwblt->m_DrawPriority = 130;
			TaskSystem::InsertObj(dwblt);

			spri3 = new CSPRI3();
			spri3->m_ActionPriority = 150;
			spri3->m_DrawPriority = 210;
			TaskSystem::InsertObj(spri3);

			g_SceneNumber = GAME_MAIN3;
			break;

		case GAME_MAIN3:
			break;
		}


		//レンダリング終了
		Dev::GetSwapChain()->Present(1, 0);//60FPSでバックバッファとプライマリバッファの交換


		//終了
		if (g_ls_game_end==true)
		{
			break;
		}
	}
	_endthreadex(0);	//スレッド終了
	return 0;
}


//Main関数---------
int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR szCmdLine, int nCmdShow)
{
	//メモリダンプ開始
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CoInitializeEx(NULL,COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	wchar_t name[] = { L"GameEngine" };	//ウィンドウ&タイトルネーム
	MSG msg;							//メッセージハンドル

	//ウィンドウステータス
	WNDCLASSEX wcex = {
		sizeof(WNDCLASSEX),CS_HREDRAW | CS_VREDRAW,
		WndProc,0,0,hInstance,NULL,NULL,
		(HBRUSH)(COLOR_WINDOW + 1),NULL,name,NULL
	};

	//ウィンドウクラス作成
	RegisterClassEx(&wcex);

	//ゲーム各システム初期化----
	CWindowCreate::NewWindow(800, 600, name, hInstance);//ウィンドウ作成
	CDeviceCreate::InitDevice(CWindowCreate::GethWnd(), 800, 600);//DirectX Deviceの初期化
	//CDeviceCreate::Init3DEnviroment();//3D環境構築
	Audio::InitAudio();//オーディオ作成
	Input::InitInput();//入力用のクラス初期化
	Draw::InitPolygonRender();//ポリゴン表示環境の初期化
	TaskSystem::InitTaskSystem();//タスクシステム初期化
	Font::InitFontTex();//フォント初期化
	Collision::InitHitLine();//コリジョンの初期化
	//リソース読み込み-------------
	HANDLE handoru[2];
	handoru[0] = (HANDLE)_beginthreadex(NULL, 0, TextureLoadSled, NULL, 0, NULL);//テクスチャ読み込み
	handoru[1] = (HANDLE)_beginthreadex(NULL, 0, MusicLoadSled, NULL, 0, NULL);//ミュージック読み込み
	WaitForMultipleObjects(2, handoru, TRUE, INFINITE);//読み込みスレッドが終了まで待機
	CloseHandle(handoru[0]);//ハンドル[0]を閉じる
	CloseHandle(handoru[1]);//ハンドル[1]を閉じる

	//Audio::StartLoopMusic();//バックミュージックスタート

	//デバッグ用オブジェクト作成
	SceneMain* scenemain = new SceneMain();
	scenemain->m_ActionPriority = 0;
	scenemain->m_DrawPriority = 0;
	TaskSystem::InsertObj(scenemain);

	HANDLE game_handoru;
	game_handoru = (HANDLE)_beginthreadex(NULL, 0, GameMainSled, NULL, 0, NULL);//ゲームメインスレッド実行

	//メッセージループ
	do
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

	} while (msg.message != WM_QUIT);
	WaitForSingleObject(game_handoru, INFINITE);//ゲームメインスレッド終了待ち
	CloseHandle(game_handoru);//ハンドルを閉じる

	//ゲームシステム破棄
	Collision::DeleteHitLine();//コリジョンの破棄
	Font::DeleteFontTex();//フォントの破棄
	TaskSystem::DeleteTaskSystem();//タスクシステムの破棄
	Draw::DeletePolygonRender();//ポリゴン表示環境の破棄
	//CDeviceCreate::Delete3DEnviroment();//3D環境破棄
	CDeviceCreate::ShutDown();//DirectXの環境破棄
	Audio::DeleteAudio();//オーディオ環境の破棄

	CoUninitialize();
	//この時点で開放されていないメモリの情報の表示
	_CrtDumpMemoryLeaks();
	return true;

}

//コールバック関数
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	Input::SetMouPos(&uMsg, &lParam);

	switch (uMsg)
	{
	case WM_KEYDOWN:		//ESCキーで終了
		switch (wParam)
		{
		case VK_ESCAPE:
			g_ls_game_end = true;
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_CLOSE:			//ウィンドウを閉じる場合
		g_ls_game_end = true;
		PostQuitMessage(0);
	case WM_DESTROY:
		return 0;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
//