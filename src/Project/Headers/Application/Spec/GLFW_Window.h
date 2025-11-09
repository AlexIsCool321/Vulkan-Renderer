#pragma once

#include <GLFW/glfw3.h>

#include <Application/IWindow.h>

namespace Application
{
	class GLFW_Window : public IWindow
	{
	protected:
		bool m_running;

	private:
		GLFWwindow* m_local_window;

	public:
		GLFW_Window(int width, int height, const char* title);
		~GLFW_Window();

		void Update();
		bool Should_Close();

		void Destroy();
	};
}