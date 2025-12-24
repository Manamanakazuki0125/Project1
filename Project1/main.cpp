#include <Windows.h>
#include "Application.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int)
{
	//Applicationクラスのインスタンスを生成し、ポインタで保持。アプリケーションのメインループ
	Application* application = new Application();

	//アプリケーション初期化
	application->Initialize(hInst);

	//ループ：アプリメインの処理を記述するところ
	application->Loop();

	//アプリ終了処理
	application->Terminate();

	//メモリ解放
	delete(application);

	return 0;
}