#ifndef INSTANCE_H
#define INSTANCE_H

#include "c_utils.h"

#include <vulkan/vulkan.h>

extern VkInstance VK_Instance;

bool_t create_instance (void);

#endif