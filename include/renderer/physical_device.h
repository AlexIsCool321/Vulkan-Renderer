#ifndef RENDERER_PHYSICAL_DEVICE_H
#define RENDERER_PHYSICAL_DEVICE_H

#include <vulkan/vulkan.h>
#include "c_utils.h"

bool_t select_physical_device (void);
bool_t get_phsyical_device_graphics_queue (void);

#endif