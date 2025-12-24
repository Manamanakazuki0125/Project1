#pragma once
#include <Windows.h>
#include "Window.h"

class Application
{
public:
	void Initialize(HINSTANCE hInst);
	void Loop();
	void Terminate();
private:
	//アプリのメインループ
	bool gameloop();
private:
	Window window_;
};