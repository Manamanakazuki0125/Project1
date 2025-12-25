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

	static LRESULT CALLBACK MainWindProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	void OnResize(UINT width, UINT height);

	HWND    GetWindowHandle() { return hWindow_; }

private:

	WNDCLASS wc_;

	HWND hWindow_ = nullptr;

	SIZE sizeWindow_;

	MSG msg_ = {};

};
