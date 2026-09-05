#ifndef RENDERER_VALIDATION_LAYERS_H
#define RENDERER_VALIDATION_LAYERS_H

#include <vulkan/vulkan.h>
#include "c_utils.h"

VkResult create_debug_utils_messenger_ext (VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* create_info, const VkAllocationCallbacks* allocator, VkDebugUtilsMessengerEXT* debug_messenger);
VKAPI_ATTR void VKAPI_CALL destroy_debug_utils_messenger_ext (VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* allocator);

bool_t set_up_debug_messanger (void);

#endif