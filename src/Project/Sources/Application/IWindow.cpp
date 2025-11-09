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
		IWindow* result = new IWindow();

		return result;
	}
}