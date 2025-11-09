#include <Application/Application.h>

using namespace Application;

int main()
{
	Application::Init();


	IWindow* window = Create_Window(800, 600, "Vulkan Renderer");

	while(!window->Should_Close())
	{
		window->Update();
	}

	window->Destroy();

	
	Application::Terminate();

	return 0;
}