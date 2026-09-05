#include <stdio.h>
#include <stdlib.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>


int main (int argc, char **argv)
{
	if (!glfwInit()) { goto EXIT; }

	glfwWindowHint (GLFW_CLIENT_API, GLFW_NO_API);
	GLFWwindow *window = glfwCreateWindow(800, 600, "Hello, Vulkan", NULL, NULL);
	if (window == NULL) { goto EXIT; }


	for ( ;; )
	{
		if (glfwWindowShouldClose(window)) { break; }
		glfwPollEvents ();
	}


EXIT:
	if (window != NULL) { glfwDestroyWindow(window); }

	glfwTerminate ();

	return EXIT_SUCCESS;
}