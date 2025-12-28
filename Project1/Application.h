#pragma once
#include <Windows.h>
#include "Window.h"
#include "Renderer.h"

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

	Renderer renderer_;
};