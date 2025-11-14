#include <Application/Application.h>

#include <Renderer/Renderer.h>

using namespace Application;
using namespace Renderer;

int main()
{
	Application::Init();

	Render_Server* renderer = new Render_Server();

	IWindow* window = Create_Window(800, 600, "Vulkan Renderer");

	while(!window->Should_Close())
	{
		window->Update();
	}

	window->Destroy();

	
	Application::Terminate();

	return 0;
}