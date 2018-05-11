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
#include "..\Menu.h"

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
/*enum Scene
{
	TITLE = 10,
	TITLE_MAIN = 20,
	GAME = 30,
	GAME_MAIN=40,
};*/

//グローバル変数--------------
bool g_ls_game_end = false;	//スレッド用ゲーム終了フラグ
int g_SceneNumber = TITLE;//ゲーム画面フラグ
bool g_key_flag = true;//キーフラグ

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
	
	Draw::LoadImage(4, L"Images\\Player5.png");//4番目に"Player5.png"を読み込み
	Draw::LoadImage(5, L"Images\\Player6.png");//5番目に"Player6.png"を読み込み
	//Draw::LoadImage(6, L"Images\\Player8.png");//6番目に"Player8.png"を読み込み

	Draw::LoadImage(10, L"Images\\Tank.png");//10番目に"Tank.png"を読み込み
	Draw::LoadImage(11, L"Images\\BucketMeter.png");//11番目に"BucketMeter.png"を読み込み
	Draw::LoadImage(12, L"Images\\Background.png");//12番目に"Background.png"を読み込み
	Draw::LoadImage(13, L"Images\\Title.png");//13番目に"Title.pngを読み込み
	Draw::LoadImage(14, L"Images\\muzusibuki.png");//14番目に"muzusibuki.pngを読み込み
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
	_endthreadex(0);	//スレッド終了
	return 0;
}

//ミュージック読み込み関数
unsigned __stdcall MusicLoadSled(void *p)
{
	//ミュージック情報取得
	//Audio::LoadBackMusic("Sounds\\Test.ogg");

	_endthreadex(0);	//スレッド終了
	return 0;
}

//ゲームメイン関数
unsigned __stdcall GameMainSled(void *p)
{
	while (1)
	{
		//ゲームメイン
		TaskSystem::ListAction();	//リスト内のアクション実行
									//衝突判定実行
		Collision::CheckStart();

		//レンダリングターゲットセットとレンダリング画面クリア
		float color[] = { 0.0f,0.25f,0.45f,1.0f };
		Dev::GetDeviceContext()->OMSetRenderTargets(1, Dev::GetppRTV(), NULL);//レンダリング先をカラーバッファ(バックバッファ)にセット
		Dev::GetDeviceContext()->ClearRenderTargetView(Dev::GetRTV(), color);//画面をcolorでクリア
		Dev::GetDeviceContext()->RSSetState(Dev::GetRS());//ラスタライズをセット
		//ここからレンダリング開始

		TaskSystem::ListDraw();		//リスト内のドロー実行
		Collision::DrawDebug();

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
		

		switch (g_SceneNumber)
		{
		case TITLE://タイトル初期化
			title = new CTitle();
			title->m_priority = 100;
			TaskSystem::InsertObj(title);
			g_SceneNumber = TITLE_MAIN;
			break;

		case TITLE_MAIN://タイトル
			break;

		case STORY:
			story = new CObjStory();
			story->m_priority = 100;
			TaskSystem::InsertObj(story);
			g_SceneNumber = STORY_MAIN;
			break;

		case STORY_MAIN:
			break;

		case STAGESELECTO://ステージセレクト初期化
			stageselecto = new CStageSelecto();
			stageselecto->m_priority = 110;
			TaskSystem::InsertObj(stageselecto);
			g_SceneNumber = STAGESELECTO_MAIN;
			break;

		case STAGESELECTO_MAIN://ステージセレクト
			break;

		case RESULT://リザルト画面初期化
			result = new CResult();
			result->m_priority = 120;
			TaskSystem::InsertObj(result);
			g_SceneNumber = RESULT_MAIN;
			break;

		case RESULT_MAIN://リザルト画面
			break;

		case GAME://ゲーム画面初期化

		   /* hero = new CHero();
			hero->m_priority = 90;
			TaskSystem::InsertObj(hero);

		    tank = new CTank();
			tank->m_priority = 80;
			TaskSystem::InsertObj(tank);*/

			/*tank = new CTank();
			tank->m_priority = 80;
			TaskSystem::InsertObj(tank);*/

			background = new CBackground();
			background->m_priority = 10;
			TaskSystem::InsertObj(background);

			tank = new CTank();
			tank->m_priority = 80;
			TaskSystem::InsertObj(tank);

			ground = new CObjGround();
			ground->m_priority = 30;
			TaskSystem::InsertObj(ground);

			hero = new CHero();
			hero->m_priority = 90;
			TaskSystem::InsertObj(hero);

			bucketmeter = new CBucketMeter();
			bucketmeter->m_priority = 20;
			TaskSystem::InsertObj(bucketmeter);

			/*tank = new CTank();
			tank->m_priority = 80;
			TaskSystem::InsertObj(tank);*/

			wtm = new CWTM();
			wtm->m_priority = 70;
			TaskSystem::InsertObj(wtm);

			g_SceneNumber = GAME_MAIN;
			break;

		case GAME_MAIN:
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
	//Audio::InitAudio();//オーディオ作成
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
	scenemain->m_priority = 0;
	TaskSystem::InsertObj(scenemain);

	TaskSystem::SortPriority();//描画順位変更

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
	//Audio::DeleteAudio();//オーディオ環境の破棄

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