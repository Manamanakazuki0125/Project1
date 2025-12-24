#pragma once
#include <windows.h>

class Window
{
public:
	//デフォルトコンストラクタ。初期化処理とか
	Window();
	//子クラスで継承可能なデストラクタ
	virtual ~Window();

	bool Initialize(HINSTANCE hInst);

	bool Terminate();

	bool MessageLoop();



};
