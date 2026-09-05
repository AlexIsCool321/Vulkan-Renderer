#include "renderer/instance.h"

#include <stdio.h>
#include <stdlib.h>

VkInstance VK_Instance = NULL;

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