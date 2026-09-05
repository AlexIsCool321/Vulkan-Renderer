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


	if (create_instance() == false)						{ goto EXIT; }

	if (select_physical_device() == false)				{ goto EXIT; }
	if (get_phsyical_device_graphics_queue() == false)	{ goto EXIT; }

	if (create_logical_device() == false)				{ goto EXIT; }

	if (set_up_debug_messanger() == false)				{ goto EXIT; }


	for ( ;; )
	{
		if (glfwWindowShouldClose(window)) { break; }
		glfwPollEvents ();

		
	}


EXIT:
	if (window != NULL) { glfwHideWindow(window); }


	if (VK_Messenger != NULL)		{ destroy_debug_utils_messenger_ext(VK_Instance, VK_Messenger, NULL); }

	if (VK_Logical_Device != NULL)	{ vkDestroyDevice(VK_Logical_Device, NULL); }

	if (VK_Instance != NULL)		{ vkDestroyInstance(VK_Instance, NULL); }


	if (window != NULL) { glfwDestroyWindow(window); }
	
	glfwTerminate ();

	return EXIT_SUCCESS;
}