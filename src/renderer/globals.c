#include "renderer/globals.h"

bool_t using_validation_layers = true;

VkInstance VK_Instance					= NULL;
VkPhysicalDevice VK_Physical_Devce		= NULL;

VkDebugUtilsMessengerEXT VK_Messenger	= NULL;