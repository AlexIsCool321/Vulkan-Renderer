#include "renderer/physical_device.h"

#include "renderer/globals.h"

bool_t select_physical_device (void)
{
	uint32_t count						= 0;
	VkPhysicalDevice *physical_devices	= NULL;
	VkResult result = vkEnumeratePhysicalDevices (VK_Instance, &count, NULL);
	if (result != VK_SUCCESS)
	{
		printf ("Failed to get physical devices! [ %i ]\n", result);
		return false;
	}

	physical_devices = allocate_big_buffer(sizeof(VkPhysicalDevice) * count);
	if (physical_devices == NULL)
	{
		printf ("Failed to allocate physical device list!\n");
		return false;
	}
	
	result = vkEnumeratePhysicalDevices (VK_Instance, &count, physical_devices);
	if (result != VK_SUCCESS)
	{
		printf ("Failed to get physical devices! [ %i ]\n", result);
		return false;
	}

	VK_Physical_Devce = physical_devices[0];

	return true;
}