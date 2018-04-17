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
#include "..\Hero.h"
#include "..\Tank.h"
#include "..\Background.h"
#include "..\BucketMeter.h"
#include "..\ObjGround.h"
#include "..\SceneMain.h"
#include "..\WTM.h"

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

//プロトタイプ宣言------
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	//ウィンドウプロジーシャー

//マルチスレッドにする関数---------
//テクスチャ読み込み関数
unsigned __stdcall TextureLoadSled(void *p)
{
	//イメージ読み込み
	Draw::LoadImage(10, L"Images\\Tank.png");//10番目に"Tank.png"を読み込み
	Draw::LoadImage(11, L"Images\\BucketMeter.png");//11番目に"BucketMeter.png"を読み込み
	Draw::LoadImage(12, L"Images\\Background.png");//12番目に"Background.png"を読み込み
	Draw::LoadImage(13, L"Images\\Title.png");//13番目に"Title.pngを読み込み
	Draw::LoadImage(0, L"Images\\Player1.png");//0番目に"Player1.png"を読み込み
	Draw::LoadImage(1, L"Images\\Player2.png");//1番目に"Player2.png"を読み込み
	Draw::LoadImage(2, L"Images\\Player3.png");//2番目に"Player3.png"を読み込み
	Draw::LoadImage(3, L"Images\\Player4.png");//3番目に"Player4.png"を読み込み
	Draw::LoadImage(4, L"Images\\Player5.png");//4番目に"Player5.png"を読み込み
	Draw::LoadImage(5, L"Images\\Player6.png");//5番目に"Player6.png"を読み込み
	Draw::LoadImage(6, L"Images\\Player8.png");//6番目に"Player8.png"を読み込み

	Draw::LoadImage(10, L"Images\\Tank.png");//10番目に"Tank.png"を読み込み
	Draw::LoadImage(11, L"Images\\BucketMeter.png");//11番目に"BucketMeter.png"を読み込み
	Draw::LoadImage(12, L"Images\\Background.png");//12番目に"Background.png"を読み込み
	Draw::LoadImage(13, L"Images\\Title.png");//13番目に"Title.pngを読み込み
	Draw::LoadImage(14, L"Images\\muzusibuki.png");//14番目に"muzusibuki.pngを読み込み
	Draw::LoadImage(16, L"Images\\WTM.png");//14番目に"muzusibuki.pngを読み込み
	Draw::LoadImage(17, L"Images\\jimen.png");//17番目に"jimen.pngを読み込み

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

		case GAME://ゲーム画面初期化

		   /* hero = new CHero();
			hero->m_priority = 90;
			TaskSystem::InsertObj(hero);

		    tank = new CTank();
			tank->m_priority = 80;
			TaskSystem::InsertObj(tank);*/

			background = new CBackground();
			background->m_priority = 10;
			TaskSystem::InsertObj(background);

			hero = new CHero();
			hero->m_priority = 90;
			TaskSystem::InsertObj(hero);

			tank = new CTank();
			tank->m_priority = 80;
			TaskSystem::InsertObj(tank);

			bucketmeter = new CBucketMeter();
			bucketmeter->m_priority = 20;
			TaskSystem::InsertObj(bucketmeter);

			ground = new CObjGround();
			ground->m_priority = 30;
			TaskSystem::InsertObj(ground);

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