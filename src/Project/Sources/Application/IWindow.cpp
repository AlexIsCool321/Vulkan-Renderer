#include <Application/Spec/GLFW_Window.h>

#include <Application/IWindow.h>

namespace Application
{
	IWindow::IWindow()
	{
		this->m_running = true;
	}

	IWindow::~IWindow()
	{

	}


	void IWindow::Update()
	{

	}

	bool IWindow::Should_Close()
	{
		return !m_running;
	}


	void IWindow::Destroy()
	{

	}



	IWindow* Create_Window(int width, int height, const char* title)
	{
		IWindow* result = nullptr;

		#ifdef __linux__
			result = static_cast<IWindow*>(new GLFW_Window(width, height, title));
		#endif

		return result;
	}
}