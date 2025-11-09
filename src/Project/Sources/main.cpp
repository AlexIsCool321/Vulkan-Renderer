#include <Application/Application.h>
#include <GLFW/glfw3.h>
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