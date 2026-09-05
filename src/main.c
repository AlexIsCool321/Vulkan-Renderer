#include <stdio.h>
#include <stdlib.h>

#include "c_utils.h"
#include "renderer/renderer.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

int main (int argc, char **argv)
{
	if (!glfwInit()) { goto EXIT; }

	glfwWindowHint (GLFW_CLIENT_API, GLFW_NO_API);
	GLFWwindow *window = glfwCreateWindow(800, 600, "Hello, Vulkan", NULL, NULL);
	if (window == NULL) { goto EXIT; }


	if (create_instance() == false) { goto EXIT; }


	for ( ;; )
	{
		if (glfwWindowShouldClose(window)) { break; }
		glfwPollEvents ();
	}


EXIT:
	if (window != NULL) { glfwHideWindow(window); }

	if (VK_Instance != NULL) { vkDestroyInstance(VK_Instance, NULL); }

	if (window != NULL) { glfwDestroyWindow(window); }
	
	glfwTerminate ();

	return EXIT_SUCCESS;
}