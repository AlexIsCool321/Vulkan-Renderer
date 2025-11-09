#include <GLFW/glfw3.h>

#include <iostream>

#include <Application/Application.h>

namespace Application
{
	void Init()
	{
		if (!glfwInit())
		{
			std::cout << "ERROR : FAILED TO LOAD GLFW!" << std::endl;

			glfwTerminate();
			return;
		}

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	}

	void Terminate()
	{
		glfwTerminate();
	}
}