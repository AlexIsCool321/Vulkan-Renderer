#include "renderer/instance.h"

#include "renderer/globals.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>




const char **get_extensions (uint32_t *length);
const char **get_layers (uint32_t *length);




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
	

	uint32_t extension_count = 0;
	const char **extensions = get_extensions(&extension_count);

	uint32_t layer_count = 0;
	const char **layers = get_layers(&layer_count);

	const VkInstanceCreateInfo create_info =
	{
		.sType						= VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
		.pNext						= NULL,

		.flags						= 0,

		.pApplicationInfo			= &application_info,

		.enabledLayerCount			= layer_count,
		.ppEnabledLayerNames		= layers,

		.enabledExtensionCount		= extension_count,
		.ppEnabledExtensionNames	= extensions
	};


	VkResult result = vkCreateInstance(&create_info, NULL, &VK_Instance);

	CLEAN_FREE (extensions);
	CLEAN_FREE (layers);

	if (result != VK_SUCCESS)
	{
		printf ("Failed to create VK Instance! [ %i ]\n", result);
		return false;
	}

	return true;
}




const char **get_extensions (uint32_t *length)
{
	const char **extensions		= NULL;
	uint32_t extension_count	= 0;

	// glfw extensions
	const char **glfw_extensions = NULL;
	uint32_t glfw_count = 0;
	glfw_extensions = glfwGetRequiredInstanceExtensions (&glfw_count);
	if (glfw_extensions == NULL) { return NULL; }

	for (uint32_t i = 0; i < glfw_count; i++)
	{
		ADD_ITEM (extensions, extension_count, glfw_extensions[i]);
	}


	// Validation Layers
	if (using_validation_layers == true)
	{
		ADD_ITEM (extensions, extension_count, VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
	}


	if (length != NULL)
	{
		(*length) = extension_count;
	}

	return extensions;
}

const char **get_layers (uint32_t *length)
{
	const char **layers		= NULL;
	uint32_t layer_count	= 0;


	// Validation Layers
	if (using_validation_layers == true)
	{
		ADD_ITEM (layers, layer_count, "VK_LAYER_KHRONOS_validation");
	}

	
	if (length != NULL)
	{
		(*length) = layer_count;
	}
	
	return layers;
}