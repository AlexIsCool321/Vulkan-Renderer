#include "renderer/validation_layers.h"

#include "renderer/globals.h"

#include <vulkan/vulkan.h>




static VKAPI_ATTR VkBool32 VKAPI_CALL validation_layer_debug_callback (VkDebugUtilsMessageSeverityFlagBitsEXT message_severity, VkDebugUtilsMessageTypeFlagsEXT message_type, const VkDebugUtilsMessengerCallbackDataEXT* callback_data, void* user_data);
VkResult create_debug_utils_messenger_ext (VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* create_info, const VkAllocationCallbacks* allocator, VkDebugUtilsMessengerEXT* debug_messenger);




bool_t set_up_debug_messanger (void)
{
	if (using_validation_layers == false) { return true; }

	VkDebugUtilsMessengerCreateInfoEXT create_info =
	{
		.sType				= VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT,
		.pNext				= NULL,

		.flags				= 0,

		.messageSeverity	= VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT,
		.messageType		= VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT,
		.pfnUserCallback	= validation_layer_debug_callback,
		.pUserData			= NULL
	};

	VkResult result = create_debug_utils_messenger_ext(VK_Instance, &create_info, NULL, &VK_Messenger);
	if (result != VK_SUCCESS)
	{
		printf ("Failed to create VK Debug Messenger! [ %i ]\n", result);
		return false;
	}

	return true;
}




static VKAPI_ATTR VkBool32 VKAPI_CALL validation_layer_debug_callback (VkDebugUtilsMessageSeverityFlagBitsEXT message_severity, VkDebugUtilsMessageTypeFlagsEXT message_type, const VkDebugUtilsMessengerCallbackDataEXT* callback_data, void* user_data)
{
	if (message_severity < VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT) { return VK_FALSE; }
	
	printf ("Validation Layer : [ %s ]\n", callback_data->pMessage);

	return VK_FALSE;
}

VkResult create_debug_utils_messenger_ext (VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* create_info, const VkAllocationCallbacks* allocator, VkDebugUtilsMessengerEXT* debug_messenger)
{
	PFN_vkCreateDebugUtilsMessengerEXT function = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
	if (function == NULL) { return VK_ERROR_EXTENSION_NOT_PRESENT; }

	return function(instance, create_info, allocator, debug_messenger);
}