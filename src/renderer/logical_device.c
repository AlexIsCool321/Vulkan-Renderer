#include "renderer/logical_device.h"

#include "renderer/globals.h"

bool_t create_logical_device (void)
{
	const VkDeviceQueueCreateInfo queue_create_info =
	{
		.sType				= VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,	// VkStructureType
		.pNext				= NULL,	// const void*
		
		.flags				= 0,
		
		.queueFamilyIndex	= VK_Graphics_Queue_Index,
		.queueCount			= 1,
		
		.pQueuePriorities	=  &(float){1.0f}
	};

	VkPhysicalDeviceFeatures device_features = {0};
	vkGetPhysicalDeviceFeatures (VK_Physical_Devce, &device_features);

	const VkDeviceCreateInfo create_info =
	{
		.sType						= VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
		.pNext						= NULL,

		.flags						= 0,

		.queueCreateInfoCount		= 1,
		.pQueueCreateInfos			= &queue_create_info,

		.enabledLayerCount			= 0,	// unused
		.ppEnabledLayerNames		= NULL,	// unused

		.enabledExtensionCount		= 0,
		.ppEnabledExtensionNames	= 0,

		.pEnabledFeatures			= &device_features,
	};

	VkResult result = vkCreateDevice(VK_Physical_Devce, &create_info, NULL, &VK_Logical_Device);
	if (result != VK_SUCCESS)
	{
		printf ("Failed to create logical device! [ %i ]\n", result);
		return false;
	}

	vkGetDeviceQueue (VK_Logical_Device, VK_Graphics_Queue_Index, 0, &VK_Graphics_Queue);

	return true;
}