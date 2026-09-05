#ifndef RENDERER_GLOBALS_H
#define RENDERER_GLOBALS_H

#include <vulkan/vulkan.h>

#include "c_utils.h"

extern bool_t using_validation_layers;

extern VkInstance VK_Instance;

extern VkPhysicalDevice VK_Physical_Devce;
extern uint32_t VK_Graphics_Queue;

extern VkDebugUtilsMessengerEXT VK_Messenger;

#endif