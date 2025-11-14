#include <iostream>

#include <Application/Spec/GLFW_Window.h>

namespace Application
{
	GLFW_Window::GLFW_Window(int width, int height, const char* title)
	{
		this->m_local_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
		if (this->m_local_window == nullptr)
		{
			std::cout << "ERROR : FAILE TO CREATE WINDOW!" << std::endl;

			return;
		}
	}

	GLFW_Window::~GLFW_Window()
	{
		this->Destroy();
	}


	void GLFW_Window::Update()
	{
		glfwPollEvents();
		std::cout << "A" << std::endl;

		this->m_running = !glfwWindowShouldClose(this->m_local_window);
	}

	bool GLFW_Window::Should_Close()
	{
		return !this->m_local_window;
	}


	void GLFW_Window::Destroy()
	{
		glfwDestroyWindow(this->m_local_window);
	}
}