#include <stdio.h>
#include <stdlib.h>

#include "c_utils.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>


VkInstance VK_Instance = {0};


bool_t create_instance (void);


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

bool_t create_instance (void)
{
	const VkApplicationInfo application_info =
	{
		.sType					= VK_STRUCTURE_TYPE_APPLICATION_INFO,
		.pNext					= NULL,

		.pApplicationName		= "Vulkan Test",
		.applicationVersion		= VK_MAKE_VERSION(1, 0, 0),
		
		.pEngineName			= "None",
		.engineVersion			= VK_MAKE_VERSION(1, 0, 0),
		
		.apiVersion				= VK_API_VERSION_1_0
	};

	const VkInstanceCreateInfo create_info =
	{
		.sType						= VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
		.pNext						= NULL,

		.flags						= 0,

		.pApplicationInfo			= &application_info,

		.enabledLayerCount			= 0,	// uint32_t
		.ppEnabledLayerNames		= 0,	// const char* const*

		.enabledExtensionCount		= 0,	// uint32_t
		.ppEnabledExtensionNames	= 0		// const char* const*
	};

	VkResult result = vkCreateInstance(&create_info, NULL, &VK_Instance);
	if (result != VK_SUCCESS)
	{
		printf ("Failed to create VK Instance! [ %i ]\n", result);
		return false;
	}

	return true;
}