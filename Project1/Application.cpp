#include "Application.h"

void Application::Initialize(HINSTANCE hInst)
{
	
	window_.Initialize(hInst);
	renderer_.Initialize(window_.GetWindowHandle());
	
	
}

void Application::Loop()
{
	while (true) {
		bool result = window_.MessageLoop();
		if (result == false)break;

		result = gameloop();
		if (result == false)break;
	}
}

void Application::Terminate()
{
	renderer_.Terminate();
	window_.Terminate();

}

bool Application::gameloop()
{
	renderer_.Draw();

	renderer_.Swap();

	return true;
}